#include<stdio.h>
#include<malloc.h>
#include<conio.h>
typedef struct tree
{
    int data;
    struct tree *left,*right;
} tree;

tree *createnode(int n)
{
    tree *p;
    p=(tree *)malloc(sizeof(tree));
    p->data=n;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void insert(tree *x,int n)
{

    if(n>x->data)
    {
        if(x->right==NULL)
            x=x->right=createnode(n);
        else
            insert(x->right,n);
    }
    else
    {
        if(x->left==NULL)
            x=x->left=createnode(n);
        else
            insert(x->left,n);
    }

}

void preorder(tree *x)
{
    if(x!=NULL)
    {
    	printf("%d\t",x->data);
        preorder(x->left);
        preorder(x->right);
    }
}

void inorder(tree *x)
{
    if(x!=NULL)
    {
        inorder(x->left);
        printf("%d\t",x->data);
        inorder(x->right);
    }
}

void postorder(tree *x)
{
    if(x!=NULL)
    {
        postorder(x->left);
        postorder(x->right);
        printf("%d\t",x->data);
    }
}        
        



void main()
{
    tree *t;
    system("cls");
    t=(tree *)malloc(sizeof(tree));
    t->data=9;
    t->left=NULL;
    t->right=NULL;

    insert(t,5);
    insert(t,3);
    insert(t,2);
    insert(t,12);
    insert(t,6);

    postorder(t);
    getch();
}