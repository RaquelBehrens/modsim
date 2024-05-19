Construção da imagem:

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

Rodando o container e compilando o GenESyS com GUI:

1. Configurar as permissões do X11

   ```xhost local:root```

2. Rodar o container

   ```docker run --name genesys --rm -ti --net=host --ipc=host -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --env="QT_X11_NO_MITSHM=1" DOCKER_IMAGE_ID```

3. Clicar em 'Configure Project' no QtCreator

4. Dar 'run' no QtCreator

Para rodar usando os scripts (após instalar docker), é só executar:

```sudo bash SCRIPT```

Para compilar o GenESyS sem GUI, segue-se o mesmos comandos da compilação normal, mas através do comando exec do Docker:

```docker exec make -C DIRECTORY OPTIONS```

Para commits e PRs:

1. Login no GitHub

	```docker exec genesys gh auth login```

2. Todos os comandos gh estão disponiveis (https://cli.github.com/manual/)

	```docker exec genesys gh PARAMETERS```


Requisitos Não-Funcionais

- Permitir que o GenESyS possa ser desenvolvido num computador com Ubuntu, sem que o usuário precise ajustar o ambiente (instalar pacotes, dependências, etc) para o ambiente de desenvolvimento (com QtCreator).

   - Imagem contém todas as bibliotecas necessárias e o QtCreator.

- Permitir que o GenESyS possa ser utilizado num computador com Ubuntu, sem que o usuário precise ajustar o ambiente (instalar pacotes, dependências, etc) para executar a interface gráfica do GenESyS.

   - Imagem contém todas as bibliotecas necessárias e o QtCreator.

- Permitir que o GenESyS possa ser utilizado num computador com Windows 10, sem que o usuário precise ajustar o ambiente (instalar pacotes, dependências, etc) para executar a interface gráfica do GenESyS.

   - Sim, através da execução padrão de containeres Ubuntu em Windows (https://docs.docker.com/desktop/install/windows-install/).

- Permitir que o GenESyS possa ser utilizado por alunos em laboratório de informática na UFSC.

   - Sim.

- Permitir que alunos possa desenvolver e depurar o GenESyS em laboratório de informática na UFSC.

   - Imagem contém QtCreator e ferramentas de build, incluindo GDB.

Requisitos Funcionais

- Disponibilizar ambiente de desenvolvimento do GenESyS no Ubuntu sem que seja necessário instalar nada (além do docker)

   - Feito.

- Disponibilizar ambiente de execução da interface gráfica do GenESyS no Ubuntu sem que seja necessário instalar nada (além do docker)

   - Feito.

- Disponibilizar ambiente de execução da interface gráfica do GenESyS no Windows sem que seja necessário instalar nada (além do docker)

   - Feito.

- Permitir que usuários usando o ambiente de desenvolvimento tenham acesso sempre à última versão disponível do GenESyS num repositório do GitHub especificado pelo professor.

   - O container dá fetch automaticamente na branch especificada toda vez que é rodado, garantindo que o repositória esteja na última versão disponível.

- Permitir que usuários usando o ambiente de desenvolvimento possam fazer pull requests num repositório do GitHub especificado pelo professor para novos desenvolvimentos feitos por eles no GenESyS (após identificarem seu usuário no GitHub).

   - Imagem contém Git e GitHub CLI, que permite fazer todas as operações necessárias.

- Permitir que o professor possa editar facilmente mudanças nos ambientes do GenESyS que serão disponibilizados, como por exemplo qual é o repositório do GitHub a partir do qual o ambiente deve ser montado..

   - Variáveis de configuração no Dockerfile.
