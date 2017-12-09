#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"



 void initialisation( struct graphe *g){
	int i,j;
	 for( i=0; i<nmax;i++){
	 	g->Sommets[i]=0;
	 	 for( j=0; j<nmax;j++){
	 	 	g->Adjacances[i][j]=0;
		  }
	 }
	 
}

int estSommet(int Sommet){
	
	return Sommet!=0;
}

void Affichage( struct graphe g){
	int i,j;
	printf("\n");printf("\n");
	printf("Liste d'adjacance d'un graphe ");
	printf("\n");printf("\n");
	 for( i=0; i<nmax;i++){
	 	if(estSommet(g.Sommets[i])){
		
	 	printf("| %d |",g.Sommets[i]);
	 	 for( j=0; j<nmax;j++){
	 	 	  if(g.Adjacances[i][j]!=0)
	 	 		printf("| %d ",g.Adjacances[i][j]);
		  }
		   }
		  printf("\n");printf("\n");
		  
	 }
	 
}
void AjouterSommet(int Sommet,struct graphe *g ){

	int i;
	
	 for( i=0; i<nmax;i++){
		 if(!estSommet(g->Sommets[i])){
		 	g->Sommets[i]=Sommet;
		 	break;
		 }
	 }
}

void SupprimerSommet(int Sommet,struct graphe *g ){

	int i;
	
	 for( i=0; i<nmax;i++){
		 if(g->Sommets[i] == Sommet){
		 	g->Sommets[i]=0;
		 	break;
		 }
	 }
}


void AjouterArc(int Sommet1,int Sommet2,struct graphe *g ){
	int i,j,s;
	s=0;
	for( i=0; i<nmax;i++){
		 if(g->Sommets[i] == Sommet1){
		 	for( j=0; j<nmax;j++){
	 	 	if(g->Adjacances[i][j]!=0)
	 	 	s=s+1;
			  }
			  	g->Adjacances[i][s]=Sommet2;
			  break;
			  break;
			  
		  }
		 
	
		 }
}

int degreSortant(int indice ,struct graphe g){
	
	int i,s=0;
	for(i=0;i<nmax;i++ ){
		if(g.Adjacances[indice][i]!=0)
		s+=1;
		
	}
	return s;
}

int iemmeSucceur(int i,int indice,struct graphe g){
	
		int j,s=0;
		
	for(j=0;j<nmax;j++ ){
		if(g.Adjacances[indice][j]!=0){
			s+=1;
		if(s==i+1)
				break;
		
		}
	}
	int c;
	for(c=0;c<nmax;c++ ){
	if(g.Adjacances[indice][j]==g.Sommets[c])
	return c ;
	
	}
	
	
	
}
void profondeur(int indice,struct graphe g,int *marque){
	
int i,j,d,v=0,x=0;

		for(i=0;i<nmax;i++){
		if(marque[i]==0){
			x=1;
		}
		}
		
		if(x==1){
				printf("visite de %d \n",g.Sommets[indice]);
		marque[indice]=1;
		d=degreSortant(indice,g);
		
		for(i=0;i<d;i++){
		v=iemmeSucceur(i,indice,g);
		if(marque[v]==0)
		profondeur(v,g,marque);
		}
	}
}



int main(int argc, char *argv[]) {
	
	 struct graphe g ;
     initialisation(&g);
    
	 AjouterSommet(1,&g);
	  AjouterSommet(2,&g);
	   AjouterSommet(3,&g);
	    AjouterSommet(4,&g);
	     AjouterSommet(5,&g);

	 
	// SupprimerSommet(1,&g);
	  Affichage(g);
	   AjouterArc(1,2,&g);
	    AjouterArc(2,1,&g);
	    AjouterArc(2,3,&g);
	     AjouterArc(5,3,&g);
	      AjouterArc(5,4,&g);
	          AjouterArc(4,5,&g);
		Affichage(g);
	
		int marque[nmax],i;

	 for(i=0;i<nmax;i++){
	 marque[i]=0;
	 }
	 
	 
	 	 for(i=0;i<nmax;i++){
	 	 	if(marque[i]==0){
	 	 		profondeur(i,g,&marque);
			  }
		 }
		 
		
   
	
	 
	
	return 0;
}
