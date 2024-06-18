#!/bin/bash

if [ $1 == "gui" ]; then
    $GENESYS_ROOT/$GENESYS_GUI_SUBPATH
elif [ $1 == "nogui" ]; then
    $GENESYS_ROOT/$GENESYS_NOGUI_SUBPATH
elif [ $1 == "qt" ]; then
    /usr/bin/qtcreator $GENESYS_ROOT/$GENESYS_PROJECT_SUBPATH
elif [ $1 == "debug" ]; then
    /bin/bash
fi

