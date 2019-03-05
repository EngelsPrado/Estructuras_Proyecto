#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{

  int item;
  struct nodo *sig;
	
};


typedef struct nodo Lista;
typedef Lista *lista1,*lista2;


int comparar(lista1,lista2);
void insertarLista1(lista1*);
void insertarLista2(lista2*);


int main(int argc, char *argv[]) {
	
	lista1 inicio1=NULL;
	lista2 inicio2=NULL;
	
	int opc,band;
	
	printf("1.Pila1 \n");
	printf("2.Pila2 \n");
	scanf("%d",&opc);
	
	do
	{
		
		switch(opc)
		{
		  case 1: insertarLista1(&inicio1);  
		          break;	
		 
		  case 2: insertarLista2(&inicio2);
		           break;
				   
		  case 3: band=comparar(inicio1,inicio2);
		         
				  if(band==1)
				     printf("\nLas listas son iguaes \n");  
		           else
				        printf("las listas no son iguales \n"); 
		           break;		   	
			
		}
		printf("1.Pila1 \n");
	printf("2.Pila2 \n");
	printf("\n3.comparar \n");
	scanf("%d",&opc);
		
	}while(opc!=4);
	
	
	
	
	return 0;
}


int comparar(lista1 inicio1,lista2 inicio2)
{
	
	lista1 actual1;
	lista2 actual2;
	
	actual1=inicio1;
	actual2=inicio2;
	

     if(actual1!=NULL)
     {
     	if(actual1->item!=actual2->item)
     	   return 0;
     	else
		     comparar(actual1->sig,actual2->sig);   
     	
	 }else
	      return 1;
	
	
}

void insertarLista1(lista1 *ptrInicio)
{
   int x;
	
	lista1 nuevo,anterior,actual;
	
	nuevo=(lista1)malloc(sizeof(Lista));
	
	printf("\n\t\t\tIngrese un numero \n");
	scanf("%d",&x);
	
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
void insertarLista2(lista2 *ptrInicio)
{
   int x;
	
	lista2 nuevo,anterior,actual;
	
	nuevo=(lista2)malloc(sizeof(Lista));
	
	printf("\n\t\t\tIngrese un numero \n");
	scanf("%d",&x);
	
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
