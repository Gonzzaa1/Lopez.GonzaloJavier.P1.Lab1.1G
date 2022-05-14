#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"


int menu()
{
    int opciones;

    printf("   **** ABM Bicicletas ****  \n"
           "--------------------------------\n\n"
           "1. Alta Bicicleta\n"
           "2. Modificar Bicicleta\n"
           "3. Baja Bicicleta\n"
           "4. Listar Bicicletas\n"
           "5. Listar Tipos\n"
           "6. Listar Colores\n"
           "7. Listar Servicios\n"
           "8. Alta Trabajos\n"
           "9. Listar Trabajos\n"
           "10. Salir\n\n"
           "Ingrese una opcion: ");
           scanf("%d", &opciones);

    return opciones;
}
int inicializarBicicleta(eBicicleta bici[], int tam)
{
    int retorno = 0;

    if(bici != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            bici[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}
int buscarLugar(eBicicleta bici[], int tam, int* pIndice)
{
    int retorno = 0;

    if(bici != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(bici[i].isEmpty)
            {
                *pIndice = i;
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}
int altaBicicleta(eBicicleta bici[], int tam, int* pNextId, eTipo tipos[], int tamT,eColor colores[],int tamC)
{
    int retorno = 0;
    int indice;
    int idTipo;
    int idColor;
    eBicicleta nuevaBicicleta;

    if(bici != NULL && tam > 0 && pNextId != NULL && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        printf("   *** Alta Bicicleta ***\n\n");

        buscarLugar(bici,tam,&indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevaBicicleta.id = *pNextId;

            printf("Ingrese Marca: ");
            fflush(stdin);
            gets(nuevaBicicleta.marca);

            while(strlen(nuevaBicicleta.marca) > 20)
            {
                printf("Dato incorrecto..Reingrese Marca: ");
                fflush(stdin);
                gets(nuevaBicicleta.marca);
            }

            listarTipo(tipos, tamT);

            printf("Ingrese id Tipo: ");
            scanf("%d", &idTipo);

            while(!validarTipo(tipos,tamT, idTipo) )
            {
                printf("Id invalido. Reingrese id tipo: ");
                scanf("%d", &idTipo);
            }

            nuevaBicicleta.idTipo = idTipo;

            listarColor(colores, tamC);

            printf("Ingrese id Color: ");
            scanf("%d", &idColor);

            while(!validarColor(colores,tamC, idColor))
            {
                printf("Id invalido. Reingrese id Color: ");
                scanf("%d", &idColor);
            }

            nuevaBicicleta.idColor = idColor;

            printf("Ingrese Material ('c' carbono - 'a' aluminio): ");
            fflush(stdin);
            scanf("%c",&nuevaBicicleta.material);

            while(nuevaBicicleta.material != 'c' && nuevaBicicleta.material != 'a')
            {
                printf("Ingrese un Material valido ('c' carbono - 'a' aluminio): ");
                fflush(stdin);
                scanf("%c",&nuevaBicicleta.material);
            }


            nuevaBicicleta.isEmpty = 0;

            bici[indice] = nuevaBicicleta;
            (*pNextId)++;
            retorno = 1;
        }
    }
    return retorno;
}
void mostrarBicicleta(eBicicleta bici,eTipo tipos[],int tam,eColor colores[])
{
    char descripcionT[20];
    char descripcionC[20];

    cargarDescripcionTipo(tipos,tam,bici.idTipo,descripcionT);
    cargarDescripcionColor(colores,tam,bici.idColor,descripcionC);

    printf("ID: %d\n"
           "Marca: %s\n"
           "Tipo: %s\n"
           "Color: %s\n"
           "Material: %c\n",
           bici.id,
           bici.marca,
           descripcionT,
           descripcionC,
           bici.material);
}
void mostrarBicicletaFila(eBicicleta bici,eTipo tipos[],int tam,eColor colores[])
{
    char descripcionT[20];
    char descripcionC[20];

    cargarDescripcionTipo(tipos,tam,bici.idTipo,descripcionT);
    cargarDescripcionColor(colores,tam,bici.idColor,descripcionC);

    printf("%4d    %10s    %10s    %10s        %c\n",
           bici.id,
           bici.marca,
           descripcionT,
           descripcionC,
           bici.material);
}
int listarBicicletas(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[])
{
    int retorno = 0;
    int flag = 1;

    if(bici!= NULL && tam > 0 && tipos != NULL && colores != NULL)
    {
        system("cls");
        printf("                   *** Lista de Bicicletas ***\n");
        printf("--------------------------------------------------------------------\n");
        printf("  Id        Marca         Tipo         Color        Material\n");
        printf("--------------------------------------------------------------------\n");


        for(int i=0; i < tam; i++)
        {
            if(!bici[i].isEmpty)
            {
                mostrarBicicletaFila(bici[i],tipos,tam,colores);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("\n\n\n             *********  No hay Bicicletas en el sistema  *********  \n\n");
        }
        retorno = 1;
    }
    return retorno;
}
int buscarBicicleta(eBicicleta bici[],int tam, int id, int* pIndex)
{
    int retorno = 0;

    if(bici != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(!bici[i].isEmpty && bici[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}
int modificarBicicleta(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[],int tamT,int tamC)
{
    int retorno = 0;

    int id;
    int indice;
    int idTipo;
    int idColor;
    char material;
    char auxCad[20];

    if(bici != NULL && tam > 0 && tipos != NULL && colores != NULL && tamT > 0 && tamC > 0)
    {
        listarBicicletas(bici,tam,tipos,colores);
        printf("\nIngrese ID: ");
        scanf("%d", &id);

        if(buscarBicicleta(bici,tam,id,&indice))
        {
            if(indice == -1)
            {
                printf("\nNo existe una bicicleta con ID: %d en el sistema\n", id);
                system("pause");
            }
            else
            {
                system("cls");
                mostrarBicicleta(bici[indice],tipos,tam,colores);
                printf("%d",indice);

                switch(menuModBici())
                {
                    case 1:
                        printf("Ingrese nueva Marca: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(bici[indice].marca, auxCad);
                        printf("Marca Modificada!\n");
                        break;
                    case 2:
                        listarTipo(tipos,tamT);

                        printf("Ingrese Nuevo id Tipo: ");
                        scanf("%d", &idTipo);

                        while(!validarTipo(tipos,tamT, idTipo))
                        {
                            printf("Id invalido. Reingrese id tipo: ");
                            scanf("%d", &idTipo);
                        }
                        bici[indice].idTipo = idTipo;
                        printf("Tipo Modificado!\n");
                        break;
                    case 3:
                        listarColor(colores,tam);
                        printf("Ingrese Nuevo id Color: ");
                        scanf("%d", &idColor);

                        while(!validarColor(colores,tamC, idColor))
                        {
                            printf("Id invalido. Reingrese id Color: ");
                            scanf("%d", &idColor);
                        }
                        bici[indice].idColor = idColor;
                        printf("Color Modificado!\n");
                        break;
                    case 4:
                        printf("Ingrese nuev Material ('c' carbono - 'a' aluminio): ");
                        fflush(stdin);
                        scanf("%c",&material);

                        while(material != 'c' && material != 'a')
                        {
                            printf("Ingrese un Material valido ('c' carbono - 'a' aluminio): ");
                            fflush(stdin);
                            scanf("%c",&material);
                        }

                        bici[indice].material = material;
                        printf("Material Modificado!\n");
                        break;
                }
                system("pause");
            }
        }
    }
    return retorno;
}
int menuModBici()
{
    int opciones;

     printf("   **** Campo de Modificaciones ****  \n"
           "----------------------------------------\n\n"
           "1. Marca\n"
           "2. Tipo\n"
           "3. Color\n"
           "4. Material\n"
           "Ingrese una opcion: ");
           scanf("%d", &opciones);

    return opciones;
}
int bajaBicicleta(eBicicleta bici[],int tam,eTipo tipos[],eColor colores[])
{
    int retorno = 0;
    int indice;
    int id;
    char confirmar;

    if(bici != NULL && tam > 0)
    {
        listarBicicletas(bici,tam,tipos,colores);
        printf("\nIngrese id: ");
        scanf("%d", &id);

        if(buscarBicicleta(bici,tam,id,&indice))
        {
        if(indice == -1)
        {
            printf("\nNo existe una bicicleta con ID: %d en el sistema\n", id);
            system("pause");
        }
        else
        {
            mostrarBicicleta(bici[indice],tipos,tam,colores);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirmar);

            if(confirmar == 's' || confirmar == 'S')
            {
                bici[indice].isEmpty = 1;
                printf("Baja exitosa!\n");
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
            system("pause");
        }

        retorno = 1;
        }
    }
    return retorno;
}
