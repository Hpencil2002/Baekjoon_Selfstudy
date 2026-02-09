#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> numbers = {
	{ "####.##.##.####", "0" },
	{ "###..#####..###", "2" },
	{ "###..####..####","3" },
	{ "#.##.####..#..#","4" },
	{ "####..###..####", "5" },
	{ "####..####.####", "6" },
	{ "###..#..#..#..#", "7" },
	{ "####.#####.####", "8" },
	{ "####.####..####", "9" },
};

int N;
string str;
string ans;
vector<string> vc;

int main() {
    cin >> N >> str;
    for (int i = 0; i < N; i += N / 5) {
        vc.push_back(str.substr(i, N / 5));
    }

    int plus = 1;
    for (int i = 0; i < N / 5; i += plus) {
        plus = 1;

        if (vc[0][i] == '#') {
            string res = "";

            if (i == N / 5 - 1 || vc[0][i + 1] == '.' && vc[3][i] == '#') {
                ans += '1';
            }
            else {
                for (int j = 0; j < 5; j++) {
                    res += vc[j].substr(i, 3);
                }

                plus = 3;

                if (numbers.find(res) != numbers.end()) {
                    ans += numbers[res];
                }
            }
        }
    }

    cout << ans;

    return 0;
}