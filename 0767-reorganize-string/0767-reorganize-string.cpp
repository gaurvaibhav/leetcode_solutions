#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    string reorganizeString(string s) {
        op;
        string str = "";
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for(char c: s) 
            mp[c]++;
        for(auto p: mp) 
            pq.push({p.second, p.first});
        while(pq.size()>1){
            auto f = pq.top();
            pq.pop();
            auto s = pq.top();
            pq.pop();
            --f.first;
            --s.first;
            str += f.second;
            str += s.second;
            if(f.first) pq.push(f);
            if(s.first) pq.push(s);
        } 
        if(!pq.empty()) {
            if(pq.top().first > 1) return "";
            else str += pq.top().second;
        }
        return str;
    } 
};