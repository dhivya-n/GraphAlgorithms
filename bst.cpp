#include<iostream>
using namespace std;
/****************Class bst******/
class BST
{
  struct node  
  {
     int value; 
     struct node *left,*right; 
  };
     struct node *root;
  public:
   BST();
   void search(node*t,int x);
   void insert(int x);
   void findmin(node *t);
   void findmax(node *t);
   void find(int x);
   void inorder(node*);
   void pre(node *t);
   void post(node *t);
node* create(int x)
{ 
  node *t=new node;
  t->value=x;
  t->left=NULL;
  t->right=NULL;
  return t;
}
node* insert(int x, node *t)
{
  if(t==NULL)
  {
    t=create(x);
  }
 else if(x<t->value)
    t->left=insert(x,t->left);
 else if(x>t->value)
   t->right=insert(x,t-> right);
return t;
}
};
BST::BST() 
{ 
  root=NULL; 
}
/**********Insert************/
void BST::insert(int x)
{
if(root==NULL)
 root=create(x);
else
 insert(x,root);
}
/**********Inorder************/
void BST::inorder(node *t)
{ 
  if(t!=NULL)
 {
  inorder(t->left);
  cout<<t->value<<"\t";
  inorder(t->right);
 }
}
/**********Search************/
void BST::search(node *t,int x)
{
  if(t!=NULL)
  {
    if(t->value>x)
     search(t->left,x);
   else if(t->value<x)
     search(t->right,x);
   else
      cout<<"\nthe element is found";
  }
 else
   cout<<"\nelement is not found";
}
/**********Find minimum************/
void BST::findmin(node *t)
{
  if(t->left!=NULL)
    findmin(t->left);
  else
   cout<<t->value;
}
/**********Find maximum************/
void BST::findmax(node *t)
{
  if(t->right!=NULL)
    findmax(t->right);
  else
   cout<<t->value;
}
/**********Preorder************/
void BST::pre(node *t)
{
    if (t!=NULL)
    {
        cout<<t->value <<"\t";
        pre(t->left);
        pre(t->right);
    }
}
/**********Postorder************/
void BST::post(node *t)
{
    if (t!=NULL)
    {
        
        post(t->left);
        post(t->right);
        cout<<t->value <<"\t";
    }
}
void BST::find(int x)
{
switch(x)
{
case 2:
    inorder(root);
break;
case 3:
 post(root);
break;
case 4:
   findmax(root);
break;
case 5:
   findmin(root);
break;
case 7:
   pre(root);
break;
default:
   search(root,x);
}
}
/**********Main function************/
int main()
{
   int ele,ch,n;
   BST t;   
    do
     {
        printf("\n\n-------------Menu---------------\n1.Insert\n2.Inorder\n3.Postorder\n4.Findmax\n5.Findmin\n6.search\n7.Preorder\n8.Exit\nchoice:"); 
        cin>>ch;
        switch(ch)
        {
           
           case 1:
             cout<<"Enter the number of elements:";
             cin>>n;
             cout<<"\nEnter the elements:";
             for(int i=0;i<n;i++)
             {
             cin>>ele;
             t.insert(ele);
              }
             break;
           case 2:
              t.find(2);
             break;
           case 3:
              t.find(3);
             break;
           case 4:
              t.find(4);
             break;
           case 5:
              t.find(5);
             break;
           case 6:
             cout<<"Enter the element to search:";
             cin>>ele;
             t.find(ele);                 
             break;
           case 7:
              t.find(7);
             break; 
           case 8:  
             cout<<"\nExiting............";
        }
      }while(ch!=8);
  
}


