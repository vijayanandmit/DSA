int maxTrailing(int arr[], int n) {
    int maxDiff = -1, minVal = arr[0];

//when all elements are same, use a set<int> to check the size of set
//return -1, otherwise, it returns 0 as maxDiff

    for(int i = 1; i < n; i++) {
        int diff = arr[i] - minVal;
        if(diff > maxDiff) {
            maxDiff = diff;
        }
        if(arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return maxDiff;
}

/*
write cpp function maxTrailing which has input array, output integer maximum trailing difference or -1, if no element in arr has a lower earlier value
trailing difference is difference between any element and any prior smaller element

he function works by iterating through the array and keeping track of the minimum value seen so far. At each element, it calculates the difference between the current element and the minimum value seen 
so far. If this difference is greater than the current maximum difference, it updates the maximum difference. Finally, if the current element is less than the minimum value seen so far, it updates the 
minimum value.

If no element in the array has a lower earlier value, the minimum value will be the first element, so the maximum trailing difference will be -1 (since there is no prior smaller element). Otherwise, the 
maximum trailing difference will be returned. */

