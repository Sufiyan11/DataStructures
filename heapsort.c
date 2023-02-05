#include<stdlib.h>
#include<stdio.h>
void insert(int a[],int n,int key)
{
	int i=n+1;
	a[i]=key;
	while(i>1 && key>a[i/2])
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i]=key;
}
void adjust(int a[],int n,int i)
{
	int j=2*i,key=a[i];
	while(j<=n)
	{
		if(j<n && a[j]<a[j+1])
			j=j+1;
		if(a[j]>key) a[j/2]=a[j];
		else break;
		j=2*j;
	}
	a[j/2]=key;
}
void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void heapify(int a[],int n)
{
	int i=n/2;
	while(i>=1){
		adjust(a,n,i);
		i-=1;
	}
}
void heapsort(int a[],int n)
{
	heapify(a,n);
	for(int i=n;i>1;i--)
	{
		swap(a,0,i-1);
		adjust(a,i-1,1);
		for(int i=0;i<n;i++)
        {
                printf("%d ",a[i]);
        }
		printf("\n");
	}
}
int main()
{
	int n,val;
	printf("Enter no.of elements : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d elements : ",n);
	for(int i=-1;i<n-1;i++)
	{
		scanf("%d",&val);
		insert(a,i,val);
	}
	heapsort(a,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

