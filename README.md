#include <stdio.h>

void leer_calificaciones(float califs[][3]);
float validar_entrada();
void calcular_promedio_estudiante(float califs[][3]);
void calcular_promedio_asignatura(float califs[][3]);
void encontrar_max_min(float califs[][3]);
void contar_aprobados_reprobados(float califs[][3]);
void mostrar_datos(float califs[][3]);

int main() {
    float calificaciones[5][3];

    printf("--- GESTION DE CALIFICACIONES ---\n");

    leer_calificaciones(calificaciones);
    printf("\n--- DATOS DE CALIFICACIONES INGRESADOS ---\n");
    mostrar_datos(calificaciones);

    printf("\n--- RESULTADOS POR ESTUDIANTE ---\n");
    calcular_promedio_estudiante(calificaciones);

    printf("\n--- RESULTADOS POR ASIGNATURA ---\n");
    calcular_promedio_asignatura(calificaciones);
    contar_aprobados_reprobados(calificaciones);

    printf("\n--- CALIFICACIONES MAXIMAS Y MINIMAS ---\n");
    encontrar_max_min(calificaciones);

    return 0;
}

void leer_calificaciones(float califs[][3]) {
    printf("Ingrese las calificaciones (rango 0 a 10):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Estudiante %d, Asignatura %d: ", i + 1, j + 1);
            califs[i][j] = validar_entrada();
        }
    }
}

float validar_entrada() {
    float nota;
    while (scanf("%f", &nota) != 1 || nota < 0.0f || nota > 10.0f) {
        while (getchar() != '\n'); 
        printf("Error. Ingrese una calificacion valida (0 a 10): ");
    }
    return nota;
}

void mostrar_datos(float califs[][3]) {
    printf("        | Asig 1 | Asig 2 | Asig 3 |\n");
    printf("----------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Estud %d | ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%6.1f |", califs[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
}

void calcular_promedio_estudiante(float califs[][3]) {
    for (int i = 0; i < 5; i++) {
        float suma = 0.0f;
        for (int j = 0; j < 3; j++) {
            suma += califs[i][j];
        }
        printf("Promedio Estudiante %d: %.2f\n", i + 1, suma / 3);
    }
}

void calcular_promedio_asignatura(float califs[][3]) {
    for (int j = 0; j < 3; j++) {
        float suma = 0.0f;
        for (int i = 0; i < 5; i++) {
            suma += califs[i][j];
        }
        printf("Promedio Asignatura %d: %.2f\n", j + 1, suma / 5);
    }
}

void encontrar_max_min(float califs[][3]) {
    
    for (int i = 0; i < 5; i++) {
        float max_e = -1.0f; 
        float min_e = 11.0f; 
        for (int j = 0; j < 3; j++) {
            if (califs[i][j] > max_e) max_e = califs[i][j];
            if (califs[i][j] < min_e) min_e = califs[i][j];
        }
        printf("Estudiante %d: Max %.1f, Min %.1f\n", i + 1, max_e, min_e);
    }

    
    for (int j = 0; j < 3; j++) {
        float max_a = -1.0f;
        float min_a = 11.0f;
        for (int i = 0; i < 5; i++) {
            if (califs[i][j] > max_a) max_a = califs[i][j];
            if (califs[i][j] < min_a) min_a = califs[i][j];
        }
        printf("Asignatura %d: Max %.1f, Min %.1f\n", j + 1, max_a, min_a);
    }
}

void contar_aprobados_reprobados(float califs[][3]) {
    for (int j = 0; j < 3; j++) {
        int aprobados = 0;
        int reprobados = 0;
        for (int i = 0; i < 5; i++) {
            if (califs[i][j] >= 6.0f) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        // Línea modificada para eliminar el texto de la Nota Aprobatoria
        printf("Asignatura %d: Aprobados: %d, Reprobados: %d\n", j + 1, aprobados, reprobados);
    }
}
