source ./scripts/config.sh

if [ $DOCKER_CACHE == 0 ]; then
    docker build -f $DOCKERFILE_NAME -t $IMAGE_NAME --no-cache .
else
    docker build -f $DOCKERFILE_NAME -t $IMAGE_NAME .
fi