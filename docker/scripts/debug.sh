source ./scripts/config.sh

if docker image inspect $GENESYS_IMAGE >/dev/null 2>&1; then
    xhost local:root
    if [[ $REMOTE == 1 ]]; then 
        docker run --name genesys --rm -ti --net=host --ipc=host \
            -e DISPLAY=$DISPLAY \
            -e MESA_LOADER_DRIVER_OVERRIDE=$MESA_LOADER_DRIVER_OVERRIDE \
            -e QT_X11_NO_MITSHM=1 \
            -e XDG_RUNTIME_DIR=/run/user/1001 \
            -v /tmp/.X11-unix:/tmp/.X11-unix \
            $GENESYS_IMAGE debug
    else
        docker run --name genesys --rm -ti --net=host --ipc=host \
            -e DISPLAY=$DISPLAY \
            -e REMOTE=$REMOTE \
            -e MESA_LOADER_DRIVER_OVERRIDE=$MESA_LOADER_DRIVER_OVERRIDE \
            -e GENESYS_ROOT=$GENESYS_ROOT \
            -e QT_X11_NO_MITSHM=1 \
            -e XDG_RUNTIME_DIR=/run/user/1001 \
            -v /tmp/.X11-unix:/tmp/.X11-unix \
            -v $GENESYS_PROJECT:$GENESYS_ROOT \
            $GENESYS_IMAGE debug
    fi
else
    echo "Build não executado"
fi
