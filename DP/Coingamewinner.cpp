// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		int n=N,x=X,y=Y;
		vector<bool>dp(n+1,false);
		//true-> picked by A , false->by B
		dp[1]=true; //first move A
		
		for(int i=2;i<=n;i++)
		{
		    //if from any three pos 
		  //  i.e i-1 or i-x or i-y b ne uthaya hai 
		  //  to ith wala A hi uthaega
		    if(i-1>=0 && dp[i-1]==false)
		    {
		        dp[i]=true;
		    }
		    else if(i-x>=0 && dp[i-x]==false)
		    {
		        dp[i]=true;
		    }
		    else if(i-y>=0 && dp[i-y]==false)
		    {
		        dp[i]=true;
		    }
		}
		if(dp[n])
		return 1;
		else
		return 0;
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends