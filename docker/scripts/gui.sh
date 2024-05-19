source ./scripts/config.sh

if docker image inspect $IMAGE_NAME >/dev/null 2>&1; then
    docker run --name genesys --rm -ti --net=host --ipc=host -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --env="QT_X11_NO_MITSHM=1" $IMAGE_NAME gui
else
    echo "Build não executado"
fi
