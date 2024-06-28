# GenESyS Docker

## Guia Rápido

Para configurar variáveis específicas de projeto, pode se utilizar o arquivo `config.sh`. Neste arquivo é possível alterar propriedades da execução.

Por padrão a execução via comandos make é local, ou seja, utiliza o código do repositório disponível localmente para desenvolvimento e execução. Para utilizar diretamente o código remoto (do repositório) e não o código local, utiliza-se a variável `REMOTE=1`.

Para abrir menu interativo:
```bash
make selector
```

Para buildar a imagem docker:
```bash
make build_image
```

Para  publicar imagem docker:
```bash
make push_image
```

Para debugar a imagem docker:
```bash
make run_debug
```

Para rodar a interface grafica do GenESyS:
```bash
make run_gui
```

Para rodar a CLI do GenESyS:
```bash
make run_shell
```

Para abrir o GenESyS no Qt Creator via Docker:
```bash
make run_qt
```

## Executando Remotamente

Caso seja necessário executar o a imagem sem os scripts e comandos disponíveis aqui, é possível fazê-lo da seguinte forma:

1. Exporte as variáveis desejadas:

```bash
# Nome da imagem Docker
export GENESYS_IMAGE="genesys-image"

# Driver gráfico
export MESA_LOADER_DRIVER_OVERRIDE=zink
```

2. Para fazer a inspeção da imagem:

```bash
docker run --name genesys --rm -ti --net=host --ipc=host \
    -e DISPLAY=$DISPLAY \
    -e MESA_LOADER_DRIVER_OVERRIDE=$MESA_LOADER_DRIVER_OVERRIDE \
    -e QT_X11_NO_MITSHM=1 \
    -e XDG_RUNTIME_DIR=/run/user/1001 \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    $GENESYS_IMAGE debug
```

3. Para rodar o Shell:

```bash
docker run --name genesys --rm -ti --net=host --ipc=host \
    -e DISPLAY=$DISPLAY \
    -e MESA_LOADER_DRIVER_OVERRIDE=$MESA_LOADER_DRIVER_OVERRIDE \
    -e QT_X11_NO_MITSHM=1 \
    -e XDG_RUNTIME_DIR=/run/user/1001 \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    $GENESYS_IMAGE shell
```

4. Para rodar o GUI:

```bash
docker run --name genesys --rm -ti --net=host --ipc=host \
    -e DISPLAY=$DISPLAY \
    -e MESA_LOADER_DRIVER_OVERRIDE=$MESA_LOADER_DRIVER_OVERRIDE \
    -e QT_X11_NO_MITSHM=1 \
    -e XDG_RUNTIME_DIR=/run/user/1001 \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    $GENESYS_IMAGE gui
```

5. Para rodar o QtCreator:

```bash
docker run --name genesys --rm -ti --net=host --ipc=host \
    -e DISPLAY=$DISPLAY \
    -e MESA_LOADER_DRIVER_OVERRIDE=$MESA_LOADER_DRIVER_OVERRIDE \
    -e QT_X11_NO_MITSHM=1 \
    -e XDG_RUNTIME_DIR=/run/user/1001 \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    $GENESYS_IMAGE qt
```