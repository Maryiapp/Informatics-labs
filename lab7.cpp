#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;



// TASK 1: Function Overloading - Absolute Value

int absolute(const int value)
{
    return (value < 0 ? -value : value);
}
double absolute(const double value)
{
    return (value < 0 ? -value : value);
}
void absolute(vector<int>& vec)
{
    for (int& v : vec)
        if (v < 0) v = -v;
}



// TASK 2: File Writing - Student Records
bool write_students(const string& filename,
    const vector<string>& names,
    const vector<int>& scores)
{
    if (names.size() != scores.size())
        return false;

    ofstream file(filename);
    if (!file)
        return false;

    for (size_t i = 0; i < names.size(); i++)
        file << "Name: " << names[i] << ", Score: " << scores[i] << "\n";
    return true;
}



// TASK 3: File Reading - Number Statistics
vector<double> read_numbers(const string& filename)
{
    ifstream file(filename);
    vector<double> numbers;

    if (!file) return numbers;

    double value;
    while (file >> value)
        numbers.push_back(value);

    return numbers;
}
int count_positive(const vector<double>& numbers)
{
    int count = 0;
    for (double n : numbers)
        if (n > 0) count++;
    return count;
}
int count_negative(const vector<double>& numbers)
{
    int count = 0;
    for (double n : numbers)
        if (n < 0) count++;
    return count;
}



// TASK 4: Reference Parameters - Sort Three Values
void sort_three(int& a, int& b, int& c)
{
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}
void increment_all(int& a, int& b, int& c, const int value)
{
    a += value;
    b += value;
    c += value;
}
void make_equal(int& a, int& b, int& c)
{
    int avg = (a + b + c) / 3;
    a = b = c = avg;
}



// TASK 5: String Stream Processing
vector<int> parse_integers(const string& text)
{
    stringstream ss(text);
    vector<int> result;
    string token;

    while (ss >> token)
    {
        stringstream num(token);
        int value;
        if (num >> value)
            result.push_back(value);
    }
    return result;
}

string join_strings(const vector<string>& words, const string& delimiter)
{
    stringstream ss;
    for (size_t i = 0; i < words.size(); i++)
    {
        ss << words[i];
        if (i + 1 < words.size())
            ss << delimiter;
    }
    return ss.str();
}

int count_tokens(const string& text)
{
    stringstream ss(text);
    string token;
    int count = 0;
    while (ss >> token)
        count++;
    return count;
}


// TASK 6: Recursive Array Operations
int array_sum_recursive(const int array[], const int length, const int index = 0)
{
    if (index >= length) return 0;
    return array[index] + array_sum_recursive(array, length, index + 1);
}

int find_max_recursive(const int array[], const int length, const int index = 0)
{
    if (index == length - 1)
        return array[index];

    return max(array[index],
        find_max_recursive(array, length, index + 1));
}



// TASK 7: Multi-File Data Processing
struct Datasummary {
    string filename;
    int line_count;
    int word_count;
    int char_count;
};
Datasummary analyze_file(const string& filename)
{
    Datasummary summary = { filename, 0, 0, 0 };
    ifstream file(filename);
    string line;
    if (!file) return summary;
    while (getline(file, line))
    {
        summary.line_count++;
        summary.char_count += line.size();

        stringstream ss(line);
        string word;

        while (ss >> word)
            summary.word_count++;
    }
    return summary;
}

void print_summary(const Datasummary& summary)
{
    cout << "File: " << summary.filename << "\n";
    cout << "Lines: " << summary.line_count << "\n";
    cout << "Words: " << summary.word_count << "\n";
    cout << "Characters: " << summary.char_count << "\n\n";
}
void compare_files(const string& file1, const string& file2)
{
    Datasummary a = analyze_file(file1);
    Datasummary b = analyze_file(file2);

    cout << "Comparing " << file1 << " and " << file2 << ":\n";

    cout << ((a.line_count > b.line_count) ? file1 : file2) << " has more lines.\n";
    cout << ((a.word_count > b.word_count) ? file1 : file2) << " has more words.\n";
    cout << ((a.char_count > b.char_count) ? file1 : file2) << " has more characters.\n\n";
}





int main()
{
    cout << "TASK 1\n";
    cout << "absolute(-42) = " << absolute(-42) << "\n";
    cout << "absolute(-3.14) = " << absolute(-3.14) << "\n";
    vector<int> vec = { -5, 10, -15, 20 };
    cout << "Vector before: ";
    for (int v : vec) cout << v << " ";
    cout << "\n";

    absolute(vec);

    cout << "Vector after: ";
    for (int v : vec) cout << v << " ";
    cout << "\n\n";




    cout << "TASK 2\n";
    vector<string> names = { "Alice", "Bob", "Charlie", "Diana", "Ethan" };
    vector<int> scores = { 90, 85, 78, 92, 88 };

    if (write_students("students.txt", names, scores))
        cout << "Students written to students.txt\n\n";
    else
        cout << "Failed to write students.\n\n";
     



    cout << "TASK 3\n";
    ofstream numfile("numbers.txt");
    numfile << "3.5 -2 0 7 -9 12 0 4";
    numfile.close();

    vector<double> nums = read_numbers("numbers.txt");

    cout << "Total numbers: " << nums.size() << "\n";
    cout << "Positive: " << count_positive(nums) << "\n";
    cout << "Negative: " << count_negative(nums) << "\n";
    cout << "Zero: " << (nums.size() - count_positive(nums) - count_negative(nums)) << "\n\n";



    cout << "task 4\n";
    int a = 45, b = 12, c = 33;

    sort_three(a, b, c);
    cout << "After sort_three: " << a << " " << b << " " << c << "\n";

    increment_all(a, b, c, 5);
    cout << "After increment_all(+5): " << a << " " << b << " " << c << "\n";

    make_equal(a, b, c);
    cout << "After make_equal: " << a << " " << b << " " << c << "\n\n";




    cout << "task 5\n";
    vector<int> parsed = parse_integers("The year 2024 has 366 days");
    cout << "Parsed integers: ";
    for (int p : parsed) cout << p << " ";
    cout << "\n";

    string joined = join_strings({ "Hello", "World", "!" }, ", ");
    cout << "Joined string: " << joined << "\n";

    cout << "Token count: " << count_tokens("C++ is fun to learn!") << "\n\n";



    cout << "task 6\n";
    int arr[] = { 34, 67, 12, 89, 45, 23, 78 };
    int length = 7;

    int sum_rec = array_sum_recursive(arr, length);
    int max_rec = find_max_recursive(arr, length);

    cout << "Recursive Sum: " << sum_rec << "\n";
    cout << "Recursive Max: " << max_rec << "\n\n";



    cout << "task 7\n";
    ofstream f1("file1.txt");
    f1 << "Hello world\nThis is file one.";
    f1.close();
    ofstream f2("file2.txt");
    f2 << "Another file\nWith more words\nAnd more lines.";
    f2.close();
    Datasummary s1 = analyze_file("file1.txt");
    Datasummary s2 = analyze_file("file2.txt");
    print_summary(s1);
    print_summary(s2);
    compare_files("file1.txt", "file2.txt");


    return 0;
}