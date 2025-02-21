#include <iostream>
using namespace std;

// sap xep mang tang dan dung QuickSort
void quickSort_37_Hau_Bai_1a_N2(int a[], int left, int right) {
    if (left < right) {
        int pivot = a[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (a[i] < pivot)
                i++;
            while (a[j] > pivot)
                j--;
            if (i <= j) {
                swap(a[i], a[j]);
                //Doi cho a[i],a[j];
                i++;
                j--;
            }
        }
        // de qui goi lai ham sau khi thoa dieu kien dung
        quickSort_37_Hau_Bai_1a_N2(a, left, j);
        quickSort_37_Hau_Bai_1a_N2(a, i, right);
    }
}
// nhap mang bang danh sach dac tu ban phim
void nhapMang_37_Hau_Bai_1a_N2(int arr[], int n) {
    cout << "Nhap " << n << " so nguyen cho mang a:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
}
//xuat mang sau khi da sap xep bang QuickSort
void xuatMang_37_Hau_Bai_1a_N2(int arr[], int n) {
    cout<< endl << "Mang sau khi xep: ";
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "       ";
    }
    cout << endl;
}
int main() {
    int data[100];
    int n;
    cout << "Nhap n: ";
    cin >> n;
    nhapMang_37_Hau_Bai_1a_N2(data, n);
    quickSort_37_Hau_Bai_1a_N2(data, 0, n - 1);
    xuatMang_37_Hau_Bai_1a_N2(data, n);
    cout << endl;
    system("pause");
    return 0;
}
