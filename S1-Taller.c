#include <stdio.h>

int main() {
    int productoID;
    char nombre[50];
    int stock;
    float precio;
    float ganancias = 0.0f;
    int opcion;
    int unidades;
    float descuento;

    printf("Registro del producto\n");
    printf("Ingrese ID del producto: ");
    scanf("%d", &productoID);
    printf("Ingrese el nombre del producto: ");
    scanf("%c", nombre);
    printf("Ingrese cantidad en stock: ");
    scanf("%d", &stock);
    printf("Ingrese precio unitario: ");
    scanf("%f", &precio);

    do {
        printf("\nMenu\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Consultar informacion\n");
        printf("4. Mostrar ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese cantidad a vender:");
                scanf("%d", &unidades);
                if (unidades <= 0) {
                    printf("Cantidad invalida. Debe ser mayor a cero.\n");
                } else if (unidades > stock) {
                    printf("No hay suficiente stock para vender %d unidades.\n", unidades);
                } else {
                    printf("Ingrese descuento aplicado (0 si no hay descuento por aplicar): ");
                    scanf("%f", &descuento);
                    if(descuento < 0 || descuento > precio) {
                        printf("Descuento invalido. No se aplicara descuento.\n");
                        descuento = 0;
                    }
                    float precioFinal = precio - descuento;
                    float ventaTotal = unidades * precioFinal;
                    stock -= unidades;
                    ganancias += ventaTotal;
                    printf("Venta realizada. Total: $%.2f\n", ventaTotal);
                }
                break;

            case 2:
                printf("Ingrese cantidad para reabastecer: ");
                scanf("%d", &unidades);
                if (unidades <= 0) {
                    printf("Cantidad invalida. Debe ser mayor a cero.\n");
                } else {
                    stock += unidades;
                    printf("Stock actualizado. Nuevo stock: %d\n", stock);
                }
                break;

            case 3:
                printf("Informacion del producto:\n");
                printf("ID: %d\n", productoID);
                printf("Nombre: %s\n", nombre);
                printf("Stock: %d\n", stock);
                printf("Precio unitario: $%.2f\n", precio);
                break;

            case 4:
                printf("Ganancias totales: $%.2f\n", ganancias);
                break;

            case 5:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion == 5);

    return 0;
}
