
#include<stdio.h>
#include<stdlib.h>
#define MAXVER 512
#define INFINITY 32767
struct edge {
	int id;
	int wei;
};
struct edge graph[MAXVER][MAXVER];
int edges[MAXVER]={0};
int weights[MAXVER][MAXVER];
int minweight[MAXVER];
int compare(const void *a, const void *b) ;
void Prim(int weights[][MAXVER], int n, int src, int edges[]);
int main(){
	int n,e;
	int i,j;
	int id,v1,v2,weight;
	int wei=0;
	int array[200]={0};
	scanf("%d%d",&n,&e);
	 for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            weights[i][j] = INFINITY;
        }
    }
	for(i=0;i<e;i++){
		scanf("%d%d%d%d",&id,&v1,&v2,&weight);
		graph[v1][v2].id = id; 
		graph[v1][v2].wei = weight;
		graph[v2][v1].id = id; 
		graph[v2][v1].wei = weight;
		weights[v1][v2] = weight;
        weights[v2][v1] = weight;
	}
	Prim(weights,n,0,edges);

	for(i=0;i<n;i++){
		array[i]=graph[edges[i]][i].id;
		wei+=graph[edges[i]][i].wei;
	}
	qsort(array, n, sizeof(int), compare);
	printf("%d\n",wei);
	for(i=1;i<n;i++){
		printf("%d ", array[i]);
	}
	return 0;
}
int compare(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    
    if (arg1 < arg2) {
        return -1;
    } else if (arg1 > arg2) {
        return 1;
    }
    return 0;
}

void Prim(int weights[][MAXVER], int n, int src, int edges[]){ 
	int minweight[MAXVER], min;
	int i, j, k;
	for (i = 0; i < n; i++){ 
		minweight[i] = weights[src][i]; 
		edges[i] = src; 
	}
	minweight[src] = 0; 
	for (i = 1; i < n; i++) { 
		min = INFINITY;
		for (j = 0, k = 0; j < n; j++)
			if (minweight[j] != 0 && minweight[j] < min) { 
				min = minweight[j]; 
				k = j;
			}
		minweight[k] = 0; 
		for (j = 0; j < n; j++)
			if (minweight[j] != 0 && weights[k][j] < minweight[j]) {
				minweight[j] = weights[k][j]; 
				edges[j] = k; 
			}
	}
}


