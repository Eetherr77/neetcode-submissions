class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for(char c : t) freq[c]++;

        int left = 0, cnt = t.size();
        int start = 0, len = INT_MAX;

        for(int right = 0; right < s.size(); right++) {
            if(freq[s[right]] > 0) cnt--;
            freq[s[right]]--;

            while(cnt == 0) {
                if(right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0) cnt++;

                left++;
            }
        }

        if(len == INT_MAX) return "";
        return s.substr(start, len);
    }
};