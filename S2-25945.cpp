#include <iostream>
using namespace std;

int n;
int arr[1000001];
int sum, avg;
int top, bot;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    avg = sum / n;

    for (int i = 0; i < n; i++) {
        if (arr[i] < avg) {
            bot += avg - arr[i];
        }
        else if (arr[i] > avg + 1) {
            top += arr[i] - (avg + 1);
        }
    }

    if (top <= bot) {
        cout << bot;
    }
    else {
        cout << top;
    }

    return 0;
}