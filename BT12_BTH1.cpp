/*
   Quản lý một queue có tối đa 100 phần tử, mỗi phần tử trong queue có kiểu int
a. Khai báo cấu trúc queue
b. Viết thủ tục khỏi tạo queue rỗng
c. Viết thủ tục xét queue rỗng
d. Viết thủ tục xét queue đầy
e. Viết thủ tục thêm một phần tử vào queue
f. Viết thủ tục xoá một phần tử trong queue
*/
#include <iostream>
#include <conio.h>
struct Queue {
    int items[100];
    int front;
    int rear;
};

// Khởi tạo một Queue rỗng
void taoHangDoi(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Kiểm tra Queue có rỗng hay không
bool rong(Queue* queue) {
    return queue->front == -1;
}

// Kiểm tra Queue có đầy hay không
bool day(Queue* queue) {
    return queue->rear == 99;
}

// Thêm một phần tử vào Queue
void themPhanTu(Queue* queue, int value) {
    if (day(queue)) {
        std::cout << "Queue da day khong the them phan tu." << std::endl;
        return;
    }

    if (rong(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = value;

    std::cout << "Da them phan tu " << value << " thanh cong." << std::endl;
}

// Xoá một phần tử trong Queue
void xoaPhanTu(Queue* queue) {
    if (rong(queue)) {
        std::cout << "Queue dang trong. Khong the xoa phan tu." << std::endl;
        return;
    }

    int value = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        // Reset Queue về trạng thái rỗng nếu tất cả phần tử đã được xoá
        taoHangDoi(queue);
    }

    std::cout << "Da xoa phan tu " << value << " thanh cong." << std::endl;
}

// In ra các phần tử trong Queue
void inHangDoi(Queue* queue) {
    if (rong(queue)) {
        std::cout << "Queue đang trong." << std::endl;
        return;
    }

    std::cout << "Queue: ";
    for (int i = queue->front; i <= queue->rear; i++) {
        std::cout << queue->items[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Queue queue;
    taoHangDoi(&queue);

    int choice;
    int element;

    do {
        system("cls");
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Them phan tu" << std::endl;
        std::cout << "2. Xoa phan tu" << std::endl;
        std::cout << "3. In Queue" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;

        switch (choice) {
        case 0:
            std::cout << "Thoat khoi chuong trinh..." << std::endl;
            break;
        case 1:
            std::cout << "Nhap phan tu muon them: ";
            std::cin >> element;
            themPhanTu(&queue, element);
            break;
        case 2:
            xoaPhanTu(&queue);
            break;
        case 3:
            inHangDoi(&queue);
            break;
        default:
            std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
        _getch();
    } while (choice != 0);

    return 0;
}
