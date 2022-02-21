#include <stdio.h>
int ar[1000][1000];
int ans[1000],visit[1000],out[1000];
int n,m,run=0,max=0;

void dfs(int cur){
    //run++;
    visit[cur] = 1;
    int j;
    for( j=0;j<n;j++){
        if( ar[cur][j] == 1 && visit[j] == 0 ) {
            dfs(j);
        }
    }
    run++;
    out[cur] = run;
}

void dfs2(int cur,int len,int tmp[]){
    tmp[len] = cur;
    visit[cur] = 0;
    int j;
    for(j=0;j<n;j++){
        if( ar[j][cur] == 1 && visit[j] == 1 ) {
            dfs2(j,len+1,tmp);
        }
    }
    if(len+1 > max) {
        max = len+1;
        int i;
      //  printf("%d \n",cur);
        for(i=0;i<max;i++){
            ans[i] = tmp[i];
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int u,v,i;
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        ar[u][v] = 1;
    }

    for(i=0;i<n;i++){//dfs1
        if(visit[i]==0) dfs(i);
    }

    for(i=0;i<n;i++){//dfs2
        int max2 = 0;
        int start = 0;
        int j;
        for(j=0;j<n;j++){//find start
            if(out[j]>max2){
                max2 = out[j];
                start = j;
                out[j] = 0;
            }
        }
        if(visit[start]==1){//reverse
            int tmp[n+1] ;
            printf("\t%d\n",start);
            dfs2(start,0,tmp);
        }
    }
    printf("%d",max);
    for(i=0;i<max;i++){//sort ans
        int j;
        for(j=i+1;j<max;j++){
            if(ans[j]<ans[i]){
                int tmp2 = ans[i];
                ans[i] = ans[j];
                ans[j] = tmp2;
            }
        }
    }

    for(i=0;i<max;i++)
        printf("%d ",ans[i]);

    return 0;
}
