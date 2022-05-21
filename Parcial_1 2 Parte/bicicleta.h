#include "tipo.h"
#include "color.h"
#include "cliente.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material;
    int rodado;
    eCliente idCliente;
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
int ordenarBicicletas(eBicicleta bici[], int tam);
int hardcodeobici(eBicicleta bici[],int* pNextId,int tam, int cant);
int validarBicicleta(eBicicleta bici[], int tam, int id);
int cargarMarcaBici(eBicicleta bici[], int tam, int id, char marca[]);
int mostrarPorColor(eBicicleta bici[],int tam, eColor colores[], int tamC,eTipo tipos[]);
int mostrarPorTipo(eBicicleta bici[],int tam, eColor colores[], int tamT,eTipo tipos[]);
int masMaterial(eBicicleta bicis[],int tam);
int ListarPorTipo(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[],int tamT);
int separarPorTipo(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[],int idTipo, int tamT);
int informeColorTipo(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[], int tamT,int tamC);
int mostrarColorMasElegido(eBicicleta bici[], int tam, eColor colores[], int tamC);
int totalColores(eBicicleta bici[], int tam, int idColor, int* pTotal);
