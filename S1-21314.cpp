#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string str;

string GetMax() {
    stack<char> st;
    string res = "";

    for (int i = 0; i < str.size(); i++) {
        if (st.empty()) {
            if (str[i] == 'K') {
                res.append(to_string(5));
            }
            else if (str[i] == 'M') {
                st.push(str[i]);
            }
        }
        else {
            if (st.top() == 'M' && str[i] == 'K') {
                res.append(to_string(5));
                for (int i = 0; i < st.size(); i++) {
                    res.append(to_string(0));
                }

                while (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(str[i]);
            }
        }
    }

    if (!st.empty()) {
        for (int i = 0; i < st.size(); i++) {
            res.append(to_string(1));
        }
    }

    return res;
}

string GetMin() {
    vector<char> vc;
    string res = "";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'K') {
            if (!vc.empty()) {
                res.append(to_string(1));
                for (int i = 0; i < vc.size() - 1; i++) {
                    res.append(to_string(0));
                }
                res.append(to_string(5));

                vc.clear();
            }
            else if (vc.empty()) {
                res.append(to_string(5));
            }
        }
        else if (str[i] == 'M') {
            vc.push_back('M');
        }
    }

    if (!vc.empty()) {
        res.append(to_string(1));
        for (int i = 0; i < vc.size() - 1; i++) {
            res.append(to_string(0));
        }
    }

    return res;
}

int main() {
    cin >> str;

    cout << GetMax() << "\n" << GetMin();

    return 0;
}