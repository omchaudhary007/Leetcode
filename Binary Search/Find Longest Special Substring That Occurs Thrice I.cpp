// problem link:- https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/
/* 
 Logic:- 
 1.Use binary search to find the answer if a K is possible then all K-1 will be possible so use binary search.
 2. To check K is possible or not we need to check whether do we have 3 k-size same substring or not.
 3. Each time we need to find same element subarray of size k.
 4. To get this we can use a map of all character to store count of all string of char element.
 5. Run loop to count all subarray of k size with same element. 
 6. Each time if currentElement!=startElem then increase startElem because we need same element window.
 7. If i-start+startElem>= k it means we got an K size subarray with same element so increase this char element count in map.
 8. If count[char]>2 it means we got 3 same size and same element subarray.
*/
// T.c=O(nlogn) s.c=O(26logn)=O(logn)

class Solution {
public:
    bool isExists(string &s,int size){
        vector<int>count(26,0);
        int windowStart=0;
        for(int i=0;i<s.size();i++){
            while(s[windowStart]!=s[i]) windowStart++;
            if(i-windowStart+1>=size) count[s[i]-'a']++;
            if(count[s[i]-'a']>2) return true;
        }
        return false;
    }
    int maximumLength(string s) {
       int minSize=0,maxSize=s.size();
       int ans=0;
       if(!isExists(s,1)) return -1;
       while(minSize<=maxSize){
          int size=minSize+(maxSize-minSize)/2;
          if(isExists(s,size)){
            ans=size;
            minSize=size+1;
          }
          else
          maxSize=size-1;
       }
       return ans;
    }
};
