#include <iostream>
#include <conio.h>
struct Node {
    int info;
    Node* left;
    Node* right;
};

// 1.2. Viết thủ tục khởi tạo cây rỗng.
Node* createEmptyTree() {
    return NULL;
}

// 1.3. Viết thủ tục thêm một phần tử vào cây (dùng đệ quy).
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->info = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->info) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->info) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// 1.4. Viết thủ tục tìm một phần tử trong cây (dùng đệ quy).
bool searchElement(Node* root, int data) {
    if (root == NULL) {
        return false;
    }

    if (data == root->info) {
        return true;
    }
    else if (data < root->info) {
        return searchElement(root->left, data);
    }
    else {
        return searchElement(root->right, data);
    }
}

// 1.5. Viết thủ tục xóa một node trong cây (dùng đệ quy).
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->info) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->info) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* minValueNode = root->right;
        while (minValueNode->left != NULL) {
            minValueNode = minValueNode->left;
        }

        root->info = minValueNode->info;
        root->right = deleteNode(root->right, minValueNode->info);
    }

    return root;
}

// 1.6. Viết thủ tục duyệt cây theo thứ tự NLR (dùng đệ quy)
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        std::cout << root->info << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// 1.7. Viết thủ tục duyệt cây theo thứ tự LNR (dùng đệ quy)
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        std::cout << root->info << " ";
        inOrderTraversal(root->right);
    }
}

// 1.8. Viết thủ tục duyệt cây theo thứ tự LRN (dùng đệ quy)
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->info << " ";
    }
}

// 1.9 Viết thủ tục đếm số phần tử trong cây.
int countElements(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countElements(root->left) + countElements(root->right);
}

// 1.10 Viết thủ tục tính trung bình cộng các phần tử trong cây.
float calculateAverage(Node* root) {
    int sum = 0;
    int count = countElements(root);

    if (count == 0) {
        return 0;
    }

    if (root != NULL) {
        sum += root->info + calculateAverage(root->left) + calculateAverage(root->right);
    }

    return (float)sum / count;
}

// 1.11 Viết thủ tục tìm giá trị lớn nhất trong cây.
int findMaxValue(Node* root) {
    if (root == NULL) {
        return INT_MIN;
    }

    int maxLeft = findMaxValue(root->left);
    int maxRight = findMaxValue(root->right);

    int maxValue = std::max(root->info, std::max(maxLeft, maxRight));
    return maxValue;
}

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// 1.12 Viết thủ tục đếm số phần tử là số nguyên tố trong cây.
int countPrimeNodes(Node* root) 
{
    if (root == NULL) {
        return 0;
    }

    int count = isPrime(root->info) ? 1 : 0;
    count += countPrimeNodes(root->left) + countPrimeNodes(root->right);

    return count;
}

// 1.13 Viết thủ tục đếm số node bậc 2 trong cây.
int countBinaryNodes(Node* root) 
{
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }

    int count = (root->left != NULL && root->right != NULL) ? 1 : 0;
    count += countBinaryNodes(root->left) + countBinaryNodes(root->right);

    return count;
}

// 1.14 Viết thủ tục xuất các node lá mức 2 trong cây.
void printLevel2LeafNodes(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 2 && root->left == NULL && root->right == NULL) {
        std::cout << root->info << " ";
    }
    else if (level > 2) {
        printLevel2LeafNodes(root->left, level - 1);
        printLevel2LeafNodes(root->right, level - 1);
    }
}

// Helper function to calculate the distance between two nodes
int calculateNodeDistance(Node* root, int a, int b, int dist) {
    if (root == NULL) {
        return 0;
    }

    int left = calculateNodeDistance(root->left, a, b, dist);
    int right = calculateNodeDistance(root->right, a, b, dist);

    if ((root->info == a || root->info == b) && (left != 0 || right != 0)) {
        dist = left + right;
    }

    if (left != 0 && right != 0) {
        return dist;
    }
    else if (root->info == a || root->info == b) {
        return 1;
    }
    else if (left != 0) {
        return left + 1;
    }
    else if (right != 0) {
        return right + 1;
    }

    return 0;
}

