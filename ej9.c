#include <stdio.h>
#include <stdlib.h>

struct nodo{

  int codigo;
  char descripcion[50];
  struct nodo *sig;
	
};


typedef struct nodo Pila;
typedef Pila *pila;

struct nodoLista{

   char nombre[50];
   int codigos[20];
   int cantidadNeveras;
  struct nodoLista *sig;
	
};


typedef struct nodoLista Lista;
typedef Lista *lista;

void crearNeveras(pila *);
void hacerPedido(pila *,lista *);
int menu();
void mostrarNeveras(pila);
void mostrarPedido(lista);

int main(int argc, char *argv[]) {
	
	pila inicio=NULL;
	lista cabeza=NULL;
	
	int opc;
	
	opc=menu();
	
	do
	{
		switch(opc)
		{
		 
		  case 1: crearNeveras(&inicio);
		          mostrarNeveras(inicio);
		          break;
		  case 2: hacerPedido(&inicio,&cabeza);	
			      mostrarPedido(cabeza);
			      break;
		}
		
		opc=menu();
		
	}while(opc!=3);
	
	
	return 0;
}

void mostrarNeveras(pila inicio)
{
	
	while(inicio!=NULL)
	{
		printf(" %d ",inicio->codigo);
		inicio=inicio->sig;
	}
	
}

void mostrarPedido(lista inicio)
{
	int index=0;

	
	while(inicio!=NULL)
	{
	   printf("\nTienda %s ",inicio->nombre);
	   printf("\nCodigo de neveras \n");
	   while(index<inicio->cantidadNeveras)
	   {
	   	 printf(" %d ",inicio->codigos[index++]);
	   }
	    index=0;
	  	inicio=inicio->sig;
	  	
	}
	
	
}

int menu()
{
	
	int opc;
	
	do
	{
		printf("\n\n\n\t\t\t1.Crear 5  neveras mas \n");
		printf("\t\t\t2.Recibir pedido de neveras \n");
		printf("\t\t\t3.Salir \n");
		printf("\n\n\nOPCION ");
		scanf("%d",&opc);
	}while(opc<1 || opc>3);
	
	
	return opc;
}

void crearNeveras(pila *ptrInicio)
{
	static int id=0;
	int x,cont=1;
	
	pila nuevo,actual,previo;
	
	
	
    while(cont<=5)
    {
    	nuevo=(pila)malloc(sizeof(Pila));
        nuevo->codigo=id++;
        fflush(stdin);
	    printf("\t\t\tIngrese una descripcion \n");
	    gets(nuevo->descripcion);
		
		if(nuevo!=NULL)
		{
		    	
		   if(*ptrInicio==NULL)
		   {
		   	  *ptrInicio=nuevo;
		       nuevo->sig=NULL;	  
		   	
		   }else
		       {
		       	 nuevo->sig=*ptrInicio;
		       	 *ptrInicio=nuevo;
		       	 
			   }
		   
		   	
		   	
		} 	  
    	cont++;
	}
	
}

void hacerPedido(pila *inicio,lista *cabeza)
{
	int cont=0,x;
	
	pila temp;
	
	lista nuevo,anterior,actual;
	
	nuevo=(lista)malloc(sizeof(Lista));
	
	printf("\n\t\t\tIngrese el numero de neveras \n");
	scanf("%d",&x);
	nuevo->cantidadNeveras=x;
	fflush(stdin);
	printf("\t\t\tIngrese el nombre de la tienda \n");
	gets(nuevo->nombre);
	
	while(cont<x )
	{
		if(*inicio!=NULL)
	   {
	   	
		   	if(nuevo!=NULL)
	        {
			   nuevo->codigos[cont]=(*inicio)->codigo;
			   
	        }
	   	
	    temp=*inicio;
	   *inicio=(*inicio)->sig;	
		free(temp);
	   }
	   
	   cont++;
	}
	
	if(*cabeza==NULL)
   {
   	  *cabeza=nuevo;
       nuevo->sig=NULL;	  
   	
   }else
       {
       	 nuevo->sig=*cabeza;
       	 *cabeza=nuevo;
       	 
	   }
	
}

