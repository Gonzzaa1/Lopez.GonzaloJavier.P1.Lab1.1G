#include <stdio.h>
#include <stdlib.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 10
#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMJ 7

int main()
{
    char salir = 'n';
    int id = 100;
    int idTrabajos = 1000;
    eBicicleta bicicletas[TAM];
    eTrabajo trabajos[TAM];
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
        {5001, "Blanco"},
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
    inicializarTrabajo(trabajos,TAMJ);
    hardcodeobici(bicicletas,&id,TAM,10);
    hardCodeTrabajo(trabajos,&idTrabajos,TAMJ,7);

    do
    {
        system("cls");

        switch(menu())
        {
            case 1:
                altaBicicleta(bicicletas,TAM,&id,tipos,TAMT,colores,TAMC);
                system("cls");
                printf("Alta exitosa!");
                system("pause");
                break;
            case 2:
                system("cls");
                modificarBicicleta(bicicletas,TAM,tipos,colores,TAMT,TAMC);
                break;
            case 3:
                system("cls");
                bajaBicicleta(bicicletas,TAM,tipos,colores);
                break;
            case 4:
                system("cls");
                ordenarBicicletas(bicicletas, TAM);
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
                altaTrabajo(trabajos,TAMJ,&idTrabajos,bicicletas,tipos,colores,servicios,TAMS);
                system("cls");
                printf("Alta exitosa!\n\n");
                system("pause");
                break;
            case 9:
                system("cls");
                listarTrabajo(trabajos,bicicletas,servicios,TAM,TAMS,TAMJ);
                system("pause");
                break;
            case 10:
                system("cls");
                mostrarPorColor(bicicletas,TAM,colores,TAMC,tipos);
                system("pause");
                break;
            case 11:
                system("cls");
                mostrarPorTipo(bicicletas,TAM,colores,TAMT,tipos);
                system("pause");
                break;
            case 12:
                system("cls");
                masMaterial(bicicletas,TAM);
                system("pause");
                break;
            case 13:
                system("cls");
                ListarPorTipo(bicicletas,TAM,tipos,colores,TAMT);
                system("pause");
                break;
            case 14:
                system("cls");
                informeColorTipo(bicicletas,TAM,tipos,colores,TAMT,TAMC);
                system("pause");
                break;
            case 15:
                system("cls");
                mostrarColorMasElegido(bicicletas,TAM,colores,TAMC);
                system("pause");
                break;
            case 16:
                system("cls");
                buscarTrabajo(trabajos,bicicletas,TAM,tipos,colores,servicios,TAMS);
                system("pause");
                break;
            case 17:
                salir = 's';
                break;
        }
    }
    while(salir != 's');

    return 0;
}
