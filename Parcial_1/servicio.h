#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED


int listarServicio(eServicio Servicio[], int tam);
int buscarServicio(eServicio Servicio[], int tam, int id, int* pIndex);
int cargarDescripcionServicio(eServicio Servicio[], int tam, int id, char desc[]);
