#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

// task 1
void print_vector_with_iterator(const vector<int>& vec)
{
    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;
    }
}


// task 2
void fill_sequential(vector<int>& vec, int start_value)
{
    iota(vec.begin(), vec.end(), start_value);
}


// task 3
void sort_descending(vector<double>& vec)
{
    sort(vec.begin(), vec.end(),
        [](double a, double b) {
            return a > b;   // descending
        });
}


// task 4
int count_greater_than(const vector<int>& vec, int threshold)
{
    int count = 0;

    for_each(vec.begin(), vec.end(),
        [&](int x) {
            if (x > threshold)
                count++;
        });

    return count;
}


// task 5
double calculate_sum(const vector<double>& vec)
{
    double sum = 0.0;

    for_each(vec.begin(), vec.end(),
        [&](double x) {
            sum += x;
        });

    return sum;
}


// task 6
string find_by_length(const vector<string>& vec, int length)
{
    for (vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it->length() == length)
            return *it;
    }
    return "";
}


// task 7
void insert_in_middle(vector<int>& target, const vector<int>& source)
{
    vector<int>::iterator middle = target.begin() + target.size() / 2;
    target.insert(middle, source.begin(), source.end());
}


// task 8
vector<int> filter_even(const vector<int>& vec)
{
    vector<int> result;

    for_each(vec.begin(), vec.end(),
        [&](int x) {
            if (x % 2 == 0)
                result.push_back(x);
        });

    return result;
}




// MAIN

int main()
{
    vector<int> v = { 1, 2, 3, 4, 5 };
    print_vector_with_iterator(v);
    cout << endl;


    vector<int> seq(5);
    fill_sequential(seq, 10);
    print_vector_with_iterator(seq);
    cout << endl;


    vector<double> d = { 1.5, 3.2, 2.1 };
    sort_descending(d);
    for (double x : d) cout << x << " ";
    cout << endl << endl;
    cout << count_greater_than(v, 3) << endl << endl;


    vector<double> s = { 1.1, 2.2, 3.3 };
    cout << calculate_sum(s) << endl << endl;
    vector<string> words = { "cat", "dog", "elephant" };
    cout << find_by_length(words, 3) << endl << endl;


    vector<int> a = { 1, 2, 3, 4 };
    vector<int> b = { 10, 20 };
    insert_in_middle(a, b);
    for (int x : a) cout << x << " ";
    cout << endl << endl;

    vector<int> ev = filter_even({ 1, 2, 3, 4, 5, 6 });
    for (int x : ev) cout << x << " ";
    cout << endl;

    return 0;
}
