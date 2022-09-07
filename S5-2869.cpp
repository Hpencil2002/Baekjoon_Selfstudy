#include <iostream>
using namespace std;

int main() {
    int a, b, v;
    int cnt = 1;

    cin >> a >> b >> v;

    cnt += (v - a) / (a - b); //정상에 다다르면 떨어지지 않으므로 목표는 v-a

    if ((v - a) % (a - b) != 0) { //v-a를 가는데에 걸리는 시간은 (v-a)/(a-b)인데 (v-a)/(a-b)의 나머지가 0이 아니면 거리가 조금 부족함 => +1해서 끝
        cnt += 1;
    }

    if (a >= v) {
        cout << "1";
    }
    else {
        cout << cnt;
    }

    return 0;
}