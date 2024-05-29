#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct Echipa
{
    float punctaj;
    char *numech;
    int pozitie;
    int r;
    struct Echipa *next;
};
typedef struct Echipa echipa;
struct Q{
echipa *front ,* rear ;
};
typedef struct Q Queue ;
typedef struct Node
{
    int **a;
    int V;
}Graph;

echipa* createch(float punctaj,char *nume,int n);
Queue * createQueue ();
void enQueue ( Queue *q, echipa* x);
int isEmpty ( Queue *q);
void deQueue ( Queue *q);
void coadaechfis(FILE *f1,Queue **q,int nrech);
void meci(echipa *ech1,echipa *ech2,Queue *invins,Queue *castig,Graph *g);
Graph* creareGraph(int V);
void printGraph ( FILE *f2,Graph *g);
float calcul(int r, int l);
void testfis(FILE *f);
void printScor(FILE *f3,Queue *invins,Queue *castig);
