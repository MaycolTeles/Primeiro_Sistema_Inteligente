#ifndef INTERFACE_H_INCLUDED        // Se "INTERFACE_H_INCLUDED" não foi definido
#define INTERFACE_H_INCLUDED        // Defina "INTERFACE_H_INCLUDED"

#include <string>               // Para poder utilizar strings
#include <vector>               // Para utilizar vector (vetor dinâmico)
#include "Sensores.h"           // Para utilizar os sensores

using namespace std;            // Para evitar o uso de "std::" como em "std::string", por exemplo

// DEFININDO UMA CLASSE:
class Interface{

    // DECLARANDO OS ATRIBUTOS:
    private:

        string nomeUsuario;         // O nome do usuário
        int numeroSensores;         // O número de sensores
        vector<Sensor *> sensores;  // Vetor dinâmico (array dinâmico) de sensores
        Sensor* sensor;             // "sensor" é do tipo "*Sensor" (Todo objeto em C++ é um ponteiro, então cada "sensor" é um ponteiro da classe "Sensor"

    // PROTOTIPANDO OS MÉTODOS:
    public:

        // Métodos Acessores (Getters), Modificadores (Setters) e Construtor (Construct)
		// Normalmente, todo método Getter, Setter e Constructor é PÚBLICO!! (public)
		// Métodos Setter normalmente PRECISAM de parâmetros, do mesmo tipo do atributo.

		// O método construtor deve possuir o mesmo nome da classe.
		// No C++, não é preciso declarar "void", apenas o nome da classe.
        Interface();      // Instancia uma nova interface


        void set_nomeUsuario(string &nomeUsuario);  // Seta o nome do usuário
        string get_nomeUsuario();                   // Retorna o nome do usuário

        void set_numeroSensores(int &numeroSensores);  // Seta o número de sensores (static = é o mesmo valor para qualquer objeto [o total de sensores é constante para todos os sensores] )
        int get_numeroSensores();                      // Retorna o número de sensores (static = mesmo valor para qualquer objeto [o total de sensores deve ser igual para todos os sensores] )


        // MÉTODOS EXCLUSIVOS:
        void introducao(string &nomeUsuario);   // Aparece quando o aplicativo é aberto (código inicia)
        void encerrar();                        // Para encerrar o programa
        void menuOpcao();                       // Para apresentar o menu de opções
        void selecionaOpcao(char opcao);        // Testa qual foi a opção digitada
        void criarSensor(int &numeroSensores, string modelo = "");  // Para criar (instanciar) um novo sensor (O modelo pode ser passado ou não para a função)
        void deletarSensor();                   // Para deletar um sensor já criado
        void mostrarSensores();                 // Para exibir todos os sensores criados
        void mostrarModelos();                  // Para exibir todos os modelos de sensores criados


};

#endif // INTERFACE_H_INCLUDED

// Fim do if
