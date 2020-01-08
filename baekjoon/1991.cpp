#include <iostream>
using namespace std;

struct Node {
	char data;
	Node* leftChild;
	Node* rightChild;

	Node(char d, Node* l = NULL, Node* r = NULL) {
		data = d;
		leftChild = l;
		rightChild = r;
	}
};

class Tree {
public:
	Node* root;

	Tree() { root = NULL; }
	~Tree() {
		del(root);
	}
	void del(Node* find) {
		if (find->leftChild) del(find->leftChild);
		if (find->rightChild) del(find->rightChild);
		delete find;
	}
	void pre(Node* find) {
		cout << find->data;
		if (find->leftChild) pre(find->leftChild);
		if (find->rightChild) pre(find->rightChild);
	}
	void in(Node* find) {
		if (find->leftChild) in(find->leftChild);
		cout << find->data;
		if (find->rightChild) in(find->rightChild);
	}
	void post(Node* find) {
		if (find->leftChild) post(find->leftChild);
		if (find->rightChild) post(find->rightChild);
		cout << find->data;
	}
	void search(char d, char l, char r, Node* n) {
		if (n->data == d) {
			if(l != '.') n->leftChild = new Node(l);
			if(r != '.') n->rightChild = new Node(r);
		}
		else {
			if (n->leftChild) search(d, l, r, n->leftChild);
			if (n->rightChild) search(d, l, r, n->rightChild);
		}
	}
	void insert(char d, char l, char r) {
		if (!root) {
			Node* n = new Node(d);
			if (l != '.') {
				Node* nl = new Node(l);
				n->leftChild = nl;
			}
			if (r != '.') {
				Node* nr = new Node(r);
				n->rightChild = nr;
			}
			root = n;
		}
		else {
			search(d, l, r, root);
		}
	}
};

int main() {
	int n;
	char c[3];
	Tree t;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c[0] >> c[1] >> c[2];
		t.insert(c[0], c[1], c[2]);
	}
	t.pre(t.root);
	cout << endl;
	t.in(t.root);
	cout << endl;
	t.post(t.root);
	cout << endl;

	return 0;
}
