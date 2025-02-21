#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void maxHeapify(Node* root, int n) {
    int largest = root->data;
    int left = 2 * root->data;
    int right = 2 * root->data + 1;

    if (left < n && root->next != nullptr && largest < root->next->data) {
        largest = root->next->data;
    }

    if (right < n && root->next != nullptr && largest < root->next->next->data) {
        largest = root->next->next->data;
    }

    if (largest != root->data) {
        swap(root, root->next);
        maxHeapify(root->next, n);
    }
}

void buildMaxHeap(Node* root, int n) {
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(root + i, n);
    }
}

void heapSort(Node* head, int n) {
    buildMaxHeap(head, n);

    for (int i = n; i > 1; i--) {
        swap(head, head + i - 1);
        n--;
        maxHeapify(head, n);
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhập số lượng số cần sắp xếp: ";
    cin >> n;

    Node* head = new Node();
    head->data = 0;
    head->next = nullptr;

    for (int i = 1; i <= n; i++) {
        cout << "Nhập số thứ " << i << ": ";
        int data;
        cin >> data;

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        head->next = newNode;
        head = newNode;
    }

    cout << "Danh sách ban đầu: ";
    printList(head);

    heapSort(head, n);

    cout << "Danh sách sau khi sắp xếp: ";
    printList(head);

    // Xóa cấp phát động
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    system("pause");
    return 0;
}
