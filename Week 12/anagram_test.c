#include<stdio.h>
typedef struct node{
   // int size;
    char* first;
    char* last;
    struct node* next;
}list_t;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int nl = m-l+1, L[nl];
    int nr = r-m, R[nr];
    // Copy data to temporary L and R arrays
    for (i=0; i<nl; i++)
        L[i] = arr[l+i];
    for (j=0; j<nr; j++)
        R[j] = arr[m+1+j];
    // Merge the L and R arrays back into arr
    i = 0; j = 0; k = l;
    while (i < nl && j < nr)
        arr[k++] = (L[i]<=R[j])? L[i++] : R[j++];
    // Copy the remaining elements, if any
    while (i < nl)
        arr[k++] = L[i++];
    while (j < nr)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int l, int r) {
    int m;
    if (l < r) {
        m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main(){
    int i,j,m,n;
    char str[51];
    scanf("%d %d",&m,&n);
    list_t* ar = (list_t*)malloc(sizeof(list_t)*m);
    for(i=0;i<m;i++){
        scanf("%s",str);
        //printf("%s\n",str);
    }
    for(i=0;i<n;i++){
        scanf("%s",str);
        //printf("%s\n",str);
    }
}
