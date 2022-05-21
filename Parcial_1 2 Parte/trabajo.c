#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"


int inicializarTrabajo(eTrabajo trabajo[], int tam)
{
    int retorno = 0;

    if(trabajo != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            trabajo[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}
int buscarLugarTrabajo(eTrabajo trabajo[], int tam, int* pIndex)
{
    int retorno = 0;

    if(trabajo != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(trabajo[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}
int altaTrabajo(eTrabajo trabajos[], int tam, int* pNextId, eBicicleta bicis[],eTipo tipos[], eColor colores[], eServicio servicios[],int tamS)
{
    int retorno = 0;
    int index;
    int idBici;
    int idServ;
    eFecha fecha;

    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && tam > 0 && pNextId != NULL && bicis != NULL && tipos != NULL && colores != NULL && servicios != NULL && tamS > 0)
    {
        system("cls");
        printf("   *** Alta Trabajo ***\n");
        printf("--------------------------\n\n");

        buscarLugarTrabajo(trabajos,tam,&index);

        if(index == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoTrabajo.id = *pNextId;

            listarBicicletas(bicis,tam,tipos,colores);
            printf("\nIngrese ID de bicicleta: ");
            scanf("%d",&idBici);

            while(!validarBicicleta(bicis,tam,idBici))
            {
                printf("\nId ingresado incorrecto...Reingrese id: ");
                scanf("%d",&idBici);
            }
            nuevoTrabajo.idBicicleta = idBici;

            printf("\n\n");
            listarServicio(servicios,tamS);
            printf("\nIngrese ID del servicio: ");
            scanf("%d",&idServ);

            while(!validarServicio(servicios,tamS,idServ))
            {
                printf("\nId ingresado incorrecto...Reingrese id: ");
                scanf("%d",&idServ);
            }
            nuevoTrabajo.idServicio = idServ;

            printf("\nIngrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);

            nuevoTrabajo.fecha = fecha;

            nuevoTrabajo.isEmpty = 0;

            trabajos[index] = nuevoTrabajo;
            (*pNextId)++;

            retorno = 1;
        }
    }
    return retorno;
}
int mostrarTrabajoFila(eTrabajo trabajos,eBicicleta bicis[],eServicio servicios[],int tam, int tamS)
{
    int retorno = 0;
    char marcaBici[20];
    char servicioDes[20];

    if(bicis != NULL && servicios != NULL && tam > 0 && tamS > 0)
    {
        cargarDescripcionServicio(servicios,tamS,trabajos.idServicio,servicioDes);
        cargarMarcaBici(bicis,tam,trabajos.idBicicleta,marcaBici);

        printf("   %d  %15s         %10s      %02d/%02d/%d\n",
               trabajos.id,
               marcaBici,
               servicioDes,
               trabajos.fecha.dia,
               trabajos.fecha.mes,
               trabajos.fecha.anio);



        retorno = 1;
    }

    return retorno;
}
int listarTrabajo(eTrabajo trabajos[],eBicicleta bicis[],eServicio servicios[],int tam, int tamS,int tamJ)
{
    int retorno = 0;
    int flag = 1;

    if(trabajos != NULL && bicis != NULL && servicios != NULL && tam > 0 && tamS > 0 && tamJ > 0)
    {
        system("cls");
        printf("       *** Listado de trabajos ***\n");
        printf("   id           bicicleta         servicio         fecha\n");
        printf("-----------------------------------------------------------\n");

        for(int i = 0; i < tamJ; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajoFila(trabajos[i],bicis,servicios,tam,tamS);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("              No hay trabajos en el sistema\n");
        }
        retorno = 1;
    }
    return retorno;
}
int hardCodeTrabajo(eTrabajo trabajo[],int* pNextId,int tam, int cant)
{
    int retorno = 0;
    eTrabajo trabajos[7]=
    {
        {0,100,20000,{20,5,2022},0},
        {0,100,20001,{20,5,2022},0},
        {0,100,20002,{20,5,2022},0},
        {0,103,20003,{20,5,2022},0},
        {0,104,20000,{20,5,2022},0},
        {0,104,20001,{20,5,2022},0},
        {0,106,20002,{20,5,2022},0}

    };

    if(trabajo!=NULL && pNextId != NULL && tam > 0 && cant <= tam)
    {
         for(int i=0; i < cant; i++)
        {
            trabajo[i] = trabajos[i];
            trabajo[i].id = *pNextId;
            (*pNextId)++;
            retorno = 1;
        }
    }
    return retorno;
}
int buscarTrabajo(eTrabajo trabajo[],eBicicleta bici[], int tam, eTipo tipos[], eColor colores[], eServicio servicios[], int tamS)
{
    int retorno = 0;
    int idBici;

    if(trabajo != NULL && bici != NULL && tam > 0 && colores != NULL && tipos != NULL && servicios != NULL && tamS > 0)
    {
        listarBicicletas(bici,tam,tipos,colores);
        printf("\nIngrese ID de bicicleta: ");
        scanf("%d",&idBici);

        while(!validarBicicleta(bici,tam,idBici))
        {
            printf("\nId ingresado incorrecto...Reingrese id: ");
            scanf("%d",&idBici);
        }

        system("cls");
        printf("             *** Listado de trabajos  ***\n");
        printf("   id           bicicleta         servicio         fecha\n");
        printf("-----------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(trabajo[i].idBicicleta == idBici)
            {
                mostrarTrabajoFila(trabajo[i],bici,servicios,tam,tamS);
            }
        }
        retorno = 1;
    }

    return retorno;
}
