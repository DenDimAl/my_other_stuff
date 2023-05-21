#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Граф можно задать двумя способами: списком смежности и матрицей смежности, в нашем случае удобнее списком.
vector <vector<int>> Gr;
vector <bool> used;
vector <int> parent;

bool dfs(int x, int p, vector<vector<int>>gr, vector<int> &path) { //функция обхода в глубину с нахождением циклов
	used[x] = 1;
	parent[x] = p;
	path.push_back(x);//первый же проверенный элемент отмечаем как посещённый
	for (int i = 0; i < gr[x].size(); i++) {
		if (!used[gr[x][i]]) {
			if (dfs(gr[x][i], x, gr, path)) { //если следующий на рассмотрение элемент не был посещён до этого, то продолжаем обход
				return true;
			}
		}
		else if (gr[x][i] != p && gr[x][i]==path[0]) {//если он был посещён, но это не родитель рассматриваемого, то мы нашли цикл
			vector <int> cycle;
			while (!path.empty() && path[path.size()-1] != gr[x][i]) {
				cycle.push_back(path[path.size() - 1]);//восстановим путь от текущего элемента до начала
				path.erase(path.end()-1);
			}
			cycle.push_back(gr[x][i]);
			cout << "cycle ";
			for (int j = 0; j < cycle.size(); j++) {//а затем выведем его
				cout << cycle[j] << " ";
			}
			cout << endl;
			return true;
		}
	}
	path.erase(path.end()-1);
	return false;//закончим обход, если рассмотренная клетка была посещена
}

void print(vector<vector<int>> Gr) {//функция вывода списка смежности на экран, она просто проходит по каждому узлу и выводит смежные с ним 
	for (int i = 0; i < Gr.size(); i++) {
		cout << i << " : ";
		for (int j = 0; j < Gr[i].size(); j++) {
			cout << Gr[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int n, m, x, ans;
	cout << "Put number of nodes" << endl;
	cin >> n;
	Gr.resize(n);
	used.resize(n);
	parent.resize(n);
	for (int i = 0; i < n; i++) {
		cout << "Put number of heighbor nodes of node" << i << " ";
		cin >> m;
		cout << "Put heighbor nodes of node" << i << " ";
		Gr[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> x;
			Gr[i][j] = x;
		}//задаём граф
	}
	print(Gr);//выведем его список смежности
	for (int i = 0; i < Gr.size(); i++) {
		vector <int> cyc;
		dfs(i, -1, Gr, cyc);
	}
	
}