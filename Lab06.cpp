#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;

// TASK 1: constexpr Factorial Function
constexpr long long factorial(const int n)
{
    if (n == 0 || n == 1)
        return 1;

    long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;

    return result;
}



// TASK 2: consteval Prime Checker
constexpr bool is_prime(const int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}



// TASK 3: Static Sum Accumulator with Query
int& total_storage()
{
    static int total = 0;
    return total;
}

void accumulate(const int value)
{
    total_storage() += value;
}

int get_total()
{
    return total_storage();
}



// TASK 4: Function with Multiple Default Parameters for Formatting
void format_price(const double price,
    const string currency = "USD",
    const bool show_symbol = true,
    const int decimal_places = 2)
{
    string symbol;

    if (currency == "USD") symbol = "$";
    else if (currency == "EUR") symbol = "€";
    else if (currency == "GBP") symbol = "£";
    else if (currency == "JPY") symbol = "¥";

    cout << fixed << setprecision(decimal_places);

    if (show_symbol)
        cout << symbol << price << "\n";
    else
        cout << price << " " << currency << "\n";
}



// TASK 5: Array Sorting and Median
void sort_array(int array[], const int length)
{
    for (int i = 0; i < length - 1; ++i)
    {
        for (int j = 0; j < length - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
}
double find_median(const int array[], const int length)
{
    if (length % 2 != 0)
        return array[length / 2];
    else
        return (array[length / 2 - 1] + array[length / 2]) / 2.0;
}
void print_array(const int array[], const int length)
{
    for (int i = 0; i < length; ++i)
        cout << array[i] << " ";
    cout << "\n";
}



// TASK 6:Vector Filtering and Transformation
void keep_evens(vector<int>& vec)
{
    vector<int> result;
    for (int x : vec)
        if (x % 2 == 0)
            result.push_back(x);

    vec = result;
}
void multiply_by(vector<int>& vec, const int multiplier)
{
    for (int& x : vec)
        x *= multiplier;
}
int product_of_elements(const vector<int>& vec)
{
    int product = 1;
    for (int x : vec)
        product *= x;
    return product;
}



// TASK 7: String Vector Search and Count
int count_starting_with(const vector<string>& vec, const char letter)
{
    int count = 0;
    char target = tolower(letter);

    for (const auto& s : vec)
    {
        if (!s.empty() && tolower(s[0]) == target)
            ++count;
    }
    return count;
}

vector<string> filter_by_length(const vector<string>& vec,
    const int min_length)
{
    vector<string> result;
    for (const auto& s : vec)
        if ((int)s.length() >= min_length)
            result.push_back(s);
    return result;
}

void print_with_length(const vector<string>& vec)
{
    for (const auto& s : vec)
        cout << s << " (" << s.length() << " chars)\n";
}



// TASK 8: Grade Management System
struct Student
{
    string name;
    vector<double> grades;
};
void add_grade(Student& student, const double grade)
{
    student.grades.push_back(grade);
}
double calculate_gpa(const Student& student)
{
    double sum = 0.0;
    for (double g : student.grades)
        sum += g;
    return sum / student.grades.size();
}
char get_letter_grade(const double gpa)
{
    if (gpa >= 90) return 'A';
    if (gpa >= 80) return 'B';
    if (gpa >= 70) return 'C';
    if (gpa >= 60) return 'D';
    return 'F';
}
void print_student_report(const Student& student)
{
    cout << "Student: " << student.name << "\nGrades: ";
    for (double g : student.grades)
        cout << g << " ";

    double gpa = calculate_gpa(student);
    cout << "\nGPA: " << gpa
        << "\nLetter grade: " << get_letter_grade(gpa) << "\n\n";
}




// MAIN

int main()
{
    // TASK 1
    constexpr int size = factorial(6);
    int arr[size];
    cout << "Array size determined at compile-time: " << size << "\n\n";

    // TASK 2
    if constexpr (is_prime(97))
        cout << "97 is prime\n\n";

    // TASK 3
    accumulate(10);
    accumulate(25);
    cout << "Total: " << get_total() << "\n";
    accumulate(-5);
    cout << "Total after update: " << get_total() << "\n\n";

    // TASK 4
    format_price(49.99);
    format_price(29.50, "EUR");
    format_price(99.95, "GBP", false);
    format_price(1234.5, "JPY", true, 0);
    cout << "\n";

    // TASK 5
    int nums[] = { 45, 23, 67, 12, 89, 34, 56 };
    int len = 7;
    print_array(nums, len);
    sort_array(nums, len);
    print_array(nums, len);
    cout << "Median: " << find_median(nums, len) << "\n\n";

    // TASK 6
    vector<int> v = { 3, 8, 15, 22, 9, 16, 5 };
    keep_evens(v);
    multiply_by(v, 3);
    cout << "Product: " << product_of_elements(v) << "\n\n";

    // TASK 7
    vector<string> words =
    { "apple", "Banana", "apricot", "Cherry", "avocado", "blueberry" };
    cout << "Starts with A: "
        << count_starting_with(words, 'a') << "\n";
    print_with_length(filter_by_length(words, 6));
    cout << "\n";

    // TASK 8
    Student s{ "Alice" };
    add_grade(s, 95);
    add_grade(s, 88);
    add_grade(s, 92);
    print_student_report(s);

    return 0;
}
