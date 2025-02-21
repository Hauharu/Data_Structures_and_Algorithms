/*
Quản lý một danh sách liên kết vòng.
a. Khai báo cấu trúc danh sách
b. Viết thủ tục khởi tạo danh sách rỗng
c. Viết thủ tục xuất các phần tử trong danh sách
d. Viết thủ tục thêm một phần tử vào đầu danh sách
e. Viết thủ tục xoá một phần tử trong đầu danh sách
f. Viết thủ tục thêm một phần tử vào cuối danh sách
g. Viết thủ tục xoá một phần tử trong cuối danh sách
h. Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, xoá phần tử này
*/

#include <iostream>
#include <conio.h>
using namespace std;

// Khai báo cấu trúc Node
struct Node {
    int info;
    Node* next;
};

// Khai báo danh sách liên kết vòng
struct CircularLinkedList {
    Node* first;
};

// Thủ tục khởi tạo danh sách rỗng
void Init(CircularLinkedList& l) {
    l.first = NULL;
}

// Thủ tục kiểm tra danh sách rỗng
bool IsEmpty(CircularLinkedList l) {
    return l.first == NULL;
}

// Thủ tục xuất các phần tử trong danh sách
void PrintCircularLinkedList(CircularLinkedList l) {
    if (l.first == NULL) {
        cout << "Danh sach rong!";
    }
    else {
        Node* p = l.first;
        do {
            cout << p->info << " ";
            p = p->next;
        } while (p != l.first);
    }
    cout << endl;
}

// Thủ tục thêm một phần tử vào đầu danh sách
void InsertAtBeginning(CircularLinkedList& l, int x) {
    Node* p = new Node;
    p->info = x;
    if (l.first == NULL) {
        p->next = p;
        l.first = p;
    }
    else {
        Node* tail = l.first;
        while (tail->next != l.first) {
            tail = tail->next;
        }
        p->next = l.first;
        tail->next = p;
        l.first = p;
    }
}

// Thủ tục xoá một phần tử trong đầu danh sách
void DeleteAtBeginning(CircularLinkedList& l) {
    if (l.first == NULL) {
        cout << "Danh sach rong!";
        return;
    }
    Node* tail = l.first;
    while (tail->next != l.first) {
        tail = tail->next;
    }
    Node* p = l.first;
    if (p == tail) {
        l.first = NULL;
    }
    else {
        l.first = p->next;
        tail->next = l.first;
    }
    delete p;
}

// Thủ tục thêm một phần tử vào cuối danh sách
void InsertAtEnd(CircularLinkedList& l, int x) {
    Node* p = new Node;
    p->info = x;
    if (l.first == NULL) {
        p->next = p;
        l.first = p;
    }
    else {
        Node* tail = l.first;
        while (tail->next != l.first) {
            tail = tail->next;
        }
        p->next = l.first;
        tail->next = p;
    }
}

// Thủ tục xoá một phần tử trong cuối danh sách
void DeleteAtEnd(CircularLinkedList& l) {
    if (l.first == NULL) {
        cout << "Danh sach rong!";
        return;
    }
    Node* tail = l.first;
    while (tail->next->next != l.first) {
        tail = tail->next;
    }
    Node* p = tail->next;
    tail->next = l.first;
    delete p;
}

// Thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, xoá phần tử này
void DeleteNode(CircularLinkedList& l, int x) {
    if (l.first == NULL) {
        cout << "Danh sach rong!";
        return;
    }
    Node* p = l.first;
    Node* prev = NULL;
    do {
        if (p->info == x) {
            if (prev == NULL) {
                DeleteAtBeginning(l);
            }
            else {
                prev->next = p->next;
                if (p == l.first) {
                    l.first = p->next;
                }
                delete p;
            }
            cout << "Phan tu " << x << " da duoc xoa khoi danh sach!\n";
            return;
        }
        prev = p;
        p = p->next;
    } while (p != l.first);
    cout << "Khong tim thay phan tu " << x << " trong danh sach!\n";
}

int main() {
    CircularLinkedList l;
    int choice, x;
    Init(l);
    while (true) {
        system("cls");
        cout << "\n---------------------------------------------------\n";
        cout << "Menu:\n";
        cout << "1. Them phan tu vao dau danh sach\n";
        cout << "2. Them phan tu vao cuoi danh sach\n";
        cout << "3. Xoa phan tu dau danh sach\n";
        cout << "4. Xoa phan tu cuoi danh sach\n";
        cout << "5. Xoa mot phan tu trong danh sach\n";
        cout << "6. Xuat danh sach\n";
        cout << "7. Thoat chuong trinh\n";
        cout << "Nhap lua chon cua ban (1-7): ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Nhap gia tri muon them vao dau danh sach: ";
            cin >> x;
            InsertAtBeginning(l, x);
            break;
        case 2:
            cout << "Nhap gia tri muon them vao cuoi danh sach: ";
            cin >> x;
            InsertAtEnd(l, x);
            break;
        case 3:
            DeleteAtBeginning(l);
            break;
        case 4:
            DeleteAtEnd(l);
            break;
        case 5:
            cout << "Nhap gia tri muon xoa: ";
            cin >> x;
            DeleteNode(l, x);
            break;
        case 6:
            cout << "Danh sach: ";
            PrintCircularLinkedList(l);
            break;
        case 7:
            return 0;
        default:
            cout << "Lua chon khong hop le!";
        }
        _getch();
    }
    return 0;
}
