#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int buscarColor(eColor color[], int tam, int id, int* pIndex)
{
    int retorno = 0;

    if(color != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;

        for(int i=0; i < tam; i++)
        {
            if(color[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}
int listarColor(eColor color[], int tam)
{
    int retorno = 0;

    if(color != NULL && tam > 0 ){

        printf("   *** Listado de colores ***\n");
        printf("  id      descripcion\n");
        printf("-----------------------------\n");

        for(int i= 0; i < tam; i++)
        {

           printf("    %4d      %10s\n", color[i].id, color[i].nombreColor);

        }
        retorno = 1;
    }
    return retorno;
}
int cargarDescripcionColor(eColor color[], int tam, int id, char desc[])
{
    int retorno = 0;
    if(color != NULL && tam > 0 && desc != NULL)
    {
        for(int i= 0; i < tam; i++)
        {

            if( color[i].id == id)
            {
                strcpy(desc, color[i].nombreColor);
                retorno = 1;
                break;
            }

        }
    }
    return retorno;
}
int validarColor(eColor color[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarColor(color, tam, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}
