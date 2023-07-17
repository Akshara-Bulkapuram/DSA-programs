class Node {
public:
int data;
Node* next;
Node* prev;
Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
Node* head;
DoublyLinkedList() : head(nullptr) {}

void add_node(int data) {
	Node* new_node = new Node(data);
	new_node->next = head;
	if (head != nullptr) {
		head->prev = new_node;
	}
	head = new_node;
}
};
