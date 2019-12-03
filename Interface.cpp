#include <iostream>
#include "Interface.h"
#include "Sensores.h"   // Para poder criar/deletar sensores, etc

using namespace std;        // Para evitar o uso do "std::" como em "std::cout", por exemplo


            // CONSTRUTOR (Construct)

// Instancia uma nova interface
Interface :: Interface(){

    int numero = 0;

    set_numeroSensores(numero);
    introducao(nomeUsuario);

    return;
}

            // M�TODOS ACESSORES (Getters)
            // E MODIFICADORES (Setters)



// Seta o nome do usu�rio
void Interface :: set_nomeUsuario(string &nomeUsuario){

    this->nomeUsuario = nomeUsuario;

    return;
}

// Retorna o nome do usu�rio
string Interface :: get_nomeUsuario(){

    return nomeUsuario;
}

// Seta o n�mero de sensores
void Interface :: set_numeroSensores(int &numeroSensores){

    this->numeroSensores = numeroSensores;  // O n�mero de sensores DESSE (this->) objeto recebe o n�mero de sensores do argumento da fun��o (int &numeroSensores)

    return;
}

// Retorna o n�mero de sensores
int Interface :: get_numeroSensores(){

    return numeroSensores;
}




            // M�TODOS EXCLUSIVOS:

// Aparece quando o aplicativo � aberto (c�digo inicia)
void Interface :: introducao(string &nomeUsuario){

    cout << "Ol�! Seja muito Bem-Vindo(a) ao AtuaSensor! Por favor, insira seu nome: ";

    while(getline(cin, nomeUsuario) && nomeUsuario == ""){          // Se o usu�rio n�o digitar nada (der enter)
        cout << endl;
        cout << "Desculpe-me, mas acredito que esse n�o seja o seu nome mesmo. Poderia, por favor, inserir o seu nome, para que possamos nos familiarizar?" << endl;
        cout << "Insira seu nome: ";
    }


    set_nomeUsuario(nomeUsuario);           // Seta o nome do usu�rio para o nome digitado

    cout << endl;
    cout << "Estamos muito contentes em ter voc� por aqui, " << nomeUsuario << "! ";
    cout << "Apresentaremos o Menu de Op��es aqui, para que voc� possa escolher o que deseja fazer." << endl;

    menuOpcao();

    return;
}

// Para encerrar o programa
void Interface :: encerrar(){

    return;
}

// Para apresentar o menu de op��es
void Interface :: menuOpcao(){

                    // DECLARA��O DE VARI�VEIS:

    int opcaoMenu;          // O n�mero digitado pelo usu�rio no menu
    char opcao;             // Para converter o n�mero digitado para um caracter
    bool first = true;      // Vari�vel auxiliar para saber se � a primeira vez que o usu�rio erra o dado de entrada


                    // PROCESSAMENTO:

    do{
        if(first){
            cout << endl << "Digite a op��o desejada no menu abaixo:" << endl;
            first = false;
        }
        else cout << "Desculpe, " << nomeUsuario << ", mas essa op��o n�o est� dispon�vel. Por favor, selecione uma op��o v�lida de acordo com o menu abaixo:" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "| 1 - Criar um novo sensor     2 - Criar um sensor a partir de um modelo j� criado   3 - Exibir todos os sensores     |" << endl;
        cout << "|        4 - Excluir um sensor         5 - Carregar sensores j� criados        6 - Consultar os dados de um sensor    |" << endl;
        cout << "| 7 - Editar o nome ou tipo do sensor      8 - Fazer alguma coisa daora   9 - Sair do programa                        |" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << endl << "Op��o desejada: ";
        cin >> opcaoMenu;
        cout << endl;
    }while(opcaoMenu < 1 || opcaoMenu > 9);

    opcao = opcaoMenu + '0';          // Convertendo a op��o entrada para um inteiro

    selecionaOpcao(opcao);

    return;
}

