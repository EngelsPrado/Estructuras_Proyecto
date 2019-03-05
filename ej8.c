#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{

  int item;
  struct nodo *sig;
	
};
      

typedef struct nodo Cola;
typedef Cola *cola;

void pushCola(cola *);
void pop(cola *);
void mostrarCola(cola);
int menu();

int main(int argc, char *argv[]) {
	
	cola inicio=NULL;
	
	int opc,acum=0;
	
	opc=menu();
	
	do
	{
		switch(opc)
		{
			
		  case 1: pushCola(&inicio); 
		          break;
		  
		  case 2: pop(&inicio);
		          break;
		  
	
		}
		
	mostrarCola(inicio);	
	 opc=menu();
	 	
	}while(opc!=3);
	
	
	return 0;
}

int menu()
{
	int opc;
	
	
	do{
		printf("\n\n\n\t\t\t1.Sentar cliente \n");
	    printf("\t\t\t2.Retirar un cliente \n");
	    printf("\t\t\t3.Salir \n");
		printf("\n\n\n\t\t\tOPCION ");
	scanf("%d",&opc);
		
	}while(opc<1 || opc>3);
	
	
	return opc;
}

void mostrarCola(cola inicio)
{
	int cont=1, acum=0;
	
	while(inicio!=NULL)
	{
	   printf(" %d ",inicio->item);
	   acum+=cont++;
	   inicio=inicio->sig;	
		
	}
	
	printf("\n\t\t\tEl total a pagar hasta el momento es: %d ",acum);
}

int dimensionCola(cola inicio)
{
   int cont=0;
	
  while(inicio!=NULL)
  {
  	++cont;
  	inicio=inicio->sig;
  	
  }	

   return cont;
}

void pop(cola *inicio)
{
	
	cola anterior,actual,temp;
	
	int dato,tam;
	
	tam=dimensionCola(*inicio);
	
    dato=1+rand()%(tam+1 - 1);

	
	if(dato==(*inicio)->item)
	{
		temp=*inicio;
		*inicio=(*inicio)->sig;
		free(temp);
	}else{
		anterior=*inicio;
		actual=(*inicio)->sig;
		
		while(actual!=NULL && actual->item!=dato)
		{
			anterior=actual;
			actual=actual->sig;
		}
		
		if(actual!=NULL)
		{
			temp=actual;
			anterior->sig=actual->sig;
			free(temp);
		}else
		     printf("\nNo se encontro el asiento \n");
	}
	
}

void pushCola(cola *ptrInicio)
{
	static int cont=1;
	
	cola nuevo,actual,previo;
	
	nuevo=(cola)malloc(sizeof(Cola));

	
    nuevo->item=cont++;
	
		
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
}
