#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    int n;
    int *rad;
    cin >> n;

    rad = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> rad[i];
    }

    int tmp = rad[0];
    for (int i = 1; i < n; i++) {
        int quo = gcd(tmp, rad[i]);
        cout << tmp / quo << "/" << rad[i] / quo << "\n"; 
    }

    return 0;
}

int gcd(int a, int b) {
    int c;

    while (b != 0) {
        c = a % b;
        a = b; 
        b = c;
    }

    return a;
}