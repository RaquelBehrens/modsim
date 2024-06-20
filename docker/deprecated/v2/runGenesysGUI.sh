# Nome do usuário
USER=$(whoami)

# Nome do Dockerfile
DOCKERFILE_NAME="Dockerfile"

# Nome da imagem Docker
GENESYS_IMAGE="genesys_image"

if ! command -v docker &> /dev/null; then
    echo "Docker não instalado"
    exit 1
else
  echo "Docker já instalado"
fi

sudo chown $USER /var/run/docker.sock

xhost local:root

docker build -f $DOCKERFILE_NAME -t $GENESYS_IMAGE .

if [ $? -eq 0 ]; then
    docker run --name genesys --rm -ti --net=host --ipc=host -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --env="QT_X11_NO_MITSHM=1" $GENESYS_IMAGE gui
else
    echo "Build não executado"
fi
