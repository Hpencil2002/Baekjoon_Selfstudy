#include <iostream>
#include <map>
using namespace std;

int a, b, num;
map<int, bool> mp;

int main() {
    cin >> a >> b;
    for (int i = 0; i < a + b; i++) {
        cin >> num;

        if (mp[num] == true) {
            mp.erase(num);
        }
        else {
            mp[num] = true;
        }
    }

    cout << mp.size();

    return 0;
}