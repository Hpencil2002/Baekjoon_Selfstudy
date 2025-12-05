#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool isPalindrome(string str) {
    string front, back;

    front = str;
    reverse(str.begin(), str.end());
    back = str;

    if (front == back) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int N;
    cin >> N;

    while (true) {
        if (isPrime(N) && isPalindrome(to_string(N))) {
            cout << N;

            return 0;
        }

        N += 1;
    }
}