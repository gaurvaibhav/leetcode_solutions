#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class MyStack {
    
public:
    queue<int> qe;
    MyStack() {
    }
    
    void push(int x) {
        op;
        qe.push(x);
        for(int i=0; i<qe.size()-1; i++){
            qe.push(qe.front());
            qe.pop();
        }
    }
    
    int pop() {
        op;
        int res = qe.front();
        qe.pop();
        return res ;
    }
    
    int top() {
        op;
        return qe.front();
    }
    
    bool empty() {
        op;
        return qe.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */