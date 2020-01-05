#include <iostream>
using namespace std;
class Complex
{
public:
    Complex();
    Complex(double real, double imag);

public:
    void display() const;
    friend Complex operator+(const Complex &A, const Complex &B);
    friend Complex operator-(const Complex &A, const Complex &B);
    friend Complex operator*(const Complex &A, const Complex &B);
    friend Complex operator/(const Complex &A, const Complex &B);
    friend bool operator==(const Complex &A, const Complex &B);
    friend bool operator!=(const Complex &A, const Complex &B);
    Complex &operator+=(const Complex &C);
    Complex &operator-=(const Complex &C);
    Complex &operator*=(const Complex &C);
    Complex &operator/=(const Complex &C);

private:
    double m_real;
    double m_imag;
};

Complex::Complex() : m_real(0.0), m_imag(0.0) {}
Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}
void Complex::display() const
{
    cout << m_real << " + " << m_imag << "i" << endl;
}
Complex operator+(const Complex &A, const Complex &B)
{
    Complex C;
    C.m_real = A.m_real + B.m_real;
    C.m_imag = A.m_imag + B.m_imag;
    return C;
}
Complex operator-(const Complex &A, const Complex &B)
{
    Complex C;
    C.m_real = A.m_real - B.m_real;
    C.m_imag = A.m_imag - B.m_imag;
    return C;
}
Complex operator*(const Complex &A, const Complex &B)
{
    Complex C;
    C.m_real = A.m_real * B.m_real;
    C.m_imag = A.m_imag * B.m_imag;
    return C;
}
Complex operator/(const Complex &A, const Complex &B)
{
    Complex C;
    C.m_real = A.m_real / B.m_real;
    C.m_imag = A.m_imag / B.m_imag;
    return C;
}
bool operator==(const Complex &A, const Complex &B)
{
    if (A.m_real == B.m_real && A.m_imag == B.m_imag)
    {
        return true;
    }
    return false;
}
bool operator!=(const Complex &A, const Complex &B)
{
    if (A.m_real == B.m_real && A.m_imag == B.m_imag)
    {
        return false;
    }
    return true;
}

template <typename T>
void Swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    Complex c1(4.3, 5.9);
    Complex c2(2.4, 3.7);
    Complex c3;
    c3 = c1 + c2;
    c3.display();
    c3 = c1 * c2;
    c3.display();

    int n1 = 100, n2 = 200;
    Swap(&n1, &n2);
    cout << "after swap:" << n1 << ", " << n2 << endl;
    return 0;
}