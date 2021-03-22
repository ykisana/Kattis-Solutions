#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
void get_divisors(int n);
int main()
{
    int n = 0;
    cout << "Enter a number:";
    cin >> n;
    get_divisors(n);
    cout << endl;
}
void get_divisors(int n)
{
    int i;
    double sqrt_of_n = sqrt(n);
    for (i = 2; i <= sqrt_of_n; i++)
        if (n % i == 0)
        {
            cout << i << ", ";
            get_divisors(n / i);
            return;
        }
    cout << n;
}