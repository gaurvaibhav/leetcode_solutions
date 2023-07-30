#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    string joinStr(string x, string y){
        op;
        if(x.find(y) != string::npos) return x;
        for(int i=min(x.length(),y.length()); i>=0; --i) {
            if(x.substr(x.length()-i) == y.substr(0,i)) 
                return x+y.substr(i);
        }
        return x+y;
    }
    string findSmaller(string x, string y) {
        op;
        if(x.length() == y.length()) {
            if(x.compare(y) < 0) return x;
            return y;
        }
        return (x.length()<y.length())?x:y;
    }
    void check(string& str, string a, string b, string c) {
        op;
        string aux = joinStr(joinStr(a,b),c);
        str = findSmaller(str,aux);
    }
    string minimumString(string a, string b, string c) {
        op;
        string res = "";
        res = a+b+c;
        check(res,a,b,c);
        check(res,a,c,b);
        check(res,b,a,c);
        check(res,b,c,a);
        check(res,c,a,b);
        check(res,c,b,a);
        return res;
    }
};
