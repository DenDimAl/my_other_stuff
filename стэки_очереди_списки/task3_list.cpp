#include <iostream>
using namespace std;
/*
* ��� ������� �������� ��������� ����������� ������
* ���������� ������ - ��� ������������� ���������, ��� ������ ������� �������� ����� ���� ����� ������ �� ���������� � ��������� �������
*/
struct list {
	int inf;
	list* prev;
	list* next;
};
void push_back(list*& h, list*& t, int x) {//������� ������� ������ �������� � ����� ������
	list* r = new list;//��� ������� �������� ����� ������ 
	r->inf = x;
	r->next = nullptr;//� ������� ��� ������� ����� ������������, � r ����� ������ ������ �� ��������� �������
	if (!h && !t) {
		r->prev = nullptr; //���� ������ ���������� ����, �� ������ r ���������� ������ �������
		h = t = r;
	}
	else {
		t->next = r;
		r->prev = t;//���� �� ����, �� �������� ����� ������������ ������ ��������� �� ������ r, � ��� r ����� ��������� �� ��������, ��� �� ����������
		t = r;//����� ���� �������������� �����, ��� ������ r
	}
}
void push_front(list*& h, list*& t, int x) {//������� ������� ������ �������� � ������ ������
	list* r = new list;
	r->inf = x;
	r->prev = nullptr;
	if (!h && !t) {
		r->next = nullptr;
		h = t = r;
	}
	else {
		h->prev = r;
		r->next = h;
		h = r;//���������� ������� �����������, ��� � ������� � �����, ������ ��� ������ �������� �� ���������������
	}
}
void print(list* h, list* t) {//������� ������ ������ �� �����
	list* p = h;
	while (p) {
		cout << p->inf << " ";//������ �������� �� ������ � ������� ��������, ��������������� ������� ������
		p = p->next;
	}
}
list* find(list* h, list* t, int x) {//�������, ������������, ��� ��������� �������� �������
	list* p = h;
	while (p) {
		if (p->inf == x) break;//��� �� ������, ���� �� ����� ������ �������, ����� ����� ������� ��������������� ���������
		p = p->next;
	}
	return p;
}
void insert_after(list*& h, list*& t, list* p, int x) {//������� ������� �������� ����� ��������� ���������
	list* r = new list;
	r->inf = x;//����� ������� ����� ������, ��� � �������� �������� ����� ��������� ������� 
	if (r == t) {
		r->next = nullptr;//���� ������� ����������� � ����� ������, �� ������� ��������, ��� � ������ ������� ������� � �����
		r->prev = p;
		p->next = r;
		t = r;
	}
	else {
		r->next = p->next;
		p->next->prev = r;//����� � ��������� ����� �� ��������� ������ �� ��� �����, ����������� ��������������� � ������ r
		r->prev = p;
		p->next = r;
	}
}
void insert_before(list*& h, list*& t, list* p, int x) {//������� ������� �������� ����� �������� ����������
	list* r = new list;
	r->inf = x;
	if (r == h) {
		r->prev = nullptr;
		r->next = p;
		p->prev = r;
		t = r;
	}
	else {
		r->prev = p->prev;
		p->prev->next = r;
		r->next = p;
		p->prev = r;
	}//��� �� �� ��������, ������ ��������� �������� �������
}
void erase(list*& h, list*& t, list* p) {
	if (p == h && p == t)
		h = t = nullptr;
	else if (p == h) {
		h = h->next;
		h->prev = nullptr;
	}
	else if (p == t) {
		t = t->prev;
		t->next = nullptr;
	}
	else {
		p->next->prev = p -> prev;
		p->prev->next = p->next;
	}
	delete p;
}
void erase_r(list*& h, list*& t, list*& p) {
	if (p == h && p == t)
		h = t = nullptr;
	else if (p == h) {
		t->next = h->next;
		h = h->next;
		h->prev = t;
	}
	else if (p == t) {
		h->prev = t->prev;
		t = t->prev;
		t->next = h;
	}
	else {
		p->next->prev = p->prev;
		p->prev->next = p->next;
	}
	delete p;
}

int main() {
	list* h = nullptr;
	list* t = nullptr;
	int x, n,k,c;
	c = 1;
	cout << "Put length of list" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push_back(h, t, x);
	}
	cin >> k;
	list* p = h;
	while (n > 1) {
		if (c == k) {
			list* q = p;
			p = p->next;
			erase_r(h, t, q);
			n--;
			c = 1;
		}
		else {
			c++;
			p = p->next;
		}
	}
	print(h, t);
}