// Testa qual foi a op��o digitada
void Interface :: selecionaOpcao(char opcao){

    switch(opcao){                      // Testa a op��o digitada pelo usu�rio
        case '1':       // Criar um sensor do zero
            cout << "Muito bem! Vamos criar um novo sensor!" << endl << endl;
            criarSensor(numeroSensores);
            break;

        case '2':       // Criar um sensor a partir de um template
            if(sensores.size() == 0){
                cout << "Voc� ainda n�o tem nenhum modelo de sensor adicionado! Por favor, adicione um sensor antes de tentar criar um novo a partir de um modelo pronto." << endl;
                menuOpcao();
            }
            cout << "Excelente! Por favor, escolha um modelo de sensor dentre os j� criados:" << endl << endl;
            mostrarModelos();
            break;

        case '3':       // Exibir os sensores j� criados
            if(sensores.size() == 0){
                cout << "Voc� ainda n�o tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar exibi-los." << endl;
                menuOpcao();
            }
            cout << "Excelente! Exibirei todos os sensores cadastrados at� agora:" << endl << endl;
            mostrarSensores();
            break;

        case '4':       // Exclui um sensor
            if(sensores.size() == 0){
                cout << "Voc� ainda n�o tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar excluir algum." << endl;
                menuOpcao();
            }
            cout << "Perfeito! Vamos eliminar esse sensor!" << endl << endl;
            deletarSensor();
            break;

        case '5':       // L� os sensores cadastrados no Banco de Dados (um arquivo txt)
            if(sensores.size() == 0){
                cout << "Voc� ainda n�o tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar excluir algum." << endl;
                menuOpcao();
            }
            cout << "Perfeito! Vamos eliminar esse sensor!" << endl << endl;
            deletarSensor();
            break;

        case '6':       // Consultar as �ltimas medidas e dados do sensor
            if(sensores.size() == 0){
                cout << "Voc� ainda n�o tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar excluir algum." << endl;
                menuOpcao();
            }
            cout << "Perfeito! Vamos eliminar esse sensor!" << endl << endl;
            deletarSensor();
            break;

        case '7':
            if(sensores.size() == 0){       // Altera o nome ou tipo do sensor
                cout << "Voc� ainda n�o tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar excluir algum." << endl;
                menuOpcao();
            }
            cout << "Perfeito! Vamos eliminar esse sensor!" << endl << endl;
            deletarSensor();
            break;

        case '8':       // Fazer alguma coisa daora
            cout << "FAZER ALGUMA COISA MASSA" << endl;
            break;

        case '9':       // Encerra o programa
            encerrar();

        default:
            cout << "Esta op��o � inv�lida. Por favor, insira uma op��o v�lida do menu abaixo: " << endl;
            menuOpcao();

    }

    return;
}

