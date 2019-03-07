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


int menu();//Muestra un menu de opciones
void calcular(lista3 );//Calcula la dimension de la lista


//Funciones para insertar elementos en una lista

void pushLista1(lista1 *,int);
void pushLista2(lista2 *,int);
void pushLista3(lista3 *,int);
void pushLista4(lista4 *,int);
void pushLista5(lista5 *,int);
//////////////////////////////////////////////////


//Funciones de manipulacion de listas
void formarLista(lista3,lista4,lista5 *);
void llenarListas(lista1 *,lista3 *,lista4 *);
void invertirLista(lista1 *,lista2 *);
int veririfcarRepetidos(lista5 *,int);
void moverNodo(lista3 *);
void reinsertarNodo(lista3 *,int);
////////////////////////////////////////////////

//Funciones para mostrar elementos de la lista
void mostrarNuevaLista(lista5 );
void mostrar(lista1);
void mostrarListaInvertida(lista2);
void mostrarLista3(lista3);
void mostrarLista4(lista4);
///////////////////////////////////////////////
int main(int argc, char *argv[]) {
	
	int num,cont=0,opc;
	
	lista1 inicio1=NULL;
	lista2 inicio2=NULL;
	lista3 inicio3=NULL;
	lista4 inicio4=NULL;
	lista5 inicio5=NULL;
	
	llenarListas(&inicio1,&inicio3,&inicio4);
	
//	mostrar(inicio1);
	
	opc=menu();
	
	do
	{
		switch(opc)
		{
			case 1: printf("\n\n\t\t\tMostrando lista antes de ser invertida \n\n\n");
			        mostrar(inicio1);
			        printf("\n\n\t\t\tMostrando lista invertida \n\n");
			        invertirLista(&inicio1,&inicio2);
			        mostrarListaInvertida(inicio2);
				    break;
				
			case 2: printf("\n\t\t\tMostrando listas a comparar \n");
			        mostrarLista3(inicio3);
			        printf("\n\n");
			        mostrarLista4(inicio4);
			        formarLista(inicio3,inicio4,&inicio5);
			        printf("\n\n\n\t\t\tNueva lista \n");
			        mostrarNuevaLista(inicio5);
					printf("\n\n"); 
				    system("pause");
	                system("cls");
				    break;
			case 3: mostrarLista3(inicio3);
			        calcular(inicio3);
			        printf("\n\n");
			        system("pause");
	                system("cls");
			        break;
			case 4: mostrarLista3(inicio3);
			        moverNodo(&inicio3);
			        mostrarLista3(inicio3);
			        system("pause");
	                system("cls");
			        break; 
			
			
		}
		
		opc=menu();
		
	}while(opc!=5);
	
	
	return 0;
}


void mostrarLista3(lista3 inicio)
{
 
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}

