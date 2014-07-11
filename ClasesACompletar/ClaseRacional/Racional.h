#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>
using namespace std;

class Racional
{
    public:
        void normalizarRacional(int& ,int& );
        void mostrarRacional(void);
        Racional(int =0,int =1);
        Racional& operator=(const Racional& );
        virtual ~Racional();

        //friend Racional operator+(const Racional&)const;
    protected:
    private:
    int numerador;
    int denominador;
};

#endif // RACIONAL_H
