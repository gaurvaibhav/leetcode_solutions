//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    void rev(string& str) {
        int i=0, j=str.length()-1;
        while(i<=j) {
            swap(str[i],str[j]);
            i++;j--;
        }
    }
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0" ;
        bool f = false;
        if(num1[0]=='-' && num2[0] =='-') {
            rev(num1);
            rev(num2);
            num1.pop_back();
            num2.pop_back();
            rev(num1);
            rev(num2);
        }
        else if(num1[0]=='-'){
            f=true;
            rev(num1);
            num1.pop_back();
            rev(num1);
        }
        else if(num2[0]=='-'){
            f=true;
            rev(num2);
            num2.pop_back();
            rev(num2);
        }
        string res((num1.length()+num2.length()), '0') ;
        for(int i=num1.length()-1; i>=0; i--) {
            for(int j=num2.length()-1; j>=0; j--) {
                int number = (res[i+j+1]-'0') + ((num1[i]-'0')*(num2[j]-'0')) ;
                res[i+j+1] = number%10 + '0' ;
                res[i+j] += number/10 ;
            }
        }
        rev(res);
        while(res.back()=='0') res.pop_back();
        if(f) res.push_back('-');
        rev(res);
        return res ;
    }

};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends