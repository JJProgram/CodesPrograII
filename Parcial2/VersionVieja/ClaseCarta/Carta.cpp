#include "Carta.h"
void Carta::mostrarCarta(void)
{
    cout << "----------" << endl;
    cout << "Destinatario: " << (this->destinatario==NULL?"NULL":this->destinatario) << endl;
    cout << "Pais de Destino: " << this->paisDeDestino << endl;
    cout << "Precio: " << this->precio << endl;
    cout << "----------" << endl;
}
char* duplicarCadena(const char* cadena)
{
    char* auxC;
    if(cadena && *cadena)
    {
        try
        {
            auxC = new char [strlen(cadena)+1];
            strcpy(auxC,cadena);
            return auxC;
        }
        catch(std :: bad_alloc e)
        {
            cerr << e.what();
        }
    }
    return NULL;
}
Carta::Carta(char* dest,char* pdD,float precio)
{
    this->destinatario=duplicarCadena(dest);

    if(this->destinatario==NULL && dest && *dest)
        cout << "ERROR: No se pudo pedir memoria para guardar destinatario" << endl;
    strcpy(this->paisDeDestino,pdD);
    this->precio=precio;
}

Carta::~Carta()
{
    delete[]destinatario;
}

Carta& Carta::operator=(const Carta& obj)
{
    delete[]this->destinatario;
    this->destinatario=duplicarCadena(obj.destinatario);
    if(obj.destinatario && *(obj.destinatario) && this->destinatario == NULL)
        cout << "ERROR: No se pudo pedir memoria para guardar destinatario" << endl;
    strcpy(this->paisDeDestino,obj.paisDeDestino);
    this->precio=obj.precio;
    return (*this);
}
Carta Carta::operator++(void)
{
    (this->precio)++;
    return (*this);
}

istream& operator>>(istream& entrada,Carta& obj)
{
    char aux[100];
    cout << "Ingrese el Destinatario: ";
    entrada.getline(aux,sizeof(aux),'\n');
    delete[]obj.destinatario;
    obj.destinatario=duplicarCadena(aux);
    if(aux && *aux && obj.destinatario == NULL)
        cout << "ERROR: No se pudo pedir memoria para guardar destinatario" << endl;
    cout << "Ingrese el Pais de Destino: ";
    entrada.getline(aux,sizeof(aux),'\n');
    strcpy(obj.paisDeDestino,aux);
    cout << "Ingrese el Precio: ";
    cin >> obj.precio;
    return entrada;
}
