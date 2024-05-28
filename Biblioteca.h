#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Echipa
{
    float punctaj;
    char *numech;
    struct Echipa *next;
};
typedef struct Echipa echipa;
struct Q{
echipa *front ,* rear ;
};
typedef struct Q Queue ;
echipa* createch(float punctaj,char *nume);
Queue * createQueue ();
void enQueue ( Queue *q, echipa* x);
int isEmpty ( Queue *q);
void deQueue ( Queue *q);
void coadaechfis(FILE *f1,Queue **q,int nrech);
void meci(echipa *ech1,echipa *ech2,Queue *invins,Queue *castig);
