#include <iostream>
#include <vector>
using namespace std;
struct queue {
	int inf;
	queue* next; //структура очень похожа на стек, даже содержащиеся поля идентичны
};
void push(queue*& h, queue*& t, int x) {// функция вставки элемента в начало очереди
	//уже можно заметить, что функция похожа на такую у стека, отличается она только тем, что нужно проверку, если очередь пустая
	queue* r = new queue;
	r->inf = x;
	r->next = nullptr;
	if (!h && !t) {//собсна сама проверка, нужно проверить, если оба указателя смотрят в пустоту, то по сути просто изначальную очередь представляем как ту, которую создали для решения
		h = t = r;
	}
	else {//иначе идём также как и со стеком, но в обратную сторону
		t->next = r;
		t = r;
	}
}
int pop(queue*& h, queue*& t) {//функция удаления первого элемента из очереди, почти полностью идентична таковой из стеков
	queue* r = h;
	int i = h->inf;
	h = h->next;
	if (!h) t = nullptr;//единственное отличие - это необходимость проверить, если мы вдруг удалили единственный элемент в очереди, то нужно обнулить и второй указатель 
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