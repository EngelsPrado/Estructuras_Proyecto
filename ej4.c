#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct nodo{

  int item;
  struct nodo *sig;
	
};


typedef struct nodo Lista;
typedef Lista *lista1,*lista2,*lista3,*lista4;

void mostrar(lista1);
void pushLista1(lista1*,int);
void pushLista2(lista2*,int);
void pushLista3(lista3*,int);
void pushLista4(lista4*,int);
void rellenarListas(lista1,lista2 *,lista3 *,lista4 *);

int main(int argc, char *argv[]) {
	
	int num,cont=0;
	
	lista1 inicio1=NULL;
	lista2 inicio2=NULL;
	lista3 inicio3=NULL;
	lista4 inicio4=NULL;
	
	srand(time(NULL));
	
	do
	{
	   num=-10 + rand()%(31- (-10));
	   pushLista1(&inicio1,num);
	   cont++;
	   	
	}while(cont<=10);
	
	mostrar(inicio1);
	
	
	rellenarListas(inicio1,&inicio2,&inicio3,&inicio4);
	
	return 0;
}

void mostrar(lista1 inicio)
{
	printf("\n\nLa lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}

void rellenarListas(lista1 inicio,lista2 *inicio2,lista3 *inicio3,lista4 *inicio4)
{

	
	while(inicio!=NULL)
	{
		
	   if(inicio->item<0)	
		 pushLista2(inicio2,inicio->item);
	   else
	       if(inicio->item>10)
		      pushLista3(inicio3,inicio->item);
		   else
		        if(inicio->item>=0 && inicio->item<=9)
				   pushLista4(inicio4,inicio->item);
				   
				   
	  inicio=inicio->sig;			   	  	 
	}
	
}

void pushLista1(lista1 *ptrInicio,int x)
{
	
	
	lista1 nuevo,actual,previo;
	
	nuevo=(lista1)malloc(sizeof(Lista));
	
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

void pushLista2(lista2 *ptrInicio,int x)
{
	
	
	lista2 nuevo,actual,previo;
	
	nuevo=(lista2)malloc(sizeof(Lista));
	
	printf("\nentra a pila2 %d \n",x);
	
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

void pushLista3(lista3 *ptrInicio,int x)
{
	
	
	lista3 nuevo,actual,previo;
	
	nuevo=(lista3)malloc(sizeof(Lista));
	
	printf("\nentra a pila3 %d \n",x);
	
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

void pushLista4(lista4 *ptrInicio,int x)
{
	
	
	lista4 nuevo,actual,previo;
	
	nuevo=(lista1)malloc(sizeof(Lista));
	
	printf("\nentra a pila4 %d \n",x);
	
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
