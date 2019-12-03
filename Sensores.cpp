#include <iostream>
#include "Sensores.h"
#include "Interface.h"


            // CONSTRUTOR (Construct)

// Instancia um novo sensor, com o seu nome e tipo correspondente
Sensor :: Sensor(string nomeSensor, string tipoSensor, int numeroSensores){

    set_nome(nomeSensor);                   // Setando o nome do sensor
    set_tipo(tipoSensor);                   // Setando o tipo do sensor
    set_index(numeroSensores);              // Setando o index (número) do sensor

    return;
}



            // MÉTODOS ACESSORES (Getters)
            // E MODIFICADORES (Setters)

// Seta o nome(tipo) do sensor
void Sensor :: set_nome(string nomeSensor){

    this->nome = nomeSensor;

    return;
}

// Retorna o nome(tipo) do sensor
string Sensor :: get_nome(){

    return nome;
}

// Seta o tipo do sensor
void Sensor :: set_tipo(string tipoSensor){

    this->tipo = tipoSensor;

    return;
}

// Retorna o tipo do sensor
string Sensor :: get_tipo(){

    return tipo;
}

// Seta um valor de medida para o sensor
void Sensor :: set_valor(float valorSensor){

    this->valor = valorSensor;

    return;
}

// Retorna um valor de medida do sensor
float Sensor :: get_valor(){

    return valor;
}

// Seta o status do sensor (ligado/desligado)
void Sensor :: set_status(bool statusSensor){

    this->status = statusSensor;

    return;
}

// Retorna o status do sensor (ligado/desligado)
bool Sensor :: get_status(){

    return status;
}

// Seta o index do sensor (sua posição/número/valor absoluto)
void Sensor :: set_index(int numeroSensores){

    this->index = numeroSensores+1;

    return;
}

// Retorna o index do sensor (sua posição/número/valor absoluto)
int Sensor :: get_index(){

    return index;

}




            // MÉTODOS EXCLUSIVOS:



// Para habilitar (ativar/ligar) um sensor já criado
bool Sensor :: habilitaSensor(Sensor &sensor){

    /*
    if(sensor == NULL)             // Se estiver tentando habilitar um sensor que não existe, retorna falso
        return false;
    */

    set_status(true);

    return true;
}

// Para desabilitar (desativar/desligar) um sensor já criado
bool Sensor :: desabilitaSensor(Sensor &sensor){

    /*
    if(sensor == NULL)             // Se estiver tentando desabilitar um sensor que não existe, retorna falso
        return false;
    */

    set_status(false);

    return true;
}
