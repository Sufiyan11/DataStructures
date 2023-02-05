#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int start=1,max=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			if(max<(i+1)-start)
			{
				max=i-start;
				start=i+1;
			}
		}
	}
	printf("The length is %d",max);
}


