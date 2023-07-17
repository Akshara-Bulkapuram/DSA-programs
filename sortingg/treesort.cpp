#include <iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node* newnode(int item){
    struct Node* temp= new Node;
    temp->key=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}


Node* insert(Node* root, int value){
    if(root==NULL){
        return newnode(value);
    }
    if (root->key<value){
        root->right=insert(root->right,value);
    }
    else if(root->key>value){
        root->left=insert(root->left,value);
    }
    return root;
}
void treeSort(int arr[], int n)
{
    struct Node *root = NULL;
  
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        root = insert(root, arr[i]);
  
    // Store inorder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}



void printarray(int arr[],int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;

}

int main(){
    int array[]={12,6,0,4,2,10,8};
    int n=sizeof(array)/sizeof(array[0]);
    treeSort(array,n);
    cout<< "sorted Array : ";
    printarray(array,n);
}