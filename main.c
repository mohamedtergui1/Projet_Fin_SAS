#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#define d "finalisee"
#define td "realiser"
#define doo "a realiser"

typedef struct{
      int jour;
      int heurs;
      int minute;
}daate;
typedef struct{
     daate date;
     int codeId;
     char titre[50];
     char description[1000];
     char statut[13];
}Taches;
void menuPrincipal(){
    system("cls");
      printf("=======================================================================================                                                   Menu Principal\n=======================================================================================");
      printf("\n1-Ajouter une nouvelle tache");
      printf("\n2-Ajouter plusieurs nouvelles taches");
      printf("\n3-Afficher la liste de toutes les taches");
      printf("\n4-Modifier une tache");
      printf("\n5-Supprimer une tache par identifiant");
      printf("\n6-Rechercher les Taches");
      printf("\n7-Statistiques");
      printf("\n8-quittet");
            printf("\n========================================================================================                                                   entree ton Choi:");
            int n;
            scanf("%d",&n);
            printf("==========================================================================================\n");

        sMenu(n);
}
void sMenu(int n){
    system("cls");
         switch(n){
           case 1 : Ajouter_une_tache();break;
           case 2 : Ajouter_plusieurs_taches();break;
           case 3 : Afficher_les_tache();break;
           case 4 : Modifier_une_tache();break;
           case 5 : Supprimer_identifiant();break;
           case 6 : Rechercher_Taches();break;
           case 7 : Statistiques();break;
           case 8 : return 0;break;
           default : printf("\ntu ai entrée un movie choi!!!");return 0;

         }
}
Ajouter_une_tache(){
           FILE *file = fopen("taches.txt", "a");
           Taches tacheA;
           if (file == NULL) {
    printf( "\nil ya une erreur !");
    fclose(file);
}
          printf("\n=======================================================================================                                                   Ajouter une nouvelle tache\n=======================================================================================");
          printf("\nentrer code id de tache:");scanf("%d",&tacheA.codeId);
          printf("entrer le titre de tache:");scanf(" %[^\n]", &tacheA.titre);
          printf("entrer le description de tache:");scanf(" %[^\n]", &tacheA.description);
          printf("entrer deadline de tache  ce formme => jj/hh/mm :");scanf("%d/%d/%d",&tacheA.date.jour,&tacheA.date.heurs,&tacheA.date.minute);
          int m;
          printf("1=>realiser\n2=>a realiser\n3=>finalisee");
          printf("\nchoisir une statue:");scanf("%d",&m);
          switch(m){
             case 1 :strcpy(tacheA.statut,td);break;
             case 2 :strcpy(tacheA.statut,d);break;
             case 3 :strcpy(tacheA.statut,doo);break;
          }
            fflush(file);
          fprintf(file, "%d\n%s\n%s\n%d\n%d\n%d\n%s\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);
          fclose(file);
          int o;
        printf("\n1-go to menu principal:");scanf("%d",&o);
        if(o==1)menuPrincipal();else return 0;
}
Ajouter_plusieurs_taches(){
       FILE *file = fopen("taches.txt", "a");
           Taches tacheA;
            if (file == NULL) {
    printf( "\nil ya une erreur !");
    fclose(file);
}
      fflush(file);
                  printf("\n=======================================================================================                                                   Ajouter plusieurs nouvelles  tache\n=======================================================================================");
          int m;
        printf("\nentree le nombre de taches tu veux te ajoutee:");scanf("%d",&m);

        for (int i=1;i<=m;i++){

             printf("\nentrer code id de tache %d:",i);scanf("%d",&tacheA.codeId);
          printf("entrer le titre de tache %d:",i);scanf(" %[^\n]", tacheA.titre);
          printf("entrer le description de tache %d:",i);scanf(" %[^\n]", tacheA.description);
          printf("entrer deadline de tache %d ce formme => jj/hh/mm :",i);scanf("%d/%d/%d",&tacheA.date.jour,&tacheA.date.heurs,&tacheA.date.minute);
          int n;
          printf("1=>realiser\n2=>a realiser\n3=>finalisee");
          printf("\nchoisir une statue de tache %d:",i);scanf("%d",&n);
          switch(n){
             case 1 :strcpy(tacheA.statut,td);break;
             case 2 :strcpy(tacheA.statut,d);break;
             case 3 :strcpy(tacheA.statut,doo);break;
          }

          fprintf(file, "%d\n%s\n%s\n%d\n%d\n%d\n%s\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);


        }

     fclose(file);

           int o;
        printf("\n1-go to menu principal:");scanf("%d",&o);
        if(o==1)menuPrincipal();else return 0;
}
Afficher_les_tache(){
            FILE *file = fopen("taches.txt", "r");
           Taches tacheA;
           if (file == NULL) {
    printf(file, "\nil ya une erreur !");
    fclose(file);
}
  rewind(file);
    printf("\n=======================================================================================\n                                                   Afficher les tache\n=======================================================================================\n");
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
     while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");

    }

    fclose(file);
        int o;
        printf("\n1-Trier les tâches par ordre alphabetique");
        printf("\n2-Trier les tâches par deadline");
        printf("\n3-Afficher les tâches dont le deadline est dans 3 jours ou moins");
        printf("\naller au menu principal");
        printf("\nentree votre choi :");scanf("%d",&o);
        if(o==1)trier_alpha();
        if(o==2)trier_deadline();
        if(o==3)jour_deadline();
        if(o==4)menuPrincipal();
        else return ;
}
Modifier_une_tache(){
   FILE *file = fopen("taches.txt", "r");
   FILE *temp = fopen("temp.txt", "w");
           Taches tacheA;
           if (file == NULL) {
    printf( "\nil ya une erreur !");
    fclose(file);
}
     rewind(file);

      int n;
           printf("=======================================================================================                                                   Modifier une tache:\n=======================================================================================\n");
           printf("\nentree le code de tache tu veux te modifie:");scanf("%d",&n);
        while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {
                if (tacheA.codeId==n){
          printf("entrer nouvelle le titre de tache:");scanf(" %[^\n]", &tacheA.titre);
          printf("entrer nouvelle le description de tache:");scanf(" %[^\n]", &tacheA.description);
          printf("entrer nouvelle deadline de tache  ce formme => jj/hh/mm :");scanf("%d/%d/%d",&tacheA.date.jour,&tacheA.date.heurs,&tacheA.date.minute);
          int m;
          printf("1=>realiser\n2=>a realiser\n3=>finalisee");
          printf("\nchoisir une nouvelle statue:");scanf("%d",&m);
          switch(m){
             case 1 :strcpy(tacheA.statut,td);break;
             case 2 :strcpy(tacheA.statut,d);break;
             case 3 :strcpy(tacheA.statut,doo);break;
          }
                }
           fprintf(temp, "%d\n%s\n%s\n%d\n%d\n%d\n%s\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);

        }
        fclose(file);
        fclose(temp);
        remove("taches.txt");
        rename("temp.txt","taches.txt");


          int o;
        printf("\n1-go to menu principal:");scanf("%d",&o);
        if(o==1)menuPrincipal();else return 0;
}
Supprimer_identifiant(){
    FILE *file = fopen("taches.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
           Taches tacheA;
           if (file==NULL) {
    printf("\nil ya une erreur !");
    fclose(file);
  }
    if (temp==NULL) {
    printf("\nil ya une erreur !");
    fclose(temp);
  }
     rewind(file);
      int n,a=0;
           printf("=======================================================================================                                                   Modifier une tache:\n=======================================================================================\n");
           printf("\nentree le code de tache tu veux te spprimer:");scanf("%d",&n);
        while (!feof(file)) {
                fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut);
                if (n!=tacheA.codeId){
            fprintf(temp, "%d\n%s\n%s\n%d\n%d\n%d\n%s\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);
        }
        else continue;
        }

        fclose(file);
        fclose(temp);
        remove("taches.txt");
        rename("temp.txt","taches.txt");

         int o;
        printf("\n1-go to menu principal:");scanf("%d",&o);
        if(o==1)menuPrincipal();else return ;
    }
Rechercher_Taches(){}
Statistiques(){}






void trier_alpha(){
    system("cls");
     FILE *file = fopen("taches.txt", "r");
           Taches *tacheA;
           if (file == NULL) {
    printf( "\nil ya une erreur !");
    fclose(file);
}
  rewind(file);
         tacheA=(Taches*)malloc(100*sizeof(Taches));
         Taches tmptache;
          int n =0;
       while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA[n].codeId, tacheA[n].titre, tacheA[n].description, &tacheA[n].date.jour, &tacheA[n].date.heurs, &tacheA[n].date.minute, tacheA[n].statut) == 7) {
          n++;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){

             if (strcmp(tacheA[i].titre,tacheA[j].titre)>0){
                               // strcpy(tacheA[j].titre,tacheA[i].titre);
                                //strcpy(tacheA[i].titre,tmpchar);
                                tmptache=tacheA[i];
                                tacheA[i]=tacheA[j];
                                tacheA[j]=tmptache;
                             }
        }
    }


     printf("\n=======================================================================================\n                                                   Afficher les tache\n=======================================================================================\n");
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
    for (int i=0;i<n;i++){
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA[i].codeId, tacheA[i].titre, tacheA[i].description, tacheA[i].date.jour, tacheA[i].date.heurs, tacheA[i].date.minute, tacheA[i].statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");

    }
    free(tacheA);
   fclose(file);
      int o;
        printf("\n1-go to menu principal:");scanf("%d",&o);
        if(o==1)menuPrincipal();else return ;
}


