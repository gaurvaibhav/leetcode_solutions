class Solution {
public:
    int sum(int n){
        int sum=0;
        while(n>0){
            int x=n%10;
            sum+=x*x;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int s,f;
        s = f = n;
        do{
            s=sum(s);
            f=sum(sum(f));
            if(f==1) return true;
        }while(s!=f);
        return false;
    }
};