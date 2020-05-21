#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Dia 21 MAYO Intento 3

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
void registroCliente(struct Registro cliente, int dimension);

void registroOperador(struct Registro operador);

void compraProducto (struct TProducto pedido[], int dimension); //Pasar el vector de estructuras en elargumento
//void ListaProductos ();

int main(){
	
	char tipoUsuario;
	char opcion, opcion2, respuesta;
	int  i;
	char claveAcceso[10] = {"1234"}, clave[10];
	struct Registro oper;
	struct Registro cliente;
	FILE *f, *pfichero1, *pfichero2, *pfichero3, *pfichero4,*pfichero5;
	char x,y;
	int quimico;
	struct TProducto pedido[5] = {{"AB", 10, 30}, {"BC", 20, 53}, {"CD", 30, 27}, {"DE", 40, 33}, {"EF", 50, 86}};
	int n;
	int dimension = 5;
	//char codigo[10];
	printf(" */*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/BIENVENIDO/a a ETSIDICHEMISTLAB/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf("Tu tienda online donde podras encontrar el producto quimico que tanto tiempo has estado buscando!!\n");
	
	printf("A continuacion, te mostramos el menu de opciones:\n");
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
						do{
							printf("Antes de acceder, introduzca la clave de acceso que le haya asignado su empresa: "); //La clave debe ser 1234
							fflush(stdin);
							scanf("%s", &clave);
							if (strcmp(clave, claveAcceso) == 0) {
								printf("Acceso concedido\n");
								system("cls");
							}else {
								printf("Ha introducido mal la clave, vuelva a introducirla\n");
							}	
						}while (clave != claveAcceso);
						
						registroOperador (oper);
						break;
					case 'a':
					case 'A':
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
							printf("Gracias por acceder a ETSIDICHEMISTLAB. Hasta pronto!!\n");
							break;
						}
				} while (opcion != 's');
			/*do { //ESTO ES LO QUE TENIAMOS ANTES
				printf("Antes de acceder, introduzca la clave de acceso que le haya asignado su empresa: "); //La clave debe ser 1234
				fflush(stdin);
				scanf("%s", &clave);
				if (strcmp(clave, claveAcceso) == 0) {
					printf("Acceso concedido\n");
					system("cls");
					/*do {
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
							printf("Gracias por acceder a ETSIDICHEMISTLAB. Hasta pronto!!\n");
							break;
						}
					} while (opcion != 's');*/
				/*}
				else {
					printf("Ha introducido mal la clave, vuelva a introducirla\n");
				}
			} while (clave != claveAcceso);*/
		}
		else if (tipoUsuario == 'C' || tipoUsuario == 'c'){
			do {
				printf("¿Que desea realizar?:\n");
				printf("a) Introduzca r para registrarte\n");
				printf("b) Introduzca c para comprar\n");
				printf("c) Introduzca s si quieres salir\n");
				getchar();
				fflush(stdin);
				scanf("%c", &opcion);
				system("cls");
				switch (opcion) {
				case 'r':
				case 'R':
					//Funcion del registro de un cliente
					registroCliente (cliente, 5);
					break;
				case 'c':
				case 'C':
					//Funcion de la compra de un producto
					compraProducto (pedido, 5);
					break;
				}
			} while (opcion != 's');
		}
		
	}else if (opcion == 2){
		printf("Ha entrado en el stock\n");
		
		f = fopen("quimicos.txt", "r");
		
		if ( f == NULL) {
			printf("No se encuentra el fichero\n");
			return 0;
		}
		printf("A continuacion, puede consultar la lista de productos: \n");
		while(fscanf(f, "%c", &x) != EOF){
			printf("%c", x);
		}
		printf("\n");
		
		fclose(f);
		printf("\n");
		do {
			printf("Escoja uno de ellos:\n");
			scanf("%d", &quimico);
			system("cls");
			switch (quimico){
				
				case 1: printf("Acido clorhidrico\n"); 
						pfichero1 = fopen("acidoclorhidrico.txt", "r");
						while(fscanf(pfichero1, "%c", &x )!= EOF){
			         		printf("%c", x);
					 	}
			         	fclose(pfichero1);
			         	printf("\n");
			         	fflush(stdin);
			         	printf("Desea comprar el producto (S o N):\n\n");
			         	scanf("%c", &respuesta);
			         	if(respuesta=='s'|| respuesta=='S'){
			         		printf("Antes de comprar, por favor, registrese para acceder\n");
							registroCliente (cliente, 5);
			         		compraProducto(pedido, 5);
					 	}
						break;
				case 2: printf("Hidroxido de Sodio\n");
						pfichero2 = fopen("hidroxidodesodio.txt", "r");
						while(fscanf(pfichero2, "%c", &x )!= EOF){
			         		printf("%c", x);
					 	}
			         	fclose(pfichero2);
			         	printf("\n");
			         	fflush(stdin);
			         	printf("Desea comprar el producto (S o N):\n\n");
			         	scanf("%c", &respuesta);
			         	if(respuesta=='s'|| respuesta=='S'){
			         		printf("Antes de comprar, por favor, registrese para acceder\n");
			         		registroCliente (cliente, 5);
			         		compraProducto(pedido, 5);
					 	}
						break;
				case 3: printf("Acido sulfurico\n");
						pfichero3 = fopen("acidosulfurico.txt", "r");
						while(fscanf(pfichero3, "%c", &x )!= EOF){
			         		printf("%c", x);
						}
				        fclose(pfichero3);
				        
				        fflush(stdin);
			         	printf("Desea comprar el producto (S o N):\n\n");
			         	scanf("%c", &respuesta);
			         	if(respuesta=='s'|| respuesta=='S'){
			         		printf("Antes de comprar, por favor, registrese para acceder\n");
			         		registroCliente (cliente, 5);
			         		compraProducto(pedido, 5);
					 	}
						break;
				case 4: printf("Acido nitrico\n"); 
						pfichero4 = fopen("acidonitrico.txt", "r");
						while(fscanf(pfichero4, "%c", &x )!= EOF){
			         		printf("%c", x);
					 	}
			         	fclose(pfichero4);
			         	
			         	fflush(stdin);
			         	printf("Desea comprar el producto (S o N):\n\n");
			         	scanf("%c", &respuesta);
			         	if(respuesta=='s'|| respuesta=='S'){
			         		printf("Antes de comprar, por favor, registrese para acceder\n");
			         		registroCliente (cliente, 5);
			         		compraProducto(pedido, 5);
					 	}
					 	break;
			    case 5: printf("Acido fosforico\n"); 
						pfichero5 = fopen("acidofosforico.txt", "r");
						while(fscanf(pfichero5, "%c", &x )!= EOF){
			         		printf("%c", x);
					 	}
				        fclose(pfichero5);
				        printf("\n");
				        fflush(stdin);
			         	printf("Desea comprar el producto (S o N):\n\n");
			         	scanf("%c", &respuesta);
			         	if(respuesta=='s'|| respuesta=='S'){
			         		printf("Antes de comprar, por favor, registrese para acceder\n");
			         		registroCliente (cliente, 5);
			         		compraProducto(pedido, 5);
					 	}
						break;
			    default: printf("Opcion incorrecta. Introduzcala otra vez\n");
			}
			
		}while( quimico < 1 || quimico > 5);
	}
	else if (opcion == 3) {
		printf("Ha elegido acceder a la venta de productos\n");
		printf("Por favor, registrese para acceder\n");
		registroCliente (cliente, 5);
		system("cls");
		compraProducto(pedido, 5);
	}
	
	return 0;
}

