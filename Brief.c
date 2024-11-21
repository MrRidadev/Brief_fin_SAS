#include <stdio.h>
typedef struct 
{
    int annee;
    int moin;
    int jour;
}date;

 typedef struct
{
    char titre [100];
    char  description_de_la_tache [225];
    char la_priorite;
     date date; //stracture imbriqué

}information;

//  fonctions Ajouter
void ajouter(){
    information inf;
    printf("entrer titre:\n");
    scanf("%s",&inf.titre);
    printf("entrer description:\n");
    scanf("%s",&inf.description_de_la_tache);
    printf("entrer date annee:\n");
    scanf("%i",&inf.date.annee);
    printf("moin:");
    scanf("%i",&inf.date.moin);
    printf("jour:");
    scanf("%i",&inf.date.jour);
}

int main(){
    int choix ;
   
    do
    {
        printf("\n ========= Menu =========== \n");
        printf("1-ajouter\n");
        printf("2- afficher\n");
        printf("3-modifier\n ");
        printf("4-Supprimer\n");
        printf("entrer le choix:\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:ajouter();
            break;
        
        default:
            break;
        }
    } while (choix !=0);
    

}