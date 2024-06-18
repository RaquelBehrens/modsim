FROM ubuntu:22.04

# Versão do Dockerfile
ARG VERSION=0.1.0

# URL do repositório
ARG GENESYS_REPO=https://github.com/RaquelBehrens/modsim

# A branch que o container usa
ENV GENESYS_MAIN_BRANCH=main

# Caminho onde o GenESyS vai ser clonado
ENV GENESYS_ROOT=/home/genesys

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

# Copia o script de inicialização para dentro do container
COPY scripts/entrypoint.sh /usr/local/bin/entrypoint.sh 
RUN chmod +x /usr/local/bin/entrypoint.sh

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

# Executa o script de inicialização
ENTRYPOINT ["bash", "/usr/local/bin/entrypoint.sh"]