//Cuerpo de la funcion del registro del operador
void registroOperador(struct Registro operador){
	
	//struct Registro oper;
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
void registroCliente(struct Registro cliente, int dimension){
	//struct Registro cliente[100];
	int i, contador=0;
	//FILE *f1;
	//int dimension;
	//f1 = fopen ("datosdelcliente.txt", "r");
	//fscanf(f1, "%d\n", &dimension);
	/*if (f1 == NULL){
		printf("No se ha encontrado el fichero\n");
		//return -1;
	}*/
/*	while (fscanf(f1, "%s %s %s %s %s %s %s %d %d %s %s %d %d %d %d %d", cliente.nombre, cliente.apellidos, cliente.contrasena, cliente.dni, cliente.email, cliente.sexo, cliente.calle, &cliente.portal, &cliente.piso, cliente.puerta, cliente.localidad, &cliente.fechaNacimiento.dia, &cliente.fechaNacimiento.mes, &cliente.fechaNacimiento.annyo, &cliente.tlf, &cliente.numeroCuenta) != EOF){
		contador++;
	} 
	printf("Numero de clientes registrados: %d\n", contador);*/
//	fclose(f1);
		
	fflush(stdin);
	printf("Nombre: ");
	gets(cliente.nombre);
	fflush(stdin);
	printf("Apellidos: ");
	gets(cliente.apellidos);
	fflush(stdin);
	printf("Contrasena: ");
	scanf("%s", cliente.contrasena);
	fflush(stdin);
	printf("DNI: ");
	scanf("%s", cliente.dni);
	fflush(stdin);
	printf("Email: ");
	scanf("%s", cliente.email);
	fflush(stdin);
	printf("Sexo (masculino o femenino): ");
	scanf("%s", cliente.sexo);
	fflush(stdin);
	printf("Calle:");
	gets(cliente.calle);
	printf("Portal-Piso-Puerta: ");
	scanf("%d %d %s", &cliente.portal, &cliente.piso, cliente.puerta); 
	fflush(stdin);
	printf("Localidad: ");
	scanf("%s", cliente.localidad);
	
	printf("Dia-Mes-Ano de nacimiento: ");
	scanf("%d %d %d", &cliente.fechaNacimiento.dia, &cliente.fechaNacimiento.mes, &cliente.fechaNacimiento.annyo);

	printf("Telefono: ");
	scanf("%d", &cliente.tlf);

	printf("Numero de cuenta: ");
	scanf("%d", &cliente.numeroCuenta);
	
	//f1 = fopen ("datosdelcliente.txt", "w");
	//dimension = dimension + 1;
	
	//f1 = fopen ("datosdelcliente.txt", "w");
	//fprintf(f1, "%d", dimension);
	/*if (f1 ==NULL){
		printf("No se encuentra el fichero\n");
	}
	
	for (i=0; i<=contador; i++){
		fprintf(f1, "%s %s %s %s %s %s %s %d %d %s %s %d %d %d %d %d\n", cliente.nombre, cliente.apellidos, cliente.contrasena, cliente.dni, cliente.email, cliente.sexo, cliente.calle, cliente.portal, cliente.piso, cliente.puerta, cliente.localidad, cliente.fechaNacimiento.dia, cliente.fechaNacimiento.mes, cliente.fechaNacimiento.annyo, cliente.tlf, cliente.numeroCuenta);
	}
	
	fclose (f1);*/
	
}

void compraProducto (struct TProducto pedido[], int dimension){ 
	//struct TProducto pedido1[5];
	int numero = 0;
	char codigobuscado[10];
	int i;
	int unidad, cantidadFinal;
	int precioFinal;
	char respuesta2;
	int facturaFinal; //Para acumular facturas de una misma compra
	
	do{
		printf("Introduzca el codigo del producto que quiere comprar:\n");
		printf("CODIGO -> PRODUCTO\n");
		printf("AB->Acido Clorhidrico\n");
		printf("BC->Hidroxido Sodico\n");
		printf("CD->Acido Sulfurico\n");
		printf("DE->Acido Nitrico\n");
		printf("EF->Acido Fosforico\n");
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
					printf("La factura a pagar es de %d euros\n", precioFinal);
					printf("Se le enviara el producto en un plazo de 5 dias laborables\n");
					
					fflush(stdin);
					printf("Quiere realizar otra compra (S/Cualquier tecla): \n");
					scanf("%c", &respuesta2);
					if(respuesta2 == 's'|| respuesta2 == 'S'){
			         	compraProducto(pedido, 5);
			         	//precioFinal += pedido[i].precio;
					}
					facturaFinal += precioFinal;
					printf("Su factura final es de %d euros\n", facturaFinal);
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
