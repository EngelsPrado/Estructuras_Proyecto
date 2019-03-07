#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
