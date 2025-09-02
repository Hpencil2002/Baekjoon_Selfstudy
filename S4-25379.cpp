#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long even_sum = 0;
    long long odd_sum = 0;
    long long even_cnt = 0;
    long long odd_cnt = 0;
    long long arr[1000001];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if (arr[i] % 2) {
            odd_sum += (i - odd_cnt++);
        }
        else {
            even_sum += (i - even_cnt++);
        }
    }

    cout << min(odd_sum, even_sum);

    return 0;
}