#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, C;
    int I_A, I_B, I_C;

    cin >> A >> B >> C;
    I_A = stoi(A);
    I_B = stoi(B);
    I_C = stoi(C);

    cout << I_A + I_B - I_C << "\n";

    string tmp_str = A + B;
    int tmp_int = stoi(tmp_str);
    cout << tmp_int - I_C;

    return 0;
}