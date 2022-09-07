#include <iostream>
using namespace std;

int main() {
    int n;
    int *num;
    cin >> n;

    num = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (num[i] == 2 || num[i] % 2 != 0) {
            if (num[i] == 3 || num[i] % 3 != 0) {
                if (num[i] == 5 || num[i] % 5 != 0) {
                    if (num[i] == 7 || num[i] % 7 != 0) {
                        if (num[i] == 11 || num[i] % 11 != 0) {
                            if (num[i] == 13 || num[i] % 13 != 0) {
                                if (num[i] == 17 || num[i] % 17 != 0) {
                                    if (num[i] == 19 || num[i] % 19 != 0) {
                                        if (num[i] == 23 || num[i] % 23 != 0) {
                                            if (num[i] == 29 || num[i] % 29 != 0) {
                                                if (num[i] == 31 || num[i] % 31 != 0) {
                                                    cnt++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (num[i] == 1) {
            cnt--;
        }
    }

    cout << cnt;
}