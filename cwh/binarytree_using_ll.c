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

};
int main(){

    //first node
    struct node *p1;
    p1   =  (struct node*)malloc(sizeof(struct node));
    p1->data=6;
    p1->left=NULL;
    p1->right=NULL;
    //second node
    struct node *p2;
    p2   =  (struct node*)malloc(sizeof(struct node));
    p2->data=5;
    p2->left=NULL;
    p2->right=NULL;
    //root node
    struct node *p;
    p   =  (struct node*)malloc(sizeof(struct node));
    p->data=2;
    p->left=p1;
    p->right=p2;//linking root node with left and right nodes

    struct node* p3=createnode(9);
    printf("%d",p3->data);
    return 0;
}
