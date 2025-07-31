#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        if (str == "KBS1") {
            index1 = i;
        }
        else if (str == "KBS2") {
            index2 = i;
        }
    }

    int order = index1 > index2 ? 1 : 0;
    for (int i = 0; i < index1; i++) {
        cout << "1";
    }
    for (int i = 0; i < index1; i++) {
        cout << "4";
    }
    for (int i = 0; i < index2 + order; i++) {
        cout << "1";
    }
    for (int i = 0; i < index2 + order - 1; i++) {
        cout << "4";
    }

    return 0;
}