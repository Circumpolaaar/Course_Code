//文件压缩-Huffman实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {			//Huffman树结构
	char c;		
	int weight;		//树节点权重，叶节点为字符和它的出现次数
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};		//存放每个字符的出现次数，如Ccount[i]表示ASCII值为i的字符出现次数 
struct tnode *Root=NULL; 	//Huffman树的根节点
char HCode[128][MAXSIZE]={{0}}; //字符的Huffman编码，如HCode['a']为字符a的Huffman编码（字符串形式） 
int Step=0;			//实验步骤 
FILE *Src, *Obj;
	
void statCount();		//步骤1：统计文件中字符频率
void createHTree();		//步骤2：创建一个Huffman树，根节点为Root 
void makeHCode();		//步骤3：根据Huffman树生成Huffman编码
void atoHZIP(); 		//步骤4：根据Huffman编码将指定ASCII码文本文件转换成Huffman码文件

void print1();			//输出步骤1的结果
void print2(struct tnode *p);	//输出步骤2的结果 
void print3();			//输出步骤3的结果
void print4();			//输出步骤4的结果

int main()
{
        if((Src=fopen("input.txt","r"))==NULL) {
	        fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1; 
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);		//输入当前实验步骤 
	
	statCount();			//实验步骤1：统计文件中字符出现次数（频率）
	(Step==1)?print1():1;   	//输出实验步骤1结果	
	createHTree();			//实验步骤2：依据字符频率生成相应的Huffman树
	(Step==2)?print2(Root):2; 	//输出实验步骤2结果	
	makeHCode();		//实验步骤3：依据Root为树的根的Huffman树生成相应Huffman编码
	(Step==3)?print3():3;   	//输出实验步骤3结果
	(Step>=4)?atoHZIP(),print4():4;//实验步骤4：据Huffman编码生成压缩文件，并输出实验步骤4结果	

	fclose(Src);
	fclose(Obj);
        return 0;
} 

//【实验步骤1】开始 
void statCount()
{
	Ccount[0]=1;
	char c;
	while((c=fgetc(Src))!=EOF) {
		Ccount[c]++;
	}
}



//【实验步骤1】结束

//【实验步骤2】开始
struct tnode *createnew(struct tnode *a,struct tnode *b);	
void add(int i,int n,struct tnode *a,struct tnode *F[]);
void createHTree()
{
	struct tnode *F[300];
	struct tnode *temp=NULL,*p=NULL;
	int i=0,j=0,n=0,m=0;
	for(i=0; i<128; i++){
		if(Ccount[i]>0){
			p = (struct tnode *)malloc(sizeof(struct tnode));
			p->c = i; 
			p->weight = Ccount[i];
			p->left = p->right = NULL;
			F[j]=p;
			j++;
		}
	}
	n=j;
	//排序
	for (i = 0; i < n - 1; i++) {
		int flag = 1;
		for (j = 0; j < n - 1 - i; j++)
			if (F[j]->weight> F[j+1]->weight)
			{
				temp = F[j];
				F[j] = F[j+1];
				F[j+1] = temp;
				flag = 0;
			}
		if(flag == 1)
			break;
	} 
	//构造
	i=0;
	m=n;
	while(n>1){
		temp=createnew(F[i],F[i+1]);
		n--;
		i=i+2;
		if(n>=2){
			add(i,n+i-1,temp,F);
		} 
		else{
			F[i]=temp;
		}
		
		
	}	
	Root=F[i];
	
}

struct tnode *createnew(struct tnode *a,struct tnode *b){
	struct tnode *p=NULL;
	p = (struct tnode *)malloc(sizeof(struct tnode));
	p->weight = a->weight+b->weight;
	p->left =a;
	p->right=b;
	
	return p;
}
void add(int i,int n,struct tnode *a,struct tnode *F[]){
	int j,k;
	for(j=i;j<n;j++){
		if(F[j]->weight>a->weight){
			break;
		}
	}
	//n是个数，i是当前位置 ，j是第一个大于 
	for(k=n-1;k>=j;k--){
		F[k+1]=F[k];
	}
	F[j]=a;
}



//【实验步骤2】结束

//【实验步骤3】开始
void forward(struct tnode *p,char b[]);
void makeHCode()
{
	char b[300];
	int i=0;
	forward (Root,b);
	
	
} 
void forward(struct tnode *p,char b[])
{

	static int len = 0;
	int i=0;
	if(p != NULL){
		//叶节点 
		if((p->left==NULL)&&(p->right==NULL)){
			b[len]='\0';
			strcpy(HCode[p->c],b);
		} 
	 	if (p->right != NULL) {
            b[len++] = '1';
            forward(p->right, b);
            len--; 
        }
		if (p->left  != NULL) {
            b[len++] = '0';
            forward(p->left, b);
            len--; 
        }	
		
	}
}




//【实验步骤3】结束

//【实验步骤4】开始
void atoHZIP()
{
	int i,k,j=0;
	char c;
	char s[1024*1024];
	unsigned char hc;
	int n;
	int bit_count = 0;
	fseek(Src,0,SEEK_SET);
	while((c=fgetc(Src))!=EOF) {
		for(i=0;i<strlen(HCode[c]);i++){
			s[j]=HCode[c][i];
			j++;
		}
	}
	
	
	for(k=0;k<strlen(HCode[0]);k++){
		s[j]=HCode[0][k];
		j++;
	}
	s[j]='\0';
	
	 for (i = 0; s[i] != '\0'; i += 8) {
        hc = 0; 
        
        for (j = 0; j < 8; j++) {
            hc = (hc << 1) | (s[i + j] - '0');
        	//printf("%x ",hc);
		}
        // 打印十六进制数
        printf("%x", hc);
fputc(hc,Obj); 
        //printf("\n");
    }

}


//【实验步骤4】结束

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\n原文件大小：%ldB\n",in_size);
	printf("压缩后文件大小：%ldB\n",out_size);
	printf("压缩率：%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}

