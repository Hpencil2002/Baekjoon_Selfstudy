#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int R;
    double pi = M_PI;
    cin >> R;

    double area_euclidean = pi * pow(R, 2);
    double area_taxicab = 2 * pow(R, 2);

    cout << fixed;
    cout.precision(6);
    cout << area_euclidean << "\n" << area_taxicab << "\n";

    return 0;
}