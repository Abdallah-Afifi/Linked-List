#include <iostream>

template <class T>
class Node {
private:
	T info;
	Node<T>* next, * back;

public:
	Node() {
		next = NULL;
		back = NULL;
	}
	//getters
	T get_info() {
		return info;
	}
	Node<T>* get_next() {
		return next;
	}
	Node<T>* get_back() {
		return back;
	}

	//setters
	void set_info(T info_p) {
		info = info_p;
	}
	void set_next(Node<T>* n) {
		next = n;
	}
	void set_back(Node<T>* b) {
		back = b;
	}

	~Node() {

	}
};

template <class T>
class My_list {
private:
	Node<T>* head, * tail;

public:
	My_list() {
		head = NULL;
		tail = NULL;
	}

	Node<T>* get_head() {
		return head;
	}

	Node<T>* get_tail() {
		return tail;
	}

	Node<T>* append(T info_p) {
		Node<T>* temp = new Node<T>();
		temp->set_info(info_p);
		if (head == NULL) {
			//first element in the list
			head = temp;
			tail = head;

		}
		else {
			//not the first element
			/*
			1.temp becomes tail
			2.temp->next = NULL
			3.temp->back = old tail
			4.old tail->next = temp
			*/
			temp->set_back(tail);
			tail->set_next(temp);
			temp->set_next(NULL);
			tail = tail->get_next();
		}
		return temp;
	}

	//insert_after method
	Node<T>* insert_after(Node<T>* curr, T info) {
		Node<T>* temp = new Node<T>(); //creating a new node
		temp->set_info(info);  //getting the info for the new node
		if ()
		temp->set_next(curr->get_next());  //setting the next pointer of the new node to the next of current node
		temp->set_back(curr); //setting the back of the new node to the current node
		curr->get_next()->set_back(temp);  //setting current as the back of temp 
		curr->set_next(temp);  //setting the next of the current to temp
	}

	~My_list() {

	}
};


int main() {
	My_list<int> list;
	Node<int>* node1 = list.append(1);
	Node<int>* node2 = list.append(2);
	Node<int>* node3 = list.append(3);

	std::cout << "List elements: ";
	Node<int>* curr = list.get_head();
	while (curr != nullptr) {
		std::cout << curr->get_info() << " ";
		curr = curr->get_next();
	}
	std::cout << std::endl;

	Node<int>* node4 = list.insert_after(node2, 4);

	std::cout << "List elements after insertions: ";
	curr = list.get_head();
	while (curr != nullptr) {
		std::cout << curr->get_info() << " ";
		curr = curr->get_next();
	}
	std::cout << std::endl;

	return 0;
}

