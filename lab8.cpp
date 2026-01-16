#include <iostream>
using namespace std;

// TASK 1: Pointer Basics (10 minutes)
void swap_values(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// TASK 2: Pointer Arithmetic (10 minutes)
int find_max(int* array, int size)
{
    int* p = array;
    int max_val = *p;

    for (int i = 1; i < size; ++i)
    {
        if (*(p + i) > max_val)
            max_val = *(p + i);
    }
    return max_val;
}

// TASK 3: Pointer to Pointer (12 minutes)
void redirect_pointer(int** ptr, int* new_target)
{
    *ptr = new_target;
}

// TASK 4: Const Pointers (10 minutes)
void print_value(const int* ptr)
{
    cout << "Value: " << *ptr << endl;
}

void increment_value(int* const ptr)
{
    (*ptr)++;
}

void display_value(const int* const ptr)
{
    cout << "Value: " << *ptr << "\n";
}

// TASK 5: Array Reversal (15 minutes)
void reverse_array(int* array, int size)
{
    int* left = array;
    int* right = array + size - 1;

    while (left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;
        ++left;
        --right;
    }
}

// TASK 6: Pointer Range Functions (12 minutes)
int sum_range(int* begin, int* end)
{
    int sum = 0;
    for (int* p = begin; p < end; ++p)
        sum += *p;

    return sum;
}

// TASK 7: Structure Pointers (12 minutes)
struct Point
{
    double x, y;
};

void move_point(Point* p, double dx, double dy)
{
    p->x += dx;
    p->y += dy;
}

void print_point(const Point* p)
{
    cout << "(" << p->x << ", " << p->y << ")\n";
}

// TASK 8: Multiple Output Parameters (15 minutes)
void analyze_array(int* array, int size,
    int* min, int* max,
    int* sum, double* avg)
{
    *min = array[0];
    *max = array[0];
    *sum = 0;

    for (int i = 0; i < size; ++i)
    {
        int val = array[i];
        if (val < *min) *min = val;
        if (val > *max) *max = val;
        *sum += val;
    }
    *avg = static_cast<double>(*sum) / size;
}






int main()
{
    // TASK 1
    {
        cout << "TASK 1: Swap Values\n";
        int a = 5, b = 10;
        cout << "Before: a = " << a << ", b = " << b << "\n";
        swap_values(&a, &b);
        cout << "After:  a = " << a << ", b = " << b << "\n\n";
    }

    // TASK 2
    {
        cout << "TASK 2: Find Maximum\n";
        int arr[] = { 3, 7, 2, 9, 1, 5 };
        int max = find_max(arr, 6);
        cout << "Maximum: " << max << "\n\n";
    }

    // TASK 3
    {
        cout << "TASK 3: Redirect Pointer\n";
        int a = 10, b = 20;
        int* p = &a;
        cout << "Before: *p = " << *p << "\n";
        redirect_pointer(&p, &b);
        cout << "After:  *p = " << *p << "\n\n";
    }

    // TASK 4
    {
        cout << "TASK 4: Const Pointers\n";
        int value = 42;
        print_value(&value);
        increment_value(&value);
        display_value(&value);
        cout << "\n";
    }

    // TASK 5
    {
        cout << "TASK 5: Reverse Array\n";
        int arr[] = { 1, 2, 3, 4, 5 };
        reverse_array(arr, 5);

        cout << "After: ";
        for (int v : arr)
            cout << v << " ";
        cout << "\n\n";
    }

    // TASK 6
    {
        cout << "TASK 6: Sum Range\n";
        int arr[] = { 10, 20, 30, 40, 50 };
        int sum = sum_range(arr, arr + 5);
        cout << "Sum: " << sum << "\n\n";
    }

    // TASK 7
    {
        cout << "TASK 7: Point Structure\n";
        Point p = { 3.0, 4.0 };
        print_point(&p);
        move_point(&p, 2.5, -1.5);
        print_point(&p);
        cout << "\n";
    }

    // TASK 8
    {
        cout << "TASK 8: Analyze Array\n";
        int arr[] = { 5, 2, 8, 1, 9, 3 };
        int min, max, sum;
        double avg;
        analyze_array(arr, 6, &min, &max, &sum, &avg);

        cout << "Minimum: " << min << "\n";
        cout << "Maximum: " << max << "\n";
        cout << "Sum: " << sum << "\n";
        cout << "Average: " << avg << "\n\n";
    }

    return 0;
}

