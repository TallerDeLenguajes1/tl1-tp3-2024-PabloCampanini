#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **matriz; // Lugar donde cargare los nombres
    char *Buff;    // Variable aux
    char *nombre;
    char *apellido;

    // Reservas de memoria de la var. aux. y de los "5 punteros"
    matriz = (char **)malloc(5 * sizeof(char *));
    Buff = (char *)malloc(100 * sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        printf("\nUsuario %d:\n", (i + 1));
        printf("\t* Ingrese sus nombres: ");
        gets(Buff);

        nombre = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(nombre, Buff);

        printf("\n\t* Ingrese sus apellidos: ", (i + 1));
        gets(Buff);

        apellido = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(apellido, Buff);

        matriz[i] = (char *)malloc((strlen(nombre) + 1 + strlen(apellido) + 1) * sizeof(char));
        strcpy(matriz[i], nombre);
        strcat(matriz[i], " "); //Agrego espacio en blanco entre nombre y apellido
        strcat(matriz[i], apellido);

        free(nombre);
        free(apellido);
    }

    free(Buff);

    printf("\nNombres y Apellidos de los usuarios:");

    for (int j = 0; j < 5; j++)
    {
        printf("\n\tUsuario %d:\n\t", (j + 1));
        puts(matriz[j]);
        free(matriz[j]);
    }

    free(matriz);
}