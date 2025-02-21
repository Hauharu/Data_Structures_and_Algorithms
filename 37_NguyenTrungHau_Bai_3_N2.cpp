/*
Bài 3: Viết chương trình c++, sử dụng giải thuật đệ quy để viết hàm
ThongBao in ra yêu cầu như sau: (với n được nhập từ bàn phím).
*/
#include <iostream>
using namespace std;
void deQuy_37_NguyenTrungHau_Bai_3_N2(int n)
{
    if (n == 0) {
        cout << endl;
    }
    else {
        cout << "Hom nay toi di hoc CSDLGT buoi 1 "<< endl;
        deQuy_37_NguyenTrungHau_Bai_3_N2(n - 1);
    }
}
int main()
{
	int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
        if (n == 0)
            cout << "Vui long nhap lai!!" << endl;
    } while (n == 0);
	deQuy_37_NguyenTrungHau_Bai_3_N2(n);
	cout << endl;
	return 0;
}
