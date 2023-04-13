#include <iostream>
#include <vector>
using namespace std;
struct queue {
	int inf;
	queue* next; //��������� ����� ������ �� ����, ���� ������������ ���� ���������
};
void push(queue*& h, queue*& t, int x) {// ������� ������� �������� � ������ �������
	//��� ����� ��������, ��� ������� ������ �� ����� � �����, ���������� ��� ������ ���, ��� ����� ��������, ���� ������� ������
	queue* r = new queue;
	r->inf = x;
	r->next = nullptr;
	if (!h && !t) {//������ ���� ��������, ����� ���������, ���� ��� ��������� ������� � �������, �� �� ���� ������ ����������� ������� ������������ ��� ��, ������� ������� ��� �������
		h = t = r;
	}
	else {//����� ��� ����� ��� � �� ������, �� � �������� �������
		t->next = r;
		t = r;
	}
}
int pop(queue*& h, queue*& t) {//������� �������� ������� �������� �� �������, ����� ��������� ��������� ������� �� ������
	queue* r = h;
	int i = h->inf;
	h = h->next;
	if (!h) t = nullptr;//������������ ������� - ��� ������������� ���������, ���� �� ����� ������� ������������ ������� � �������, �� ����� �������� � ������ ��������� 
	delete r;
	return i;
}
int main() {
	queue* h= nullptr;
	queue* t = nullptr;
	int n, m, x,k,y,w;
	vector <vector<int>> Gr;

	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) a[i] = 0;

	for (int i = 0; i < n; i++) {
		Gr.push_back(vector<int>());
		cout << "next ";
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> w;
			Gr[i].push_back(w);
		}
	}
	cin >> x;
	a[x] = 1;
	push(h, t, x);
	cout << x;
	while (h) {
		x=pop(h, t);
		for (int i = 0; i < Gr[x].size(); i++) {
			if (a[Gr[x][i]] == 0) {
				y = Gr[x][i];
				push(h, t, y);
				cout << y;
			}
		}
	}
}