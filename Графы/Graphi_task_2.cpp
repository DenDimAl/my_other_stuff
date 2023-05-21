#include <iostream>
#include <vector>

using namespace std;
// ���� ����� ������ ����� ���������: ������� ��������� � �������� ���������, � ����� ������ ������� �������.
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
		}//����� ����
	}
	print(Gr);//������� ��� ������ ��������� 
	cout << "Put nodes which  ";
	cin >> a;
	cin >> b;
	for (int i=0;i<min(Gr[a].size(),Gr[b].size());i++)
		if (Gr[a][i] == b || Gr[b][i] == a) {
			cout << "These nodes already are neighbors" << endl; //���� ������������ ������� ��� ������, �� ������ �� ����� ������ ���������
			neigh = true;
			break;
		}
	if (!neigh) {
		Gr[a].push_back(b);//����� ������ ������� � ������ ������� ����� �������� ������ ��������������� ������� 
		Gr[b].push_back(a);
		
	}
	cout << "Graph after operation looks like" << endl;
	print(Gr);//������� ������������ ������ ���������
}