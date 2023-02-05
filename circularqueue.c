#include<stdio.h>
#include<stdlib.h>
struct node
{
        int val;
        struct node *next;
};
struct node *front=NULL,*rare=NULL;
struct  node* createNode(int v)
{
        struct node *h;
        h=(struct node*)malloc(sizeof(struct node));
        h->val=v;
        h->next=NULL;
        return h;
}
void enqueue(int val)
{
        struct node *newn=createNode(val);
	if(front==NULL && rare==NULL){
		front=newn;
		rare=newn;
	}
	else{
		rare->next=newn;
		rare=newn;
	}
        rare->next=front;
}
int dequeue()
{
	int val;
	if(!front && !rare) return -1;
	if(front==rare){
		val=front->val;
		free(front);
	}
	else{
		struct node *temp=front;
		rare->next=front->next;
		val=front->val;
		front=front->next;
		free(temp);
	}
	return val;
}
void print()
{
	struct node *temp=front;
        while(temp->next!=front)
        {
                printf("%d  ",temp->val);
                temp=temp->next;
        }
	printf("%d",temp->val);
}
int main()
{
	int n,val;
	printf("Enter no.of elements : ");
	scanf("%d",&n);
	printf("Enter %d elements : ",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val);
		enqueue(val);
	}
	printf("Queue : ");
	print();
	val=dequeue();
	printf("\nFirst element entered : %d \n",val);
	printf("The Queue : ");
	print();
}
