#include <iostream>
#include <vector>
#include <set>
using namespace std;
// ���� ����� ������ ����� ���������: ������� ��������� � �������� ���������, � ����� ������ ������� �������.
void print(vector<vector<int>> Gr) {//������� ������ ������ ��������� �� �����, ��� ������ �������� �� ������� ���� � ������� ������� � ��� 
	for (int i = 0; i < Gr.size(); i++) {
		cout << i << " : ";
		for (int j = 0; j < Gr[i].size();j++) {
			cout << Gr[i][j]<<" ";
		}
		cout << endl;
	}
}
int main() {
	vector<vector<int>> Gr;
	int n, m, x,ans;
	cout << "Put number of nodes" << endl;
	cin >> n;
	Gr.resize(n);
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
	cout << "Put node which neighbors you want to find ";
	cin >> ans;
	cout << "Answer is" << endl;
	for (int i = 0; i < Gr[ans].size(); i++)
		cout << Gr[ans][i]<<" ";//������� �������, ������� � �������

}