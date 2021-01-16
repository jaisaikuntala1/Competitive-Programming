/*
Job Sequencing Problem 
Medium Accuracy: 34.0% Submissions: 7582 Points: 4
Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Input Format:

Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

Example 1:

Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output: 2 60
Explanation: 2 jobs can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = (1,2,100)(2,1,19)(3,2,27)
(4,1,25)(5,1,15)
Output:2 127
Explanation: 2 jobs can be done with
maximum profit of 127 (100+27).
Your Task :

Complete the function jobscheduling() that returns count of jobs and maximum profit.

Constraints:
1 <= N <= 100
1 <= Deadline <= 100
1 <= Profit <= 500

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(N)
*/


// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends


// Prints minimum number of platforms reqquired 
bool compare(Job a, Job b){
    return a.profit>b.profit;
}
pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    int deadlines_filled[n+1];
    for(int i=0;i<n;i++){
        deadlines_filled[i] = -1;
    }
    sort(arr,arr+n,compare);
    int num_of_jobs = 0;
    int pro = 0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead-1;j>=0;j--){
            if(deadlines_filled[j]==-1){
                num_of_jobs++;
                pro += arr[i].profit;
                deadlines_filled[j] = 1;
                break;
            }
        }
        
    }
    pair<int,int> ans;
    ans = make_pair(num_of_jobs,pro);
    return ans;
    
    
    
} 



// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        //function call
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}


  // } Driver Code Ends