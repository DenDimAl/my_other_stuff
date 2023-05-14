#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;
struct tree {//��������� ������
	int inf;
	tree* parent;
	tree* left;
	tree* right;
};
tree* node(int x) {//�������, ������������ � � ������� ������ 
	tree* n = new tree;
	n->inf = x;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}
void create(tree*& tr, int n) {//������� �������� �������� ����������������� ������
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
void preorder(tree* tr) {//������ �����
	if (tr) {
		cout << tr->inf<<" ";
		preorder(tr->left);
		preorder(tr->right);
	}
}
tree* find_n(tree* tr, int x) {//������� ���������� ����� � ������
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
void print(tree* tr, int k) { //������� ������ �������� ����������������� ������ �� �����
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

int height(tree* tr) {//������� ���������� ������ ������
	//�� ��� ������� ����� ����� ������������ � ��� ���������� ����� ������ ������� ���������
	//������� ������ ���� ����� �����, ��� ������ ����� ������ ����� ������ ��������� �������� ��������
	//� ���� ����, ������ ��� ����� ������� ��������� � ������ ������ �������� � �������� �, ��� ��� �� �����
	if (!tr)
		return 0;//���� ������ ������, �� ����� ����
	else
		return 1 + max(height(tr->left), height(tr->right));
}

int main() {
	tree* tr = nullptr;
	int n,y,ans;
	cout << "Put number of tree elements" << endl;
	cin >> n;
	cout << "Put elements of tree" << endl;
	create(tr, n);//������ ������
	int k = int(log((float)n) / log((float)2.0));
	preorder(tr);
	cout << endl;
	print(tr, k);//������� ���
	cout << "Put node which height you want to find" << endl;
	cin >> y;//���������� ������� �������
	tree* p = find_n(tr, y);
	cout << "Answer " << endl;
	ans = height(p);
	cout << ans;//������� �����
}