#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{

  int item;
  struct nodo *sig;
	
};


typedef struct nodo Pila;
typedef Pila *pila1,*pila2;


int menu();//Muestra un menu de opciones
void push(pila1 *,int);//Inserta nodos en forma de pila 
void pop(pila1 *,pila2 *);//Elimina los nodos de la pila 1
void pushPila(pila2 *,int );//Inserta los nodos provenientes de la pila1 en la pila2
void mostrar(pila1);//Muestra el estado de la pila 1
void popPila2(pila1 *,pila2 *);//Saca los elementos de la pila2 y los regresa a la pila1

int main(int argc, char *argv[]) {
	
	pila1 inicio1=NULL;
	pila2 inicio2=NULL;
	
	int op,x;
	
	op=menu();
	
	
	do
	{
		
		switch(op)
		{
			case 1:printf("\n\t\t\tIngrese el codigo del contenedor: ");
	               scanf("%d",&x);
			       push(&inicio1,x);
				   mostrar(inicio1);
				   break;
			case 2:	pop(&inicio1,&inicio2);
			        mostrar(inicio1);
			       break;
		}
		
		printf("\n\n");
        system("cls");
		op=menu();
		
	}while(op!=3);
	

	
	
	return 0;
}

//Muestra los elementos actuales de la pila1
void mostrar(pila1 inicio)
{
	printf("\n\n\t\t\t El estado actual de la pila: \n\n");
	
	while(inicio!=NULL)
	{
		
	   printf("\n -->[%d] ",inicio->item);
	   inicio=inicio->sig;	
		
	}
	printf("\n\n\n");
	system("pause");
}


int menu()
{
	
	int opc;
	printf("\t\t\t\t\t\t M E N U\n");
	printf("\t\t\t-------------------------------------------------------\n");
	do
	{
	  printf("\n\n\n\t\t\t-->1.Apilar un elemento \n\n");
	  printf("\t\t\t-->2.Sacar un elemento \n\n");
	  printf("\t\t\t-->3.Salir\n\n");
	printf("\t\t\t-------------------------------------------------------\n\n");  
	  printf("\n\n\n\t\t\tOPCION ");
	  scanf("%d",&opc);	
		
	}while(opc<1 || opc>3);
	
	
	
	
}

//Saca los elementos de la pila2 y los regresa a la pila1
 
void popPila2(pila1 *inicio1,pila2 *inicio2 )
{
	
	pila2 temp,anterior,actual;
		
	while(*inicio2!=NULL)
	{
		actual=*inicio2;
		
		if(actual->sig==NULL)//Cuando sea el ultimo elemento de la pila2,lo insertamos en nuevamente en la pila1
		{
		 push(inicio1,actual->item);
		 temp=actual;
		 *inicio2=NULL; 
		  free(actual);	
		  return;
		}
		
		
		while(actual!=NULL && actual->sig!=NULL)//Buscamos el ultimo elemento  de la pila
		{
			anterior=actual;
			actual=actual->sig;
			
		}
		
		push(inicio1,actual->item);//Lo insertamos nuevamente en la pila1
	    temp=actual;
	    anterior->sig=actual->sig;
		free(actual);
	
	}
	
	
}


void pop(pila1 *inicio1,pila2 *inicio2)
{
	
	pila1 temp,actual;
	
	int num;
	
	printf("\n\n\t\t\tIngrese numero que desea retirar: ");
	scanf("%d",&num);
	
	actual=*inicio1;
		
	
	while(*inicio1!=NULL)
	{
		
	
		if(num==(*inicio1)->item)//Cuando sea el elemento que queremos borrar
		{
		   temp=*inicio1;
		   *inicio1=(*inicio1)->sig;	
			free(temp);
			popPila2(inicio1,inicio2);//Mandamos a llamar la funcion que se encarga de insertar nuevamente los valores que fueron sacados para borrar un numero
			return;
		}else
		   {
		   pushPila(inicio2,(*inicio1)->item);//Antes de borrar el elemento lo guardamos en otra pila
		   temp=*inicio1;
		   *inicio1=(*inicio1)->sig;	
			free(temp);	
			}	
		   
	    
	}
	
	

}

//Inserta nodos en forma de pila
void pushPila(pila2 *ptrInicio,int num)
{
	
	pila2 nuevo,actual,previo;
	
	nuevo=(pila2)malloc(sizeof(Pila));//Creamos un nuevo nodo	
	
	if(nuevo!=NULL)//Verificamos que haya espacio en memoria para ese nodo
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
	
}

void push(pila1 *ptrInicio,int x)
{
	
	
	pila1 nuevo,actual,previo;
	
	nuevo=(pila1)malloc(sizeof(Pila));
	
	
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
