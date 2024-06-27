source ./scripts/config.sh

while true
do
read -p "
Menu: O que deseja executar?
.............................
1. Build GenESyS Image
2. Debug GenESyS Image
3. GenESyS GUI
4. GenESyS Shell
5. IDE do GenESyS (QtCreator)
6. Sair da aplicação
> " input

    if [ "$input" == "6" ]; then
        break
    fi

    case "$input" in
        "1")
        bash ./scripts/build.sh
        ;;
        "2")
        bash ./scripts/debug.sh
        ;;
        "3")
        bash ./scripts/gui.sh
        ;;
        "4")
        bash ./scripts/shell.sh
        ;;
        "5")
        bash ./scripts/qt.sh
        ;;
        *)
        echo -e "\nOpção inválida."
        ;;
    esac
done
