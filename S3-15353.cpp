#include <iostream>
#include <string>
#include <vector>
using namespace std;

int num1[10001] = { 0, };
int num2[10001] = { 0, };
vector<int> vc;

int main() {
    string A, B;
    cin >> A >> B;
    if (A.size() < B.size()) {
        string tmp = A;
        A = B;
        B = tmp;
    }

    for (int i = 0; i < A.size(); i++) {
        num1[i + 1] = A[i] - '0';
    }
    for (int i = 0; i < B.size(); i++) {
        num2[i + 1 + A.size() - B.size()] = B[i] - '0';
    }

    for (int i = A.size(); i > 0; i--) {
        int c = num1[i] + num2[i];

        if (c >= 10) {
            num1[i - 1] += 1;
            c -= 10;
        }

        vc.push_back(c);
    }

    if (num1[0] != 0) {
        vc.push_back(1);
    }

    for (int i = vc.size() - 1; i >= 0; i--) {
        cout << vc[i];
    }

    return 0;
}