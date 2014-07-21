#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <string.h>
using namespace std;

class Carta
{
    public:
        void mostrarCarta(void);
        Carta(char* =NULL,char* ="\0",float =0.0);
        virtual ~Carta();
        Carta& operator=(const Carta& obj);
        Carta operator++(void);
        friend istream& operator>>(istream& ,Carta& );
    protected:
    private:
        char* destinatario;
        char paisDeDestino [20];
        float precio;
};

#endif // CARTA_H
