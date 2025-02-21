#include<iostream>
using namespace std;

// Khai báo cấu trúc
struct Node
{
    int coefficient;
    int exponent;
    Node* next;
};

typedef Node* Polynomial;

// Tạo node mới
Node* createNode(int coef, int expo)
{
    Node* newNode = new Node;
    newNode->coefficient = coef;
    newNode->exponent = expo;
    newNode->next = NULL;
    return newNode;
}

// Thêm một node vào đuôi danh sách
void addTerm(Polynomial& poly, int coef, int expo)
{
    Node* newNode = createNode(coef, expo);
    if (poly == NULL)
    {
        poly = newNode;
    }
    else
    {
        Node* temp = poly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hủy danh sách liên kết đơn
void deleteList(Polynomial poly)
{
    Node* temp;
    while (poly != NULL)
    {
        temp = poly->next;
        delete poly;
        poly = temp;
    }
}

// Nhập đa thức
void inputPolynomial(Polynomial& poly)
{
    int n;
    cout << "Nhap so luong term trong da thuc: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int coef, expo;
        cout << "Nhap he so cua term thu " << i + 1 << ": ";
        cin >> coef;
        cout << "Nhap so mu cua term thu " << i + 1 << ": ";
        cin >> expo;
        addTerm(poly, coef, expo);
    }
}

// Xuất đa thức
void outputPolynomial(Polynomial poly)
{
    Node* temp = poly;
    while (temp != NULL)
    {
        cout << temp->coefficient << "x^" << temp->exponent;
        if (temp->next != NULL)
        {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Cộng hai đa thức
Polynomial addPolynomials(Polynomial poly1, Polynomial poly2)
{
    Polynomial sum = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exponent > temp2->exponent)
        {
            addTerm(sum, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            addTerm(sum, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
        else
        {
            int coefSum = temp1->coefficient + temp2->coefficient;
            if (coefSum != 0)
            {
                addTerm(sum, coefSum, temp1->exponent);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        addTerm(sum, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        addTerm(sum, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return sum;
}

// Trừ hai đa thức
Polynomial subtractPolynomials(Polynomial poly1, Polynomial poly2)
{
    Polynomial difference = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exponent > temp2->exponent)
        {
            addTerm(difference, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            addTerm(difference, -temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
        else
        {
            int coefDiff = temp1->coefficient - temp2->coefficient;
            if (coefDiff != 0)
            {
                addTerm(difference, coefDiff, temp1->exponent);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        addTerm(difference, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        addTerm(difference, -temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return difference;
}

// Nhân hai đa thức
Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2)
{
    Polynomial product = NULL;
    Node* temp1 = poly1;

    while (temp1 != NULL)
    {
        Node* temp2 = poly2;
        while (temp2 != NULL)
        {
            int coefProduct = temp1->coefficient * temp2->coefficient;
            int expoProduct = temp1->exponent + temp2->exponent;
            addTerm(product, coefProduct, expoProduct);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return product;
}

// Hàm main tạo menu
int main()
{
    Polynomial poly1 = NULL;
    Polynomial poly2 = NULL;
    Polynomial result = NULL;
    char choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Nhap da thuc 1\n";
        cout << "2. Nhap da thuc 2\n";
        cout << "3. Xuat da thuc 1\n";
        cout << "4. Xuat da thuc 2\n";
        cout << "5. Cong hai da thuc\n";
        cout << "6. Tru hai da thuc\n";
        cout << "7. Nhan hai da thuc\n";
        cout << "8. Chia hai da thuc\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            if (poly1 != NULL)
            {
                deleteList(poly1);
            }
            inputPolynomial(poly1);
            break;
        case '2':
            if (poly2 != NULL)
            {
                deleteList(poly2);
            }
            inputPolynomial(poly2);
            break;
        case '3':
            cout << "Da thuc 1: ";
            outputPolynomial(poly1);
            break;
        case '4':
            cout << "Da thuc 2: ";
            outputPolynomial(poly2);
            break;
        case '5':
            result = addPolynomials(poly1, poly2);
            cout << "Tong hai da thuc: ";
            outputPolynomial(result);
            break;
        case '6':
            result = subtractPolynomials(poly1, poly2);
            cout << "Hieu hai da thuc: ";
            outputPolynomial(result);
            break;
        case '7':
            result = multiplyPolynomials(poly1, poly2);
            cout << "Tich hai da thuc: ";
            outputPolynomial(result);
            break;
        case '8':
            // code chia hai đa thức
            break;
        case '0':
            deleteList(poly1);
            deleteList(poly2);
            deleteList(result);
            cout << "Cam on da su dung chuong trinh!";
            break;
        default:
            cout << "Lua chon khong hop le!";
            break;
        }
    } while (choice != '0');

    return 0;
}
