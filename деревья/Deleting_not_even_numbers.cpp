#include <iostream>
using namespace std;
struct tree
{
	int inf;
	tree* parent;
	tree* left;
	tree* right;
}; //структура дерева
tree* node(int x) {//функция преобразования числа в элемент дерева
	tree* n = new tree;
	n->inf = x;
	n->parent = nullptr;
	n->right = nullptr;
	n->left = nullptr;
	return n;
}
void inorder(tree* tr) {//функция смметричного обхода дерева
	if (tr) {
		if (tr->left)
			inorder(tr->left);
		cout << tr->inf<<" ";
		if(tr->right)
			inorder(tr->right);
	}
}
void insert(tree*& tr,int x) {//функция вставки элемента в дерево
	tree* n = node(x);
	if (!tr) {
		tr = n;
	}
	else {
		tree* y = tr;
		while (y) {
			if (n->inf > y->inf)
				if (y->right)
					y = y->right;
				else {
					n->parent = y;
					y->right = n;
					break;
				}
			else if (n->inf < y->inf)
				if (y->left)
					y = y->left;
				else {
					n->parent = y;
					y->left = n;
					break;
				}
		}
	}
}
//функции нахождения минимального и максимального элемента в дереве, понадобятся при удалении
tree* Min(tree* tr) {
	if (!tr->left) return tr;
	else return Min(tr->left);
}
tree* Max(tree* tr) {
	if (!tr->right) return tr;
	else return Max(tr->right);
}
tree* find(tree* tr, int x) { //функция нахождения числа в дереве
	if (!tr)
		return nullptr;
	if (x == tr->inf)
		return tr;
	if (x < tr->inf)
		return find(tr->left, x);
	else
		return find(tr->right, x);
}
tree* next(tree* tr, int x) { //функция нахождения следующего за указанным узлом числа в дереве
	tree* n = find(tr, x);
	if (n->right)
		return Min(n->right);
	tree* y = n->parent;
	while (y && n == y->right) {
		n = y;
		y = y->parent;
	}
	return y;
}
void deleting (tree*& tr, tree* v) { //функция удаления элемента в дереве
	tree* p = v->parent;
	if (!p && !v->right && !v->left) tr = nullptr;
	else if (!v->left && !v->right) {
		if (p->left == v)
			p->left = nullptr;
		if (p->right == v)
			p->right = nullptr;
		delete v;
	}
	else if (!v->left || !v->right) {
		if (!p) {
			if (!v->left) {
				tr = v->right;
				v->parent = nullptr;
			}
			else {
				tr = v->left;
				v->parent = nullptr;
			}
		}
		else {
			if (!v->left) {
				if (p->left == v)
					p->left = v->right;
				else
					p->right = v->right;
			}
			else {
				if (p->left == v)
					p->left = v->left;
				else
					p->right = v->left;
			}
			delete v;
		}
	}
	else {
		tree* succ = next(tr, v->inf);
		v->inf = succ->inf;
		if (succ->parent->left == succ) {
			succ->parent->left = succ->right;
			if (succ->right)
				succ->right->parent = succ->parent;
		}
		else {
			succ->parent->right = succ->right;
			if (succ->right)
				succ->right->parent = succ->parent;
		}
		delete succ;
	}
	
}
//для удаления нечётных элементов просто выполним любой проход по дереву и удалим нечётные 
void delete_not_even(tree* &tr) {
	if (tr){
	if (tr->left) 
		delete_not_even(tr->left);//прошли по левым детям
	if (tr->right)
		delete_not_even(tr->right);//прошли по правым детям
	}
	if (tr->inf % 2 == 1) {
		tree* p = tr;
		deleting(tr, p);//удалили нечётных
	}
}
int main() {
	tree* tr=nullptr;
	int n,x;
	cout << "Put number of elements of tree" << endl;
	cin >> n;
	cout << "Put elements of tree" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(tr, x);//создаём дерево
	}
	inorder(tr);//выведем дерево
	cout <<"Answer is " << endl;
	delete_not_even(tr);
	inorder(tr);//вывдем дерево без нечётных элементов
}