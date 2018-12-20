#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data;
	struct node*lchild,*rchild;
}*p,*q,*root=NULL;

//to generate a node
struct node*getnode()
{
	q=(struct node*)malloc(sizeof(struct node));
	printf("Accept data\t");
	scanf("%d",&q->data);
	q->lchild=q->rchild=NULL;
	return(q);
}

//stack code starts
struct stack
{
	int flag;
	struct node*t;
	struct stack*next;
}*start=NULL,*y,*z,*top;

void push(struct node*x) //push operation of stack
{
	if(start==NULL)
	{
		start=(struct stack*)malloc(sizeof(struct stack));
		start->t=x;
		start->next=NULL;
		top=start;
		top->flag=0;
	}
	else
	{
		y=(struct stack*)malloc(sizeof(struct stack));
		y->t=x;
		y->next=NULL;
		z=start;
		while(z->next!=NULL)
		{
			z=z->next;
		}
		z->next=y;
		top=y;
		top->flag=0;
	}
}

struct node* pop()//pop operation of stack
{
	struct node*i;
	struct stack*k;
	if(start==NULL)
	{
		printf("Tree is empty");
    }
	else if(start!=NULL&&start->next==NULL)
	{
		i=start->t;
		start=NULL;
		top=NULL;
		return i;
	}
	else
	{
		k=start;
		start=start->next;
		k->next=NULL;
		i=k->t;
		return i;
	}
	return 0;
}

//display operation of stack
void display()
{
	for(y=start;y!=NULL;y=y->next)
	{
		printf("%d ",y->t->data);
	}
}
//stack code ends

//create code for binary tree
void create()
{
	char ch;
	int ch1;
	do
	{
	if(root==NULL)
	root=getnode();
	else
	{
		p=root;
		A:	printf("Where do you want to add (R/L) of %d\t",p->data);
		//flushall();
		scanf("%s",&ch);
		if(ch=='l')
		{
			if(p->lchild==NULL)
			{
				p->lchild=getnode();
			}
			else
			{
				p=p->lchild;
				goto A;
			}
		}
		else if(ch=='r')
		{
			if(p->rchild==NULL)
			{
				p->rchild=getnode();
			}
			else
			{
				p=p->rchild;
				goto A;
			}
		}
	}
	printf("Do you wish to enter more?\t");
	scanf("%d",&ch1);
	}while(ch1!=0);
}

//differnt order printing using recursion
void preorder(struct node*t)
{
	if(t!=NULL)
	{
	printf("%d",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void postorder(struct node*t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%d",t->data);
	}
}
void inorder(struct node*t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		printf("%d",t->data);
		inorder(t->rchild);
	}
}

//different order printing using non recursion
void non_preorder(struct node*p)
{
	push(p);
	while(top!=NULL)
	{
		p=pop();
		while(p!=NULL)
		{
			if(p->rchild!=NULL)
			{
				push(p->rchild);
			}
			printf("%d",p->data);
			p=p->lchild;
		}
	}
}
void non_inorder(struct node*p)
{
	while(1)
	{
		while(p!=NULL)
		{
			push(p);
			p=p->lchild;
		}
		if(top==NULL)
			break;
		p=pop();
		printf("%d",p->data);
		p=p->rchild;
	}
}

int non_postorder(struct node*p)
{
	while(1)
	{
		while(p!=NULL)
		{
				push(p);
				p=p->lchild;
		}
		while(top->flag==1)
		{
			p=pop();
			printf("%d",p->data);
			if(top==NULL)
			{
				return 0;
			}
	}
		if(top->flag!=1)
		{
			top->flag=1;
			p=top->t->rchild;
		}
	}
}

//levelwise printing
void levelwise_print(struct node*p)
{
	if(p!=NULL)
	push(p);
	do
	{
		p=pop();
		printf("%d",p->data);
		if(p->lchild!=NULL)
			push(p->lchild);
		if(p->rchild!=NULL)
			push(p->rchild);
	}while(start!=NULL);
}

void mirror_image(struct node*t)
{
	if(t!=NULL)
	{
		struct node*temp=NULL;
		temp=t->lchild;
		t->lchild=t->rchild;
		t->rchild=temp;
		mirror_image(t->lchild);
		mirror_image(t->rchild);
	}
}

int count_node(struct node*t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		if(t->lchild==NULL&&t->rchild==NULL)
			return 1;
		else
			return(count_node(t->lchild)+count_node(t->rchild));
	}
}

int max(int i,int j)
{
	if(i>=j)
		return i;
	else
		return j;
}

int depth(struct node*t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		return (1+max(depth(t->lchild),depth(t->rchild)));
	}
}

int main()
{
	int ch1,ch2,m,n;
	//clrscr();
	do
	{
		printf("\n\t***MENU***\n1.Create\n2.Traversal by using recursion\n3.Traversal by using non recursion\n4.Mirror image\n5.Count node\n6.Depth\n7.Level-wise Printing\n8.Exit\t");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:
				create();
				break;
			case 2:
				printf("\t1.Preorder\t2.Inorder\t3.Postorder");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1:
						printf("The Preorder is: ");
				preorder(root);
						break;
					case 2:
			printf("The Inorder is: ");
						inorder(root);
						break;
					case 3:
						printf("The Postorder is: ");
						postorder(root);
						break;
				}
				break;
			case 3:
				printf("\t1.Preorder\t2.Inorder\t3.Postorder\t");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1:
						printf("The Preorder is: ");
						non_preorder(root);
						break;
					case 2:
						printf("The Inorder is: ");
						non_inorder(root);
						break;
					case 3:
						printf("The Postorder is: ");
						non_postorder(root);
						break;
				}
				break;
			case 4:
				mirror_image(root);
				printf("The mirror image have been saved.\n");
				break;
			case 5:
				m=count_node(root);
				printf("The no. of Nodes are %d.",m);
				break;
			case 6:
				n=depth(root);
				printf("The Depth of the tree is %d.",n);
				break;
			case 7:
				levelwise_print(root);
				break;
			case 8:
				exit(0);
			}
		//printf("\nDo you want to continue\t");
		//scanf("%d",&ch2);
	}while(ch2);
}
