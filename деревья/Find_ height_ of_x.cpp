#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;
struct tree {//структура дерева
	int inf;
	tree* parent;
	tree* left;
	tree* right;
};
tree* node(int x) {//функция, превращающая х в элемент дерева 
	tree* n = new tree;
	n->inf = x;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}
void create(tree*& tr, int n) {//функция создания идеально сбалансированного дерева
	int x;
	if (n > 0) {
		cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}
void preorder(tree* tr) {//прямой обход
	if (tr) {
		cout << tr->inf<<" ";
		preorder(tr->left);
		preorder(tr->right);
	}
}
tree* find_n(tree* tr, int x) {//функция нахождения числа в дереве
	if (!tr)
		return nullptr;
	else {
		if (tr->inf == x)
			return tr;
		else {
			find_n(tr->left, x);
			find_n(tr->right, x);
		}
	}
}
void print(tree* tr, int k) { //функция вывода идеально сбалансированного дерева на экран
	if (!tr) cout << "empty tree\n";
	else {
		queue <tree*> cur, next;
		tree* r = tr;
		cur.push(r);
		int j = 0;
		while (cur.size()) {
			if (j == 0) {
				for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
					cout << ' ';
			}
			tree* buf = cur.front();
			cur.pop();
			j++;
			if (buf) {
				cout << buf->inf;
				next.push(buf->left);
				next.push(buf->right);
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' ';
			}
			if (!buf) {
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' ';
				cout << ' ';
			}
			if (cur.empty()) {
				cout << endl;
				swap(cur, next);
				j = 0;
				k--;
			}
		}
	}
}

int height(tree* tr) {//функция нахождения высоты дерева
	//но эту функцию можно также использовать и для нахождения длины любого другого поддерева
	//поэтому высоту узла можно найти, как высоту всего дерева минус высота поддерева искомого элемента
	//и плюс один, потому что здесь функция учитывает и высоту самого элемента и вычитает её, что нам не нужно
	if (!tr)
		return 0;//если дерево пустое, то вернём ноль
	else
		return 1 + max(height(tr->left), height(tr->right));
}

int main() {
	tree* tr = nullptr;
	int n,y,ans;
	cout << "Put number of tree elements" << endl;
	cin >> n;
	cout << "Put elements of tree" << endl;
	create(tr, n);//строим дерево
	int k = int(log((float)n) / log((float)2.0));
	preorder(tr);
	cout << endl;
	print(tr, k);//выведем его
	cout << "Put node which height you want to find" << endl;
	cin >> y;//спрашиваем искомый элемент
	tree* p = find_n(tr, y);
	cout << "Answer " << endl;
	ans = height(p);
	cout << ans;//выводим ответ
}