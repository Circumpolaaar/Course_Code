#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>



int times=0;
void selectSort(int k[], int n);
void bubbleSort(int a[], int n);
void heapSort(int k[], int n);
void adjust(int k[ ],int i,int n);
void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend);
void mergeSort(int k[], int n);
void mSort(int k[],int tmp[], int left, int right);
void sort(int v[], int left, int right);
void quickSort(int k[], int n);
void swap(int v[], int i, int j);
int main(){
	
	int j,i,k=0;
	int op;
	int n;
	int sum;
	int digit[100];
	
	scanf("%d%d",&n,&op);
	for(i=0;i<n;i++){
		scanf("%d",&digit[i]);
	}
	if(op==1)
		selectSort(digit, n);
	else if(op==2)
		bubbleSort(digit,n);
	else if(op==3)
		heapSort(digit,  n);
	else if(op==4)
		mergeSort(digit, n);
	else if(op==5)
		quickSort(digit,n);
		
	for(i=0;i<n;i++){
		printf("%d ",digit[i]);
	}
	printf("\n%d",times);
	return 0;
}

void selectSort(int k[], int n){
	int i, j, d;
	int temp;
	for (i = 0; i < n - 1; i++){
		d = i;
		for (j = i + 1; j < n; j++){
			if (k[j] < k[d]){
				d = j;
				
			}
			times++;
		}
			
				
		if (d != i){
			temp = k[d];
			k[d] = k[i];
			k[i] = temp;
		}
	}
}
void bubbleSort(int a[], int n)
{
	int i, j;
	int temp;
	for (i = 0; i < n - 1; i++) {
		int flag = 1;
		for (j = 0; j < n - 1 - i; j++){
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 0;
			}
			times++;
		}
			
		if(flag == 1)
			break;
	}
}
void heapSort(int k[], int n){
	int i;
	int temp;
	for (i = n / 2 - 1; i >= 0; i--)
		adjust(k, i, n);
	for (i = n - 1; i >= 1; i--){
		temp = k[i];
		k[i] = k[0];
		k[0] = temp;
		adjust(k, 0, i);
	}
}
void adjust(int k[ ],int i,int n){
    int j,temp;
    temp=k[i];
    j=2*i+1;
    while(j<n){
        if(j<n-1 && k[j]<k[j+1])
            j++;
            
        times++;
        if(temp>=k[j]){
        	
        	break;
		}
        k[(j-1)/2]=k[j];
        j=2*j+1;
    }
    k[(j-1)/2]=temp;
}
void mergeSort(int k[], int n){
	int *tmp;
	tmp = (int *)malloc(sizeof(int) * n);
	if (tmp != NULL) {
		mSort(k, tmp, 0, n - 1);
		free(tmp);
	}
	else printf("No space for tmp array!!!\n");
}
void mSort(int k[],int tmp[], int left, int right){
	int center;
	if (left < right) {
		center = (left + right) / 2;
		mSort(k, tmp, left, center);
		mSort(k, tmp, center + 1, right);
		merge(k, tmp, left, center, right);
	}
}
void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend){     
    int i=left, j=leftend+1, q=left;
    while(i<=leftend && j<=rightend){
    	times++;
        if(x[i]<=x[j]){
        	tmp[q++]=x[i++];
        	
		}
            
        else
            tmp[q++]=x[j++];
    }
    while(i<=leftend)
        tmp[q++]=x[i++];
    while(j<=rightend)
        tmp[q++]=x[j++];
    for(i=left; i<=rightend; i++)
        x[i]=tmp[i];
}
void sort(int v[], int left, int right)
{
	int i, last;
	
	//swap(v, left, (left + right) / 2); 
	if(left<right){
		last = left;
		for (i = left + 1; i <= right; i++){
			times++;
			if (v[i] < v[left]){			
				swap(v, ++last, i);
			}		
		}
		
	swap(v, left, last); 
	sort(v, left, last-1);
	sort(v, last + 1, right);
	}
	
}

void quickSort(int k[], int n)
{
sort(k, 0, n - 1);
}

void swap(int v[], int i, int j)
{
int tmp;
tmp = v[i];
v[i] = v[j];
v[j] = tmp;
}

