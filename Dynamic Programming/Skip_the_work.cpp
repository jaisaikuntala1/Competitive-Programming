/*

Skip the work 

Given an array A[ ] denoting the time taken to complete N tasks, determine the minimum amount of time required to finish the tasks considering that you can skip any task, but skipping two consecutive tasks is forbidden.
 

Example 1:

Input:
N = 2
A[] ={10,20}
Output: 10
Explanation: we can take time of
10 units and skip 20 units time.

â€‹Example 2:

Input:
N = 4
A[] = {10,5,7,10}
Output: 12
Explanation: we can skip both the
tens and pick 5 and 7 only.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minAmount() which accepts array A[] and its size N as input parameter and returns minimum amount of time required to finish the tasks.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 106

*/

#include <iostream>
using namespace std;

 // } Driver Code Ends






class Solution
{
  public:
    int minAmount(int arr[] , int n)
    {
        if (n <= 0) 
        {return 0;} 
  
    // Initialize value for the case when there 
    // is only one task in task list. 
    int incl = arr[0];  // First task is included 
    int excl = 0;       // First task is exluded 
  
    // Process remaining n-1 tasks 
    for (int i=1; i<n; i++) 
    { 
       // Time taken if current task is included 
       // There are two possibilities 
       // (a) Previous task is also included 
       // (b) Previous task is not included 
       int incl_new = arr[i] + min(excl, incl); 
  
       // Time taken when current task is not 
       // included.  There is only one possibility 
       // that previous task is also included. 
       int excl_new = incl; 
  
       // Update incl and excl for next iteration 
       incl = incl_new; 
       excl = excl_new; 
    } 
  
    // Return maximum of two values for last task 
    return min(incl, excl); 
      
     
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            int n;
            cin>>n;
            int arr[n];
            for(int i = 0;i<n;i++)
                cin>>arr[i];
            Solution ob;    
            cout<<ob.minAmount(arr,n)<<endl;    
        }
}  // } Driver Code Ends