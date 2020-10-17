class Solution {
public:
    
    int peakIndexInMountainArray(vector<int>& arr) {
        
        // Solution 1: Linear Scan
        // for(int i = 1; i < arr.size()-1; i++){
        //     if (arr[i] > arr[i-1] && arr[i] > arr[i+1])
        //         return i;
        // }
        // return 1; // Never Executed
        
        // Solution 2: Binary Search
        // int lo = 1;
        // int hi = arr.size() - 2;
        // while(lo <= hi){
        //     int mid = lo + (hi - lo)/2;
        //     if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
        //         return mid;
        //     else if (arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1])
        //         lo = mid+1;
        //     else
        //         hi = mid-1;
        // }
        // return 1; // Never Executed
        
    }
};
