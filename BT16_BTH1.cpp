#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* first;

public:
    LinkedList() {
        first = nullptr;
    }

    void addElement(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = first;
        first = newNode;
    }

    LinkedList* getUnion(LinkedList* list1, LinkedList* list2) {
        LinkedList* unionList = new LinkedList();

        Node* current = list1->first;
        while (current != nullptr) {
            unionList->addElement(current->value);
            current = current->next;
        }

        current = list2->first;
        while (current != nullptr) {
            if (!unionList->search(current->value)) {
                unionList->addElement(current->value);
            }
            current = current->next;
        }

        return unionList;
    }

    LinkedList* getIntersection(LinkedList* list1, LinkedList* list2) {
        LinkedList* intersectionList = new LinkedList();

        Node* current = list1->first;
        while (current != nullptr) {
            if (list2->search(current->value)) {
                intersectionList->addElement(current->value);
            }
            current = current->next;
        }

        return intersectionList;
    }

    LinkedList* getComplement(LinkedList* list1, LinkedList* list2) {
        LinkedList* complementList = new LinkedList();

        Node* current = list1->first;
        while (current != nullptr) {
            if (!list2->search(current->value)) {
                complementList->addElement(current->value);
            }
            current = current->next;
        }

        return complementList;
    }

    bool search(int value) {
        Node* current = first;
        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printList() {
        Node* current = first;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

LinkedList* inputList() {
    LinkedList* list = new LinkedList();
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
        cin >> value;
        list->addElement(value);
    }
    return list;
}

int main() {
    LinkedList* list1 = inputList();
    LinkedList* list2 = inputList();

    LinkedList* unionList = list1->getUnion(list1, list2);
    cout << "Tap hop la hop cua hai danh sach:" << endl;
    unionList->printList();

    LinkedList* intersectionList = list1->getIntersection(list1, list2);
    cout << "Tap hop giao cua hai danh sach:" << endl;
    intersectionList->printList();

    LinkedList* complementList = list1->getComplement(list1, list2);
    cout << "Tap hop bu cua hai danh sach:" << endl;
    complementList->printList();

    delete list1;
    delete list2;
    delete unionList;
    delete intersectionList;
    delete complementList;

    return 0;
}
