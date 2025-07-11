#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> input;
    for (int i = 0; i < N; i++) {
        int product, delivery;
        cin >> product >> delivery;

        input.push_back({product, delivery});
    }

    sort(input.begin(), input.end());

    int maxCost = 0;
    int maxProfit = 0;

    for (int i = 0; i < N; i++) {
        int sum = 0;

        for (int j = i; j < N; j++) {
            int curProfit = input[i].first - input[j].second;
            if (curProfit > 0) {
                sum += curProfit;
            }
        }

        if (maxProfit < sum) {
            maxProfit = sum;
            maxCost = input[i].first;
        }
    }

    cout << maxCost;

    return 0;
}