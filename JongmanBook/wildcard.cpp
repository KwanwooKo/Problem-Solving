#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
class Solution {
    private:
        string pattern;
        vector<string> list;
        vector<string> ans;
        int cache[101][101];
        int n;
    public:
        Solution() {
            cin >> pattern;
            cin >> n;
            memset(cache, -1, sizeof(cache));
            for (int i = 0; i < n; i++) {
                string s;
                cin >> s;
                list.push_back(s);
            }
        }
        int matchMemoized(int s, int w, string S, string W) {
            int& ret = cache[w][s];
            if (ret != -1) return ret;

            while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
                w++, s++;
            if (w == W.size()) {
                return ret = (s == S.size());
            }
            if (W[w] == '*') {
                for (int skip = 0; s + skip <= S.size(); skip++) {
                    if (matchMemoized(s + skip, w + 1, S, W)) {
                        return ret = 1;
                    }
                }
            }
            return ret = 0;
        }
        bool match(const string& s, const string& w) {
            int pos = 0;
            while (pos < s.size() && pos < w.size() && (s[pos] == '?' || s[pos] == w[pos]))
                pos++;
            if (pos == w.size()) {
                return pos == s.size();
            }
            if (w[pos] == '*') {
                for (int skip = 0; pos + skip <= s.size(); skip++) {
                    if (match(s.substr(pos + skip), w.substr(pos + 1))) {
                        return true;
                    }
                }
            }
            return false;
        }
        void solve() {
            for (int i = 0; i < n; i++) {
                if (match(pattern, list[i])) {
                    ans.push_back(list[i]);
                }
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << endl;
            }
        }
};
int main(void) {
    int t;
    cin >> t;
    while (t--) {
        Solution* sol = new Solution();
        sol->solve();
        delete sol;
    }
}
