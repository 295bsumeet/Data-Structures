
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
        int data;	
        struct node *lchild;
        struct node *rchild;
				 //int flag;
}*root=NULL,*p,*q,*r;

typedef struct node node;

struct stack
{
	node *t;
	struct stack *next;
	int flag;
}*start=NULL,*y,*k,*top=NULL;
	
void push(node *x)
{
	if(start==NULL)
	{
		start=(struct stack*)malloc(sizeof(struct stack));		start->t=x;
		start->next=NULL;
		top=start;
		top->flag=0;
	}
	else
	{
		y=(struct stack*)malloc(sizeof(struct stack));
		y->t=x;
	    y->next=NULL;
		k=start;
		while(k->next!=NULL)
		k=k->next;
		k->next=y;
		top=y;
		top->flag=0;
	}
}
	
node* pop()
{
	node *i;
	struct stack *k;
	if(start==NULL&&top==NULL)
	{
		printf("tree is empty");
	}
	else if(start!=NULL&&start->next==NULL&&top==start)
	{
		top=NULL;
		i=start->t;
		start=NULL; //to perform pop operation on stack
		return i;
	}
	else
	{
		k=start;
		while(k->next->next!=NULL)
			k=k->next;
		top=k;
		y=k->next;
		k->next=NULL;
		i=y->t;
		y=NULL;
		return i;
	}
}

node* first_node(int data1)
{
	q=(node*)malloc(sizeof(node));
	q->data=data1;
	q->lchild=q->rchild=NULL;
	return q;
}

void other_node()
{
	int ch1,data1;
	if(root==NULL)
	{
		//root=(node*)malloc(sizeof(node));  //to create the  tree
		printf("\n\tEnter data for the tree");
		scanf("%d",&data1);
		root=first_node(data1);
	}
	else
	{
		do
	    {
			p=root;
			printf("\n\tEnter data for the tree");
	        scanf("%d",&data1);
label:      if(data1<p->data&&p->lchild==NULL)
			{
				p->lchild=first_node(data1			}
			else if(data1<p->data&&p->lchild!=NULL)
			{
				p=p->lchild;
				goto label;
			}
			else if(data1>p->data&&p->rchild==NULL)
			{
				p->rchild=first_node(data1);                                                                                                      
			}
			else if(data1>p->data&&p->rchild!=NULL)
			{      
				p=p->rchild;
				goto label;
			}
			else
				printf("\n\tOne of the numbers is already repeated in the tree");
			printf("\nWant u to join more node?");                                                             
			scanf("%d",&ch1);
		}while(ch1!=0);
	}
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

node* mirror_img(node *t)
{
   node *temp;
   if(t!=NULL)
   {
      temp=t->lchild;
      t->lchild=t->rchild;
      t->rchild=temp;
      mirror_img(t->lchild);
      mirror_img(t->rchild);
   }
   
  return t;
}

int count_lnodes(node *t)
{
   if(t==NULL)
     return 0;
   else
   {
      if(t->lchild==NULL && t->rchild==NULL)
         return 1;
      else
         return(count_lnodes(t->lchild)+count_lnodes(t->rchild));
   }
}

int Max(int i,int j)
{
  if(i>=j)
    return i;
  else 
  return j;  
}

int depth(node *t)
{
   if(t==NULL)
      return 0;
   else
      return(1+Max(depth(t->lchild),depth(t->rchild)));
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

void main()
{
	int ch,ch1,c,c1,n,d,m,ch2;
	node *rootm;
	//clrscr();
	do
	{
	 printf("\n\t***MENU***\n1.Create binary tree\n2.Traversal by using recursion\n3.Traversal by using non recursion\n4.Level-wise Printing of a tree\n5.Mirror Image of a tree\n6.Counting Leaf nodes\n7.Depth of a tree\n8.Exit");
	 scanf("%d",&ch);

	 switch(ch)
	 {
		case 1:
                other_node();
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
			printf("The level wise printing of tree is:\t");
			levelwise_print(root);
			break;

		case 5:
                rootm=mirror_img(root);
		        printf("\nMirror image of the tree is saved...");
		        break;

		case 6:
               n=count_lnodes(root);
		       printf("\nThere are %d leaf nodes in this tree",n);
		       break;

		case 7:
               d=depth(root);
		       printf("\n%d is the depth of the tree",d);
		       break;

		case 8:
			exit(0);

		}
	//printf("\nDo you wish to continue??\n1.Yes\t0.No.");
    //scanf("%d",&ch1);
	}while(1);
}
