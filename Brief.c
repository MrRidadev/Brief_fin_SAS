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
    char la_priorite [6];
     date date; //stracture imbriqué

}information;

//  fonctions Ajouter
information inf;
void ajouter(){
   
    printf("entrer titre: ");
    scanf("%s",inf.titre);
    printf("  entrer description: ");
    scanf(" %s",inf.description_de_la_tache);
    printf("entrer la_priorite(high, low): ");
    scanf("%s",inf.la_priorite);
    printf("entrer date annee:");
    scanf("%d",&inf.date.annee);
    printf("moin:");
    scanf("%d",&inf.date.moin);
    printf("jour:");
    scanf("%d",&inf.date.jour);
    

     if (inf.date.jour < 1 || inf.date.jour > 31 ||
        inf.date.moin < 1 || inf.date.moin > 12 ||
        inf.date.annee < 0) {
        printf("Date invalide, veuillez reessayer.\n");
        return;
    }

    printf("ajouter avec succes !");
}
// fonction afficher 
void afficher() {
    int choix ;
    if (choix==1)
    {
         printf("Titre: %s\n", inf.titre);
         printf("Description de la tache: %s\n", inf.description_de_la_tache);
         printf("priorite: %s\n", inf.la_priorite);
         printf("Date (jour/moin/annee): %d / %d / %d\n", inf.date.jour, inf.date.moin, inf.date.annee);
    }else{
        printf("erreur");
    }  
    
   
}
//fonction Modifier

void modifier() {
    printf("Entrer le nouveau titre :\n ");
    scanf("%s", inf.titre); 

    printf("Entrer la nouvelle description :\n ");
    scanf("%s", inf.description_de_la_tache); 

    printf("entrer la_priorite(h pour high, l pour low):\n");
    scanf("%c",&inf.la_priorite);

    printf("entrer date annee:");
    scanf("%d",&inf.date.annee);
    printf("moin:");
    scanf("%d",&inf.date.moin);
    printf("jour:");
    scanf("%d",&inf.date.jour);

    // Vérification basique des entrées
    if (inf.date.jour < 1 || inf.date.jour > 31 ||
        inf.date.moin < 1 || inf.date.moin > 12 ||
        inf.date.annee < 0) {
        printf("Date invalide, veuillez reessayer.\n");
        return;
    }

    printf("Tache modifiee avec succes !\n");
}
// fonction supprimier
void supprimier() {
    
    inf.titre[0] = '\0';  
    inf.description_de_la_tache[0] = '\0';
    inf.la_priorite [0] = '\0';
    inf.date.annee = 0;
    inf.date.moin = 0;
    inf.date.jour = 0;

    printf("La tache a ete supprimee avec succes !\n");
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
        case 2:afficher();
            break;
        case 3:modifier();
            break;
        case 4:supprimier();
            break;

        default:
            printf("Choix invalide, veuillez reessayer.\n");

    
        }
    } while (choix !=5);
    

}