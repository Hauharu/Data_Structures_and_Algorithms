#include <iostream>
#include <stack>

using namespace std;

void decToBin(int decimal) {
    stack<int> binaryStack;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binaryStack.push(remainder);
        decimal /= 2;
    }

    cout << "Hệ nhị phân: ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }
}

int main() {
    int decimal;
    cout << "Nhap so thap phan: ";
    cin >> decimal;
    decToBin(decimal);

    return 0;
}
