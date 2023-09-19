class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(k > n || n == 0) return 0;
        if(k <= 1) return n;
        unordered_map<char, int> mp;
        for(char& c: s) mp[c]++;
        int i;
        for(i=0; i<n && mp[s[i]]>=k; ++i);
        if(i >= n-1) return i; 
        int left, right;
        left = right = 0;
        left = longestSubstring(s.substr(0, i), k);
        for(; i<n && mp[s[i]]<k; ++i);
        if(i<n) right = longestSubstring(s.substr(i), k);
        return max(left, right);
    }
};