/*
Quản lý danh sách liên kết đơn lưu các số nguyên.
2.1 Khai báo cấu trúc danh sách.
2.2 Viết thủ tục nhập danh sách từ bàn phím, từ file txt.
2.3 Viết thủ tục xuất danh sách.
2.4 Viết thủ tục sắp xếp danh sách theo thứ tự giảm dần bằng thuật toán InsertionSort.
2.5 Viết thủ tục sắp xếp danh sách theo thứ tự giảm dần bằng thuật toán SelectionSort.
2.6 Viết thủ tục sắp xếp danh sách theo thứ tự giảm dần bằng thuật toán InterchangeSort.
2.7 Viết thủ tục sắp xếp danh sách theo thứ tự giảm dần bằng thuật toán BubbleSort.
2.8 Viết thủ tục sắp xếp danh sách theo thứ tự giảm dần bằng thuật toán MergeSort.
2.9 Viết thủ tục tìm kiếm một phần tử trong danh sách có thứ tự (dùng phương pháp tìm kiếm
tuần tự).
2.10 Viết thủ tục tìm kiếm một phần tử trong danh sách có thứ tự (dùng phương pháp tìm kiếm
nhị phân). (Lưu ý: SV tự rút ra nhận xét về thuận lợi và khó khăn).
2.11 Viết thủ tục kiểm tra danh sách liên kết đơn có đang lưu các số nguyên giảm dần hay không?
2.12 Viết thủ tục đảo ngược danh sách liên kết đơn.
2.13 Viết thủ tục trả về danh sách liên kết đơn các phần tử là số chẵn trong danh sách liên kết
đơn ban đầu.
2.14 Viết main để kiểm chứng toàn bộ chương trình dưới dạng menu lựa chọn thủ tục thực hiện.
*/
#include <iostream>
#include <fstream>

using namespace std;

// 2.1 Khai báo cấu trúc danh sách liên kết đơn
struct Node {
    int info;
    Node* next;
};

// Hàm tạo một nút mới trong danh sách
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    return newNode;
}

// 2.2 Thủ tục nhập danh sách từ bàn phím
Node* inputList() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int value;
    char choice;

    do {
        cout << "Nhap gia tri: ";
        cin >> value;
        Node* newNode = createNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Tiep tuc? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return head;
}

// 2.3 Thủ tục xuất danh sách
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }

    cout << "Danh sach: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

// 2.4 Thủ tục sắp xếp danh sách theo thứ tự giảm dần (Insertion Sort)
void insertionSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* sortedList = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;

        if (sortedList == nullptr || current->info > sortedList->info) {
            current->next = sortedList;
            sortedList = current;
        }
        else {
            Node* temp = sortedList;
            while (temp->next != nullptr && current->info < temp->next->info)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    displayList(sortedList);
}

// 2.5 Thủ tục sắp xếp danh sách theo thứ tự giảm dần (Selection Sort)
void selectionSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* sortedList = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* maxNode = current;
        Node* temp = current->next;

        while (temp != nullptr) {
            if (temp->info > maxNode->info)
                maxNode = temp;
            temp = temp->next;
        }

        if (maxNode == current)
            sortedList = maxNode;
        else {
            Node* prev = current;
            while (prev->next != maxNode)
                prev = prev->next;
            prev->next = maxNode->next;
            maxNode->next = sortedList;
            sortedList = maxNode;
        }

        current = current->next;
    }

    displayList(sortedList);
}

// 2.6 Thủ tục sắp xếp danh sách theo thứ tự giảm dần (Interchange Sort)
void interchangeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* current = head;
    while (current->next != nullptr) {
        Node* temp = current->next;
        while (temp != nullptr) {
            if (temp->info > current->info)
                swap(temp->info, current->info);
            temp = temp->next;
        }
        current = current->next;
    }

    displayList(head);
}

// 2.7 Thủ tục sắp xếp danh sách theo thứ tự giảm dần (Bubble Sort)
void bubbleSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    bool sorted;
    Node* current;
    Node* last = nullptr;

    do {
        sorted = true;
        current = head;

        while (current->next != last) {
            if (current->info < current->next->info) {
                swap(current->info, current->next->info);
                sorted = false;
            }
            current = current->next;
        }

        last = current;
    } while (!sorted);

    displayList(head);
}

// Hàm hỗ trợ cho Merge Sort
Node* merge(Node* left, Node* right) {
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    Node* result = nullptr;
    if (left->info >= right->info) {
        result = left;
        result->next = merge(left->next, right);
    }
    else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// 2.8 Thủ tục sắp xếp danh sách theo thứ tự giảm dần (Merge Sort)
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    return merge(mergeSort(head), mergeSort(mid));
}

// 2.9 Thủ tục tìm kiếm một phần tử trong danh sách có thứ tự (Tìm kiếm tuần tự)
bool sequentialSearch(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->info == value)
            return true;
        current = current->next;
    }
    return false;
}

// 2.10 Thủ tục tìm kiếm một phần tử trong danh sách có thứ tự (Tìm kiếm nhị phân)
bool binarySearch(Node* head, int value) {
    Node* left = head;
    Node* right = nullptr;

    // Tìm độ dài danh sách
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    // Tìm kiếm nhị phân
    while (length > 0) {
        int mid = length / 2;
        right = head;
        for (int i = 0; i < mid; i++) {
            right = right->next;
        }

        if (right->info == value)
            return true;
        else if (right->info > value) {
            length = mid;
        }
        else {
            length -= mid + 1;
            head = right->next;
        }
    }

    return false;
}

