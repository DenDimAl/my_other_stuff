#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
void quicksort(int**& a, int l, int r,int noc) {
	int i = l;
	int j = r;
	int pil = a[j][noc];
	while (i <= j) {
		while (a[i][noc] < pil) {
			i++;
		}
		while (a[j][noc] > pil) {
			j--;
		}
		if (i <= j) {
			swap(a[i][noc], a[j][noc]);
			j--;
			i++;
		}
	}
	if (j-l > 0) {
		quicksort(a, l, j, noc);
	}
	if (r-i > 0) {
		quicksort(a, i, r, noc);
	}
}
void quicksort(int*& a, int l, int r) {
	cout << "rec";
	int i = l;
	int j = r;
	int pil = a[j];
	while (i <= j) {
		while (a[i] < pil) {
			i++;
		}
		while (a[j] > pil) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			j--;
			i++;
		}
	}
	if (j - l > 0) {
		cout << "rec1";
		quicksort(a, l, j);
		
	}
	if (r-i > 0) {
		cout << "rec2";
		quicksort(a, i, r);
	}
}
void print(int** a,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << a[i][j] << " ";
        }
        out << endl;
    }
}
int main() {
	int n;
	string emp,t;
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
			a[i][j] = stoi(t);
		}
	}
	for (int i = 0; i < n; i++) quicksort(a, 0, n - 1, i);
	print(a, n);
}