#include<bits/stdc++.h>
using namespace std;
const int N=2e5+12;
vector<int>build_lps(string p){
    int m = p.size();
    vector<int> lps(m+1);
    int j = 0;
    lps[0] = 0;
    for(int i = 1; i<m ; i++){
       while(j >= 0 && p[i] != p[j]){
        if(j > 0) j = lps[j-1];
        else j = -1;
       }
       j++;
       lps[i] = j;
    }
    return lps;
}
vector<int> ans;
void kmp(string s, string p, vector<int>lps){
    
    int n = s.size(), m = p.size();
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j >= 0 && p[j] != s[i]){
            if( j > 0)j = lps[j-1];
            else j = -1;
        }    
            j++;
            if(j == m){
                j = lps[j-1];
                ans.push_back(i - m + 1);
            }
        
    }
}
int main(){

    string s,p;
    cin >> s >> p;
    vector<int>lps=build_lps(p);
    kmp(s,p,lps);
    if(ans.size()){
        cout << ans.size() << endl;
        for( auto u : ans)cout << u+1 << " ";
        cout << endl ;
    }
    else cout  << "Not Found" << endl;
   
}