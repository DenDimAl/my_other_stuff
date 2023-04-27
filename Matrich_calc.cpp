#include <iostream>
#include <math.h>
using namespace std;
struct vector
{
	double x, y, z; //создаЄтс€ структура векторов
};
void print(vector a) {// функци€ вывода координат вектора
	cout << "Coordinates of vector" << a.x << " " << a.y << " " << a.z << endl;
}
double skalprois(vector a, vector b) {// функци€ подсчЄта их скал€рного произведени€
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
vector vekprois(vector a, vector b) {//функци€, возвращающа€ координаты векторного произведени€
	vector c;
	c.x = a.y * b.z - a.z * b.y;
	c.y = a.x * b.z - a.z * b.x;
	c.z = a.x * b.y - a.y * b.x;
	return c;
}
double** input(int n, int m) {//функци€ ввода двумерного массива
	double** arr = new double* [n];
	for (int i = 0; i < n; i++) arr[i] = new double[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	return arr;
}
void print(double** arr, int n, int m) {//функци€ вывода двумерного массива
	for (int i = 0; i < n; i++) {
		for (int j=0; j < m; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
}
double** matprois(double** arr1, double** arr2, int n1, int m1, int n2, int m2) {
	double** arr = new double* [n1]; //функци€ возвращающа€ массив, €вл€ющийс€ произведением двух массивов
	for (int i = 0; i < n1; i++) {
		arr[i] = new double[m2];
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			for (int k = 0; k < n2; k++) {
				arr[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	return arr;
}
void trans(double** arr, int n, int m) {//функци€ транспонировани€ матрицы
	double t;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < m; j++) {
			t = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = t;
		}
	}
	print (arr,n,m);
}
double det(double** arr1, int n) {//функци€ подсчЄта определител€ по теореме Ћапласа
	if (n == 1) {
		return arr1[0][0];
	}
	else {
		if (n == 2) {
			return arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0];
		}
		else { //функци€ рекурсивна€, сверху стартовые значени€ 
			double d = 0;
			for (int k = 0; k < n; k++) {
				double** m = new double* [n - 1];
				for (int i = 0; i < n - 1; i++) {
					m[i] = new double[n - 1];
				}
				for (int i = 1; i < n; i++) {
					int t = 0;
					for (int j = 0; j < n; j++) {
						if (j == k)
							continue;
						m[i - 1][t] = arr1[i][j];
						t++;// будем создавать из большого массива массивы поменьше
					}
				}
				d += pow(-1, k + 2) * arr1[0][k] * det(m, n - 1);//и считаем определители этих массивов
			}
			return d;
		}
	}
}
int main() {
	int y;
	cout << "Put number of operation you want to do" << endl;
	cout << "1 for Dot multiplication of two vectors " << endl;
	cout << "2 for vector multiplication of two vectors " << endl;
	cout << "3 for multiplication of two matrix " << endl;
	cout << "4 for transpositon of matrix " << endl;
	cout << "5 to calculate determinant of matrix" << endl;
	cin >> y;//спрашиваем, какую именно операцию хотим выполнить и выполн€ем
	if (y == 1) {
		vector a, b;
		cout << "Put coordinates of vectors" << endl;
		cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z;
		cout << skalprois(a, b);
	}
	else if (y == 2) {
		vector a, b;
		cout << "Put coordinates of vectors" << endl;
		cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z;
		vector c = vekprois(a, b);
		print(c);
	}
	else if (y == 3) {
		int n1, m1, n2, m2;
		cout << "Put length and width of first matrix" << endl;
		cin >> n1 >> m1;
		cout << "Put elements of first matrix" << endl;
		double** arr1 = input(n1, m1);
		cout << "Put length and width of second matrix" << endl;
		cin >> n2 >> m2;
		if (n1 != m2) {
			cout << "With these width and length impossible to mutiply matrixes" << endl;
		}
		cout << "Put elements of second matrix" << endl;
		double** arr2 = input(n2, m2);
		double** ans = matprois(arr1, arr2, n1, m1, n2, m2);
		cout <<"Answer is"<< endl;
		print(ans, n1, m2);
	}
	else if (y == 4) {
		int n, m;
		cout << "Put lentgh and width of matrix" << endl;
		cin >> n >> m;
		cout << "Put elements of matrix" << endl;
		double** arr = input(n, m);
		cout <<"Answer is" << endl;
		trans(arr, n, m);	
	}
	else if (y == 5) {
		int n, m;
		cout << "Put lentgh and width of matrix" << endl;
		cin >> n >> m;
		double** arr = input(n, m);
		double deter = det(arr, n);
		cout << endl;
		cout << "determinant is " << deter << endl;
	}
	else cout << "No such operation" << endl;
}