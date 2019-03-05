#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{

  int codigo;
  float precio;
  struct nodo *sig;
	
};


typedef struct nodo Lista;
typedef Lista *lista;

int menu();
void insertarFinal(lista *,float *);
void mostrarXrango(lista );
void mostrarXprecio(lista );
void mostrarXcodigo(lista );
void eliminarXrango(lista *);
void eliminarLista(lista *);

int main(int argc, char *argv[]) {
	
	int opc;
	float sumaPrecios=0;
	
	lista inicio=NULL;
	
	opc=menu();
	
	do
	{
		switch(opc)
		{
			case 1: insertarFinal(&inicio,&sumaPrecios);
			        break;
			
			case 2: mostrarXcodigo(inicio);
			        break;
			        
			case 3: printf("\n\t\t\tLa suma de todos los precios es %.2f \n",sumaPrecios);
			        break;
					
					
			case 4: mostrarXprecio(inicio);
			        break;		 
					
			case 5: eliminarXrango(&inicio);
			        break;
			        
			case 6: eliminarLista(&inicio);
			        break;        
							       
		}
	  mostrarXrango(inicio);	
	  opc=menu();
	  
	  	
	}while(opc!=6);
	
	
	
	
	return 0;
}
void eliminarLista(lista *inicio)
{
	
	lista temp,actual;
	
	actual=*inicio;
	
	printf("\n\t\t\tEliminando elementos de la lista antes de salir...\n");
	
    while(actual!=NULL)
	{
		if(actual!=NULL)
		{
		   temp=actual;
		   actual=actual->sig;	
			free(temp);
		}
		
	}
}

int elementosLista(lista *inicio)
{
	
	int cont=0;
	
	lista actual;
	
	actual=*inicio;
	
	while(actual!=NULL)
	{
		
	   cont++;
	   actual=actual->sig;	
		
	}
	
	return cont;
}

void eliminarXrango(lista *inicio)
{
	int codigoInicio,codigoFinal;
	
	lista actual,anterior,temp;
	
	printf("\n\t\t\tIngrese el coodigo de inicio \n");
	scanf("%d",&codigoInicio);
	printf("\n\t\t\tIngrese el codigo final \n");
	scanf("%d",&codigoFinal);
	
	actual=*inicio;
	anterior=actual; 
	
	if(elementosLista(inicio)<(codigoFinal-codigoInicio))
	  {
	  	printf("\n\t\t\tCodigos fuera de rango \n");
	  	return;
	  }
	
	while(actual!=NULL) 
	{
		
		//validar si es el primero
		
		
		if(actual->codigo>=codigoInicio && actual->codigo<=codigoFinal)
		{
		  	
		  temp=actual;
		  anterior->sig=actual->sig;
		  actual=anterior;
		  free(temp);
		  	
		} 
		
	  anterior=actual; 	
	  actual=actual->sig;	
		
	}
	
	
}

void mostrarXprecio(lista inicio)
{
	int precio;
	
	printf("\n\t\t\tIngrese el precio del libro \n");
	scanf("%d",&precio);
	
	while(inicio!=NULL)
	{
		
	   if(precio<=inicio->precio)
	      printf("\n\t\t\tLibro Encontrado \n");
	      
	    else
		     printf("\n\t\t\tLibro no encontrado \n");
			   
	   inicio=inicio->sig;	
		
	}
	
}


void mostrarXcodigo(lista inicio)
{
	int codigo;
	
	printf("\n\t\t\tIngrese el codig del libro \n");
	scanf("%d",&codigo);
	
	while(inicio!=NULL)
	{
		
	   if(codigo==inicio->codigo)
	      {
	      	printf("\n\t\t\tLibro Encontrado \n");
	      break; 
	      
		  }
	    else
		     printf("\n\t\t\tLibro no encontrado \n");
			   
	   inicio=inicio->sig;	
		
	}
	
}

void mostrarXrango(lista inicio)
{
	printf("\nLa lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->codigo);
	   inicio=inicio->sig;	
		
	}
	
}

void insertarFinal(lista *ptrInicio,float *sumaPrecios)
{
   int codigo;
   float precio;
	
	lista nuevo,actual,anterior;
	
	nuevo=(lista)malloc(sizeof(Lista));
	
	printf("\n\t\t\tIngrese el codigo del libro \n");
	scanf("%d",&nuevo->codigo);
	printf("\t\t\tIngrese el precio del libro \n");
	scanf("%f",&nuevo->precio);
	*sumaPrecios+=nuevo->precio;
	
	
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


int menu()
{
	int opc;
	
	do
	{
		printf("\n\n\n\t\t\t1.Agregar un nuevo libro al final de la lista \n");
		printf("\t\t\t2.Buscar un libro por el codigo \n");
		printf("\t\t\t3.Mostrar la suma de todos los precios \n");
		printf("\t\t\t4.Mostrar el listado de libros que sean menores a un precio ingresado\n");
		printf("\t\t\t5.Eliminar los libros que esten en un rango de codigo(codigo inicio y codigo final)\n");
		printf("\t\t\t6.Salir de la aplicacion eliminando la lista por completo \n");
		printf("\t\t\tOPCION ");
		scanf("%d",&opc);
	}while(opc<1 || opc>6);
	
	return opc;
	
}
