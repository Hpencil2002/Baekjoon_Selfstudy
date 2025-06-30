#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int price[100001] = { 0, };

int main() {
    int U, N;
    cin >> U >> N;

    vector<pair<string, int>> vc(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i].first >> vc[i].second;
        price[vc[i].second] += 1;
    }

    int minprice = 100001;
    for (int i = 1; i <= 100000; i++) {
        if (price[i] > 0) {
            minprice = min(minprice, price[i]);
        }
    }

    vector<int> lowprice;
    for (int i = 1; i <= 100000; i++) {
        if (price[i] == minprice) {
            lowprice.push_back(i);
        }
    }

    sort(lowprice.begin(), lowprice.end());

    for (int i = 0; i < N; i++) {
        if (vc[i].second == lowprice[0]) {
            cout << vc[i].first << ' ' << vc[i].second;
            break;
        }
    }

    return 0;
}