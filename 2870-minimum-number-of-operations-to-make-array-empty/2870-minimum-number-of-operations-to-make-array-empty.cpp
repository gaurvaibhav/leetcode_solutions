class Solution {
public:
    int minOperations(vector<int>& nums) {
        int answer;
        unordered_map<int, int> mapp;
        priority_queue<int> priorq;
        for(int& num: nums)
        {
            mapp[num]++;
        }
        answer = 0;
        for(auto& it: mapp)
        {
            priorq.push(it.second);
        }
        while(!priorq.empty())
        {
            if(priorq.top() == 1) return -1;
            if(priorq.top() % 3 == 0) 
            {
                int t = priorq.top();
                priorq.pop();
                answer += t/3;
            }
            else if(priorq.top() > 4) 
            {
                int t = priorq.top();
                priorq.pop();
                t -= 3;
                if(t) priorq.push(t);
                answer ++;
            }
            else if(priorq.top() == 2) 
            {
                int t = priorq.top();
                priorq.pop();
                answer++;
            }
            else if(priorq.top() == 4) 
            {
                int t = priorq.top();
                priorq.pop();
                answer+=2;
            }
            
        }
        return answer;
    }
};