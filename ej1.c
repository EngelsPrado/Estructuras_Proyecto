#include <stdio.h>
#include <stdlib.h>


struct nodo{

  int codigo;
  float precio;
  struct nodo *sig;
	
};


typedef struct nodo Lista;
typedef Lista *lista;

int menu();
void insertarFinal(lista *,float *);//Inserta nodos en forma de cola
void mostrarXrango(lista );//Muestra todos los elementos(libros) de la cola 
void mostrarXprecio(lista );//Muestra los libros menores que un precio x
void mostrarXcodigo(lista );//Busca un libro por su codigo
void eliminarXrango(lista *,float *);//Elimina todos los libros que esten dentro de un rango especificado
void eliminarLista(lista *);//Elimina todos los libros

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
			        
			case 3: printf("\n\t\t\t-->La suma de todos los precios es %.2f \n",sumaPrecios);
			        break;
					
					
			case 4: mostrarXprecio(inicio);
			        break;		 
					
			case 5: eliminarXrango(&inicio,&sumaPrecios);
			        break;
			        
			case 6: eliminarLista(&inicio);
			        break;        
							       
		}	
	  opc=menu();
	  
	  	
	}while(opc!=6);
	
	
	
	
	return 0;
}

//Elimina todos los elementos de la lista
void eliminarLista(lista *inicio)
{
	
	lista temp,actual;
	
	actual=*inicio;
	
	printf("\n\t\t\tEliminando elementos de la lista antes de salir...\n");
	
    while(actual!=NULL)
	{
	
		temp=actual;
		actual=actual->sig;	
		free(temp);
	}
}


//Funcion que elimina los libros que esten dentro de un rango
void eliminarXrango(lista *inicio, float *sumaPrecios)
{
	int codigoInicio,codigoFinal;
	
	lista actual,anterior,temp;
	
	 mostrarXrango(*inicio);
	
	
	printf("\n\t\t\tIngrese el codigo de inicio: ");
	scanf("%d",&codigoInicio);
	printf("\n\t\t\tIngrese el codigo final: ");
	scanf("%d",&codigoFinal);
	
	
	
	
	if((*inicio)->codigo==codigoInicio)//Si el codigo de inicio esta en el principio de la lista se procede a eliminar con el algoritmo de eliminacion por el inicio
	{
	   temp=*inicio;
	  *sumaPrecios-=(*inicio)->precio;
	  *inicio=(*inicio)->sig;
	   free(temp);
	   
	   while(*inicio!=NULL && (*inicio)->codigo<=codigoFinal) 
	   {
	   	 temp=*inicio;
	     *sumaPrecios-=(*inicio)->precio; 	 
		 *inicio=(*inicio)->sig;
		  free(temp);	 
	     	
	   } 	 
	   
	}else// De lo contrario se procede a eliminar nodos con el algoritmo de eliminacion en cualquier nodo
	{
	  actual=(*inicio)->sig;
	  anterior=*inicio;
	
		while(actual!=NULL) 
		{
			if(actual!=NULL && actual->codigo>=codigoInicio && actual->codigo<=codigoFinal)
			{
				
			  temp=actual;
			  *sumaPrecios-=actual->precio;
			  anterior->sig=actual->sig;
			  actual=anterior;
			  free(temp);
				
			} 
				
			anterior=actual; 	
			actual=actual->sig;
		}	
		
		
	 } 
		 	
	
	
	
}

//Funcion que encargada de buscar los libros menores que un precio x
void mostrarXprecio(lista inicio)
{
	int precio;
	
	printf("\n\t\t\tIngrese el precio del libro \n");
	scanf("%d",&precio);
	
	printf("\t\t Codigo %10s \n\n\n","Precio");
	while(inicio!=NULL)
	{
		
	   if(precio<=inicio->precio)
	    {
	      printf("\n\t\t %d %15.2f \n",inicio->codigo,inicio->precio);   	
		}  			   
	   inicio=inicio->sig;	
		
	}
	
}

//Busca un libro por el codigo del mismo
void mostrarXcodigo(lista inicio)
{
	int codigo,band=0;
	
	printf("\n\t\t\tIngrese el codigo del libro: ");
	scanf("%d",&codigo);
	
	while(inicio!=NULL)
	{
		
	   if(codigo==inicio->codigo)
	      {
	        printf("\n\n\t\t\t Codigo %10s \n","Precio");
	        printf("\t\t\t %d %15.2f \n",inicio->codigo,inicio->precio);
	        band=1;
	        break; 
		  }
			   
	   inicio=inicio->sig;	
		
	}
	
	if(band==0)//Si band no cambia su valor significa que el libro no fue encontrado
	{
		printf("\n\t\t\t--> Libro no encontrado \n");
	}
	
	system("pause");
	system("cls");
	
}

void mostrarXrango(lista inicio)
{
	printf("\n\t\t\t La lista es: \n\n\n");
	
	while(inicio!=NULL)
	{
		
	   printf(" [%d] ",inicio->codigo);
	   inicio=inicio->sig;	
		
	}
	printf("\n\n");
	system("pause");
	system("cls");
	
}

void insertarFinal(lista *ptrInicio,float *sumaPrecios)
{
   int codigo;
   float precio;
	
	lista nuevo,actual,anterior;
	
	nuevo=(lista)malloc(sizeof(Lista));
	
	printf("\n\t\t\tIngrese el codigo del libro: ");
	scanf("%d",&nuevo->codigo);
	printf("\n\t\t\tIngrese el precio del libro: ");
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
	 
	system("cls"); 
}


int menu()
{
	int opc;
	
	printf("\n\n\t\t\t\t\t\t\t *M E N U* \n");
	do
	{   
		printf("\n\n\n\t\t\t--------------------------------------------------------------------------------------------\n\n"); 
		printf("\n\n\n\t\t\t1.Agregar un nuevo libro al final de la lista \n\n");
		printf("\t\t\t2.Buscar un libro por el codigo \n\n");
		printf("\t\t\t3.Mostrar la suma de todos los precios \n\n");
		printf("\t\t\t4.Mostrar el listado de libros que sean menores a un precio ingresado\n\n");
		printf("\t\t\t5.Eliminar los libros que esten en un rango de codigo(codigo inicio y codigo final)\n\n");
		printf("\t\t\t6.Salir de la aplicacion eliminando la lista por completo \n\n");
		printf("\t\t\t--------------------------------------------------------------------------------------------\n\n");
		printf("\t\t\tOPCION ");
		scanf("%d",&opc);
	}while(opc<1 || opc>6);
	
	system("cls");
	return opc;
	
}
