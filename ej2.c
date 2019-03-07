#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct caja{

  int item;
  struct caja *sig;
	
};

typedef struct caja Cola;
typedef Cola *carrito,*colaFila1,*colaFila2,*colaCarrito;




void llenarCarritos(carrito *);
void pushCarrito(carrito *);
void pushFila1(colaFila1 *);
void pushFila2(colaFila2 *);
void popFila1(colaFila1 *);
void popFila2(colaFila2 *);
void popColaCarrito(colaCarrito *);
void removerCarrito(carrito *);
void esperaCarrito(colaCarrito *);
void estadoCarritos(carrito);
int filaMenosLlena(colaFila1 *,colaFila2 *);
int menu();
void realizarCompra(int,colaFila1 *,colaFila2 *,carrito *);
void verEstadoFilas(colaFila1,colaFila2);
void estadoColaCarritos(carrito);
void antesDeComprar(carrito *,colaCarrito *);

int main(int argc, char *argv[]) {
	
	int opc,band,num;
	
	srand(time(NULL));
	
	carrito inicio=NULL;
	colaFila1 inicio1=NULL;
	colaFila2 inicio2=NULL;
	colaCarrito inicio3=NULL;
	
	
	
	llenarCarritos(&inicio);//Llena la lista de carritos en un inicio
		
	
	do
	{
		system("cls");
		printf("\n\t\t\t------------------------------------------------\n");
		printf("\n\n\n\t\t\t\t\tBIENVENIDOS \n");
		printf("\n\t\t\t------------------------------------------------\n");
		
		opc=menu();
		
		switch(opc)
		{
			case 1:
				   system("cls");
				   antesDeComprar(&inicio,&inicio3);
				   printf("\t\t\t--------------------------------------------------\n");	
				   printf("\n\t\t\t-->Entrando al supermercado...");
				   estadoCarritos(inicio);
				   int fila=filaMenosLlena(&inicio1,&inicio2);	//Comprobamos la fila menos llena
				   printf("\n\t\t\t--------------------------------------------------\n");
			 
				   realizarCompra(fila,&inicio1,&inicio2,&inicio);
				   break;
			case 2: estadoColaCarritos(inicio3);
			        break;
			
			
			case 3: verEstadoFilas(inicio1,inicio2);
			        break;
			
		
		}
		
    	
	}while(opc!=4);
	
	
	return 0;
}
void verEstadoFilas(colaFila1 inicio1,colaFila2 inicio2)
{
	int cont1=0,cont2=0;
	
	system("cls");
	
	while(inicio1!=NULL)
	{
		cont1++;
		inicio1=inicio1->sig;
		
	}
	
	printf("\n\t\t\tLa cantidad de personas haciendo cola en la fila 1 son %d ",cont1);
	
	while(inicio2!=NULL)
	{
		cont2++;
		inicio2=inicio2->sig;
		
	}
	
	printf("\n\t\t\tLa cantidad de personas haciendo cola en la fila 2 son %d ",cont2);
	
   printf("\n\n\n");
   system("pause");
	
}

void estadoColaCarritos(colaCarrito inicio)
{
	int cont=0;
	
	while(inicio!=NULL)
	{
		cont++;
		inicio=inicio->sig;
		
	}
	
	printf("\n\t\t\tLa cantidad de personas esperando por un carrito son %d ",cont);
	
	printf("\n\n");
	system("pause");
	
}

void antesDeComprar(carrito *inicio,colaCarrito *inicio3)
{
	int band,num;
	
	band=verificarCarritos(inicio);//Verificamos si hay carritos disponibles
   
   	if(band==1)//Si no hay carritos disponibles procedemos a esperar que haya uno disponible
	{
	  do
	  {
	  	num=1+rand()%(4-1);
	  	
	  	if(band==1)//No hay carritos disponible aun y la cola de espera crece
	  	{
	  	  esperaCarrito(inicio3);//La cola de personas esperando por un carrito aumenta
		  	
		}else
		      {
		      	popColaCarrito(inicio3);//Cuando un carrito disponible procedemos a ocuparlo
		      	pushCarrito(inicio);
			  }
		      
	  	
	  }while(num!=1); 
   	
     }
}

void realizarCompra(int fila,colaFila1 *inicio1,colaFila2 *inicio2,carrito *inicio)
{
	int num;
	
	switch(fila)
		{
			case 1: num=1+rand()%(4-1); 
			
			        if(num==1)//El cajero esta atentiendo
			        {
			          printf("\n\t\t\tHaciendo Fila en el cajero \n");	
			          pushFila1(inicio1);//Cuando el cajero esta atendiendo, la cola de espera aumenta	
					}else//El cajero atendio
					     {
					     	printf("\n\t\t\tCompra realizada con exito \n");
					     	popFila1(inicio1);//Cuando hemos sido atendidos salimos de la cola de espera
			                pushCarrito(inicio);//Al finalizar la compra regresamos el carrito 
						  } 
				
				break;
			case 2: num=1+rand()%(4-1); 
			
			        if(num==1)//El cajero esta atentiendo
			        {
			          printf("\n\t\t\tHaciendo Fila en el cajero \n");	
			          pushFila2(inicio2);	
					}else//El cajero atendio
					     {
					     	printf("\n\t\t\tCompra realizada con exito \n");
					     	popFila1(inicio2);//Cuando hemos sido atendidos salimos de la cola de espera
			                pushCarrito(inicio);//Al finalizar la compra regresamos el carrito
						  } 
			
			     break;
		}
		
	system("pause");
}

