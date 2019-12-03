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

            // MÉTODOS ACESSORES (Getters)
            // E MODIFICADORES (Setters)



// Seta o nome do usuário
void Interface :: set_nomeUsuario(string &nomeUsuario){

    this->nomeUsuario = nomeUsuario;

    return;
}

// Retorna o nome do usuário
string Interface :: get_nomeUsuario(){

    return nomeUsuario;
}

// Seta o número de sensores
void Interface :: set_numeroSensores(int &numeroSensores){

    this->numeroSensores = numeroSensores;  // O número de sensores DESSE (this->) objeto recebe o número de sensores do argumento da função (int &numeroSensores)

    return;
}

// Retorna o número de sensores
int Interface :: get_numeroSensores(){

    return numeroSensores;
}




            // MÉTODOS EXCLUSIVOS:

// Aparece quando o aplicativo é aberto (código inicia)
void Interface :: introducao(string &nomeUsuario){

    cout << "Olá! Seja muito Bem-Vindo(a) ao AtuaSensor! Por favor, insira seu nome: ";

    while(getline(cin, nomeUsuario) && nomeUsuario == ""){          // Se o usuário não digitar nada (der enter)
        cout << endl;
        cout << "Desculpe-me, mas acredito que esse não seja o seu nome mesmo. Poderia, por favor, inserir o seu nome, para que possamos nos familiarizar?" << endl;
        cout << "Insira seu nome: ";
    }


    set_nomeUsuario(nomeUsuario);           // Seta o nome do usuário para o nome digitado

    cout << endl;
    cout << "Estamos muito contentes em ter você por aqui, " << nomeUsuario << "! ";
    cout << "Apresentaremos o Menu de Opções aqui, para que você possa escolher o que deseja fazer." << endl;

    menuOpcao();

    return;
}

// Para encerrar o programa
void Interface :: encerrar(){

    return;
}

// Para apresentar o menu de opções
void Interface :: menuOpcao(){

                    // DECLARAÇÃO DE VARIÁVEIS:

    int opcaoMenu;          // O número digitado pelo usuário no menu
    char opcao;             // Para converter o número digitado para um caracter
    bool first = true;      // Variável auxiliar para saber se é a primeira vez que o usuário erra o dado de entrada


                    // PROCESSAMENTO:

    do{
        if(first){
            cout << endl << "Digite a opção desejada no menu abaixo:" << endl;
            first = false;
        }
        else cout << "Desculpe, " << nomeUsuario << ", mas essa opção não está disponível. Por favor, selecione uma opção válida de acordo com o menu abaixo:" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "| 1 - Criar um novo sensor     2 - Criar um sensor a partir de um modelo já criado   3 - Exibir todos os sensores     |" << endl;
        cout << "|        4 - Excluir um sensor         5 - Carregar sensores já criados        6 - Consultar os dados de um sensor    |" << endl;
        cout << "| 7 - Editar o nome ou tipo do sensor      8 - Fazer alguma coisa daora   9 - Sair do programa                        |" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << endl << "Opção desejada: ";
        cin >> opcaoMenu;
        cout << endl;
    }while(opcaoMenu < 1 || opcaoMenu > 9);

    opcao = opcaoMenu + '0';          // Convertendo a opção entrada para um inteiro

    selecionaOpcao(opcao);

    return;
}

