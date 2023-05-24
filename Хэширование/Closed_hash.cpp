#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
ifstream in("employers.txt");	//подключим нужный файл


struct date
{
	int d, m, y; //структура даты
};

struct employer {
	string surn, work;
	date dob;
	int exp, sal;	//структура работника
};
bool operator ==(date a, date b) {
	if (a.d == b.d && a.m == b.m && a.y == b.y)
		return true;
	return false;
}
bool operator ==(employer a, employer b) {
	if ((a.dob == b.dob) && (a.exp == b.exp) && (a.sal = b.sal) && (a.surn == b.surn) && (a.work == b.work))
		return true;

	return false;	//переназначим оператор == для проверки на равенство сторудников и дат
}
void print(date b) {
	cout << b.d << "." << b.m << "." << b.y << " ";
}
void print(employer a) {
	cout << a.surn << " " << a.work << " "; print(a.dob); cout << a.exp << " " << a.sal;	//функции вывода информации о сотруднике и даты на экран
}
date StrToDate(string abc) {	//функция, переводящая строку в дату
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
employer GetInfo(string rab) {	//функция получения информации о сотруднике из строки
	employer chel;
	int spc, c;
	c = 0;
	while (rab.size() > 0) {
		string t = rab.substr(0, rab.find_first_of(' '));
		rab.erase(0, rab.find_first_of(' ') + 1);
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
int help_h(int s) {	//функция нахождния вспомогательного хэша методом умножения
	float s_frac = s * 0.61803;
	int integ = int(s_frac);
	float frac = s_frac - integ;
	frac *= 32;
	return int(frac);
}
int lin_h(int h_s, int i) {
	return ((h_s + i) % 32);	//Функция нахождения основного линейного хэша
}
void create(vector <employer> a, vector<employer> &table) {	//функция создания закрытой хэш-таблицы
	table.resize(32);// размерность хэш-таблицы равна числу всех возможных хэшей от 0 до 31 в нашем случае
	int j = 0;//создадим ещё одну переменную для работы линейного хэширования
	for (int i = 0; i < a.size(); i++) {
		int k = help_h(a[i].exp);	//для каждого нового элемента найдём вспомогательный хэш
		for (int o = 0; o < 32; o++) {
			int p = lin_h(k, j);	//чтобы найти для него основной хэш
			if (table[p].exp == 0) {
				table[p] = a[i];	//и если ячейка, стоящая под этим хэшом пустая, то заполним её эти элементом 
				break;
			}
			else
				j++;	//иначе продвинемся дальше, чтобы найти для него место
		}
	}
	
}
void find_el(int x, vector<employer> table) {//функция нахождения элемента в таблице
	int k = help_h(x);//находим хэш для заданного числа
	for (int i = k; i < table.size(); i++) {
		if (table[i].exp == x) {
			cout << "Information about worker: "; print(table[i]);	//и смотрим, начиная с него на ячейки, в попытках найти ячейку, содержащую искомый элемент
			cout << endl;
		}
	}
}

int main() {
	vector<employer> tab;
	vector<employer> people;
	people.resize(20);
	for (int i = 0; i < 20; i++) {
		string a;
		getline(in, a);
		employer chel = GetInfo(a);
		people[i] = chel;
	}//создадим массив работников
	create(people, tab);//создадим хэш-таблицу работников
	for (int i = 0; i <tab.size(); i++) {
		cout<<" "<< i << ": "; print(tab[i]);
		cout << endl;//выведем хэш-таблицу
	}
	cout << endl;
	int e;
	cout << "Put an exprience of looking employer: ";
	cin >> e;//спрашиваем искомый опыт и находим людей с ним
	find_el(e, tab);
}