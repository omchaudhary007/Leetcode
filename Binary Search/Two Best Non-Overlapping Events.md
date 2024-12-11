# 2054. Two Best Non-Overlapping Events

**Problem:-** We have an array of event consist of [start, end, value] where start and end is inclusive. We need to find maximum possible value by attending at most 2 non-overlapping event.

**Requirement of question:-** 

1. Each time we need second event which is non-overlapping means 2nd event should have startTime₂>endTime₁
2. For every 1st event we need to find second non-overlapping event which has highest value.
3. We need  maximum value of 1st event and 2nd event.

**Using Binary search+ Sorting+ Suffix Array:-** 

1. For first requirement sort array so that we can get 2nd event easily in less Time.
2. To get highest possible value of second event we will maintain a suffix array which will hold maximum possible value till i-th index event.
3. We will run a loop and for every i-th event we will find non-overlapping event with highest value from i+1th to n-1th using binary search.
4. Each time we will update maxSum with value1+value2.

**Time complexity=O(2nlogn) and space complexity=O(n)**

**Code:-** 

```cpp
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
      int n=events.size(),maxValue=0;
      sort(events.begin(),events.end());
      vector<int>maxtill_Index(n);
      maxtill_Index[n-1]=events[n-1][2];
      for(int i=n-2;i>=0;i--){
         maxtill_Index[i]=max(events[i][2],maxtill_Index[i+1]);
      }
      for(int i=0;i<n;i++){
        int secondIndex=-1;
        int start=i+1,end=n-1;
        while(start<=end){
          int mid=start+(end-start)/2;
          if(events[mid][0]>events[i][1]){
              secondIndex=mid;
              end=mid-1;
          }
          else
          start=mid+1;
        }
        if(secondIndex!=-1){
         maxValue=
         max(maxValue,events[i][2]+maxtill_Index[secondIndex]);
        }
        maxValue=max(maxValue,events[i][2]);
      }
      return maxValue;
    }
};
```
