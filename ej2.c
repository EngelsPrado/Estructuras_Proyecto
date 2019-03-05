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
void popFila1(carrito *);
void popFila2(carrito *);
void popColaCarrito(colaCarrito *);
void removerCarrito(carrito *);
void insertarFinal(colaCarrito *);
int filaMenosLlena(colaFila1 *,colaFila2 *);

int main(int argc, char *argv[]) {
	
	int opc,band,num;
	
	srand(time(NULL));
	
	carrito inicio=NULL;
	colaFila1 inicio1=NULL;
	colaFila2 inicio2=NULL;
	colaCarrito inicio3=NULL;
	
	printf("\n\n\n\t\t\tBIENVENIDO \n");
	
	llenarCarritos(&inicio);
		
	
	do
	{
		band=verificarCarritos(&inicio,&inicio3);
   
   
	   	if(band==1)
		{
		  do
		  {
		  	num=1+rand()%(4-1);
		  	
		  	if(band==1)//No hay carritos disponible aun y la cola de espera crece
		  	{
		  	  insertarFinal(&inicio3);
			  	
			}else
			      popColaCarrito(&inicio3);
		  	
		  }while(num!=1); 
	   	
	  }
	   
	   int fila=filaMenosLlena(&inicio1,&inicio2);	
		
	   printf("\n\n\n\t\t\tRealizando compra \n");
	    	
		switch(fila)
		{
			case 1: num=1+rand()%(4-1); 
			
			        if(num==1)//El cajero esta atentiendo
			        {
			          printf("\n\t\t\tHaciendo Fila en el cajero \n");	
			          pushFila1(&inicio1);	
					}else//El cajero atendio
					      popFila1(&inicio1);
			
			        pushCarrito(&inicio);
				
				break;
			case 2: num=1+rand()%(4-1); 
			
			        if(num==1)//El cajero esta atentiendo
			        {
			          pushFila2(&inicio2);	
					}else//El cajero atendio
					      popFila1(&inicio2);
					      
			        pushCarrito(&inicio);
			
			     break;
		}
		
	printf("\n\t\t\tPresione -1 para salir \n");
	scanf("%d",&opc);
		
	}while(opc!=-1);
	
	
	return 0;
}

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

void popFila2(carrito *inicio)
{
	
	
	carrito temp,anterior,actual;
	
	actual=*inicio;
	
	
	if(actual!=NULL)
	{
		//Validar si es el primero
		
		
		while(actual!=NULL && actual->sig!=NULL)
		{
			anterior=actual;
			actual=actual->sig;
			
		}
		
	    temp=actual;
	    anterior->sig=actual->sig;
		free(actual);
	}
}

void popFila1(carrito *inicio)
{
	
	
	carrito temp,anterior,actual;
	
	actual=*inicio;
	
	
	if(actual!=NULL)
	{
		//Validar si es el primero
		
		
		while(actual!=NULL && actual->sig!=NULL)
		{
			anterior=actual;
			actual=actual->sig;
			
		}
		
	    temp=actual;
	    anterior->sig=actual->sig;
		free(actual);
	}
}

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

void insertarFinal(colaCarrito *ptrInicio)
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
	
	
	
	
	while(cont<=3)
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
	        printf("\n\t\t\tSacando un carrito \n");
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
	   	printf("\n\t\t\tLa fila menos llena es la 1 \n");
	   	return 1;
	   }
	else
	    {
	      printf("\n\t\t\tLa fila menos llena es la 2 \n");
		  return 2;	
		}   
	
}


