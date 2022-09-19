#include <iostream>
using namespace std;

int han(int num);

int main() {
    int n;
    int count;

    cin >> n;
    count = han(n);

    cout << count << "\n";
    return 0;
}

int han(int num) {
    int cnt = 0;

    if (num < 100) {
        return num;
    }
    else {
        cnt = 99;

        for (int i = 100; i < num + 1; i++) {
            int hund = i / 100;
            int ten = (i / 10) % 10;
            int one = i % 10;

            if ((hund - ten) == (ten- one)) {
                cnt += 1;
            }
        }
    }

    return cnt;
}