#pragma once

template <typename T>
struct ChainNode {
	T element;
	ChainNode<T>* next;
	// Initialize the node.
	ChainNode(T e = 0, ChainNode<T>* n = nullptr) :element(e), next(n) {}
};

template <typename T>
class Chain
{
protected:
	int m_size;
	ChainNode<T>* headnode;
	// Initialize the header.
	void init();
public:
	// Return "m_size".
	int size() const;
	// Judge whether the Chian is empty.
	bool empty() const;
	// By default, 
	// when creating a "Chain" object:
	// "m_size" is set to "0",
	// "headnode" is created and points to nullptr.
	Chain();
	// Store information in headnote.
	Chain(T);
	// Delete every node in the chain.
	~Chain();
	// Return the reference of the information in headnode.
	T& info();
	// Return the pointer of the first node.
	ChainNode<T>* get_firstNode() const;
	// With a single "const T&" parameter (as "data"),
	// create and insert a new node after "headnode";
	// meanwhile, increase "m_size".
	void insert(const T&);
	// With a "LNode<T>" pointer a "const T&" parameter (as "data"),
	// create and insert a new node after the node pointed;
	// meanwhile, increase "m_size".
	void insert(ChainNode<T>*, const T*);
	// Return the "i"th node.
	ChainNode<T>* get_node(int);
	// Bin Sort.
	void binSort(int);

};



template<class T>
int Chain<T>::size() const {
	return m_size;
}

template<class T>
bool Chain<T>::empty() const {
	return !m_size;
}

template<class T>
void Chain<T>::init() {
	headnode = new ChainNode<T>;
	headnode->next = nullptr;
	m_size = 0;
}

template<class T>
Chain<T>::Chain() {
	init();
}

template<class T>
Chain<T>::Chain(T info) {
	init();
	headnode->element = info;
}

template<class T>
Chain<T>::~Chain() {
	ChainNode<T>* p = headnode;
	while (headnode) {
		p = p->next;
		delete headnode;
		headnode = p;
	}
}

template<class T>
T& Chain<T>::info() {
	return headnode->element;
}

template<class T>
ChainNode<T>* Chain<T>::get_firstNode() const {
	return headnode->next;
}


template<class T>
void Chain<T>::insert(const T& e) {
	m_size++;
	ChainNode<T>* p = new ChainNode<T>(e, headnode->next);
	headnode->next = p;
}

template<class T>
void Chain<T>::insert(ChainNode<T>* p, const T* e) {
	if (!p) return;
	m_size++;
	ChainNode<T>* s = new ChainNode<T>(e, p->next);
	p->next = s;
}

template<class T>
ChainNode<T>* Chain<T>::get_node(int i) {
	int j = 0;
	ChainNode<T>* p = headnode;
	while (p && j < i) { p = p->next; ++j; }
	if (!p || j != i) return nullptr;
	else return p;

}

template<class T>
void Chain<T>::binSort(int range) {
	// Allocate the firstNode to "pNode".
	ChainNode<T>* pNode = get_firstNode();

	// Create and initialize the bins.
	ChainNode<T>** bottom, ** top;
	bottom = new ChainNode<T>*[range + 1];
	top = new ChainNode<T>*[range + 1];
	for (int i = 0; i <= range; i++) {
		bottom[i] = nullptr;
	}

	// Allocate the nodes to the bins,
	// In each bin, it should be empty or a chain in which nodes have same elements.
	for (; pNode != nullptr; pNode = pNode->next) {
		// Convert the type of "element" to "int".
		int theBin = pNode->element;
		// The bin is empty:
		if (bottom[theBin] == nullptr) {
			top[theBin] = pNode;
			bottom[theBin] = top[theBin];
		}
		// The bin is not empty:
		else {
			// Allocate "pNode" to the pointer above "top[theBin]";
			top[theBin]->next = pNode;
			// Make the pointer above "top[theBin]";
			top[theBin] = pNode;
		}
	}

	// Collect the nodes from the bins and assemble them to an ordered chain.
	ChainNode<T>* temp = nullptr;
	for (int theBin = 0; theBin <= range; theBin++) {
		if (bottom[theBin] != nullptr) {
			// The first non-empty bin.
			if (temp == nullptr) {
				headnode->next = bottom[theBin];
			}
			// Not the first non-empty bin.
			else {
				temp->next = bottom[theBin];
			}
			temp = top[theBin];
		}
	}
	if (temp != nullptr) {
		temp->next = nullptr;
	}

	// "bottom" and "top" are pointers to pointers;
	delete[] bottom;
	delete[] top;
}

