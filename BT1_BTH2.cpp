#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

struct DanhSach {
    int data[100];
    int count;
};

// Khai báo các hàm
void NhapDanhSach(DanhSach& ds);
void NhapDanhSachTuFile(DanhSach& ds, const string& fileName);
void XuatDanhSach(const DanhSach& ds);
void InsertionSort(DanhSach& ds);
void SelectionSort(DanhSach& ds);
void InterchangeSort(DanhSach& ds);
void BubbleSort(DanhSach& ds);
void Merge(DanhSach& ds, int left, int middle, int right);
void MergeSort(DanhSach& ds, int left, int right);
int TimKiemTuanTu(const DanhSach& ds, int key);
int TimKiemNhiPhan(const DanhSach& ds, int key);
bool KiemTraMangTangDan(const DanhSach& ds);

int main() 
{
    DanhSach ds;
 

    int choice;
    do {
        system("cls");
        cout << "\n---------------------";
        cout << "\nCHUONG TRINH QUAN LY DANH SACH";
        cout << "\n---------------------";
        cout << "\n1. Nhap danh sach tu ban phim";
        cout << "\n2. Nhap danh sach tu file";
        cout << "\n3. Xuat danh sach";
        cout << "\n4. Sap xep danh sach bang Insertion Sort";
        cout << "\n5. Sap xep danh sach bang Selection Sort";
        cout << "\n6. Sap xep danh sach bang Interchange Sort";
        cout << "\n7. Sap xep danh sach bang Bubble Sort";
        cout << "\n8. Sap xep danh sach bang Merge Sort";
        cout << "\n9. Tim kiem phan tu trong danh sach (Tim kiem tuan tu)";
        cout << "\n10. Tim kiem phan tu trong danh sach (Tim kiem nhi phan)";
        cout << "\n11. Kiem tra mang co phai la mang tang dan?";
        cout << "\n0. Thoat";
        cout << "\n---------------------";
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            NhapDanhSach(ds);
            break;
        case 2: {
            string fileName;
            cout << "Nhap ten file: ";
            cin >> fileName;
            NhapDanhSachTuFile(ds, fileName);
            break;
        }
        case 3:
            XuatDanhSach(ds);
            break;
        case 4:
            InsertionSort(ds);
            break;
        case 5:
            SelectionSort(ds);
            break;
        case 6:
            InterchangeSort(ds);
            break;
        case 7:
            BubbleSort(ds);
            break;
        case 8:
            MergeSort(ds, 0, ds.count - 1);
            cout << "Da sap xep danh sach bang Merge Sort." << endl;
            break;
        case 9: {
            int key;
            cout << "Nhap phan tu can tim: ";
            cin >> key;
            int index = TimKiemTuanTu(ds, key);
            if (index != -1) {
                cout << "Phan tu " << key << " co trong danh sach tai vi tri " << index << endl;
            }
            else {
                cout << "Phan tu " << key << " khong co trong danh sach." << endl;
            }
            break;
        }
        case 10: {
            int key;
            cout << "Nhap phan tu can tim: ";
            cin >> key;
            int index = TimKiemNhiPhan(ds, key);
            if (index != -1) {
                cout << "Phan tu " << key << " co trong danh sach tai vi tri " << index << endl;
            }
            else {
                cout << "Phan tu " << key << " khong co trong danh sach." << endl;
            }
            break;
        }
        case 11:
            if (KiemTraMangTangDan(ds)) {
                cout << "Danh sach la mot mang tang dan." << endl;
            }
            else {
                cout << "Danh sach khong phai la mot mang tang dan." << endl;
            }
            break;
        case 0:
            cout << "Thoat chuong trinh.";
            break;
        default:
            cout << "Lua chon khong hop le.";
            break;
        }
        _getch();
    } while (choice != 0);

    return 0;
}

void NhapDanhSach(DanhSach& ds) {
    cout << "Nhap so luong phan tu: ";
    cin >> ds.count;

    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < ds.count; i++) {
        cin >> ds.data[i];
    }
}

void NhapDanhSachTuFile(DanhSach& ds, const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        file >> ds.count;
        for (int i = 0; i < ds.count; i++) {
            file >> ds.data[i];
        }
        file.close();
        cout << "Nhap danh sach tu file thanh cong." << endl;
    }
    else {
        cout << "Khong the mo file." << endl;
    }
}

void XuatDanhSach(const DanhSach& ds) {
    cout << "Danh sach: ";
    for (int i = 0; i < ds.count; i++) {
        cout << ds.data[i] << " ";
    }
    cout << endl;
}

void InsertionSort(DanhSach& ds) {
    for (int i = 1; i < ds.count; i++) {
        int key = ds.data[i];
        int j = i - 1;
        while (j >= 0 && ds.data[j] > key) {
            ds.data[j + 1] = ds.data[j];
            j--;
        }
        ds.data[j + 1] = key;
    }
    cout << "Da sap xep danh sach bang Insertion Sort." << endl;
}

void SelectionSort(DanhSach& ds) {
    for (int i = 0; i < ds.count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < ds.count; j++) {
            if (ds.data[j] < ds.data[minIndex]) {
                minIndex = j;
            }
        }
        swap(ds.data[i], ds.data[minIndex]);
    }
    cout << "Da sap xep danh sach bang Selection Sort." << endl;
}

void InterchangeSort(DanhSach& ds) {
    for (int i = 0; i < ds.count - 1; i++) {
        for (int j = i + 1; j < ds.count; j++) {
            if (ds.data[j] < ds.data[i]) {
                swap(ds.data[i], ds.data[j]);
            }
        }
    }
    cout << "Da sap xep danh sach bang Interchange Sort." << endl;
}

void BubbleSort(DanhSach& ds) {
    for (int i = 0; i < ds.count - 1; i++) {
        for (int j = 0; j < ds.count - i - 1; j++) {
            if (ds.data[j] > ds.data[j + 1]) {
                swap(ds.data[j], ds.data[j + 1]);
            }
        }
    }
    cout << "Da sap xep danh sach bang Bubble Sort." << endl;
}

void Merge(DanhSach& ds, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = ds.data[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = ds.data[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            ds.data[k] = L[i];
            i++;
        }
        else {
            ds.data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        ds.data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        ds.data[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void MergeSort(DanhSach& ds, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        MergeSort(ds, left, middle);
        MergeSort(ds, middle + 1, right);

        Merge(ds, left, middle, right);
    }
}

int TimKiemTuanTu(const DanhSach& ds, int key) {
    for (int i = 0; i < ds.count; i++) {
        if (ds.data[i] == key) {
            return i;
        }
    }
    return -1;
}

int TimKiemNhiPhan(const DanhSach& ds, int key) {
    int left = 0;
    int right = ds.count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds.data[mid] == key) {
            return mid;
        }
        if (ds.data[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

bool KiemTraMangTangDan(const DanhSach& ds) {
    for (int i = 1; i < ds.count; i++) {
        if (ds.data[i] < ds.data[i - 1]) {
            return false;
        }
    }
    return true;
}