void mostrarLista4(lista4 inicio)
{
 
	
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
	
	printf("\n\t\t\tIngrese el numero que desea borrar ");
	scanf("%d",&dato);
	
	if(dato==(*inicio)->item)//Verificamos si el nodo es el primero
	{
		temp=*inicio;
		*inicio=(*inicio)->sig;
		free(temp);
	}else{
		anterior=*inicio;
		actual=(*inicio)->sig;
		
		while(actual!=NULL && actual->item!=dato)//Hasta encontrarlo
		{
			anterior=actual;
			actual=actual->sig;
		}
		
		if(actual!=NULL)//Procedemos a la eliminacion
		{
			temp=actual;
			anterior->sig=actual->sig;
			free(temp);
		}
	}
	
	reinsertarNodo(inicio,dato);//Enviamos el dato para su posterior reubicacion dentro de la lista
	
}
void reinsertarNodo(lista3 *inicio,int x)
{
	
	
	int nodo;
	
	lista3 nuevo,anterior,actual;
	
	nuevo=(lista3)malloc(sizeof(Lista));
	
	printf("\n\t\t\tIngrese el numero para reinsertarlo: ");//Pedimos en donde ubicaremos el nodo que fue eliminado antes
	scanf("%d",&nodo);	
	
	if(nuevo!=NULL)
	{
		nuevo->item=x;
		
		if((*inicio)->item==nodo)//Verificamos si la reubicacion esta en el primero elemento
	    {
	   	  nuevo->sig=*inicio;
		  *inicio=nuevo;	   
	    }else
	    {// de lo contrario hacemos la insercion en cualquier nodo
	    	anterior=*inicio;
		    actual=(*inicio)->sig;	
			while(actual!=NULL && actual->item!=nodo)//
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
}


void calcular(lista3 inicio)
{
	int cont=0;
	
	
	while(inicio!=NULL)
	{
	   cont++; 
	   inicio=inicio->sig;	
		
	}
	
	printf("\n\n\nEl tamanio de la lista es de %d ",cont);
}

void mostrarNuevaLista(lista5 inicio)
{
	
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
	
	
	//La intencion es comparar cada elemento de la lista3 con todos los elementos de la lista4
	//Insertar los numeros iguales de cada lista en una nueva lista, sin que estos se repitan
	
	while(inicio3!=NULL)//Iniciamos con la lista3
	{
		actual1=inicio3;
		actual2=inicio4;
	
		while(actual2!=NULL)//Comparamos con los datos de la lista4
		{
		
			if(actual1->item==actual2->item)//Comparamos dato con dato de cada lista
			{
			
				int band=veririfcarRepetidos(inicio5,actual1->item);//Verificamos si en la nueva lista ya se encuentra un numero repetido
			    if(band==1)//Si hay un repetido, avanzamos al siguiente dato
				  goto here;  
				else//De lo contrario lo insertamos en la nueva lista	
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
	
	    if(x==num)//Si el numero es igual a uno de los que ya se encuentran en la lista nueva,entonces evitamos insertarlo
	    {
	    	return 1;
	    	
		}
			    
	   actual=actual->sig;	    
	}
	
	return 0;
}

//Llenamos las listas con numeros aleatorios
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
	
  //Procedemos a sacar los elementos de la lista1 por el final,y enviar cada datos a una nueva lista que se insertara por el final	
	
  while(*inicio1!=NULL)
	{
		actual=*inicio1;
		
		if(actual->sig==NULL)//Si es el ultimo elemento de la lista
		{
		 pushLista2(inicio2,actual->item);//Enviamos el dato
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
		pushLista2(inicio2,actual->item);//Enviamos el ultimo elemento de la lista
	    temp=actual;
	    anterior->sig=actual->sig;
		free(actual);
	
	}	
	
	
}

int menu()
{
	int opc;
	printf("\n\n\n\t\t\t\t\t\t M  E  N  U \n\n\n");
	do
	{
	  printf("\n\n\n\t\t\t1.Invertir la lista 1 \n\n");
	  printf("\t\t\t2.Formar una lista que contenga los elementos comunes de otras dos \n\n");
	  printf("\t\t\t3.Calcular la longitud de la lista en cada momento\n\n");
	  printf("\t\t\t4. Mover un nodo j, n posiciones más adelante.\n\n");
	  printf("\t\t\t5.Salir \n\n");
	  printf("\n\n\n\t\t\tOPCION = ");
	  scanf("%d",&opc);	
		
		
	}while(opc<1 || opc>5);
	
	return opc;
	
	
}

void mostrar(lista1 inicio)
{	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}

void mostrarListaInvertida(lista2 inicio)
{
	
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	
}

void pushLista2(lista2 *ptrInicio,int x)
{
	
	
	lista2 nuevo,actual,previo;
	
	nuevo=(lista2)malloc(sizeof(Lista));
	
	
	//Insertamos los elementos por el ultimo elemento
	if(nuevo!=NULL)
	{
		nuevo->item=x;
	   if(*ptrInicio==NULL)//Veirificamos si es el primero elemento
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

void pushLista5(lista5 *ptrInicio,int x)
{
	
	
	lista5 nuevo,actual,previo;
	
	nuevo=(lista5)malloc(sizeof(Lista));
	

	
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
