#include<stdio.h>
#include<stdlib.h>
struct DLL{
	int val;
	struct DLL *next,*prev;
};
struct DLL* createNode(int val)
{
	struct DLL *h;
	h=(struct DLL *)malloc(sizeof(struct DLL));
	h->val=val;
	h->next=NULL;
	h->prev=NULL;
	return h;
}
struct DLL* createList(int n)
{
	struct DLL *head=NULL,*tail,*newn;
	int val;
	printf("Enter %d numbers :",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val);
		newn=createNode(val);
		if(head==NULL) head=newn;
		else
		{
			tail->next=newn;
			newn->prev=tail;
		}
		tail=newn;
	}
	return head;
}
void print(struct DLL *h)
{
	while(h->next!=NULL)
	{
		printf("%d <-> ",h->val);
		h=h->next;
	}
	printf("%d\n",h->val);
}
int listlength(struct DLL *h)
{
	int i=0;
	while(h)
	{
		i++;
		h=h->next;
	}
	return i;
}
struct DLL* insertatfirst(struct DLL *h,struct DLL *newn)
{
	newn->next=h;
	h->prev=newn;
	return newn;
}
struct DLL* insertatlast(struct DLL *h,struct DLL *newn)
{
	struct DLL *temp=h;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newn;
	newn->prev=temp;
	return h;
}
struct DLL* insertlist(struct DLL *h,int val,int pos)
{
	int n=listlength(h);
	struct DLL *temp=h,*newn=createNode(val);
	if(pos<=1) return insertatfirst(h,newn);
	if(pos>n) return insertatlast(h,newn);
	for(int i=1;i<pos-1;i++)
		temp=temp->next;
	newn->next=temp->next;
	newn->prev=temp;
	temp->next=newn;
	return h;
}
struct DLL* insertofvalue(struct DLL *h,int val)
{
	int i=0;
	struct DLL *temp=h;
	while(temp){
		if(temp->val>val) return insertlist(h,val,i);
		temp=temp->next;
		i++;
	}
	return insertlist(h,val,i);
}
struct DLL* deleteatfirst(struct DLL *h)
{
	struct DLL *t=h;
	h=h->next;
	h->prev=NULL;
	free(t);
	return h;
}
struct DLL* deleteatlast(struct DLL *h)
{
	struct DLL *t,*head=h;
	while(h->next->next)
		h=h->next;
	t=h->next;
	h->next=NULL;
	free(t);
	return head;
}
struct DLL* deleteatpos(struct DLL *h,int pos)
{
	printf("YES");
	struct DLL *head=h,*t;
	int n=listlength(h);
	if(pos<=1) return deleteatfirst(h);
	if(pos>=n) return deleteatlast(h);
	for(int i=1;i<pos-1;i++)
		h=h->next;
	t=h->next;
	h->next=t->next;
	t->next->prev=h;
	free(t);
	return head;
}
struct DLL* deletenode(struct DLL *h,int val)
{
	int i=1;
	struct DLL *head=h;
	while(h)
	{
		if(h->val==val) return deleteatpos(head,i);
		h=h->next;
		i++;
	}
	return head;
}
void swap(struct DLL *h1,struct DLL *h2)
{
	int val=h1->val;
	h1->val=h2->val;
	h2->val=val;
}
struct DLL* reverselist(struct DLL *h)
{
	struct DLL *t=h,*head=h;
	while(t->next)
		t=t->next;
	int n=listlength(h);
	for(int i=0;i<n/2;i++)
	{
		swap(h,t);
		h=h->next;
		t=t->prev;
	}
	return head;
}

int main()
{
	struct DLL *h;
	int n,val,pos;
	printf("Enter the number of elements :");
	scanf("%d",&n);
	h=createList(n);
	print(h);
	printf("Enter the value of innsertion : ");
	scanf("%d",&val);
	h=insertofvalue(h,val);
	print(h);
	printf("Reversing of list : ");
	h=reverselist(h);
	print(h);
	printf("Enter the value and position of deletion : ");
	scanf("%d %d",&val,&pos);
	h=deletenode(h,val);
	printf("Deleting the %d from list : ",val);
	print(h);
	h=deleteatpos(h,pos);
	printf("Deleting the value at position %d :",pos);
	print(h);
	printf("Enter the value and position of insertion : ");
	scanf("%d %d",&val,&pos);
	printf("List after insertion : ");
	h=insertlist(h,val,pos);
	print(h);
}
