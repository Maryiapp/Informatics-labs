#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <numbers>

using namespace std;

/* ----------------------------------------------------------
   TASK 1: Simple Function — Sum of Three Numbers
---------------------------------------------------------- */
double sum3(double a, double b, double c)
{
    return a + b + c;
}




/* ----------------------------------------------------------
   TASK 2: Stars with a Twist — print_stars_advanced
---------------------------------------------------------- */
void print_stars_advanced(int s, char symbol)
{
    cout << "[";
    for (int i = 0; i < s; i++)
        cout << symbol;
    cout << "]" << endl;
}




/* ----------------------------------------------------------
   TASK 3: Recursion Practice — Factorial
---------------------------------------------------------- */
int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}




/* ----------------------------------------------------------
   TASK 4: Monte Carlo π Approximation
---------------------------------------------------------- */
double estimate_pi(int shots)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    uniform_real_distribution<double> dist(-1.0, 1.0);

    int inside = 0;

    for (int i = 0; i < shots; i++)
    {
        double x = dist(gen);
        double y = dist(gen);

        if (x * x + y * y < 1.0)
            inside++;
    }

    return 4.0 * inside / shots;
}



/* ----------------------------------------------------------
   TASK 5: Inline Function — Minimum
---------------------------------------------------------- */
inline double minimum(double a, double b)
{
    return (a < b) ? a : b;
}



/* ----------------------------------------------------------
   MAIN FUNCTION
---------------------------------------------------------- */
int main()
{
    cout << "=== Function Practice Tasks ===" << endl;
    cout << "Sum of three: " << sum3(1.1, 2.2, 3.3) << endl;
    print_stars_advanced(5, '#');
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Estimated π: " << estimate_pi(10000) << endl;
    cout << "Minimum of 10 and 3.14: " << minimum(10, 3.14) << endl;
    return 0;
}





    