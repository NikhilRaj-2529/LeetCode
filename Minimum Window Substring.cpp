// Leet Code POTD FEB - 04
// 76
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        if(t == s) return t;
        string ans="";
        map<char,int>mp;
        map<char,int>mpp;
        for(int i=0;i<t.size();i++) mp[t[i]]++;
        string temp;
        for(int i = 0 ;i < s.size() ; i++){
            temp+=s[i];
            if(mp[s[i]] > 0){
                mpp[s[i]]++;
                int f = 1;
                for(auto it : mp){
                    if(mpp[it.first] < it.second){
                        f = 0;
                        break;
                    }
                }
                if(f==1){
                    if(ans == "") ans = temp;
                    else if(ans.size() > temp.size()) ans = temp;
                    while(mp[temp[0]] < 1 or mpp[temp[0]] > mp[temp[0]]){
                        if(mpp[temp[0]] > 0) mpp[temp[0]]--;
                        temp.erase(0,1);
                        if(ans.size() > temp.size()) ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};
