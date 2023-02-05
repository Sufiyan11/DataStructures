#include<stdio.h>
#include<stdlib.h>
struct LL{
        int val;
        struct LL *next;
};
struct LL* node(int val)
{
        struct LL *h=(struct LL*)malloc(sizeof(struct LL));
        h->val=val;
        h->next=NULL;
        return h;
}
struct LL *front=NULL,*rare=NULL;
void enqueue(int val)
{
        struct LL *newn=node(val);
        if(!front) front=newn;
        else rare->next=newn;
        rare=newn;
}
int dequeue()
{
        if(!front) return -1;
        int val=front->val;
        front=front->next;
        return val;

}
void print()
{
        if(!front) return;
        struct LL *temp=front;
        while(temp!=rare){
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
        printf("Enter %d values : ",n);
        for(int i=0;i<n;i++)
        {
                scanf("%d",&val);
                enqueue(val);
        }
        val=dequeue();
        printf("First entered value : %d\n",val);
        print();
}
