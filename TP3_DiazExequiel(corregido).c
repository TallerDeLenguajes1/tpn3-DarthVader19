#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//-------estructuras-------
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
}Productos;

typedef struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
Productos *Producto; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Clientes;

//-----------Prototipos----------------
Clientes *Interfaz();
void CargarClientes(Clientes *usuario, int n);
void CargarProductos(Clientes *p_usuario,int cantidad,int i);

//------------MAIN-----------------
int main(){
	Clientes *cliente;//cliente es una variable puntero a Clientes 
	cliente = Interfaz();//llamo a la función que me solicita la cantidad de clientes y me devuelve el espacio de memoria para mis estructuras dependiend del nro de clientes

	
	return 0;
}

//----------DESARROLLO DE FUNCIONES-------	
Clientes *Interfaz(){
	int nroclientes;//numero de clientes
	Clientes*usuarios;
	
	printf("Ingrese el numero de Clientes:\n");
	scanf("%d",&nroclientes);
	usuarios = (Clientes *)malloc(sizeof(Clientes)*nroclientes);//reservo espacio para 5 usuarios
	
	//--------cargar los clientes-------
	CargarClientes(usuarios,nroclientes);
	
	return usuarios;
}

void CargarClientes(Clientes *usuario, int n){
	int i,tama,cant;
	char *nom;//variable auxiliar para guardar el nombre
	Clientes *p_user;//esta sera una variable auxiliar para sacar el tamaño a reservar
	
	for(i=0;i<n;i++)
	{
			printf("\nDatos del Cliente #%d:\n",i+1);
			p_user->ClienteID = i+1;
			printf("Ingrese Nombre: \n");
			fflush(stdin);
			fgets(nom,20,stdin);//acá reservo 20 lugares,pero para hacerlo mas eficiente debo reservar la memoria justa. Para ello
			tama = strlen(nom);//saco el tamanio de la cadena para determinar los bites a reservar
			p_user->NombreCliente = malloc(sizeof(tama));//en la estructura reservo el tamanio justo para guardar el nombre
			if(p_user->NombreCliente ==NULL)
			{
				printf("error al reservar memoria en el nombre.");
			}else{
				strcpy(p_user->NombreCliente,nom);
			}
			//free(nom); ¿Está bien limpiar aquí? o es mejor hacerlo despues que termine la iteracion?
			printf("\nIngrese cantiad de productos:\n");
			scanf("%d",p_user->CantidadProductosAPedir);
			cant = p_user->CantidadProductosAPedir;
			p_user[i].Producto= (Productos*)malloc(sizeof(Productos)*cant);
			
			CargarProductos(p_user,cant,i);
	}
	
}

void CargarProductos(Clientes *p_usuario,int cantidad,int i){
	
	int precio_unitario,aleatorio,j,tamanio;
	
	for(j=0;j< cantidad;j++)
	{
		precio_unitario = 10 + rand() % 91;
		aleatorio = rand() % 5;
		p_usuario[i].Producto[j].ProductoID = j+1;
		p_usuario[i].Producto[j].Cantidad = 1 + rand() % 11;
		tamanio = strlen(TiposProductos[aleatorio]);
		p_usuario[i].Producto[j].TipoProducto= (char*)malloc(sizeof(char)*tamanio);
		strcpy(p_usuario[i].Producto[j].TipoProducto,TiposProductos[aleatorio]);
		p_usuario[i].Producto[j].PrecioUnitario = 10 + rand() % 91;
		p_usuario[i].Producto + j;
	}
	
}
