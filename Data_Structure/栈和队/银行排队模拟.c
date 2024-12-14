#include <stdio.h>
struct Node{
	int timein;
	int timeout;
int type;
}people[801];
int judge, front=0, rear=-1, window=3, win_able=3;
void print(int i){
	int j;
	judge=0;
	for(j=0;j<win_able;j++){
		judge=1;
		if(rear+1==front)
			break;
		people[front++].timeout=i;
		printf("%d : %d\n", front, i-people[front-1].timein);
	}
	win_able=window;
	for(j=0;j<front;j++){
		if(people[j].type>0)
			people[j].type--;
	}
	for(j=0;j<front;j++){
		if(people[j].type>0){
			win_able--;
			if(win_able==0)
				break;
		}
	}
}
int main() {
	int i, j, k=0, n, num[51]={0}, flag[51]={0};
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &num[i]);
		if(num[i]==0)
			flag[i]=1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<num[i];j++)
			scanf("%d", &people[k++].type);
	}
	for(j=0;flag[j];j++);
	for(i=j;i<n;i++){
		for(k=0;k<num[i];k++)
			people[++rear].timein=i;
		while(((rear-front+1)/window>=7)&&(window<5)&&(!flag[i])){
			window++;
			win_able++;
		}
		print(i);
		while(((rear-front+1)/window<7)&&(window>3)&&judge){
			window--;
			win_able--;
		}
	}
	while(front<rear+1){
		print(i);
		while(((rear-front+1)/window<7)&&(window>3)&&judge){
			window--;
			win_able--;
		}
		i++;
	}
return 0;
}

