#ifndef AUTO_H
#define AUTO_H
#include <iostream>

using namespace std;
class Auto
{
    public:
        Auto(); //constructor
        Auto(char* ,char* ,float ,int ); //constructor parametrizado
        virtual ~Auto(); //destructor
        void mostrarAuto();
    protected:
    private:
        char* marca;
        char modelo[15];
        float precio;
        int anio;
};

#endif // AUTO_H
