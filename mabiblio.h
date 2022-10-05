//
// Created by denis on 05/10/2022.
//

#ifndef TP5_MABIBLIO_H
#define TP5_MABIBLIO_H

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define NB_SOM_MAX 10 //nombre de sommets maximum
#define INF 9999999
#define MAX 30

//liste chainée de couples (sommet, poids)
typedef struct maillon{
    struct maillon *suiv;
    int nom;
    int poids;
} MAILLON, *LISTE;

//graph structure
typedef struct graphe{
    int nbSommets;
    LISTE Adj[NB_SOM_MAX]; //liste d'adjacence
} GRAPHE;


// Kruskal's algorithm in C
typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;


void insere(int som_a, int som_b, int poids, LISTE Adj[]);
void initAdjGraphe(GRAPHE *G);
void litGraphe(const char *adr, GRAPHE *G ,int matrice[MAX][MAX]);
void afficheGraphe(GRAPHE G);
void kruskalAlgo(int n, int Graph[MAX][MAX]);
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2, int n);
void sort();
void print();
void primAlgo(GRAPHE G, int matrice[MAX][MAX]);

#endif //TP5_MABIBLIO_H
