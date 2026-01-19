#include <iostream>
using namespace std;

int N;
int ans;
pair<int, int> arr[100001];
int Min = 100001;
int Max = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;

        if (arr[i].second < Min) {
            Min = arr[i].second;
        }
        if (arr[i].first > Max) {
            Max = arr[i].first;
        }
    }

    int gap = Max - Min;
    if (gap < 0) {
        ans = 0;
    }
    else {
        ans = gap;
    }

    cout << ans;

    return 0;
}