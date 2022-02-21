#include<stdio.h>
#define V 4
#define INF 1e9
int g[1000][1000];

void floyd(int n){
    int i, j, k;
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
}

int main()
{
    int n,m,p,i,j;
    scanf("%d %d %d",&n,&m,&p);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }

    int u,v,w;
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        g[u][v] = w;
        g[v][u] = w;
    }

    floyd(n);

    while(p--){
        scanf("%d %d",&u,&v);
        if(g[u][v]!=INF) printf("%d\n",g[u][v]);
        else printf("-1\n");
    }

    return 0;
}
