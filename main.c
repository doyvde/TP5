#include "mabiblio.h"

///source : https://openclassrooms.com/forum/sujet/implementation-algorithme-de-dijkstra
///source : https://www.programiz.com/dsa/dijkstra-algorithm
///source : https://www.programiz.com/dsa/kruskal-algorithm
///source : https://www.programiz.com/dsa/prim-algorithm
///source : mon TP3



//main
int main(){
    GRAPHE G;// declaration du graphe
    int matrice[MAX][MAX];//declaratio de la matrice



    int option;
    printf("Que voulez vous faire ? \n");//
    printf("1- Krushkal\n");//
    printf("2- Prim\n");//
    scanf("%d", &option);//
    printf("\n");//

    litGraphe("graphe.txt", &G,matrice);// lecture du fichier et creation du graphe sous morme matricielle et de liste
    afficheGraphe(G);//affichage des donnes du graphe
    int n=G.nbSommets;//initialisation du monbre de sommet



    switch (option)//
    {
        //1 - État du jeu
        case 1:
            kruskalAlgo(n,matrice);
            print();
            break;//

            //2 - Acheter une propriété
        case 2:
            primAlgo(G,matrice);
            break;//



            //option Invalide
        default://
            printf("Erreur! Veuillez saisir une option valide : ");//
            fflush(stdin);//
            break;//
    }



    return 0;
}
