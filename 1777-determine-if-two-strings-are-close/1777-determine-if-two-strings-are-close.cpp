class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> mp1(26, 0), mp2(26, 0);
        set<char> s1, s2;
        for(char& c: word1)
        {
            mp1[c-'a']++;
            s1.insert(c);
        }
        for(char& c: word2)
        {
            mp2[c-'a']++;
            s2.insert(c);
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return ((mp1 == mp2) && (s1 == s2));
    }
};