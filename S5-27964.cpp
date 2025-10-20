#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string cheese;
        cin >> cheese;

        if (cheese.size() >= 6 && cheese.substr(cheese.size() - 6, 6) == "Cheese") {
            if (mp.find(cheese) == mp.end()) {
                mp[cheese] = 1;
            }
        }
    }

    if (mp.size() >= 4) {
        cout << "yummy";
    }
    else {
        cout << "sad";
    }

    return 0;
}