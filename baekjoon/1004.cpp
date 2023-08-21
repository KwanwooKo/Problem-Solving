#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int get_dist_square(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        pair<int, int> start;
        pair<int, int> arrive;
        cin >> start.first >> start.second;
        cin >> arrive.first >> arrive.second;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            int r;
            pair<int, int> center;
            cin >> center.first >> center.second >> r;
            int dist_start = get_dist_square(start, center);
            int dist_arrive = get_dist_square(arrive, center);
            if (dist_start <= r * r && dist_arrive <= r * r)
                continue;
            else {
                if (dist_start <= r * r) {
                    ans++;   
                }
                if (dist_arrive <= r * r) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
