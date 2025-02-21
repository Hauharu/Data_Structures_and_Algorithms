/*
   Quản lý một stack có số phần tử khá lớn, biến động. Mỗi phần tử có kiểu int (danh sách liên kết đơn)
a. Khai báo cấu trúc stack
b. Viết thủ tục khỏi tạo stack rỗng
c. Viết thủ tục xét stack rỗng
d. Viết thủ tục thêm một phần tử vào stack
e. Viết thủ tục xoá một phần tử trong stack
f. Áp dụng stack đã xây dựng, đổi số hệ thập sang hệ nhị phân
g. Áp dụng stack đã xây dựng, giải bài toán tháp Hà nội.(*)
*/
#include <iostream>
#include <conio.h>
using namespace std;

// Khai báo cấu trúc của một node trong danh sách liên kết đơn
struct Node {
    int info;
    Node* next;
};

// Khai báo cấu trúc của stack
struct Stack {
    Node* top;
};

// Thủ tục khởi tạo stack rỗng
void InitializeStack(Stack& stack) {
    stack.top = nullptr;
}

// Thủ tục kiểm tra stack rỗng
bool IsEmpty(Stack stack) {
    return stack.top == nullptr;
}

// Thủ tục xuất stack
void PrintStack(Stack stack) {
    cout << "Cac phan tu trong stack: ";
    Node* temp = stack.top;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Thủ tục thêm một phần tử vào stack
void Push(Stack& stack, int value) {
    // Tạo một node mới
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;

    // Thêm node vào đầu stack
    if (IsEmpty(stack)) {
        stack.top = newNode;
    }
    else {
        newNode->next = stack.top;
        stack.top = newNode;
    }
}

// Thủ tục xoá một phần tử trong stack
void Pop(Stack& stack) {
    if (IsEmpty(stack)) {
        cout << "Stack rong" << endl;
        return;
    }

    // Xoá node đầu stack
    Node* temp = stack.top;
    stack.top = stack.top->next;
    delete temp;
}

// Hàm chuyển đổi số hệ thập phân sang hệ nhị phân
void ConvertDecimalToBinary(int decimal) {
    Stack stack;
    InitializeStack(stack);

    while (decimal != 0) {
        int remainder = decimal % 2;
        Push(stack, remainder);
        decimal /= 2;
    }

    cout << "So he nhi phan tuong ung: ";
    while (!IsEmpty(stack)) {
        cout << stack.top->info;
        Pop(stack);
    }
    cout << endl;
}

// Hàm giải bài toán tháp Hà Nội
void HanoiTower(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Chuyen dia 1 tu cot " << source << " sang cot " << destination << endl;
        return;
    }

    HanoiTower(n - 1, source, destination, auxiliary);
    cout << "Chuyen dia " << n << " tu cot " << source << " sang cot " << destination << endl;
    HanoiTower(n - 1, auxiliary, source, destination);
}

int main() {
    int choice;
    Stack stack;
    InitializeStack(stack);

    do {
        system("cls");
        cout << "======= MENU =======" << endl;
        cout << "1. Kiem tra stack rong" << endl;
        cout << "2. Xuat cac phan tu" << endl;
        cout << "3. Them phan tu vao stack" << endl;
        cout << "4. Xoa phan tu trong stack" << endl;
        cout << "5. Chuyen doi so he thap phan sang he nhi phan" << endl;
        cout << "6. Giai bai toan thap Ha Noi" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (IsEmpty(stack)) {
                cout << "Stack rong" << endl;
            }
            else {
                cout << "Stack khong rong" << endl;
            }
            break;
        case 2:
            if (IsEmpty(stack)) {
                cout << "Stack rong" << endl;
            }
            else {
                cout << "Stack khong rong" << endl;
                PrintStack(stack);
            }
            break;
        case 3:
            int value;
            cout << "Nhap gia tri muon them vao stack: ";
            cin >> value;
            Push(stack, value);
            break;
        case 4:
            Pop(stack);
            break;
        case 5:
            int decimal;
            cout << "Nhap so he thap phan: ";
            cin >> decimal;
            ConvertDecimalToBinary(decimal);
            break;
        case 6:
            int n;
            cout << "Nhap so luong dia trong thap Ha Noi: ";
            cin >> n;
            HanoiTower(n, 'A', 'B', 'C');
            break;
        case 0:
            cout << "Thoat" << endl;
            break;
        default:
            cout << "Lua chon khong hop le! Vui long thu lai." << endl;
            break;
        }
        _getch();
    } while (choice != 0);

    return 0;
}
