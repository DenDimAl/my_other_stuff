#include <iostream>
#include <vector>
#include<queue>
using namespace std;
// Граф можно задать двумя способами: списком смежности и матрицей смежности, в нашем случае удобнее списком.
void print(vector<vector<int>> Gr) {//функция вывода списка смежности на экран, она просто проходит по каждому узлу и выводит смежные с ним 
	for (int i = 0; i < Gr.size(); i++) {
		cout << i << " : ";
		for (int j = 0; j < Gr[i].size(); j++) {
			cout << Gr[i][j] << " ";
		}
		cout << endl;
	}
}
void print(vector <int> smth) {
	for (int i = 0; i < smth.size(); i++) {
		cout << smth[i] << " ";
	}
}
int main() {
	vector<vector<int>> Gr;
	queue <int>h;
	int n, m, x, a, b;
	cout << "Put number of nodes" << endl;
	cin >> n;
	
	Gr.resize(n);
	for (int i = 0; i < n; i++) {
		cout << "Put number of heighbor nodes of node " << i << " ";
		cin >> m;
		cout << "Put heighbor nodes of node " << i << " ";
		Gr[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> x;
			Gr[i][j] = x;
		}//задаём граф
	}
	print(Gr);//выведем его список смежности 
	int* dist = new int[n];
	for (int i = 0; i < n; i++)
		dist[i] = -1;//создадим массив, содержащий дистанцию узла соответствующего индекса от начальной вершины

	vector <int> path;//нам также пригодится вектор для вывода пути
	bool fin = false;
	bool fl = true;//переменные, необходимые для выхода из обхода в ширину
	int c, d;
	int t = 0;
	cout << "Put start and finish" << endl;
	cin >> a >> b;//спрашиваем начальную и конечную клетку
	dist[a] = 0;
	d = a;
	h.push(a);
	path.push_back(b);//сразу добавим начальную клетку в вектор, выводящий путь
	while (!h.empty() && fl && !fin) {
		a = h.front();
		h.pop();
		for (int i = 0; i < Gr[a].size(); i++) {
			if (dist[Gr[a][i]] == -1) {
				c = Gr[a][i];
				dist[c] = dist[a] + 1;//здесь заполняется массив dist в соответствии с тем, сколько узлов пришлось дойти, чтобы достигнуть текущего
				h.push(c);
				if (c == b) {
					fin = true;
					break;
				}
			}
		}
		t++;
		if (t > n) fl = false;//если при обходе мы так и не нашли путь в конечную клетку, то запомним это
	}
	while (d != b) {
		if (!fl) {
			cout << "Impossible to reach this node" << endl; //если не нашли, то выводим сообщение об этом
			break;
		}
		else {
			for (int i = 0; i < Gr[b].size();i++ ) {
				if (dist[Gr[b][i]] == dist[b] - 1) {
					b = Gr[b][i];
					path.push_back(b);//иначе восстанавливаем путь, идя от конечной к начальной клетке, по узлам, расстояние между которыми - 1
					
					break;
				}
				
			}
			
		}
	}
	reverse(path.begin(), path.end());
	print(path);//перевернём и выведем найденный путь 
}