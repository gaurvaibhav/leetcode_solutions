//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    private:
    void rev(vector<int>& arr) {
        int i=0, j=arr.size()-1;
        while(i<=j){
            swap(arr[i++],arr[j--]);
        }
    }
    public:
    vector<int> leaders(int a[], int n){
        int mx=a[n-1];
        vector<int> res;
        res.push_back(mx);
        for(int i=n-2; i>=0; --i) {
            if(a[i]>=mx) mx=a[i],res.push_back(mx);
        }
        rev(res);
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends