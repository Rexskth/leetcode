class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string s="";
      int n=strs.size();
     
     vector<int> v;
      int min=INT_MAX;
      for(int i=0;i<n;i++){
         v.push_back(strs[i].size());
         
      }
      for(int i=0;i<n;i++){
          if(v[i]<min){
              min=v[i];
          }
      }
      bool f=true;
      int cnt=0;
      for(int m=0;m<min;m++)
      {
          for(int j=1;j<n;j++){
              if(strs[j-1][m]!=strs[j][m]){
                  f=false;
                  break;
              }
          
          }
          if(f){
              cnt++;
          }
      }
       s=strs[0].substr(0,cnt);
      return s;
    }
};