source config.sh

# Nome do usuário
USER=$(whoami)

if [[ $REMOTE == 1 ]]; then
  GENESYS_ROOT=$GENESYS_REMOTE_ROOT
else
  GENESYS_ROOT=$GENESYS_LOCAL_ROOT
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