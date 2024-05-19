#!/bin/bash

if [ -z "$REPO_PADRAO" ]; then
    # Se não for o repositório padrão, verifique se o repositório é privado
    read -p $'\nEste é um repositório privado (s/N)?\n> ' input_private
    if [ "$input_private" == "s" ]; then
        echo -e "\nPara poder fazer pull deste repositório, adicione a seguinte chave pública SSH à sua conta do GitHub:\n"
        cat ~/.ssh/id_rsa.pub

        read -p $'\nApós adicionar a chave à sua conta do GitHub, aperte ENTER para continuar.\n' input_dummy
    fi
fi

rm -rf /home/Genesys-Simulator
git clone ${clone_command} /home/Genesys-Simulator