// Testa qual foi a opção digitada
void Interface :: selecionaOpcao(char opcao){

    switch(opcao){                      // Testa a opção digitada pelo usuário
        case '1':       // Criar um sensor do zero
            cout << "Muito bem! Vamos criar um novo sensor!" << endl << endl;
            criarSensor(numeroSensores);
            break;

        case '2':       // Criar um sensor a partir de um template
            if(sensores.size() == 0){
                cout << "Você ainda não tem nenhum modelo de sensor adicionado! Por favor, adicione um sensor antes de tentar criar um novo a partir de um modelo pronto." << endl;
                menuOpcao();
            }
            cout << "Excelente! Por favor, escolha um modelo de sensor dentre os já criados:" << endl << endl;
            mostrarModelos();
            break;

        case '3':       // Exibir os sensores já criados
            if(sensores.size() == 0){
                cout << "Você ainda não tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar exibi-los." << endl;
                menuOpcao();
            }
            cout << "Excelente! Exibirei todos os sensores cadastrados até agora:" << endl << endl;
            mostrarSensores();
            break;

        case '4':       // Exclui um sensor
            if(sensores.size() == 0){
                cout << "Você ainda não tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar excluir algum." << endl;
                menuOpcao();
            }
            cout << "Perfeito! Vamos eliminar esse sensor!" << endl << endl;
            deletarSensor();
            break;

        case '5':       // Lê os sensores cadastrados no Banco de Dados (um arquivo txt)
            if(sensores.size() == 0){
                cout << "Você ainda não tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar excluir algum." << endl;
                menuOpcao();
            }
            cout << "Perfeito! Vamos eliminar esse sensor!" << endl << endl;
            deletarSensor();
            break;

        case '6':       // Consultar as últimas medidas e dados do sensor
            if(sensores.size() == 0){
                cout << "Você ainda não tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar excluir algum." << endl;
                menuOpcao();
            }
            cout << "Perfeito! Vamos eliminar esse sensor!" << endl << endl;
            deletarSensor();
            break;

        case '7':
            if(sensores.size() == 0){       // Altera o nome ou tipo do sensor
                cout << "Você ainda não tem nenhum sensor adicionado! Por favor, adicione um sensor antes de tentar excluir algum." << endl;
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
            cout << "Esta opção é inválida. Por favor, insira uma opção válida do menu abaixo: " << endl;
            menuOpcao();

    }

    return;
}

// Para criar (instanciar) um novo sensor
void Interface :: criarSensor(int &numeroSensores, string modelo){

                // DECLARAÇÃO DE VARIÁVEIS:

    string nome, tipo;       // Nome e tipo do sensor
    int i = numeroSensores;  // Contador auxiliar
    bool first = true;       // Variável auxiliar para identificar erro do usuário

                // PROCESSAMENTO:

    cin.ignore();               // Limpar o buffer do "enter"


    do{                     // Repete esse laço até que o usuário entre com um NOME VÁLIDO
        if(first)
            first = false;
        else cout << "Perdoe-me, mas esse não é um nome válido. Por favor, escolha um outro nome para seu sensor." << endl << endl;

        cout << "Digite o nome do sensor que você deseja criar: ";
        getline(cin, nome);


    }while(nome == "");     // NOME VÁLIDO != "" (Nome válido pode ser qualquer coisa, menos "enter")


    if(!first)              // Caso o usuário tenha errado na hora de digitar o nome, seta para verdadeiro
        first = true;       // Para que ele possa errar na hora de digitar o tipo

    if(modelo == ""){      // Se estiver criando um modelo do zero
        do{                  // Repete esse laço até que o usuário entre com um TIPO VÁLIDO
            if(first){
                cout << "Agora, digite o tipo do sensor que você deseja criar: ";
                first = false;
            }
            else{
                cout << "Perdoe-me, mas esse não é um tipo válido. Por favor, escolha um outro tipo para seu sensor." << endl << endl;
                cout << "Digite o tipo do sensor que você deseja criar: ";
            }
            getline(cin, tipo);
        }while(tipo == "");     // TIPO VÁLIDO != "" (Nome válido pode ser qualquer coisa, menos "enter")
    }
    else{                   // Se estiver criando o modelo de um template/preset já existente
        tipo = modelo;      // O tipo do sensor vai ser de um template/preset já existente
    }


    sensor = new Sensor(nome, tipo, numeroSensores);
    sensores.push_back(sensor);


    if(sensores[i] != NULL){
        cout << endl << "O sensor \"" << sensores[i]->get_nome() << "\" foi criado na posição " << sensores[i]->get_index() << endl;
        numeroSensores++;
        menuOpcao();
    }

    cout << "Não foi possível criar o sensor \"" << sensores[i]->get_nome() << "\". Por favor, tente novamente." << endl;
    criarSensor(numeroSensores);

    return;
}

// Para deletar um sensor já criado
void Interface :: deletarSensor(){

    char opcao;         // Opção digitada pelo usuário
    int i;              // Sensor a ser removido será o da posição i
    bool first = true;  // Variável para testar erro do usuário

    do{
        if(first)
            first = false;
        else cout << "Me desculpe, mas essa opção é inválida." << endl << endl;

        cout << "Por favor, insira o número do sensor que você deseja remover. Caso não saiba, digite \"m\" para exibir o menu de sensores e confirmar o número do sensor que você deseja remover: ";
        cin >> opcao;

        i = opcao - '0';      // Transformando a opção (char) digitada em um número do sensor desejado (int)

    }while(opcao != 'm' && i / i == 0);

    i--;

    cout << endl;

    if(opcao == 'm')
        mostrarSensores();



    if(sensores[i] == NULL){
        cout << "Perdoe-me, mas não há nenhum sensor com esse valor ou index. Se possível, tente novamente." << endl << endl;
        deletarSensor();
    }

    cout << "O sensor " << sensores[i]->get_nome() << " está sendo deletado. Aguarde um instante..." << endl;

    delete sensores[i];                      // Deletando o sensor do programa (Liberando a memória)
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

    cout << "Os tipos de sensores já criados até agora foram: " << endl;

    for(int i = 0; i < get_numeroSensores(); i++)
        cout << sensores[i]->get_tipo() << endl;

    cout << endl << "Agora, se possível, selecione o tipo do sensor já existente para criar um com o mesmo modelo: " << endl;
    getline(cin, modelo);
    cin.ignore();               // Limpar o buffer do "enter"

    criarSensor(numeroSensores, modelo);

    return;
}
