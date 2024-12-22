#include<queue>
#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *left;
  Node *right;
  
  Node (int x){
      data = x;
      left=NULL;
      right=NULL;
  }
};
Node* createTree(Node *root){
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if (data ==-1){
        return NULL;
    }
    cout<<"Enter the left data of "<<data<<endl;
    root->left=createTree(root->left);
    cout<<"Enter the right data of data"<<data<<endl;
    root->right=createTree(root->right);
    return root;
}
void leveltraversal(Node *root){
	queue<Node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node*temp = q.front();
		q.pop();
		if (temp==NULL){ //level complete honae pae 
			cout<<endl;
			if (!q.empty()){ // agr child nodes hon
				q.push(NULL);
			}	
		}
		else{
			cout<<" "<<temp->data;
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
  	}
}

void Inorder(Node *&root){
	if (root == NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
	
}
void preOrder(Node *&root){
	if(root ==NULL){
		return;
	}
	cout<<" "<<root->data;
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Node *&root){
	if (root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<" "<<root->data;
}

int findleafs(Node *&root)
{
	if(root ==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return 1;
		
	}
	return findleafs(root->left)+findleafs(root->right);
	
}

int height(Node *&root){
	if (root==NULL){
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	int ans = max(left,right)+1;
	return ans;
}

int diameter(Node *&root){
	if (root==NULL){
		return 0;
		
	}
	int h1= diameter(root->left);
	int h2= diameter(root->right);
	int h3= height(root->left ) + height(root->right)+1;
	int ans ;
	if(h1>h2 &&h1>h3){
		ans = h1;
	}
	else if(h2>h1 && h2>h3){
		ans = h2;
	}
	else {
		ans = h3;
	}
	return ans;
}
int main() {
   Node *root;
   root =createTree(root);
 
   leveltraversal(root);
   
   cout<<"Inorder traversal :  ";
   Inorder(root);
   cout<<endl;
   cout<<"Preorder traversal :  ";
   preOrder(root) ;
   cout<<endl;
     
   cout<<"Postorder traversal :  ";
   postOrder(root) ;
   
   
   cout<<endl;
   
   int leafs=findleafs(root);
   cout<<" leafs are "<<leafs<<endl;
   
   int len = height(root);
   cout<<"height of tree is "<<len<<endl;
   
   int dia=diameter(root);
   cout<<" diameter of tree is :"<<dia<<endl;
    return 0;
}

