#include <iostream>
#include <fstream>
using namespace std;
// sap xep danh sach bang QuickSort
void quickSort_37_Hau_Bai_1c_N2(int a[], int left, int right) {
    if (left < right) {
        int pivot = a[(left + right) / 2];
        int i = left;
        int j = right;
        while (i <= j) {
            while (a[i] < pivot)
                i++;
            while (a[j] > pivot)
                j--;
            if (i <= j) {
                swap(a[i], a[j]);
                //hoan doi a[i],a[j]
                i++;
                j--;
            }
        }
        //goi lai de quy sau khi thoa dieu kien dung
        quickSort_37_Hau_Bai_1c_N2(a, left, j);
        quickSort_37_Hau_Bai_1c_N2(a, i, right);
    }
}

//xuat danh sach sau khi sap xep bang QuickSort
void xuatMang_37_Hau_Bai_1c_N2(int arr[], int n)
{
    cout << "Mang hien tai: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Nhap du lieu va Doc vao file file_37_Hau.txt 
void processFile_37_Hau_Bai_1c_N2(int arr[], const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Không thể mở file." << endl;
        return;
    }

    int n;
    file >> n;
    for (int i = 0; i < n; i++) {
        file >> arr[i];
    }
    file.close();
    // Sap xep danh sach tang dan bang quicksort
    quickSort_37_Hau_Bai_1c_N2(arr, 0, n - 1);
    // Hien thi danh sach sau khi sap xep
    std::cout << "Danh sach sau khi sap xep tang dan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[100];
    int n;
    cout << "Nhap tu file" << endl;
    string filename = "file_37_Hau.txt";
    processFile_37_Hau_Bai_1c_N2(data, filename);
    return 0;
}
