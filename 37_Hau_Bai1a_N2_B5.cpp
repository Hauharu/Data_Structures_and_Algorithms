#include <iostream>
#define MAX 100
using namespace std;
char vertex[MAX];
void input_37_Hau_Bai1a_N2_B5(int a[][MAX], int& n);
void output_37_Hau_Bai1a_N2_B5(int a[][MAX], int n);
void main()
{
	int a[MAX][MAX], n;
	input_37_Hau_Bai1a_N2_B5(a, n);
	output_37_Hau_Bai1a_N2_B5(a, n);
}
void input_37_Hau_Bai1a_N2_B5(int a[][MAX], int& n)
{
	//nhap so luong dinh cua do thi 
	do
	{
		cout << "Nhap so luong dinh cua do thi n: ";
		cin >> n;
	} while (n <= 0 || n > MAX);
	//nhap ten cua tung dinh trong do thi
	cout << "Nhap ten cac dinh cua do thi theo thu tu: "; for (int i = 0; i < n; i++)
		cin >> vertex[i];
	//nhap ma tran ke
	for (int i = 0; i < n; i++) {
		cout << "Nhap (1/0) cua cac dinh voi dinh "<< vertex[i] << ": ";
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];
	}
}
void output_37_Hau_Bai1a_N2_B5(int a[][MAX], int n)
{
	cout << "\t";
	for (int i = 0; i < n; i++) 
		cout << vertex[i] << "\t";
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << "\t";
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t"; cout << endl;
		cout << endl;
	}
}