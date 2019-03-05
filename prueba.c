#include <stdio.h>
#include <stdlib.h>

struct nodo{

  int item;
  struct nodo *sig;
	
};


typedef struct nodo Lista;
typedef Lista *lista;

void insertarFinal(lista *);
void mostrar(lista);

int main(int argc, char *argv[]) {
	
	lista lista1,lista2;
	
	lista1=lista2=NULL;
	
	
	int cont=0;
	
	do
	{
		
	 insertarFinal(&lista1);	
		
	}while(cont<=5);
	
	mostrar(lista1);
	
	cont=0;
	
	do
	{
		
	 insertarFinal(&lista2);	
		
	}while(cont<=5);
	
	mostrar(lista2);
	return 0;
}
void mostrar(lista inicio)
{
	printf("\nLa lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}

void insertarFinal(lista *ptrInicio)
{
  
	
	lista nuevo,actual,anterior;
	
	nuevo=(lista)malloc(sizeof(Lista));
	

	nuevo->item=1;
	
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
