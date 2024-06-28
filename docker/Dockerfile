FROM ubuntu:22.04

# Versão do Dockerfile
ARG VERSION=0.1.0

# URL do repositório
ARG GENESYS_REPO=https://github.com/RaquelBehrens/modsim

# Se o modo de execução é local ou remoto
ENV REMOTE=1

# A branch que o container usa
ENV GENESYS_BRANCH=main

# Caminho onde o GenESyS vai ser clonado
ENV GENESYS_ROOT=/home/genesys/remote

# Sub-caminho onde está localizado o arquivo do projeto
ENV GENESYS_PROJECT_SUBPATH=source/applications/gui/qt/GenesysQtGUI/GenesysQtGUI.pro

# Sub-caminho onde está o binário do Genesys com GUI
ENV GENESYS_GUI_SUBPATH=GenesysQtGUI

# Sub-caminho onde está o binário do Genesys sem GUI
ENV GENESYS_NOGUI_SUBPATH=GenesysShell

LABEL maintainer=$GENESYS_USER \
url=$GENESYS_REPO \
name="docker-genesys" \
version=$VERSION

# Instala todas as bibliotecas necessárias
RUN echo "Instalando pre-requisitos" && \
    apt-get update && \
    apt-get upgrade --assume-yes && \
    DEBIAN_FRONTEND=noninteractive apt-get --assume-yes dist-upgrade && \
    DEBIAN_FRONTEND=noninteractive apt-get --assume-yes install \
        build-essential \
        curl \
        git \
        libclang1 \
        libgl1-mesa-dri \
        libgl1-mesa-glx \
        xdg-utils \
        qtcreator \
        qtbase5-dev \
        qttools5-*

# Diminui o tamanho da imagem
RUN echo "Limpando" && \
    apt-get autoremove --assume-yes && \
    apt-get clean && \
    rm --force --recursive /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Instala o comando gh que é o CLI oficial do GitHub
RUN echo "Preparando GitHub CLI" && \
    type -p curl >/dev/null || (apt-get update && apt-get install curl -y) && \
    curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg && \
    chmod go+r /usr/share/keyrings/githubcli-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | tee /etc/apt/sources.list.d/github-cli.list > /dev/null && \
    apt-get update && \
    apt-get install gh -y

# Clona o GenESyS
RUN echo "Clonando GeNESyS" && \
    git clone $GENESYS_REPO $GENESYS_ROOT
    
# Copia o script de inicialização para dentro do container
COPY scripts/entrypoint.sh /usr/local/bin/entrypoint.sh 
RUN chmod +x /usr/local/bin/entrypoint.sh

# Executa o script de inicialização
ENTRYPOINT ["bash", "/usr/local/bin/entrypoint.sh"]
