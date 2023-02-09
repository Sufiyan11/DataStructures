#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *left,*right;
};
struct node* createnode(int val)
{
	struct node *h=(struct node *)malloc(sizeof(struct node));
	h->val=val;
	h->left=h->right=NULL;
	return h;
}
struct node* insertnode(struct node *root,int val)
{
	if(!root){
		root=createnode(val);
		return root;
	}
	if(root->val>val) root->left=insertnode(root->left,val);
	if(root->val<val) root->right=insertnode(root->right,val);
	return root;
}

void print_LPR(struct node *root)
{
	if(!root) return;
	if(root->left!=NULL) print_LPR(root->left);	
	printf("%d ",root->val);
	if(root->right!=NULL) print_LPR(root->right);
}
void print_LRP(struct node *root)
{
        if(!root) return;
        if(root->left!=NULL) print_LRP(root->left);
        if(root->right!=NULL) print_LRP(root->right);
	printf("%d ",root->val);
}
void print_PLR(struct node *root)
{
        if(!root) return;
	 printf("%d ",root->val);
	if(root->left!=NULL) print_PLR(root->left);
        if(root->right!=NULL) print_PLR(root->right);
}

struct node* deletenode(struct node *root,int key)
{
	struct node *t;
	if(!root) return root;
	if(root->val>key) root->left=deletenode(root->left,key);
	else if(root->val<key) root->right=deletenode(root->right,key);
	else{
                if(root->left==NULL){
                        t=root->right;
                        free(root);
                        return t;
                }
                else if(root->right==NULL){
                        t=root->left;
                        free(root);
                        return t;
                }
                else{
                        t=findmin(root->right);
                        root->val=t->val;
                        root->right=deletenode(root->right,t->val);
                }
        }
	return root;
}
struct node* findnode(struct node *root,int key)
{
	struct node *temp=root;
	while(temp){
		if(temp->val==key) return temp;
		if(temp->val>key) temp=temp->left;
		else temp=temp->right;
	}
	return NULL;
}
struct node* findmax(struct node *root)
{
	if(!root) return root;
	struct node *temp=root;
	while(temp->right)
		temp=temp->right;
	return temp;
}
struct node* findmin(struct node *root)
{
        if(!root) return root;
        struct node *temp=root;
        while(temp->left)
                temp=temp->left;
        return temp;
}
struct node*  predecessor(struct node *root)
{
	if(!root || root->left==NULL) return root;
	return findmax(root->left);
}
struct node*  successor(struct node *root)
{
        if(!root || root->right==NULL) return root;
        return findmin(root->right);
}
int main()
{
	struct node *root=NULL,*newn;
	int n,val;
	printf("Enter no.of elements : ");
	scanf("%d",&n);
	printf("Enter %d numbers : ",n);
	for(int i=0;i<n;i++){
		scanf("%d",&val);
		root=insertnode(root,val);
	}
	printf("Printing elements in LRP order  :  ");
	print_LRP(root);
	printf("\nPrinting elements in PLR order  :  ");
	print_PLR(root);
	printf("\nPrinting elements in LPR order  :  ");
	print_LPR(root);
	printf("\nEnter the value of deletion : ");
	scanf("%d",&val);
	root=deletenode(root,val);
	printf("BST after deletion : ");
	print_LPR(root);
	newn=predecessor(root);
        printf("\nPredecessor  of root : %d",newn->val);
        newn=successor(root);
        printf("\nSuccessor  of root : %d",newn->val);
}
