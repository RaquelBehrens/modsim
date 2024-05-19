#!/bin/bash
$command

# Salvar o trabalho
echo -e "\n==============================================================================="
echo -e "Não se esqueça de salvar seu trabalho. Commite suas alterações e faça o push.\nVocê pode usar o VSCode para fazer o controle de versão do seu código.\n\nComandos úteis\n.............."
echo -e "vscode: Executar o VSCode\nrecompile-gui: Recompile a interface gráfica do Genesys a partir do código-fonte"
echo -e "recompile-shell: Recompile a aplicação shell do Genesys a partir do código-fonte"
echo -e "===============================================================================\n"

read -p $'Gostaria de acessar o terminal antes de sair (s/N)?\n> ' input_access_terminal

if [ "$input_access_terminal" == "s" ]; then

  git config --global user.email "${GIT_USER_EMAIL}"
  git config --global user.name "${GIT_USERNAME}"

  echo -e "\nPara sair do terminal tecle Ctrl+D"
  echo -e "Para poder fazer push e pull requests para um repositório do GitHub, adicione a seguinte chave pública SSH à sua conta do GitHub:\n"

  cat ~/.ssh/id_rsa.pub

  echo ""

  cd /home/Genesys-Simulator && bash     
fi

