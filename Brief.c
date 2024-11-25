#include <stdio.h>

typedef struct {
    int annee;
    int moin;
    int jour;
} date;

typedef struct {
    char titre[100];
    char description_de_la_tache[225];
    int la_priorite;
    date date; // Structure imbriquée
} information;

information inf[20];
int taille = 0;

// Fonction Ajouter
void ajouter() {
    printf("Entrer titre: ");
    scanf("%s", inf[taille].titre);
    printf("Entrer description: ");
    scanf("%s", inf[taille].description_de_la_tache);
    
    do
    {
       printf("Entrer la priorite (1 pour high, 2 pour low): ");
        scanf("%d", &inf[taille].la_priorite);
    } while (inf[taille].la_priorite!=1 && inf[taille].la_priorite!=2);
    

    do
    {
        printf("Entrer date annee: ");
    scanf("%d", &inf[taille].date.annee);
    printf("Mois: ");
    scanf("%d", &inf[taille].date.moin);
    printf("Jour: ");
    scanf("%d", &inf[taille].date.jour);
    } while (inf[taille].date.jour < 1 || inf[taille].date.jour > 31 ||
        inf[taille].date.moin < 1 || inf[taille].date.moin > 12 ||
        inf[taille].date.annee < 0);
    
        taille++;
        printf("Ajoute avec succes !\n");
    
}

// Fonction Afficher
void afficher() {
    for (int i = 0; i < taille; i++) {
        printf("=====La tache%d ===== \n", i + 1);
        printf("Titre: %s\n", inf[i].titre);
        printf("Description de la tache: %s\n", inf[i].description_de_la_tache);
        
        if (inf[i].la_priorite== 1)
        {
            printf("la priorite: high\n");
        }else  
        {
            printf("la priorite: low \n");
        }
        
        printf("Date (JJ/MM/AAAA): %d / %d / %d\n", inf[i].date.jour, inf[i].date.moin, inf[i].date.annee);
    }
}

// fonction Filtrer 
void filtrer(){
    int p,i;

do
    {
       printf("entrer prioriter (1 pour high ou 2 pour low) pour filtrer:\n " );
        scanf("%d",&p);
    } while (p!=1 && p!=2);

for ( i = 0; i < taille; i++)
{
    if (inf[i].la_priorite==p)
    {
        printf("Titre: %s\n", inf[i].titre);
        printf("Description de la tache: %s\n", inf[i].description_de_la_tache);
         if (inf[i].la_priorite== 1)
        {
            printf("la priorite: high\n");
        }else  
        {
            printf("la priorite: low \n");
        }
        
        
        printf("Date (JJ/MM/AAAA): %d / %d / %d\n", inf[i].date.jour, inf[i].date.moin, inf[i].date.annee);
    }
    
}

}

// Fonction Modifier
void modifier(int index) {
    if (index >= 0 && index < taille) {
        printf("Entrer le nouveau titre: ");
        scanf("%s", inf[index].titre);
        printf("Entrer la nouvelle description: ");
        scanf("%s", inf[index].description_de_la_tache);
        printf("Entrer la priorite (1 pour high, 2 pour low): ");
        scanf("%d", &inf[index].la_priorite);
        printf("Entrer date annee: ");
        scanf("%d", &inf[index].date.annee);
        printf("Mois: ");
        scanf("%d", &inf[index].date.moin);
        printf("Jour: ");
        scanf("%d", &inf[index].date.jour);

        if (inf[index].date.jour < 1 || inf[index].date.jour > 31 ||
            inf[index].date.moin < 1 || inf[index].date.moin > 12 ||
            inf[index].date.annee < 0) {
            printf("Date invalide, veuillez reessayer.\n");
        } else {
            printf("Tache modifiee avec succes !\n");
        }
    } else {
        printf("Index invalide !\n");
    }
}

// Fonction Supprimer
void supprimier(int index) {
    if (index < 0 || index >= taille) {
        printf("Index invalide, impossible de supprimer !\n");
    } else {
        for (int i = index; i < taille - 1; i++) {
            inf[i] = inf[i + 1];
        }
        taille--;
        printf("La tache a ete supprimee avec succes !\n");
    }
}

int main() {
    int choix;
    int index;

    do {
        printf("\n ========= Menu =========== \n");
        printf("1 - Ajouter\n");
        printf("2 - Afficher\n");
        printf("3 - Modifier\n");
        printf("4 - Supprimer\n");
        printf("5 - Filtrer\n");
        printf("6 - Quitter\n");
        printf("Entrer le choix: ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            ajouter();
            break;
        case 2:
            afficher();
            break;
        case 3:
            printf("Entrer l'index de la tache a modifier: ");
            scanf("%d", &index);
            if (index < 1 || index > taille) {
                printf("Index invalide !\n");
            } else {
                modifier(index - 1);
            }
            break;
        case 4:
            printf("Entrer l'index de la tache a supprimer: ");
            scanf("%d", &index);
            if (index < 1 || index > taille) {
                printf("Index invalide !\n");
            } else {
                supprimier(index - 1);
            }
            break;
        case 5:filtrer();
        break;
        case 6:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 7);

    return 0;
}
