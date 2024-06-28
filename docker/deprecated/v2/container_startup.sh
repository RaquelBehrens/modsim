#!/bin/bash

# Garante que a versão do repositório do GenESyS é a última possível
git -C $GENESYS_CLONE_PATH fetch --all
git -C $GENESYS_CLONE_PATH reset --hard origin/$GENESYS_BRANCH

if [ $1 == "gui" ]; then
    $GENESYS_CLONE_PATH$GENESYS_GUI_SUBPATH
elif [ $1 == "nogui" ]; then
    $GENESYS_CLONE_PATH$GENESYS_NOGUI_SUBPATH
else
    /usr/bin/qtcreator $GENESYS_CLONE_PATH$GENESYS_PROJECT_SUBPATH
fi

