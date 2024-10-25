#include <iostream>

using namespace std;

void allocate(int**& p, int n, int m) {
	p = new int* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new int[m];

	}
}
int** allocate(int n, int m) {
   int** p = new int* [n];
   for (int i = 0; i < n; i++) {
	   p[i] = new int[m];

   }
   return p;
}
void fill(int** p, int n, int m, int e = 1) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p[i][j] = i + j*e;
		}
	}
}
void print(int** p, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}
void deallocate(int**& p, int n) {
	for (int i = 0; i < n; i++) {
		delete[] p[i];
	}
	delete p;
}
int main() { 
	int n = 3;
	int m = 4;
//	int** p = allocate(n, m);
	
 	int** mat1 = nullptr;
	allocate(mat1, n, m);
	cout << sizeof(mat1) << endl;
	fill(mat1, n, m);
	cout << "mat1" << endl;
	print(mat1, n, m);
	int** mat2 = nullptr;
	allocate(mat2, n, m);
	fill(mat2, n, m, 5);
	cout << "mat2" << endl;
	print(mat2, n, m);
	

	
	
	
	deallocate(mat1, n);
	deallocate(mat2, n);

	


	
	return 0;
}