// 2.11 Thủ tục kiểm tra danh sách có đang lưu các số nguyên giảm dần hay không
bool isDecreasingOrder(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->info < current->next->info)
            return false;
        current = current->next;
    }
    return true;
}

// 2.12 Thủ tục đảo ngược danh sách liên kết đơn
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

// 2.13 Thủ tục trả về danh sách liên kết đơn các phần tử là số chẵn trong danh sách ban đầu
Node* getEvenList(Node* head) {
    Node* evenList = nullptr;
    Node* tail = nullptr;
    Node* current = head;

    while (current != nullptr) {
        if (current->info % 2 == 0) {
            Node* newNode = createNode(current->info);
            if (evenList == nullptr) {
                evenList = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        current = current->next;
    }

    return evenList;
}

// 2.14 Main function để kiểm chứng toàn bộ chương trình dưới dạng menu lựa chọn thủ tục thực hiện
int main() {
    Node* head = nullptr;
    int choice, value;
    bool isSorted = false;

    do {
        cout << "\n-------------------------" << endl;
        cout << "CAC CHUC NANG CHUONG TRINH:" << endl;
        cout << "1. Nhap danh sach tu ban phim." << endl;
        cout << "2. Nhap danh sach tu file txt." << endl;
        cout << "3. Xuat danh sach." << endl;
        cout << "4. Sap xep danh sach theo thu tu giam dan (Insertion Sort)." << endl;
        cout << "5. Sap xep danh sach theo thu tu giam dan (Selection Sort)." << endl;
        cout << "6. Sap xep danh sach theo thu tu giam dan (Interchange Sort)." << endl;
        cout << "7. Sap xep danh sach theo thu tu giam dan (Bubble Sort)." << endl;
        cout << "8. Sap xep danh sach theo thu tu giam dan (Merge Sort)." << endl;
        cout << "9. Tim kiem mot phan tu trong danh sach co thu tu (Tim kiem tuan tu)." << endl;
        cout << "10. Tim kiem mot phan tu trong danh sach co thu tu (Tim kiem nhi phan)." << endl;
        cout << "11. Kiem tra danh sach co dang luu cac so nguyen giam dan hay khong." << endl;
        cout << "12. Dao nguoc danh sach." << endl;
        cout << "13. Tra ve danh sach cac phan tu la so chan trong danh sach ban dau." << endl;
        cout << "0. Thoat." << endl;
        cout << "-------------------------" << endl;

        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (head != nullptr) {
                cout << "Danh sach đa ton tai. Ban co muon ghi đe danh sach hien tai? (Y/N): ";
                char overwriteChoice;
                cin >> overwriteChoice;
                if (overwriteChoice == 'N' || overwriteChoice == 'n')
                    break;
            }
            head = inputList();
            isSorted = false;
            break;
        case 2: {
            if (head != nullptr) {
                cout << "Danh sach đa ton tai. Ban co muon ghi đe danh sach hien tai? (Y/N): ";
                char overwriteChoice;
                cin >> overwriteChoice;
                if (overwriteChoice == 'N' || overwriteChoice == 'n')
                    break;
            }

            string filename;
            cout << "Nhap ten file txt: ";
            cin >> filename;

            ifstream inputFile(filename);
            if (!inputFile) {
                cout << "Khong the mo file." << endl;
                break;
            }

            int value;
            while (inputFile >> value) {
                Node* newNode = createNode(value);
                if (head == nullptr) {
                    head = newNode;
                }
                else {
                    Node* temp = head;
                    while (temp->next != nullptr)
                        temp = temp->next;
                    temp->next = newNode;
                }
            }
            inputFile.close();

            isSorted = false;
            break;
        }
        case 3:
            displayList(head);
            break;
        case 4:
            insertionSort(head);
            isSorted = true;
            break;
        case 5:
            selectionSort(head);
            isSorted = true;
            break;
        case 6:
            interchangeSort(head);
            isSorted = true;
            break;
        case 7:
            bubbleSort(head);
            isSorted = true;
            break;
        case 8:
            head = mergeSort(head);
            isSorted = true;
            break;
        case 9:
            cout << "Nhap gia tri can tim: ";
            cin >> value;
            if (sequentialSearch(head, value))
                cout << "Phan tu " << value << " ton tai trong danh sach." << endl;
            else
                cout << "Phan tu " << value << " khong ton tai trong danh sach." << endl;
            break;
        case 10:
            if (!isSorted) {
                cout << "Danh sach chua đuoc sap xep. Vui long sap xep danh sach truoc." << endl;
                break;
            }

            cout << "Nhap gia tri can tim: ";
            cin >> value;
            if (binarySearch(head, value))
                cout << "Phan tu " << value << " ton tai trong danh sach." << endl;
            else
                cout << "Phan tu " << value << " khong ton tai trong danh sach." << endl;
            break;
        case 11:
            if (isDecreasingOrder(head))
                cout << "Danh sach luu cac so nguyen giam dan." << endl;
            else
                cout << "Danh sach khong luu cac so nguyen giam dan." << endl;
            break;
        case 12:
            head = reverseList(head);
            cout << "Danh sach đa duoc đao nguoc." << endl;
            break;
        case 13: {
            Node* evenList = getEvenList(head);
            cout << "Danh sach cac phan tu chan: ";
            displayList(evenList);
            break;
        }
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
