class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, ans = 0, mx = 0;

        for(int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            mx = max(mx, freq[s[right] - 'A']);

            while((right - left + 1) - mx > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};