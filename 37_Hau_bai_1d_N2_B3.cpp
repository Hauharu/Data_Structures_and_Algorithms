#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
// sap xep danh sach bang QuickSort
void quickSort_37_Hau_Bai_1d_N2(int a[], int left, int right) {
    if (left < right) {
        int pivot = a[(left + right) / 2];//vi tri x o giua de chia mang thanh 2 phan
        int i = left, j = right;
        while (i <= j) {// vong lap su dung neu j<i
            while (a[i] < pivot)// do theo chieu i den khi co gia tri khong thoa dieu kien quicksort
                i++;
            while (a[j] > pivot)// do theo chieu j den khi co gia tri khong thoa dieu kien quicksort
                j--;
            if (i <= j) {// khi thoa 2 dieu kien tren ma i van con be hon hoac bang j
                swap(a[i], a[j]);
                //Doi cho a[i],a[j];
                i++;//tiep tuc di chuyen
                j--;//tiep tuc di chuyen
            }
        }
        // de qui goi lai ham sau khi thoa dieu kien dung
        quickSort_37_Hau_Bai_1d_N2(a, left, j);
        quickSort_37_Hau_Bai_1d_N2(a, i, right);
    }
}
//xuat danh sach sau khi sap xep
void xuatMang_37_Hau_Bai_1d_N2(int arr[], int n)
{
    cout << "Mang hien tai: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//ket hop random,ghi file,doc file
void writeFile_37_Hau_Bai_1d_N2(int arr[], int n, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Không thể mở file." << endl;
        return;
    }

    file << n << endl;
    for (int i = 0; i < n; i++) {
        file << arr[i] << " ";
    }
    file.close();
}

int main() {
    int data[100];
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % (10 - (-30) + 1) - 30;
    }
    writeFile_37_Hau_Bai_1d_N2(data, n, "random+file_Hau37.txt");
    quickSort_37_Hau_Bai_1d_N2(data, 0, n - 1);
    xuatMang_37_Hau_Bai_1d_N2(data, n);
    system("pause");
    return 0;
}
