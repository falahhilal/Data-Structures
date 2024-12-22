#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value) {
        key = value;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    TreeNode* insert(TreeNode* root, int key) {
        // Perform normal BST insert
        if (!root) {
        	root = new TreeNode(key);
        	return root;
        }
        if (key < root->key) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }

        // Update height of this ancestor node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Get the balance factor
        int balance = getBalance(root);

        // If the node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < root->left->key) {
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && key > root->right->key) {
            return leftRotate(root);
        }

        // Left Right Case
        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void preOrder(TreeNode* root) {
        if (root) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

private:
    int getHeight(TreeNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(TreeNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    TreeNode* leftRotate(TreeNode* z) {
        TreeNode* y = z->right;
        TreeNode* T2 = y->left;

        // Perform rotation
        y->left = z;
        z->right = T2;

        // Update heights
        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        // Return the new root
        return y;
    }

    TreeNode* rightRotate(TreeNode* z) {
        TreeNode* y = z->left;
        TreeNode* T3 = y->right;

        // Perform rotation
        y->right = z;
        z->left = T3;

        // Update heights
        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        // Return the new root
        return y;
    }
    
    int minval(TreeNode *&root){
	TreeNode *temp = root;
	while(temp->left!=NULL){
		temp= temp->left;
	}
	int ans = temp->key;
	return ans;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Step 1: Perform standard BST delete
        if (!root) {
            return root;
        }
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = minval(root->right);
            root->key = temp->key; // Copy the inorder successor's content to this node
            root->right = deleteNode(root->right, temp->key); // Delete the inorder successor
        }

        // Step 2: Update height of the current node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Step 3: Rebalance the node if needed
        return balance(root, key);
    }
    TreeNode* balance(TreeNode* node, int key) {
    	// Get the balance factor of the node
    	int balance = getBalance(node);
    	// Left Left Case
    	if (balance > 1 && getBalance(node->left) >= 0){
    		return rightRotate(node);
		}

    	// Left Right Case
    	if (balance > 1 && getBalance(node->left) < 0) {
        	node->left = leftRotate(node->left);
        	return rightRotate(node);
    	}

    	// Right Right Case
    	if (balance < -1 && getBalance(node->right) <= 0){
    		return leftRotate(node);
		}

   		 // Right Left Case
    	if (balance < -1 && getBalance(node->right) > 0) {
        	node->right = rightRotate(node->right);
        	return leftRotate(node);
    	}

    	return node; // Return the (possibly unchanged) node pointer
	}
};

int main() {
    AVLTree avl;
    TreeNode* root = NULL;

    // Insert nodes
    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int i=0;i<6;i++) {
        root = avl.insert(root, keys[i]);
    }

    // Preorder traversal
    cout << "Preorder traversal of the AVL tree is:" << endl;
    avl.preOrder(root);
    cout << endl;

    return 0;
}
