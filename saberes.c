#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create();
void read();
void sort();
void average();
void exitUser();

int main()
{
    encabezado();
    menu();
}

void encabezado()
{
    printf("INSTITUTO POLITECNICO NACIONAL\n");
    printf("UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERIA CAMPUS ZACATECAS\n");
    printf("ZACATECAS, ZACATECAS, A 05 DE SEPTIEMBRE DEL 2024\n");
    printf("ELABORADO POR: VICTOR ALFREDO GARCIA CALVILLO\n");
}

void menu()
{
    char option;

    printf("Bienvenido! ¿Que accion quieres realizar?\n");
    printf("A) Dar de alta a algun alumno\n");
    printf("B) Consultar los datos almacenados \n");
    printf("C) Ordenar los datos almacenados\n");
    printf("D) Promedio de edades\n");
    printf("E) Salir\n");

    scanf("%s", &option);

    if(option == 'A' || option == 'a')
    {
        create();
    }
    else if(option == 'B' || option == 'b')
    {
        read();
    }
    else if(option == 'C' || option == 'c')
    {
        sort();
    }
    else if(option == 'D' || option == 'd')
    {
        average();
    }
    else if(option == 'E' || option == 'e')
    {
        exitUser();
    }
    else
    {
        printf("Opcion no encontrada, intenta de nuevo");
    }
}

void create()
{
    system("cls");
    char nombre[100];
    int edad = 0;
    char sexo[20];
    char direccion[200];
    int telefono = 0;
    char email[50];
    char answer;

    FILE *database;
    database = fopen("database.txt", "a");
    if(database != NULL)
    {
        printf("Introduzca los siguientes datos: \n");
        printf("Nombre completo (Apellido paterno, apellido materno y nombres): ");
        fgets(nombre, 100, stdin);
        scanf("%[^\n]%*c", &nombre);
        printf("\nEdad: ");
        scanf("%i", &edad);
        printf("\nSexo: ");
        scanf("%s", &sexo);
        printf("\nDireccion: ");
        fgets(direccion, 200, stdin);
        scanf("%[^\n]%*c", &direccion);
        printf("\nTelefono: ");
        scanf("%i", &telefono);
        printf("\nEmail: ");
        fgets(email, 50, stdin);
        scanf("%[^\n]%*c", &email);

        fprintf(database, "Nombre: %s\n", nombre);
        fprintf(database, "Edad: %d\n", edad);
        fprintf(database, "Sexo: %s\n", sexo);
        fprintf(database, "Direccion: %s\n", direccion);
        fprintf(database, "Telefono: %d\n", telefono);
        fprintf(database, "Email: %s\n", email);
        printf("\nAlumno registrado correctamente\n");
        fclose(database);
        printf("¿Quieres registrar otro alumno (S/N)?: ");
        scanf("%s", &answer);
        if(answer == 'S' || answer == 's')
        {
            create();
        }
        else
        {
            system("cls");
            menu();
        }
    }
    else
    {
        printf("Error al conectarse a la base de datos");
    }

}

void read()
{
    system("cls");
    char nombre[100];
    int edad = 0;
    char sexo[20];
    char direccion[200];
    int telefono = 0;
    char email[50];
    int total = 6;
    char line[2000];
    char answer;

    FILE *database;
    database = fopen("database.txt", "r");

    if(database != NULL)
    {
        while(fgets(line, 2000, database)){
            printf("\n%s", line);
        }
        printf("Quieres regresar al menu? (S/N)");
        scanf("%s", &answer);
        if(answer == 'S' || answer == 's'){
            fclose(database);
            system("cls");
            menu();
        }
    }
    else
    {
        printf("Error al conectarse con la base de datos");
    }
}

void sort()
{
    printf("Funcion para ordenar alumnos");
}

void average()
{
    system("cls");
    FILE *database;
    database = fopen("database.txt", "r");
    char line[2000];
    float counter = 0;
    float suma = 0;
    float promedio;
    char answer;

    if(database != NULL)
    {
        while(fgets(line, 2000, database)){
            if(strstr(line, "Edad:")){
                int age = atoi(line+6);
                suma += age;
                counter++;
            }
        }
        promedio = suma / counter;
        printf("Promedio de edades: %.3f\n\n\n", promedio);
        printf("Quieres regresar al menu? (S/N)");
        scanf("%s", &answer);
        if(answer == 'S' || answer == 's'){
            fclose(database);
            system("cls");
            menu();
        }
    }
    else
    {
        printf("Error al conectarse con la base de datos");
    }
}

void exitUser()
{
    printf("FIN DEL CURSO");
}
