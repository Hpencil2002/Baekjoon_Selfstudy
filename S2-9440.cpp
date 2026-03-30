#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int arr[15];

int main() {
    while (true) {
        cin >> N;
        if (N == 0) {
            return 0;
        }

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + N);

        string a = "";
        string b = "";
        int ans;
        int zero = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] == 0) {
                zero += 1;
            }
        }
        if (zero == 1) {
            swap(arr[0], arr[2]);
        }
        else if (zero > 1) {
            swap(arr[0], arr[zero]);
            swap(arr[1], arr[zero + 1]);
        }

        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                a += to_string(arr[i]);
            }
            else {
                b += to_string(arr[i]);
            }
        }

        ans = stoi(a) + stoi(b);
        cout << ans << "\n";
    }
}