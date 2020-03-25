#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Registro{
	char nombre[50];
	char apellidos[50];
	char email[50];
	char contrasena[50], localidad[50], sexo[10], calle[100], puerta[5], dni[10];
	int dnacimiento, mnacimiento, anacimiento, tlf, portal, piso, numeroCuenta;
};
void RegistroCliente(struct Registro);


int main(){
	int opcion;
	char tipoUsuario;
	int contrasena= 111;
	struct Registro;
	char nombre[50]="";
	printf("                            Bienvenido/a a ETSIDICHEMISTLAB\n");
	printf("Tu tienda online donde podras encontrar el producto quimico que tanto tiempo has estado buscando\n");
	printf("A continuacion te mostramos el menu de opciones:\n");
	printf("1. Registro.\n");
	printf("2. Stock.\n");
	printf("3. Venta.\n");
	scanf("%d", &opcion);
	if(opcion == 1){
		printf("Por favor, indique si es operador o cliente, para ello pulse:\n");
		printf("a) 'O' si es operador\n");
		printf("b) 'C' si es cliente\n");
		fflush(stdin);
		scanf("%c", &tipoUsuario);
	}
	do{
		printf("Introduce tu contrasena:\n");
		scanf("%d", &contrasena);
		printf("Bienvenido operador\n");
		struct Registro();
		
	
	}while (opcion == 'o' || opcion == 'O');
	
	
	return 0;
}

void RegistroCliente(struct Registro){
	printf("Introduce tu nombre:\n");
	scanf("%s", Registro.nombre);
	printf("Introduce tu apellido:\n");
	scanf("%s", Registro.);
	
}
