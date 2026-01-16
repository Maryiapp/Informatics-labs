#include <iostream>
#include <string>
#include <vector>
using namespace std;

// task 1
constexpr long int power(const int base, const int exponent)
{
    long int result = 1;
    for (int i = 0; i < exponent; ++i)
        result *= base;
    return result;
}

constexpr int arr_size = power(2, 4);
int test_array[arr_size];



// task 2
constexpr long int fibonacci(const int n)
{
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}



// task 3
static int count_value = 0;
int counter()
{
    return ++count_value;
}

void reset_counter()
{
    count_value = 0;
}


// task 4
void print_grade(const string name, const int score,
    const string course = "Programming",
    const string semester = "Fall 2025")
{
    cout << name << " scored " << score
        << " in " << course << " (" << semester << ")" << endl;
}



// task 5
double find_max(const double array[], const int length)
{
    double max = array[0];
    for (int i = 1; i < length; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
double find_min(const double array[], const int length)
{
    double min = array[0];
    for (int i = 1; i < length; i++)
        if (array[i] < min)
            min = array[i];
    return min;
}
double calculate_average(const double array[], const int length)
{
    double sum = 0;
    for (int i = 0; i < length; i++)
        sum += array[i];
    return sum / length;
}




// task 6
void remove_negatives(vector<int>& vec)
{
    vector<int> out;
    for (int n : vec)
        if (n >= 0) out.push_back(n);
    vec = out;
}
int sum_elements(const vector<int>& vec)
{
    int sum = 0;
    for (int n : vec)
        sum += n;
    return sum;
}




// task 7
void print_strings(const vector<string>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        cout << i << ": " << vec[i] << endl;
}
string find_longest(const vector<string>& vec)
{
    string longest = vec[0];
    for (const string& s : vec)
        if (s.size() > longest.size())
            longest = s;
    return longest;
}


// task 8
void add_temperature(vector<double>& temps, double temp)
{
    temps.push_back(temp);
}
void print_statistics(const vector<double>& temps)
{
    double max = temps[0];
    double min = temps[0];
    double sum = 0;
    for (double t : temps)
    {
        if (t > max) max = t;
        if (t < min) min = t;
        sum += t;
    }
    cout << "Number of readings: " << temps.size() << endl;
    cout << "Highest temperature: " << max << endl;
    cout << "Lowest temperature : " << min << endl;
    cout << "Average temperature: " << sum / temps.size() << endl;






}
int main()
{

    cout << "TASK 1\n";
    cout << "power(2, 10) = " << power(2, 10) << endl;
    cout << "power(5, 3)  = " << power(5, 3) << endl;
    cout << "power(3, 0)  = " << power(3, 0) << endl << endl;


    cout << "TASK 2\n";
    cout << "fibonacci(0)  = " << fibonacci(0) << endl;
    cout << "fibonacci(10) = " << fibonacci(10) << endl;
    cout << "fibonacci(15) = " << fibonacci(15) << endl;
    cout << endl;


    cout << "TASK 3\n";
    for (int i = 0; i < 5; i++) cout << counter() << " ";
    cout << endl;
    cout << "Resetting counter\n";
    reset_counter();
    for (int i = 0; i < 3; i++) cout << counter() << " ";
    cout << endl << endl;


    cout << "TASK 4\n";
    print_grade("Alice", 95, "Math", "Spring 2025");
    print_grade("Bob", 88);
    print_grade("Charlie", 92, "Physics");
    cout << endl;


    cout << "TASK 5\n";
    double arr[] = { 23.5, 67.8, 12.3, 89.1, 45.6, 34.2 };
    int len = 6;
    cout << "Max:     " << find_max(arr, len) << endl;
    cout << "Min:     " << find_min(arr, len) << endl;
    cout << "Average: " << calculate_average(arr, len) << endl << endl;



    cout << "TASK 6\n";
    vector<int> nums = { 10, -5, 20, -15, 30, -25, 40 };
    cout << "Original vector: ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    cout << "Sum before removal: " << sum_elements(nums) << endl;
    remove_negatives(nums);
    cout << "Vector after removing negatives: ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    cout << "Sum after removal: " << sum_elements(nums) << endl << endl;


    cout << "TASK 7\n";
    vector<string> langs = { "C++", "Python", "JavaScript", "Go", "Rust", "Assembly" };
    print_strings(langs);
    cout << "Longest string: " << find_longest(langs) << endl << endl;


    cout << "TASK 8\n";
    vector<double> temps;
    add_temperature(temps, 20.5);
    add_temperature(temps, 22.3);
    add_temperature(temps, 19.8);
    add_temperature(temps, 23.1);
    add_temperature(temps, 21.7);
    add_temperature(temps, 18.9);
    add_temperature(temps, 24.2);
    print_statistics(temps);
    cout << endl;

    return 0;
}
