#include <iostream>
using namespace std;

int N;
int sp, ep;

int main() {
    cin >> N;

    cout << "? 1" << endl;
    cin >> sp;
    cout << "? " << N << endl;
    cin >> ep;

    if (sp == ep) {
        cout << "! 0" << endl;
    }
    else {
        sp > ep ? cout << "! -1" << endl : cout << "! 1" << endl;
    }

    return 0;
}