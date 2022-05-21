

#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eTipo;

#endif // TIPO_H_INCLUDED

int buscarTipo(eTipo tipo[], int tam, int id, int* pIndex);
int listarTipo(eTipo tipo[], int tam);
int cargarDescripcionTipo(eTipo tipo[], int tam, int id, char desc[]);
int validarTipo(eTipo tipo[], int tam, int id);
