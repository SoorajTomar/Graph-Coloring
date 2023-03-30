#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
void printgc(int v,int c[v]){
    printf("Solution is:\n");
    for(int i=0;i<v;i++)
    printf("%d ",c[i]);
}
bool issafe(int v,int g[v][v],int c[v],int j,int i){
    for(int p=0;p<v;p++)
    if(g[i][p]==1&&c[p]==j)
    return false;
    return true;
}
bool gcu(int v,int g[v][v],int c[v],int i,int m){
    if(i==v)
    return true;
    for(int j=1;j<=m;j++){
        if(issafe(v,g,c,j,i))
        {c[i]=j;
        if(gcu(v,g,c,i+1,m))
        return true;
        c[i]=0;}
    }
    return false;
}
void color(int v,int g[v][v],int m){
    int c[v];
    for(int j=0;j<v;j++)
    c[j]=0;
    if(!gcu(v,g,c,0,m))
    printf("No solution exists!");
    else
    printgc(v,c);
}
int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    int g[v][v];
    for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
    g[i][j]=0;
    printf("Enter the vertices with their neighbours one by one and enter -1 -1 to end\n");
    while(true){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==y && x==-1)
        break;
        g[x-1][y-1]=1;
        g[y-1][x-1]=1;
    }
    printf("Graph is:\n");
    for(int i=0;i<v;i++){
    for(int j=0;j<v;j++)
    printf("%d ",g[i][j]);
    printf("\n");}
    int m;
    printf("Enter no of colors to be used: ");
    scanf("%d",&m);
    color(v,g,m);
    return 0;
}
