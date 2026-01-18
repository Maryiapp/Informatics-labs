#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <utility>
using namespace std;

// Task 1: Create a struct called 'book' with fields for title, author, year of publication, 
// and number of pages. Then create a vector of at least 3 books and print out the author 
// of the second book in your collection.
struct book {
    string title;
    string author;
    int year;
    int pages;
};



// Task 2: Write a function that takes a vector of integers and returns a pair containing 
// the sum and the average of all numbers. Test it with the vector {12, 45, 67, 23, 89, 34}.
pair<int, double> sumAndAverage(const vector<int>& v) {
    int sum = 0;
    for (int num : v) {
        sum += num;
    }
    double avg = static_cast<double>(sum) / v.size();
    return { sum, avg };
}



// Task 3: Create a std::array of 5 doubles representing temperatures in Celsius. 
// Write code to find and display both the highest and lowest temperature from the array 
// without using any additional functions.



// Task 4: Build a simple phone book using std::map where the key is a person's name 
// and the value is their phone number. Add at least 4 entries, then write code to 
// look up and display a specific person's number. Also print all entries in the phone book.



// Task 5: Define a struct called 'student' that contains name, student ID number, 
// and a vector of grades. Create two students, add several grades to each, 
// then calculate and print the average grade for both students.
struct student {
    string name;
    int id;
    vector<int> grades;
};

// Task 6: Create a nested structure for a 'computer' that has fields for brand and model, 
// plus a nested struct for 'processor' containing manufacturer, model, and speed in GHz. 
// Initialize one computer object and print all its details.
struct computer {
    string brand;
    string model;

    struct processor {
        string manufacturer;
        string model;
        double speedGHz;
    } cpu;
};


// Task 7: Use std::map to count how many times each character appears in the string 
// "programming is fun and challenging". Display the results showing each character 
// and its count, but skip spaces in your counting.




int main()
{
    // task 1
    vector<book> books = {
        {"1984", "George Orwell", 1949, 328},
        {"The Hobbit", "J.R.R. Tolkien", 1937, 310},
        {"Dune", "Frank Herbert", 1965, 412}
    };

    cout << "Author of second book: " << books[1].author << endl << endl;

    // task 2
    vector<int> nums = { 12, 45, 67, 23, 89, 34 };
    pair<int, double> result = sumAndAverage(nums);

    cout << "Sum: " << result.first << endl;
    cout << "Average: " << result.second << endl << endl;

    // task 3
    array<double, 5> temps = { 12.5, 7.3, 19.8, 4.6, 15.2 };

    double maxTemp = temps[0];
    double minTemp = temps[0];

    for (int i = 1; i < 5; i++) {
        if (temps[i] > maxTemp) maxTemp = temps[i];
        if (temps[i] < minTemp) minTemp = temps[i];
    }

    cout << "Highest temperature: " << maxTemp << endl;
    cout << "Lowest temperature: " << minTemp << endl << endl;

    // task 4
    map<string, string> phoneBook;
    phoneBook["Alice"] = "123-4567";
    phoneBook["Bob"] = "987-6543";
    phoneBook["Charlie"] = "555-1122";
    phoneBook["Diana"] = "444-8899";

    cout << "Bob's number: " << phoneBook["Bob"] << endl << endl;

    cout << "Phone book entries:" << endl;
    for (const auto& entry : phoneBook) {
        cout << entry.first << " -> " << entry.second << endl;
    }
    cout << endl;

    // task 5
    student s1;
    s1.name = "John";
    s1.id = 101;
    s1.grades = { 85, 90, 88 };

    student s2;
    s2.name = "Emma";
    s2.id = 102;
    s2.grades = { 92, 95, 89 };

    auto calcAverage = [](const student& s) {
        int sum = 0;
        for (int g : s.grades) sum += g;
        return static_cast<double>(sum) / s.grades.size();
        };

    cout << s1.name << "'s average: " << calcAverage(s1) << endl;
    cout << s2.name << "'s average: " << calcAverage(s2) << endl << endl;

    // task 6
    computer pc;
    pc.brand = "Dell";
    pc.model = "XPS 15";
    pc.cpu.manufacturer = "Intel";
    pc.cpu.model = "i7-12700H";
    pc.cpu.speedGHz = 3.5;

    cout << "Computer details:" << endl;
    cout << "Brand: " << pc.brand << endl;
    cout << "Model: " << pc.model << endl;
    cout << "CPU Manufacturer: " << pc.cpu.manufacturer << endl;
    cout << "CPU Model: " << pc.cpu.model << endl;
    cout << "CPU Speed: " << pc.cpu.speedGHz << " GHz" << endl << endl;

    // task 7
    string text = "programming is fun and challenging";
    map<char, int> freq;

    for (char c : text) {
        if (c != ' ') {
            freq[c]++;
        }
    }

    cout << "Character frequencies:" << endl;
    for (const auto& p : freq) {
        cout << "'" << p.first << "' : " << p.second << endl;
    }

    return 0;
}

