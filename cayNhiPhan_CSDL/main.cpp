#include<iostream>
using namespace std;

struct node_tree {
	int data;
	node_tree* treeRight;
	node_tree* treeLeft;
};
typedef node_tree* TREE;	
bool isEmpty(TREE p) {
	return (p == NULL);
}

void initTree(TREE &p) {
	p = NULL;
 }

TREE create_node(int x) {
	TREE node = new node_tree;
	node->data = x;
	node->treeRight = NULL;
	node->treeLeft = NULL;
	return node;
}

void create_tree(TREE& p, int x) {
	if (isEmpty(p)) {
		TREE node = create_node(x);
		p = node;
		return;
	}else {
		if (x > p->data)
		{
			create_tree(p->treeRight, x);
		}
		if (x < p->data)
		{
			create_tree(p->treeLeft, x);
		}
	}
}

void duyetNLR(TREE p) {
	if (p != NULL)
	{
		cout << p->data << " | ";
		duyetNLR(p->treeLeft);
		duyetNLR(p->treeRight);
	}
	
}

TREE search_node(TREE p, int x) {
	if (p != NULL){
		if (p->data == x){
			return p;
		}
		else if (x > p->data)
		{
			return search_node(p->treeRight,x);
		}
		else {
			return search_node(p->treeLeft, x);
		}
	}	
	return NULL;
}
void input(TREE &p) {
	int x;
	do {
		cout << "\nNhap gia tri( -99 de thoat):";
		cin >> x;
		if (x == -99) break;
		create_tree(p,x);
	} while (true);
}
int main(){
	TREE tree;
	int var;
	initTree(tree);
	input(tree);
	cout << "\n========DUYET NODE LEFT RIGHT=======" << endl;
	duyetNLR(tree);
	cout << "\n=========TIM NODE===========" << endl;
	cout << "Nhap gia tri node can tim: ";
	cin >> var;
	TREE p = search_node(tree, var);
	if (p != NULL)
	{
		cout << "\nTim thay node co gia tri: " << p->data;
	}
	else {
		cout << "\nNode khong ton tai";
	}
	return 0;
}