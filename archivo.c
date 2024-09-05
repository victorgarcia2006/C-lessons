#include <stdio.h>

int main(){

    FILE *archivo;
    archivo = fopen("archivo.txt", "w");

    if(archivo == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    } else {
        printf("Archivo abierto correctamente\n");
        fprintf(archivo, "Hola mundo\n");
        fclose(archivo);
    }
}