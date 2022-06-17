// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here 
        sort(arr,arr+N);
        int ans=0;
        
        //direct sol//
        // for(int i=N-1;i>0;i--)
        // {
        //     if(arr[i]-arr[i-1]<K)
        //     {
        //         ans+=arr[i]+arr[i-1];
        //         i--;
        //     }
            
        // }
        
        vector<int>dp(N,0);
        
        if(N>=2)
        dp[1]=arr[0]+arr[1];
        
        for(int i=1;i<N;i++)
        {
            int exclude= dp[i-1];
            int include= arr[i]+arr[i-1]+dp[i-2];
            
            if(arr[i]-arr[i-1]<K)
            {
                dp[i]=max(include,exclude);
            }
            else
            {
                dp[i]=exclude;
            }
        }
        
        
        return dp[N-1];
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends