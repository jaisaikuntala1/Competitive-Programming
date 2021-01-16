/*

Minimum number of jumps 
Medium Accuracy: 32.96% Submissions: 23600 Points: 4
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Example 1:

Input:
N=11 
arr=1 3 5 8 9 2 6 7 6 8 9 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
Example 2:

Input :
N= 6
arr= 1 4 3 2 6 7
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element.
Your task:

You don't need to read input or print anything. Your task is to complete function minJumps() which takes the array arr and it's size N as input parameters and returns the minimum number of jumps.

Constraints:
1 ≤ N ≤ 107
0 <= ai <= 107

 

*/



//Time Complexity : O(n^2)

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
              
        if(n==1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int jumps[n];
        for(int i=0;i<n;i++){
            jumps[i] = INT_MAX;
        }
        jumps[0] = 0;
        for(int i=0;i<n-1;i++){
            for(int j = min(i+arr[i],n-1);j>i;j--){
                if(jumps[j]>jumps[i]+1){
                    jumps[j] = jumps[i]+1;
                }
                else{
                    break;
                }
            }
        }
        if(jumps[n-1]==INT_MAX){
            return -1;
        }
        return jumps[n-1];
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends





  // METHOD 2:

  //Time Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
              
        if(n<=1){
         return 0;
     }
     if(arr[0]==0){
         return -1;
     }
     int jumps_made = 1;
     int max_reachable = arr[0];
     int steps_remaining = arr[0];
     for(int i=1;i<n;i++){
         if(i==n-1){
             return jumps_made;
         }
         max_reachable = max(max_reachable,i+arr[i]);
         steps_remaining--;
         if(steps_remaining==0){
             jumps_made++;
             if(i>=max_reachable){
                 return -1;
             }
             steps_remaining = max_reachable - i;
         }
     }
     return jumps_made;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends