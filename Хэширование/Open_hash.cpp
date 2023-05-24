#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <list>
#include <vector>
using namespace std;
ifstream in("employers.txt");	//��������� ������ ����


struct date
{
	int d, m, y;	//��������� ����
};

struct employer {
	string surn, work;
	date dob;
	int exp, sal;	//��������� ���������
};
bool operator ==(date a, date b) {
	if (a.d == b.d && a.m == b.m && a.y == b.y)
		return true;
	return false;
}
bool operator ==(employer a, employer b) {
	if ((a.dob == b.dob) && (a.exp == b.exp) && (a.sal = b.sal) && (a.surn == b.surn) && (a.work == b.work)) 
		return true;
	
	return false;	//������������ �������� == ��� �������� �� ��������� ����������� � ���
}
void print(date b) {
	cout << b.d << "." << b.m << "." << b.y <<" ";
}
void print(employer a) {
	cout << a.surn << " " << a.work << " "; print(a.dob); cout << a.exp << " " << a.sal;	//������� ������ ���������� � ���������� � ���� �� �����
}
date StrToDate(string abc) {	//�������, ����������� ������ � ���� 
	date chislo;
	int dd, mm, yyyy;
	chislo.d = 0;
	chislo.m = 0;
	chislo.y = 0;
	if (abc.size() != 10) {
		cout << "Incorrect input" << endl;
	}
	else {
		dd = stoi(abc.substr(0, 2));
		mm = stoi(abc.substr(3, 2));
		yyyy = stoi(abc.substr(6, 4));
		chislo.d = dd;
		chislo.m = mm;
		chislo.y = yyyy;
	}
	return chislo;
}
employer GetInfo(string rab) {	//������� ��������� ���������� � ���������� �� ������
	employer chel;
	int spc,c;
	c = 0;
	while (rab.size() > 0) {
		string t = rab.substr(0, rab.find_first_of(' '));
		rab.erase(0, rab.find_first_of(' ')+1);
		if (c == 0) chel.surn = t;
		if (c == 1) chel.work = t;
		if (c == 2) chel.dob = StrToDate(t);
		if (c == 3) chel.exp = stoi(t);
		if (c == 4) {
			chel.sal = stoi(t);
			break;
		}
		c++;
	}
	return chel;
}
int h(employer s) {	//������� ��������� ���� �� �������� ����������, ���� ������ ����� ����� 19 ��� ��� ���������
	return s.sal % 19;
}
void create(vector <employer> a, vector<list<employer>> &table) {	//������� �������� ���-�������
	table.resize(19);	//����������� ������� ����� ����� ��������� ����� �.� 19 �� 0 �� 18
	for (int i = 0; i < a.size() - 1; i++) {
		int k = h(a[i]);	//���������� ��� ��� ������� ���������� � ���������� ��� � ��������������� ������ 
		table[k].push_back(a[i]);	
	}
}
void find_el_on_hash(vector<list<employer>> table, int x) {	//������� ������ ���������� �� �������� � ���-�������
	int heh = x%19;		//���������, � ����� ������ ����� ���������� ���������� � ������ ���������
	bool fl=false;	//�������� ����� ���������, ����� ������ ���������� ��� ������
	cout << "hash is: " << heh<<" ";
	for (auto it = table[heh].begin(); it != table[heh].end(); it++) {
		employer c = *it;
		if (c.sal == x) {
			cout << "Information about worker: "; print(c);	// ���� ����� ������ �����������, ������� ���������� � ���
			fl = true;
		}
	}
	if (!fl) {
		cout << "No such element";	//���� ������ �� �����, �� ������� ��������� �� ����
	}
	cout << endl;
}
void del_el(vector<list<employer>>& table, int x) {	//������� �������� �������� � ���-�������
	int heh = x%19;	//����� ������� ��� ��������� �����
	bool fl=false;
	for (auto it = table[heh].begin(); it != table[heh].end(); it++) {	//������������� � ��������������� ������ ������� �����������	
		employer c = *it;
		if (c.sal == x) {	//���� �����, �� �������
			fl = true;
			table[heh].erase(it);
			if (!table[heh].empty()) it = table[heh].begin();	//������������ ��������� �� ������, ��� ��������� ������
			else break;	//�����, ������� �� ������ ������
		}
	}
	if (!fl) {
		cout << "No such employer to fire ";
	}
}
int main() {
	vector <list <employer>> table;
	vector<employer> people;
	people.resize(20);
	for (int i = 0; i < 20; i++) {
		string a;
		getline(in, a);
		employer chel = GetInfo(a);
		people[i] = chel;	//�������� ������ �����������
	}
	create(people, table);//�������� ���-������� �����������
	for (int i = 0; i < table.size(); i++) {
		cout << i << ": ";
		for (auto it = table[i].begin(); it != table[i].end(); it++) {
			employer x = *it;
			print(x);//������� �
		}
		cout << endl;
	}
	cout << endl;
	int s;
	cout << "Put a salary of an employer who you need to find: ";
	cin >> s;
	find_el_on_hash(table, s);
	cout << "Put a salary of an employer who you need to fire: ";
	cin >> s;
	del_el(table, s); //������ ������� �����
	cout << "This man has been fired you can see it on hash-table:" << endl;
	for (int i = 0; i < table.size(); i++) {
		cout << i << ": ";
		for (auto it = table[i].begin(); it != table[i].end(); it++) {
			employer x = *it;
			print(x);	//��� ��� ������� ������� ��� �������� ����, ������������� �� ��������� ������ ��������
		}
		cout << endl;
	}
}