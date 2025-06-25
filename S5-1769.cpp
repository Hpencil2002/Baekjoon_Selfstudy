#include <iostream>
#include <string>
using namespace std;

int cnt = 0;
int len = 0;

int get_num(string str) {
    int result = 0;

    for (int i = 0; i < len; i++) {
        result += str[i] - '0';
    }

    return result;
}

int main() {
    string input = "";
    cin >> input;
    len = input.size();

    while (len > 1) {
        cnt += 1;

        int sum = 0;
        sum = get_num(input);
        input = to_string(sum);
        len = input.size();
    }

    cout << cnt << "\n";
    if (stoi(input) % 3 == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}