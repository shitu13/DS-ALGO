// Constructing a Tree and Traversal - InOrder, PreOrder, PostOrder, LevelOrder.


#include <bits/stdc++.h>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in the left of: " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in the right of: " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) { // Previous level is finished
            cout << endl;
            if (!q.empty()) {  // queue still has some child nodes
                
                q.push(NULL);
            }
        }

        else {
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node* root){
    //base case
    if(root == NULL)
        return;

    inOrder(root-> left);
    cout << root -> data << " ";
    inOrder(root -> right);
    
}

void preOrder(node* root){
    //base case
    if(root == NULL)
        return;

    cout << root -> data << " ";
    preOrder(root-> left);
    preOrder(root -> right);
    
}

void postOrder(node* root){
    //base case
    if(root == NULL)
        return;

    postOrder(root-> left);
    postOrder(root -> right);
    cout << root -> data << " ";
    
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    
    cout << "Enter data for root: " <<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout << "Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin >> leftData;
        
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }
        
        cout << "Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin >> rightData;
        
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
    
}


int main() {

    node* root = NULL;

    // creating a Tree
    root = buildTree(root);
    levelOrderTraversal(root);

    cout<<endl << "Inorder Traversal is: ";
    inOrder(root);
    

    cout<<endl << "Preorder Traversal is: ";
    preOrder(root);


    cout<<endl << "Postorder Traversal is: ";
    postOrder(root);

    cout<<endl<<endl;
    
    cout<< "For level Order Traversal" <<endl;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    
  
    
    return 0;
}