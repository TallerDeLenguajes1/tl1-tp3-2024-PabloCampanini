#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 12

int main()
{
    srand(time(NULL));
    int matriz[N][M];
    float promedio[N];
    int max = 0, min = 50001, anioMax, anioMin, mesMax, mesMin;

    for (int i = 0; i < N; i++)
    {
        printf("Anio %d: ", (i + 1));

        int suma = 0;

        for (int j = 0; j < M; j++)
        {

            matriz[i][j] = 10000 + rand() % (50000 - 10000 + 1);

            printf("$%d\t", matriz[i][j]);

            suma = suma + matriz[i][j];

            if (matriz[i][j] > max)
            {
                max = matriz[i][j];
                anioMax = i + 1;
                mesMax = j + 1;
            }

            if (matriz[i][j] < min)
            {
                min = matriz[i][j];
                anioMin = i + 1;
                mesMin = j + 1;
            }
            
            
        }

        promedio[i] = (float)suma / M;

        printf("\n\n");
    }

    for (int i = 0; i < N; i++)
    {
        printf("Ganancias anio %d:\t $%.2f\n", (i + 1), promedio[i]);
    }

    printf("\nEl maximo de ganancias se tuvo en el mes %d del anio %d con un valor = $%d\n", mesMax, anioMax, max);
    printf("\nEl minimo de ganancias se tuvo en el mes %d del anio %d con un valor = $%d\n", mesMin, anioMin, min);

    return 0;
}
