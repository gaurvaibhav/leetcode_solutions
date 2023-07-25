#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    bool isValid(string s) {
        op;
        stack<char> aux ;
        for(char it : s) {
            if(it == '(' || it == '{' || it == '[') {
                aux.push(it) ;
            }
            else {
                if(aux.empty() || (aux.top() == '(' && it != ')') || (aux.top() == '{' && it != '}') || (aux.top() == '[' && it != ']') ) {
                    return false ;
                }
                aux.pop() ;
            }
        }
        return aux.empty() ;
    }
};