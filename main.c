#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Biblioteca.h"
///argv[0]=exec, argv[1]=input,argv[2]=rezgraf,argv[3]=rezscor
int main(int argc, char* argv[])
{
    FILE *f1=fopen(argv[1],"rt"),*f2=fopen(argv[2],"wt"),*f3=fopen(argv[3],"wt");
    testfis(f1);
    testfis(f2);
    testfis(f3);
    int nrech=32;
    Queue *q,*invins,*castig;
    echipa *copy;
    q=createQueue();
    invins=createQueue();
    castig=createQueue();
    coadaechfis(f1,&q,nrech);
    Graph *g=creareGraph(32);
    while(nrech>1)
    {
    while(castig->front!=NULL)
    {
        enQueue(q,castig->front);
        deQueue(castig);
    }
    while(q->front!=NULL)
    {
        copy=q->front;
        meci(copy,copy->next,invins,castig,g);
        deQueue(q);
        deQueue(q);
    }
    nrech=nrech/2;
    }
    printGraph(f2,g);
    printScor(f3,invins,castig);
    return 0;
}
