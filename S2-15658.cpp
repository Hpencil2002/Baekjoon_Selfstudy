#include <iostream>
#include <vector>
using namespace std;

int N;
int maxVal = -1000000001;
int minVal = 1000000001;
vector<int> nums;
int Plus, Minus, Multiple, Divide;

void dfs(int p, int mi, int mul, int div, int sum, int index) {
    if (index == N) {
        if (sum > maxVal) {
            maxVal = sum;
        }
        if (sum < minVal) {
            minVal = sum;
        }

        return;
    }

    if (p < Plus) {
        dfs(p + 1, mi, mul, div, sum + nums[index], index + 1);
    }
    if (mi < Minus) {
        dfs(p, mi + 1, mul, div, sum - nums[index], index + 1);
    }
    if (mul < Multiple) {
        dfs(p, mi, mul + 1, div, sum * nums[index], index + 1);
    }
    if (div < Divide) {
        dfs(p, mi, mul, div + 1, sum / nums[index], index + 1);
    }
}

int main() {
    cin >> N;

    nums = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    cin >> Plus >> Minus >> Multiple >> Divide;

    dfs(0, 0, 0, 0, nums[0], 1);

    cout << maxVal << "\n" << minVal;

    return 0;
}