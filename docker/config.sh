# -------------------------------------------------------- #
# Configurações de Usuário                                 #
# -------------------------------------------------------- #

### Configurações de Ambiente

# Se a execução é local ou remota (1 - código remoto, 0 - código local)
REMOTE=0

# Driver gráfico
MESA_LOADER_DRIVER_OVERRIDE=zink


### Configurações da Execução Docker

# Usuário docker 
GENESYS_USER="genesys-user"

# Nome da imagem Docker
GENESYS_IMAGE="genesys-image"



# -------------------------------------------------------- #
# Configurações de Desenvolvedor                           #
# -------------------------------------------------------- #

### Configurações do Build Docker

# Utilizar cache no build da imagem (1 - sim, 0 - não)
DOCKER_CACHE=1

# Path do arquivo dockerfile a ser utilizado no build
GENESYS_DOCKERFILE="Dockerfile"

# Link para o repositório git
GENESYS_REPO=https://github.com/RaquelBehrens/modsim

# Branch do repositório a ser utilizada
GENESYS_BRANCH=main


### Configurações de Estrutura Interna

# Path da raiz do projeto a ser utilizado dentro da imagem no modo local
GENESYS_PROJECT=$(cd .. && pwd)

# Path onde será armazenado o repositório do simulador no modo remoto
GENESYS_REMOTE_ROOT=/home/genesys/remote

# Path onde será armazenado o repositório do simulador no modo local
GENESYS_LOCAL_ROOT=/home/genesys/local

# Path do executável compilado para execução do genesys pelo terminal
GENESYS_NOGUI_SUBPATH=release/GenesysShell

# Path do executável compilado para execução do genesys pela interface gráfica
GENESYS_GUI_SUBPATH=release/GenesysQtGUI

# Path do projeto Qt para execução do genesys pelo QtCreator
GENESYS_PROJECT_SUBPATH=source/applications/gui/qt/GenesysQtGUI/GenesysQtGUI.pro
