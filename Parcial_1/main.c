#include <stdio.h>
#include <stdlib.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

#define TAM 10
#define TAMT 4
#define TAMC 5
#define TAMS 4

int main()
{
    char salir = 'n';
    int id = 100;
    eBicicleta bicicletas[TAM];
    eTipo tipos[TAMT] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor colores[TAMC] =
    {
        {5000, "Gris"},
        {5001, "Blanca"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"}
    };
    eServicio servicios[TAMS]=
    {
        {20000, "Limpieza", 30},
        {20001, "Parche",400},
        {20002, "Centrado",500},
        {20003, "Cadena", 450}
    };

    inicializarBicicleta(bicicletas,TAM);

    do
    {
        system("cls");

        switch(menu())
        {
            case 1:
                altaBicicleta(bicicletas,TAM,&id,tipos,TAMT,colores,TAMC);
                break;
            case 2:
                modificarBicicleta(bicicletas,TAM,tipos,colores,TAMT,TAMC);
                break;
            case 3:
                bajaBicicleta(bicicletas,TAM,tipos,colores);
                break;
            case 4:
                listarBicicletas(bicicletas,TAM,tipos,colores);
                system("pause");
                break;
            case 5:
                system("cls");
                listarTipo(tipos,TAMT);
                system("pause");
                break;
            case 6:
                system("cls");
                listarColor(colores,TAMC);
                system("pause");
                break;
            case 7:
                system("cls");
                listarServicio(servicios,TAMS);
                system("pause");
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                salir = 's';
                break;
        }
    }
    while(salir != 's');

    return 0;
}
