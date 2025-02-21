#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;

struct Node {
    int key;
    int next;
};

struct hashTable {
    Node heads[MAX];
    int r;
};

void init(hashTable& ht) {
    for (int i = 0; i < MAX; i++)
        ht.heads[i].key = ht.heads[i].next = -1;
    ht.r = MAX - 1;
}

int hashFunc(int x) {
    return x % 5;
}

bool insert(hashTable& ht, int x) {
    if (ht.r >= 0) {
        int index = hashFunc(x);
        if (ht.heads[index].key == -1)
            ht.heads[index].key = x;
        else {
            ht.heads[ht.r].key = x;
            while (ht.heads[index].next != -1)
                index = ht.heads[index].next;
            ht.heads[index].next = ht.r;
        }
        while (ht.r >= 0 && ht.heads[ht.r].key >= 0)
            ht.r--;
        return true;
    }
    return false;
}

void insertFile(hashTable& ht) {
    ifstream file("baitap.txt");
    if (file.is_open()) {
        int n, x;
        file >> n;
        for (int i = 0; i < n; i++) {
            file >> x;
            insert(ht, x);
        }
        file.close();
        cout << endl << "Doc file thanh cong" << endl;
    }
    else {
        cout << "Mo file khong thanh cong" << endl;
    }
}

int search(hashTable ht, int x) {
    int index = hashFunc(x);
    do {
        if (ht.heads[index].key == x)
            return index;
        index = ht.heads[index].next;
    } while (index >= 0);
    return -1;
}

int count(hashTable ht) {
    int count = 0;
    for (int i = 0; i < MAX; i++) {
        if (ht.heads[i].key != -1)
            count++;
    }
    return count;
}

void deleteNode(hashTable& ht, int x) {
    int index = hashFunc(x);
    int parent;
    while (ht.heads[index].key != x) {
        parent = index;
        index = ht.heads[index].next;
    }
    if (ht.heads[index].next != -1) {
        while (ht.heads[index].next != -1) {
            parent = index;
            int x = ht.heads[index].next;
            ht.heads[index].key = ht.heads[x].key;
            index = ht.heads[index].next;
        }
    }
    if (ht.heads[index].next == -1) {
        ht.heads[index].key = -1;
        ht.heads[parent].next = -1;
    }
    ht.r = index;
}

void show(hashTable ht) {
    for (int i = 0; i < MAX; i++) {
        if (ht.heads[i].key >= 0)
            cout << i << " ---> " << ht.heads[i].key << " : " << ht.heads[i].next << endl;
    }
}

int main() {
    hashTable ht;
    int chon;
    bool ktao;
    int x;
    do {
        system("cls");
        cout << "1. Khoi tao bang bam\n"
            << "2. Them phan tu\n"
            << "3. Them phan tu tu file\n"
            << "4. Tim kiem\n"
            << "5. Dem so phan tu\n"
            << "6. Xoa phan tu\n"
            << "7. Xuat bang\n"
            << "8. Thoat\n"
            << "Nhap yeu cau cua ban: ";
        cin >> chon;
        switch (chon) {
        case 1:
            init(ht);
            ktao = true;
            cout << "Khoi tao thanh cong" << endl;
            break;
        case 2:
            if (ktao) {
                cout << "Nhap phan tu can them: ";
                cin >> x;
                if (insert(ht, x))
                    cout << "Them thanh cong" << endl;
                else
                    cout << "Them khong thanh cong" << endl;
            }
            else {
                cout << "Bang bam chua duoc khoi tao" << endl;
            }
            break;
        case 3:
            if (ktao)
                insertFile(ht);
            else
                cout << "Bang bam chua duoc khoi tao" << endl;
            break;
        case 4:
            if (ktao) {
                cout << "Nhap phan tu can tim: ";
                cin >> x;
                int vt = search(ht, x);
                if (vt != -1)
                    cout << "Phan tu " << x << " tai vi tri " << vt << endl;
                else
                    cout << "Phan tu " << x << " khong co trong bang" << endl;
            }
            else {
                cout << "Bang bam chua duoc khoi tao" << endl;
            }
            break;
        case 5:
            if (ktao)
                cout << "So phan tu trong bang la: " << count(ht) << endl;
            else
                cout << "Bang bam chua duoc khoi tao" << endl;
            break;
        case 6:
            if (ktao) {
                cout << "Nhap phan tu can xoa: ";
                cin >> x;
                deleteNode(ht, x);
                cout << "Xoa thanh cong" << endl;
            }
            else {
                cout << "Bang bam chua duoc khoi tao" << endl;
            }
            break;
        case 7:
            if (ktao)
                show(ht);
            else
                cout << "Bang bam chua duoc khoi tao" << endl;
            break;
        default:
            exit(true);
            break;
        }
        system("pause");
    } while (true);
    return 0;
}
