# atk-sandbox
Environment to develop in ROS2 and other software we use in WAutodrive

This tutorial on setting up atk is based on [this stackoverflow post](https://stackoverflowteams.com/c/wisconsin-autonomous/questions/92). Please refer to it for the most up-to-date information. 

# Notes
1. Things you add in the docker container won't persist when they shut down. So it would be useful to create a fork of this repository and push changes you make so that you won't lose your progress.


# Windows

1. Install [WSL](https://learn.microsoft.com/en-us/windows/wsl/install). 

   - Make sure to check that you are using WSL2 and upgrade your WSL if not. 

2. Install [Docker Desktop](https://www.docker.com/products/docker-desktop/)

   - Make sure you also have Docker Compose v2. Docker Desktop ships with that by default but you'll have to enable it in its settings.

3. Once these are set up, you can follow the Linux instructions below from step 2 onwards in your WSL terminal.

# MacOS

==WIP==
TLDR: Should mostly be same as Linux, but instead of `apt` you'll have to use `brew`. You'll also have to install Docker Desktop for Mac.

# Linux

1. Install Docker as per [this](https://docs.docker.com/desktop/install/ubuntu/).

   Make sure it installs correctly and ***is running***, also make sure docker compose v2 is installed

2. Make sure python is installed (I used python 3.10 because that's what we will be using for development)

* Make sure `pip` is installed as well. You can install it by running `sudo apt install python-pip`.

* Optional: Install and set up miniconda as per [this](https://docs.conda.io/en/latest/miniconda.html) to isolate your environment if that matters to you. You can learn more about what it is and how to set it up on our workstation [here](https://stackoverflowteams.com/c/wisconsin-autonomous/questions/87).

3. Install autonomy-toolkit by running `pip install autonomy-toolkit`

4. Clone the repository you want to use (example: [our WAutodrive repo](https://github.com/WisconsinAutonomous/WAutoDrive)). For the coding challenge, you'd use the atk-sandbox repository. For the way we develop, the repository you'd want to develop on would probably be one that has an `atk.yml` file. This file is imperative, you won't be able to build the container without it

5. `cd` to the repository and run `atk dev`. The first time this runs, it'll take about 10 minutes because it's gonna build the container. After that it shouldn't take so long unless you always build the container when you start it, which shouldn't be necessary. Look at [this post](https://stackoverflowteams.com/c/wisconsin-autonomous/questions/47) for more details on what atk is and how to use it.
