#include "Biblioteca.h"
echipa* createch(float punctaj,char *nume,int n)
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
    membru->pozitie=n;
    membru->r=0;
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
    for(i=0; i<nrech; i++)
    {
        ech=NULL;
        numech=(char*)realloc(numech,50);
        fscanf(f1,"%f",&punctaj);
        fscanf(f1,"%c",&a);
        fgets(numech,50,f1);
        numech[strlen(numech)-1]='\0';
        while(numech[strlen(numech)-1]==' ')
            numech[strlen(numech)-1]='\0';
        ech=createch(punctaj,numech,i);
        enQueue(*q,ech);
    }
}
void meci(echipa *ech1,echipa *ech2,Queue *invins,Queue *castig,Graph *g)
{
    if(ech1->punctaj>ech2->punctaj)
    {
        (ech1->r)++;
        enQueue(castig,ech1);
        enQueue(invins,ech2);
        g->a[ech2->pozitie][ech1->pozitie]=1;
    }
    else if(ech1->punctaj<ech2->punctaj)
    {
        (ech2->r)++;
        enQueue(invins,ech1);
        enQueue(castig,ech2);
        g->a[ech1->pozitie][ech2->pozitie]=1;
    }
    else
    {
        if(strcmp(ech1->numech,ech2->numech)>0)
        {
            (ech1->r)++;
            enQueue(castig,ech1);
            enQueue(invins,ech2);
            g->a[ech2->pozitie][ech1->pozitie]=1;
        }
        else
        {
            (ech2->r)++;
            enQueue(invins,ech1);
            enQueue(castig,ech2);
            g->a[ech1->pozitie][ech2->pozitie]=1;
        }
    }
}
Graph* creareGraph(int V)
{
    int i;
    Graph *g=(Graph*)malloc(sizeof(Graph));
    if(g==NULL)
    {
        printf("memerror");
        return NULL;
    }
    g->V=V;
    g->a=(int **)malloc(g->V*sizeof(int*));
    for(i=0; i<g->V; i++)
        g->a[i]=(int*)calloc(g->V,sizeof(int));
        if(g->a==NULL)
        {
            printf("memerror");
            return NULL;
        }
    return g;
}
void printGraph ( FILE *f2,Graph *g)
{
    int i, j;
    for (i=0; i<g->V; i++)
    {
        for (j=0; j<g->V; j++)
            fprintf (f2,"%d ",g->a[i][j]);
        fprintf (f2,"\n");
    }
}
float calcul(int r, int l)
{
    float q=0.15;
    float pr=0;
    pr=(float)(q*pow((2-q),r))/(pow(2,l)+pow((2-q),l)*(q-1));
    return pr;
}
void testfis(FILE *f)
{
    if(f==NULL)
    {
        printf("Fisierul nu a putut fi deschis");
        exit(1);
    }
}
void printScor(FILE *f3,Queue *invins,Queue *castig)
{
    float pr;
    while(invins->front!=NULL)
    {
        pr=calcul(invins->front->r,(castig->front->r)+1);
        fprintf(f3,"%.4f %s\n",pr,invins->front->numech);
        deQueue(invins);
    }
    pr=calcul(castig->front->r,(castig->front->r)+1);
    fprintf(f3,"%.4f %s",pr,castig->front->numech);
    deQueue(castig);
}
