#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<int> st;

int main() {
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            st.push(str[i] - '0');
        }
        else {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();

            if (str[i] == '+') {
                int num = num2 + num1;
                st.push(num);
            }
            else if (str[i] == '-') {
                int num = num2 - num1;
                st.push(num);
            }
            else if (str[i] == '*') {
                int num = num2 * num1;
                st.push(num);
            }
            else if (str[i] == '/') {
                int num = num2 / num1;
                st.push(num);
            }
        }
    }

    cout << st.top();

    return 0;
}