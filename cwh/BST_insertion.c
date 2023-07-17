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
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
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
// void insert(struct node *root, int key){
//    struct node *prev = NULL;
//    while(root!=NULL){
//        prev = root;
//        if(key==root->data){
//            printf("Cannot insert %d, already in BST", key);
//            return;
//        }
//        else if(key<root->data){
//            root = root->left;
//        }
//        else{
//            root = root->right;
//        }
//    }
//    struct node* new = createNode(key);
//    if(key<prev->data){
//        prev->left = new;
//    }
//    else{
//        prev->right = new;
//    }
// }

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

    // inorder(p1);
    // printf("\n");
    // printf("%d",isBST(p1));

    // printf("\n");
    // printf("\n");
    // struct node* index = search(p1,9);
    // if (index!=NULL){
    //     printf("element found! \n");
    // }
    // else{
    //     printf("element  not found");
    // }
    int k=insert(p1,9);
    printf("%d\n",k);
    int kz=insert(p1,4);
    printf("%d\n",kz);

    return 0;
}
