#include<stdio.h>
#include<stdlib.h>
struct poly{
        int val,exp;
        struct poly *next;
};
struct poly* polynode(int val,int exp)
{
        struct poly *h;
        h=(struct poly*)malloc(sizeof(struct poly));
        h->val=val;
        h->exp=exp;
        h->next=NULL;
}
struct poly* polynomial(int n)
{
        struct poly *head=NULL,*tail,*newn;
        if(n==0)
        {       printf("Enter non-zero input\n");
                return head;
        }
        int val,exp,i;
        printf("Enter the polynomial: coefficient and exponent power by::\n");
        for(i=0;i<n;i++)
        {
                scanf("%d %d",&val,&exp);
                newn=polynode(val,exp);
                if(head==NULL) head=newn;
                else tail->next=newn;
                tail=newn;
        }
        return head;
}
void print(struct poly *h)
{
        if(!h) printf("No Poynomial\n");
        else
        {
        while(h->next!=NULL)
        {
		if(h->val==0)
			continue;
		else printf("%dx^%d + ",h->val,h->exp);
               h=h->next;
        }
        if(h->exp==0)
                printf("%d\n",h->val);
        else
                printf("%dx^%d\n",h->val,h->exp);
        }
}
void swap(struct poly *m,struct poly *n)
{
        int val=m->val,exp=m->exp;
        m->val=n->val;
        m->exp=n->exp;
        n->val=val;
        n->exp=exp;
}
struct poly* polysort(struct poly *h)
{
        struct poly *t,*head=h;
        while(h)
        {
                t=head;
                while(t->next!=NULL)
                {
                        if(t->exp<t->next->exp)
                                swap(t,t->next);
                        t=t->next;
                }
                h=h->next;
        }
        return head;
}
struct poly* polyadd(struct poly *m,struct poly *n)
{
        m=polysort(m);
        n=polysort(n);
        struct poly *h=NULL,*tail,*newn;
        if(m==NULL)
                return n;
        if(n==NULL)
                return m;
        while(m && n)
        {
                if(m->exp==n->exp)
                {
                        newn=polynode(m->val+n->val,m->exp);
                        m=m->next;
                        n=n->next;
		}
                else if(m->exp>n->exp)
                {
                        newn=polynode(m->val,m->exp);
                        m=m->next;
                }
                else
                {
                        newn=polynode(n->val,n->exp);
                        n=n->next;
                }
                if(h==NULL)
                        h=newn;
                else
                        tail->next=newn;
                tail=newn;
        }
        while(m)
        {
                newn=polynode(m->val,m->exp);
                tail->next=newn;
                tail=newn;
                m=m->next;
        }
        while(n)
        {
                newn=polynode(n->val,n->exp);
                tail->next=newn;
                tail=newn;
                n=n->next;
        }
        h=polysort(h);
        return h;
}
struct poly* polymul(struct poly *m,struct poly *n)
{
        struct poly *head,*temp,*newn,*extra=polynode(0,0),*tail;
        while(m)
        {
		head=NULL;
                temp=n;
                while(temp)
                {
                        newn=polynode(m->val*temp->val,m->exp+temp->exp);
                        temp=temp->next;
                        if(head==NULL) head=newn;
                        else tail->next=newn;
                        tail=newn;
                }
                m=m->next;
                head=polyadd(head,extra);
		extra=head;
        }
        return head;
}
int main()
{
        struct poly *add,*mul,*h1,*h2;
        int n1,n2;
        printf("Enter the number of elments in polymonial1 : ");
        scanf("%d",&n1);
        h1=polynomial(n1);
        printf("Enter the number of elments in polymonial1 : ");
        scanf("%d",&n2);
        h2=polynomial(n2);
        h2=polysort(h2);
        h1=polysort(h1);
        printf("Given polynomials : \nFirst plynomail : ");
        print(h1);
        printf("Second polynomial :");
        print(h2);
        add=polyadd(h1,h2);
        printf("The addition of given polynomials :  ");
        print(add);
	mul=polymul(h1,h2);
	printf("The multiplication of given polynomials : ");
	print(mul);
	

}