// 1.15 Viết thủ tục đếm cạnh đường đi từ node a đến node b (do người dùng nhập) trong cây.
int countPathEdges(Node* root, int a, int b) {
    int dist = calculateNodeDistance(root, a, b, 0);

    if (dist != 0) {
        return dist - 1;
    }

    return 0;
}

// Helper function to free the memory used by the tree
void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* tree = createEmptyTree();
    int choice, data;
    do {
        system("cls");
        std::cout << "\n-----------------------------";
        std::cout << "\nCHUONG TRINH QUAN LY CAY NHI PHAN";
        std::cout << "\n1. Them phan tu vao cay";
        std::cout << "\n2. Tim phan tu trong cay";
        std::cout << "\n3. Xoa phan tu trong cay";
        std::cout << "\n4. Duyet cay theo thu tu NLR";
        std::cout << "\n5. Duyet cay theo thu tu LNR";
        std::cout << "\n6. Duyet cay theo thu tu LRN";
        std::cout << "\n7. Dem so phan tu trong cay";
        std::cout << "\n8. Tinh trung binh cong cac phan tu";
        std::cout << "\n9. Tim gia tri lon nhat trong cay";
        std::cout << "\n10. Dem so phan tu la so nguyen to trong cay";
        std::cout << "\n11. Dem so node bac 2 trong cay";
        std::cout << "\n12. Xuat cac node la muc 2 trong cay";
        std::cout << "\n13. Dem canh duong di tu node a den node b";
        std::cout << "\n\n0. Thoat";
        std::cout << "\n-----------------------------";
        std::cout << "\nNhap lua chon cua ban: ";
        std::cin >> choice;

        switch (choice) {
        case 0:
            std::cout << "Ket thuc chuong trinh!";
            deleteTree(tree);
            break;
        case 1:
            std::cout << "Nhap gia tri can them: ";
            std::cin >> data;
            tree = insertNode(tree, data);
            std::cout << "Cay sau khi them: ";
            inOrderTraversal(tree);
            break;
        case 2:
            std::cout << "Nhap gia tri can tim: ";
            std::cin >> data;
            if (searchElement(tree, data)) {
                std::cout << "Phan tu " << data << " co trong cay!\n";
            }
            else {
                std::cout << "Phan tu " << data << " khong co trong cay!\n";
            }
            break;
        case 3:
            std::cout << "Nhap gia tri can xoa: ";
            std::cin >> data;
            tree = deleteNode(tree, data);
            std::cout << "Cay sau khi xoa: ";
            inOrderTraversal(tree);
            break;
        case 4:
            std::cout << "Duyet cay theo thu tu NLR: ";
            preOrderTraversal(tree);
            break;
        case 5:
            std::cout << "Duyet cay theo thu tu LNR: ";
            inOrderTraversal(tree);
            break;
        case 6:
            std::cout << "Duyet cay theo thu tu LRN: ";
            postOrderTraversal(tree);
            break;
        case 7:
            std::cout << "So phan tu trong cay: " << countElements(tree) << std::endl;
            break;
        case 8:
            std::cout << "Trung binh cong cua cac phan tu trong cay: " << calculateAverage(tree) << std::endl;
            break;
        case 9:
            std::cout << "Gia tri lon nhat trong cay: " << findMaxValue(tree) << std::endl;
            break;
        case 10:
            std::cout << "So phan tu la so nguyen to trong cay: " << countPrimeNodes(tree) << std::endl;
            break;
        case 11:
            std::cout << "So node bac 2 trong cay: " << countBinaryNodes(tree) << std::endl;
            break;
        case 12:
            std::cout << "Cac node la muc 2 trong cay: ";
            printLevel2LeafNodes(tree, 2);
            std::cout << std::endl;
            break;
        case 13:
            int a, b;
            std::cout << "Nhap gia tri node a: ";
            std::cin >> a;
            std::cout << "Nhap gia tri node b: ";
            std::cin >> b;
            std::cout << "So canh duong di tu node " << a << " den node " << b << ": " << countPathEdges(tree, a, b) << std::endl;
            break;
        default:
            std::cout << "Lua chon khong hop le!";
            break;
        }
        _getch();
    } while (choice != 0);

    return 0;
}
