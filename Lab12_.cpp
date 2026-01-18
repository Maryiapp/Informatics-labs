#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

/* TASK 1: Apply Operation Using Function Pointer
   Write a function that takes two doubles and a pointer to a function,
   then applies that function to the two numbers and returns the result.
   The function should work with add, subtract, and multiply functions. */
double apply_operation(double a, double b, double (*op)(const double, const double)) {
    return op(a, b);
}

/* TASK 2: Array of Function Pointers
   Write a function that creates an array of function pointers (add, subtract, multiply)
   and applies all three operations to two given numbers. Store the results in a
   vector and return it. */
std::vector<double> all_operations(double a, double b) {
    std::vector<double> results;

    double (*operations[])(const double, const double) = { add, subtract, multiply };

    for (auto op : operations) {
        results.push_back(op(a, b));
    }

    return results;
}

/* TASK 3: Transform Array Using Function Pointer
   Write a function that takes a pointer to the beginning of an array,
   a pointer past the last element, and a function pointer that transforms
   each double value. Apply the transformation to all elements. */
void transform_array(double* begin, double* past_the_last,
    double (*transform_func)(double)) {
    for (double* p = begin; p != past_the_last; ++p) {
        *p = transform_func(*p);
    }
}

/* TASK 4: Custom Operation with Lambda
   Write a function that takes two integers and performs a custom operation
   using std::function and a lambda. The lambda should calculate:
   (a * b) + (a - b) */
int custom_calc(int a, int b) {
    std::function<int(int, int)> calc = [](int x, int y) {
        return (x * y) + (x - y);
        };

    return calc(a, b);
}

/* TASK 5: Filter Array Using Pointer Arithmetic
   Write a function that takes a pointer to an array of doubles, its size,
   and a threshold value. Count how many elements are greater than the threshold
   using pointer arithmetic (no array indexing with []). */
int count_above_threshold(double* arr, int size, double threshold) {
    int count = 0;

    for (double* p = arr; p != arr + size; ++p) {
        if (*p > threshold) {
            count++;
        }
    }

    return count;
}

/* TASK 6: Typedef for Function Pointer
   Create a typedef for a function pointer that takes two doubles and returns a double.
   Then write a function that accepts this typedef as a parameter and applies it
   to calculate the result of: operation(a, b) * 2 */
typedef double (*operation_func)(const double, const double);
double double_operation(double a, double b, operation_func op) {
    return op(a, b) * 2;
}

/* TASK 7: Find Maximum Using Custom Comparator
   Write a function that finds the maximum value in an array of doubles
   using pointer arithmetic and a comparison function pointer. The comparison
   function should return true if first argument is greater than second. */
double find_max_with_compare(double* arr, int size,
    bool (*compare)(double, double)) {
    double max = *arr;

    for (double* p = arr + 1; p != arr + size; ++p) {
        if (compare(*p, max)) {
            max = *p;
        }
    }

    return max;
}



/* HELPER FUNCTIONS */

double add(const double l, const double p) {
    return l + p;
}

double subtract(const double l, const double p) {
    return l - p;
}

double multiply(const double l, const double p) {
    return l * p;
}

bool greater_than(double a, double b) {
    return a > b;
}



double double_value(double x) {
    return x * 2;
}



// MAIN

int main() {

    // TASK 1
    std::cout << "TASK 1: Apply Operation\n";
    std::cout << apply_operation(10.0, 5.0, add) << std::endl;
    std::cout << apply_operation(10.0, 5.0, subtract) << std::endl;
    std::cout << apply_operation(10.0, 5.0, multiply) << std::endl;

    // TASK 2
    std::cout << "\nTASK 2: All Operations\n";
    std::vector<double> results = all_operations(8.0, 2.0);
    for (double x : results) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // TASK 3
    std::cout << "\nTASK 3: Transform Array\n";
    double arr1[] = { 1.0, 2.0, 3.0 };
    transform_array(arr1, arr1 + 3, double_value);
    for (double x : arr1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // TASK 4
    std::cout << "\nTASK 4: Custom Calculation\n";
    std::cout << custom_calc(5, 3) << std::endl;

    // TASK 5
    std::cout << "\nTASK 5: Count Above Threshold\n";
    double arr2[] = { 1.5, 3.7, 2.1, 4.9 };
    std::cout << count_above_threshold(arr2, 4, 2.5) << std::endl;

    // TASK 6
    std::cout << "\nTASK 6: Double Operation\n";
    std::cout << double_operation(4.0, 6.0, add) << std::endl;

    // TASK 7
    std::cout << "\nTASK 7: Find Maximum\n";
    double arr3[] = { 2.5, 7.1, 3.9, 5.2 };
    std::cout << find_max_with_compare(arr3, 4, greater_than) << std::endl;

    return 0;
}

