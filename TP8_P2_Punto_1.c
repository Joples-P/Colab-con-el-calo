#include <stdio.h>
#include <stdlib.h>

typedef char string[50];

typedef struct{
	int nroCuenta;
	string nombre;
	int codOpe; //codigo de operacion;
	float importe;
}tClienteBanco;

tClienteBanco cliente;
FILE * banco;

void iniciarArchivo();
void proceso();
void finalizarArchivo();
void ingresarDatos();

int main(){
	iniciarArchivo();
	proceso();
	finalizarArchivo();
	return 0;
}

void iniciarArchivo(){
	banco = fopen("clientes_banco.dat", "wb");
	if(banco == NULL){
		printf("Error al abrir el archivo!\n");
		exit(EXIT_FAILURE);
	}else{
		printf("Se abrio el archivo correctamente!\n");
	}
}

void proceso(){
	char opcion;
	
	printf("\nDesea agregar datos(s/n): ");
	fflush(stdin);
	scanf("%c", &opcion);
	
	while(opcion == 's' || opcion == 'S'){
		ingresarDatos();
		fwrite(&cliente, sizeof(tClienteBanco), 1, banco);
		
		printf("Movimiento añadido!\n");
		printf("\nDesea seguir anadiendo datos?(s/n): ");
		fflush(stdin);
		scanf("%c", &opcion);
	}
	
}



void finalizarArchivo(){
	fclose(banco);
}

void ingresarDatos(){
	printf("\n*** Ingreso de datos ***\n");
	
	printf("\nIngrese el numero de cuenta: ");
	scanf("%d", &cliente.nroCuenta);
	
	printf("\nIngrese el nombre del cliente: ");
	scanf("%s", &cliente.nombre);
	
	printf("\nIngrese el codigo de operacion (1-Deposito / 2-Extraccion): ");
	scanf("%d", &cliente.codOpe);
	
	printf("\nIngrese el importe: ");
	scanf("%.2f", &cliente.importe);
	
}


