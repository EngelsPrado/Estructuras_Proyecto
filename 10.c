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


int menu();
void insertarProducto(cola *);
void mostrarProductos(cola);

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

void mostrarProductos(cola inicio)
{
	float mayor,menor;
	
	
	mayor=menor=inicio->precio;
	
	printf("\n\t\t\tLISTADO DE PRODUCTOS \n\n\n");
	
	printf("\nCodigo %10s %10s \n\n","Descripcion", "Precio");
	while(inicio!=NULL)
	{
		
	 printf("\n%d %10s %10.2f \n",inicio->codigo,inicio->descripcion,inicio->precio);
	 
	 if(menor>inicio->precio)
	  {
	  	menor=inicio->precio;
	  }else
	       if(mayor<inicio->precio)
	       {
	       	mayor=inicio->precio;
		   }
	 
	 inicio=inicio->sig;	
	}
	
	printf("\n\n\nEl precio menor es: %.2f ",menor);
	printf("\n\nEl precio mayor es : %.2f ",mayor);
	
}


void insertarProducto(cola *ptrInicio)
{
   int x;
	
	cola nuevo,anterior,actual;
	
	nuevo=(cola)malloc(sizeof(Cola));
	
	printf("\t\t\tIngrese el codigo del producto \n");
	scanf("%d",&nuevo->codigo);
	fflush(stdin);
	printf("\t\t\tIngrese una descripcion del producto \n");
	gets(nuevo->descripcion);
	fflush(stdin);
	printf("\t\t\tDigite el precio del producto \n");
	scanf("%f",&nuevo->precio);
	
	if(nuevo!=NULL)
	 {
		   if(*ptrInicio==NULL)
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
	
}
