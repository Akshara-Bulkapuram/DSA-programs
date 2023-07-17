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

int main(){

    struct node* p1=createnode(6);
    struct node* p2=createnode(7);
    struct node* p3=createnode(8);
    struct node* p4=createnode(0);
    struct node* p5=createnode(5);
    struct node* p6=createnode(7);
    struct node* p7=createnode(9);
            //the tree looks like this
            //       6
            //     /   \'
            //    7      8
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
    printf("\n");
    printf("%d",isBST(p1));



    return 0;
}
