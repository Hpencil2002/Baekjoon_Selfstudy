#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, tmp;
    int *num;

    cin >> N;
    num = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        cout << upper_bound(num, num + N, tmp) - lower_bound(num, num + N, tmp) << " ";
    }

    delete[] num;

    return 0;
}