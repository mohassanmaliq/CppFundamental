#include <iostream>
using namespace std;

// Practice 1 - Declaring a pointer
void practice1()
{
    int y = 5;
    int* yPtr;
    yPtr = &y;

    cout << "Value of y                = " << y << endl;
    cout << "Address of y              = " << &y << endl;
    cout << "Value of yPtr             = " << yPtr << endl;
    cout << "Adress of yPtr pointer    = " << &yPtr << endl;

}

// Practice 2 - Using & and *
void practice2()
{
    int y = 5;
    int* yPtr;
    yPtr = &y;

    cout << "Value of y       = " << y << endl;
    cout << "Address of y     = " << &y << endl;
    cout << "Value of yPtr    = " << yPtr << endl;
    cout << "Value at *yPtr   = " << *yPtr << endl;

    *yPtr = 10;

    cout << "\nAfter changing *yPtr:" << endl;
    cout << "New value of y   = " << y << endl;
    cout << "Value at *yPtr   = " << *yPtr << endl;
}

// Practice 3 - Pointer arithmetic
void practice3()
{
    int v[3] = { 10, 100, 200 };
    int* ptr;

    ptr = v;

    for (int i = 0; i < 3; i++)
    {
        cout << "Value at ptr  = " << ptr << "\n";
        cout << "Value at *ptr = " << *ptr << "\n";
        ptr++;
    }
}

// Practice 4 - 2-D array of pointers
void practice4()
{
    int arr1[5][5] = { { 0, 1, 2, 3, 4 },
                       { 2, 3, 4, 5, 6 },
                       { 4, 5, 6, 7, 8 },
                       { 5, 4, 3, 2, 6 },
                       { 2, 5, 4, 3, 1 } };
    int* arr2[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr2[i][j] = &arr1[i][j];
        }
    }

    cout << "The values are\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << *arr2[i][j] << " ";
        }
        cout << "\n";
    }
}

// Practice 5 - Displaying a 2-D array in pointer notation
void practice5()
{
    const int rows = 3, cols = 3;
    int matrix[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

// Practice 8 - Initializing pointers and checking for NULL
void practice8()
{
    int x = 42;
    int arr[3] = { 7, 8, 9 };

    int* p1 = &x;
    int* p2 = arr;
    int* p3 = p1;
    int* p4 = nullptr;
    int* p5 = NULL;

    cout << "*p1 = " << *p1 << ",  *p2 = " << *p2 << ",  *p3 = " << *p3 << endl;
    cout << "p4 = " << p4 << ",  p5 = " << p5 << endl;

    if (p4 != nullptr)
        cout << "*p4 = " << *p4 << endl;
    else
        cout << "p4 is a null pointer - cannot dereference" << endl;

    p4 = &arr[2];
    if (p4 != NULL)
        cout << "Now *p4 = " << *p4 << endl;
}

// Practice 9 - Array of pointers
void practice9()
{
    const int size = 3;
    int var[size] = { 10, 100, 200 };
    int* ptr[size];

    for (int i = 0; i < size; i++) {
        ptr[i] = &var[i];
    }

    for (int i = 0; i < size; i++) {
        cout << "Value of var[" << i << "] = ";
        cout << *ptr[i] << endl;
    }
}

// Practice 10 - Comparing pointers
void practice10()
{
    int a = 5, b = 5;
    int* pa = &a, * pb = &b, * pc = &a;

    cout << "pa == pc  : " << (pa == pc) << endl;
    cout << "pa == pb  : " << (pa == pb) << endl;
    cout << "*pa == *pb: " << (*pa == *pb) << endl;

    int arr[6] = { 3, 6, 9, 12, 15, 18 };
    int* start = arr;
    int* end = arr + 5;

    cout << "Traversal using (start <= end): ";
    for (int* p = start; p <= end; p++)
        cout << *p << " ";
    cout << endl;

    int* left = arr, * right = arr + 5;
    while (left < right)
    {
        cout << "(" << *left << "," << *right << ") ";
        left++;
        right--;
    }
    cout << endl;
}

int main()
{
    cout << "--- Practice 1 ---\n";  practice1();
    cout << "\n--- Practice 2 ---\n"; practice2();
    cout << "\n--- Practice 3 ---\n"; practice3();
    cout << "\n--- Practice 4 ---\n"; practice4();
    cout << "\n--- Practice 5 ---\n"; practice5();
    cout << "\n--- Practice 8 ---\n"; practice8();
    cout << "\n--- Practice 9 ---\n"; practice9();
    cout << "\n--- Practice 10 ---\n"; practice10();
    return 0;
}