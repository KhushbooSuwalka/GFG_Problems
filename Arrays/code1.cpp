#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int target){
    for(int i=0;i<n;i++){  
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int target;
    int arr[5];
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter 5 numbers: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the target number: ";
    cin>>target;

    int result = linearSearch(arr,n,target);

    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }

    return 0;
}