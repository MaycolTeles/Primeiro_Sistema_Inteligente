#ifndef SENSORES_H_INCLUDED     // Se SENSORES_H_INCLUDED não foi definido
#define SENSORES_H_INCLUDED     // Defina SENSORES_H_INCLUDED

#include <string>               // Para poder utilizar string

using namespace std;            // Para não precisar escrever "std::" como em "std::string", por exemplo

// DEFININDO UMA CLASSE
class Sensor{

    // DECLARANDO OS ATRIBUTOS:
    // Para fazer um bom encapsulamento, TODOS OS ATRIBUTOS devem ser setados como PRIVADOS!! (private)
    private:
        string nome;                // Nome do sensor
        string tipo;                // Tipo do sensor
        float valor;                // Valor(medida) do sensor
        bool status;                // Status atual do sensor (habilitado/desabilitado - ligado/desligado - on/off)
        int index;                  // Index do sensor (posição dele no vetor)

    // PROTOTIPANDO OS MÉTODOS:
    public:



        // MÉTODOS ACESSORES (Getters), MODIFICADORES (Setters) e CONSTRUTOR (Construct)
		// Normalmente, todo método Getter, Setter e Constructor é PÚBLICO!! (public)
		// Métodos Setter normalmente PRECISAM de parâmetros, do mesmo tipo do atributo.

		// O método construtor deve possuir o mesmo nome da classe.
		// No C++, não é preciso declarar "void", apenas o nome da classe.
        Sensor(string nomeSensor, string tipoSensor, int numeroSensores);  // Instancia um novo sensor, com o seu nome, tipo e index correspondentes

        void inicio();           // Para zerar o número de sensores, chama somente quando inicia o programa

        void set_nome(string nomeSensor);   // Seta o nome do sensor
        string get_nome();                  // Retorna o nome do sensor

        void set_tipo(string tipoSensor);   // Seta o tipo do sensor
        string get_tipo();                  // Retorna o tipo do sensor


        void set_valor(float valorSensor);  // Seta um valor de medida para o sensor
        float get_valor();                  // Retorna um valor de medida do sensor


        void set_status(bool statusSensor); // Seta o status do sensor (ligado/desligado)
        bool get_status();                  // Retorna o status do sensor (ligado/desligado)


        void set_index(int numeroSensores);    // Seta o index do sensor (sua posição/número/valor absoluto)
        int get_index();                       // Retorna o index do sensor (sua posição/número/valor absoluto)



        // MÉTODOS EXCLUSIVOS:
        bool habilitaSensor(Sensor &sensor);     // Para habilitar (ativar/ligar) um sensor já criado
        bool desabilitaSensor(Sensor &sensor);   // Para desabilitar (desativar/desligar) um sensor já criado

};



#endif // SENSORES_H_INCLUDED

// Fim do if
