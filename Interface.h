#ifndef INTERFACE_H_INCLUDED        // Se "INTERFACE_H_INCLUDED" n�o foi definido
#define INTERFACE_H_INCLUDED        // Defina "INTERFACE_H_INCLUDED"

#include <string>               // Para poder utilizar strings
#include <vector>               // Para utilizar vector (vetor din�mico)
#include "Sensores.h"           // Para utilizar os sensores

using namespace std;            // Para evitar o uso de "std::" como em "std::string", por exemplo

// DEFININDO UMA CLASSE:
class Interface{

    // DECLARANDO OS ATRIBUTOS:
    private:

        string nomeUsuario;         // O nome do usu�rio
        int numeroSensores;         // O n�mero de sensores
        vector<Sensor *> sensores;  // Vetor din�mico (array din�mico) de sensores
        Sensor* sensor;             // "sensor" � do tipo "*Sensor" (Todo objeto em C++ � um ponteiro, ent�o cada "sensor" � um ponteiro da classe "Sensor"

    // PROTOTIPANDO OS M�TODOS:
    public:

        // M�todos Acessores (Getters), Modificadores (Setters) e Construtor (Construct)
		// Normalmente, todo m�todo Getter, Setter e Constructor � P�BLICO!! (public)
		// M�todos Setter normalmente PRECISAM de par�metros, do mesmo tipo do atributo.

		// O m�todo construtor deve possuir o mesmo nome da classe.
		// No C++, n�o � preciso declarar "void", apenas o nome da classe.
        Interface();      // Instancia uma nova interface


        void set_nomeUsuario(string &nomeUsuario);  // Seta o nome do usu�rio
        string get_nomeUsuario();                   // Retorna o nome do usu�rio

        void set_numeroSensores(int &numeroSensores);  // Seta o n�mero de sensores (static = � o mesmo valor para qualquer objeto [o total de sensores � constante para todos os sensores] )
        int get_numeroSensores();                      // Retorna o n�mero de sensores (static = mesmo valor para qualquer objeto [o total de sensores deve ser igual para todos os sensores] )


        // M�TODOS EXCLUSIVOS:
        void introducao(string &nomeUsuario);   // Aparece quando o aplicativo � aberto (c�digo inicia)
        void encerrar();                        // Para encerrar o programa
        void menuOpcao();                       // Para apresentar o menu de op��es
        void selecionaOpcao(char opcao);        // Testa qual foi a op��o digitada
        void criarSensor(int &numeroSensores, string modelo = "");  // Para criar (instanciar) um novo sensor (O modelo pode ser passado ou n�o para a fun��o)
        void deletarSensor();                   // Para deletar um sensor j� criado
        void mostrarSensores();                 // Para exibir todos os sensores criados
        void mostrarModelos();                  // Para exibir todos os modelos de sensores criados


};

#endif // INTERFACE_H_INCLUDED

// Fim do if
