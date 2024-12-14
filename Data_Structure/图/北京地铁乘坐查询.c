#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h> 
#define MAXNUM 512 
#define MAXLEN 16 
#define INFINITY 32767
struct station { 
	char sname[MAXLEN]; 
	int ischange; 
};
struct weight {
	int wei; 
	int lno;
};
struct station BGvertex[MAXNUM]; 
struct weight BGweights[MAXNUM][MAXNUM];
int Vnum = 0; 
void Dijkstra(int v0, int v1, int spath[]);
void initMap();
void printPath(int v0, int v1, int spath[]);
int addVertex(struct station st) ;
int convertNameToIndex(const char *name) ;
char start[20]={0},dest[20]={0};

int main(){
	
    int v0, v1;
    int temp;
	int spath[MAXNUM]={0};
	int i=0,j=0; 
	
	for(i=0;i<MAXNUM;i++){
		for(j=0;j<MAXNUM;j++){
			
			if(i==j){
				BGweights[i][j].wei=0;
				BGweights[i][j].lno=-1;
			}
			else{
				BGweights[i][j].wei=INFINITY;
				BGweights[i][j].lno=-1;
			}
		}
		
		
	}initMap();
    fgets(start, 20, stdin);
    fgets(dest, 20, stdin);
	start[strcspn(start, "\n")] = '\0';
    dest[strcspn(dest, "\n")] = '\0';

    
    v0 = convertNameToIndex(start); 
    v1 = convertNameToIndex(dest); 
    
    
    Dijkstra(v0, v1, spath);
    printPath(v0, v1, spath);
	
	return 0;
}
int addVertex(struct station st) {
	int i;
    for (i = 0; i < Vnum; i++) {
        if (strcmp(BGvertex[i].sname, st.sname) == 0) {
            return i;
        }
    }
    strcpy(BGvertex[Vnum].sname, st.sname);
    BGvertex[Vnum].ischange = st.ischange;
    Vnum++;
    return Vnum-1;
}
int convertNameToIndex(const char *name) {
	int i;
    for (i = 0; i < Vnum; i++) {
        if (strcmp(BGvertex[i].sname, name) == 0) {
            return i; 
        }
    }
    return -1;
}
void initMap(){
	FILE *fp;
	int i, j, snum, lno, lnum, v1, v2;
	struct station st;
	fp=fopen("bgstations.txt","r");
	fscanf(fp, "%d", &snum);
		for (i = 0; i < snum; i++) {
		fscanf(fp, "%d %d", &lno, &lnum); 
		v1 = v2 = -1;
		for (j = 0; j < lnum; j++) {
			fscanf(fp, "%s %d", st.sname, &st.ischange);
			v2 = addVertex(st); 
			if (v1 != -1) {
				BGweights[v1][v2].wei = BGweights[v2][v1].wei = 1;
				BGweights[v1][v2].lno = BGweights[v2][v1].lno = lno;
			}
			v1 = v2;
		}
	}
	
}

void printPath(int v0, int v1, int spath[]) {
    char path[80] = {0}, buf[80];
    int board[MAXNUM], bcount = 0, line = -1, sc = 0;
    int i;
    do {
        board[bcount++] = v1;
    } while ((v1 = spath[v1]) != v0);
    board[bcount++] = v0;
    line = BGweights[board[bcount - 1]][board[bcount - 2]].lno;
    sprintf(buf, "%s-%d(", BGvertex[board[bcount - 1]].sname, line);
    strcpy(path, buf); 
	sc = 1;
    for (i = bcount - 2; i > 0; i--, sc++) {
        if (BGweights[board[i]][board[i - 1]].lno != line) {
            line = BGweights[board[i]][board[i - 1]].lno;
            sprintf(buf, "%d)-%s-%d(", sc, BGvertex[board[i]].sname, line);
            strcat(path, buf); 
			sc = 0;
        }
    }
    sprintf(buf, "%d)-%s\n", sc, BGvertex[board[i]].sname);
    strcat(path, buf);
    puts(path);
}
void Dijkstra(int v0, int v1, int spath[]){
	int i, j, v=0, minweight;
	char wfound[MAXNUM] = {0}; 
	int sweight[MAXNUM] = {0};
	for (i = 0; i < Vnum; i++){
		sweight[i] = BGweights[v0][i].wei; 
		spath[i] = v0; 
	}	
	sweight[v0] = 0; wfound[v0] = 1;
	for (i = 0; i < Vnum - 1; i++) { 
		minweight = INFINITY;
		for (j = 0; j < Vnum; j++) 
			if (!wfound[j] && (sweight[j] < minweight)) {
				v = j; minweight = sweight[v]; }
		wfound[v] = 1; 
		if (v == v1) return; 
		for (j = 0; j < Vnum; j++) 
			if(!wfound[j]&&(BGweights[v][j].lno>0)&&(minweight+BGweights[v][j].wei<sweight[j])){
				sweight[j] = minweight + BGweights[v][j].wei;
				
				spath[j] = v; 
			}
	} 
}

