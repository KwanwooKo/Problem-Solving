#include <iostream>
#include <vector>

class Solution {

private:
    vector<int> xList;

public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        for (auto point : points) {
            xList.push_back(point[0]);
        }
        sort(xList.begin(), xList.end());
        xList.erase(unique(xList.begin(), xList.end()), xList.end());

        int ans = 0;
        int cur = xList[0];

        for (int i = 1; i < xList.size(); i++) {
            ans = max(xList[i] - cur, ans);
            cur = xList[i];
        }
        
        return ans;
    }
};