// Para criar (instanciar) um novo sensor
void Interface :: criarSensor(int &numeroSensores, string modelo){

                // DECLARA��O DE VARI�VEIS:

    string nome, tipo;       // Nome e tipo do sensor
    int i = numeroSensores;  // Contador auxiliar
    bool first = true;       // Vari�vel auxiliar para identificar erro do usu�rio

                // PROCESSAMENTO:

    cin.ignore();               // Limpar o buffer do "enter"


    do{                     // Repete esse la�o at� que o usu�rio entre com um NOME V�LIDO
        if(first)
            first = false;
        else cout << "Perdoe-me, mas esse n�o � um nome v�lido. Por favor, escolha um outro nome para seu sensor." << endl << endl;

        cout << "Digite o nome do sensor que voc� deseja criar: ";
        getline(cin, nome);


    }while(nome == "");     // NOME V�LIDO != "" (Nome v�lido pode ser qualquer coisa, menos "enter")


    if(!first)              // Caso o usu�rio tenha errado na hora de digitar o nome, seta para verdadeiro
        first = true;       // Para que ele possa errar na hora de digitar o tipo

    if(modelo == ""){      // Se estiver criando um modelo do zero
        do{                  // Repete esse la�o at� que o usu�rio entre com um TIPO V�LIDO
            if(first){
                cout << "Agora, digite o tipo do sensor que voc� deseja criar: ";
                first = false;
            }
            else{
                cout << "Perdoe-me, mas esse n�o � um tipo v�lido. Por favor, escolha um outro tipo para seu sensor." << endl << endl;
                cout << "Digite o tipo do sensor que voc� deseja criar: ";
            }
            getline(cin, tipo);
        }while(tipo == "");     // TIPO V�LIDO != "" (Nome v�lido pode ser qualquer coisa, menos "enter")
    }
    else{                   // Se estiver criando o modelo de um template/preset j� existente
        tipo = modelo;      // O tipo do sensor vai ser de um template/preset j� existente
    }


    sensor = new Sensor(nome, tipo, numeroSensores);
    sensores.push_back(sensor);


    if(sensores[i] != NULL){
        cout << endl << "O sensor \"" << sensores[i]->get_nome() << "\" foi criado na posi��o " << sensores[i]->get_index() << endl;
        numeroSensores++;
        menuOpcao();
    }

    cout << "N�o foi poss�vel criar o sensor \"" << sensores[i]->get_nome() << "\". Por favor, tente novamente." << endl;
    criarSensor(numeroSensores);

    return;
}

// Para deletar um sensor j� criado
void Interface :: deletarSensor(){

    char opcao;         // Op��o digitada pelo usu�rio
    int i;              // Sensor a ser removido ser� o da posi��o i
    bool first = true;  // Vari�vel para testar erro do usu�rio

    do{
        if(first)
            first = false;
        else cout << "Me desculpe, mas essa op��o � inv�lida." << endl << endl;

        cout << "Por favor, insira o n�mero do sensor que voc� deseja remover. Caso n�o saiba, digite \"m\" para exibir o menu de sensores e confirmar o n�mero do sensor que voc� deseja remover: ";
        cin >> opcao;

        i = opcao - '0';      // Transformando a op��o (char) digitada em um n�mero do sensor desejado (int)

    }while(opcao != 'm' && i / i == 0);

    i--;

    cout << endl;

    if(opcao == 'm')
        mostrarSensores();



    if(sensores[i] == NULL){
        cout << "Perdoe-me, mas n�o h� nenhum sensor com esse valor ou index. Se poss�vel, tente novamente." << endl << endl;
        deletarSensor();
    }

    cout << "O sensor " << sensores[i]->get_nome() << " est� sendo deletado. Aguarde um instante..." << endl;

    delete sensores[i];                      // Deletando o sensor do programa (Liberando a mem�ria)
    sensores.erase(sensores.begin() + i);    // Removendo o sensor desejado do vector e organizando dinamicamente os que sobraram


    numeroSensores--;

    set_numeroSensores(numeroSensores);


    menuOpcao();

    return;
}

// Para exibir todos os sensores criados
void Interface :: mostrarSensores(){

    for(int i = 0; i < get_numeroSensores(); i++){
        cout << "Sensor " << sensores[i]->get_index() << ":" << endl;
        cout << "   Nome do Sensor: " << sensores[i]->get_nome() << endl;
        cout << "   Tipo do Sensor: " << sensores[i]->get_tipo() << endl;
        cout << "---------------------" << endl;

    }

    menuOpcao();

    return;
}

// Para exibir todos os modelos de sensores criados
void Interface :: mostrarModelos(){

    string modelo;

    cout << "Os tipos de sensores j� criados at� agora foram: " << endl;

    for(int i = 0; i < get_numeroSensores(); i++)
        cout << sensores[i]->get_tipo() << endl;

    cout << endl << "Agora, se poss�vel, selecione o tipo do sensor j� existente para criar um com o mesmo modelo: " << endl;
    getline(cin, modelo);
    cin.ignore();               // Limpar o buffer do "enter"

    criarSensor(numeroSensores, modelo);

    return;
}
