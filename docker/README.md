# GenESyS Docker

## Guia Rápido

Para abrir menu interativo:
```bash
make selector
```

Para buildar a imagem docker:
```bash
make build_image
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

## Construção da imagem

1. Instalar o Docker
	
   https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository

2. Atribuir permissão de execução para o usuário

	```sudo chown $USER /var/run/docker.sock```

3. Construir imagem

	```docker build -f Dockerfile .```

4. Pegar o id da imagem

   ```docker image ls```

5. Seguir instruções de push ao DockerHub (ou continuar com o id local acima)

   https://docs.docker.com/engine/reference/commandline/push/

## Rodando o container e compilando o GenESyS com GUI

1. Configurar as permissões do X11

   ```xhost local:root```

2. Rodar o container

   ```docker run --name genesys --rm -ti --net=host --ipc=host -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --env="QT_X11_NO_MITSHM=1" DOCKER_IMAGE_ID```

3. Clicar em 'Configure Project' no QtCreator

4. Dar 'run' no QtCreator

## Rodar usando os scripts (após instalar docker)

```sudo bash SCRIPT```

## Compilar o GenESyS sem GUI

Segue-se o mesmos comandos da compilação normal, mas através do comando exec do Docker:

```docker exec make -C DIRECTORY OPTIONS```

## Contribuições

1. Login no GitHub

	```docker exec genesys gh auth login```

2. Todos os comandos gh estão disponiveis (https://cli.github.com/manual/)

	```docker exec genesys gh PARAMETERS```