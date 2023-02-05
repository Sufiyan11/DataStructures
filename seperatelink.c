#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int no;
	char name[50];
	char dep[50];
	struct node *next;
};
struct node* createnode(int nno,char nname[50],char ndep[50])
{
	struct node *h=(struct node*)malloc(sizeof(struct node));
	h->no=nno;
	strcpy(h->name,nname);
	strcpy(h->dep,ndep);
	h->next=NULL;
	return h;
}
struct node **head[10];
void create()
{
	for(int i=0;i<10;i++)
		head[i]=NULL;
}
void createtable(int n)
{
	int eno;
	char nname[50],ndep[50];
	printf("Enter the details of %d employees ::\n",n);
        for(int j=0;j<n;j++)
        {
                printf("Employee %d :\n",j+1);
                printf("No : ");
                scanf("%d",&eno);
                printf("Name : ");
                scanf("%s",nname);
                printf("Work department : ");
                scanf("%s",ndep);
                struct node *newn=createnode(eno,nname,ndep);
                int i=eno%10;
		if(head[i]==NULL)
			head[i]=newn;
		else
		{
			newn->next=head[i];
			head[i]=newn;
		}
	}
}
void insert()
{
	int nno;
	char nname[50],ndep[50];
	printf("Enter the employee details for adding :\nno , name , work of department : \n");
	scanf("%d",&nno);
	scanf("%s",nname);
	scanf("%s",ndep);
	struct node *newn=createnode(nno,nname,ndep);
	int i=nno%10;
	if(head[i]==NULL)
		head[i]=newn;
	else
	{
		newn->next=head[i];
		head[i]=newn;
	}
}
struct node* nodesearch()
{
	int eno;
	printf("Enter the Employee no for search : ");
	scanf("%d",&eno);
	int i=eno%10;
	if(head[i]==NULL)
		return NULL;
	else
	{
		struct node *newn=head[i];
		while(newn!=NULL)
		{
			if(newn->no==eno)
				return newn;
			newn=newn->next;
		}
		return NULL;
	}
}
void print(struct node *h)
{
	if(!h) printf("No data of employee");
	else printf("%d   %s\t%s\n",h->no,h->name,h->dep);
}
void printlist(struct node *h)
{
	while(h)
	{
		print(h);
		h=h->next;
	}
}
void printwhole()
{
	printf("ID  Name    Department\n");
	for(int i=0;i<10;i++)
	{
		struct node *newn=head[i];
		if(head[i]!=NULL)
			printlist(newn);
	}
}
int main()
{
	create();
	int n;
	printf("Enter the number of employees : ");
	scanf("%d",&n);
	createtable(n);
	insert();
	printwhole();
	struct node *newn=nodesearch();
	printf("\nDetails of employee :\n");
	print(newn);
}




