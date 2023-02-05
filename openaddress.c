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
struct node **head[100];
void create()
{
        for(int i=0;i<100;i++)
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
                for(int i=0;;i++)
		{
			int key=((eno%10)+(i*(eno%7))+i*(eno%9))%10;
			if(head[key]==NULL)
			{
				head[key]=newn;
				break;
			}
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
	for(int i=0;;i++)
	{
		int key=((nno%10)+i*(nno%7)+i*(nno%9))%10;
                if(head[key]==NULL)
                {
			head[key]=newn;
                        break;
                }
        }	
}
struct node* nodesearch()
{
        int eno;
        printf("Enter the Employee no for search : ");
        scanf("%d",&eno);
        for(int i=0;;i++)
        {
		printf("%d\n",i);
                int key=((eno%10)+i*(eno%7)+i*(eno%9))%10;
		struct node *newn=head[key];
                if(newn->no==eno)
			return head[key];
        }
}
void print(struct node *h)
{
        if(!h) printf("No data of employee");
        else printf("%d   %s\t%s\n",h->no,h->name,h->dep);
}
void printwhole()
{
        printf("ID  Name    Department\n");
        for(int i=0;i<10;i++)
        {
                struct node *newn=head[i];
                if(head[i]!=NULL)
                        print(newn);
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
        printf("Id  Name   Department\n");
        print(newn);
}
