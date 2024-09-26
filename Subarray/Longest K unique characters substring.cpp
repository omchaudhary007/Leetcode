// problem link:-https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
/* logic:- 
  maintain count of unique letters and there last occuerence and when unique letters>k then remove one most leftest character occurences to get longest size
*/

class Solution{
  public:
    int longestKSubstr(string s, int k) {
       vector<int>letters(26,-1);
       int l=0,n=s.size();
       int longest=0;
       for(int i=0;i<n;i++){
          if(letters[s[i]-'a']==-1) k--;
          letters[s[i]-'a']=i;
          if(k<0){
            l=n;
            int mini=n;
            for(int j=0;j<26;j++){
                if(letters[j]!=-1) l=min(l,letters[j]);
            }
            l=l+1;
            for(int j=0;j<26;j++){
                if(letters[j]!=-1 && letters[j]<l) letters[j]=-1,k++;
            }
          }
          if(k==0)
          longest=max(longest,(i-l+1));
       }
       if(longest==0) return -1;
       return longest;
    }
};
