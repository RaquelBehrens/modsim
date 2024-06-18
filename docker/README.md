# GenESyS Docker

## Guia Rápido

Para configurar variáveis específicas de projeto, pode se utilizar o arquivo `config.sh`, dentro da pasta **scripts**. Neste arquivo é possível alterar propriedades da execução. Por padrão a execução via comandos make é local, ou seja, utiliza o código do repositório disponível localmente para desenvolvimento e execução. Para utilizar diretamente o código do repositório e não o código local, utiliza-se a variável `REMOTE=1`.

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
