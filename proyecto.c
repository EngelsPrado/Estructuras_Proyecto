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
void revelarMensaje(cola *,char []);

int main(int argc, char *argv[]) {
	
	
   char palabra[]="holaaah"; 	
	
	cola inicio=NULL;
	
	pasarPalabra(&inicio,palabra);
	
	mostrarPalabra(inicio);
	
	revelarMensaje(&inicio,palabra);
	
	mostrarPalabra(inicio);
		
	return 0;
}

void revelarMensaje(cola *inicio,char palabra[])
{
	
  cola actual1,actual2;
  int cont=0,pos[2]={0},tam,i=0,posi=0;
  	
  actual1=*inicio;
  
  tam=strlen(palabra);
  printf("\t\t\tPalabra actualmente \n");
  mostrarPalabra(*inicio); 
   while(*inicio!=NULL)
   {  
      i=0;
      cont=0;
      while(i<tam)
	  {
	  	printf("\nComparando %c : %c ",(*inicio)->letra,palabra[i]);
	  	if((*inicio)->letra==palabra[i])
	    {   printf("\nIgual y pos= %d \n",posi);
	        pos[posi++]=i;
	    	cont++;
		}
		if(cont==2)
		{
		  pop(inicio,pos,palabra); 	
		}
	    i++;
	    
	  }  
   
     *inicio=(*inicio)->sig;
   }
	
	
}

void pop(cola *inicio,int pos[], char palabra[])
{
	
	int cont=0,tam,i=0;
	
	cola actual,actual2,temp,anterior;
	tam=strlen(palabra);
	
	printf("\n\t\t\tEliminando repetidos \n");
	//actual1=*inicio;
	printf("\n\t\t\tLetras  a eliminar %c y %c \n",palabra[pos[0]],palabra[pos[1]]);
	
	if(*inicio!=NULL)
	{
	  if((*inicio)->letra==palabra[pos[0]])
	  {
	  	temp=*inicio;
	  	*inicio=(*inicio)->sig;
		free(temp);	  	
	  	
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
			anterior->sig=actual->sig;
			free(temp);
		}
	  }
		
	}
	  
 	  
	if(*inicio!=NULL)
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
			anterior->sig=actual->sig;
			free(temp);
		}	
		
	  	
	  revelarMensaje(inicio,palabra);	
	}
		
	
		
}	


void mostrarPalabra(cola inicio)
{
	
	while(inicio!=NULL)
	{
	   printf("\n %c ",inicio->letra);
	   inicio=inicio->sig;	
		
	}
	
}



void pasarPalabra(cola *ptrInicio,char *palabra)
{
	
	
	
	int tam,i=0;
	
	cola nuevo,actual;
	
	tam=strlen(palabra);
	printf("\t\t\tTam de la palabra %d \n",tam);
	
	while(i<tam)
	{
	  nuevo=(cola)malloc(sizeof(Cola));	
	 // printf("\nPasando %c ",*palabra++);
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