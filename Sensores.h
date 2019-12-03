#ifndef SENSORES_H_INCLUDED     // Se SENSORES_H_INCLUDED n�o foi definido
#define SENSORES_H_INCLUDED     // Defina SENSORES_H_INCLUDED

#include <string>               // Para poder utilizar string

using namespace std;            // Para n�o precisar escrever "std::" como em "std::string", por exemplo

// DEFININDO UMA CLASSE
class Sensor{

    // DECLARANDO OS ATRIBUTOS:
    // Para fazer um bom encapsulamento, TODOS OS ATRIBUTOS devem ser setados como PRIVADOS!! (private)
    private:
        string nome;                // Nome do sensor
        string tipo;                // Tipo do sensor
        float valor;                // Valor(medida) do sensor
        bool status;                // Status atual do sensor (habilitado/desabilitado - ligado/desligado - on/off)
        int index;                  // Index do sensor (posi��o dele no vetor)

    // PROTOTIPANDO OS M�TODOS:
    public:



        // M�TODOS ACESSORES (Getters), MODIFICADORES (Setters) e CONSTRUTOR (Construct)
		// Normalmente, todo m�todo Getter, Setter e Constructor � P�BLICO!! (public)
		// M�todos Setter normalmente PRECISAM de par�metros, do mesmo tipo do atributo.

		// O m�todo construtor deve possuir o mesmo nome da classe.
		// No C++, n�o � preciso declarar "void", apenas o nome da classe.
        Sensor(string nomeSensor, string tipoSensor, int numeroSensores);  // Instancia um novo sensor, com o seu nome, tipo e index correspondentes

        void inicio();           // Para zerar o n�mero de sensores, chama somente quando inicia o programa

        void set_nome(string nomeSensor);   // Seta o nome do sensor
        string get_nome();                  // Retorna o nome do sensor

        void set_tipo(string tipoSensor);   // Seta o tipo do sensor
        string get_tipo();                  // Retorna o tipo do sensor


        void set_valor(float valorSensor);  // Seta um valor de medida para o sensor
        float get_valor();                  // Retorna um valor de medida do sensor


        void set_status(bool statusSensor); // Seta o status do sensor (ligado/desligado)
        bool get_status();                  // Retorna o status do sensor (ligado/desligado)


        void set_index(int numeroSensores);    // Seta o index do sensor (sua posi��o/n�mero/valor absoluto)
        int get_index();                       // Retorna o index do sensor (sua posi��o/n�mero/valor absoluto)



        // M�TODOS EXCLUSIVOS:
        bool habilitaSensor(Sensor &sensor);     // Para habilitar (ativar/ligar) um sensor j� criado
        bool desabilitaSensor(Sensor &sensor);   // Para desabilitar (desativar/desligar) um sensor j� criado

};



#endif // SENSORES_H_INCLUDED

// Fim do if
