#include <stdio.h>
char ar[105][105];
int n,visit[105][105],finished=0,row[]={-1,0,1,0},col[]={0,1,0,-1};

void traverseMaze(int i,int j){
    if (i<0 || i>=n || j<0 || j>=n )
        return;
    if (ar[i][j]=='#' || ar[i][j]=='.' || visit[i][j]==1)
        return;
    visit[i][j] = 1;
    if (ar[i][j]=='G'){
        finished = 1;
        return;
    }
    int k;
    for(k=0;k<4;k++){
        traverseMaze(i+row[k],j+col[k]);
        if (ar[i][j] == ' ' && finished ==1) {
            ar[i][j] = '.';
            return;

        }
    }
}
/*
void traverseMaze(int i,int j){
    if (i<0 || i>=n || j<0 || j>=n )
        return;
    if (ar[i][j]=='#' || ar[i][j]=='.')
        return;
    if (ar[i][j]=='G'){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%c",ar[i][j]);
            }
            printf("\n");
        }
    }
    if (ar[i][j]!='S') ar[i][j]='.';
    traverseMaze(i+1,j);
    traverseMaze(i-1,j);
    traverseMaze(i,j+1);
    traverseMaze(i,j-1);
    ar[i][j]=' ';
}
*/
int main() {
    int i,j;
    scanf("%d",&n);
    char temp[n+5];
    fgets(temp, n+5, stdin);
    for (i = 0; i < n; i++)
    {
        fgets(ar[i], 100, stdin);
    }
    /*
    for(i=0;i<n;i++){
        fgets(temp,n+5, stdin);
        for(j=0;j<n;j++) ar[i][j] = temp[j];
    }
    */
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (ar[i][j]=='S') traverseMaze(i,j);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c",ar[i][j]);
        }
        printf("\n");
    }
}
/*
12
############
#   #      #
S # # #### #
### #    # #
#    ### # G
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
############

11
###########
S    #    #
# ## # ## G
# #  #   ##
# ######  #
#   #  # ##
### # ## ##
#     #   #
# ##### # #
#       # #
###########

*/

