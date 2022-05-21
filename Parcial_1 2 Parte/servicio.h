#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED


int listarServicio(eServicio servicio[], int tam);
int buscarServicio(eServicio servicio[], int tam, int id, int* pIndex);
int cargarDescripcionServicio(eServicio servicio[], int tam, int id, char desc[]);
int validarServicio(eServicio servicio[], int tam, int id);
