# Nome do usuário
USER=$(whoami)
GENESYS_USER="genesys-user"
GENESYS_ROOT=/home/genesys
PROJECT_ROOT=$(cd .. && pwd)

# Utilizar cache no build da imagem (1 - sim, 0 - não)
DOCKER_CACHE=0

# Nome do Dockerfile
DOCKERFILE_NAME="Dockerfile"
MESA_LOADER_DRIVER_OVERRIDE=zink

# Nome da imagem Docker
IMAGE_NAME="genesys-image"

if ! command -v docker &> /dev/null; then
    echo "Docker não instalado"
    exit 1
else
  echo "Docker já instalado"
fi

sudo chown $USER /var/run/docker.sock