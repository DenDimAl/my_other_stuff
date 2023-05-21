#include <iostream>
#include <vector>
#include<queue>
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
		}//����� ����
	}
	print(Gr);//������� ��� ������ ��������� 
	int* dist = new int[n];
	for (int i = 0; i < n; i++)
		dist[i] = -1;//�������� ������, ���������� ��������� ���� ���������������� ������� �� ��������� �������

	vector <int> path;//��� ����� ���������� ������ ��� ������ ����
	bool fin = false;
	bool fl = true;//����������, ����������� ��� ������ �� ������ � ������
	int c, d;
	int t = 0;
	cout << "Put start and finish" << endl;
	cin >> a >> b;//���������� ��������� � �������� ������
	dist[a] = 0;
	d = a;
	h.push(a);
	path.push_back(b);//����� ������� ��������� ������ � ������, ��������� ����
	while (!h.empty() && fl && !fin) {
		a = h.front();
		h.pop();
		for (int i = 0; i < Gr[a].size(); i++) {
			if (dist[Gr[a][i]] == -1) {
				c = Gr[a][i];
				dist[c] = dist[a] + 1;//����� ����������� ������ dist � ������������ � ���, ������� ����� �������� �����, ����� ���������� ��������
				h.push(c);
				if (c == b) {
					fin = true;
					break;
				}
			}
		}
		t++;
		if (t > n) fl = false;//���� ��� ������ �� ��� � �� ����� ���� � �������� ������, �� �������� ���
	}
	while (d != b) {
		if (!fl) {
			cout << "Impossible to reach this node" << endl; //���� �� �����, �� ������� ��������� �� ����
			break;
		}
		else {
			for (int i = 0; i < Gr[b].size();i++ ) {
				if (dist[Gr[b][i]] == dist[b] - 1) {
					b = Gr[b][i];
					path.push_back(b);//����� ��������������� ����, ��� �� �������� � ��������� ������, �� �����, ���������� ����� �������� - 1
					
					break;
				}
				
			}
			
		}
	}
	reverse(path.begin(), path.end());
	print(path);//��������� � ������� ��������� ���� 
}