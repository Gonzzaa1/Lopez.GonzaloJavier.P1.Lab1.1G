#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int listarServicio(eServicio servicio[], int tam)
{
    int retorno = 0;

    if(servicio != NULL && tam > 0 ){

        printf("   *** Listado de Tipos ***\n");
        printf("  id      descripcion    precio\n");
        printf("------------------------------------\n");

        for(int i= 0; i < tam; i++)
        {

           printf("    %4d      %10s   %.2f\n", servicio[i].id, servicio[i].descripcion,servicio[i].precio);

        }
        retorno = 1;
    }
    return retorno;
}
int buscarServicio(eServicio servicio[], int tam, int id, int* pIndex)
{
    int retorno = 0;

    if(servicio != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(servicio[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}
int cargarDescripcionServicio(eServicio servicio[], int tam, int id, char desc[])
{
    int retorno = 0;
    if(servicio != NULL && tam > 0 && desc != NULL)
    {
        for(int i= 0; i < tam; i++)
        {

            if(servicio[i].id == id)
            {
                strcpy(desc, servicio[i].descripcion);
                retorno = 1;
                break;
            }

        }
    }
    return retorno;
}
int validarServicio(eServicio servicio[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarServicio(servicio, tam, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}
