#include<stdio.h>
#include<stdlib.h>
struct CLL
{
        int val;
        struct CLL *next;
};


struct  CLL* createNode(int v)
{
        struct CLL *h;
        h=(struct CLL*)malloc(sizeof(struct CLL));
        h->val=v;
        h->next=NULL;
        return h;
}


struct CLL* createlist(int n)
{
        struct CLL *head=NULL,*newn,*tail;
	printf("Enter %d number : ",n);
        for(int i=0;i<n;i++)
        {
                int v;
                scanf("%d",&v);
                newn=createNode(v);
                if(head==NULL)
                        head=newn;
                else
                        tail->next=newn;
                tail=newn;
        }
	tail->next=head;
        return tail;
}
void printlist(struct CLL *h)
{
	struct CLL *temp=h->next;
        while(temp!=h)
        {
                printf("%d-> ",temp->val);
                temp=temp->next;
        }
        printf("%d",temp->val);
}
int listlength(struct CLL *h)
{
	struct CLL *temp=h->next;
	int c=1;
	while(temp!=h)
    	{
        	temp=temp->next;
        	c++;	
    	}
    	return c;
}
struct CLL* insertatfirst(struct CLL *h,struct CLL *newn)
{
	newn->next=h->next;
	h->next=newn;
	return h;
}


struct CLL* insertatlast(struct CLL *h,struct CLL *newn)
{
    newn->next=h->next;
    h->next=newn;
    return newn;
}
struct CLL* insertlist(struct CLL *h,int pos,int val)
{
    struct CLL *newn,*temp;
    int n=listlength(h);
    temp=h->next;
    newn=createNode(val);
    if(pos<=1) return insertatfirst(h,newn);
    if(pos>n)  return insertatlast(h,newn);
    for(int i=1;i<=n;i++)
    {
         if(i==pos-1)
         {
             newn->next=temp->next;
             temp->next=newn;
             return h;
         }
         temp=temp->next;
    }
}


struct CLL* insertofvalue(struct CLL *h,int val)
{
        struct CLL *temp=h->next;
        int n=listlength(h);
        if(temp->val>val) return insertlist(h,1,val);
	int i=1;
	while(i<=n)
        {
                if(temp->val>val)  return insertlist(h,i,val);
                temp=temp->next;
		i++;
        }
        return insertlist(h,i+1,val);
}
struct CLL* deleteatbeg(struct CLL *h)
{
	struct CLL *temp=h->next;
	h->next=temp->next;
	free(temp);
	return h;
}
struct CLL* deleteatlast(struct CLL *h)
{
	struct CLL *temp=h,*del;
	while(temp->next->next!=h)
		temp=temp->next;
	del=temp->next;
	temp->next=del->next;
	free(del);
	return temp;
}
struct CLL* deleteatpos(struct CLL *h,int pos)
{
	struct CLL *temp=h->next,*del;
	int n=listlength(h);
	if(pos<=1) return deleteatbeg(h);
	if(pos>=n) return deleteatlast(h->next);
	for(int i=1;i<pos-1;i++)
		temp=temp->next;
	del=temp->next;
	temp->next=del->next;
	free(del);
	return h;
}
struct CLL* removeval(struct CLL *h,int val)
{
        struct CLL *temp=h->next,*pre;
        if(temp->val==val) return deleteatpos(h,1);
        int i=1;
        while(temp)
        {
                if(temp->val==val) return deleteatpos(h,i);
                i++;
                temp=temp->next;
        }
        printf("%d not found in list.",val);
        return h;
}
int detect(struct CLL *h,struct CLL *temp,int n)
{
        for(int i=0;i<n;i++)
        {
                if(h==temp) return 1;
                h=h->next;
        }
        return 0;
}
int cycle(struct CLL *h)
{
        struct CLL *temp=h;
        int i=0;
        while(temp->next!=NULL)
        {
                if(detect(h,temp,i)) return temp->val;
                i++;
                temp=temp->next;
        }
	return -1;
}
int main()
{
        struct CLL *h;
        int n1,pos,val;
        printf("Enter the number of elements :");
        scanf("%d",&n1);
        h=createlist(n1);
	printlist(h);
	int value=cycle(h);
	if(value==-1) printf("Cycle is not detected.\n");
	else printf("Cycle is detected at node with value %d\n",value);
	printf("Enter the position and value of insertion : ");
        scanf("%d %d",&pos,&val);
        h=insertlist(h,pos,val);
        printlist(h);
	printf("Enter the value of insertion : ");
	scanf("%d",&val);
	h=insertofvalue(h,val);
	printlist(h);
        printf("Enter the position of deletion : ");
        scanf("%d",&pos);
        h=deleteatpos(h,pos);
        printlist(h);
	printf("Enter the value of deletion : ");
        scanf("%d",&val);
        h=removeval(h,val);
        printlist(h);
}
