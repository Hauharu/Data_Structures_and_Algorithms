/*
Quản lý một danh sách có số phần tử khá lớn, biến động. Mỗi phần tử có kiểu int. Thường 
có nhu cầu truy suất phần tử đứng trước và phần tử đứng sau phần tử đang truy xuất. (Danh sách
liên kết kép)
a. Khai báo cấu trúc danh sách
b. Viết thủ tục khai báo danh sách rỗng
c. Xuất các phần tử trong danh sách.
d. Viết thủ tục thêm phần tử vào đầu danh sách
e. Viết thủ tục thêm một phần tử vào cuối danh sách.
f. Viết thủ tục xoá phần tử đầu danh sách
g. Viết thủ tục xoá phần tử cuối danh sách
h. Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, xoá phần tử này
i. Viết thủ tục tìm một phần tử có giá trị bằng với giá trị x hoặc gần nhất và lớn hơn phần tử x nhập vào;
   Thêm một phần tử trước phần tử tìm thấy
*/

#include <iostream>
#include <conio.h>
using namespace std;

// Khai báo cấu trúc danh sách 
struct Node 
{
    int info;
    Node* prev;
    Node* next;
};

// Khai báo danh sách 
struct LinkedList
{
    Node* first, * last;
};

void Init(LinkedList& l);
void process_List(LinkedList l);
void insert_First(LinkedList& l, int x);
void insert_Last(LinkedList& l, int x);
void delete_First(LinkedList& l);
void delete_Last(LinkedList& l);
void delete_Node(LinkedList& l, int x);
void InsertBeforeClosest(LinkedList& l, int x);
void delete_Pointer(LinkedList& l);

// hàm main
int main() {
    LinkedList l;
    int choose, x;
    bool in = true;
    Init(l);
    while (true) {
        system("cls");
        cout << "\n-------------------------------------------\n";
        cout << "Menu:\n";
        cout << "1. Them phan tu vao dau danh sach\n";
        cout << "2. Them phan tu vao cuoi danh sach\n";
        cout << "3. Xoa phan tu dau danh sach\n";
        cout << "4. Xoa phan tu cuoi danh sach\n";
        cout << "5. Xoa mot phan tu trong danh sach\n";
        cout << "6. Tim phan tu gan nhat va chen mot phan tu vao truoc\n";
        cout << "7. Xuat danh sach\n";
        cout << "8. Thoat chuong trinh\n";
        cout << "Nhap lua chon cua ban (1-8): ";
        cin >> choose;
        switch (choose) {
        case 1:
            cout << "Nhap gia tri muon them vao dau danh sach: ";
            cin >> x;
            insert_First(l, x);
            in = true;
            break;
        case 2:
            cout << "Nhap gia tri muon them vao cuoi danh sach: ";
            cin >> x;
            insert_Last(l, x);
            in = true;
            break;
        case 3:
            if (in)
                delete_First(l);
            else
                cout << "Mang chua duoc nhap.\n";
            break;
        case 4:
            if (in)
                delete_Last(l); 
            else
                cout << "Mang chua duoc nhap.\n";
            break;
        case 5:
            if (in)
            {
                cout << "Nhap gia tri muon xoa: ";
                cin >> x;
                delete_Node(l, x);
            }
            else
                cout << "Mang chua duoc nhap.\n";
            break;
        case 6:
            if (in)
            {
                cout << "Nhap gia tri muon chen: ";
                cin >> x;
                InsertBeforeClosest(l, x);
            }
            else
                cout << "Mang chua duoc nhap.\n";
            break;
        case 7:
            if (in)
            {
                cout << "Danh sach dang luu tru: ";
                process_List(l);
            }
            else
                cout << "Mang chua duoc nhap.\n";
            break;
        case 8:
            delete_Pointer(l);
            cout << "Thoat chuong trinh\n";
            return 0;
        default:
            cout << "Lua chon khong hop le!";
        }
        _getch();
    }
    return 0;
}

// Thủ tục Khai báo danh sách rỗng
void Init(LinkedList& l) {
    l.first = NULL;
    l.last = NULL;
}

// Thủ tục xuất các phần tử trong danh sách
void process_List(LinkedList l) {
    Node* p = l.first;
    if (p == NULL) {
        cout << "Danh sach rong!";
        return;
    }
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
}

// Thủ tục thêm phần tử vào đầu danh sách
void insert_First(LinkedList& l, int x) {
    Node* p = new Node;
    p->info = x;
    p->prev = NULL;
    if (l.first == NULL) {
        l.first = p;
        l.last = p;
        p->next = NULL;
    }
    else {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

// Thủ tục thêm phần tử vào cuối danh sách
void insert_Last(LinkedList& l, int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    if (l.first == NULL) {
        l.first = p;
        l.last = p;
        p->prev = NULL;
    }
    else {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

// Thủ tục xoá phần tử đầu danh sách
void delete_First(LinkedList& l) {
    if (l.first == NULL) {
        cout << "Danh sach rong!";
        return;
    }
    Node* p = l.first;
    l.first = l.first->next;
    if (l.first == NULL) {
        l.last = NULL;
    }
    else {
        l.first->prev = NULL;
    }
    delete p;
}

// Thủ tục xoá phần tử cuối danh sách
void delete_Last(LinkedList& l) {
    if (l.last == NULL) {
        cout << "Danh sach rong!";
        return;
    }
    Node* p = l.last;
    l.last = l.last->prev;
    if (l.last == NULL) {
        l.first = NULL;
    }
    else {
        l.last->next = NULL;
    }
    delete p;
}

// Thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, xoá phần tử này
void delete_Node(LinkedList& l, int x) {
    Node* p = l.first;
    while (p != NULL && p->info != x) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Khong tim thay phan tu " << x << " trong danh sach!\n";
        return;
    }
    if (p->prev == NULL) {
        delete_First(l);
    }
    else if (p->next == NULL) {
        delete_Last(l);
    }
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}

// Thủ tục tìm một phần tử có giá trị bằng với giá trị x hoặc gần nhất và lớn hơn phần tử x nhập vào; Thêm một phần tử trước phần tử tìm thấy
void InsertBeforeClosest(LinkedList& l, int x) {
    Node* p = l.first;
    int min_diff = INT_MAX;
    Node* closest = NULL;
    while (p != NULL) {
        int diff = abs(p->info - x);
        if (diff < min_diff) {
            min_diff = diff;
            closest = p;
        }
        p = p->next;
    }
    insert_First(l, x);
    if (closest != l.first) {
        closest->prev->next = l.first;
        l.first->prev = closest->prev;
        closest->prev = l.first;
        l.first->next = closest;
    }
    else {
        l.first->next = closest;
        closest->prev = l.first;
    }
}

// Hủy danh sách
void delete_Pointer(LinkedList& l)
{
    while (l.first != NULL || l.last != NULL)
    {
        delete l.first;
        delete l.last;
    }
}
