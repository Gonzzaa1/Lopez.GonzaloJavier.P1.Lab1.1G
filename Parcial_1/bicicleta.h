#include "tipo.h"
#include "color.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material;
    int isEmpty;

}eBicicleta;

#endif // BICICLETA_H_INCLUDED

int menu();
int inicializarBicicleta(eBicicleta bici[], int tam);
int buscarLugar(eBicicleta bici[], int tam, int* pIndice);
int altaBicicleta(eBicicleta bici[], int tam, int* pNextId, eTipo tipos[], int tamT,eColor colores[],int tamC);
void mostrarBicicleta(eBicicleta bici,eTipo tipos[],int tam,eColor colores[]);
void mostrarBicicletaFila(eBicicleta bici,eTipo tipos[],int tam,eColor colores[]);
int listarBicicletas(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[]);
int modificarBicicleta(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[],int tamT,int tamC);
int buscarBicicleta(eBicicleta bici[],int tam, int id, int* pIndex);
int menuModBici();
int bajaBicicleta(eBicicleta bici[],int tam,eTipo tipos[],eColor colores[]);

