#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#define d "finalisee"
#define td "realiser"
#define doo "a realiser"
#include<time.h>
#include<conio.h>
    time_t currentTime;
    struct tm *timeInfo;
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

int fonction_de_vExisstence(int id){
    FILE *file = fopen("taches.txt", "r");
           Taches tacheA;
           if (file == NULL) {
    printf( "\nil ya une erreur !");
    fclose(file);
}
rewind(file);
    int x=0;
  while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {
            if(tacheA.codeId==id)
             x++;
     }
     fclose(file);
    return x;
}

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
     time(&currentTime);
    timeInfo = localtime(&currentTime);
     int day = timeInfo->tm_mday;
    int hour = timeInfo->tm_hour;
    int minute = timeInfo->tm_min;
          printf("\n==================================================================================================================                                                   Ajouter une nouvelle tache\n==================================================================================================================");
          printf("\nentrer code id de tache:");scanf("%d",&tacheA.codeId);
           while(fonction_de_vExisstence(tacheA.codeId)!=0){
            printf("\ncode id de tache  il ai exist entre autre code id:");scanf("%d",&tacheA.codeId);
           }
          printf("entrer le titre de tache:");scanf(" %[^\n]", &tacheA.titre);
          printf("entrer le description de tache:");scanf(" %[^\n]", &tacheA.description);
          printf("entrer deadline de tache  ce formme => jj/hh/mm :");scanf("%d/%d/%d",&tacheA.date.jour,&tacheA.date.heurs,&tacheA.date.minute);
          while(tacheA.date.jour<0||tacheA.date.heurs<0||tacheA.date.minute<0){
             printf("entrer time positive de tache  ce formme => jj/hh/mm :");scanf("%d/%d/%d",&tacheA.date.jour,&tacheA.date.heurs,&tacheA.date.minute);
          }
          int m;
          printf("1=>realiser\n2=>a realiser\n3=>finalisee");
          printf("\nchoisir une statue:");scanf("%d",&m);
          switch(m){
             case 1 :strcpy(tacheA.statut,td);break;
             case 2 :strcpy(tacheA.statut,d);break;
             case 3 :strcpy(tacheA.statut,doo);break;
          }
            fflush(file);
          fprintf(file, "%d\n%s\n%s\n%d\n%d\n%d\n%s\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour+day+(tacheA.date.heurs+hour+(tacheA.date.minute+minute)/60)/24, (tacheA.date.heurs+hour+(tacheA.date.minute+minute)/60)%24, (tacheA.date.minute+minute)%60, tacheA.statut);
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
                  printf("\n===============================================================================================================                                                   Ajouter plusieurs nouvelles  tache\n===============================================================================================================");
          int m;
        printf("\nentree le nombre de taches tu veux te ajoutee:");scanf("%d",&m);
     time(&currentTime);
    timeInfo = localtime(&currentTime);
     int day = timeInfo->tm_mday;
    int hour = timeInfo->tm_hour;
    int minute = timeInfo->tm_min;
        for (int i=1;i<=m;i++){

             printf("\nentrer code id de tache %d:",i);scanf("%d",&tacheA.codeId);
              while(fonction_de_vExisstence(tacheA.codeId)!=0){
            printf("\ncode id de tache %d il ai exist entre autre code id:",i);scanf("%d",&tacheA.codeId);
           }
          printf("entrer le titre de tache %d:",i);scanf(" %[^\n]", tacheA.titre);
          printf("entrer le description de tache %d:",i);scanf(" %[^\n]", tacheA.description);
          printf("entrer deadline de tache %d ce formme => jj/hh/mm :",i);scanf("%d/%d/%d",&tacheA.date.jour,&tacheA.date.heurs,&tacheA.date.minute);
          while(tacheA.date.jour<0||tacheA.date.heurs<0||tacheA.date.minute<0){
             printf("entrer time positive de tache %d ce formme => jj/hh/mm :",i);scanf("%d/%d/%d",&tacheA.date.jour,&tacheA.date.heurs,&tacheA.date.minute);
          }
          int n;
          printf("1=>realiser\n2=>a realiser\n3=>finalisee");
          printf("\nchoisir une statue de tache %d:",i);scanf("%d",&n);
          switch(n){
             case 1 :strcpy(tacheA.statut,td);break;
             case 2 :strcpy(tacheA.statut,d);break;
             case 3 :strcpy(tacheA.statut,doo);break;
          }

          fprintf(file, "%d\n%s\n%s\n%d\n%d\n%d\n%s\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour+day+(tacheA.date.heurs+hour+(tacheA.date.minute+minute)/60)/24, (tacheA.date.heurs+hour+(tacheA.date.minute+minute)/60)%24, (tacheA.date.minute+minute)%60, tacheA.statut);


        }

     fclose(file);

           int o;
        printf("\n1-go to menu principal:");scanf("%d",&o);
        if(o==1)menuPrincipal();else return 0;
}

Afficher_les_tache(){
     time(&currentTime);
    timeInfo = localtime(&currentTime);
     int day= timeInfo->tm_mday;
    int hour = timeInfo->tm_hour;
     int minute = timeInfo->tm_min;
            FILE *file = fopen("taches.txt", "r");
           Taches tacheA;
           if (file == NULL) {
    printf(file, "\nil ya une erreur !");
    fclose(file);
}
  rewind(file);
    printf("\n=======================================================================================================================\n                                                   Afficher les tache\n=======================================================================================================================\n");
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
     while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA.codeId, tacheA.titre, tacheA.description,abs(tacheA.date.jour-day), abs(tacheA.date.heurs-hour), abs(tacheA.date.minute-minute), tacheA.statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");

    }

    fclose(file);
        int o;
        printf("\n1-Trier les taches par ordre alphabetique");
        printf("\n2-Trier les taches par deadline");
        printf("\n3-Afficher les taches dont le deadline est dans 3 jours ou moins");
        printf("\n4-aller au menu principal");
        printf("\nentree votre choi :");scanf("%d",&o);
        if(o==1)trier_alpha();
        if(o==2)trier_deadline();
        if(o==3)jour_deadline_3jour();
        if(o==4)menuPrincipal();
        else return ;
}

