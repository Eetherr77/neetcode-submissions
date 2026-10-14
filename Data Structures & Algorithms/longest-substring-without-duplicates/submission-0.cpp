class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0, ans = 0;
        map<char, int> mp;

        for(int i = 0, j = 0; i < s.size(); i++) {
            mp[s[i]]++;

            while(mp[s[i]] > 1) {
                mp[s[j]]--;
                j++;
            }

            cnt = i - j + 1;
            ans = max(ans, cnt);
        }

        return ans;
    }
};