#include <stdio.h>
/*
#Author : Ahmed Alweimine
*/

//fonction qui lit un fichier et Cherche l'existance d'un etudiant puis Calcule sa moyenne génerale
void lireFichier(char nomFichier[],int Coeff[],	int sumCoeffi,char Matricule[]){
    //l'ouverture de fichier
	FILE *nom_fichier=fopen( nomFichier,"r");
	int a=0;  // compteur initialisé par 0 et sa valeur est changé à 1 si le matricule entré par l'utilisateur trouvé dans le fichier 
	int sumNote=0; //compteur contient la somme des notes de l'etuiant dont le matricule est entré par l'utilisateur
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
		mot=strtok(ligne,";");   //la fonction strtok est prédefini en C qui permet d'extraire tous le mot separé par un symbole (ici le fichier format CSV donc separé par ;) d'une ligne 
		//la fonction  strcmp est prédefini en C qui permet la comparaison des chaines de caractéres
		if(strcmp(mot,Matricule)==0){
		//printf("Etudiant trouvé \n");
		a=1;	
		}
		while(mot!=NULL){
		printf("      %s",mot);		
		mot=strtok(NULL,";");
		if(a==1){
		//atoi : une fonction quin converti une chaine de caractére en entier
		sumNote=atoi(mot)*Coeff[i]+sumNote;
		i++;
		}	
		}
		//si a==1 c-a-d que le matricule entré par l'utilistauer correspont bien à un etudiant trouvé dans le fichier  et sa moyenne est calculé
		if(a==1)
		{
		a=0; // on reinitialise le compteur a à O car on s'intresse que à la l'etudiant dont le matricule est entré
		}
	}
	/*partie affichage de resultat à l'ecrans*/
	if(sumNote!=0)
	printf("\n La Moyenne Generale est : %f",sumNote/(double)sumCoeffi);
    else
	printf("\n le Matricule ne Correspond a aucun etudiant.. Vielliez Enrer un Matricule Valide!!");
} 

/*La Fonction */

int main(){
	//les coeffitient ici enreé comme tableau 
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
    lireFichier("EtudiantResultat.csv",Coeffictients,6,Matricule);  //ici 6  est la somme des coeffitient juste pour facilité le calcule dans fonction
}
