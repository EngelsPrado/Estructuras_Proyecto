#include <stdio.h>
#include <stdlib.h>

/*

   Nombre: Engels Prado Herrera                    Asignatura: Estructura de Datos
    
   Docente:Lesbia Valerio                          Carrera:Ing.En sistemas de informacion 

   Objetivo: La Tienda “Compra Feliz”, desea registrar la información de sus productos (código, descripción, precio).
            Para ello ha solicitado un programa que presente las siguientes opciones: 
 
         Ingresar Productos         Mostrar Productos         Salir 
 
         El usuario debe poder ingresar tantos productos como necesite (n productos). Cuando seleccione
		 mostrar que presente la lista de todos los productos (código, descripción, precio) Primero que entro          
		 primero en salir en la lista de productos y al final de la lista mostrada, el producto que tiene el precio          mayor.  Menor. 

*/


struct nodo{

  int codigo;
  char descripcion[50];
  float precio;
  struct nodo *sig;
	
};


typedef struct nodo Cola;
typedef Cola *cola;


int menu();//Presenta un menu
void insertarProducto(cola *);//Inserta elementos a la cola
void mostrarProductos(cola);//Muestra todos los elementos de la cola

int main(int argc, char *argv[]) {
	
	cola inicio=NULL;
	
	int opc;
	
	
	opc=menu();
	
	do
	{
		
	  switch(opc)
	  {
	  	
	  	case 1: insertarProducto(&inicio);
	  	        break;
	  	
	  	case 2: mostrarProductos(inicio);
	  	        break;
	  }	
	  
	    
		opc=menu();
		
	}while(opc!=3);
	
	
	return 0;
}

int menu()
{
	
	int opc;
	printf("\n\n\n\t\t\t\t\t M   E    N     U \n\n\n");
	do
	{
	  printf("\n\n\n\t\t\t1.Insertar nuevo productos \n");
	  printf("\t\t\t2.Mostrar productos \n");
	  printf("\t\t\t3.Salir \n");
	  printf("\n\n\n\t\t\tOPCION ");
	  scanf("%d",&opc);	
		
	}while(opc<1 || opc>3);
	
	return opc;
}

//Muestra todos los productos insertados
void mostrarProductos(cola inicio)
{
	float mayor,menor;
	int codigoMenor,codigoMayor;
	
	system("cls");
	
	mayor=menor=inicio->precio;
	codigoMenor=codigoMayor=1;
	printf("\n\t\t\tLISTADO DE PRODUCTOS \n\n\n");
	
	printf("\n\t\t\tCodigo %15s %15s \n\n","Descripcion", "Precio");
	while(inicio!=NULL)
	{
		
	 printf("\n\t\t\t%d %15s %20.2f \n",inicio->codigo,inicio->descripcion,inicio->precio);
	 
	 if(menor>inicio->precio)
	  {
	  	menor=inicio->precio;
	  	codigoMenor=inicio->codigo;
	  }else
	       if(mayor<inicio->precio)
	       {
	       	mayor=inicio->precio;
	       	codigoMayor=inicio->codigo;
		   }
	 
	 inicio=inicio->sig;	
	}
	
	printf("\n\n\nEl precio menor es:%.2f con codigo: %d",menor,codigoMenor);
	printf("\n\nEl precio mayor es:%.2f con codigo: %d",mayor,codigoMayor);
	printf("\n\n");
	system("pause");
	system("cls");
}

//Inserta nuevos elementos en forma de cola
void insertarProducto(cola *ptrInicio)
{
   int x;
	
	cola nuevo,anterior,actual;
	
	nuevo=(cola)malloc(sizeof(Cola));
	
	printf("\t\t\tIngrese el codigo del producto: ");
	scanf("%d",&nuevo->codigo);
	fflush(stdin);
	printf("\t\t\tIngrese una descripcion del producto: ");
	gets(nuevo->descripcion);
	fflush(stdin);
	printf("\t\t\tDigite el precio del producto: ");
	scanf("%f",&nuevo->precio);
	
	if(nuevo!=NULL)
	 {
		   if(*ptrInicio==NULL)//Verificamos si es el primer elemento
		   {
		   	 nuevo->sig=NULL;
		   	 *ptrInicio=nuevo;
		   	 actual=nuevo;
		   	 
		   }else
		     {
		       nuevo->sig=NULL;
		   
		       actual=*ptrInicio;
		    	
			   while(actual!=NULL && actual->sig!=NULL)
			   { 
			   	 actual=actual->sig;
		         	   	 
			   }
			   
			   	actual->sig=nuevo;	
		     	
			 }
		   	
	 } 
	
	system("cls");
}
