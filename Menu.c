#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dia 22 MAYO

//FECHA DE NACIMIENTO
struct TFecha {
	int dia;
	int mes;
	int annyo;
};

//DATOS QUE SE VAN A SOLICITAR

struct Registro{
	char nombre[50];
	char apellidos[50];
	char email[50];
	char contrasena[50], localidad[50], sexo[10], calle[100], puerta[5], dni[10];
	int tlf, portal, piso, numeroCuenta, marca;
	struct TFecha fechaNacimiento;
};

//DATOS DE UN PRODUCTO

struct TProducto{
	char codigo[10];
	int cantidad;
	int precio;
};

//FUNCIONES EMPLEADAS PARA EL CORRECTO FUNCIONAMIENTO DE NUESTRA TIENDA ONLINE

int registroCliente(struct Registro cliente, int dimension);

int registroOperador(struct Registro operador, int dimension);

int compraProducto (struct TProducto pedido[], int dimension); 

int main(){
	
	char tipoUsuario;
	char opcion, opcion2, respuesta;
	int  i;
	char claveAcceso[10] = {"1234"}, clave[10];
	struct Registro oper;
	struct Registro cliente, operador;
	FILE *f, *pfichero1, *pfichero2, *pfichero3, *pfichero4,*pfichero5;
	char x,y;
	int quimico;
	struct TProducto pedido[5] = {{"AB", 10, 30}, {"BC", 20, 53}, {"CD", 30, 27}, {"DE", 40, 33}, {"EF", 50, 86}};
	int n;
	int dimension = 5;
	
	
	printf("\n");
	printf(" */*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/BIENVENIDO/A a ETSIDICHEMISTLAB/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf("\n");
	printf("Tu tienda online donde podras encontrar el producto quimico que tanto tiempo has estado buscando!!\n");
	
	printf("A continuacion, le mostramos el menu de opciones de nuestra tienda:\n");
	printf("Elija donde quiere acceder: \n");
	printf("1. Registro.\n");
	printf("2. Stock.\n");
	printf("3. Venta.\n");
	scanf("%d", &opcion);
	
	//DESARROLLAMOS LAS FUNCIONALIDADES DE LA TIENDA ATENDIENDO A LA OPCION ELEGIDA ANTERIORMENTE
	
	if (opcion == 1){ //DISTINGUIREMOS ENTRE OPERADOR Y CLIENTE 
		printf("Por favor, indique si es operador o cliente, para ello pulse:\n");
		printf("a) 'O' si es operador\n");
		printf("b) 'C' si es cliente\n");
		fflush(stdin);
		scanf("%c", &tipoUsuario);
		
		if (tipoUsuario == 'O' || tipoUsuario == 'o') { //CORRESPONDE A UN OPERADOR DE LA TIENDA
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
                        do{
                            printf("Antes de acceder, introduzca la clave de acceso " 
							"que le haya asignado su empresa: "); //La clave debe ser 1234
                            fflush(stdin);
                            scanf("%s", &clave);
                            if (strcmp(clave, claveAcceso) == 0) {
                                printf("Acceso concedido\n");
                               
                            }else {
                                printf("Ha introducido mal la clave, vuelva a introducirla\n");
                            }   
                        }while (strcmp(clave, claveAcceso) != 0);
                       	system("cls");
                        registroOperador (oper, 5);
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
            } while (opcion != 's' && opcion != 'a' && opcion != 'r' && opcion != 'A' &&opcion != 'S' && opcion != 'R');
            
		}else if (tipoUsuario == 'C' || tipoUsuario == 'c'){ //CORRESPONDE A UN CLIENTE DE LA TIENDA
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
			} while (opcion != 's' && opcion != 'S' && opcion != 'r' && opcion != 'R' && opcion != 'c' && opcion != 'C');
		}
		
//SE ACCEDE Al STOCK DIRECTAMENTE. EN EL CASO DE QUE DESEE REALIZAR UNA COMPRA, SE LE PEDIRÁ REGISTRARSE SIN TENER 
//QUE VOLVER A LA OPCION 1 DE REGISTRO

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
			    default: printf("Opcion no valida. Se dispone de 5 productos unicamente. Introduzcala otra vez\n");
			    		
			}
			
		}while( quimico < 1 || quimico > 5);
	}
	
	//SE ACCEDE A LA COMPRA-VENTA DE PRODUCTOS. SI NO SE HA REGISTRADO ANTES, SE LE PEDIRÁ HACERLO
	else if (opcion == 3) { 
		printf("Ha elegido acceder a la venta de productos\n");
		printf("Por favor, registrese para acceder\n");
		registroCliente (cliente, 5);
		system("cls");
		compraProducto(pedido, 5);
	}
	
	//FIN DEL PROGRAMA
	return 0;
}

