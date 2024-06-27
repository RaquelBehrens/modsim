source ./scripts/config.sh

if [ $DOCKER_CACHE == 0 ]; then
    docker build -f $GENESYS_DOCKERFILE -t $GENESYS_IMAGE --no-cache .
else
    docker build -f $GENESYS_DOCKERFILE -t $GENESYS_IMAGE .
fi