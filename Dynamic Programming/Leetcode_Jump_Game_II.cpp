/*

45. Jump Game II

3513

163

Add to List

Share
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


*/


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
              
        if(n==0 || n==1){
            return 0;
        }
        int jumps[n];
        for(int i=0;i<n;i++){
            jumps[i] = INT_MAX;
        }
        jumps[0] = 0;
        for(int i=0;i<n-1;i++){
            for(int j = min(i+nums[i],n-1);j>i;j--){
                if(jumps[j]>jumps[i]+1){
                    jumps[j] = jumps[i]+1;
                }
                else{
                    break;
                }
            }
        }
        return jumps[n-1];
        
        
        
        
    }
};