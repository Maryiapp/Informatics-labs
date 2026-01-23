#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

/* TASK 1: Create and Use unique_ptr
   Write a function that creates a unique_ptr to an integer, sets its value
   to the given parameter, and returns the unique_ptr. */
unique_ptr<int> create_unique(int value) {
    return make_unique<int>(value);
}

/*TASK 2: Transfer Ownership with unique_ptr
   Write a function that takes a unique_ptr by move, adds 100 to its value,
   and returns the modified unique_ptr. */
unique_ptr<int> add_hundred(unique_ptr<int> ptr) {
    if (ptr) {
        *ptr += 100;
    }
    return ptr;
}

/* TASK 3: Create Dynamic Array with unique_ptr
   Write a function that creates a unique_ptr to a dynamic array of doubles
   of given size, initializes all elements to their index * 2.5, and returns it. */
unique_ptr<double[]> create_array(size_t size) {
    unique_ptr<double[]> arr = make_unique<double[]>(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = i * 2.5;
    }
    return arr;
}

/* TASK 4: Shared Ownership with shared_ptr
   Write a function that creates a shared_ptr to an integer with given value
   and returns a vector containing 3 copies of that shared_ptr.
   All should point to the same value. */
vector<shared_ptr<int>> create_shared(int value) {
    shared_ptr<int> ptr = make_shared<int>(value);
    vector<shared_ptr<int>> ptrs(3, ptr);
    return ptrs;
}

/* TASK 5: Custom strlen Implementation
   Write a function that calculates the length of a C-style string
   without using strlen. Use pointer arithmetic. */
int my_string_length(const char* str) {
    const char* start = str;
    while (*str) {
        ++str;
    }
    return str - start;
}

/* TASK 6: Custom strcpy Implementation  
   Write a function that copies a C-style string from source to destination.
   Assume destination has enough space. Use pointer arithmetic. */
void my_string_copy(char* destination, const char* source) {
    while (*source) {
        *destination = *source;
        ++destination;
        ++source;
    }
    *destination = '\0';
}

/* TASK 7: Custom strcat Implementation
   Write a function that concatenates (appends) source string to the end
   of destination string. Assume destination has enough space. */
void my_string_concat(char* destination, const char* source) {
    while (*destination) {
        ++destination;
    }
    while (*source) {
        *destination = *source;
        ++destination;
        ++source;
    }
    *destination = '\0';
}

/* TASK 8: Count Words in C-String
   Write a function that counts the number of words in a C-style string.
   Words are separated by spaces. Multiple spaces count as one separator. */
int count_words(const char* str) {
    int count = 0;
    bool in_word = false;

    while (*str) {
        if (*str != ' ' && !in_word) {
            in_word = true;
            ++count;
        }
        else if (*str == ' ') {
            in_word = false;
        }
        ++str;
    }
    return count;
}

/* MAIN FUNCTION */
int main() {
    // TASK 1
    cout << "TASK 1\n";
    auto uptr = create_unique(42);
    cout << "Value: " << *uptr << "\n\n";

    // TASK 2
    cout << "TASK 2\n";
    auto moved_ptr = add_hundred(move(uptr));
    cout << "After adding 100: " << *moved_ptr << "\n\n";

    // TASK 3
    cout << "TASK 3\n";
    auto arr = create_array(4);
    for (int i = 0; i < 4; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    // TASK 4
    cout << "TASK 4\n";
    auto shared_vec = create_shared(99);
    cout << "Value: " << *shared_vec[0] << "\n";
    cout << "use_count: " << shared_vec[0].use_count() << "\n\n";

    // TASK 5
    cout << "TASK 5\n";
    cout << "Length of 'Hello': "
        << my_string_length("Hello") << "\n\n";

    // TASK 6
    cout << "TASK 6\n";
    char dest1[50];
    my_string_copy(dest1, "Copy");
    cout << "Copied string: " << dest1 << "\n\n";

    // TASK 7
    cout << "TASK 7\n";
    char dest2[50] = "Hello";
    my_string_concat(dest2, " World");
    cout << "Concatenated string: " << dest2 << "\n\n";

    // TASK 8
    cout << "TASK 8\n";
    cout << "Word count: "
        << count_words("Hello  World  C++") << "\n";

    return 0;
}


