#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} typedef Cliente;

float montoTotal(Producto producto);

int main()
{
    srand(time(NULL));

    // Productos a vender
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillo", "Caramelo", "Bebidas"};

    // Declaracion de variables
    int cantidadClientes;
    char *Buff = (char *)malloc(100 * sizeof(char));                   // Variable aux para el nombre
    float *montos = (float *)malloc(cantidadClientes * sizeof(float)); // Almacenamiento montos
    float *total = (float *)malloc(cantidadClientes * sizeof(float)); //Almaceno los montos totales a pagar de cada cliente

    // Cantidad de clientes ingresados por el usuario
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    // Almacenamiento de los datos de los clientes
    Cliente *lista_cliente = (Cliente *)malloc(cantidadClientes * sizeof(Cliente));

    // Cargado de las estructuras
    for (int i = 0; i < cantidadClientes; i++)
    {
        //Inicio total a pagar por cliente en 0
        total[i] = 0;

        lista_cliente[i].ClienteID = i + 1; // ID del cliente, empieza en 1

        // Cargado del nombre del cliente por el usuario
        printf("Ingrese el nombre del Cliente: %d", lista_cliente[i].ClienteID);
        gets(Buff);

        lista_cliente[i].NombreCliente = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(lista_cliente[i].NombreCliente, Buff);

        // Cantidad de productos a pedir
        lista_cliente[i].CantidadProductosAPedir = 1 + rand() % 5;

        // Reserva de memoria para la cantidad de productos
        lista_cliente[i].Productos = (Producto *)malloc(lista_cliente[i].CantidadProductosAPedir * sizeof(Producto));

        // Cargado de la estructura producto
        for (int j = 0; j < lista_cliente[i].CantidadProductosAPedir; j++)
        {
            lista_cliente[i].Productos[j].ProductoID = j + 1; // ID del producto, inicia en 1

            // Cantidad de cada producto
            lista_cliente[i].Productos[j].Cantidad = 1 + rand() % 10;

            // Nombre del producto obtenido de arreglo TiposProductos
            int indice = 1 + rand() % 5; // Elijo de forma aleatoria el tipoo de producto

            lista_cliente[i].Productos[j].TipoProducto = (char *)malloc((strlen(TiposProductos[indice]) + 1) * sizeof(char)); // Reserva de memoria
            lista_cliente[i].Productos[j].TipoProducto = TiposProductos[indice];

            // Asignacion del precio unitario
            lista_cliente[i].Productos[j].PrecioUnitario = 10 + rand() % 91;

            // Determino el precio total
            montos[j] = montoTotal(lista_cliente[i].Productos[j]);

            //Suma de los montos de cada cliente
            total[i] = montos[j] + total[i];    //Suma de los montos de todos los productos
        }
    }

    free(Buff);
    free(montos);

    // Escritura  de lo cargado en las estructuras
    printf("Informacion de los %d clientes ingresados:\n", cantidadClientes);
    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("\n\t* Cliente %d: ", lista_cliente[i].ClienteID);   //ID del cliente

        puts(lista_cliente[i].NombreCliente);   //Nombre del cliente
        free(lista_cliente[i].NombreCliente);   //Libero la memoria asignada para cada nombre

        printf("\n\t");   //Salto de linea estetico

        printf("* Productos adquiridos por el cliente %d: \n", lista_cliente[i].ClienteID);

        //Escritura de lo cargado dentro de la estructura Productos
        for (int j = 0; j < lista_cliente[i].CantidadProductosAPedir; j++)
        {
            printf("\t\t--> Producto %d: ", lista_cliente[i].Productos[j].ProductoID);  //ID del producto

            puts(lista_cliente[i].Productos[j].TipoProducto);   //Nombre del producto obtenido del arreglo TiposProductos
            free(lista_cliente[i].Productos[j].TipoProducto);   //Libero la memoria usada para almacenar el nombre

            printf("\n");   //Salto de linea estetico

            printf("\t\t\t--> Cantidad pedida: %d\n", lista_cliente[i].Productos[j].Cantidad);
            printf("\t\t\t--> Precio unitario: $%.2f", lista_cliente[i].Productos[j].PrecioUnitario);
        }
        
        printf("\t ******______TOTAL A PAGAR DEL CLIENTE %d: $%.2f______******\n", lista_cliente[i].ClienteID, total[i]);
        
    }

    free(total);
    free(lista_cliente);

    return 0;
}

float montoTotal(Producto producto)
{
    float monto = producto.PrecioUnitario * producto.Cantidad;

    return monto;
}