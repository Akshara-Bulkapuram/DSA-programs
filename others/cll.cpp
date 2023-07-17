class Node {
public:
int data;
Node* next;
Node(int d) : data(d), next(nullptr) {}
};

class CircularLinkedList {
public:
Node* head;
CircularLinkedList() : head(nullptr) {}

void add_node(int data) {
	Node* new_node = new Node(data);
	if (head == nullptr) {
		head = new_node;
		new_node->next = head;
		return;
	}
	Node* current = head;
	while (current->next != head) {
		current = current->next;
	}
	current->next = new_node;
	new_node->next = head;
}
};
