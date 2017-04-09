#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct node *queue[20];
long long int front=0,rear=0;
struct node * insert(struct node *root,long long int data);
struct node * getNewnode(long long int data);
long long int search(struct node *root,long long int data);
long long int findmin(struct node *root);
long long int findmax(struct node *root);
void levelorder(struct node *root);
void preorder(struct node *root);
void inorder(struct node *root );
void postorder(struct node *root);
void print(struct node *root);
int findheight(struct node *root);
struct node
{
	long long int data;
	struct node *left;
	struct node *right;
};
int main()
{
	long long int t,data,c,n;
	struct node *root=NULL;
	do
	{
		printf("What u want to perform \n1.insert\n2.search\n3.exit\n");
		scanf("%lld",&c);
		printf("enter the number\n");
		scanf("%lld",&data);
		if(c==1)
			root=insert(root,data);
		else if(c==2)
		{
			t=search(root,data);
			if(t==1)
				printf("\nfound\n");
			else
				printf("\nnot found\n");
		}
	}while(c!=3);
	print(root);
	printf("want to find the min and max in tree\n");
	scanf("%lld",&n);
	if(n==1)
		printf("%lld\n",(findmin(root)));
	else
		printf("%lld\n",(findmax(root)));
	printf("the levelorder traversal is \n");
	levelorder(root);
	printf("\n");
	printf("the preorder traversal is \n");
	preorder(root);
	printf("\n");
	printf("the inorder traversal is \n");
	inorder(root);
	printf("\n");
	printf("the postorder traversal is \n");
	postorder(root);
	printf("\n");
	printf("The height of the tree is\n");
	printf("%d\n",(findheight(root)));
	return 0;
}
struct node * getNewnode(long long int data)
{
	struct node * newnode= (struct node *) malloc(sizeof(struct node ));
	newnode->data=data;
	newnode->right=newnode->left=NULL;
	return newnode;
}
struct node * insert(struct node *root,long long int data)
{
	if(root==NULL)
	{
		root=getNewnode(data);
		return root;
	}
	else if(data<=root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
long long int search(struct node * root,long long int data)
{
	if(root==NULL)
		return 0;
	if(root->data==data)
		return 1;
	if(data<=root->data)
		return search(root->left,data);
	else
		return search(root->right,data);
}
long long int findmin(struct node *root)
{

	struct node *current=root;
	if(root==NULL)
	{
		printf("error\n");
		return 0;
	}
	if(current->left==NULL)
		return current->data;
	return findmin(current->left);
}
long long int findmax(struct node *root)
{

	struct node *current=root;
	if(root==NULL)
	{
		printf("error");
		return 0;
	}
	if(current->right==NULL)
		return current->data;
	return findmax(current->right);
}
void print(struct node *root)
{
	struct node *current=root;
	while(current!=NULL)
	{
		printf("%lld ",current->data);
		current=current->left;
	}
	current=root;
	printf("\n");

	while(current!=NULL)
	{
		printf("%lld ",current->data);
		current=current->right;
	}
}
void levelorder(struct node *root)
{
	if(root==NULL)
		return;
	queue[rear++]=root;
	if(front!=-1 && rear!=-1)
	{
		struct node *current=root;
		front++;
		printf("%lld ",current->data);
		if(root->left!=NULL)
			queue[rear++]=root->left;
		else if(root->right!=NULL)
			queue[rear++]=root->right;
	}
}
void preorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%lld ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%lld ",root->data);
	inorder(root->right);
}
void postorder(struct node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%lld ",root->data);
}
int findheight(struct node *root)
{
	int left,right;
	if(root==NULL)
		return -1;
	left=findheight(root->left);
	right=findheight(root->right);
	return (left>right?left:right)+1;
}