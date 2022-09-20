#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int A, B;
    string A2, B2;

    cin >> A >> B;
    
    A2 = to_string(A);
    B2 = to_string(B);

    reverse(A2.begin(), A2.end());
    reverse(B2.begin(), B2.end());

    if (A2 > B2) {
        cout << A2 << "\n";
    }
    else {
        cout << B2 << "\n";
    }

    return 0;
}