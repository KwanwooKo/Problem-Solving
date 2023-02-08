#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class Solution {
    private:
        string W;
        vector<string> list;
        vector<string> ans;
        // [w][s] => 해당 문자열이 매칭 되는지 확인
        int cache[101][101];
        int n;
    public:
        Solution() {
            cin >> W;
            cin >> n;
            for (int i = 0; i < n; i++) {
                string s;
                cin >> s;
                list.push_back(s);
            }
        }
        int memoizedPattern(int s, int w, string S) {
            int& ret = cache[w][s];
            if (ret != -1) return ret;
            while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
                s++, w++;

            // 패턴에 * 이 더이상 없는 경우
            if (w == W.size()) {
                // 패턴이 남았지만 문자열이 이미 끝난 경우, 하지만 이 경우는 패턴도 안남음
                return ret = (s == S.size());
            }

            if (W[w] == '*') {
                for (int skip = 0; s + skip <= S.size(); skip++) {
                    if (memoizedPattern(s + skip, w + 1, S)) {
                        return ret = 1;
                    }
                }
            }
            return ret = 0;
        }
        void printAns() {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << endl;
            }
        }
        void solve() {
            for (int i = 0; i < list.size(); i++) {
                string S = list[i];
                memset(cache, -1, sizeof(cache));
                int check = memoizedPattern(0, 0, S);
                if (check) ans.push_back(list[i]);
            }
            printAns();
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution* sol = new Solution();
    sol->solve();
    delete sol;
}
