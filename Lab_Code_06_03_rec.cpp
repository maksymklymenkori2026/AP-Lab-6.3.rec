// Lab 6.3.rec
// Variant 13

#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

double ToDouble(double x)
    { return x; }
double ToDouble(const string s)
    { return stod(s); }

// повертає чи масив впорядкований за НЕзростанням
template <typename T>
T Ordered(T* a, const int n, int i = 0)
{
    if (i >= n - 1)
        return static_cast<T>(true);
    if (ToDouble(a[i]) < ToDouble(a[i + 1]))
        return static_cast<T>(false);
    return Ordered(a, n, i + 1);
}
bool Ordered(int* a, const int n, int i = 0)
{
    if (i >= n - 1)
        return true;
    if (ToDouble(a[i]) < ToDouble(a[i + 1]))
        return false;
    return Ordered(a, n, i + 1);
}

template <typename T>
T Print(T* a, const int n, int i = 0)
{
    if (i >= n) {
        cout << endl << endl;
        return a[0];
    }
    cout << setw(6) << a[i];
    return Print(a, n, i + 1);
}
void Print(int* a, const int n, int i = 0)
{
    if (i >= n) {
        cout << endl << endl;
        return;
    }
    cout << setw(6) << a[i];
    Print(a, n, i + 1);
}

template <typename T>
T Create(T* a, const int n, int i = 0) {
    if (i >= n)
        return a[0];
    a[i] = (i + 1) * 1.1;
    return Create(a, n, i + 1);
}

void Create(int* a, const int n, int i = 0) {
    if (i >= n)
        return;
    a[i] = (i + 1) * 1.1;
    Create(a, n, i + 1);
}

int main()
{
    const int n = 10;
    int a[n];
    double b[n];

    Create(a, n);
    Create(b, n);

    bool r1 = Ordered(a, n);
    cout << "Ordered(a, n) = " << r1 << endl;
    Print(a, n);

    bool r2 = Ordered<int>(a, n);
    cout << "Ordered<int>(a, n) = " << r2 << endl;
    Print(a, n);

    bool r3 = Ordered<double>(b, n);
    cout << "Ordered<double>(b, n) = " << r3 << endl;
    Print(b, n);

    return 0;
}