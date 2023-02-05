#include<stdio.h>
#include<stdlib.h>


struct SLL
{
        int val;
        struct SLL *next;
};


struct  SLL* createNode(int v)
{
        struct SLL *h;
        h=(struct SLL*)malloc(sizeof(struct SLL));
        h->val=v;
        h->next=NULL;
        return h;
}


struct SLL* createlist(int n)
{
        struct SLL *head=NULL,*newn,*tail;
        for(int i=0;i<n;i++)
        {
                int v;
                printf("Enter the number : ");
                scanf("%d",&v);
                newn=createNode(v);
                if(head==NULL)
                        head=newn;
                else
                        tail->next=newn;
                tail=newn;
        }
        return head;
}


void printlist(struct SLL *h)
{
        while(h)
        {
                printf("%d ",h->val);
                h=h->next;
        }
        printf("\n");
}


struct SLL* insertatfirst(struct SLL *h,struct SLL *newn)
{
    newn->next=h;
    return newn;
}


struct SLL* insertatlast(struct SLL *h,struct SLL *newn)
{
    struct SLL *temp=h;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newn;
    return h;
}
void printreverse(struct SLL *h)
{
	if(h->next!=NULL)
		printreverse(h->next);
	printf("%d ->",h->val);
}
int listlength(struct SLL *temp)
{
    int c=0;
    while(temp)
    {
        temp=temp->next;
        c++;
    }
    return c;
}
struct SLL* reverselist(struct SLL *h)
{
	struct SLL *head=h;
	if(h->next!=NULL)
	{
		head=reverselist(h->next);
		h->next->next=h;
		h->next=NULL;

	}
	return head;
}


struct SLL* insertlist(struct SLL *h,int val,int pos)
{
    struct SLL *newn,*temp;
    int n=listlength(h);
    temp=h;
    newn=createNode(val);
    if(pos<=1)
    {    h=insertatfirst(h,newn); }
    else if(pos>n)
    {    h=insertatlast(h,newn); }
    else
    {
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
}


struct SLL* insertofval(struct SLL *h,int val)
{
	struct SLL *temp=h;
	int n=listlength(h);
	if(temp->val>val)
		return insertlist(h,val,1);
	int i;
	for(i=1;i<=n;i++)
	{
		if(temp->val>val)
			return insertlist(h,val,i);
		temp=temp->next;
	
	}
	return insertlist(h,val,i+1);
}


int middleelement(struct SLL *h)
{
	int n=listlength(h);
	int i=0;
	if(n%2==0) i=1;
	while(i<n/2)
	{
		h=h->next;
		i++;
	}
	return h->val;
}

struct SLL* removepos(struct SLL *h,int pos)
{
	struct SLL *temp=h,*rem;
	int n=listlength(h);
	if(pos>n || pos<0)
	{
		printf("Enter appropriate position.");
		return h;
	}
	if(pos==1)
	{
		rem=h;
		h=h->next;
		free(rem);
		return h;
	}
	for(int i=1;i<pos-1;i++)
		temp=temp->next;
	rem=temp->next;
	temp->next=rem->next;
	free(rem);
	return h;
}
struct SLL* removeval(struct SLL *h,int val)
{
	struct SLL *temp=h,*pre;
	if(temp->val==val)
		return removepos(h,1);
	int i=1;
	while(temp)
	{
		if(temp->val==val) 
		{
			return removepos(h,i);
		}
		i++;
		temp=temp->next;
	}
	printf("%d not found in list.",val);
	return h;
}
struct SLL* removelast(struct SLL *h,int pos)
{
	int n=listlength(h);
	int i=n-pos;
	if(i<0 || i>n) 
	{
		printf("Enter valid position\n");
		return h;
	}
	return removepos(h,i+1);
}
struct SLL* mergelist(struct SLL *h,struct SLL *t)
{
	struct SLL *head=NULL,*tail,*newn;
	while(h && t)
	{
		if(h->val>t->val)
		{
			newn=createNode(t->val);
			t=t->next;
		}
		else
		{
			newn=createNode(h->val);
			h=h->next;
		}
		if(head==NULL)
			head=newn;
		else
			tail->next=newn;
		tail=newn;
	}

