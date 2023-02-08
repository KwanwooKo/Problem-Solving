#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define endl '\n'
#define INF 987654321
using namespace std;

class Solution {
    private:
        int n, ans;
        vector<pair<int, int> > list;
        priority_queue<pair<int, int> > pq;
    public:
        Solution() {
            cin >> n;
            ans = 1;
            for (int i = 0; i < n; i++) {
                int score1, score2;
                cin >> score1 >> score2;
                list.push_back(make_pair(score1, score2));
            }
        }
        void solve() {
            sort(list.begin(), list.end());
            pq.push(make_pair(list[0].first, list[0].second));
            for (int i = 1; i < n; i++) {
                int curScore = list[i].second;
                int topScore = pq.top().second;
                // can not join the company
                if (topScore < curScore) continue;
                pq.push(make_pair(list[i].first, list[i].second));
                ans++;
            }
            cout << ans << endl;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution* sol = new Solution();
        sol->solve();
        delete sol;

    }
}

