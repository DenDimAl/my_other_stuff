#include <iostream>
using namespace std;
/*
* Для решения создадим структуру двусвязного списка
* двусвязный список - это самоссылочная структура, где каждый элемент содержит кроме себя также ссылку на предыдущий и следующий элемент
*/
struct list {
	int inf;
	list* prev;
	list* next;
};
void push_back(list*& h, list*& t, int x) {//функция вставки нового элемента в конец списка
	list* r = new list;//для вставки создадим новый список 
	r->inf = x;
	r->next = nullptr;//в котором сам элемент равен вставляемому, а r имеет только ссылку на следующий элемент
	if (!h && !t) {
		r->prev = nullptr; //если список изначально пуст, то список r становится нужным списком
		h = t = r;
	}
	else {
		t->next = r;
		r->prev = t;//если не пуст, то заставим хвост изначального списка ссылаться на список r, а сам r будет ссылаться на исходный, как на предыдущий
		t = r;//после чего перезаписываем хвост, как список r
	}
}
void push_front(list*& h, list*& t, int x) {//функция вставки нового элемента в начало списка
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
		h = r;//фактически функция реализована, как и вставка в конец, просто все ссылки заменены на противоположные
	}
}
void print(list* h, list* t) {//функция вывода списка на экран
	list* p = h;
	while (p) {
		cout << p->inf << " ";//просто проходим по списку и выводим элементы, соответствующие текущей ссылке
		p = p->next;
	}
}
list* find(list* h, list* t, int x) {//функция, показывающая, где находится введённый элемент
	list* p = h;
	while (p) {
		if (p->inf == x) break;//идём по списку, пока не найдём нужный элемент, когда найдём выведем соответствующий указатель
		p = p->next;
	}
	return p;
}
void insert_after(list*& h, list*& t, list* p, int x) {//функция вставки элемента после введённого указателя
	list* r = new list;
	r->inf = x;//вновь созадим новый список, где в качестве элемента лежит указанный элемент 
	if (r == t) {
		r->next = nullptr;//если функция применяется к концу списка, то проведём действия, как в случае простой вставки в конец
		r->prev = p;
		p->next = r;
		t = r;
	}
	else {
		r->next = p->next;
		p->next->prev = r;//иначе в указанной точке мы разбиваем список на две части, присоединяя соответствующие к списку r
		r->prev = p;
		p->next = r;
	}
}
void insert_before(list*& h, list*& t, list* p, int x) {//функция вставки элемента перед введённым указателем
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
	}//все те же действия, только указатели поменять местами
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