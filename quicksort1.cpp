#include<iostream>
#include <chrono>
#include <stack>
using namespace std::chrono;

using namespace std;
void swap(int &a,int &b){    //a function to do swapping where arguements are passed in passed by refernce method
    int temp=b;
    b=a;                        
    a=temp;
}
int pivot_position(int Arr[],int start,int pivot){   //finding the position of the pivot element imagining the list is sorted
    int pre_index=start-1;                           //here I have selected the last element as my pivot elemnt
    for(int j=start;j<pivot;j++){
        if (Arr[j] <= Arr[pivot]){
            pre_index++;
            swap(Arr[pre_index],Arr[j]);    
        }
    }
    pre_index++;
    swap(Arr[pre_index],Arr[pivot]);       //swpapping the pivot element with the element at the required position
    return pre_index;                   //returning the index of the pivot element
}
void quicksort(int Arr[],int start,int pivot){   //recursive quicksort function
    if (start<pivot){
    int pivot_index=pivot_position(Arr,start,pivot);
    quicksort(Arr,start,pivot_index-1);
    quicksort(Arr,pivot_index+1,pivot);
    }
}

void quicksort_iterative(int arr[], int start, int end) {  //iterative quicksort function
    stack<int> index_stack;    //initializing a stack to store boundary values

    index_stack.push(start);    //storing boundary values
    index_stack.push(end);

    while (!index_stack.empty()) {      //repeating the steps untill the list gets empty   
        end = index_stack.top();
        index_stack.pop();
        start = index_stack.top();
        index_stack.pop();

        int pivot = pivot_position(arr, start, end);   //finding the pivot position

        if (pivot - 1 > start) {
            index_stack.push(start);
            index_stack.push(pivot - 1);
        }

        if (pivot + 1 < end) {
            index_stack.push(pivot + 1);
            index_stack.push(end);
        }
    }
}


int main(){
    int arr_size=18000;
    double total_duration1 = 0;
    double total_duration2 = 0;
    for (int i = 0; i < 10; i++) {
    int rand_array[arr_size];         //initializing random array 
    int copy_array1[arr_size];        //initializing 2 copies of that array
    int copy_array2[arr_size];
    
    for(int i=0;i<arr_size;i++){         //creating the random array
        rand_array[i]=rand()%100;
    }
    for(int o=0;o<arr_size;o++){           //creating 2 copies
        copy_array1[o]=rand_array[o];
    }
    for(int o=0;o<arr_size;o++){
        copy_array2[o]=rand_array[o];
    }

    auto start1 = high_resolution_clock::now();        //time for recursive method
    quicksort_iterative(copy_array1,0,arr_size-1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    total_duration1 += duration1.count();
    

    auto start2 = high_resolution_clock::now();       //time for iterative method
    quicksort(copy_array2,0,arr_size-1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    total_duration2 += duration2.count();
    
    } 
    cout<<"size of the array: "<<arr_size<<endl;                //printing the output by taking an averege value for 10 executions
    cout <<"time for iterative method: "<<total_duration1/10 << endl;
    cout<<"size of the array: "<<arr_size<<endl;
    cout <<"time for recursive method: "<<total_duration2/10 << endl;

    return 0;
}
