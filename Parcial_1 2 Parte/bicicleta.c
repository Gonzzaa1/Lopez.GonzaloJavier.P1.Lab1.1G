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
           "10. Listado de Bicicletas de color\n"
           "11. Listado de Bicicletas por tipo\n"
           "\n   *** INFORMES ***\n\n"
           "12. Informe Material Bicicletas\n"
           "13. Listado Bicicletas separadas por tipo\n"
           "14. Informe por color y tipo seleccionado\n"
           "15. Informe de color mas elegido\n"
           "16. Trabajos por bicicletas\n"
           "17. Salir\n\n"
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
            printf("\n\n");
            listarTipo(tipos, tamT);

            printf("Ingrese id Tipo: ");
            scanf("%d", &idTipo);

            while(!validarTipo(tipos,tamT, idTipo) )
            {
                printf("Id invalido. Reingrese id tipo: ");
                scanf("%d", &idTipo);
            }

            nuevaBicicleta.idTipo = idTipo;

            printf("\n\n");
            listarColor(colores, tamC);

            printf("Ingrese id Color: ");
            scanf("%d", &idColor);

            while(!validarColor(colores,tamC, idColor))
            {
                printf("Id invalido. Reingrese id Color: ");
                scanf("%d", &idColor);
            }

            nuevaBicicleta.idColor = idColor;

            printf("\n\n");
            printf("Ingrese Material ('c' carbono - 'a' aluminio): ");
            fflush(stdin);
            scanf("%c",&nuevaBicicleta.material);

            while(nuevaBicicleta.material != 'c' && nuevaBicicleta.material != 'a')
            {
                printf("Ingrese un Material valido ('c' carbono - 'a' aluminio): ");
                fflush(stdin);
                scanf("%c",&nuevaBicicleta.material);
            }

            printf("Ingrese Rodado: ");
            fflush(stdin);
            scanf("%d", &nuevaBicicleta.rodado);

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
           "Material: %c\n"
           "Rodado: %d\n",
           bici.id,
           bici.marca,
           descripcionT,
           descripcionC,
           bici.material,
           bici.rodado);
}
void mostrarBicicletaFila(eBicicleta bici,eTipo tipos[],int tam,eColor colores[])
{
    char descripcionT[20];
    char descripcionC[20];

    cargarDescripcionTipo(tipos,tam,bici.idTipo,descripcionT);
    cargarDescripcionColor(colores,tam,bici.idColor,descripcionC);

    printf("    %3d  %15s   %10s    %10s           %c          %d  %15s\n",
           bici.id,
           bici.marca,
           descripcionT,
           descripcionC,
           bici.material,
           bici.rodado,
           bici.idCliente.nombre);
}
int listarBicicletas(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[])
{
    int retorno = 0;
    int flag = 1;

    if(bici!= NULL && tam > 0 && tipos != NULL && colores != NULL)
    {
        //system("cls");
        printf("                   *** Lista de Bicicletas ***\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("    Id            Marca          Tipo          Color        Material    Rodado         Duenio\n");
        printf("----------------------------------------------------------------------------------------------\n");


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
    int rodado;
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
                printf("\n");

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
                        listarColor(colores,tamC);
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
                        printf("Ingrese nuevo Material ('c' carbono - 'a' aluminio): ");
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
                    case 5:
                        printf("Ingrese nuevo rodado: ");
                        fflush(stdin);
                        scanf("%d",&rodado);
                        bici[indice].rodado = rodado;
                        printf("Rodado Modificado!\n");
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
           "5. Rodado\n"
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
int ordenarBicicletas(eBicicleta bici[], int tam)
{
    int retorno = 0;
    eBicicleta auxBici;

    if(bici != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam ;j++)
            {
                if((bici[i].idTipo == bici[j].idTipo && bici[i].rodado > bici[j].rodado) || (bici[i].idTipo != bici[j].idTipo && bici[i].idTipo > bici[j].idTipo) )
                {
                    auxBici = bici[i];
                    bici[i] = bici[j];
                    bici[j] = auxBici;
                }
            }
        }
        retorno = 1;
    }

    return retorno;
}
int hardcodeobici(eBicicleta bici[],int* pNextId,int tam, int cant)
{
    int retorno = 0;
    eBicicleta bicis[10]=
    {
        {0,"Vairo",1000,5000,'a',21,{600,"JUAN",'m'},0},
        {0,"Trek",1001,5001,'c',27,{601,"PEDRO",'m'},0},
        {0,"Speed Run",1002,5002,'a',29,{602,"MARIA",'f'},0},
        {0,"All Terrains",1003,5003,'c',21,{603,"GONZALO",'m'},0},
        {0,"Merida",1000,5000,'a',27,{604,"JUANA",'f'},0},
        {0,"Vairo",1001,5001,'c',29,{605,"PILAR",'f'},0},
        {0,"Trek",1002,5002,'a',21,{606,"LUCIA",'f'},0},
        {0,"Speed Run",1003,5003,'c',27,{607,"RAMIRO",'m'},0},
        {0,"All Terrains",1000,5000,'a',29,{608,"PABLO",'m'},0},
        {0,"Merida",1001,5001,'c',21,{609,"ANA",'f'},0}
    };
    if(bici!=NULL && pNextId != NULL && tam > 0 && cant <= tam)
    {
         for(int i=0; i < cant; i++)
        {
            bici[i] = bicis[i];
            bici[i].id = *pNextId;
            (*pNextId)++;
            retorno = 1;
        }
    }
    return retorno;
}
int validarBicicleta(eBicicleta bici[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarBicicleta(bici, tam, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}
int cargarMarcaBici(eBicicleta bici[], int tam, int id, char marca[])
{
    int retorno = 0;

    if(bici != NULL && tam > 0 && marca != NULL)
    {
        for(int i= 0; i < tam; i++)
        {

            if( bici[i].id == id && !bici[i].isEmpty)
            {
                strcpy(marca, bici[i].marca);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
int mostrarPorColor(eBicicleta bici[],int tam, eColor colores[], int tamC,eTipo tipos[])
{
    int retorno = 0;
    int idColor;
    char desColor[20];

    if(bici != NULL && tam > 0 && colores != NULL && tamC > 0 && tipos != NULL)
    {
        listarColor(colores, tamC);
        printf("\nIngrese el id del Color deseado: ");
        scanf("%d", &idColor);
        while(!validarColor(colores,tamC, idColor))
        {
            printf("\nNo existe el ID : %d. \nPor favor Reingrese un id valido: ", idColor);
            scanf("%d", &idColor);
        }

        cargarDescripcionColor(colores,tamC,idColor,desColor);

        system("cls");
        printf("                   *** Lista de Bicicletas por color %s ***\n", desColor);
        printf("----------------------------------------------------------------------------------------------\n");
        printf("    Id            Marca          Tipo          Color        Material    Rodado         Duenio\n");
        printf("----------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(bici[i].idColor == idColor && !bici[i].isEmpty)
            {
                mostrarBicicletaFila(bici[i],tipos,tam,colores);
            }
        }
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}
int mostrarPorTipo(eBicicleta bici[],int tam, eColor colores[], int tamT,eTipo tipos[])
{
    int retorno = 0;
    int idTipo;
    char desTipo[20];

    if(bici != NULL && tam > 0 && colores != NULL && tamT > 0 && tipos != NULL)
    {
        listarTipo(tipos, tamT);
        printf("\nIngrese el id del Tipo deseado: ");
        scanf("%d", &idTipo);

        while(!validarTipo(tipos,tamT, idTipo))
        {
            printf("\nNo existe el ID : %d. \nPor favor Reingrese un id valido: ", idTipo);
            scanf("%d", &idTipo);
        }

        cargarDescripcionTipo(tipos,tamT,idTipo,desTipo);

        system("cls");
        printf("                   *** Lista de Bicicletas por Tipo %s ***\n", desTipo);
        printf("----------------------------------------------------------------------------------------------\n");
        printf("    Id            Marca          Tipo          Color        Material    Rodado         Duenio\n");
        printf("----------------------------------------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(bici[i].idTipo == idTipo  && !bici[i].isEmpty)
            {
                mostrarBicicletaFila(bici[i],tipos,tam,colores);
            }
        }
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}
int masMaterial(eBicicleta bicis[],int tam)
{
    int retorno = 0;
    int contA = 0;
    int contC = 0;

    if(bicis != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!bicis[i].isEmpty)
            {
                if(bicis[i].material == 'a')
                {
                    contA++;
                }
                else
                {
                    contC++;
                }
            }
        }

        printf("                   *** INFORME MATERIAL ***\n");
        printf("------------------------------------------------------------------\n");

        if(contA == contC)
        {
            printf("\nHay la misma cantidad de bicicletas de material Aluminio y de Carbono\nLa cantidad es de: %d bicicletas de ambos material\n\n", contA);
        }
        else if(contA > contC)
        {
            printf("\nHay mas cantidad de bicicletas de material Aluminio que de Carbono\nLa cantidad es de: %d bicicletas de Aluminio\n\n", contA);
        }
        else
        {
            printf("\nHay mas cantidad de bicicletas de material Carbono que de Aluminio\nLa cantidad es de: %d bicicletas de Carbono\n\n", contC);
        }
    }
    return retorno;
}
int ListarPorTipo(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[],int tamT)
{
    int retorno = 0;

    if(bici != NULL && tam > 0 && colores != NULL && tipos != NULL && tamT > 0)
    {
        printf("                   *** INFORME SEPARADO POR TIPOS ***\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("    Id            Marca          Tipo          Color        Material    Rodado         Duenio\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("                             *** RUTERAS ***\n\n");
        separarPorTipo(bici,tam,tipos,colores,1000,tamT);
        printf("                             *** CARRERA ***\n\n");
        separarPorTipo(bici,tam,tipos,colores,1001,tamT);
        printf("                             *** MOUNTAIN ***\n\n");
        separarPorTipo(bici,tam,tipos,colores,1002,tamT);
        printf("                             *** BMX ***\n\n");
        separarPorTipo(bici,tam,tipos,colores,1003,tamT);

        retorno = 1;
    }
    return retorno;
}
int separarPorTipo(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[],int idTipo, int tamT)
{
    int retorno = 0;
    if(bici != NULL && tam > 0 && colores != NULL && tipos != NULL && tamT > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(!bici[i].isEmpty && bici[i].idTipo == idTipo)
            {
                mostrarBicicletaFila(bici[i],tipos,tam,colores);
            }
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;
}
int informeColorTipo(eBicicleta bici[], int tam,eTipo tipos[],eColor colores[], int tamT,int tamC)
{
    int retorno = 0;
    char destipo[10];
    char desColor[10];
    int idColor;
    int idTipo;
    int cont = 0;

    if(bici != NULL && tam > 0 && colores != NULL && tipos != NULL && tamT > 0 && tamC > 0)
    {
        listarColor(colores, tamC);
        printf("\nIngrese el id del Color deseado: ");
        scanf("%d", &idColor);

        while(!validarColor(colores,tamC, idColor))
        {
            printf("\nNo existe el ID : %d. \nPor favor Reingrese un id valido: ", idColor);
            scanf("%d", &idColor);
        }

        listarTipo(tipos, tamT);
        printf("\nIngrese el id del Tipo deseado: ");
        scanf("%d", &idTipo);

        while(!validarTipo(tipos,tamT, idTipo))
        {
            printf("\nNo existe el ID : %d. \nPor favor Reingrese un id valido: ", idTipo);
            scanf("%d", &idTipo);
        }

        cargarDescripcionColor(colores,tamC,idColor,desColor);
        cargarDescripcionTipo(tipos,tamT,idTipo,destipo);

        for(int i = 0; i < tam; i++)
        {
            if(bici[i].idColor == idColor && bici[i].idTipo == idTipo)
            {
                cont++;
            }
        }
        system("cls");
        printf("                   *** INFORME COLOR Y TIPO ***\n");
        printf("------------------------------------------------------------------\n\n");
        printf("La cantida de bicicletas de color %s y de tipo %s es de: %d Bicicletas\n\n",desColor,destipo,cont);

        retorno = 1;
    }
    return retorno;
}
int mostrarColorMasElegido(eBicicleta bici[], int tam, eColor colores[], int tamC)
{
    int retorno = 0;
    int totales[tamC];
    int flag = 1;
    int mayor;
    char desColor[10];

    if(bici != NULL && tam > 0 && colores != NULL && tamC > 0 )
    {
        for(int i = 0; i < tamC; i++)
        {
            totales[i] = 0;
        }
        for(int i = 0; i < tamC; i++)
        {
            totalColores(bici,tam,colores[i].id,&totales[i]);
        }
        for(int i=0; i < tamC; i++)
        {

            if(flag || totales[i] > mayor)
            {
                mayor = totales[i];
                flag = 0;
            }
        }

        printf("                   *** INFORME COLOR/ES MAS ELEGIDOS ***\n");
        printf("------------------------------------------------------------------\n\n");
        printf("Color/res mas elegidos: ");


        for(int i=0; i < tamC; i++)
        {
            cargarDescripcionColor(colores,tamC,colores[i].id,desColor);

            if(totales[i] == mayor)
            {
                printf("%s\n", desColor);
            }
        }

        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}
int totalColores(eBicicleta bici[], int tam, int idColor, int* pTotal)
{
    int retorno = 0;
    int contadorColor = 0;

    if(bici != NULL && tam > 0 && pTotal != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(!bici[i].isEmpty && bici[i].idColor == idColor)
            {
                contadorColor ++;
            }
        }
        *pTotal = contadorColor;
        retorno = 1;
    }
    return retorno;
}
