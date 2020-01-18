#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
      TreeNode *left;
 TreeNode *right;
       
};
typedef TreeNode* Bstptr;
void insert(Bstptr &T,int x){
if(T==NULL){
Bstptr l=new TreeNode;
l->val=x;
l->left=l->right=NULL;
T=l;
}
else{
if(T->val<x){
insert(T->right,x);
}
else {
insert(T->left,x);
}
}
}


int  findmin(TreeNode* x)							//do inorder and check for consecutive ones
    {
        
        if(x->left==NULL)
            return x->val;
        return findmin(x->left);
    }
    int findmax(TreeNode* x)
    {if(x->right==NULL)
            return x->val;
        return findmax(x->right);
    }   
    int minDiffInBST(TreeNode* root) {
        static int mn=root->val;
        if(root->left==NULL && root->right==NULL)
            return mn;
        if(root->left!=NULL)
        {
            mn=min(mn,abs(root->val-findmax(root->left)));
            cout<<mn<<" ";
            return minDiffInBST(root->left);
        }
        if(root->right!=NULL)
        {
            mn=min(mn,abs(root->val-findmin(root->right)));
            cout<<mn<<" ";
            return minDiffInBST(root->right);
        }
        return mn;
    }
int main()
{	int n;
    cin>>n;
    Bstptr T=NULL;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        insert(T,x);
    }
    cout<<minDiffInBST(T);
    return 0;
}
