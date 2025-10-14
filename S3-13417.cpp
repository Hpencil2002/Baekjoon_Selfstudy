#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string cards = "";
        char card;
        for (int i = 0; i < N; i++) {
            cin >> card;
            cards = cards + card < card + cards ? cards + card : card + cards;
        }

        cout << cards << "\n";
    }

    return 0;
}