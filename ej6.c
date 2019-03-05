#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int num;
  char user[20];
  char program[20];
  struct nodo *sig;
	
};


typedef struct nodo Cola;
typedef Cola *cola;


void pushCola(cola *);
void popCola(cola *);
void popColaImpresion(cola *);
void mostrarEstado(cola);
int menu();

int main(int argc, char *argv[]) {
	
	int opc;
	
	cola inicio=NULL;
	
	opc=menu();
	
	do
	{
		
		switch(opc)
		{
		   case 1:  pushCola(&inicio);
					break; 
		   
		   
		   case 2: popCola(&inicio);
		   	
		   	       break;
		   case 3: popColaImpresion(&inicio);
		   	       break;
		   	
		   case 4:  break;
		   	
		   	
		}
		mostrarEstado(inicio);
		
		opc=menu();
		
		
	}while(opc!=4);
	
	
	return 0;
}


int menu()
{
   int opc;
   
   do
   {
   	  printf("\n\n\n\t\t\t1.Enviar impresion \n");
   	  printf("\t\t\t2.Imprimir \n");
   	  printf("\t\t\t3.Eliminar impresion \n");
   	  printf("\t\t\t4.Salir\n");
   	  printf("\n\n\n\t\t\tOPCION ");
   	  scanf("%d",&opc);
   	
   }while(opc<1 || opc>4);
  	
  	return opc;
}

void mostrarEstado(cola inicio)
{
	
	cola actual;
	
	actual=inicio;
	
	
	while(actual!=NULL)
	{
		
		printf(" %s ",actual->user);
		actual=actual->sig;
		
		
	}
	
}

void pushCola(cola *ptrInicio)
{
	static int cont=0;
	
	cola nuevo,actual,previo;
	
	nuevo=(cola)malloc(sizeof(Cola));
	fflush(stdin);
    printf("\t\t\tIngrese el nombre de usuario \n");
    gets(nuevo->user);
    fflush(stdin);
    printf("\t\t\tIngrese el programa desde el cual se envia la impresion \n");
    gets(nuevo->program);
	nuevo->num=cont++;
	
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


void popColaImpresion(cola *inicio)
{
	int dato;
	
	cola temp,actual,anterior;
	
	printf("\n\t\t\tIngrese el numero que desea borrar \n");
	scanf("%d",&dato);
	
	if(dato==(*inicio)->num)
	{
		temp=*inicio;
		*inicio=(*inicio)->sig;
		free(temp);
	}else{
		anterior=*inicio;
		actual=(*inicio)->sig;
		
		
		while(actual!=NULL && actual->num!=dato)
		{
			anterior=actual;
			actual=actual->sig;
		}
	    
	     anterior->sig=NULL;
	     
	     while(actual!=NULL)
	     {
	     	temp=actual;
	     	actual=actual->sig;
	     	free(temp);
	     	
		 }
		
		
	}
}

void popCola(cola *inicio )
{
	
	cola temp,anterior,actual;
	
	
	if(*inicio!=NULL)
	{
	   temp=*inicio;
	   *inicio=(*inicio)->sig;	
		free(temp);
	}	
	
	
}

