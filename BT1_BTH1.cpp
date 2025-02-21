

#include <iostream>
#include <conio.h>
using namespace std;


//a. Khai báo cấu trúc danh sách :
struct List {
    int elements[100];
    int size;
};


// Khai báo các thủ tục:
void nhapDanhSach(List& danhSach);
void xuatDanhSach(List danhSach);
int timPhanTu(List danhSach, int phanTu);
void timXoaPhanTu(List& danhSach, int phanTu);
void timTatCa(List danhSach, int phanTu);
void chenPhanTu(List& danhSach, int phanTu, int viTri);
void xoaPhanTuViTri(List& danhSach, int viTri);
void xoaPhanTuTrung(List& danhSach);
void daoNguocDanhSach(List& danhSach);
bool laDoiXung(List danhSach);
void sapXepTangDan(List& danhSach);
void sapXepGiamDan(List& danhSach);
void hoanViPhanTu(List& danhSach, int viTri1, int viTri2);
void ghepHaiDanhSach(List& danhSach1, List& danhSach2);
void timPhanTuVaTinh(List danhSach, int phanTu);

int main() {
    List danhSach;
    int luaChon, phanTu, viTri;
    do {
        system("cls");
        cout << "--------MENU--------" << endl;
        cout << "1. Nhap danh sach" << endl;
        cout << "2. Xuat danh sach" << endl;
        cout << "3. Tim mot phan tu va tinh thoi gian thuc hien" << endl;
        cout << "4. Tim mot phan tu va xoa phan tu do" << endl;
        cout << "5. Tim tat ca cac vi tri cua mot phan tu" << endl;
        cout << "6. Chen mot phan tu" << endl;
        cout << "7. Xoa mot phan tu tai vi tri" << endl;
        cout << "8. Xoa cac phan tu trung nhau" << endl;
        cout << "9. Dao nguoc danh sach" << endl;
        cout << "10. Kiem tra doi xung" << endl;
        cout << "11. Sap xep tang dan" << endl;
        cout << "12. Sap xep giam dan" << endl;
        cout << "13. Hoan vi hai phan tu" << endl;
        cout << "14. Ghep hai danh sach" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 0:
            cout << "Tam biet!";
            break;
        case 1:
            nhapDanhSach(danhSach);
            break;
        case 2:
            xuatDanhSach(danhSach);
            break;
        case 3:
            cout << "Nhap phan tu can tim: ";
            cin >> phanTu;
            timPhanTuVaTinh(danhSach, phanTu);
            break;
        case 4:
            cout << "Nhap phan tu can xoa: ";
            cin >> phanTu;
            timXoaPhanTu(danhSach, phanTu);
            break;
        case 5:
            cout << "Nhap phan tu can tim: ";
            cin >> phanTu;
            timTatCa(danhSach, phanTu);
            break;
        case 6:
            cout << "Nhap phan tu can chen: ";
            cin >> phanTu;
            cout << "Nhap vi tri can chen: ";
            cin >> viTri;
            chenPhanTu(danhSach, phanTu, viTri);
            break;
        case 7:
            cout << "Nhap vi tri can xoa: ";
            cin >> viTri;
            xoaPhanTuViTri(danhSach, viTri);
            break;
        case 8:
            xoaPhanTuTrung(danhSach);
            break;
        case 9:
            daoNguocDanhSach(danhSach);
            break;
        case 10:
            if (laDoiXung(danhSach)) {
                cout << "Danh sach la doi xung" << endl;
            }
            else {
                cout << "Danh sach khong doi xung" << endl;
            }
            break;
        case 11:
            sapXepTangDan(danhSach);
            break;
        case 12:
            sapXepGiamDan(danhSach);
            break;
        case 13:
            cout << "Nhap vi tri phan tu 1: ";
            cin >> viTri;
            cout << "Nhap vi tri phan tu 2: ";
            cin >> phanTu;
            hoanViPhanTu(danhSach, viTri, phanTu);
            break;
        case 14:
            List danhSach2;
            nhapDanhSach(danhSach2);
            ghepHaiDanhSach(danhSach, danhSach2);
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            break;
        }
        _getch();
    } while (luaChon != 0);
    return 0;
}


//b. Viết thủ tục nhập danh sách :
void nhapDanhSach(List& danhSach) {
    cout << "Nhap kich thuoc cua danh sach (toi da la 100): ";
    cin >> danhSach.size;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < danhSach.size; i++) {
        cin >> danhSach.elements[i];
    }
}


//c. Viết thủ tục xuất danh sách ra màn hình :
void xuatDanhSach(List danhSach) {
    cout << "Danh sach: ";
    for (int i = 0; i < danhSach.size; i++) {
        cout << danhSach.elements[i] << " ";
    }
    cout << endl;
}


//d. Viết thủ tục tìm một phần tử trong danh sách. Tính độ phức tạp của thuật toán :
int timPhanTu(List danhSach, int phanTu) {
    for (int i = 0; i < danhSach.size; i++) {
        if (danhSach.elements[i] == phanTu) {
            return i; // Tìm thấy phần tử tại vị trí i
        }
    }
    return -1; // Không tìm thấy phần tử
}
// Độphức tạp: O(n)
// 
//d. Viết thủ tục tìm một phần tử trong danh sách. Tính độ phức tạp của thuật toán :
void timPhanTuVaTinh(List danhSach, int phanTu) {
    clock_t start = clock();

    for (int i = 0; i < danhSach.size; i++) {
        if (danhSach.elements[i] == phanTu) {
            std::cout << "Tim thay phan tu " << phanTu << " tai vi tri " << i + 1 << std::endl;
            break;
        }
    }

    clock_t end = clock();
    double thoiGian = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Thoi gian tim kiem: " << thoiGian << " giay" << std::endl;
}

