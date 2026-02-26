#include <iostream>
using namespace std;

pair<int, int> p1;
pair<int, int> p2;
pair<int, int> p3;

int main() {
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;

    int flag = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
    if (flag > 0) {
        cout << 1;
    }
    else if (flag < 0) {
        cout << -1;
    }
    else {
        cout << 0;
    }

    return 0;
}