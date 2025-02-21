#include <iostream>
#include <fstream>
using namespace std;

// sap xep mang tang dan dung CountingSort
void countingSort_37_Hau_Bai_1c_N2_B4(int a[], int b[], int n, int k)
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

void xuatMang_37_Hau_Bai_1c_N2_B4(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void processFile_37_Hau_Bai_1c_N2_B4(int arr[], const string& filename, int& n, int& k) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open file." << endl;
        return;
    }

    file >> n >> k;

    for (int i = 0; i < n; i++) {
        file >> arr[i];
    }
    file.close();

    // Sort the array using counting sort
    countingSort_37_Hau_Bai_1c_N2_B4(arr, arr, n, k);

    // Display the sorted array
    cout << "Danh sach sau khi sap xep tang dan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k = INT_MIN;
    int data[100], dataSorted[100];
    cout << "Nhap tu file" << endl;
    string filename = "37_Hau.txt";
    processFile_37_Hau_Bai_1c_N2_B4(data, filename, n, k);
    // Display the original array
    cout << "Mang truoc khi sap xep: \n";
    xuatMang_37_Hau_Bai_1c_N2_B4(data, n);
    cout << endl;
    system("pause");
    return 0;
}
