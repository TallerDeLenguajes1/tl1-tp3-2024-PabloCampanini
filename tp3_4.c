#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    //Productos a vender
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillo", "Caramelo", "Bebidas"};

    //Declaracion de varia
    int cantidadClientes;
    char *Buff = (char *)malloc(100 * sizeof(char));    //Variable aux para el nombre

    //Cantidad de clientes ingresados por el usuario
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    //Almacenamiento de los datos de los clientes
    Cliente *lista_cliente = (Cliente *) malloc(cantidadClientes * sizeof(Cliente));

    //Cargado de las estructuras
    for (int i = 0; i < cantidadClientes; i++)
    {
        lista_cliente[i].ClienteID = i + 1; //ID del cliente, empieza en 1

        //Cargado del nombre del cliente por el usuario
        printf("Ingrese el nombre del Cliente: %d", lista_cliente[i].ClienteID);
        gets(Buff);

        lista_cliente[i].NombreCliente = (char *)malloc((strlen(Buff)+1) * sizeof(char));
        strcpy(lista_cliente[i].NombreCliente,Buff);
    }
    

    return 0;
}