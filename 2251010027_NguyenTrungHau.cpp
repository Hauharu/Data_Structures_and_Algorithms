#include <iostream>
#include <stack>

using namespace std; // Sử dụng không gian tên std

// Hàm chuyển đổi số nguyên thành số đảo ngược thứ tự các chữ số
int DaoNguocSo(int number) {
    stack<int> digitStack;

    // Đưa từng chữ số của số vào ngăn xếp
    while (number > 0) {
        int digit = number % 10;
        digitStack.push(digit);
        number /= 10;
    }

    int reversedNumber = 0;
    int multiplier = 1;

    // Lấy từng chữ số từ ngăn xếp để tạo số đảo ngược
    while (!digitStack.empty()) {
        int digit = digitStack.top();
        digitStack.pop();
        reversedNumber += digit * multiplier;
        multiplier *= 10;
    }

    return reversedNumber;
}

int main() {
    int number;
    cout << "Nhap vao mot so nguyen khong am: ";
    cin >> number;

    if (number < 0) {
        cout << "Vui long nhap so khong am." << endl;
        return 1;
    }

    int reversed = DaoNguocSo(number);

    cout << "So dao nguoc: " << reversed << endl;

    return 0;
}
