#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isCPP(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '_') {
            return true;
        }
    }

    return false;
}

int main() {
    string str;
    cin >> str;

    bool bFirst = true;
    string buff = "", ans = "";
    vector<string> vc;

    if (!islower(str[0])) {
        cout << "Error!";

        return 0;
    }
    if (str[str.size() - 1] == '_') {
        cout << "Error!";

        return 0;
    }

    if (isCPP(str)) {
        istringstream ss(str);
        while (getline(ss, buff, '_')) {
            vc.push_back(buff);
        }

        for (auto word : vc) {
            if (islower(word[0])) {
                if (bFirst) {
                    bFirst = false;
                }
                else {
                    word[0] = toupper(word[0]);
                }

                ans += word;
            }
            else {
                cout << "Error!";

                return 0;
            }

            for (int i = 1; i < word.size(); i++) {
                if (isupper(word[i])) {
                    cout << "Error!";

                    return 0;
                }
            }
        }
    }
    else {
        for (auto word : str) {
            if (isupper(word)) {
                ans += buff;
                ans += '_';
                buff.clear();
                buff += tolower(word);
            }
            else {
                buff += word;
            }
        }

        ans += buff;
    }

    cout << ans;

    return 0;
}