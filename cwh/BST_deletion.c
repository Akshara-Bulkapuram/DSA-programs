#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node *p;
    p   =  (struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;

}


struct node* inorder(struct node* root){
    if(root!=NULL){
        
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

int isBST(struct node* root){
    static struct node* prev=NULL;
    if(root!=NULL){
        
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
        }
    else {
        return 1;
        }
        
}
struct node* search(struct node* root,int key){
    
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if (root->data>key)
    {
         search(root->left,key);
    }
    else{
         search(root->right,key);
    }
    
}
int insert(struct node* root, int val){
    static struct node* prev=NULL;
    if(root==NULL&& prev!=NULL){
        if(val>prev->data){
            prev->right=createnode(val);
        }
        else{
            prev->left=createnode(val);
        }
    return 1;
    }
    if (root->data==val){
        printf("\ninsertion failed!\n");
        return 0;
    }
    else if(root->data>val){
        prev=root;
        root=root->left;
        return insert(root,val);
    }
    else{
        prev=root;
        root=root->right;
        return insert(root,val);
    }

}
struct node *inOrderPredecessor(struct node* root){
    //right most node of left subtree is inorder predecessor
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root->left= deleteNode(root->left,value);
    }
    else if (value > root->data){
        root->right= deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left= deleteNode(root->left, iPre->data);
    }
    return root;
}









int main(){

    struct node* p1=createnode(6);
    struct node* p2=createnode(1);
    struct node* p3=createnode(8);
    struct node* p4=createnode(0);
    struct node* p5=createnode(5);
    struct node* p6=createnode(7);
    struct node* p7=createnode(9);
            //the tree looks like this
            //       6
            //     /   \'
            //    1      8
            //  /   \   /  \'
            // 0     5 7    9
            //          
            //            
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=p6;
    p3->right=p7;

    inorder(p1);
    printf("\nroot is %d",p1->data);
    printf("\n");
    deleteNode(p1,7);
    inorder(p1);
    printf("\nroot is %d",p1->data);
    printf("\n");
    deleteNode(p1,6);
    inorder(p1);
    printf("\nroot is %d",p1->data);


    return 0;
}