Modifier_une_tache(){
    time(&currentTime);
    timeInfo = localtime(&currentTime);
     int day= timeInfo->tm_mday;
    int hour = timeInfo->tm_hour;
     int minute = timeInfo->tm_min;
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

Rechercher_Taches(){
          FILE *file = fopen("taches.txt", "r");
           Taches tacheA;
           if (file == NULL) {
    printf(file, "\nil ya une erreur !");
    fclose(file);
}
rewind(file);
  char *tmp;  tmp=(char*)malloc(50*sizeof(char));

   printf("\nentree le =>titer de tache  au le =>codeId de tache:"); scanf("%s",tmp);



int p =strlen(tmp);

   if( atoi(tmp)!=NULL&&p<4){

    printf("\n========================================================================================================================\n                                                Afficher Rechercher Taches <<%s>>\n========================================================================================================================\n",tmp);
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
     while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {

            if(tacheA.codeId==atoi(tmp)){
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");
     }
    }
   }
     else {
            printf("\n=======================================================================================\n                                                   Afficher Rechercher Taches <<%s>>\n=======================================================================================\n",tmp);
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
     while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {

            if(strncmp(tmp,tacheA.titre,p)==0){
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");
    }
    }
     }
    fclose(file);
        int o;
         printf("\n1-go to menu principal:");scanf("%d",&o);
        if(o==1)menuPrincipal();else return 0;
}

Statistiques(){
  printf("\n=======================================================================================                                                   Statistiques\n=======================================================================================");
   printf("\n1-Afficher le nombre total des taches");
   printf("\n2-Afficher le nombre de taches completes et incompletes.");
   printf("\n3-Afficher le nombre de jours restants jusqu'au délai de chaque tâche.");
   printf("\n4->aller au menu principal");
   int n;
   printf("\n=>entrer votre choi:");scanf("%d",&n);
   switch(n){
      case 1: nomber_total_des_taches();break;
      case 2: nomber_des_taches_incompletes();break;
      case 3: nomber_de_jeur_restants();break;
      case 4: menuPrincipal();break;
      default : printf("tu ai entrer yne movie choi!!");
   }

}

nomber_total_des_taches(){
    system("cls");
  FILE *file = fopen("taches.txt", "r");
           Taches tacheA;
           if (file == NULL) {
    printf(file, "\nil ya une erreur !");
    fclose(file);
}
  rewind(file);
  int x=0;
    printf("\n=======================================================================================\n                                                   Afficher les tache\n=======================================================================================\n");
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
     while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {

        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");
      x++;
    }
     printf("\nle total taches egal = %d",x);
    fclose(file);
    Statistiques();
    }

nomber_des_taches_incompletes(){
     FILE *file = fopen("taches.txt", "r");
           Taches tacheA;
           if (file == NULL) {
    printf(file, "\nil ya une erreur !");
    fclose(file);
}
  rewind(file);
  int x=0,y=0;
    printf("\n============================================================================================================\n                                                   Afficher les tache non complet\n============================================================================================================\n");
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
     while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {
     if(strcmp(tacheA.statut,td)==0||strcmp(tacheA.statut,doo)==0){
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");
      x++;
     }
     else y++;
    }
     printf("\nle total taches non complet est; egal = %d",x);
     printf("\nle total taches  complet est; egal = %d",y);
    fclose(file);
    Statistiques();}

nomber_de_jeur_restants(){
    system("cls");
     time(&currentTime);
    timeInfo = localtime(&currentTime);
     int day= timeInfo->tm_mday;
    int hour = timeInfo->tm_hour;
     int minute = timeInfo->tm_min;
            FILE *file = fopen("taches.txt", "r");
           Taches tacheA;
           if (file == NULL) {
    printf(file, "\nil ya une erreur !");
    fclose(file);
}
  rewind(file);
    printf("\n=======================================================================================================================\n                                                   Afficher les tache\n=======================================================================================================================\n");
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
     while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA.codeId, tacheA.titre, tacheA.description,abs(tacheA.date.jour-day), abs(tacheA.date.heurs-hour), abs(tacheA.date.minute-minute), tacheA.statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");

    }


    fclose(file);
    Statistiques();
}

