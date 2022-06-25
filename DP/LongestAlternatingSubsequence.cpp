// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int ans=0,j=1;
		    int n=nums.size();
		    int maxtill=nums[0],mintill=nums[0];
		    for(int i=1;i<n;i++) // <x2>
		    {
		        if(j%2)
		        {
    		        if(nums[i]>mintill)
    		        {
    		            j++;
    		            maxtill=nums[i];
    		            continue;
    		        }
    		        else
    		        {
    		            mintill=nums[i];
    		        }
		        }
		        else
		        {
		            if(nums[i]<maxtill)
    		        {
    		            j++;
    		            mintill=nums[i];
    		            continue;
    		        }
    		        else
    		        {
    		            maxtill=nums[i];
    		        }
		        }
		    }
		    ans=j;
		    j=1,maxtill=nums[0],mintill=nums[0];
		    for(int i=1;i<n;i++) // >x2<
		    {
		        if(j%2)
		        {
    		        if(nums[i]<maxtill)
    		        {
    		            j++;
    		            mintill=nums[i];
    		            continue;
    		        }
    		        else
    		        {
    		            maxtill=nums[i];
    		        }
		        }
		        else
		        {
		            if(nums[i]>mintill)
    		        {
    		            j++;
    		            maxtill=nums[i];
    		            continue;
    		        }
    		        else
    		        {
    		            mintill=nums[i];
    		        }
		        }
		    }
		    return max(ans,j);
		}

};

// make pyramid like dig from test cases ->the corner pts/vertices 
// ka sum is ans 
//             			    60
// 				  50	   /	
// 			     /  \	  / 
// 			    49   \   /
// 			   /	  \ /				
// 		      33       31
// 	   22     /
//    /  \	 /		
//  10		9

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends