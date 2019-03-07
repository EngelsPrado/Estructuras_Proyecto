#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int num;
  char user[20];
  char program[20];
  struct nodo *sig;
	
};


typedef struct nodo Cola;
typedef Cola *cola;


void pushCola(cola *);//Inserta elementos de la cola
void popCola(cola *);//Elimina elementos de la cola
void popColaImpresion(cola *);//Elimina una impresion, incluyendo las que estan encimas de esa
void mostrarEstado(cola);//Mostrar la cola de impresiones pendientes
int menu();//Muestra un menu de opciones

int main(int argc, char *argv[]) {
	
	int opc;
	
	cola inicio=NULL;
	
	opc=menu();
	
	do
	{
		
		switch(opc)
		{
		   case 1:  pushCola(&inicio);
					break; 
		   
		   
		   case 2: popCola(&inicio);
		   	
		   	       break;
		   case 3: popColaImpresion(&inicio);
		   	       break;
		   	
		   case 4:  break;
		   	
		   	
		}
		printf("\n\n");
		mostrarEstado(inicio);
		
		opc=menu();
		
		
	}while(opc!=4);
	
	
	return 0;
}


int menu()
{
   int opc;
   
   printf("\n\n\n\t\t\t\t\t M  E  N  U\n\n\n");
   do
   {
   	  printf("\n\n\n\t\t\t1.Enviar impresion \n");
   	  printf("\t\t\t2.Imprimir \n");
   	  printf("\t\t\t3.Eliminar impresion \n");
   	  printf("\t\t\t4.Salir\n");
   	  printf("\n\n\n\t\t\tOPCION ");
   	  scanf("%d",&opc);
   	
   }while(opc<1 || opc>4);
  	
  	return opc;
}

void mostrarEstado(cola inicio)
{
	
	cola actual;
	
	actual=inicio;
	
	printf("\nNumero de trabajo %15s \n\n","Usuario");
	while(actual!=NULL)
	{
		
		printf("\n %d %30s ",actual->num,actual->user);
		actual=actual->sig;
		
		
	}
	printf("\n\n");
	system("pause");
	system("cls");
}


//Insertamos la impresion en forma de cola
void pushCola(cola *ptrInicio)
{
	static int cont=1;
	
	cola nuevo,actual,previo;
	
	nuevo=(cola)malloc(sizeof(Cola));
	fflush(stdin);
    printf("\t\t\tIngrese el nombre de usuario: ");
    gets(nuevo->user);
    fflush(stdin);
    printf("\n\n");
    printf("\t\t\tIngrese el programa desde el cual se envia la impresion:  ");
    gets(nuevo->program);
	nuevo->num=cont++;
	
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

//Eliminamos la impresion y/o las que estan encimas de ellas
void popColaImpresion(cola *inicio)
{
	int dato;
	
	cola temp,actual,anterior;
	
	printf("\n\t\t\tIngrese el numero de trabajo que desea borrar:   ");
	scanf("%d",&dato);
	
	if(*inicio!=NULL)
	{
		if(dato==(*inicio)->num)
	   {
		temp=*inicio;
		*inicio=(*inicio)->sig;
		free(temp);
	  }else{
		anterior=*inicio;
		actual=(*inicio)->sig;
		
		
		while(actual!=NULL && actual->num!=dato)
		{
			anterior=actual;
			actual=actual->sig;
		}
	    
	     anterior->sig=NULL;
	     
	     while(actual!=NULL)
	     {
	     	temp=actual;
	     	actual=actual->sig;
	     	free(temp);
	     	
		 }
		
		
	 }
	}
}

//Eliminamos las impresiones mas recientes en ser enviadas para imprimir
void popCola(cola *inicio )
{
	
	cola temp,anterior,actual;
	
	
	if(*inicio!=NULL)
	{
	   temp=*inicio;
	   *inicio=(*inicio)->sig;	
		free(temp);
	}	
	
	
}

