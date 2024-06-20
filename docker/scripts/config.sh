# Nome do usuário
USER=$(whoami)

# Se a execução é local ou remota (usando git)
REMOTE=0

# Usuário da imagem
GENESYS_USER="genesys-user"

# Nome da imagem Docker
GENESYS_IMAGE="genesys-image"

# Utilizar cache no build da imagem (1 - sim, 0 - não)
DOCKER_CACHE=1

# Nome do Dockerfile
GENESYS_DOCKERFILE="Dockerfile"

# Driver gráfico
MESA_LOADER_DRIVER_OVERRIDE=zink

# Variáveis internas da imagem
GENESYS_PROJECT=$(cd .. && pwd)
GENESYS_NOGUI_SUBPATH=GenesysShell
GENESYS_GUI_SUBPATH=GenesysQtGUI

if [[ $REMOTE == 1 ]]; then
  GENESYS_ROOT=/home/genesys/remote
else
  GENESYS_ROOT=/home/genesys/local
fi
echo "Raiz do projeto:"
echo $GENESYS_ROOT

if ! command -v docker &> /dev/null; then
    echo "Docker não instalado"
    exit 1
else
  echo "Docker já instalado"
fi

sudo chown $USER /var/run/docker.sock