//A CONTINUACIÓN SE DESARROLLAN LAS FUNCIONES EMPLEADAS EN EL PROGRAMA

//CUERPO FUNCION REGISTRO DE UN OPERADOR

int registroOperador(struct Registro operador, int dimension){
    FILE *F2;
    int contador=1, i;
    
    // Primer paso: ABRIR el fichero    
    F2 = fopen("datosdeloperador.txt", "r");
    
    if (F2 == NULL) {
        printf("No se encuentra el fichero\n");
    }
    
    // Segundo paso: LEER el fichero
    while (fscanf(F2,"%s %s %s %s %s %s %s %d %d %s %s %d %d %d %d %d", operador.nombre, operador.apellidos, 
			operador.contrasena, operador.dni, operador.email, operador.sexo, operador.calle, 
			&operador.portal, &operador.piso, operador.puerta, operador.localidad, &operador.fechaNacimiento.dia, 
			&operador.fechaNacimiento.mes, &operador.fechaNacimiento.annyo, &operador.tlf, 
			&operador.numeroCuenta) != EOF) {
        
        //contador++;
    }
    //contador--;
    
    //printf("Contador de puntos: %d\n", contador);
    
    // Tercer paso: CERRAR el fichero
    fclose(F2);
    
    //TRABAJAMOS CON EL VECTOR DE ESTRUCTURAS OPERADOR
    printf("Introduzca sus datos:\n");
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
	printf("Calle:");
	scanf("%s", operador.calle);
	
	printf("Portal-Piso-Puerta: ");
	scanf("%d %d %s", &operador.portal, &operador.piso, operador.puerta); 
	
	fflush(stdin);
	printf("Localidad: ");
	scanf("%s", operador.localidad);
	
	printf("Dia-Mes-Ano de nacimiento: ");
	scanf("%d %d %d", &operador.fechaNacimiento.dia, &operador.fechaNacimiento.mes, &operador.fechaNacimiento.annyo);
			
	printf("Telefono: ");
	scanf("%d", &operador.tlf);
		
	printf("Numero de cuenta: ");
	scanf("%d", &operador.numeroCuenta);
			
	//ABRIMOS EL FICHERO EN MODO ESCRITURA
	F2 = fopen ("datosdeloperador.txt", "w");
	
	if (F2 == NULL){
		printf("Fichero no encontrado\n");
		return 0;
	}
	
	for (i=0; i <contador; i++){
		fprintf(F2, "%s %s %s %s %s %s %s %d %d %s %s %d %d %d %d %d\n", operador.nombre, operador.apellidos, 
		operador.contrasena, operador.dni, operador.email, operador.sexo, operador.calle, operador.portal, 
		operador.piso, operador.puerta, operador.localidad, operador.fechaNacimiento.dia, 
		operador.fechaNacimiento.mes, operador.fechaNacimiento.annyo, operador.tlf, operador.numeroCuenta);
	}
	
	//POR ULTIMO, CERRAMOS EL FICHERO
	fclose(F2);
	return 0;
    
}


//CUERPO FUNCION REGISTRO DE UN CLIENTE

