#include <iostream>
using namespace std;

int main() {
    int num[10], i, j;
    int cnt = 0;

    for (i = 0; i < 10; i++) {
        cin >> num[i];
        num[i] %= 42;
        
        for (j = 0; j < i; j++) {
            if (num[i] == num[j]) {
                break;
            }
        }
        
        if (i == j) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}