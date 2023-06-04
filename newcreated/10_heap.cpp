#include<iostream>
using namespace std;

class heap
{
    public : 
    int n ;
    int * minheap, * maxheap;
    void get()
    {
        int k ;
        cout<<"\nEnter no of students : ";
        cin>> n;
        minheap = new int[n];
        maxheap = new int[n];
        cout<<"\nEnter marks one by one : ";
        for (int i = 0; i < n; i++)
        {
            cin>>k;
            minheap[i] = k;
            heapify(0, i);
            maxheap[i] = k;
            heapify(1, i);
        }
        
    }

    void print()
    {
        cout<<"\nThe maximum marks are : "<<maxheap[0];
        cout<<"\nThe minimum marks are : "<<minheap[0];
    }

    void heapify(bool c , int v)
    {
        if (!c)
        {
            // minheap 
            while (minheap[(v-1)/2]>minheap[v])
            {
               int temp =  minheap[(v-1)/2];
               minheap[(v-1)/2] = minheap[v];
               minheap[v] = temp;
               v = (v-1)/2;
               if (v==-1)
               {
                break;
               }
               
            }
            
             
        }
        else{
            // maxheap
           while (maxheap[(v-1)/2] < maxheap[v])
           {
            int temp =  maxheap[(v-1)/2];
               maxheap[(v-1)/2] = maxheap[v];
               maxheap[v] = temp;
               v = (v-1)/2;
               if (v==-1)
               {
                break;
               }
               
           }
           
        }
        
    }

};

int main()
{
    heap h;
    h.get();
    h.print();
}