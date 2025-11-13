#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    int T;
    cin >> T;

    list<char> password;
    list<char>::iterator it;
    while (T--) {
        string str;
        cin >> str;

        password.clear();
        it = password.begin();

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '<') {
                if (it != password.begin()) {
                    it--;
                }
            }
            else if (str[i] == '>') {
                if (it != password.end()) {
                    it++;
                }
            }
            else if (str[i] == '-') {
                if (it != password.begin()) {
                    it = password.erase(--it);
                }
            }
            else {
                it = password.insert(it, str[i]);
                it++;
            }
        }

        for (char x : password) {
            cout << x;
        }
        cout << "\n";
    }

    return 0;
}