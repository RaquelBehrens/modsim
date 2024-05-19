FROM ubuntu:latest

# Set the DEBIAN_FRONTEND variable to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Create a user 
RUN useradd -ms /bin/bash genesys

# Set the user's password 
RUN echo 'genesys:genesys' | chpasswd

# Grant the user sudo privileges
RUN usermod -aG sudo genesys

# Expose the X11 socket for GUI applications 
ENV DISPLAY=$DISPLAY

# Install dependencies
RUN apt-get update && \
    apt-get -y install build-essential && \
    apt-get -y install openssl libssl-dev libssl1.0 libgl1-mesa-dev libqt5x11extras5 '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev && \
    apt-get -y install xauth xorg x11-apps
    
RUN apt-get -y install qt5-assistant qt5-qmake qtcreator libqt5designer5 qttools5-* qtbase5-dev git

# Install vscode
RUN apt-get install -y software-properties-common apt-transport-https wget && \
    wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | apt-key add - && \
    add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" -y && \
    apt-get install -y code

# Clone the repository
RUN git clone https://github.com/rlcancian2/Genesys-Simulator /home/Genesys-Simulator

COPY ./container-scripts/clone-repo.sh /home/scripts/clone-repo.sh
COPY ./container-scripts/run-genesys.sh /home/scripts/run-genesys.sh

RUN echo '#!/bin/bash\ncode --no-sandbox --user-data-dir="/home/genesys/.vscode-root"' > /usr/bin/vscode && \
    chmod +x /usr/bin/vscode

RUN echo '#!/bin/bash\n/home/Genesys-Simulator/GenesysQtGUI 2> /dev/null' > /usr/bin/run-default-gui && \
    chmod +x /usr/bin/run-default-gui && \
    echo '#!/bin/bash\nqtcreator 2> /dev/null' > /usr/bin/run-qtcreator && \
    chmod +x /usr/bin/run-qtcreator

COPY ./container-scripts/recompile-gui /usr/bin/recompile-gui
COPY ./container-scripts/recompile-shell /usr/bin/recompile-shell
COPY ./container-scripts/generate-ssh-key /usr/bin/generate-ssh-key

RUN chmod +x /usr/bin/recompile-gui && chmod +x /usr/bin/recompile-shell && chmod +x /usr/bin/generate-ssh-key

WORKDIR /home/scripts

# Start bash when the container starts
# ENTRYPOINT . /home/genesys/.bashrc
