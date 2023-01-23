#include<iostream>
using namespace std;
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};
//nodes will be created in heap using new operator
//address of root nodes imp
BstNode * GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
}
BstNode* Insert(BstNode * root,int data)
{
   if(root ==NULL)
   {
       //empty tree
       root  = GetNewNode(data);

   }
   else if(data<= root->data)
   {
       root->left = Insert(root->left,data);
   }
      else
   {
       root->right = Insert(root->right,data);
   }
   return root;
}
bool Search(BstNode*root,int data)
{
    if (root == NULL) return false;
    else if(root->data == data) return true;
    else if(data<=root->data) return Search(root->left,data);
    else  return Search(root->right,data);
}

int main()
{
BstNode *root = NULL; //setting tree as empty
root = Insert(root,13);
root = Insert(root,15);
root = Insert(root,23);
int num;
cout<<"Enter number to search: "<<endl;
cin>>num;
if(Search(root,num))
    cout<<"Found\n"<<endl;
else
    cout<<"Not found"<<endl;




}
