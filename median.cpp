#include<iostream>
#include<vector>
#include <sstream>
#include<string>
#include <algorithm>
#include <iomanip>

using namespace std;

void swap(int &a,int &b){
    int temp=b;
    b=a;
    a=temp;
}

int pivot_position(vector<int> &Arr,int start,int pivot){
    int pre_index=start-1;
    for(int j=start;j<pivot;j++){
        if (Arr[j] <= Arr[pivot]){
            pre_index++;
            swap(Arr[pre_index],Arr[j]);
        }
    }
    pre_index++;
    swap(Arr[pre_index],Arr[pivot]);
    return pre_index;
}

void quicksort(vector<int> &Arr,int start,int pivot){
    if (start<pivot){
        int pivot_index=pivot_position(Arr,start,pivot);
        quicksort(Arr,start,pivot_index-1);
        quicksort(Arr,pivot_index+1,pivot);
    }
}

int main(){
    string input;     //taking the array input as a string
    cin>>input;
    vector<int> input_list;
    stringstream ss(input);
    char ch;
    int num;
    while (ss >> ch ) {
        if(ch == '[' || ch == ',' || ch == ']') {   //excluding the other characters in the string
            continue;}
        ss.putback(ch);
        ss>>num;    
        input_list.push_back(num);  //getting the integers in the string to a vector
    }
 
    vector<int> integer_list ;
    for(int i=0;i<input_list.size();i++){            //updating a running array by taking one element at a time
        integer_list.push_back(input_list[i]);
        quicksort(integer_list,0,integer_list.size()-1);
        cout<<"sorted list : ";
        cout<<"[";
    for(int j=0;j<integer_list.size();j++){
        cout<<integer_list[j];
        if(j<integer_list.size()-1){
            cout<<',';
        }
    }
    cout<<']'<<"     ";

    double Median;
    if((integer_list.size())%2==1){
        int Median_index=(integer_list.size()/2 );        //calculating the median
        Median=integer_list[Median_index];
    }
    else{
        int pre_index=integer_list.size()/2-1;
        int past_index=integer_list.size()/2;
        Median=(integer_list[pre_index]+integer_list[past_index])/2.0;
    }
    cout<<"Median : ";
    cout << fixed << setprecision(1) << Median << endl;   //outputing at the given precision
    }
    return 0;
}






