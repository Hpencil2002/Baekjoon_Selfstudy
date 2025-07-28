#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int height[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> height[i];
        sum += height[i];
    }

    sort(height, height + 9);

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - (height[i] + height[j]) == 100) {
                for (int h = 0; h < 9; h++) {
                    if (h != i && h != j) {
                        cout << height[h] << '\n';
                    }
                }

                return 0;
            }
        }
    }

    return 0;
}