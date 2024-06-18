source ./scripts/config.sh

if docker image inspect $IMAGE_NAME >/dev/null 2>&1; then
    xhost local:root
    docker run --name genesys --rm -ti --net=host --ipc=host \
        -e DISPLAY=$DISPLAY \
        -e MESA_LOADER_DRIVER_OVERRIDE=$MESA_LOADER_DRIVER_OVERRIDE \
        -e GENESYS_GUI_SUBPATH=$GENESYS_GUI_SUBPATH \
        -e QT_X11_NO_MITSHM=1 \
        -e XDG_RUNTIME_DIR=/run/user/1001 \
        -v /tmp/.X11-unix:/tmp/.X11-unix \
        -v $PROJECT_ROOT:$GENESYS_ROOT \
        $IMAGE_NAME gui
else
    echo "Build não executado"
fi
