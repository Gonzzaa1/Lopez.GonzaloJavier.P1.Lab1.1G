#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;

#endif // COLOR_H_INCLUDED

int buscarColor(eColor color[], int tam, int id, int* pIndex);
int listarColor(eColor color[], int tam);
int cargarDescripcionColor(eColor color[], int tam, int id, char desc[]);
int validarColor(eColor color[], int tam, int id);
