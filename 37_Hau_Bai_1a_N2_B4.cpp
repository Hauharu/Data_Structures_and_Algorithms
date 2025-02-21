#include <iostream>
using namespace std;

// nhap mang 
void nhapMang_37_Hau_Bai_1a_N2_B4(int a[], int& n, int& k)
{
	cout << "Nhap so luong phan tu n: ";
	cin >> n;
	k = INT16_MIN;// khoi tao k la so nguyen nho nhat
	for (int i = 0; i < n; i++)//vong lap nhap tung chi so cho mang a
	{
		cout << "Nhap phan tu thu " << i << ": ";
		cin >> a[i];//nhap gia tri cho mang a
		if (k < a[i])// so sanh gia tri moi nhap voi bien k
			k = a[i];// gan gia tri a[i] cho k
	}
}
// xuat danh sach
void xuatMang_37_Hau_Bai_1a_N2_B4(int a[], int n)
{
	for (int i = 0; i < n; i++)//vong lap in ra cac chi so trong mang
		cout << a[i] << "\t";//in ra mang voi tung chi so thu i
	cout << endl;
}
// sap xep mang tang dan dung CountingSort
void countingSort_37_Hau_Bai_1a_N2_B4(int a[], int b[], int n, int k)
{
	int* c = new int[k + 1];// cap phat dong cho mang c dua vao gia tri max cua mang
	for (int i = 0; i <= k; i++)
		c[i] = 0;//khoi tao cac gia tri trong mang bang gia tri 0
	for (int i = 0; i < n; i++)
		c[a[i]]++;// tang gia tri cua chi so di trong mang c len 1 gia tri
	cout << "\n\nvi tri:\t";
	for (int i = 0; i <= k; i++)//vong lap in ra cac gia tri
		cout << i << "\t";
	cout << "\nc[]:\t";
	for (int i = 0; i <= k; i++)//vong lap in ra so lan lap lai cua so 
		cout << c[i] << "\t";
	cout << "\n\n\n";
	int j = 0;//khoi tao chi so cho mang b
	for (int i = 0; i <= k; i++)//vong lap chay het cac gia tri
		while (c[i] > 0)//dieu kien gia tri co xuat hien trong de
		{
			b[j++] = i;//gan gia tri i cho gia tri j trong mang b
			c[i]--;//giam gia tri di 1 de xet tiep no con xuat hien nua khong
		}
	delete[]c;
}
int main() {
	int n, k;
	int data[100], dataSorted[100];

	nhapMang_37_Hau_Bai_1a_N2_B4(data, n, k);
	countingSort_37_Hau_Bai_1a_N2_B4(data, dataSorted, n, k);

	cout << "Mang truoc khi sap xep: \n";
	xuatMang_37_Hau_Bai_1a_N2_B4(data, n);

	cout << "\nMang sau khi sap xep: \n";
	xuatMang_37_Hau_Bai_1a_N2_B4(dataSorted, n);

	cout << endl;
	system("pause");
	return 0;
}
