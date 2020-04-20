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

//FUNCIONES
void registroCliente(struct Registro);

void registroOperador(struct Registro);

int main(){
	char tipoUsuario;
	char opcion;
	int claveAcceso=1234, clave;
	struct Registro operador;
	
	printf("                            Bienvenido/a a ETSIDICHEMISTLAB\n");
	printf("Tu tienda online donde podras encontrar el producto quimico que tanto tiempo has estado buscando\n");
	
	printf("A continuacion te mostramos el menu de opciones:\n");
	printf("Elija donde quiere acceder: \n");
	printf("1. Registro.\n");
	printf("2. Stock.\n");
	printf("3. Venta.\n");
	scanf("%d", &opcion);
	if (opcion == 1){
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
							//registroOperador (&operador); No me funciona bien....????
							//Prueba para ver si compila bien
							fflush(stdin);
							printf("Nombre: ");
							scanf("%s", operador.nombre);
							fflush(stdin);
							printf("Apellidos: ");
							scanf("%s", operador.apellidos);
							fflush(stdin);
							printf("Contrasena: ");
							scanf("%s", operador.contrasena);
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
			do {
				printf("¿Que desea realizar?:\n");
				printf("a) Introduzca r para registrarte\n");
				printf("b) Introduzca a para acceder\n");
				printf("c) Introduzca s si quieres salir\n");
				getchar();
				scanf("%c", &opcion);
				system("cls");
				switch (opcion) {
				case 'r':
				case 'R':
					//Funcion del registro de un cliente
					break;
				case 'a':
				case 'A':
					//Funcion del acceso del cliente
					break;
				}
			} while (opcion != 's');
		}
	}			
	
	else if (opcion == 2){
		printf("Has entrado en el stock, que tipo de producto quieres?:\n");
		//Aqui tendremos que poner los ficheros de los productos (llamada a las funciones correspondientes)
		
	}
	else {
		printf("Has elegido acceder a la venta de productos\n");
		//Aqui estaran las ventas, facturas y demas (llamada a las funciones correspondientes)
	}
				

	return 0;
}

/*void registroOperador(struct Registro){
	struct Registro operador;
	fflush(stdin);
	printf("Nombre: ");
	scanf("%s", operador.nombre);
	fflush(stdin);
	printf("Apellidos: ");
	scanf("%s", operador.apellidos);
	fflush(stdin);
	printf("Contrasena: ");
	scanf("%s", operador.contrasena);
	fflush(stdin);
	printf("DNI: ");
	scanf("%s", operador.dni);
	fflush(stdin);
	printf("Email: ");
	scanf("%s", operador.email);
	fflush(stdin);
	printf("Sexo (masculino o femenino): ");
	scanf("%s", operador.sexo);
	fflush(stdin);
	printf("Localidad: ");
	scanf("%s", operador.localidad);
	
	printf("Dia-Mes-Ano de nacimiento: ");
	scanf("%d %d %d", &operador.fechaNacimiento.dia, &operador.fechaNacimiento.mes, &operador.fechaNacimiento.annyo);

	printf("Telefono: ");
	scanf("%d", &operador.tlf);

	printf("Numero de cuenta: ");
	scanf("%d", &operador.numeroCuenta);
	
	
}*/

	/*FILE *f, *pfichero1, *pfichero2, *pfichero3, *pfichero4;
	char x,y;
	int quimico;
	f = fopen("quimicos.txt", "r");
	
	if ( f == NULL) {
		printf("No se encuentra el fichero\n");
		return 0;
	}
	printf("A continuacion le mostramos la lista de productos: \n");
	while(fscanf(f, "%c", &x) != EOF){
		printf("%c", x);

	}
	printf("\n");
	
	fclose(f);
	printf("\n");
	do {
	
  	printf("Escoja uno de ellos: \n");
	scanf("%d", &quimico); 
	switch (quimico){
		
		case 1: printf("Acido clorhidrico\n"); 
		pfichero1 = fopen("acidoclorhidrico.txt", "r");
		while(fscanf(pfichero1, "%c", &x )!= EOF){
	         printf("%c", x);}
	         fclose(pfichero1);
			break;
		case 2: printf("Hidroxido de Sodio\n");
		pfichero2 = fopen("hidroxidodesodio.txt", "r");
		while(fscanf(pfichero2, "%c", &x )!= EOF){
	         printf("%c", x);}
	         fclose(pfichero2);
			break;
		case 3: printf("Acido sulfurico\n");
		pfichero3 = fopen("acidosulfurico.txt", "r");
		while(fscanf(pfichero3, "%c", &x )!= EOF){
	         printf("%c", x);}
	         fclose(pfichero3);
			break;
		case 4: printf("Acido nitrico\n"); 
			pfichero4 = fopen("acidonitrico.txt", "r");
			while(fscanf(pfichero4, "%c", &x )!= EOF){
	         printf("%c", x);}
	         fclose(pfichero4);break;
	    default: printf("Opcion incorrecta. Introduzcala otra vez\n");
		}
		
	}
	    
		while( quimico < 1 || quimico > 4);
		

	
	
	
		return 0;
	}*/
