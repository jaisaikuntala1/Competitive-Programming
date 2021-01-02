/*

Check if Linked List is Palindrome 

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
void reversal(struct Node** head_ref){
    struct Node* current;
    struct Node* next;
    struct Node* prev;
    prev = NULL;
    current = *head_ref;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
bool comparelists(struct Node* head1, struct Node* head2){
    while(head1&&head2){
        if(head1->data!=head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1==NULL&&head2==NULL){
        return true;
    }
    if(head1==NULL || head2==NULL){
        return false;
    }
}
bool isPalindrome(Node *head)
{
    //Your code here
   struct Node* slow_ptr;
   struct Node* slow_ptr_prev = head;
   struct Node* fast_ptr;
   slow_ptr = head;
   fast_ptr = head;
   bool result = true;
   
   if(head!=NULL && head->next!=NULL){
       while(fast_ptr!=NULL && fast_ptr->next!=NULL){
       slow_ptr_prev = slow_ptr;
       slow_ptr = slow_ptr->next;
       fast_ptr = fast_ptr->next->next;
       
        }
    struct Node* secondhalf;
    slow_ptr_prev->next = NULL;
    if(fast_ptr!=NULL){
           slow_ptr = slow_ptr->next;
    }
    secondhalf = slow_ptr;
    reversal(&secondhalf);
    result = comparelists(head,secondhalf);
    }
    
    return result;
   
   
}