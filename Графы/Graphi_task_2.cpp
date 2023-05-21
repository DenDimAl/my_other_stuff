#include <iostream>
#include <vector>

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
int main() {
	vector<vector<int>> Gr;
	int n, m, x, a, b;
	bool neigh=false;
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
	cout << "Put nodes which  ";
	cin >> a;
	cin >> b;
	for (int i=0;i<min(Gr[a].size(),Gr[b].size());i++)
		if (Gr[a][i] == b || Gr[b][i] == a) {
			cout << "These nodes already are neighbors" << endl; //если предложенные вершины уже соседи, то просто не будем ничего вставлять
			neigh = true;
			break;
		}
	if (!neigh) {
		Gr[a].push_back(b);//иначе просто вставим в списки смежных узлов заданный вершин противоположную вершину 
		Gr[b].push_back(a);
		
	}
	cout << "Graph after operation looks like" << endl;
	print(Gr);//выведем получившийся список смежности
}