#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char stack[50],top=-1;
void push(char val)
{
        if(top==49)
        {
                printf("Stack is Full.");
                return;
        }
        top++;
        stack[top]=val;
}
int pop()
{
        if(top==-1)
        {
                printf("Stack is Empty.");
                return 0;
        }
        top--;
        return stack[top+1];
}
int peek()
{
        if(top==-1)
        {
                printf("Stack is Empty.");
                return 0;
        }
        return stack[top];
}
void print()
{
        if(top==-1)
        {
                printf("Stack is Empty.");
                return;
        }
        int temp=top;
        while(temp>=0)
        {
                printf("%c ",stack[temp]);
                temp--;
        }
}
void balance(char str[])
{
        int bal=1;
        int i=0;
        while(str[i]!='\0')
        {
                if(str[i]=='('|| str[i]=='[')
                        push(str[i]);
                if(str[i]==')'){
                        if(peek()=='(')
                                pop();
                        else
                        {
                                bal=0;
                                break;
                        }
                }
                if(str[i]==']'){
                        if(peek()=='[')
                                pop();
                        else
                        {
                                bal=0;
                                break;
                        }
                }
                i++;
        }
        if(bal>0)
                printf("\nThe equation is balanced.\n");
        else
                printf("\nThe Equation is not balanced.\n");
}
int precedence(char a)
{
        switch(a)
        {
                case '+': case '-' : return 2;
                case '*': case '/' : return 3;
                case '^': return 4;
                case '(' : case ')' :case '[' : case ']' :return 1;
        }
}
char* createpostfix(char str[])
{
        char *postfix=(char*)malloc(strlen(str)*sizeof(char));;
        int index=0,i=0;
        while(str[i]!='\0')
        {
                if(str[i]==')')
                {
                        while(stack[top]!='(')
                        {
                                if(stack[top]!='('){
                                postfix[index]=stack[top];
                                index++;
                                }
                                top--;
                        }
                        if(stack[top]=='(') pop();
                }
                else if(str[i]>=48 && str[i]<=57)
                {
                        postfix[index]=str[i];
                        index++;
                }
		else{
			push(str[i]);
			int temp=top;
			while(stack[temp]!='('){
				int temp1=temp;
				while(stack[temp1]!='('){
					if(precedence(stack[temp])<precedence(stack[temp1])){
						char s=stack[temp];
						stack[temp]=stack[temp1];
						stack[temp1]=s;
					
					}
					temp1--;
				}
				temp--;
			}
		}
                i++;
        }
	return postfix;
}
int evaluate(char *postfix)
{
	int res=1,num[25],c=-1,i=0;
	while(postfix[i]!='\0'){
		if(postfix[i]>='0' && postfix[i]<='9'){
			c++;
			num[c]=(int)postfix[i]-48;
		}
		else{
                switch(postfix[i]){
                        case '+':
                                res=num[c-1]+num[c];
                                break;
                        case '-':
                                res=num[c-1]-num[c];
                                break;
                        case '*':
                                res=num[c]*num[c-1];
                                break;
                        case'/':
                                res=num[c-1]/num[c];
                                break;
                        case '^':
				for(int k=0;k<num[c];k++)
					res*=num[c-1];
                                break;
                        case '%':
                                res=num[c-1]%num[c];
                                break;
                }
		c=c-1;
		num[c]=res;
                }
                i++;
        }
	return num[0];
}
int main()
{
        char str[50];
        printf("Enter the equation : ");
        scanf("%s",str);
        int i=0;
        char *exp=createpostfix(str);
	int res=evaluate(exp);
	printf("%s is the postfix expression of given infix expression.\n",exp);
	printf("The evaluation result of postfix expression : %d",res);
        balance(str);
}
