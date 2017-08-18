#include<iostream>
using namespace std;
class bst
{
	struct node
	{
		struct node *left,*right;
		int value;
	};
	struct node *root;
	public:
	bst()
	{
		root=NULL;
	}
	node* create(int x)
	{
		node *t=new node;
		t->value=x;
		t->left=NULL;
		t->right=NULL;
		return t;
	}
	node * insert(node *t,int x)
	{
		if(t==NULL)
		t=create(x);
		else
		if(x<t->value)
		t->left=insert(t->left,x);
		else if(x>t->value)
		t->right=insert(t->right,x);
		return t;
	}
	public:
	void insert(int x)
	{
		if(root==NULL)
		root=create(x);
		else
		insert(root,x);
	}
	void inorder(node *t)
	{
		if(t!=NULL)
		{
			inorder(t->left);
			cout<<"\t"<<t->value;
			inorder(t->right);
		}
	}
	void search(node *t,int x)
	{
		if(t!=NULL)
		{
			if(x<t->value)
			search(t->left,x);
			else if(x>t->value)
			search(t->right,x);
			else
			cout<<"\nFound";
		}
		else
		cout<<"\nNOt found";
	}
	void findmin(node *t)
	{
		if(t->left==NULL)
		cout<<t->value;
		else
		findmin(t->left);
	}
	void in()
	{
		inorder(root);
		int x;
		cin>>x;
		search(root,x);
		findmin(root);
	}
};
int main()
{
	bst b;
	for(int i=1;i<10;i++)
	{
		int x;
		cin>>x;
		b.insert(x);
	}
	b.in();
}
