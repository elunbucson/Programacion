#include <stdio.h>


int es_par(int numero) {
    return numero % 2 == 0;
}


int es_impar(int numero) {
    return numero % 2 != 0;
}

void imprimir_y_sumar(int inicio, int fin, int tipo) {
    int suma = 0;
    printf("Números ");
    printf(tipo == 0 ? "pares" : "impares");
    printf(" en el rango [%d, %d]:\n", inicio, fin);

    for (int i = inicio; i <= fin; i++) {
        if ((tipo == 0 && es_par(i)) || (tipo == 1 && es_impar(i))) {
            printf("%d ", i);
            suma += i;
        }
    }
    printf("\nSuma: %d\n", suma);
}

void manejar_opciones(int inicio, int fin) {
    int opcion;
    do {
        printf("\nElija una operación:\n");
        printf("1. Mostrar números pares y su suma\n");
        printf("2. Mostrar números impares y su suma\n");
        printf("3. Mostrar números pares e impares con sus sumas\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            imprimir_y_sumar(inicio, fin, 0);
        } else if (opcion == 2) {
            imprimir_y_sumar(inicio, fin, 1);
        } else if (opcion == 3) {
            printf("\n--- Números pares ---\n");
            imprimir_y_sumar(inicio, fin, 0);
            printf("\n--- Números impares ---\n");
            imprimir_y_sumar(inicio, fin, 1);
        } else if (opcion == 4) {
            printf("Saliendo del programa...\n");
        } else {
            printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}

int main() {
    int inicio, fin;


    do {
        printf("Ingrese el valor inicial del rango: ");
        scanf("%d", &inicio);
        printf("Ingrese el valor final del rango: ");
        scanf("%d", &fin);

        if (inicio > fin) {
            printf("El valor inicial debe ser menor o igual al valor final. Intente de nuevo.\n");
        }
    } while (inicio > fin);

    manejar_opciones(inicio, fin);

    return 0;
}
