#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MES 30


/*

   Nombre: Engels Prado Herrera                    Asignatura: Estructura de Datos
    
   Docente:Lesbia Valerio                          Carrera:Ing.En sistemas de informacion 

   Objetivo: Dada una lista que se encuentra almacenada en memoria donde cada nodo posee la Temperatura promedio diaria del mes de junio del corriente año. Se pide armar tres listas:  
 
    Una con los nodos cuya componente sea menor a 0º.      
	Otra con los nodos cuya componente sea mayor a 10º.
	y la última con los nodos cuyas temperaturas se encuentren en el rango 0-9 inclusive.

*/

struct nodo{

  int item;
  struct nodo *sig;
	
};


typedef struct nodo Lista;
typedef Lista *lista1,*lista2,*lista3,*lista4;

void mostrar(lista1);//Mostramos las temperaturas promedio del dia del mes de Junio
void pushLista1(lista1*,int);//Funcion que inserta las temperatus diarias en una lista
void pushLista2(lista2*,int);//Funcion que inserta las temperatus menores a 0
void pushLista3(lista3*,int);//Funcion que inserta las temperaturas mayores a 10
void pushLista4(lista4*,int);//Funcion que inserta las temperaturas que oscila entre 0 y 9
void rellenarListas(lista1,lista2 *,lista3 *,lista4 *);//Rellena cada lista con las temperatuas dependiendo del rango de validacion
int menu();
void mostrarPila1(lista2);//Muestra las temperaturas menores que 0
void mostrarPila2(lista3);//Muestra las temperaturas mayores que 10
void mostrarPila3(lista4);//Muestra las temperaturas entre 0-9

int main(int argc, char *argv[]) {
	
	int num,cont=0,opc;
	
	lista1 inicio1=NULL;
	lista2 inicio2=NULL;
	lista3 inicio3=NULL;
	lista4 inicio4=NULL;
	
	srand(time(NULL));
	
	do
	{
	   num=-10 + rand()%(31- (-10));
	   pushLista1(&inicio1,num);
	   cont++;
	   	
	}while(cont<=MES);
	
	//mostrar(inicio1);
	
	opc=menu();
	rellenarListas(inicio1,&inicio2,&inicio3,&inicio4);
	do
	{
	   switch(opc)
	   {
	   	  case 1: mostrarPila1(inicio2);
	   	  	      break;  
	   	  	
	   	  	
	   	  case 2:
	   	  	      mostrarPila2(inicio3);
	   	  	      break; 
			 
			 
		  case 3: mostrarPila3(inicio4);
	   	  	      break; 
		  	      
		  	  	
	     
			
	   }	
	  printf("\n\n\n");
	  system("pause");
	  system("cls");	
	  opc=menu();	
	}while(opc!=4);
	
	
	
	return 0;
}

void mostrarPila1(lista2 inicio)
{
	int cont=0;
	
	system("cls");
	printf("\n\t\t\t Temperaturas menores que 0 grados \n\n");
	while(inicio!=NULL)
	{
		printf("\t [%d] ",inicio->item);
	   if(cont==5)
	    {
	    	cont=0;
	    	printf("\n\n");
		 } 
	   cont++;
	   inicio=inicio->sig; 	
		
	}
	
}

void mostrarPila2(lista3 inicio)
{
	int cont=0;
	
	system("cls");
	printf("\n\t\t\t Temperaturas mayores que 10 grados \n\n");
	while(inicio!=NULL)
	{
	   printf("\t [%d] ",inicio->item);
	   if(cont==5)
	    {
	    	cont=0;
	    	printf("\n\n");
		 } 
	   cont++;
	   inicio=inicio->sig; 	
		
	}
	
}
void mostrarPila3(lista4 inicio)
{
	int cont=0;
	
	system("cls");
	printf("\n\t\t\t Temperaturas entre 0-9 grados \n\n");
	while(inicio!=NULL)
	{
	   printf("\t [%d] ",inicio->item);
	   if(cont==5)
	    {
	    	cont=0;
	    	printf("\n\n");
		 } 
	   cont++;
	   inicio=inicio->sig; 	
		
	}
	
}

int menu()
{
   int opc;
   
   printf("\n\n\n\n\t\t\t\t\t\t M E N U \n\n\n\n\n");
   
   do
   {
   	 printf("\t\t\t1.Mostrar el promedio de temperaturas diarias menores que 0 grados \n\n");
   	 printf("\t\t\t2.Mostrar el promedio de temperaturas diarias mayores que 10 grados \n\n");
   	 printf("\t\t\t3.Mostrar el promedio de temperaturas diarias entre 0-9 grados \n\n");
   	 printf("\t\t\t4.Salir\n\n\n");
   	 printf("\t\t\tOPCION ");
   	 scanf("%d",&opc);
   }while(opc<1 || opc>4);	
	
	return opc;
}
void mostrar(lista1 inicio)
{
	int cont=1,dia=1;
	
	printf("\n\t\t\t El promedio de lluvias por dia del mes de Junio \n\n");
	
	while(inicio!=NULL)
	{
	   printf("[%d] ",inicio->item);
	   if(cont==5)
	    {
	    	printf("\n\n");
	    	cont=0;
		}
		
	   cont++;
	   inicio=inicio->sig;		
	}
	
	system("pause");
}

void rellenarListas(lista1 inicio,lista2 *inicio2,lista3 *inicio3,lista4 *inicio4)
{

	
	while(inicio!=NULL)
	{
		//Hacemos las respectivas validaciones para decidir que temperatura va en que lista
		
	   if(inicio->item<0)	
		 pushLista2(inicio2,inicio->item);
	   else
	       if(inicio->item>10)
		      pushLista3(inicio3,inicio->item);
		   else
		        if(inicio->item>=0 && inicio->item<=9)
				   pushLista4(inicio4,inicio->item);
				   
				   
	  inicio=inicio->sig;			   	  	 
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

void pushLista2(lista2 *ptrInicio,int x)
{
	
	
	lista2 nuevo,actual,previo;
	
	nuevo=(lista2)malloc(sizeof(Lista));
		
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
