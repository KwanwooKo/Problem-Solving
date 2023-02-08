#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

class Solution {
    private:
        string input;
    public:
        Solution() {
            cin >> input;
        }
        bool checkCapital(char c) {
            if ('A' <= c && c <= 'Z') {
                return true;
            }
            return false;
        }
        bool detectCapitalUse(string word) {
            char firstWord = word[0];
            // 맨 앞글자가 대문자 인 경우
            if (checkCapital(firstWord)) {
                char secondWord = word[1];
                if (checkCapital(secondWord)) {
                    for (int i = 2; i < word.size(); i++) {
                        if (!checkCapital(word[i])) return false;
                    }
                    return true;

                } else {
                    for (int i = 1; i < word.size(); i++) {
                        if (checkCapital(word[i])) return false;
                    }
                    return true;
                }
            }
            // 맨 앞글자가 소문자 인 경우
            else {
                for (int i = 1; i < word.size(); i++) {
                    if (checkCapital(word[i])) return false;
                }
                return true;
            }
        }
        void solve() {
            bool check = detectCapitalUse(input);
            if (check) cout << "true" << endl;
            else cout << "false" << endl;
        }
};

int main(void) {
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