trier_deadline(){    system("cls");
     FILE *file = fopen("taches.txt", "r");
           Taches *tacheA;
           if (file == NULL) {
    printf( "\nil ya une erreur !");
    fclose(file);
}
  rewind(file);
         tacheA=(Taches*)malloc(100*sizeof(Taches));
         Taches tmptache;
          int n =0;
       while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA[n].codeId, tacheA[n].titre, tacheA[n].description, &tacheA[n].date.jour, &tacheA[n].date.heurs, &tacheA[n].date.minute, tacheA[n].statut) == 7) {
          n++;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){

             if (tacheA[n].date.jour<tacheA[j].date.jour){
                                tmptache=tacheA[i];
                                tacheA[i]=tacheA[j];
                                tacheA[j]=tmptache;
                             }
              else if (tacheA[n].date.heurs<tacheA[j].date.heurs&&tacheA[n].date.jour==tacheA[j].date.jour)   {
                                tmptache=tacheA[i];
                                tacheA[i]=tacheA[j];
                                tacheA[j]=tmptache;
              }
              else if (tacheA[n].date.minute<tacheA[j].date.minute&&tacheA[n].date.heurs==tacheA[j].date.heurs&&tacheA[n].date.jour==tacheA[j].date.jour){
                                tmptache=tacheA[i];
                                tacheA[i]=tacheA[j];
                                tacheA[j]=tmptache;
              }
        }
    }


     printf("\n=======================================================================================\n                                                   Afficher les tache\n=======================================================================================\n");
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
    for (int i=0;i<n;i++){
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA[i].codeId, tacheA[i].titre, tacheA[i].description, tacheA[i].date.jour, tacheA[i].date.heurs, tacheA[i].date.minute, tacheA[i].statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");

    }
    free(tacheA);
   fclose(file);
      int o;
        printf("\n1-go to menu principal:");scanf("%d",&o);
        if(o==1)menuPrincipal();else return ;}

jour_deadline(){}

int main()
{
    menuPrincipal();
    return 0;
}
