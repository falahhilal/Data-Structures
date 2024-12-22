#include<iostream>
#include<queue>
using namespace std;
class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		Node (int x){
			data = x;
			left = NULL;
			right = NULL;
		}
		
};
Node *  insertInBST(Node *&root,int data){
	if (root==NULL){
		root = new Node(data);
	    return root;
	}
	if(data>root->data){
		root->right = insertInBST(root->right,data);
		
	}
	else{
		root->left= insertInBST(root->left,data);
	}
	return root;
}
void takeInput(Node *&root){
	int data=0;
	cout<<"enter the data "<<endl;
	cin>>data;
	while(data!=-1){
		root = insertInBST(root,data);
		cout<<"enter the data "<<endl;
		cin>>data;
	}
}

void BreadthFirst(Node *& root){
	queue<Node *>q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		if (temp == NULL){
			cout<<endl;
			if(!q.empty()){
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


int minval(Node *&root){
	Node *temp = root;
	while(temp->left!=NULL){
		temp= temp->left;
	}
	int ans = temp->data;
	return ans;
}
int maxval(Node *&root){
	Node *temp = root;
	while(temp->right!=NULL){
		temp= temp->right;
	}
	int ans = temp->data;
	return ans;
}

bool search(Node *&root,int key){
	if (root==NULL){
	return false;
	}
	if (root->data==key){
		return true;
	}
		
	if(key>root->data){
		return search(root->right,key);
	}
	else
	{
		return search(root->left,key);
	}
}

Node * deleteNode(Node *&root, int key) {
    if (root == NULL) {
        return root; // Key not found, return null
    }
    if (key == root->data) {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child (left)
        if (root->left != NULL && root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: One child (right)
        if (root->left == NULL && root->right != NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // Case 4: Two children
        if (root->left != NULL && root->right != NULL) {
            int min = minval(root->right);
            root->data = min; // Replace with the minimum value from the right subtree
            root->right = deleteNode(root->right, min); // Delete that minimum value
            return root; // Return updated root
        }
    } else {
        if (key < root->data) {
            root->left = deleteNode(root->left, key); // Search in left subtree
        } else {
            root->right = deleteNode(root->right, key); // Search in right subtree
        }
    }
    return root; // Return the unchanged root pointer
}



int main(){
	Node *root=NULL;
	takeInput(root);
	BreadthFirst(root);
	bool ans= search(root,6);
	if(ans==true){
		cout<<"found"<<endl;
	}
	else{
		cout<<"Not found"<<endl;
	}
	cout<<" min val is "<<minval(root);
	cout<<"ENTER THE VAL TO DELT THAT NODE "<<endl;
	int data;
	cin>>data;
	deleteNode(root,data);
	BreadthFirst(root);
	
	return 0;
	
}
