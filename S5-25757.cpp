#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;

int main() {
    int N;
    char T;
    cin >> N >> T;

    for (int i = 0;  i < N; i++) {
        string name;
        cin >> name;

        s.insert(name);
    }

    if (T == 'Y') {
        cout << s.size();
    }
    else if (T == 'F') {
        cout << s.size() / 2;
    }
    else {
        cout << s.size() / 3;
    }

    return 0;
}