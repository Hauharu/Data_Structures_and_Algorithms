#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
using namespace std;
// sap xep mang bang QuickSort
void quickSort_37_Hau_Bai_1e_N2(int a[], int left, int right) {
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
        quickSort_37_Hau_Bai_1e_N2(a, left, j);
        quickSort_37_Hau_Bai_1e_N2(a, i, right);
    }
}
// nhap mang tu ban phim
void nhapMang_37_Hau_Bai_1e_N2(int arr[], int n) {
    cout << "Nhap " << n << " so nguyen cho mang a" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
}
// xuat danh sach sau khi sap xep
void xuatMang_37_Hau_Bai_1e_N2(int arr[], int n) {
    cout << "Mang hien tai: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
    cout << endl;
}
// nhap mang bang random
void nhapMangRandom_37_Hau_Bai_1e_N2(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (10 - (-30) + 1) - 30;
    }
}
//ghi vao file
void processFile_37_Hau_Bai_1e_N2(int arr[], const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Khong the mo file." << endl;
        return;
    }

    int n;
    file >> n;
    for (int i = 0; i < n; i++) {
        file >> arr[i];
    }
    file.close();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// random+doc file
void writeFile_37_Hau_Bai_1e_N2(int arr[], int n, const std::string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Khong the mo file." << endl;
        return;
    }

    file << n << endl;
    for (int i = 0; i < n; i++) {
        file << arr[i] << " ";
    }
    file.close();
}

int main() {
    int choice;
    int arr[100];
    int n;

    do {
        system("cls");
        cout << "Menu:" << endl;
        cout << "1. Nhap n tu ban phim" << endl;
        cout << "2. Random va ghi vao file" << endl;
        cout << "3. Doc du lieu tu file" << endl;
        cout << "5. Xuat" << endl;
        cout << "6. Xuat file sau khi random" << endl;
        cout << "8. HeapSort" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap yeu cau: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap so luong phan tu: ";
            cin >> n;
            nhapMang_37_Hau_Bai_1e_N2(arr, n);
            cout << "Chon \"5. Xuat\" de xem" << endl;
            break;
        case 2:
        {
            cout << "Nhap so luong phan tu de random va ghi file: ";
            cin >> n;
            nhapMangRandom_37_Hau_Bai_1e_N2(arr, n);
            writeFile_37_Hau_Bai_1e_N2(arr, n, "Bai_1e_37_Hau.txt");
            cout << "Da tao so random va ghi vao file vui long chon \"3. Doc tu file\" de xem" << endl;
            break;
        }
        case 3:
        {
            cout << "Da doc tu file: ";
            string filename = "Bai_1e_37_Hau.txt";
            processFile_37_Hau_Bai_1e_N2(arr, filename);
        }
        break;
        case 5:
        {
            cout << "Danh sach hien tai sau khi sap xep " << endl;
            xuatMang_37_Hau_Bai_1e_N2(arr, n);
            break;
        }

        case 8:
        {
            cout << "Danh sach da duoc sap xep bang thuat toan QuickSort" << endl;
            quickSort_37_Hau_Bai_1e_N2(arr, 0, n - 1);
            break;
        }
        case 0:
            cout << "Ket thuc chuong trinh." << endl;
            break;

        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
        _getch();
    } while (choice != 0);
    system("pause");
    return 0;
}
