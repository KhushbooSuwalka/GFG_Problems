//Median of two sorted arrays of same size
//Given two sorted arrays a[] and b[] of equal size, find and return the median of the combined array after merging them into a single sorted array.

// Examples:
// Input: a[] = [-5, 3, 6, 12, 15], b[] = [-12, -10, -6, -3, 4]
// Output: 0
// Explanation: The merged array is [-12, -10, -6, -5, -3, 3, 4, 6, 12, 15]. So the median of the merged array is (-3 + 3) / 2 = 0.

#include<bits/stdc++.h>
using namespace std;

double getMedian(vector<int>& a, vector<int>& b) {
  
    // Concatenate
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    // Sort the concatenated array
    sort(c.begin(), c.end());
    
    // Calculate and return the median
    int n = c.size();
  	
    int mid1 = n / 2;
    int mid2 = mid1 - 1;
	return (c[mid1] + c[mid2]) / 2.0;
}

//Approach 2 :- Using Merge of Merge Sort

double getMedian(vector<int>& a, vector<int>& b) {
  	
  	int n = a.size();
    int i = 0, j = 0;
    int count;
  
    // m1 to store element at index n of merged array
    // m2 to store element at index (n - 1) of merged array
    int m1 = -1, m2 = -1;

    // Loop till n
    for (count = 0; count <= n; count++) {
        m2 = m1;
      
        // If both the arrays have remaining elements
        if (i < n && j < n) {
            if (a[i] > b[j])
                m1 = b[j++];
            else
                m1 = a[i++];
        }
        
      	// If only a has remaining elements
        else if (i < n)
            m1 = a[i++];
      	
        // If only b has remaining elements
        else 
            m1 = b[j++];
    }

    return (m1 + m2) / 2.0;
}

//Approach 3 :- Using Binary Search

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int low=0;
        int n=a.size();
        int high=n;
        int mid1,mid2;
        
        while(low<=high){
            mid1=(low+high)/2;
            mid2 =n-mid1;
            
            int l1=(mid1==0 ? INT_MIN : a[mid1-1]);
            int r1=(mid1==n ? INT_MAX : a[mid1]);
            
            int l2=(mid2==0 ? INT_MIN : b[mid2-1]);
            int r2=(mid2==n ? INT_MAX : b[mid2]);
            
            if(l1<=r2 && l2<=r1){
                return (max(l1,l2) + min(r1,r2))/2.0;
            }
            
            if(l1>r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
            
        }
        
        return 0;
    }
};


