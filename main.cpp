#include <iostream>
#include "Sensores.h"
#include "Interface.h"

using namespace std;



int main(){

    setlocale(LC_ALL, "Portuguese");        // Para usar a estrutura ortogr�fica em portugu�s

    // INSTANCIANDO NOVOS OBJETOS:
    // No C++, � preciso identificar o novo Objeto da Classe como *ponteiro*. Portanto, como exemplo:
    Interface *interface = new Interface();         // Instancia uma interface nova


    return 0;
}
