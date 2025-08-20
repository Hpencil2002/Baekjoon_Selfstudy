#include <iostream>
#include <string>
using namespace std;

string word, ring;
int N, ans;

bool isFind(int i) {
    for (int j = 0; j < word.size(); j++) {
        if (ring[i + j] != word[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> word >> N;

    while (N--) {
        cin >> ring;

        for (int i = 0; i < word.size() - 1; i++) {
            ring.push_back(ring[i]);
        }

        for (int i = 0; i <= ring.size() - word.size(); i++) {
            if (isFind(i)) {
                ans += 1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}