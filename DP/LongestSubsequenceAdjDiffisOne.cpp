// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<int>dp(N+1,0);
        int ans=-1;
        for(int i=0;i<N;i++)
        {
            int num=-1;
            for(int j=0;j<i;j++)
            {
                if(abs(A[i]-A[j])==1)
                {
                    num=max(num,dp[j]);
                }
            }
            if(num==-1)
            dp[i]=0;
            else
            dp[i]=num+1;
            
            ans=max(ans,dp[i]);
        }
        return ans+1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends