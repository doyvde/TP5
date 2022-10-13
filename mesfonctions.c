//
// Created by denis on 05/10/2022.
//
#include "mabiblio.h"

edge_list elist;
edge_list spanlist;

// Applying Krushkal Algo
void kruskalAlgo(int n, int Graph[MAX][MAX]) {
    int belongs[MAX], i, j, cno1, cno2;
    elist.n = 0;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }

    sort();

    for (i = 0; i < n; i++)
        belongs[i] = i;

    spanlist.n = 0;

    for (i = 0; i < elist.n; i++) {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);

        if (cno1 != cno2) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2,n);
        }
    }
}

int find(int belongs[], int vertexno) {
    return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2,int n) {
    int i;

    for (i = 0; i < n; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}

// Sorting algo
void sort() {
    int i, j;
    edge temp;

    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].w > elist.data[j + 1].w) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}

// Printing the result
void print() {
    int i, cost = 0;

    for (i = 0; i < spanlist.n; i++) {
        printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }

    printf("\nPoids Total: %d \n", cost);
}

//insere (som_b,poids) en tete dans la liste d’adjacence Adj[som_a]
void insere(int som_a, int som_b, int poids, LISTE Adj[]){
    LISTE prem= malloc(sizeof(LISTE));
    prem->nom = som_b;
    prem->poids = poids;
    prem->suiv = Adj[som_a];
    Adj[som_a] = prem;
}

//initialisation de la table d’adjacence : toutes les listes chainées sont vides
void initAdjGraphe(GRAPHE *G){
    int i;
    for(i = 0; i< G->nbSommets; i++){
        G->Adj[i] = NULL;
    }
}

//pour charger un graphe a partir d’un fichier
void litGraphe(const char *adr, GRAPHE *G ,int matrice[MAX][MAX]){
    FILE *f;
    int s,sa,sb,pds,nbArcs,i,j,temp;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            matrice[i][j]=0;
        }
    }

    f=fopen(adr,"r");

    if (f == NULL){
        printf("File is missing!");
        exit(1);
    }

    fscanf(f,"%d",&(G->nbSommets));
    temp=G->nbSommets;
    initAdjGraphe(G);
    while(G->nbSommets){
        fscanf(f,"%d",&s);
        G->nbSommets--;
    }
    G->nbSommets=temp;
    fscanf(f,"%d",&nbArcs);
    while(nbArcs){
        fscanf(f,"%d %d %d",&sa,&sb,&pds);
        matrice[sa][sb]=pds;
        matrice[sb][sa]=pds;
        insere(sa,sb,pds, G->Adj);
        nbArcs--;
    }
    fclose(f);
}

// affichage d’un graphe : le nombre de sommets, puischaque arc pondéré : (sommet_1, sommet_2, poids)
void afficheGraphe(GRAPHE G){
    int j;
    printf("Nb sommets: %d\n", G.nbSommets);

    for(j = 0; j < G.nbSommets; j++){
        MAILLON* tmp = G.Adj[j];
        while(tmp != NULL){
            printf(" (%d, %d, %d)\n",j, tmp->nom, tmp->poids);
            tmp = tmp->suiv;
        }
    }
}

void primAlgo(GRAPHE G, int matrice[MAX][MAX]){
    int no_edge;  // number of edge
    int poids=0;
    int j;
    int V=G.nbSommets;//initialisation du monbre de sommet
    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];
    // set selected false initially
    // memset( selected[V], sizeof(selected));

    for(j=0;j<V;j++)
    {
        selected[j]=false;
    }

    // set number of edge to 0
    no_edge = 0;

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    //graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x;  //  row number
    int y;  //  col number

    // print for edge and weight
    printf("\nBords : Poids\n");

    while (no_edge < V - 1) {
        //For every vertex in the set S, find the all adjacent vertices
        // , calculate the distance from the vertex selected at step 1.
        // if the vertex is already in the set S, discard it otherwise
        //choose another vertex nearest to selected vertex  at step 1.

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (j = 0; j < V; j++) {
                    if (!selected[j] && matrice[i][j]) {  // not in selected and there is an edge
                        if (min > matrice[i][j]) {
                            min = matrice[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, matrice[x][y]);
        poids=poids+matrice[x][y];
        selected[y] = true;
        no_edge++;
    }
    printf("Le poids total est de: %d \n",poids);//
}