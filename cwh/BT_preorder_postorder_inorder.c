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

struct node* preorder(struct node* root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node* postorder(struct node* root){
    if(root!=NULL){
        
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

struct node* inorder(struct node* root){
    if(root!=NULL){
        
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}


int main(){

    struct node* p1=createnode(5);
    struct node* p2=createnode(9);
    struct node* p3=createnode(1);
    struct node* p4=createnode(0);
    struct node* p5=createnode(6);
    struct node* p6=createnode(3);
    struct node* p7=createnode(4);
    struct node* p8=createnode(7);
            //the tree looks like this
            //       5
            //     /   \'
            //    9      1
            //  /   \   /  \'
            // 0     6 3    4
            //        /
            //       7
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=p6;
    p3->right=p7;
    p6->left=p8;


    preorder(p1);
    printf("\n");
    postorder(p1);
    printf("\n");
    inorder(p1);
    printf("\n");
    
    return 0;
}
