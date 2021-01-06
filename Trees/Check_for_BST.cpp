/*

Check for BST 
Medium Accuracy: 21.58% Submissions: 100k+ Points: 4
Given a binary tree. Check whether it is a BST or not.

Example 1:

Input:
    2
 /    \
1      3
Output: 1
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false. The printing is done by the driver's code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
0 <= Number of edges <= 100000

*/
#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    cout << isBST(root) << endl;
   }
   return 0;
}



 // } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return true if the given tree is a BST, else return false
bool isbst(Node* root,int mini, int maxi){
   if(root==NULL){
       return true;
   }
   if(root->data<mini || root->data>maxi){
       return false;
   }
   else{
       return isbst(root->left,mini,root->data-1)&&isbst(root->right,root->data+1,maxi);
   }
}
bool isBST(Node* root) {
    return isbst(root,-1,1000000007);
}