int registroCliente(struct Registro cliente,int dimension){
    FILE * F1;
    int contador=1, i;
    int opcion; // 1 si quiero dar de alta un nuevo punto; 2 si quiero salir 
    
    // Primer paso: ABRIR el fichero    
    F1 = fopen("datosdelcliente.txt", "r");
    
    if (F1 == NULL) {
        printf("No se encuentra el fichero\n");
        }
    
    // Segundo paso: LEER el fichero
    while (fscanf(F1,"%s %s %s %s %s %s %s %d %d %s %s %d %d %d %d %d", cliente.nombre, cliente.apellidos, 
		cliente.contrasena, cliente.dni, cliente.email, cliente.sexo, cliente.calle, &cliente.portal, 
		&cliente.piso, cliente.puerta, cliente.localidad, &cliente.fechaNacimiento.dia, 
		&cliente.fechaNacimiento.mes, &cliente.fechaNacimiento.annyo, &cliente.tlf, &cliente.numeroCuenta) != EOF) {
        
        //contador++;
    }
    
    //printf("Contador de puntos: %d\n", contador);
    
    // Tercer paso: CERRAR el fichero
    fclose(F1);
    
	//TRABAJAMOS CON EL VECTOR DE ESTRUCTURAS CLIENTE
    fflush(stdin);
    printf("Nombre: ");
    scanf("%s",cliente.nombre);
    
    fflush(stdin);
    printf("Apellidos: ");
    scanf("%s",cliente.apellidos);
    
    fflush(stdin);
    printf("Contrasena: ");
    scanf("%s",cliente.contrasena);
    
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
    scanf("%s",cliente.calle);
    
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
	
	//ABRIMOS EL FICHERO EN MODO ESCRITURA
    F1 = fopen("datosdelcliente.txt", "w");
    
    if (F1 == NULL) {
        printf("No se ha podido crear el fichero\n");
    }
    
    for (i=0; i < contador; i++) { // Escribo los datos en el fichero abierto
        fprintf(F1,"%s %s %s %s %s %s %s %d %d %s %s %d %d %d %d %d\n", cliente.nombre, cliente.apellidos, 
		cliente.contrasena, cliente.dni, cliente.email, cliente.sexo, cliente.calle, cliente.portal, cliente.piso, 
		cliente.puerta, cliente.localidad, cliente.fechaNacimiento.dia, cliente.fechaNacimiento.mes, 
		cliente.fechaNacimiento.annyo, cliente.tlf, cliente.numeroCuenta); 
		
    }
    
    //POR ULTIMO, CERRAMOS EL FICHERO
    fclose(F1);
    return 0;
} 

 
//CUERPO FUNCION COMPRA

int compraProducto (struct TProducto pedido[], int dimension){ 
	
	int numero = 0;
	char codigobuscado[10];
	int i;
	int unidad, cantidadFinal;
	int precioFinal;
	char respuesta2;
	
	
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
					precioFinal = unidad * pedido[i].precio;
					printf("La factura a pagar es de %d euros\n", precioFinal);
					printf("Se le enviara el producto en un plazo de 5 dias laborables\n");
					break;
				
				}else{
					printf("No hay suficiente stock\n");
				}
			}
			//else {
			//	if (numero ==5){
				//	printf("Has introducido un codigo erroneo\n");
				//}
				
			//}
		}
	} while(strcmp (pedido[i].codigo, codigobuscado) != 0 );
	
	//LE PREGUNTAMOS SI QUIERE SEGUIR COMPRANDO
	fflush(stdin);
	printf("Quiere realizar otra compra (S/Cualquier tecla): \n");
	scanf("%c", &respuesta2);
	
	if(respuesta2 == 's'|| respuesta2 == 'S') {
		compraProducto(pedido, 5);
		
	} else {
		printf("Gracias por su compra. Esperamos verlo de nuevo.\n");
		printf("Recibira su compra en su domicilio\n");
		return 0;
	}
			
	return 0;
}





