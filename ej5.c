#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//mostrar tamanios por lista

struct nodo{

  int item;
  struct nodo *sig;
	
};


typedef struct nodo Lista;
typedef Lista *lista1,*lista2,*lista3,*lista4,*lista5;


int menu();
void calcular(lista3 );
void pushLista1(lista1 *,int);
void pushLista2(lista2 *,int);
void pushLista3(lista3 *,int);
void pushLista4(lista4 *,int);
void pushLista5(lista5 *,int);
void mostrarNuevaLista(lista5 );
void formarLista(lista3,lista4,lista5 *);
void llenarListas(lista1 *,lista3 *,lista4 *);
void invertirLista(lista1 *,lista2 *);
void mostrar(lista1);
void mostrarListaInvertida(lista2);
int veririfcarRepetidos(lista5 *,int);
void moverNodo(lista3 *);
void reinsertarNodo(lista3 *,int);
void mostrarLista3(lista3);

int main(int argc, char *argv[]) {
	
	int num,cont=0,opc;
	
	lista1 inicio1=NULL;
	lista2 inicio2=NULL;
	lista3 inicio3=NULL;
	lista4 inicio4=NULL;
	lista5 inicio5=NULL;
	
	llenarListas(&inicio1,&inicio3,&inicio4);
	
	mostrar(inicio1);
	
	opc=menu();
	
	do
	{
		switch(opc)
		{
			case 1: invertirLista(&inicio1,&inicio2);
			        mostrarListaInvertida(inicio2);
				    break;
				
			case 2: formarLista(inicio3,inicio4,&inicio5);
			        mostrarNuevaLista(inicio5); 
				
				    break;
			case 3: calcular(inicio3);
			        break;
			case 4: moverNodo(&inicio3);
			        mostrarLista3(inicio3);
			        break; 
			
			case 5:	break;
			
		}
		
		opc=menu();
		
	}while(opc!=5);
	
	
	return 0;
}

void mostrarLista3(lista3 inicio)
{
  printf("\n\nLa lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}	
	
}

void moverNodo(lista3 *inicio)
{
	
	lista3 anterior,actual,temp;
	
	int dato;
	
	printf("\n\t\t\tIngrese el numero que desea borrar \n");
	scanf("%d",&dato);
	
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
		}
	}
	
	mostrarLista3(*inicio);
	reinsertarNodo(inicio,dato);
	
}
void reinsertarNodo(lista3 *inicio,int x)
{
	
	
	int nodo;
	
	lista3 nuevo,anterior,actual;
	
	nuevo=(lista3)malloc(sizeof(Lista));
	
	printf("\n\t\t\tIngrese el numero del nodo\n");
	scanf("%d",&nodo);	
	
	if(nuevo!=NULL)
	{
		
		nuevo->item=x;
	    actual=*inicio;	
		while(actual!=NULL && actual->item!=nodo)
		{
			anterior=actual;
			actual=actual->sig;
			
		}
		
		if(actual->sig==NULL)
		   printf("\n\t\t\tNo encontrado \n");
		 
		nuevo->sig=actual;
		anterior->sig=nuevo;   
		
	}
}


void calcular(lista3 inicio)
{
	int cont=0;
	
	printf("\n\nLa lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
	   cont++; 
	   inicio=inicio->sig;	
		
	}
	
	printf("\n\n\nEl tamanio de la lista es de %d ",cont);
}

void mostrarNuevaLista(lista5 inicio)
{
	
	printf("\n\nLa lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}

void formarLista(lista3 inicio3,lista4 inicio4,lista5 *inicio5)
{
	
	lista3 actual1;
	lista4 actual2;
	
	
	while(inicio3!=NULL)
	{
		actual1=inicio3;
		actual2=inicio4;
		
		printf("\nComparando %d con ",actual1->item);
		while(actual2!=NULL)
		{
			printf(" : %d ",actual2->item);
			
			if(actual1->item==actual2->item)
			{
				printf("\nComun\n"); 
				
				int band=veririfcarRepetidos(inicio5,actual1->item);
			    if(band==1)
				  goto here;  
				else	
				    pushLista5(inicio5,actual1->item);
			}
		
		 here:
		 actual2=actual2->sig;	
			
		}
		
		
		inicio3=inicio3->sig;
		
		
	}
	
	
}

int veririfcarRepetidos(lista5 *inicio,int x)
{
	
	lista5 actual;
	
	actual=*inicio;
	
	int num;
	
	while(actual!=NULL)
	{
		num=actual->item;
		printf("Buscando %d: %d ",x,num);
		
	    if(x==num)
	    {
	    	printf("\nrepetido \n"); 
	    	return 1;
	    	
		}
		
		    
	   actual=actual->sig;	    
	}
	
	return 0;
}


void llenarListas(lista1 *inicio1,lista3 *inicio3,lista4 *inicio4)
{
	int cont=0,num;
	
	srand(time(NULL));
	
	do
	{
	   num=1 + rand()%(11-1);
	   pushLista1(inicio1,num);
	   cont++;
	   	
	}while(cont<=5);
	
	cont=0;
	
	do
	{
	   num=1 + rand()%(11-1);
	   pushLista3(inicio3,num);
	   cont++;
	   	
	}while(cont<=5);
	
	cont=0;
	
	do
	{
	   num=1 + rand()%(11-1);
	   pushLista4(inicio4,num);
	   cont++;
	   	
	}while(cont<=5);
	
	
}

void invertirLista(lista1 *inicio1,lista2 *inicio2)
{
	
	lista1 temp,anterior,actual;
	
  while(*inicio1!=NULL)
	{
		actual=*inicio1;
		
		if(actual->sig==NULL)
		{
		 pushLista2(inicio2,actual->item);
		 temp=actual;
		 *inicio1=NULL; 
		  free(actual);	
		  return;
		}
		
		
		while(actual!=NULL && actual->sig!=NULL)
		{
			anterior=actual;
			actual=actual->sig;
			
		}
		pushLista2(inicio2,actual->item);
	    temp=actual;
	    anterior->sig=actual->sig;
		free(actual);
	
	}	
	
	
}

int menu()
{
	int opc;
	
	do
	{
	  printf("\n\n\n\t\t\t1.Invertir la lista 1 \n");
	  printf("\t\t\t2.Formar una lista que contenga los elementos comunes de otras dos \n");
	  printf("\t\t\t3.Calcular la longitud de la lista en cada momento\n");
	  printf("\t\t\t4. Mover un nodo j, n posiciones más adelante.\n");
	  printf("\t\t\t5.Salir \n");
	  printf("\n\n\n\t\t\tOPCION = ");
	  scanf("%d",&opc);	
		
		
	}while(opc<1 || opc>5);
	
	
	
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

void mostrarListaInvertida(lista2 inicio)
{
	printf("\n\nLa lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}

void pushLista2(lista2 *ptrInicio,int x)
{
	
	
	lista2 nuevo,actual,previo;
	
	nuevo=(lista1)malloc(sizeof(Lista));
	
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

void pushLista5(lista5 *ptrInicio,int x)
{
	
	
	lista5 nuevo,actual,previo;
	
	nuevo=(lista5)malloc(sizeof(Lista));
	
	printf("\nentra a pila5 %d \n",x);
	
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
	
	nuevo=(lista4)malloc(sizeof(Lista));
	
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
