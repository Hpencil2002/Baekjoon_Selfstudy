#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    vector<int> vc = vector<int>(N, 0);
    for (int i = 0; i < M; i++) {
        int oper, index, x;

        cin >> oper >> index;
        index -= 1;

        if (oper == 1 || oper == 2) {
            cin >> x;
            x -= 1;

            if (x < 0 || x > 19) {
                continue;
            }
        }

        if (oper == 1) {
            vc[index] |= (1 << x);
        }
        else if (oper == 2) {
            vc[index] &= ~(1 << x);
        }
        else if (oper == 3) {
            vc[index] <<= 1;
            vc[index] &= ((1 << 20) - 1);
        }
        else if (oper == 4) {
            vc[index] >>= 1;
        }
    }

    set<int> st;
    for (int i = 0; i < vc.size(); i++) {
        st.insert(vc[i]);
    }

    cout << st.size();

    return 0;
}