	while(h)
        {
		tail->next=h;
		tail=tail->next;
		h=h->next;
	}     
        while(t)
	{	tail->next=t;
		tail=tail->next;
		t=t->next;
	}
	      return head;
}
struct SLL* duplicatesrem(struct SLL *h)
{
	struct SLL *head=h,*pre;
	while(h->next!=NULL)
	{
		if(h->val==h->next->val)
		{
			pre=h->next;
			h->next=h->next->next;
			free(pre);
		}
		else h=h->next;
	}
	return head;
}
int comparelist(struct SLL *h1,struct SLL *h2)
{
	int n1=listlength(h1),n2=listlength(h2);
	if(n1!=n2) return 0;
	while(h1)
	{
		if(h1->val!=h2->val) return 0;
		h1=h1->next;
		h2=h2->next;
	}
	return 1;
}
int detect(struct SLL *h,struct SLL *temp,int n)
{
	for(int i=0;i<n;i++)
	{
		if(h==temp) return 1;
		h=h->next;
	}
	return 0;
}
int cycle(struct SLL *h)
{
	struct SLL *temp=h;
	int i=0;
	while(temp->next!=NULL)
	{
		if(detect(h,temp,i)) return 1;
		i++;
		temp=temp->next;
	}
}
struct SLL* mergepoint(struct SLL *head1,struct SLL *head2)
{
	struct SLL *temp;
	while(head1)
    	{
     	temp=head2;
     	while(temp)
     	{
     	if(temp==head1) return temp;
     	temp=temp->next;
     	}
     	head1=head1->next;
    	}
    	return NULL;
}
int main()
{
        struct SLL *h,*t,*newn;
        int n1,n2,val,pos;
	//list
        printf("Enter the number of elements :");
        scanf("%d",&n1);
        h=createlist(n1);
	//cycle detect
        if(cycle(h)) printf("Given list has detected cycle.");
        else printf("Given list has not detected cycle.");
	//reverse print
	printf("\nReverse  printing of list :");
	printreverse(h);
	//duplicates
	h=duplicatesrem(h);
	printf("\nlist after deletion of duplicates :");
	printlist(h);
	//second list
	printf("Enter the number of elements : ");
        scanf("%d",&n2);
        t=createlist(n2);
	//print
        printf("The elements in the list1 : ");
        printlist(h);
        printf("The elements in the list2 : ");
        printlist(t);
	//merging of lists
        newn=mergelist(h,t);
        printf("Merged list : ");
        printlist(newn);
	//comparing
	if(comparelist(h,t)) printf("Both are equal\n");
	else printf("List are not equal\n");
	//insertion on value
	printf("Enter the value of insertion : ");
        int ins;
        scanf("%d",&ins);
        h=insertofval(h,ins);
        printlist(h);
	//middle element
	int middle=middleelement(h);
        printf("The middle element of the list : %d\n",middle);
	//delete on position from last
	printf("Enter the position from last to delete : ");
	scanf("%d",&pos);
	h=removelast(h,pos);
	printlist(h);
	//delete on value
	printf("Enter the value for deletion : ");
	scanf("%d",&val);
	h=removeval(h,val);
	printlist(h);
	//delete on position
	printf("Enter the position of deletion : ");
	scanf("%d",&pos);
	h=removepos(h,pos);
	printlist(h);
	//insertion on position
        printf("Enter the value and position of insertion :");
        scanf("%d %d",&val,&pos);
        h=insertlist(h,val,pos);
        printlist(h);
	//reversing list
	printf("Reversing the list : ");
	h=reverselist(h);
	printlist(h);
	//mergepoint
	struct SLL *point=mergepoint(h,t);
	if(!point) printf("NO merge point.\n");
	else printf("The data at merge point %d\n",point->val);
}
