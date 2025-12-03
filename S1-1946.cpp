#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> arr[100000];
int cntArr[21];

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        sort(arr, arr + N);

        int maxScore = arr[0].second;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i].second <= maxScore) {
                cnt += 1;
                maxScore = arr[i].second;
            }
        }

        cntArr[t] = cnt;
    }

    for (int i = 0; i < T; i++) {
        cout << cntArr[i] << "\n";
    }

    return 0;
}