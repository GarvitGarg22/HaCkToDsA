#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeinput_Levelwise(){

int rootdata;
cout<<"Enter root data ";
cin>>rootdata;

TreeNode<int>* root = new TreeNode<int>(rootdata);

queue<TreeNode<int>*> pendingNodes;
pendingNodes.push(root);

while (pendingNodes.size()!=0)
{   
    int numchild;
    TreeNode<int> * front = pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter the number of childs of "<<front->data<<" ";
    cin>>numchild;
    
    for (int i = 0; i < numchild; i++)
    {
        int data;
        cout<<"Enter the "<<i<<"th cild of "<<front->data<<endl;
        cin>>data;
        TreeNode<int>*child = new TreeNode<int>(data);
        pendingNodes.push(child);
        front->children.push_back(child);

    }
    
}
    return root;
}

TreeNode<int>* takeinput(){

int rootData;
cout<<"Enter root data "<<endl;
cin>>rootData;

TreeNode<int> *root = new TreeNode<int>(rootData);

int n;
cout<<"Number of children of "<<rootData<<endl;
cin>>n;

for (int i = 0; i < n; i++)
{
    TreeNode<int> * child = takeinput();
    root->children.push_back(child);

}
return root;

}


void printTree(TreeNode<int>* root){

if(root==NULL){
    return;
}

cout<<root->data<<": ";

for (int i = 0; i < root->children.size(); i++)
{
    cout<<root->children[i]->data<<", ";
}

cout<<endl;
for (int i = 0; i < root->children.size(); i++)
{
    printTree(root->children[i]);
}
}

void print_levelwise(TreeNode<int>* root){

queue<TreeNode<int>*> pendingchilds;
pendingchilds.push(root);

while(pendingchilds.size()!=0){
TreeNode<int>*front = pendingchilds.front();
cout<<front->data<<": ";
pendingchilds.pop();
for (int i = 0; i < front->children.size(); i++)
{
    cout<<front->children[i]->data<<" ";
    pendingchilds.push(front->children[i]);
}
cout<<endl;
}

}

int numnodes(TreeNode<int>* root){
if(root==NULL){
    return 0;
}
int ans = 1;
for (int i = 0; i < root->children.size(); i++)
{
    ans += numnodes(root->children[i]);
}

return ans;

}

int main(){

TreeNode<int>* root = takeinput_Levelwise();
print_levelwise(root);
cout<<"Number of nodes present in your tree "<<endl;
cout<<numnodes(root);
}