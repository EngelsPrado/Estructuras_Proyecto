#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{

  int item;
  struct nodo *sig;
	
};


typedef struct nodo Pila;
typedef Pila *pila1,*pila2;


int menu();
void push(pila1 *,int);
void pop(pila1 *,pila2 *);
void pushPila(pila2 *,int );
void mostrar(pila1);
void mostrar2(pila2);
int main(int argc, char *argv[]) {
	
	pila1 inicio1=NULL;
	pila2 inicio2=NULL;
	
	int op,x;
	
	op=menu();
	
	
	do
	{
		
		switch(op)
		{
			case 1:printf("\n\t\t\tIngrese un numero \n");
	               scanf("%d",&x);
			       push(&inicio1,x);
				
				   break;
			case 2:	pop(&inicio1,&inicio2);
			
			       break;
		}
		
		mostrar(inicio1);
		printf("\n\n");
		mostrar(inicio2);
		op=menu();
		
	}while(op!=3);
	
	
	mostrar(inicio1);
	
	
	
	
	
	
	return 0;
}

void mostrar2(pila2 inicio)
{
	printf("\n\nLa pila 2 es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}


void mostrar(pila1 inicio)
{
	printf("\n\nLa lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}

int menu()
{
	
	int opc;
	
	do
	{
	  printf("\n\n\n\t\t\t1.Apilar un elemento \n");
	  printf("\t\t\t2.Sacar un elemento \n");
	  printf("\t\t\t3.Salir\n");
	  printf("\n\n\n\t\t\tOPCION ");
	  scanf("%d",&opc);	
		
	}while(opc<1 || opc>3);
	
	
	
	
}

void popPila2(pila1 *inicio1,pila2 *inicio2 )
{
	
	pila2 temp,anterior,actual;
	
	
	
	
	while(*inicio2!=NULL)
	{
		actual=*inicio2;
		
		if(actual->sig==NULL)
		{
		 push(inicio1,actual->item);
		 temp=actual;
		 *inicio2=NULL; 
		  free(actual);	
		  return;
		}
		
		
		while(actual!=NULL && actual->sig!=NULL)
		{
			anterior=actual;
			actual=actual->sig;
			
		}
		push(inicio1,actual->item);
	    temp=actual;
	    anterior->sig=actual->sig;
		free(actual);
	
	}
	
	
}


void pop(pila1 *inicio1,pila2 *inicio2)
{
	
	pila1 temp,actual;
	
	int num;
	
	printf("\n\n\t\t\tIngrese numero que desea retirar \n");
	scanf("%d",&num);
	
	actual=*inicio1;
		
	
	while(*inicio1!=NULL)
	{
		
	
		if(num==(*inicio1)->item)
		{
		   temp=*inicio1;
		   *inicio1=(*inicio1)->sig;	
			free(temp);
			popPila2(inicio1,inicio2);
			return;
		}else
		   {
		   pushPila(inicio2,(*inicio1)->item);
		   temp=*inicio1;
		   *inicio1=(*inicio1)->sig;	
			free(temp);	
			}	
		   
	    
	}
	
	

}

void pushPila(pila2 *ptrInicio,int num)
{
	
	pila2 nuevo,actual,previo;
	
	nuevo=(pila2)malloc(sizeof(Pila));
	printf("\n\n\nEntra pila 2 %d \n",num);
	
	if(nuevo!=NULL)
	{
	   nuevo->item=num;
	   
	    	
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

void push(pila1 *ptrInicio,int x)
{
	
	
	pila1 nuevo,actual,previo;
	
	nuevo=(pila1)malloc(sizeof(Pila));
	
	printf("\nentra a pila1 %d \n",x);
	
	if(nuevo!=NULL)
	{
	   nuevo->item=x;
	   
	    	
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
