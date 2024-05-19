source ./scripts/config.sh

while true
do
read -p "
Menu: O que deseja executar?
.............................
1. Build GenESyS Image
2. GenESyS GUI
3. GenESyS Shell
4. IDE do GenESyS (QtCreator)
5. Sair da aplicação
> " input

    if [ "$input" == "5" ]; then
        break
    fi

    case "$input" in
        "1")
        bash ./scripts/build.sh
        ;;       
        "2")
        bash ./scripts/gui.sh
        ;;
        "3")
        bash ./scripts/shell.sh
        ;;
        "4")
        bash ./scripts/qt.sh
        ;;
        *)
        echo -e "\nOpção inválida."
        ;;
    esac
done
