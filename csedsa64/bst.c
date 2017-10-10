#include<stdio.h>
#include<stdlib.h>
 struct tree
{
        struct tree *left;
        int info;
        struct tree *right;
};

void postorder(struct tree *root);
void inorder(struct tree *root);
void preorder(struct tree *root);
struct tree *insert(struct tree *root, int item);
struct tree *delete_caseab(struct tree *root, struct tree *loc, struct tree *par);
struct tree *delete(struct tree *root,int item);
struct tree *delete_casec(struct tree *root, struct tree *loc, struct tree *par);





main()
{
	struct tree *root=NULL;
	int n,item,ch;
	while (1)
	{
		printf("\n1.Create\n2.PreOrder\n3.Inorder\n4.Postorder\n5.Delete\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("ENter the item to Insert");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				printf("Ente the item to delete:");
				scanf("%d",&item);
				root=delete(root,item);
				break;
		}
	}
}



struct tree *insert(struct tree *root, int item)
{
	struct tree *par,*loc,*newnode;
	par=NULL;
	loc=root;
	while(loc!=NULL)
	{
		if(item==loc->info)
		{
			printf("Duplicate");
			return;
		}
	par=loc;
	if(item < loc->info)
	{
		loc=loc->left;
	}
	else
	{
		loc=loc->right;
	}
	}
	newnode=(struct tree*)malloc(sizeof(struct tree));
	newnode->info=item;
	newnode->left=NULL;
	newnode->right=NULL;
	if(par==NULL)
	{
		root=newnode;
	}
	else if(item < par->info)
	{
		par->left=newnode;
	}
	else
	{
		par->right=newnode;
	}
	return(root);
	
}
void preorder(struct tree *root)
{
	struct tree *temp;
	temp=root;
	if(temp!=NULL)
	{
		printf("%d ",temp->info);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(struct tree *root)
{
        struct tree *temp;
        temp=root;
        if(temp!=NULL)
        {
                
                inorder(temp->left);
		printf("%d ",temp->info);

                inorder(temp->right);
        }
}
void postorder(struct tree *root)
{
        struct tree *temp;
        temp=root;
        if(temp!=NULL)
        {
               
                postorder(temp->left);
                postorder(temp->right);
		printf("%d ",temp->info);

        }
}

struct tree *delete(struct tree *root,int item)
{
	struct tree *loc,*par;
	loc=root;
	par=NULL;
	while(loc!=NULL && item!=loc->info)
	{
		par=loc;
	
	if(item<loc->info)
	{
		loc=loc->left;
	}
	else
	{
		loc=loc->right;
	}
	}
	if(loc==NULL)
	{
		printf("NOT FOUND");
	}
	if(loc->left!=NULL && loc->right!=NULL)
	{
		root=delete_casec(root,loc,par);
	}
	else
	{
		root=delete_caseab(root,loc,par);
	}
	free(loc);
	return(root);
}
struct tree *delete_caseab(struct tree *root, struct tree *loc, struct tree *par)
{
	struct tree *child;
	if(loc->left==NULL && loc->right==NULL)
	{
		child=NULL;
	}	
	else if(loc->left!=NULL)
	{
		child=loc->left;
	}
	else
	{
		child=loc->right;
	}
	if(par!=NULL)
	{
		if(loc=par->left)
		{
			par->left=child;
		}
		else
		{
			par->right=child;
		}
	}
	else
	{
		root=child;
	}
	return(root);
}

struct tree *delete_casec(struct tree *root, struct tree *loc, struct tree *par)
{
	struct tree *suc,*parsuc,*ptr,*save;
	
	suc=loc->right;
	parsuc=loc;
	while(par->left!=NULL)
	{
		parsuc=suc;
		suc=suc->left;
		
	}
	suc=ptr;
	parsuc=save;
	root=delete_caseab(root,suc,parsuc);
	if(par!=NULL)
	{
		if(loc==par->left)
		{
			par->left=suc;
		}
		else
		{
			par->right=suc;
		}
	}
	else
	{
		root=suc;
	}
	suc->left=loc->left;
	suc->right=loc->right;
	return(root);
}	
