/*

RACHIT AND NIGHT TUITION Problem Code: CIN001

 
Rachit lives on the coordinate axis OX at x=a. He has his night tuition classes at x=b. On the axis at point x=c, a road light is placed which has it's radius of coverage as r i.e. from x=c, at a distance less than or equal to r, he will have light on his path, otherwise he has to walk in dark.

Print the distance (the total coordinate points) during which Rachit will walk in dark while going from his home to his tuition. Note that the road light can be located between his home and tuition and even outside it.

Constraints - −10^8≤a,b,c≤10^8 0≤r≤10^8

Input - First line contains the total number of test cases t(1<=t<=1000).

The next line contains four test cases a : the coordinate of his home, b : the coordinate of his tuition classes, c : the coordinate where road light is present and r : it's coverage radius.

Output - Output an integer - the total coordinate points during which Rachit will walk in the dark during his movement.

Sample Test Case -

Input- 5 -3 2 2 0 -3 1 2 0 -1 -3 -3 0 2 3 2 3 -1 3 -2 2

Output- 5 4 2 0 3

*/

#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int x,y,c,r,a,b;
        cin>>x>>y>>c>>r;
        a = min(x,y);
        b = max(x,y);
        int tot_dist = b-a;
        if((c+r)<a || (c-r)>b){
            cout<<tot_dist<<" ";
        }
        else if(tot_dist==0){
            cout<<0<<" ";
        }
        else if(r==0){
            cout<<b-a<<" ";
        }
        else if(a<=(c-r) && (c+r)<=b){
            cout<<(tot_dist-(2*r))<<" ";
        }
        else if((c-r)<=a && (c+r)<=b){
            cout<<tot_dist-(c+r-a)<<" ";
        }
        else if(a<=(c-r) && b<=(c+r)){
            cout<<tot_dist-(b-c+r)<<" ";
        }
        else{
            cout<<0<<" ";
        }
    }
}
