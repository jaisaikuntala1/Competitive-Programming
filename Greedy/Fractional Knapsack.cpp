/*

Fractional Knapsack 
Easy Accuracy: 37.03% Submissions: 9544 Points: 2
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output: 240.00
Explanation: Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 

Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output: 160.00
Explanation: Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
 

Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size n and returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.

 

Constraints:
1 <= N <= 100
1 <= W <= 100

 

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
bool compare(Item a, Item b){
    return ((double)a.value/(double)a.weight)>((double)b.value/(double)b.weight);
    
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr,arr+n,compare);
    double wt = 0;
    double profit = 0;
    for(int i=0;i<n;i++){
        if(wt+arr[i].weight<=W){
            wt += arr[i].weight;
            profit += arr[i].value;
        }
        else{
            double rem_wt = W-wt;
            profit += (arr[i].value*rem_wt/arr[i].weight);
            break;
        }
    }
    return profit;
    
    
}

// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends

