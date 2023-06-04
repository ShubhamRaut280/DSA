#include <iostream>
#include <queue>

using namespace std;

int main() {

int n, k; 

    priority_queue<int, vector<int>>maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    cout<<"Enter no of students: ";
    cin>>n;
    cout<<"\nEnter marks: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>k;
        maxheap.push(k);
        minheap.push(k);
    }
   cout<<"\nminimum marks are : "<<minheap.top(); 
   cout<<"\nmaximum marks are : "<<maxheap.top();

    return 0;
}
