#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int B, C, D;
    cin >> B >> C >> D;

    vector<int> burger = vector<int>(B);
    vector<int> side = vector<int>(C);
    vector<int> drink = vector<int>(D);

    int before = 0;
    for (int i = 0; i < B; i++) {
        cin >> burger[i];
        before += burger[i];
    }
    for (int i = 0; i < C; i++) {
        cin >> side[i];
        before += side[i];
    }
    for (int i = 0; i < D; i++) {
        cin >> drink[i];
        before += drink[i];
    }

    sort(burger.begin(), burger.end(), greater<int>());
    sort(side.begin(), side.end(), greater<int>());
    sort(drink.begin(), drink.end(), greater<int>());

    vector<int> set_menu;
    vector<int> individual;

    int min_set = min({B, C, D});
    for (int i = 0; i < min_set; i++) {
        int price = (burger[i] + side[i] + drink[i]) * 0.9;
        set_menu.push_back(price);
    }

    for (int i = min_set; i < B; i++) {
        individual.push_back(burger[i]);
    }
    for (int i = min_set; i < C; i++) {
        individual.push_back(side[i]);
    }
    for (int i = min_set; i < D; i++) {
        individual.push_back(drink[i]);
    }

    int after = 0;
    for (int i = 0; i < set_menu.size(); i++) {
        after += set_menu[i];
    }
    for (int i = 0; i < individual.size(); i++) {
        after += individual[i];
    }

    cout << before << "\n" << after;

    return 0;
}