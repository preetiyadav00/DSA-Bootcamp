// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

   // TC,SC- O(n)
	public:
	
long long int mat[4][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {-1,0,-1}
};
long long int dp[10][30];

	long long int solve(long long int i,long long int j,long long int n)
	{
	    
	    
	    if(n==1)    //one digit number sab 1 banaenge hi
	    return 1;
	    if(dp[mat[i][j]][n]!=-1)
	    return dp[mat[i][j]][n];    //memoize
	    
	    long long int a=0,b=0,c=0,d=0,e=0;  
	    
	    
	     a=solve(i,j,n-1);   //back to that element itself
	    if(mat[i+1][j]!=-1 && i+1<4)
	     {   b=solve(i+1,j,n-1);} //down
	    if(mat[i-1][j]!=-1 && i-1>=0)
	     {   c=solve(i-1,j,n-1);} //up
	    if(mat[i][j+1]!=-1 && j+1<3)
	    {    d=solve(i,j+1,n-1); }//right
	    if(mat[i][j-1]!=-1 && j-1>=0)
	    {    e=solve(i,j-1,n-1);} //left
	    
	    return dp[mat[i][j]][n]=a+b+c+d+e;
	}
	long long getCount(int N)
	{
		// Your code goes here
		dp[10][N+1];
        memset(dp,-1,sizeof(dp));
		long long int ans=0;
		for(int i=0;i<4;i++)
		{
		    for(int j=0;j<3;j++)
		    {
		        if(mat[i][j]!=-1)
		            {
		                ans+=solve(i,j,N);
		                
		            }
		    }
		}
		return ans;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends