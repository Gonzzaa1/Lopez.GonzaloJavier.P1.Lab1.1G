#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int buscarTipo(eTipo tipo[], int tam, int id, int* pIndex)
{
    int retorno = 0;

    if(tipo != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(tipo[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}
int listarTipo(eTipo tipo[], int tam)
{
    int retorno = 0;

    if(tipo != NULL && tam > 0 ){

        printf("   *** Listado de Tipos ***\n");
        printf("  id      descripcion\n");
        printf("-----------------------------\n");

        for(int i= 0; i < tam; i++)
        {

           printf("    %4d      %10s\n", tipo[i].id, tipo[i].descripcion);

        }
        retorno = 1;
    }
    return retorno;
}
int cargarDescripcionTipo(eTipo tipo[], int tam, int id, char desc[])
{

    int retorno = 0;
    if(tipo != NULL && tam > 0 && desc != NULL)
    {
        for(int i= 0; i < tam; i++)
        {

            if( tipo[i].id == id)
            {
                strcpy(desc, tipo[i].descripcion);
                retorno = 1;
                break;
            }

        }
    }
    return retorno;
}

int validarTipo(eTipo tipo[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarTipo(tipo, tam, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}
