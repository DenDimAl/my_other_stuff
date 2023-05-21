#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// ���� ����� ������ ����� ���������: ������� ��������� � �������� ���������, � ����� ������ ������� �������.
vector <vector<int>> Gr;
vector <bool> used;
vector <int> parent;

bool dfs(int x, int p, vector<vector<int>>gr, vector<int> &path) { //������� ������ � ������� � ����������� ������
	used[x] = 1;
	parent[x] = p;
	path.push_back(x);//������ �� ����������� ������� �������� ��� ����������
	for (int i = 0; i < gr[x].size(); i++) {
		if (!used[gr[x][i]]) {
			if (dfs(gr[x][i], x, gr, path)) { //���� ��������� �� ������������ ������� �� ��� ������� �� �����, �� ���������� �����
				return true;
			}
		}
		else if (gr[x][i] != p && gr[x][i]==path[0]) {//���� �� ��� �������, �� ��� �� �������� ����������������, �� �� ����� ����
			vector <int> cycle;
			while (!path.empty() && path[path.size()-1] != gr[x][i]) {
				cycle.push_back(path[path.size() - 1]);//����������� ���� �� �������� �������� �� ������
				path.erase(path.end()-1);
			}
			cycle.push_back(gr[x][i]);
			cout << "cycle ";
			for (int j = 0; j < cycle.size(); j++) {//� ����� ������� ���
				cout << cycle[j] << " ";
			}
			cout << endl;
			return true;
		}
	}
	path.erase(path.end()-1);
	return false;//�������� �����, ���� ������������� ������ ���� ��������
}

void print(vector<vector<int>> Gr) {//������� ������ ������ ��������� �� �����, ��� ������ �������� �� ������� ���� � ������� ������� � ��� 
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
		}//����� ����
	}
	print(Gr);//������� ��� ������ ���������
	for (int i = 0; i < Gr.size(); i++) {
		vector <int> cyc;
		dfs(i, -1, Gr, cyc);
	}
	
}