void trier_alpha(){
    system("cls");
    time(&currentTime);
    timeInfo = localtime(&currentTime);
     int day= timeInfo->tm_mday;
    int hour = timeInfo->tm_hour;
     int minute = timeInfo->tm_min;
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

             if (strcmp(tolower(tacheA[i].titre),tolower(tacheA[j].titre))>0){
                               // strcpy(tacheA[j].titre,tacheA[i].titre);
                                //strcpy(tacheA[i].titre,tmpchar);
                                tmptache=tacheA[i];
                                tacheA[i]=tacheA[j];
                                tacheA[j]=tmptache;
                             }
        }
    }


     printf("\n=======================================================================================\n                                                   Trier les taches par ordre alphabetique\n=======================================================================================\n");
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
        printf("\n1-Trier les taches par ordre alphabetique");
        printf("\n2-Trier les taches par deadline");
        printf("\n3-Afficher les taches dont le deadline est dans 3 jours ou moins");
        printf("\n4-aller au menu principal");
        printf("\n=>entree votre choi :");scanf("%d",&o);
        if(o==1)trier_alpha();
        if(o==2)trier_deadline();
        if(o==3)jour_deadline_3jour();
        if(o==4)menuPrincipal();
        else return ;
}

trier_deadline(){
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

             if (tacheA[n].date.jour<tacheA[j].date.jour){
                                tmptache=tacheA[i];
                                tacheA[i]=tacheA[j];
                                tacheA[j]=tmptache;
                             }
              else if (tacheA[n].date.jour==tacheA[j].date.jour){
                    if (tacheA[n].date.heurs<tacheA[j].date.heurs){
                                tmptache=tacheA[i];
                                tacheA[i]=tacheA[j];
                                tacheA[j]=tmptache;
                    }
                    else if (tacheA[n].date.heurs==tacheA[j].date.heurs){
                    if (tacheA[n].date.minute<tacheA[j].date.minute){
                                tmptache=tacheA[i];
                                tacheA[i]=tacheA[j];
                                tacheA[j]=tmptache;
                    }
              }
              }
            }
    }
     printf("\n=======================================================================================\n                                                   Trier les taches par deadline\n=======================================================================================\n");
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
        printf("\n1-Trier les taches par ordre alphabetique");
        printf("\n2-Trier les taches par deadline");
        printf("\n3-Afficher les taches dont le deadline est dans 3 jours ou moins");
        printf("\n4-aller au menu principal");
        printf("\n=>nentree votre choi :");scanf("%d",&o);
        if(o==1)trier_alpha();
        if(o==2)trier_deadline();
        if(o==3)jour_deadline_3jour();
        if(o==4)menuPrincipal();
        else return ;
        }
    DZN(){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("      chargement.......\n\n\n\n\n\n");


        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        for(int i=-1;i<=4;i++){
   printf("                             ");
        for (int j=35;j >-35;j--){

            if (i<abs(j)/3)printf("*");

            else printf(" ");
             if(j%2==0)SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            else SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            for(double s ;s<999999;s++){}
        }

        printf("\n");
    }
    printf("                             ");
       printf("*******************        ");
       SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
       printf("#gestion des taches#");
       SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
         printf("    *******************\n");
    for(int i=4;i>=-1;i--){
   printf("                             ");

        for (int j=35;j>-35;j--){

            if (i<abs(j)/3)printf("*");
            else printf(" ");
            if(j%2==0)SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            else SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            for(double s ;s<999999;s++){}

        }
        Sleep(5);
        printf("\n");
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("\n\n\n\n\n\n            cliquez sur n'importe quelle touche pour passer:");

    }
jour_deadline_3jour(){
    system("cls");
    time(&currentTime);
    timeInfo = localtime(&currentTime);
     int day= timeInfo->tm_mday;

          FILE *file = fopen("taches.txt", "r");
           Taches tacheA;
           if (file == NULL) {
    printf(file, "\nil ya une erreur !");
    fclose(file);
}
  rewind(file);
    printf("\n===================================================================================================================\n                                                   Afficher les tache de deadline inferieur 3 jour\n===================================================================================================================\n");
    printf("\n_______________________________________________________________________________________________________________________\n");
    printf("|ID|           titre    |                   discription                                         |deadline |   status  |");
    printf("\n|__|____________________|_______________________________________________________________________|_________|___________|\n");
     while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]\n", &tacheA.codeId, tacheA.titre, tacheA.description, &tacheA.date.jour, &tacheA.date.heurs, &tacheA.date.minute, tacheA.statut) == 7) {
        if(tacheA.date.jour-day<=3){
        printf("|%2d|%-20s|%-71s|%02d-%02d-%02d |%-11s|\n", tacheA.codeId, tacheA.titre, tacheA.description, tacheA.date.jour, tacheA.date.heurs, tacheA.date.minute, tacheA.statut);
        printf("|__|____________________|_______________________________________________________________________|_________|___________|\n");
        }
    }

    fclose(file);
        int o;
        printf("\n1-Trier les taches par ordre alphabetique");
        printf("\n2-Trier les taches par deadline");
        printf("\n3-Afficher les taches dont le deadline est dans 3 jours ou moins");
        printf("\n4-aller au menu principal");
        printf("\n=>entree votre choi :");scanf("%d",&o);
        if(o==1)trier_alpha();
        if(o==2)trier_deadline();
        if(o==3)jour_deadline_3jour();
        if(o==4)menuPrincipal();
        else return ;
}
int main()
{
    DZN();
   getch();
    menuPrincipal();
    return 0;
}
