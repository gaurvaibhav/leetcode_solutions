#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class MinStack {
public:
    stack<int> stc;
    vector<int> mn;
    MinStack() {
        op;
    }
    
    void push(int val) {
        op;
        stc.push(val);
        if(mn.size()==0 || val<=mn.back()) {
            mn.push_back(val);
        }
    }
    
    void pop() {
        op;
        if(stc.top()==mn.back()) {
            mn.pop_back();
        }
        stc.pop();
    }
    
    int top() {
        op;
        return stc.top();
    }
    
    int getMin() {
        op;
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