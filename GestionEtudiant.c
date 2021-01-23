#include <stdio.h>
/*
#Author : Ahmed Alweimine
*/

//fonction qui lit un fichier et Cherche l'existance d'un etudiant puis Calcule sa moyenne g�nerale
void lireFichier(char nomFichier[],int Coeff[],	int sumCoeffi,char Matricule[]){
    //l'ouverture de fichier
	FILE *nom_fichier=fopen( nomFichier,"r");
	int a=0;  // compteur initialis� par 0 et sa valeur est chang� � 1 si le matricule entr� par l'utilisateur trouv� dans le fichier 
	int sumNote=0; //compteur contient la somme des notes de l'etuiant dont le matricule est entr� par l'utilisateur
	int i=0;   //indice pour parcourire le tableau des coeffitients
	/*dans le cas ou l'ouverture de fichier echoue*/
	if(nom_fichier==NULL){
		perror("pblm d'ouverture de fichier");
		exit(1);
	} 
	char ligne[1000];    //pour stocker les lignes des fichiers
	//le parcours des lignes
	while(fgets(ligne,sizeof(ligne),nom_fichier)){
		char *mot;   
		//la lecture des lignes mot par mot
		mot=strtok(ligne,";");   //la fonction strtok est pr�defini en C qui permet d'extraire tous le mot separ� par un symbole (ici le fichier format CSV donc separ� par ;) d'une ligne 
		//la fonction  strcmp est pr�defini en C qui permet la comparaison des chaines de caract�res
		if(strcmp(mot,Matricule)==0){
		//printf("Etudiant trouv� \n");
		a=1;	
		}
		while(mot!=NULL){
		printf("      %s",mot);		
		mot=strtok(NULL,";");
		if(a==1){
		//atoi : une fonction quin converti une chaine de caract�re en entier
		sumNote=atoi(mot)*Coeff[i]+sumNote;
		i++;
		}	
		}
		//si a==1 c-a-d que le matricule entr� par l'utilistauer correspont bien � un etudiant trouv� dans le fichier  et sa moyenne est calcul�
		if(a==1)
		{
		a=0; // on reinitialise le compteur a � O car on s'intresse que � la l'etudiant dont le matricule est entr�
		}
	}
	/*partie affichage de resultat � l'ecrans*/
	if(sumNote!=0)
	printf("\n La Moyenne Generale est : %f",sumNote/(double)sumCoeffi);
    else
	printf("\n le Matricule ne Correspond a aucun etudiant.. Vielliez Enrer un Matricule Valide!!");
} 

/*La Fonction */

int main(){
	//les coeffitient ici enre� comme tableau 
	int Coeffictients[]={3,2,1};
	printf("----------------------Les Coefficients:-----------------\n");
	int i=0;
    while(i<3){
    printf("%d ",Coeffictients[i]);
	i++;	
	}
	
	char Matricule[100];
	
	printf("\n----------------------Les Notes -----------------\n");
	printf("Entrer SVP  votre Matricule:");
    scanf("%s", Matricule);
 	//printf("Votre matricule %s !\n\n", Matricule);
 	printf("----------------------Les Resultat:-----------------\n");
    lireFichier("EtudiantResultat.csv",Coeffictients,6,Matricule);  //ici 6  est la somme des coeffitient juste pour facilit� le calcule dans fonction
}
