class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int cnt = 1, ans = 1;

        for(int i = 0; i + 1 < nums.size(); ++i) {
            if(nums[i] == nums[i + 1]) {
                continue;
            }
            else if(nums[i] == nums[i + 1] - 1) {
                cnt++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }

        return max(ans, cnt);
    }
};