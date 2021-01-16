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