#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <deque>
using namespace std;


/*  TASK 1: Reverse Print Using Iterator
   Write a function that prints all elements of a vector in reverse order
   using a reverse iterator. Each element should be printed on a new line. */

void reverse_print(const vector<int>& vec)
{
    for (vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << *it << endl;
    }
}



/* TASK 2: Multiply All Elements
   Write a function that multiplies all elements in a vector by a given
   factor. Use std::for_each with a lambda function that captures the
   factor by value. */

void multiply_all(vector<int>& vec, int factor)
{
    for_each(vec.begin(), vec.end(),
        [factor](int& x) {
            x *= factor;
        });
}


/* TASK 3: Sort Strings by Length
   Write a function that sorts a vector of strings by their length
   (shortest first). Use std::sort with a lambda function. */
void sort_by_length(vector<string>& vec)
{
    sort(vec.begin(), vec.end(),
        [](const string& a, const string& b) {
            return a.length() < b.length();
        });
}


/* TASK 4: Find Maximum Value
   Write a function that finds and returns the maximum value in a vector.
   Use std::for_each with a lambda function and capture the maximum
   value by reference. */
int find_maximum(const vector<int>& vec)
{
    int maximum = vec[0];

    for_each(vec.begin(), vec.end(),
        [&](int x) {
            if (x > maximum)
                maximum = x;
        });

    return maximum;
}


/* TASK 5: Calculate Average
   Write a function that calculates the average of all elements in a
   vector of doubles. Use std::for_each with a lambda function. */
double calculate_average(const vector<double>& vec)
{
    double sum = 0.0;

    for_each(vec.begin(), vec.end(),
        [&](double x) {
            sum += x;
        });

    return sum / vec.size();
}


/* TASK 6: Erase All Negative Numbers
   Write a function that removes all negative numbers from a vector.
   Use an iterator and the erase method in a loop. */
void erase_negatives(vector<int>& vec)
{
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); )
    {
        if (*it < 0)
            it = vec.erase(it);   // erase returns next valid iterator
        else
            ++it;
    }
}


/* TASK 7: Merge Two Sorted Vectors
   Write a function that takes two sorted vectors and merges them into
   the first vector, maintaining sorted order. Use vector::insert with
   iterators, then sort the result. */
void merge_sorted(vector<int>& first, const vector<int>& second)
{
    first.insert(first.end(), second.begin(), second.end());
    sort(first.begin(), first.end());
}


/* TASK 8: Count Strings Starting With Letter
   Write a function that counts how many strings in a vector start with
   a given letter (case-sensitive). Use std::for_each with a lambda
   function. */
int count_starting_with(const vector<string>& vec, char letter)
{
    int count = 0;

    for_each(vec.begin(), vec.end(),
        [&](const string& s) {
            if (!s.empty() && s[0] == letter)
                count++;
        });

    return count;
}




// MAIN 

int main()
{
    vector<int> v = { 1, 2, 3 };
    reverse_print(v);
    cout << endl;

    multiply_all(v, 5);
    for (int x : v) cout << x << " ";
    cout << endl << endl;

    vector<string> words = { "apple", "dog", "elephant", "cat" };
    sort_by_length(words);
    for (const string& s : words) cout << s << " ";
    cout << endl << endl;

    vector<int> nums = { 3, 7, 2, 9, 1 };
    cout << find_maximum(nums) << endl << endl;

    vector<double> d = { 2.0, 4.0, 6.0, 8.0 };
    cout << calculate_average(d) << endl << endl;

    vector<int> mix = { 1, -2, 3, -4, 5 };
    erase_negatives(mix);
    for (int x : mix) cout << x << " ";
    cout << endl << endl;

    vector<int> a = { 1, 3, 5 };
    vector<int> b = { 2, 4, 6 };
    merge_sorted(a, b);
    for (int x : a) cout << x << " ";
    cout << endl << endl;

    vector<string> names = { "apple", "ant", "bear", "Alice" };
    cout << count_starting_with(names, 'a') << endl;

    return 0;
}

