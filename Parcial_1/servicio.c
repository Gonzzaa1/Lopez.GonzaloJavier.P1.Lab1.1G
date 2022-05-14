#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int listarServicio(eServicio Servicio[], int tam)
{
    int retorno = 0;

    if(Servicio != NULL && tam > 0 ){

        printf("   *** Listado de Tipos ***\n");
        printf("  id      descripcion    precio\n");
        printf("------------------------------------\n");

        for(int i= 0; i < tam; i++)
        {

           printf("    %4d      %10s   %.2f\n", Servicio[i].id, Servicio[i].descripcion,Servicio[i].precio);

        }
        retorno = 1;
    }
    return retorno;
}
int buscarServicio(eServicio Servicio[], int tam, int id, int* pIndex)
{
    int retorno = 0;

    if(Servicio != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(Servicio[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}
int cargarDescripcionServicio(eServicio Servicio[], int tam, int id, char desc[])
{
    int retorno = 0;
    if(Servicio != NULL && tam > 0 && desc != NULL)
    {
        for(int i= 0; i < tam; i++)
        {

            if( Servicio[i].id == id)
            {
                strcpy(desc, Servicio[i].descripcion);
                retorno = 1;
                break;
            }

        }
    }
    return retorno;
}
