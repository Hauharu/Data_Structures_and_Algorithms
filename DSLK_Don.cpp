/*
Bài 4: Quản lý một danh sách có số phần tử khá lớn, biến động. Mỗi phần tử có kiểu int. (Dùng
cấu trúc Danh sách liên kết đơn)
a. Khai báo cấu trúc danh sách.
b. Viết thủ tục khởi tạo danh sách rỗng.
c. Viết thủ tục xuất các phần tử trong danh sách.
d. Viết thủ tục tìm một phần tử trong danh sách.
e. Viết thủ tục thêm một phần tử vào đầu danh sách.
f. Viết thủ tục xoá phần tử đầu danh sách.
g. Viết thủ tục thêm một phần tử vào cuối danh sách.
h. Viết thủ tục xoá phần tử cuối danh sách.
i. Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, hãy xoá phần tử này.
j. Từ danh sách trên chuyển thành danh sách có thứ tự. (*)
   Sap xep tang dan cac phan tu trong danh sach
   Huy con tro first
*/
#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;

// khai bao cau truc danh sach	
struct Node
{
	int info;
	Node* next;
};

Node* first;

void khoi_Tao();
void xuat();
Node* tim(int x);
void them_Dau(int x);
void them_Cuoi(int x);
int xoa_Dau();
int xoa_Cuoi();
void tim_Xoa(int x);
void huy_DS();
void sx_Tang();
int main()
{
	int chon, x;
	bool in = false;
	do
	{
		system("cls");
		cout << "Menu co ban cua danh sach lien ket don\n"
			<< "1. Khoi tao danh sach\n"
			<< "2. Xuat danh sach\n"
			<< "3. Tim mot phan tu trong danh sach\n"
			<< "4. Them mot phan tu vao dau danh sach\n"
			<< "5. Them mot phan tu vao cuoi danh sach\n"
			<< "6. Xoa mot phan tu dau danh sach\n"
			<< "7. Xoa mot phan tu cuoi danh sach\n"
			<< "8. Tim mot phan tu va xoa no trong danh sach\n"
			<< "9. Sap xep tang cac phan tu trong danh sach\n"
			<< "10. Chon 0 de thoat chuong trinh\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			khoi_Tao();
			cout << "Da khoi tao mang rong thanh cong\n";
			break;
		case 2:
			if (in)
			{
				cout << "Danh sach dang luu tru:\n";
				xuat();
			}
			else
				cout << "Mang dang rong chua duoc nhap\n";
			break;
		case 3:
			if (in)
			{
				cout << "Nhap phan tu can tim: ";
				cin >> x;
				tim(x);
			}
			else
				cout << "Mang dang rong chua duoc nhap\n";
			break;
		case 4:
			cout << "Nhap phan tu can them dau cho danh sach: ";
			cin >> x;
			them_Dau(x);
			in = true;
			break;
		case 5:
			cout << "Nhap phan tu can them cuoi cho danh sach: ";
			cin >> x;
			them_Cuoi(x);
			in = true;
			break;
		case 6:
			if (xoa_Dau() == 1)
				cout << "Da xoa phan tu dau danh sach ";
			else if (xoa_Dau() == 0)
				cout << "Mang dang rong chua duoc nhap\n";
			break;
		case 7:
			if (xoa_Cuoi() == 1)
				cout << "Da xoa phan tu cuoi danh sach ";
			else if (xoa_Cuoi() == 0)
				cout << "Mang dang rong chua duoc nhap\n";
			break;
		case 9:
			if (in)
			{
				cout << "Da sap xep tang dan cac phan tu trong danh sach\n";
				sx_Tang();
			}
			else
				cout << "Mang dang rong chua duoc nhap\n";
			break;
		case 0:
			huy_DS();
			cout << "Thoat chuong trinh\n";
			return 0;
		}
		_getch();
	} while (true);
	return 0;
}

// khoi tao danh sach rong
void khoi_Tao()
{
	first = NULL;
}

// xuat danh sach
void xuat()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
}

// tim mot phan tu trong danh sach
Node* tim(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p->next;
	}
	return p;
}

// them dau danh sach
void them_Dau(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->next = first;
	first = p;
}

// them cuoi danh sach
void them_Cuoi(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->next = NULL;
	if (first == NULL) //không có phần tử cuối cùng
		first = p;
	else
	{
		Node* q = first;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

// xoa dau danh sach
int xoa_Dau()
{
	if (first != NULL) // danh sách khác rỗng
	{
		Node* p = first;
		first = first->next;
		delete p;
		return 1;
	}
	return 0;
}

// xoa cuoi danh sach
int xoa_Cuoi()
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first; q = NULL;
		if (p != NULL)
			while (p->next != NULL)
			{
				q = p; p = p->next;
			}
		if (p != first) // p là đầu thì không tồn tại q;
			q->next = NULL;
		else first = NULL;
		delete p;
		return 1;
	}return 0;
}

// tim mot phan tu va xoa no 
void tim_Xoa(int x);

// sap xep tang danh sach
void sx_Tang()
{
	Node* p = first;
	while (p->next != NULL)
	{
		Node* q = p->next;
		while (q != NULL)
		{
			if (q->info < p->info)
				swap(q->info, p->info);
			q = q->next;
		}
		p = p->next;
	}
}

// huy vung lien ket
void huy_DS()
{
	while (first != NULL)
		delete first;
}


/*
Bài 5: Quản lý một danh sách có thứ tự có số phần tử khá lớn, biến động. Mỗi phần tử có kiểu
int. (danh sách liên kết đơn)
a. Khai báo cấu trúc danh sách như bài 4
b. Viết thủ tục khởi tạo danh sách rỗng như bài 4
c. Viết thủ tục thêm một phần tử vào danh sách
d. Viết thủ tục xuất các phần tử trong danh sách như bài 4
e. Viết thủ tục tìm một phần tử trong danh sách. như bài 4
f. Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, xoá một phần tử này.
   Sap xep tang cac phan tu trong danh sach
*/
