#!/bin/sh

#=======================================================================
build_cmd () { # Takes the cmd input string and outputs the same
    # string correctly quoted to be evaluated again.
    #
    # Always returns a 0
    #
    # usage: build_cmd
    #

    # Use version of echo here that will preserve
    # backslashes within $cmd. - g490189

            echo "$1" | awk '
#----------------------------------------------------------------------------
        BEGIN { squote = sprintf ("%c", 39)   # set single quote
                dquote = sprintf ("%c", 34)   # set double quote
              }
          NF != 0 { newarg=dquote             # initialize output string to
                                              # double quote
          lookquote=dquote                    # look for double quote
          oldarg = $0
          while ((i = index (oldarg, lookquote))) {
             newarg = newarg substr (oldarg, 1, i - 1) lookquote
             oldarg = substr (oldarg, i, length (oldarg) - i + 1)
             if (lookquote == dquote)
                lookquote = squote
             else
                lookquote = dquote
             newarg = newarg lookquote
          }
          printf " %s", newarg oldarg lookquote }
#----------------------------------------------------------------------------
        '
            return 0
}

build_cmds () {
    # Output the result of calling build_cmd on each argument.

    for param in "$@"; do
        echo -n `build_cmd "$param"`" "
    done
}

getMATLABVersion () {
    stat /usr/local/bin/matlab | grep -Eo "R[0-9]{4}[ab]"
}

printMessage () {
    # Print README file according to the mode in which the container is running.
    message=$1

    echo ----------------------------------------------------
    cat "/etc/$1"
    echo ----------------------------------------------------

}

startVNCServer () {
    # Start VNC server, either in background or in foreground.
    mode=$1

    if [ "$mode" = "foreground" ] ; then
        /usr/bin/vncserver -localhost no 
        /opt/noVNC/utils/launch.sh --vnc localhost:5901 
    else
        /usr/bin/vncserver -localhost no 
        /opt/noVNC/utils/launch.sh --vnc localhost:5901 &
    fi
}

validateInput () {
    # Validate the flags the user provided.

    if [ "$modes" -gt 1 ]; then
        printf "Error: -help, -vnc, -shell and -batch are mutually exclusive.\n"
        printf "Use the -help option to review the API documentation for this container.\n"
        exit 1
    fi

    if [ "$BATCH" = true ]; then
        # In batch mode, force the usage of either license file or network license manager.
        if [ -z "$MLM_LICENSE_FILE" ]; then
            printf "Error: -batch requires MLM_LICENSE_FILE set.\n"
            exit 1
        fi

        if [ -z "$BATCH_COMMAND" ]; then
            printf "Error: -batch must be followed by a MATLAB command.\n"
            exit 1
        fi

        ARGLIST="-batch ${BATCH_COMMAND}"

    fi

    if [ "$RUN" = true ]; then
        ARGLIST="-r ${RUN_COMMAND}"
    fi
}

startContainer() {

    # In help mode, just print the help message
    if [ "$HELP" = true ]; then

        printMessage help_readme

    # In desktop mode, print vnc message and start the VNC server in the foreground
    elif [ "$VNC" = true ]; then

        printMessage vnc_readme
        startVNCServer foreground

    # In shell mode, start bash and start the VNC server
    elif [ "$SHELL" = true ]; then

        startVNCServer background

        # Always want everything to start in the user home folder
        cd ~/Documents/MATLAB/
        exec /bin/bash

    # In custom mode, exec the specified command
    elif [ "$CUSTOM" = true ]; then

        eval exec "${CUSTOM_COMMAND}"

    # Otherwise, run MATLAB
    else

        if [ -z "$LICENCE_MESSAGE" ]; then
            echo "$LICENSE_MESSAGE"
        fi

        echo "Running matlab ${ARGLIST}"
        cd ~/Documents/MATLAB/
        eval exec "matlab ${ARGLIST}"
    fi
}

modes=0

if [ $# -ne 0 ] ; then
    if [ $(echo "-help" | grep -Eo "^$1$") ] || \
    [ $(echo "-vnc" | grep -Eo "^$1$") ] || \
    [ $(echo "-shell" | grep -Eo "^$1$") ] || \
    [ $(echo "-batch" | grep -Eo "^$1$") ]; then
        CUSTOM=false
    else
        CUSTOM=true
    fi
fi

if [ "$CUSTOM" = false ]; then
    while [ $# -gt 0 ]; do
        case "$1" in
                -help)
                HELP=true;
                modes=$((modes+1))
                ;;
                -vnc)
                VNC=true;
                modes=$((modes+1))
                ;;
                -shell)
                SHELL=true;
                modes=$((modes+1))
                ;;
                -batch)
                BATCH=true;
                BATCH_COMMAND=`build_cmd "$2"`
                modes=$((modes+1))
                ;;
        esac
        shift
    done
else
    CUSTOM_COMMAND=`build_cmds "$@"`
fi

startContainer

exit
