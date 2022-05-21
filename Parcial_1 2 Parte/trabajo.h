#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED


int inicializarTrabajo(eTrabajo trabajo[], int tam);
int buscarLugarTrabajo(eTrabajo trabajo[], int tam,int* pIndex);
int altaTrabajo(eTrabajo trabajos[], int tam, int* pNextId, eBicicleta bicis[],eTipo tipos[], eColor colores[], eServicio servicios[],int tamS);
int mostrarTrabajoFila(eTrabajo trabajos,eBicicleta bicis[],eServicio servicios[],int tam, int tamS);
int listarTrabajo(eTrabajo trabajos[],eBicicleta bicis[],eServicio servicios[],int tam, int tamS,int tamJ);
int hardCodeTrabajo(eTrabajo trabajo[],int* pNextId,int tam, int cant);
int buscarTrabajo(eTrabajo trabajo[],eBicicleta bici[], int tam, eTipo tipos[], eColor colores[], eServicio servicios[], int tamS);