//e. Tìm một phần tử trong danh sách. Nếu tìm thấy, xoá phần tử đó :
void timXoaPhanTu(List& danhSach, int phanTu) {
    int viTri = timPhanTu(danhSach, phanTu);
    if (viTri != -1) {
        for (int i = viTri; i < danhSach.size - 1; i++)
        {
            danhSach.elements[i] = danhSach.elements[i + 1];
        }
        danhSach.size--;
    }
}


//f. Viết thủ tục tìm một phần tử trong danh sách. Trả về tất cả vị trí xuất hiện của nó :
void timTatCa(List danhSach, int phanTu) {
    cout << "Cac vi tri cua " << phanTu << ": ";
    for (int i = 0; i < danhSach.size; i++) {
        if (danhSach.elements[i] == phanTu) {
            cout << i << " ";
        }
    }
    cout << endl;
}


//j. Viết thủ tục thêm một phần tử tại vị trí thứ i vào danh sách :
void chenPhanTu(List& danhSach, int phanTu, int viTri) {
    if (danhSach.size == 100) { // Danh sách đã đầy
        return;
    }
    if (viTri < 0 || viTri > danhSach.size) { // Vị trí chèn không hợp lệ
        return;
    }
    for (int i = danhSach.size - 1; i >= viTri; i--) {
        danhSach.elements[i + 1] = danhSach.elements[i];
    }
    danhSach.elements[viTri] = phanTu;
    danhSach.size++;
}


//h. Viết thủ tục xoá phần tử tại vị trí thứ i trong danh sách :
void xoaPhanTuViTri(List& danhSach, int viTri) {
    if (viTri < 0 || viTri >= danhSach.size) { // Vị trí xoá không hợp lệ
        return;
    }
    for (int i = viTri; i < danhSach.size - 1; i++) {
        danhSach.elements[i] = danhSach.elements[i + 1];
    }
    danhSach.size--;
}


//i. Viết thủ tục xóa các phần tử phía sau khi trùng với phần tử đầu :
void xoaPhanTuTrung(List& danhSach) {
    int i = 0;
    while (i < danhSach.size) {
        int j = i + 1;
        while (j < danhSach.size) {
            if (danhSach.elements[j] == danhSach.elements[i]) {
                xoaPhanTuViTri(danhSach, j);
            }
            else {
                j++;
            }
        }
        i++;
    }
}


//j. Viết thủ tục đảo ngược các phần tử trong danh sách :
void daoNguocDanhSach(List& danhSach) {
    for (int i = 0; i < danhSach.size / 2; i++) {
        int temp = danhSach.elements[i];
        danhSach.elements[i] = danhSach.elements[danhSach.size - i - 1];
        danhSach.elements[danhSach.size - i - 1] = temp;
    }
}


//k. Viết thủ tục xem mảng có đối xứng hay không :
bool laDoiXung(List danhSach) {
    for (int i = 0; i < danhSach.size / 2; i++) {
        if (danhSach.elements[i] != danhSach.elements[danhSach.size - i - 1]) {
            return false;
        }
    }
    return true;
}


//l. Viết thủ tục sắp xếp mảng tăng dần :
void sapXepTangDan(List& danhSach) {
    for (int i = 0; i < danhSach.size - 1; i++) {
        for (int j = i + 1; j < danhSach.size; j++) {
            if (danhSach.elements[i] > danhSach.elements[j]) {
                int temp = danhSach.elements[i];
                danhSach.elements[i] = danhSach.elements[j];
                danhSach.elements[j] = temp;
            }
        }
    }
}


//m. Viết thủ tục sắp xếp mảng giảm dần :
void sapXepGiamDan(List& danhSach) {
    for (int i = 0; i < danhSach.size - 1; i++) {
        for (int j = i + 1; j < danhSach.size; j++) {
            if (danhSach.elements[i] < danhSach.elements[j]) {
                int temp = danhSach.elements[i];
                danhSach.elements[i] = danhSach.elements[j];
                danhSach.elements[j] = temp;
            }
        }
    }
}


//n. Viết thủ tục hoán đổi 2 vị trí trong danh sách :
void hoanViPhanTu(List& danhSach, int viTri1, int viTri2) {
    if (viTri1 < 0 || viTri1 >= danhSach.size || viTri2 < 0 || viTri2 >= danhSach.size) {
        return;
    }
    int temp = danhSach.elements[viTri1];
    danhSach.elements[viTri1] = danhSach.elements[viTri2];
    danhSach.elements[viTri2] = temp;
}


//o. Viết thủ tục ghép nối 2 mảng một chiều thành 1 danh sách lớn :
void ghepHaiDanhSach(List& danhSach1, List& danhSach2) {
    if (danhSach1.size + danhSach2.size > 100) { // Tổng số phần tử vượt quá giới hạn
        return;
    }
    for (int i = 0; i < danhSach2.size; i++) {
        danhSach1.elements[danhSach1.size + i] = danhSach2.elements[i];
    }
    danhSach1.size += danhSach2.size;
}
