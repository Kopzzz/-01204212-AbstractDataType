#include <stdio.h>

int g[1000][1000];
int index[1000];

int max(int a,int b){
    return a>b ? a : b;
}

int is_clique(int end){
    int i,j;
    for (i=1 ; i<end ; i++) {
        for (j=i+1 ; j<end ; j++){
           // printf("i=%d j=%d g[%d][%d]\n",i,j,index[i],index[j]);
            if (g[index[i]][index[j]] == 0)
                return 0;
        }
    }
    return 1;
}

int maxCliques(int n,int cur, int l){
    int maxx = 0;
    int j;
   // printf("\tcur=%d l=%d\n",cur,l);
    for(j=cur+1 ; j<=n ; j++) {
        index[l] = j;
        //printf("index[%d] = %d\n",l,j);
        if (is_clique(l+1)) {
            maxx = max(maxx, l);
            maxx = max(maxx, maxCliques(n,j,l+1));
        }
    }
    return maxx;
}

int main(){
    int n,m,u,v,i;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g[u+1][v+1] = 1;
        g[v+1][u+1] = 1;
    }

    printf("%d",maxCliques(n,0,1));

    return 0;
}
