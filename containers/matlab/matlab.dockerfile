# To specify which MATLAB release to install in the container, edit the value of the MATLAB_RELEASE argument.
# Use lower case to specify the release, for example: ARG MATLAB_RELEASE=r2020a
ARG MATLAB_RELEASE=r2022a
ARG MATLAB_RELEASE_DIR=R2022a

# When you start the build stage, this Dockerfile by default uses the Ubuntu-based matlab-deps image.
# To check the available matlab-deps images, see: https://hub.docker.com/r/mathworks/matlab-deps
FROM mathworks/matlab:${MATLAB_RELEASE}

# Declare the global argument to use at the current build stage
ARG MATLAB_RELEASE
ARG MATLAB_RELEASE_DIR

# Run mpm to install MATLAB in the target location and delete the mpm installation afterwards
USER root
ARG MPM_PRODUCTS
RUN wget -q https://www.mathworks.com/mpm/glnxa64/mpm && \ 
    chmod +x mpm && \
    ./mpm install \
        --release=${MATLAB_RELEASE} \
        --destination=/opt/matlab/${MATLAB_RELEASE_DIR} \
        --products $MPM_PRODUCTS && \
    rm -f mpm /tmp/mathworks_root.log 

# Add user and grant sudo permission.
ARG USER_GID
ARG USER_UID
RUN groupmod -o -g ${USER_GID} matlab
RUN usermod -u ${USER_UID} -g ${USER_GID} matlab
RUN echo "matlab ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/matlab && \
    chmod 0440 /etc/sudoers.d/matlab

# Install some packages
ARG APT_DEPENDENCIES
RUN apt update && apt install -y wget $APT_DEPENDENCIES

# Clean up to reduce image size
RUN apt-get clean && apt-get autoremove -y && rm -rf /var/lib/apt/lists/*

# Install miniconda
ENV CONDA_DIR /opt/conda
RUN wget --quiet https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda.sh && \
     /bin/bash ~/miniconda.sh -b -p /opt/conda

# Put conda in path so we can use conda activate
ENV PATH=$CONDA_DIR/bin:$PATH

# Install chrono's packages
ARG PIP_DEPENDENCIES
ARG CONDA_DEPENDENCIES
ARG CONDA_CHANNELS
RUN if [ -n "$CONDA_DEPENDENCIES" ]; then \
			for c in $CONDA_CHANNELS; do \
				conda config --append channels $c;	\
			done; \
			unset CONDA_CHANNELS; \
			conda install $CONDA_DEPENDENCIES; \
    fi
RUN if [ -n "$PIP_DEPENDENCIES" ]; then \
      pip install $PIP_DEPENDENCIES; \
    fi

# Clean up conda
RUN conda clean -a -y

# Set user and work directory
USER matlab
