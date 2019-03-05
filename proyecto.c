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
	
	
   char palabra[]="holaaahoh"; 	
	
	cola inicio=NULL;
	
	pasarPalabra(&inicio,palabra);
	
	mostrarPalabra(inicio);
	
	revelarMensaje(&inicio,palabra);
	printf("\nPalabra sin encriptar \n");
	mostrarPalabra(inicio);
		
	return 0;
}


void revelarMensaje(cola *inicio,char *palabra)
{
	
  cola actual1,actual2;
  int cont=0,pos[2]={0},tam,i=0,posi=0,index=1;
  	
  actual1=*inicio;
  int	tamCola= dimensionCola(*inicio);
  tam=strlen(palabra);
  printf("\t\t\tPalabra cola actualmente \n");
  mostrarPalabra(*inicio); 
  printf("\nPalabra comparar %s ",palabra);
   while(actual1!=NULL)
   {  
      i=0;
      cont=0;
      posi=0;
      while(i<tam)
	  {
	  	printf("\nComparando %c : %c ",actual1->letra,palabra[i]);
	  	if(actual1->letra==palabra[i] && palabra[i]!='0')
	    {   printf("\nIgual y pos= %d \n",i);
	        pos[posi++]=i;
	    	cont++;
	    	printf("\n\t\t Contador %d ",cont);
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
     printf("\n\t\t\t INDEX= %d  ",index);
     index++;
   }
	
	
}

void pop(cola *inicio,int pos[], char *palabra)
{
	
	int cont=0,tam,i=0;
	
	cola actual,actual2,temp,anterior;
	tam=strlen(palabra);
	
	printf("\n\t\t\tEliminando repetidos \n");
	//actual1=*inicio;
	printf("\t\t\tPalabra entrante %s ",palabra);
	printf("\n\t\t\tLetras  a eliminar %c y %c \n",palabra[pos[0]],palabra[pos[1]]);
	
	if(*inicio!=NULL)
	{
	  if((*inicio)->letra==palabra[pos[0]])
	  {
	  	temp=*inicio;
	  	printf("\nBorrando %c ",(*inicio)->letra);
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
			printf("\nBorrando %c ",actual->letra);
			anterior->sig=actual->sig;
			free(temp);
			cont++;
		}
	  }
		
	}
	  
//	despilarPalabra(*inicio,palabra); 
 	printf("\nAntes de borrar el segundo \n");
 //	mostrarPalabra(*inicio);   
 //	printf("\nInicio %c ",(*inicio)->letra);  
	if(*inicio!=NULL && palabra[pos[1]]!='0')
	{
		printf("\n\t\t\tCreo estar aqui \n"); 
	    anterior=*inicio;//4
		actual=(*inicio)->sig;//3
		printf("\t\t\tAnterior: %c   Actual: %c ",anterior->letra,actual->letra);
		
		while(actual!=NULL && actual->letra!=palabra[pos[1]])
		{printf("\n\t\t\tAnterior: %c   Actual: %c letra: %c ",anterior->letra,actual->letra,palabra[pos[1]]);
			anterior=actual;
			actual=actual->sig;
		}
		
		printf("\t\t\tAnterior: %c   Actual: %c ",anterior->letra,actual->letra);
		if(actual!=NULL)
		{
			temp=actual;
			printf("\nBorrando %c ",actual->letra);
			anterior->sig=actual->sig;
			free(temp);
			cont++;
		}
		    
		   	
		if(cont==2)			
		 {
		  printf("\nCONT antes de entrar %d=== \n",cont); 	
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
	printf("\nEl tamanio de la cola actualmente es %d ",tamCola);
	
	memset(palabra,'0',tam);
//	palabra=(char *)realloc(palabra,tamCola*sizeof(char));
	
	while(i<tamCola)
	{
	  printf("\nEntra %c ",inicio->letra);	
	  palabra[i]=inicio->letra;
	  printf("\nRecibe %c ",palabra[i]);
	  i++;
	  inicio=inicio->sig;	
	  	
	}

    printf("\nNueva palabra : %s \n",palabra);
		
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
