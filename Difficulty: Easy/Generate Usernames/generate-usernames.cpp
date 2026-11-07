class Solution {
  public:
    int n;
    unordered_map<string,int> mp;

    string fun(string t){
        int ct=1;
        string s;

        while(1){
            s=t+to_string(ct++);
            if(!mp.count(s)) break;
        }

        return s;
    }

    vector<string> generateUsernames(vector<string> arr) {
        n=arr.size();
        vector<string> v(n,"");

        for(int i=0;i<n;i++) if(!mp.count(arr[i])) v[i]=arr[i],mp[v[i]]++;
        for(int i=0;i<n;i++) if(v[i]=="") v[i]=fun(arr[i]),mp[v[i]]++;

        return v;
    }
};

