class MinStack {
public:
    stack<int> stc;
    vector<int> mn;
    MinStack() {
        
    }
    
    void push(int val) {
        stc.push(val);
        if(mn.size()==0 || val<=mn.back()) {
            mn.push_back(val);
        }
    }
    
    void pop() {
        if(stc.top()==mn.back()) {
            mn.pop_back();
        }
        stc.pop();
    }
    
    int top() {
        return stc.top();
    }
    
    int getMin() {
        return mn.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */