#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
void BubbleSort(int** m, int n) {
    int  j, a1, b1, a2, b2;//будем сортировать массив по диагоналям, параллельынм побочным пузырьком
    bool fl;
    for (j = 1; j < n - 1; ++j) {
        do {
            fl = false;
            for (int i = j; i >= 1; --i) {
                if (m[i][j - i] < m[i - 1][j - (i - 1)]) {
                    swap(m[i][j - i], m[i - 1][j - (i - 1)]);//здесь мы проходим по элементам выше побочной диагонали
                    fl = true;
                }
            }
        } while (fl);
    }

    for (j = 1; j < n; ++j) {
        do {
            fl = false;
            for (int i = j; i >= 1; --i) {
                a1 = n - 1 - j + (i - 1);
                b1 = n - 1 - (i - 1);

                a2 = n - 1 - j + i;
                b2 = n - 1 - i;
                if (m[a1][b1] > m[a2][b2]) {
                    swap(m[a1][b1], m[a2][b2]);//здесь по элементам ниже
                    fl = true;
                }
            }
        } while (fl);
    }
}
void print(int** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << a[i][j] << " ";
		}
		out << endl;//функция вывода массива в файл
	}
}
int main() {
	int n;
	string emp, t;
	getline(in, emp);
	n = stoi(emp);
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		getline(in, emp);
		for (int j = 0; j < n; j++) {
			t = emp.substr(0, emp.find_first_of(' '));
			emp.erase(0, emp.find_first_of(' ') + 1);
			a[i][j] = stoi(t);//записываем изначальный массив
		}
	}
	BubbleSort (a,n);//сортируем 
	print(a, n);//выводим
}