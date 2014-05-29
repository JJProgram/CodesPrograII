#include "FcUsadas.h"
int main()
{
    if(!cargarySumarPilas())
        {
            printf("El programa fracaso\nPresione una tecla para salir...");
            getch();
            exit(1);
        }
    printf("El programa finalizo exitosamente\nPresione una tecla para salir...");
    getch();
    return 1;
}