int menu()
{
	int opc;
	
	
	do
	{
	  printf("\t\t\t1.Realizar una compra \n");
	  printf("\t\t\t2.Ver estado de la cola de espera por un carrito\n");
	  printf("\t\t\t3.Ver estado de las filas 1 y 2 de los cajeros \n");
	  printf("\t\t\t4.Salir\n");
	  printf("\n\n\n\t\tOPCION ");
	  scanf("%d",&opc);	
		
	}while(opc<1 || opc>4);
	return opc;
}

void estadoCarritos(carrito inicio)
{
     int cont=0;
	 	
	while(inicio!=NULL)
	{
	 cont++;
	 inicio=inicio->sig;  	
		
	}
	
	printf("\n\t\t\t-->Tomando un carrito, quedan %d Carritos disponibles \n",cont);
}

//Elimina un nodo de la cola de espera por un carrito
void popColaCarrito(colaCarrito *inicio)
{
	
	colaCarrito actual,anterior,temp;
	
	actual=*inicio;
	
	
    if(*inicio!=NULL)
	{
	   temp=*inicio;
	   *inicio=(*inicio)->sig;	
		free(temp);
	}
	
}

//Elimina un nodo al principio de la cola
void popFila2(colaFila2 *inicio)
{
	
	
	colaFila2 temp;

	
	if(*inicio!=NULL)
	{
	   temp=*inicio;
	   *inicio=(*inicio)->sig;	
		free(temp);
	}
}
//Elimina un nodo al principio de la cola
void popFila1(colaFila1 *inicio)
{
	
	
	colaFila1 temp;

   if(*inicio!=NULL)
	{
	   temp=*inicio;
	   *inicio=(*inicio)->sig;	
		free(temp);
	}
}


//Coloca nuevamente el carrito que fue ocupado
void pushCarrito(carrito *ptrInicio)
{
	    carrito nuevo;
	
  	    nuevo=(carrito)malloc(sizeof(Cola));
		
	
		if(nuevo!=NULL)
		{
		   nuevo->item=1;
		   
		    	
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


//Inserta un nodo al final de la cola en la fila 2 
void pushFila2(colaFila2 *ptrInicio)
{
    colaFila2 nuevo,actual,anterior;
	
	nuevo=(colaFila2)malloc(sizeof(Cola));
	
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

//Inserta un nodo al final de la cola en la fila 1
void pushFila1(colaFila1 *ptrInicio)
{
  colaFila1 nuevo,actual,anterior;
	
	nuevo=(colaFila1)malloc(sizeof(Cola));
	
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

void esperaCarrito(colaCarrito *ptrInicio)
{
  
	colaCarrito nuevo,actual,anterior;
	
	nuevo=(colaCarrito)malloc(sizeof(Cola));
	
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


void removerCarrito(carrito *inicio)
{
    carrito temp;
	
	if(*inicio!=NULL)
	{
	   temp=*inicio;
	   *inicio=(*inicio)->sig;	
		free(temp);
	}	
	
	
}


void llenarCarritos(carrito *ptrInicio)
{
	int cont=1;
	
	
	
	
	while(cont<=20)
	{
		carrito nuevo;
		nuevo=(carrito)malloc(sizeof(Cola));
		
	
		if(nuevo!=NULL)
		{
		   nuevo->item=1;
		   
		    	
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

int verificarCarritos(carrito *inicio1)
{
	
	if(*inicio1==NULL)
	 {
	   printf("\n\t\t\tNo hay carritos disponibles,esperando por uno \n");
	   return 1;
	 }else
	      {
			removerCarrito(inicio1);
			return 0;
		  }  
	
	
}

int filaMenosLlena(colaFila1 *inicio1,colaFila2 *inicio2)
{
	int cont1=0,cont2=0;
	
	while(*inicio1!=NULL)
	{
		cont1++;
	   *inicio1=(*inicio1)->sig;	
		
	}
	
	while(*inicio2!=NULL)
	{
		cont2++;
	   *inicio2=(*inicio2)->sig;	
		
	}
	
	if(cont1<=cont2)
	   {
	   	printf("\n\t\t\t-->La fila menos llena es la 1 \n");
	   	return 1;
	   }
	else
	    {
	      printf("\n\t\t\t-->La fila menos llena es la 2 \n");
		  return 2;	
		}   
	
}


