#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

   Nombre: Engels Prado Herrera                    Asignatura: Estructura de Datos
    
   Docente:Lesbia Valerio                          Carrera:Ing.En sistemas de informacion 

   Objetivo:En tu negocio tienes una secuencia de n sillas acomodas en línea recta y numeradas de 1 a n, por cada persona que se siente en una silla con el número x,
   deberás pagar $x al gobierno, pero como quieres tener cómodos a los clientes, no tienes otra opción que pedirles que tomen asiento;
   sin embargo, el aprecio por el cliente aún no te ha quitado la codicia, por lo que puedes indicarle a cada cliente donde sentarse, pero el cliente decide cuando irse;
   desde el momento que un cliente llega hasta el momento que se va,
   el cliente pasará todo el tiempo sentado en una silla y no estará dispuesto a compartirla con nadie más. 
 
   Escribe un programa que dado el historial de qué clientes llegan y qué clientes se van en orden
   cronológico (del más reciente al más último),
    calcule que asientos   asignarles a cada quien para que el
	dinero que debas pagar al gobierno sea el Mínimo posible. Tu programa deberá funcionar  correctamente.

*/



struct nodo{

  int item;
  struct nodo *sig;
	
};
      

typedef struct nodo Cola;
typedef Cola *cola;

void pushCola(cola *,int *);//Inserta elementos en la cola
void pop(cola *);//saca un elemento de la cola
void mostrarCola(cola);//Muestra los elementos de la cola
int menu();

int main(int argc, char *argv[]) {
	
	cola inicio=NULL;
	
	int opc,acum=0;
	
	opc=menu();
	
	do
	{
		switch(opc)
		{
			
		  case 1: pushCola(&inicio,&acum); 
		          break;
		  
		  case 2: pop(&inicio);
		          system("pause");
		          break;
		  
	
		}
	 printf("\n\t\t\tAsientos ocupados \n");	
	 mostrarCola(inicio);	
	 printf("\n\n");
	 printf("\n\t\t\tEl total a pagar hasta el momento es= %d ",acum);
	 printf("\n\n");
	 system("pause");
	 system("cls");
	 opc=menu();
	 	
	}while(opc!=3);
	
	
	return 0;
}

int menu()
{
	int opc;
	
	printf("\n\n\n\t\t\t\t M   E   N    U \n\n\n");
	do{
		printf("\n\n\n\t\t\t1.Sentar cliente \n");
	    printf("\t\t\t2.Retirar un cliente \n");
	    printf("\t\t\t3.Salir \n");
		printf("\n\n\n\t\t\tOPCION ");
	scanf("%d",&opc);
		
	}while(opc<1 || opc>3);
	
	
	return opc;
}

void mostrarCola(cola inicio)
{
	int cont=1, acum=0;
	
	while(inicio!=NULL)
	{
	   printf(" %d ",inicio->item);
	   acum+=cont++;
	   inicio=inicio->sig;	
		
	}

}
//Retorna la dimension de la cola
int dimensionCola(cola inicio)
{
   int cont=0;
	
  while(inicio!=NULL)
  {
  	++cont;
  	inicio=inicio->sig;
  	
  }	

   return cont;
}

//Funcion que eliminar elementos en cualquier parte de la cola
void pop(cola *inicio)
{
	
	cola anterior,actual,temp;
	
	int dato,tam;
	
	tam=dimensionCola(*inicio);
	
    dato=1+rand()%(tam+1 - 1);//Asignamos un valor aleatorio a dato


	printf("\n\t\t\tSaliendo clientes # %d ",dato);
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
		}else
		     printf("\nNo se encontro el asiento \n");
	}
	
}


//Funcion que inserta elementos en forma de cola
void pushCola(cola *ptrInicio,int *acum)
{
	static int cont=1;
	
	cola nuevo,actual,previo;
	
	nuevo=(cola)malloc(sizeof(Cola));
		
	if(nuevo!=NULL)
	{
	   
	  nuevo->item=cont++;  
	    	
	   if(*ptrInicio==NULL)
	   {
	   	  *ptrInicio=nuevo;
	       nuevo->sig=NULL;	  
	       *acum+=nuevo->item;  	
	   }else
	       {
	       	 nuevo->sig=*ptrInicio;
	       	 *ptrInicio=nuevo;
	       	 *acum+=nuevo->item;
		   }
	   
	   	
	   	
	}
}
