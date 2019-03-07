#include <stdio.h>
#include <stdlib.h>


//Dedicada a guardar datos de las neveras
struct nodo{

  int codigo;
  char descripcion[50];
  struct nodo *sig;
	
};


typedef struct nodo Pila;
typedef Pila *pila;

//Dedicada a guardar la lista de tiendas que adquieron neveras
struct nodoLista{

   char nombre[50];
   int codigos[20];
   int cantidadNeveras;
  struct nodoLista *sig;
	
};


typedef struct nodoLista Lista;
typedef Lista *lista;

void crearNeveras(pila *);//Crea nuevos elementos en forma de pila
void hacerPedido(pila *,lista *);//Hace un pop a la pila que contiene las neveras y las guarda en una nueva lista
int menu();//Presenta un menu
void mostrarNeveras(pila);//Muestra las neveras actuales o disponibles
void mostrarPedido(lista);//Muestra las neveras vendidas

int main(int argc, char *argv[]) {
	
	pila inicio=NULL;
	lista cabeza=NULL;
	
	int opc;
	
	opc=menu();
	
	do
	{
		switch(opc)
		{
		 
		  case 1: crearNeveras(&inicio);
		          mostrarNeveras(inicio);
		          break;
		  case 2: hacerPedido(&inicio,&cabeza);	
			      mostrarPedido(cabeza);
			      break;
		}
		
		opc=menu();
		system("pause");
		system("cls");
	}while(opc!=3);
	
	
	return 0;
}

void mostrarNeveras(pila inicio)
{
	system("cls");
	
	printf("\n\n\t\t\t\t\tListado de neveras \n\n\n");
	
	printf("\n\n\t\t\t Codigo %20s \n\n","Descripcion");
	while(inicio!=NULL)
	{
		printf("\t\t\t  %d %20s\n",inicio->codigo,inicio->descripcion);
		inicio=inicio->sig;
	}
	
	printf("\n\n");
	system("pause");
	system("cls");
}

//Muestra el listado de tiendas que adquieron neveras, con sus respectivos codigos
void mostrarPedido(lista inicio)
{
	int index=0;

	
	printf("\t\t\t Tienda %20s \n\n\n","Codigos Neveras");
	while(inicio!=NULL)
	{
	   printf("\n\t\t\t %s ",inicio->nombre);
	   while(index<inicio->cantidadNeveras)
	   {
	   	 printf("\n\t\t\t\t\t%10d",inicio->codigos[index++]);
	   }
	    index=0;
	  	inicio=inicio->sig;
	  	printf("\n\n");
	}
	
	system("pause");
	system("cls");
}

int menu()
{
	
	int opc;
	
	 printf("\n\n\t\t\t\t\t M  E  N  U\n\n");
	do
	{
		printf("\n\n\n\t\t\t1.Crear 5  neveras mas \n");
		printf("\t\t\t2.Recibir pedido de neveras \n");
		printf("\t\t\t3.Salir \n");
		printf("\n\n\n\t\t\tOPCION ");
		scanf("%d",&opc);
	}while(opc<1 || opc>3);
	
	
	return opc;
}


//Funcion que crea elementos en forma de pila
void crearNeveras(pila *ptrInicio)
{
	static int id=0;
	int x,cont=1;
	
	pila nuevo,actual,previo;
	
	
	
    while(cont<=5)
    {
    	nuevo=(pila)malloc(sizeof(Pila));
        nuevo->codigo=id++;
        fflush(stdin);
	    printf("\t\t\tIngrese una descripcion para la nevera %d : ",cont);
	    gets(nuevo->descripcion);
		
		if(nuevo!=NULL)
		{
		    	
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


void hacerPedido(pila *inicio,lista *cabeza)
{
	int cont=0,x;
	
	pila temp;
	
	lista nuevo,anterior,actual;
	
	nuevo=(lista)malloc(sizeof(Lista));
	
	printf("\n\t\t\tIngrese el numero de neveras: ");
	scanf("%d",&x);
	nuevo->cantidadNeveras=x;
	fflush(stdin);
	printf("\t\t\tIngrese el nombre de la tienda: ");
	gets(nuevo->nombre);
	
	while(cont<x )
	{
		if(*inicio!=NULL)
	   {
	   	
		   	if(nuevo!=NULL)
	        {
			   nuevo->codigos[cont]=(*inicio)->codigo;//Guardamos los codigos de las neveras
			   
	        }
	   	
	   	// Y la vamos borrando 
	    temp=*inicio;
	   *inicio=(*inicio)->sig;	
		free(temp);
	   }
	   
	   cont++;
	}
	
	//Posteriormente insertamos el nodo en la lista que guardara las tiendas con sus neveras y respectivos codigos
	if(*cabeza==NULL)
   {
   	  *cabeza=nuevo;
       nuevo->sig=NULL;	  
   	
   }else
       {
       	 nuevo->sig=*cabeza;
       	 *cabeza=nuevo;
       	 
	   }
	
}

