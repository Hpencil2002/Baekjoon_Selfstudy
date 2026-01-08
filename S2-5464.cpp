#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
int ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqu;
queue<int> orderQu;
queue<int> inoutQu;
vector<int> weight;
vector<pair<int, int>> space;

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int price;
        cin >> price;

        pqu.push({ i, price });
    }

    weight = vector<int>(M + 1);
    for (int i = 1; i <= M; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < M * 2; i++) {
        int record;
        cin >> record;

        inoutQu.push(record);
    }

    space = vector<pair<int, int>>(M + 1);
    while (inoutQu.size() > 0) {
        int curRecord = inoutQu.front();
        inoutQu.pop();

        if (curRecord > 0) {
            if (pqu.size() == 0) {
                orderQu.push(curRecord);
            }
            else {
                space[curRecord] = pqu.top();
                pqu.pop();
            }
        }
        else {
            int curCar = abs(curRecord);
            pqu.push(space[curCar]);

            ans += space[curCar].second * weight[curCar];

            if (orderQu.size() > 0) {
                space[orderQu.front()] = pqu.top();
                pqu.pop();
                orderQu.pop();
            }
        }
    }

    cout << ans;

    return 0;
}