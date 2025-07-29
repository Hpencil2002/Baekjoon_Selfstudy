#include <iostream>
#include <string>
using namespace std;

int main() {
    int P;
    cin >> P;

    while (P--) {
        string coin;
        cin >> coin;

        int coin_list[8] = { 0, };
        for (int i = 0; i < coin.size() - 2; i++) {
            string coin_3 = coin.substr(i, 3);

            if (coin_3 == "TTT") {
                coin_list[0] += 1;
            }
            else if (coin_3 == "TTH") {
                coin_list[1] += 1;
            }
            else if (coin_3 == "THT") {
                coin_list[2] += 1;
            }
            else if (coin_3 == "THH") {
                coin_list[3] += 1;
            }
            else if (coin_3 == "HTT") {
                coin_list[4] += 1;
            }
            else if (coin_3 == "HTH") {
                coin_list[5] += 1;
            }
            else if (coin_3 == "HHT") {
                coin_list[6] += 1;
            }
            else if (coin_3 == "HHH") {
                coin_list[7] += 1;
            }
        }

        for (auto& element : coin_list) {
            cout << element << ' ';
        }
        cout << "\n";
    }

    return 0;
}