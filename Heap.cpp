#include<bits/stdc++.h>
using namespace std;

// 10

class Heap {
    vector<int> arr;
    int size;

    public:
    Heap() {
        size = 0;
    }

    Heap(vector<int>& a) {
        arr = a;
        size = a.size();

        for(int i=size/2-1; i>=0; i--){
            heapify(i);
        }
    }

    void insert(int val){
        arr.push_back(val);
        int index = size;
        size++;

        reHeapUp(index);
    }

    int maxVal(){
        return ( size ? arr[0] : -1 );
    }

    int minVal() {

        if(size == 0)
            return -1;

        int minVal = *min_element(arr.begin() + (size / 2), arr.end());
        return minVal;
    }

    void heapify(int i){

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < size && arr[left] > arr[largest]){
            largest = left;
        }

        if(right < size && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void reHeapUp(int index){

        int parent = (index - 1) / 2;

        if(parent >= 0 && arr[parent] < arr[index]){
            swap(arr[parent], arr[index]);
            reHeapUp(parent);
        }
    }
};

int main(){

    int n;
    cout << "Enter No. of subjects: ";
    cin >> n;

    // Heap Creation
    Heap h;

    int marks = -1;
    for(int i=0; i<n; i++){
        cout << "Enter Marks for subject " << i+1 << ": ";
        cin >> marks;
        h.insert(marks);
    }

    cout << "Minimum Marks: " << h.maxVal() << endl;
    cout << "Maximum Marks: " << h.minVal() << endl;
    
    return 0;
}