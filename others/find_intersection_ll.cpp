// C++ Program for the above approach
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	bool visited;
	Node(int data){
		this->data = data;
		this->next = NULL;
		this->visited = false;
	}
};

int getIntersectNode(Node* head1, Node* head2){
	Node* temp1 = head1;
	while(temp1 != NULL){
		temp1->visited = true;
		temp1 = temp1->next;
	}
	
	temp1 = head2;
	while(temp1 != NULL){
		if(temp1->visited)
			return temp1->data;
		else
			temp1->visited = true;
		temp1 = temp1->next;
	}
    return -1;
}

// driver program
int main(){
	Node* head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(4);
	head1->next->next->next->next = new Node(5);
	head1->next->next->next->next->next = new Node(6);
	head1->next->next->next->next->next->next = new Node(7);
	// list 2
	Node* head2 = new Node(10);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next->next->next;
	
	cout<<"The node of intersection is : "<<getIntersectNode(head1, head2);
	return 0;
}

