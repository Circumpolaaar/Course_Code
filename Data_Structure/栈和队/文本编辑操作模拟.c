#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct _operation
{
    int op;
    int pos;
    int flag;
    char str[520];
} operation, *opr;
void restore(char *a, operation x);
void store(char *a, operation x);
int main() {
    char *a = malloc(520);
	int i=0,j=0;
    gets(a); 
    int n = 0, opt = 0;
    scanf("%d", &n);
    operation x[200];
    for (i = 0; i < n; i++) {
        scanf("%d%d %s", &x[i].op, &x[i].pos, x[i].str); }
    	x[i].flag=0;
		// 复原
    for (j = n - 1; j >= 0; j--) {
        restore(a, x[j]);
        //puts(a);
	   }
    while (scanf("%d", &opt) != EOF) {
        if (opt == 3) {
            n--;
        } else if (opt == 1) {
            x[n].op = 1;
            scanf("%d %s", &x[n].pos, x[n].str);
            x[n].flag=1;
            n++;
        } else if (opt == 2) {
            x[n].op = 2;
            scanf("%d %s", &x[n].pos, x[n].str);
            x[n].flag=1;
            n++;
        } else if(opt==-1){
        	break;}
    }
    for (j = 0; j < n; j++) {
        store(a, x[j]);
        //puts(a);
    }
    printf("%s\n", a);free(a);return 0;
}
void restore(char *a, operation x) {
    int n = strlen(x.str);
    int i=0,j=0,k=0;
	int b=strlen(a);
    if (x.op == 1) {
    for (i = x.pos + n ; i < strlen(a); i++) {
        a[i - n] = a[i];
    }
    a[i - n] = '\0';   
    } else if (x.op == 2) {
        // 插入操作
        memmove(a + x.pos + n, a + x.pos, strlen(a) - x.pos + 1);
        memcpy(a + x.pos, x.str, n);
    }
}
void store(char *a, operation x) {
    int n = strlen(x.str);
    int i=0,j=0,k=0;
	int b=strlen(a);
	int sum=0;
    if (x.op == 2) {// 删除操作
        if(x.flag==1){
			sum=0;
        	for(i=0;i<n;i++){
				sum=sum*10+x.str[i]-'0';}
			if (x.pos + sum <= b) {
       	     	memmove(a + x.pos, a + x.pos + sum, b - x.pos - sum + 1);
       		 } 
			else {
       	   		a[x.pos] = '\0';
			}
		} 
		else if(x.flag==0){
			for (i = x.pos + n ; i < b; i++) {
        		a[i - n] = a[i];
   			 }
   			 a[b - n] = '\0'; 
		}
	}
	else if (x.op == 1) {
        memmove(a + x.pos + n, a + x.pos, b - x.pos + 1);
        memcpy(a + x.pos, x.str, n);
    }
}

