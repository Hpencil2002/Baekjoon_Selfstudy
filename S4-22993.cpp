#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100001];
long long ori;
bool flag = true;

int main() {
    cin >> N;

    cin >> ori;
    for (int i = 1; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N);

    for (int i = 1; i < N; i++) {
        if (ori <= arr[i]) {
            flag = false;
            break;
        }
        else {
            ori += arr[i];
        }
    }

    if (flag) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}