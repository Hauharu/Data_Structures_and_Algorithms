#include <iostream>
#include <conio.h>
using namespace std;

// Khai báo cấu trúc Node cho danh sách liên kết đơn
struct Node {
    int info;
    Node* next;
};

// Khai báo cấu trúc Queue
struct Queue {
    Node* front;
    Node* rear;
};

// Thủ tục khởi tạo queue rỗng
void initQueue(Queue& q) {
    q.front = NULL;
    q.rear = NULL;
}

// Thủ tục xét queue rỗng
bool isEmpty(Queue q) {
    return (q.front == NULL);
}

// Thủ tục thêm một phần tử vào queue
void enqueue(Queue& q, int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q.front = newNode;
        q.rear = newNode;
    }
    else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

// Thủ tục xoá một phần tử trong queue
void dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue dang rong\n";
    }
    else {
        Node* temp = q.front;
        q.front = q.front->next;
        delete temp;
    }
}

// Thủ tục xuất các phần tử trong queue
void output(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue dang rong\n";
    }
    else {
        Node* current = q.front;
        while (current != NULL) {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void deletePointer(Queue q)
{
    while (q.front != NULL || q.rear != NULL)
    {
        delete q.front;
        delete q.rear;
    }
}
// Hàm main để tạo menu và sử dụng các thủ tục quản lý queue
int main() {
    Queue q;
    initQueue(q);

    int choice, value;
    while (true) {
        system("cls");
        cout << "\n----- MENU -----\n";
        cout << "1. Them mot phan tu vao queue\n";
        cout << "2. Xoa mot phan tu trong queue\n";
        cout << "3. Xuat cac phan tu co trong queue\n";
        cout << "4. Chon 0 de thoat chuong trinh\n";
        cout << "Ban chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri can them: ";
            cin >> value;
            enqueue(q, value);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            output(q);
            break;
        case 0:
            deletePointer(q);
            cout<<"Thoat";
            return 0;
        default:
            cout << "Lua chon khong hop le!\n";
        }
        _getch();
    }
}
