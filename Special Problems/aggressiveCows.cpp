//Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.
// Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

// Examples:
// Input: arr[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.

#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& arr, int k, int dist)
{
    int cows = 1;
    int last = arr[0];

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] - last >= dist)
        {
            cows++;
            last = arr[i];
        }
    }

    return cows >= k;
}

int aggressiveCows(vector<int>& arr, int k)
{
    sort(arr.begin(), arr.end());

    int maxDist = arr.back() - arr.front();

    int ans = 0;

    for(int dist = 1; dist <= maxDist; dist++)
    {
        if(canPlace(arr, k, dist))
        {
            ans = dist;
        }
    }

    return ans;
}

//Approach 2: Binary Search --> Submitted

class Solution {
public:
    bool canPlace(vector<int>& arr, int k, int dist)
    {
        int cows = 1;
        int last = arr[0];

        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] - last >= dist)
            {
                cows++;
                last = arr[i];
            }
        }

        return cows >= k;
    }

    int aggressiveCows(vector<int>& arr, int k)
    {
        sort(arr.begin(), arr.end());

        int low = 1;
        int high = arr.back() - arr.front();
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(canPlace(arr, k, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};
