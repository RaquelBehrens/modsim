#!/bin/bash
if [[ $REMOTE == 1 ]]; then
    echo "Executando a partir do código remoto"
    git -C $GENESYS_ROOT fetch --all
    git -C $GENESYS_ROOT reset --hard origin/$GENESYS_MAIN_BRANCH
else
    echo "Executando a partir do código local"
fi

if [ $1 == "gui" ]; then
    $GENESYS_ROOT/$GENESYS_GUI_SUBPATH
elif [ $1 == "nogui" ]; then
    $GENESYS_ROOT/$GENESYS_NOGUI_SUBPATH
elif [ $1 == "qt" ]; then
    /usr/bin/qtcreator $GENESYS_ROOT/$GENESYS_PROJECT_SUBPATH
elif [ $1 == "debug" ]; then
    /bin/bash
fi

