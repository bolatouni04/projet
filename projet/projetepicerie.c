#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  _XPANIER 27
#define  _YPANIER 52

int main()
{
    char reponse[10];
    int nb_elem = 0;
    int i = 0;
    int y = 0;
    int x = 0;
    float prix = 0;
    char panier;
    float montant;
    float monnaie;

    system("clear");
    system("cat epicerie.txt");
    const char fruits[15][15] = {{"🍓"},{"🍇"},{"🍏"},{"🍎"},{"🍐"},{"🍊"},{"🍋"},{"🍌"},{"🍉"},{"🍈"},{"🍒"},{"🍑"},{"🥥"},{"🍍"},{"🥝"}};
    const char legumes[15][15] = {{"🍅"},{"🍆"},{"🥦"},{"🌽"},{"🥒"},{"🌶"},{"🥕"},{"🥔"},{"🍠"},{"🥑"},{"🍀"},{"🥜"},{"🌱"},{"🌿"},{"🍄"}};
    const char viandes[15][15] = {{"🍗"},{"🍖"},{"🥩"},{"🥓"},{"🍘"},{"🥫"},{"🍱"},{"🦐"},{"🐚"},{"🦀"},{"🐠"},{"🐟"},{"🍤"},{"🐡"},{"🐋"}};
    const char *PLFRUITS[] = {"F00","F01","F02","F03","F04","F05","F06","F07","F08","F09","F10","F11","F12","F13","F14"};
    const char *PLLEGUMES[] = {"L00","L01","L02","L03","L04","L05","L06","L07","L08","L09","L10","L11","L12","L12","L13","L14"};
    const char *PLVIANDES[] = {"V00","V01","V02","V03","V04","V05","V06","V07","V08","V09","V10","V11","V12","V12","V13","V14"};
    const float prixF[15] = {3.4 , 4.1 , 2.9 , 2.2 , 2, 3.1 , 1 , 2.5 , 3.8 , 2.5 , 2 , 1.6 , 1.8 , 3.7 , 1.5 };
    const float prixL[15] = {2.4 , 2.1 , 1.9 , 2.8 , 1.7 , 2.1 , 2.9 , 1.9 , 1.9 , 3.1 , 2.1 , 2.5 , 2.8 , 2.3 , 2.7};
    const float prixV[15] = {3.2 , 3.9 , 4.3 , 3.8 , 4.9 ,5 , 5.1 , 2.3 , 3.8 , 4 , 5.4 , 3.1 , 4.3 , 4.8 , 5.1};

    printf("\033[%d;%dH", 27, 22);
    
    while (nb_elem < 9) {
        scanf("%s", reponse);
        
        if (strcmp(reponse, "FIN") == 0)
            break; 
        for (int n = 0; n < 15; n++) {
            if (strcmp(reponse, PLFRUITS[n]) == 0) {

                //ici il faut gerer x et y (qui vont etre ajoute aux constantes du panier)
                printf("\033[%d;%dH", _XPANIER - x, _YPANIER + y);
                printf("%s", fruits[n]);
                fflush(stdout); 
                prix += prixF[n];
                nb_elem++;
                
                y = (nb_elem % 3) * 3;
                x = nb_elem / 3;
            } else if (strcmp(reponse, PLLEGUMES[n]) == 0) {

                //ici il faut gerer x et y (qui vont etre ajoute aux constantes du panier)
                printf("\033[%d;%dH", _XPANIER - x, _YPANIER + y);
                printf("%s", legumes[n]);
                fflush(stdout); 
                prix += prixF[n];
                nb_elem++;
                
                y = (nb_elem % 3) * 3;
                x = nb_elem / 3;
            } else if (strcmp(reponse, PLVIANDES[n]) == 0) {

                //ici il faut gerer x et y (qui vont etre ajoute aux constantes du panier)
                printf("\033[%d;%dH", _XPANIER - x, _YPANIER + y);
                printf("%s", viandes[n]);
                fflush(stdout); 
                prix += prixF[n];
                nb_elem++;
                
                y = (nb_elem % 3) * 3;
                x = nb_elem / 3;
            }
           
        }

        printf("\033[%d;%dH", 27, 22);
        i = 0;
        while (i < strlen(reponse)) {
            printf(" ");
            i++;
        }
    
        printf("\033[%d;%dH", 25, 90);
        fflush(stdout);
        printf("%.2f",prix);
        printf("\033[%d;%dH", 27, 22);  
    }
    // paiement
    //printf("%s\n", reponse);
    printf("\033[%d;%dH",26,96);
    fflush(stdout);
    scanf("%f",&montant);
    monnaie = montant-prix;
    printf("\033[%d;%dH",27,83);
    printf("%.2f €",monnaie);

    scanf("%s", reponse);

    return 0;
}