#include "Biblioteca.h"
echipa* createch(float punctaj,char *nume)
{
    echipa *membru=(echipa*)malloc(sizeof(echipa));
    if(membru==NULL)
    {
        printf("Alocarea a esuat");
        exit(1);
    }
    membru->punctaj=punctaj;
    membru->numech=malloc((strlen(nume)+1)*sizeof(char));
    strcpy(membru->numech,nume);
    return membru;
}
Queue * createQueue ()
{
    Queue *q;
    q=( Queue *) malloc ( sizeof ( Queue ));
    if (q== NULL ) return NULL ;
    q->front =q->rear=NULL ;
    return q;
}
void enQueue ( Queue *q, echipa* x)
{
    echipa* newNode=(echipa*)malloc(sizeof(echipa));
    *newNode=*x;
    newNode->next= NULL ;
    if (q->rear == NULL ) q->rear = newNode ;
    else
    {
        (q->rear)->next = newNode ;
        (q->rear)=newNode ;
    }
    if (q->front == NULL ) q->front =q->rear ;
}
int isEmpty ( Queue *q)
{
    return (q->front == NULL );
}
void deQueue ( Queue *q)
{
    echipa *aux;
    if ( isEmpty (q)) return;
    aux=q->front ;
    q->front =(q->front)->next ;
    if(q->front==NULL)
        q->rear=NULL;
    free (aux );
}
void coadaechfis(FILE *f1,Queue **q,int nrech)
{
    float punctaj;
    char a,*numech;
    echipa *ech;
    int i;
    numech=(char*)malloc(sizeof(char)*50);
    for(i=0;i<nrech;i++)
    {
        ech=NULL;
        numech=(char*)realloc(numech,50);
        fscanf(f1,"%f",&punctaj);
        fscanf(f1,"%c",&a);
        fgets(numech,50,f1);
        numech[strlen(numech)-1]='\0';
        while(numech[strlen(numech)-1]==' ')
            numech[strlen(numech)-1]='\0';
        ech=createch(punctaj,numech);
        enQueue(*q,ech);
    }
}
void meci(echipa *ech1,echipa *ech2,Queue *invins,Queue *castig)
{
    if(ech1->punctaj>ech2->punctaj)
    {
        enQueue(castig,ech1);
        enQueue(invins,ech2);
    }
    else if(ech1->punctaj<ech2->punctaj)
    {
        enQueue(invins,ech1);
        enQueue(castig,ech2);
    }
    else
    {
        if(strcmp(ech1->numech,ech2->numech)>0)
        {
            enQueue(castig,ech1);
            enQueue(invins,ech2);
        }
        else
        {
            enQueue(invins,ech1);
            enQueue(castig,ech2);
        }
    }
}
