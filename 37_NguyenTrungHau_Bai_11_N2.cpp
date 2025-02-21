#include <iostream>
#include <ctime>
#define MAX 100
#include <cstdlib>
using namespace std;
// Hàm nhập mảng sử dụng hàm random
void nhapMang_37_NguyenTrungHau_Bai_1_N2(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (50 - 30 + 1) + 30;
    }
}

// Hàm in mảng ra màn hình
void xuatMang_37_NguyenTrungHau_Bai_1_N2(int arr[], int n) {
    cout << "Mang hien tai: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm tìm kiếm một phần tử trong mảng và trả về chỉ số của nó, -1 nếu không tìm thấy
int timKiem_37_NguyenTrungHau_Bai_1_N2(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Hàm thêm một phần tử mới vào mảng
void themPhanTu(int arr[], int& n, int x, int vitri) {
    // Đẩy tất cả phần tử từ vị trí vitri về sau một bước
    for (int i = n - 1; i >= vitri; i--) {
        arr[i + 1] = arr[i];
    }

    // Thêm phần tử x vào vị trí vitri
    arr[vitri] = x;

    // Tăng kích thước mảng lên 1
    n++;
}

// Hàm xóa một phần tử khỏi mảng
void xoaPhanTu(int arr[], int& n, int vitri) {
    // Dịch tất cả phần tử từ vị trí vitri về sau một bước
    for (int i = vitri; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Giảm kích thước mảng xuống 1
    n--;
}

int main()
{
    int arr[MAX], x, b, n, vitri;
    do {
        cout << "Nhap so phan tu mang: ";
        cin >> n;
        if (n<0 || n>MAX)
            cout << "Nhap sai, nhap lai" << endl;
    } while (n<0 || n>MAX);
    nhapMang_37_NguyenTrungHau_Bai_1_N2(arr, n);
    xuatMang_37_NguyenTrungHau_Bai_1_N2(arr, n);
    cout << "Nhap phan tu can tim kiem: ";
    cin >> x;
    vitri = timKiem_37_NguyenTrungHau_Bai_1_N2(arr, n, x);
    if (vitri != -1) {
        cout << "Tim thay phan tu " << x << " tai vi tri " << vitri << endl;
    }
    else {
        cout << "Khong tim thay phan tu " << x << endl;
    }
    cout << "Nhap phan tu can them: ";
    cin >> b;
    cout << "Nhap vi tri muon them: ";
    cin >> vitri;
    themPhanTu(arr, n, b, vitri);
    xuatMang_37_NguyenTrungHau_Bai_1_N2(arr, n);
    cout << endl;
    cout << "Nhap vi tri phan tu muon xoa: ";
    cin >> vitri;
    xoaPhanTu(arr, n, vitri);
    xuatMang_37_NguyenTrungHau_Bai_1_N2(arr, n);
    cout << endl;
    return 0;
}