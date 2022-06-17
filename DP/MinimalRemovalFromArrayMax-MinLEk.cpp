// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        int n=a.size();
        int ans=INT_MAX;
        sort(a.begin(),a.end());
        for(int j=n-1;j>=0;j--)
        {
            int lb=lower_bound(a.begin(),a.end(),a[j]-k)-a.begin();
            int num1=n-(j+1);
            int num2=lb;
            ans=min(ans,num1+num2);
        }
        return ans;
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends