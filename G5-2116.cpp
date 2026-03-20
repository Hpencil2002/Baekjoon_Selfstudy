#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans;
int arr[10000][6];

int getTop(int i) {
    if (i == 0) {
        return 5;
    }
    if (i == 1) {
        return 3;
    }
    if (i == 2) {
        return 4;
    }
    if (i == 3) {
        return 1;
    }
    if (i == 4) {
        return 2;
    }
    if (i == 5) {
        return 0;
    }
    return 0;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    for (int d = 0; d < 6; d++) {
        int ansTmp = 0;
        int index = d;
        int maxVal = 0;

        for (int i = 0; i < N - 1; i++) {
            maxVal = 0;
            index = getTop(index);

            for (int s = 0; s < 6; s++) {
                if (arr[i + 1][s] == arr[i][index]) {
                    for (int x = 0; x < 6; x++) {
                        if (x == index || x == getTop(index)) {
                            continue;
                        }
                        else {
                            maxVal = max(maxVal, arr[i][x]);
                        }
                    }

                    index = s;

                    break;
                }
            }

            ansTmp += maxVal;
        }

        maxVal = 0;
        index = getTop(index);

        for (int i = 0; i < 6; i++) {
            if (i == index || i == getTop(index)) {
                continue;
            }
            else {
                maxVal = max(maxVal, arr[N - 1][i]);
            }
        }

        ansTmp += maxVal;

        ans = max(ans, ansTmp);
    }

    cout << ans;

    return 0;
}