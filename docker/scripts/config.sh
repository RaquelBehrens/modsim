# Nome do usuário
USER=$(whoami)

# Usuário da imagem
GENESYS_USER="genesys-user"

# Nome da imagem Docker
IMAGE_NAME="genesys-image"

# Utilizar cache no build da imagem (1 - sim, 0 - não)
DOCKER_CACHE=0

# Nome do Dockerfile
DOCKERFILE_NAME="Dockerfile"

# Driver gráfico
MESA_LOADER_DRIVER_OVERRIDE=zink

# Variáveis internas da imagem
GENESYS_ROOT=/home/genesys
PROJECT_ROOT=$(cd .. && pwd)
GENESYS_NOGUI_SUBPATH=GenesysShell
GENESYS_GUI_SUBPATH=GenesysQtGUI

if ! command -v docker &> /dev/null; then
    echo "Docker não instalado"
    exit 1
else
  echo "Docker já instalado"
fi

sudo chown $USER /var/run/docker.sock