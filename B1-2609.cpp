#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << "\n" << lcm(a, b) << "\n";
    
    return 0;
}