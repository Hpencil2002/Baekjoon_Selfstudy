#include <iostream>
#include <vector>
using namespace std;

int K;
int input[10024];
vector<int> arr[11];

void insertTree(int depth, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    arr[depth].push_back(input[mid]);
    insertTree(depth + 1, start, mid);
    insertTree(depth + 1, mid + 1, end);
}

int main() {
    cin >> K;

    int num;
    int index = 0;
    while (cin >> num) {
        input[index] = num;
        index += 1;
    }

    insertTree(0, 0, index);

    for (int i = 0; i < K; i++) {
        for (auto o : arr[i]) {
            cout << o << ' ';
        }

        cout << "\n";
    }

    return 0;
}