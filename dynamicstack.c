#include<stdio.h>
#include<stdlib.h>
struct SLL{
        int val;
        struct SLL *next;
};
struct SLL *stack={NULL};
struct SLL* node(int val)
{
        struct SLL *h;
        h=(struct SLL*)malloc(sizeof(struct SLL));
        h->val=val;
        h->next=NULL;
        return h;
}
void push(struct SLL *h)
{
        if(stack!=NULL) h->next=stack;
        stack=h;
}
int pop()
{
        if(!stack)
        {
                printf("Stack is Empty.");
                return -1;
        }
        int val=stack->val;
	struct SLL *curr=stack;
        stack=stack->next;
	free(curr);
        return val;
}
int peek()
{
        if(!stack)
        {
                printf("Stack is Empty.");
                return -1;
        }
        return stack->val;
}
void print()
{
        if(!stack)
        {
                printf("Stack is Empty.");
                return;
        }
        struct SLL *temp=stack;
        while(temp)
        {
                printf("%d ",temp->val);
                temp=temp->next;
        }
	printf("\n");
}
void stacklist(int n)
{
        int val;
        struct SLL *newn;
        printf("Enter %d numbers : ",n);
        for(int i=0;i<n;i++)
        {
                scanf("%d",&val);
                newn=node(val);
                push(newn);
        }
}
int main()
{
        int n,val;
        printf("Enter the number of elements : ");
        scanf("%d",&n);
        stacklist(n);
	int last=peek();
        printf("The top value in stack : %d\n",last);
        printf("Deleting the last entered value : ");
        pop();
        print();
	printf("Enter the value to push into stack :");
        scanf("%d",&val);
        struct SLL *newn=node(val);
        push(newn);
	printf("Stack : ");
	print();
}
