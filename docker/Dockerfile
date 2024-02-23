FROM python:3.6.14-stretch
RUN echo "deb http://archive.debian.org/debian stretch main" > /etc/apt/sources.list

# Install gfortran and other necessary packages
RUN apt-get update && apt-get install -y --no-install-recommends \
        libxml2-dev     \
        libxslt1-dev    \
        libopenblas-dev \
        liblapack-dev   \
		less			\
		build-essential \
		gfortran        \
		fort77          \
		wget            \
		cmake           \
        libflint-2.5.2  \
        libflint-dev    \
        libgmp-dev      \
		yasm            \
		xvfb            \
		xauth           \
		ffmpeg          \
		sudo

# Add a user
ENV USER renaissance
ENV HOME /home/$USER
RUN useradd -ms "/bin/bash" "$USER"
RUN echo "$USER":"$USER" | chpasswd && adduser $USER sudo
WORKDIR $HOME

# Create renaissance directory with proper permissions
RUN mkdir /renaissance && chown $USER:$USER /renaissance
RUN chmod 777 /renaissance

# Copy src and python package requirements
COPY src/ /src/
COPY requirements.txt .

# Install Python packages
RUN python3 -m pip install --upgrade pip setuptools==59.6.0 wheel
RUN pip install -r requirements.txt

# Make utils executable
COPY ./utils /utils
RUN chmod +x /utils/*.sh

# Install sundials
RUN /utils/install_sundials.sh

# Export environment variables
ENV SUNDIALS_INCLUDEDIR="${HOME}/sundials/include"
ENV SUNDIALS_LIBDIR="${HOME}/sundials/lib"
ENV SUNDIALS_INST="${HOME}/sundials"

# Set up include path for Sundials headers
ENV C_INCLUDE_PATH="${SUNDIALS_INST}/include"
ENV LD_LIBRARY_PATH="${HOME}/sundials/lib"
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"/usr/local/lib"

# Install scikits.odes
RUN pip install 'scikits.odes==2.6.3'

# If files are provided, install cplex and gurobi
COPY ./solvers /solvers
RUN /utils/install_cplex.sh
RUN /utils/install_gurobi.sh
RUN rm -rf /solvers
RUN /utils/activate_gurobi.sh

# Set up workspace folder
# RUN mkdir /renaissance
COPY .bashrc $HOME
RUN chown "$USER" "$HOME/.bashrc"
RUN alias ll="ls -al"

# Finalizing installation
USER $USER
RUN mkdir ./work
WORKDIR /home/$USER/work

# Load your package in development mode on startup
ENTRYPOINT ["/bin/bash", "-c", "pip install --user -e /renaissance[ORACLE] && $0 $*"]

CMD /bin/bash
