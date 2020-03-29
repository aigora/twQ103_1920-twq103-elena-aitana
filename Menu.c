#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TFecha {
	int dia;
	int mes;
	int annyo;
};

struct Registro{
	char nombre[50];
	char apellidos[50];
	char email[50];
	char contrasena[50], localidad[50], sexo[10], calle[100], puerta[5], dni[10];
	int tlf, portal, piso, numeroCuenta;
	struct TFecha fechaNacimiento;
};

void RegistroCliente(struct Registro);

void RegistroOperador(struct Operador);

int main(){
	char tipoUsuario;
	char opcion;
	int claveAcceso=1234, clave;
	
	printf("                            Bienvenido/a a ETSIDICHEMISTLAB\n");
	printf("Tu tienda online donde podras encontrar el producto quimico que tanto tiempo has estado buscando\n");
	
	printf("A continuacion te mostramos el menu de opciones:\n");
	printf("1. Registro.\n");
	printf("2. Stock.\n");
	printf("3. Venta.\n");
	scanf("%d", &opcion);			
	printf("Por favor, indique si es operador o cliente, para ello pulse:\n");
	printf("a) 'O' si es operador\n");
	printf("b) 'C' si es cliente\n");
	fflush(stdin);
	scanf("%c", &tipoUsuario);
	if (tipoUsuario == 'O' || tipoUsuario == 'o') {
		do {
			printf("Antes de acceder, introduzca la clave de acceso que le hayan asignado: "); //La clave debe ser 1234
			scanf("%d", &clave);
			if (clave == 1234) {
				printf("Acceso concedido\n");
				printf("\n");
				do {
					printf("¿Que desea realizar?\n");
					printf("a) Introduzca r para registrarte\n");
					printf("b) Introduzca a para acceder\n");
					printf("c) Introduzca s para salir\n");
					getchar();
					scanf("%c", &opcion);
					system("cls");
					switch (opcion) {
					case 'r':
					case 'R':
						//Aqui pondriamos la funcion del registro del operador
						printf("Introduce tu nombre:");
						break;
					case 'a':
					case 'A':
						//Aqui pondriamos la funcion del acceso del operador
						break;
					}
				} while (opcion != 's');
			}
			else {
				printf("Ha introducido mal la clave, vuelva a introducirla\n");
			}
		} while (clave != claveAcceso);
	}
	else if (tipoUsuario == 'C' || tipoUsuario == 'c'){
		
	}
	if (opcion == 2){
		printf("Has entrado en el stock, que tipo de producto quieres?");
	}
	
				

	return 0;
}

/*void RegistroOperador(struct Operador){
	int i;
	
	printf("Introduce tu nombre: ");
	scanf("%s", Registro[i].nombre);
	printf("Introduce tu apellidos: ");
	scanf("%s", Registro[i].apellidos);
	
}*/
