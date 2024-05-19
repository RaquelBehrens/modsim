# Fluxo de funcionamento do script

## Passo 1: Imagem do Genesys Docker

O primeiro passo do script consiste em verificar se há uma imagem chamada `genesys-image` instalada no ambiente Docker local.
Se houver, o script prossegue com o fluxo normal. 

Se não houver, é verificado se há um Dockerfile no diretório atual.

Havendo um Dockerfile, é feito um prompt para o usuário questionando se este gostaria de compilar a imagem a partir do Dockerfile ou baixar a imagem do Docker Hub.

Caso o usuário opte por compilar a imagem, a imagem será comilada a partir do seguinte comando: 
```
docker build -t genesys-image .
```
Caso o usuário opte por baixar a imagem do Docker Hub, a imagem será baixada a partir do seguinte comando:

```
docker pull modsimgrupo6/genesys:1.0
docker image tag modsimgrupo6/genesys:1.0 genesys-image:latest
```

O nome do repositório em que a imagem se encontra no Docker Hub é `modsimgrupo6/genesys:1.0`, no entanto em nosso script nos referimos a imagem do Genesys Docker como `genesys-image`.
Desta forma, é preciso "renomear" a imagem do Docker Hub pelo comando `docker image tag`.

Caso não exista um Dockerfile no repositório atual (cenário em que só é disponibilizado o script `docker-genesys.sh` na máquina), será feito o download da imagem do Docker Hub.

## Passo 2: Configuração do Git

Após este fluxo, será feita a configuração do Git por meio de prompts ao usuário, nos quais serão requisitadas as seguintes informações:

- Username do Git
- Email do Git
- URL do repositório Git que será usado para lançar o Genesys
- Branch do repositório Git

Estas configurações serão salvas no arquivo `config.sh`, podendo ser alteradas neste mesmo arquivo.

Se o repositório Git for o repositório padrão do Genesys, [https://github.com/rlcancian2/Genesys-Simulator](https://github.com/rlcancian2/Genesys-Simulator), o usuário terá a opção de atualizar o repositório ou usar
o repositório no estado em que se encontra na imagem, possivelmente desatualizado.

- Se optar por atualizar o repositório, será feito um `git clone` dentro do container do Genesys Docker por meio do comando `docker run`.

- Se optar por não atualizar, então será baixada a novamente a imagem do Genesys Docker do Docker Hub, de modo a garantir que a imagem local é a imagem original disponibilizada no Docker Hub (note que se a imagem já tiver sido baixada, 
não será preciso fazer o download completo novamente).

Se o repositório do Git não for o padrão, será feito o clone deste dentro do container Genesys Docker.

**Autenticação:**

Para se autenticar no GitHub e poder fazer o push e pull de repositórios, é criado um par de chaves SSH (chave pública e chave privada) dentro do container por meio do script `generate-ssh-key`. O usuário deverá adicionar a chave pública SSH à
sua conta do GitHub para que este método de autenticação funcione.

A chave pública será escrita no arquivo `config.sh`, além de ser exibida no terminal em diversos momentos. 

## Passo 3: Menu de execução

Neste passo será apresentado ao usuário o menu de execução, com as seguintes opções de execução:

1. Genesys GUI
2. Genesys Shell
3. QtCreator
4. VSCode
5. Sair da aplicação

**Genesys GUI**

A interface gráfica do Genesys pode ser executada a partir do binário já disponibilizado no repositório do Genesys ou a partir da compilação do código fonte.

No primeiro caso, será executado o binário `GenesysQtGUI` disponibilizado na raiz do repositório padrão do Genesys.

No segundo caso, o código fonte será compilado pelo script `recompile-gui`, gerando um executável que será executado pelo container.

**Genesys Shell**

A aplicação shell do Genesys pode ser executada a partir do binário já disponibilizado no repositório do Genesys ou a partir da compilação do código fonte.

No primeiro caso, será executado o binário `GenesysShell` disponibilizado na raiz do repositório padrão do Genesys.

No segundo caso, o código fonte será compilado pelo script `recompile-shell`, gerando um executável que será executado pelo container.

No estado que o repositório Genesys se encontra no momento (commit 06b7814) não foi possível compilar o Genesys Shell por conta de algumas incorreções em arquivos de compilação. 
Neste repositório foram feitas as correções necessárias para que seja possível compilar o Genesys Shell.

**QTCreator**

A IDE do Genesys será executada a partir do comando `run-qtcreator`.

**VSCode**

Além do QTCreator, foi disponibilizada uma IDE alternativa para desenvolvimento, o VSCode. Esta IDE fornece um excelente suporte para o controle de versão do código, sendo possível visualizar com mais clareza 
os diffs no código fonte e realizar commits de forma facilitada.


# Arquivos e Diretórios do projeto

Todos os arquivos e diretórios relativos à dockerização do Genesys encontram-se na pasta `docker/`

No diretório `container-scripts/` encontram-se os scripts que são importados para dentro do container e executados dentro deste.

- **clone-repo.sh** : Script para apagar o repositório atual do Genesys do container e fazer clone de um novo repositório.
- **generate-ssh-key** : Script de geração de par de chaves SSH
- **recompile-gui** : Script de compilação da aplicação de interface gráfica do Genesys a partir do código fonte.
- **recompile-shell** : Script de compilação da aplicação shell do Genesys a partir do código fonte.
- **run-genesys.sh** : Script de execução dos programas do menu de execução.

No diretório `docker` encontram-se os scripts que são executados na máquina host:

- **config.sh** : Arquivo de configuração do projeto.
- **docker-genesys.sh** : Script de execução do projeto.
- **Dockerfile** : Script Dockerfile para compilação da imagem do Genesys Docker.

# Considerações Gerais

## Aplicações com interface gráfica dentro do container

Para que seja possível exibir janelas de aplicações de interface gráfica que executam dentro do container, foi preciso mapear o socket do X11 da máquina host com o container. 
Além disto, foi criado um token de acesso do X11 por meio do `xauth`, o qual foi também foi preciso mapear para dentro do container. O token de acesso é gerado pelo seguinte comando na máquina host (executado pelo script `docker-genesys.sh`):
```
xauth nlist $DISPLAY | sed -e 's/^..../ffff/' | xauth -f $XAUTH nmerge -
```

Para isto foi utilizada a funcionalidade de volumes do Docker, por meio da qual foi feito o seguinte mapeamento:

```
-v /tmp/.X11-unix:/tmp/.X11-unix
-v /tmp/.docker.xauth
```

O mapeamento destes volumes, juntamente com a passagem da variável de ambiente $DISPLAY da máquina host para o container (por meio do argumento `-e DISPLAY=$DISPLAY`) são suficientes para que seja possível rodar aplicações de interface gráfica
dentro do container.

## Execução de comandos no container durante execução do script

Durante a execução do script, diversas vezes são executados comandos dentro container. Visto que o container é uma entidade efêmera que perde seu estado após a finalização, depois da execução de cada comando no container 
é feito o salvamento do estado deste em uma nova imagem, por meio do comando `docker commit genesys-container genesys-image` .
