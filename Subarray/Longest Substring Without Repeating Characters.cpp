// link:- https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0,longest=0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i]) && mp[s[i]]>=l) l=mp[s[i]]+1;
            mp[s[i]]=i;
            longest=max(longest,i-l+1);
        }
        return longest;
    }
};
