#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct palabra{
  char letra;
  struct palabra *sig;	
	
};


typedef struct palabra Cola;
typedef Cola *cola;


void pasarPalabra(cola *,char *);
void mostrarPalabra(cola);
void pop(cola *,int [],char []);
void revelarMensaje(cola *,char *);
int dimensionCola(cola );
void despilarPalabra(cola,char * );

int main(int argc, char *argv[]) {
	
	
   char palabra[]="eeexafaafmccessndd"; 	
	
	cola inicio=NULL;
	
	pasarPalabra(&inicio,palabra);
	
	mostrarPalabra(inicio);
	
	revelarMensaje(&inicio,palabra);
	printf("\n\t\t\tPalabra sin encriptar \n");
	mostrarPalabra(inicio);
		
	return 0;
}


void revelarMensaje(cola *inicio,char *palabra)
{
	
  cola actual1,actual2;
  int cont=0,pos[2]={0},tam,i=0,posi=0,index=1,tamCola;
  	
  actual1=*inicio;
  tamCola= dimensionCola(*inicio);
  tam=strlen(palabra);
  printf("\n\n\t\t\tPalabra actualmente\n\n");
  mostrarPalabra(*inicio); 

   while(actual1!=NULL)
   {  
      i=0;
      cont=0;
      posi=0;
      while(i<tam)
	  {
	  	if(actual1->letra==palabra[i] && palabra[i]!='0')
	    {  
	        pos[posi++]=i;
	    	cont++;
		}
		
		if(cont==2)
		{	
		  pop(inicio,pos,palabra);//
		  return;
		}
	    i++;
	    
	  }
	
      printf("\n\n");
    //  printf("\ncont = %d ",cont);
     actual1=actual1->sig;
     if(actual1->sig==NULL)
     {
     	return;
	 }
     index++;
   }
	
	
}

void pop(cola *inicio,int pos[], char *palabra)
{
	
	int cont=0,tam,i=0;
	
	cola actual,actual2,temp,anterior;
	tam=strlen(palabra);
	
	printf("\n\t\t\tEliminando repetidos \n");
	
	printf("\n\t\t\tLetras  a eliminar %c y %c \n",palabra[pos[0]],palabra[pos[1]]);
	
	if(*inicio!=NULL)
	{
	  if((*inicio)->letra==palabra[pos[0]])
	  {
	  	temp=*inicio;
	  	printf("\n\t\t\tBorrando %c ",(*inicio)->letra);
	  	*inicio=(*inicio)->sig;
		free(temp);	  	
	  	cont++;
	  }else
	  {
	  	anterior=*inicio;//4
		actual=(*inicio)->sig;//3
		
		while(actual!=NULL && actual->letra!=palabra[pos[0]])
		{
			anterior=actual;
			actual=actual->sig;
		}
		
		if(actual!=NULL)
		{
			temp=actual;
			printf("\n\t\t\tBorrando %c ",actual->letra);
			anterior->sig=actual->sig;
			free(temp);
			cont++;
		}
	  }
		
	}
	   
	if(*inicio!=NULL && palabra[pos[1]]!='0')
	{ 
	    anterior=*inicio;//4
		actual=(*inicio)->sig;//3		
		while(actual!=NULL && actual->letra!=palabra[pos[1]])
		{
		    
			anterior=actual;
			actual=actual->sig;
		}

		if(actual!=NULL)
		{
			temp=actual;
			printf("\n\t\t\tBorrando %c ",actual->letra);
			anterior->sig=actual->sig;
			free(temp);
			cont++;
		}
		    
		   	
		if(cont==2)			
		 {	
		  despilarPalabra(*inicio,palabra);	
	      revelarMensaje(inicio,palabra);	
		 }
	}
	    
			
}	

int dimensionCola(cola inicio)
{
	
	int cont=0;
	
	while(inicio!=NULL)
	{
	   cont++;
	   inicio=inicio->sig;	
		
	}
	
	return cont;
	
}



void despilarPalabra(cola inicio,char *palabra)
{
	
   int tamCola,i=0,tam;
   
    tamCola= dimensionCola(inicio);	
    tam=strlen(palabra);	
	
	memset(palabra,'0',tam);
	
	while(i<tamCola)
	{
	
	  palabra[i]=inicio->letra;
	  i++;
	  inicio=inicio->sig;	
	  	
	}
		
}

void mostrarPalabra(cola inicio)
{
	
	while(inicio!=NULL)
	{
	   printf(" %c ",inicio->letra);
	   inicio=inicio->sig;	
		
	}
	
}



void pasarPalabra(cola *ptrInicio,char *palabra)
{
	
	
	
	int tam,i=0;
	
	cola nuevo,actual;
	
	tam=strlen(palabra);
	
	while(i<tam)
	{
	  nuevo=(cola)malloc(sizeof(Cola));	
	  nuevo->letra=*palabra++;	
		
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
	  	i++;
	}
	
	
	
}
