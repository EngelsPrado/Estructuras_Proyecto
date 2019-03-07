#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{

  int item;
  struct nodo *sig;
	
};


typedef struct nodo Lista;
typedef Lista *lista1,*lista2;


int comparar(lista1,lista2);//Compara ambas listas
void insertarLista1(lista1*);//Inserta valores en la lista1
void insertarLista2(lista2*);//Inserta valores en la lista2
void mostrarLista1(lista1);//Muestra los elementos de la lista 1
void mostrarLista2(lista2);//Muestra los elementos de la lista 2

int main(int argc, char *argv[]) {
	
	lista1 inicio1=NULL;
	lista2 inicio2=NULL;
	
	int opc,band;
	

	opc=menu();
	
	do
	{
		
		switch(opc)
		{
		  case 1: insertarLista1(&inicio1);
		           mostrarLista1(inicio1);  
		          break;	
		 
		  case 2: insertarLista2(&inicio2);
		          mostrarLista2(inicio2); 
		           break;
				   
		  case 3: band=comparar(inicio1,inicio2);
		         
				  if(band==1)
				     printf("\n\t\t\tLas listas son iguaes \n");  
		           else
				        printf("\n\t\t\tlas listas no son iguales \n"); 
		           break;		   	
			
		}
		  printf("\n\n");
	      system("pause");
          system("cls");
   
		opc=menu();
	}while(opc!=4);
	
	
	
	
	return 0;
}

int menu()
{
  int opc;
  
  printf("\n\n\n\t\t\t\t M  E  N  U \n\n\n");
  do
  {
  	printf("\n\n\n\t\t\t1.Insertar numeros en la lista 1 \n");
  	printf("\t\t\t2.Insertar numeros en la lista 2 \n");
  	printf("\t\t\t3.Comparar las listas 1 y 2 \n");
  	printf("\t\t\t4.Salir \n\n\n");
  	printf("\t\t\tOPCION: ");
  	scanf("%d",&opc);
  	
  }while(opc<1 || opc>4);
   return opc;
   
 
}


int comparar(lista1 inicio1,lista2 inicio2)
{
	
	lista1 actual1;
	lista2 actual2;
	
	actual1=inicio1;
	actual2=inicio2;
	

     if(actual1!=NULL)//La funcion se detendra hasta que en la lista ya no hayan elementos
     {
     	if(actual1->item!=actual2->item)//Y si algun elemento no es igual al otro, significa que las listas no son iguales
     	   return 0;
     	else //Mientras las listas sean iguales seguimos enviando datos de forma recursiva para compararlos entre si
		     comparar(actual1->sig,actual2->sig);   
     	
	 }else//Llegados a este punto significa que todos los elementos eran iguales
	      return 1;
	
	
}

void insertarLista1(lista1 *ptrInicio)
{
   int x,cont=1,num;
	
	lista1 nuevo,anterior,actual;
	srand(time(NULL));

	
	printf("\n\t\t\tIngrese la cantidad de numeros que desea insertar \n");
	scanf("%d",&x);
	
	while(cont<=x)
	{
	   num=1+rand()%(11-1);
	    nuevo=(lista1)malloc(sizeof(Lista)); 	
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
	
	  cont++;
	}	

	
}

void mostrarLista1(lista1 inicio)
{
	
	printf("\t\t\tMostrando elementos de la lista 1 \n\n");
	while(inicio!=NULL)
	{
		printf(" %d ",inicio->item);
		inicio=inicio->sig;
		
	}
	
}

void mostrarLista2(lista2 inicio)
{
	printf("\t\t\tMostrando elementos de la lista 2 \n\n");
	while(inicio!=NULL)
	{
		printf(" %d ",inicio->item);
		inicio=inicio->sig;
		
	}
	
	
}

void insertarLista2(lista2 *ptrInicio)
{
   int x,cont=1,num;
	
	lista2 nuevo,anterior,actual;
	srand(time(NULL));

	
	printf("\n\t\t\tIngrese la cantidad de numeros que desea insertar a la lista \n");
	scanf("%d",&x);
	
	while(cont<=x)
	{
		num=1+rand()%(11-1);
		nuevo=(lista2)malloc(sizeof(Lista));
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
		cont++;
	}
	
}
