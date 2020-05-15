#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Dia 14 MAYO 

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

struct TProducto{
	char codigo[10];
	int cantidad;
	int precio;
};

//FUNCIONES
void registroCliente(struct Registro cliente);

void registroOperador(struct Registro operador);

void compraProducto (struct TProducto pedido[], int dimension); //Pasar el vector de estructuras en elargumento
//void ListaProductos ();

int main(){
	
	char tipoUsuario;
	char opcion, opcion2;
	int  i;
	//char aux[10];
	char claveAcceso[10] = {"1234"}, clave[10];
	struct Registro oper;
	struct Registro client;
	FILE *f, *pfichero1, *pfichero2, *pfichero3, *pfichero4,*pfichero5;
	char x,y;
	int quimico;
	struct TProducto pedido[5] = {{"AB", 10,30}, {"BC", 20,53}, {"CD", 30,27}, {"DE", 40,33}, {"EF", 50,86}};
	int n;
	int dimension = 5;
	//char codigo[10];
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
				fflush(stdin);
				scanf("%s", &clave);
				if (strcmp(clave, claveAcceso) == 0) {
					printf("Acceso concedido\n");
					printf("\n");
					do {
						printf("¿Que desea realizar?\n");
						printf("a) Introduzca r para registrarte\n");
						printf("b) Introduzca a para acceder\n");
						printf("c) Introduzca s para salir\n"); //PREGUNTAR COMO SALIR DEL PROGRAMA!!
						getchar();
						scanf("%c", &opcion);
						system("cls");
						switch (opcion) {
						case 'r':
						case 'R':
							registroOperador (oper); 
							break;
						case 'a':
						case 'A':
							//Aqui pondriamos la funcion del acceso del operador
							printf("Bienvenido al stock\n");
							printf("Quiere consultar el stock? (S/Cualquier letra):\n");
							fflush(stdin);
							scanf("%c", &opcion2);
							if (opcion2 == 'S' || opcion2 == 's'){
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
							}else {
								printf("Hasta pronto.\n");
							}
							break;
						case 's':
						case 'S': 
							printf("Hasta luego\n");
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
					registroCliente (client);
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
		printf("Has entrado en el stock. Elija el producto:\n");
		
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
			         fclose(pfichero4);
					 break;
			    case 5: printf("Acido fosforico\n"); 
					pfichero5 = fopen("acidofosforico.txt", "r");
					while(fscanf(pfichero5, "%c", &x )!= EOF){
			         printf("%c", x);}
			         fclose(pfichero5);
					 break;
			    default: printf("Opcion incorrecta. Introduzcala otra vez\n");
			}
			
		}while( quimico < 1 || quimico > 5);
	}
	else {
		printf("Has elegido acceder a la venta de productos\n");
		printf("Registrese para acceder\n");
		//registroCliente (client);
		
		compraProducto(pedido, 5);
	}

	return 0;
}

//Cuerpo de la funcion del registro del operador
void registroOperador(struct Registro operador){
	
	struct Registro oper;
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
	
}

//Cuerpo de la funcion del registro del cliente
void registroCliente(struct Registro cliente){
	struct Registro client[100];
	int i;
	/*FILE *f1;
	int i, dimension;
	f1 = fopen ("datosdelcliente.txt", "r");
	fscanf(f1, "%d\n", &dimension);
	for (i=0; i<dimension; i++){
		fscanf(f1, "%s %s %s %s %s %s %s %d %d %s %s %d %d %d %d %d\n", client[i].nombre, client[i].apellidos, client[i].contrasena, client[i].dni, client[i].email, client[i].sexo, client[i].calle, &client[i].portal, &client[i].piso, client[i].puerta, client[i].localidad, &client[i].fechaNacimiento[i].dia, &client[i].fechaNacimiento[i].mes, &client[i].fechaNacimiento[i].annyo, &client[i].tlf, &client[i].numeroCuenta);
	}
	fclose (f1);*/
	
	fflush(stdin);
	printf("Nombre: ");
	scanf("%s", client[i].nombre);
	fflush(stdin);
	printf("Apellidos: ");
	scanf("%s", client[i].apellidos);
	fflush(stdin);
	printf("Contrasena: ");
	scanf("%s", client[i].contrasena);
	fflush(stdin);
	printf("DNI: ");
	scanf("%s", client[i].dni);
	fflush(stdin);
	printf("Email: ");
	scanf("%s", client[i].email);
	fflush(stdin);
	printf("Sexo (masculino o femenino): ");
	scanf("%s", client[i].sexo);
	fflush(stdin);
	printf("Calle-Portal-Piso-Puerta:\n");
	scanf("%s %d %d %s", client[i].calle, &client[i].portal, &client[i].piso, client[i].puerta);
	fflush(stdin);
	printf("Localidad: ");
	scanf("%s", client[i].localidad);
	
	printf("Dia-Mes-Ano de nacimiento: ");
	scanf("%d %d %d", &client[i].fechaNacimiento.dia, &client[i].fechaNacimiento.mes, &client[i].fechaNacimiento.annyo);

	printf("Telefono: ");
	scanf("%d", &client[i].tlf);

	printf("Numero de cuenta: ");
	scanf("%d", &client[i].numeroCuenta);
	//dimension = dimension + 1;
	
	/*f1 = fopen ("datosdelcliente.txt", "w");
	fprintf(f1, "%d", dimension);
	for (i=0; i<dimension; i++){
		fprintf(f1, "%s %s %s %s %s %s %s %d %d %s %s %d %d %d %d %d\n", client[i].nombre, client[i].apellidos, client[i].contrasena, client[i].dni, client[i].email, client[i].sexo, client[i].calle, client[i].portal, client[i].piso, client[i].puerta, client[i].localidad, client[i].fechaNacimiento[i].dia, client[i].fechaNacimiento[i].mes, client[i].fechaNacimiento[i].annyo, client[i].tlf, client[i].numeroCuenta);
	}
	fclose (f1);*/
	
	
}

void compraProducto (struct TProducto pedido[], int dimension){ 
	
	int numero = 0;
	char codigobuscado[10];
	int i;
	int unidad, cantidadFinal;
	int precioFinal;
	
	do{
		printf("Introduzca el codigo del producto que quiere comprar:\n");
		scanf("%s", codigobuscado);
		for(i=0; i <5; i++){
		
			if (strcmp (pedido[i].codigo, codigobuscado) == 0 ) {
				printf("¿Cuantas unidades quieres?:\n");
				scanf("%d", &unidad);
				fflush(stdin);
			
				if ((unidad >=1) && (unidad < pedido[i].cantidad)){
					cantidadFinal = pedido[i].cantidad - unidad;
					printf("La cantidad final del producto en el almacen es %d\n", cantidadFinal);
					precioFinal = unidad * pedido[i].precio;
					printf("El precio del producto %d euros\n", precioFinal);
					break;
				}else{
					printf("No hay suficiente stock\n");
				}
			}
			else {
				numero++;
					if (numero == 5) {
			printf("Has introducido un codigo erroneo\n");
			}
		
		}
		}
	} while(strcmp (pedido[i].codigo, codigobuscado) != 0 );
	
	
}
