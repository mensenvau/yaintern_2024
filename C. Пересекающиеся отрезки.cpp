#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
   
    int n, x, y, res = 0;
    vector<vector<int>>tm;
    unordered_set<int> st;
    
    in>>n;
    for(int i=0;i<n;i++){
        in>>x>>y;
        tm.push_back({ x, y });
    }
    
    sort(tm.begin(), tm.end());
    
    int last_end = tm[0][1];
    for(int i=1;i<n;i++){
       if(tm[i][1]<=last_end || tm[i][0] == tm[i-1][0]) st.insert(i);
       last_end = max(last_end, tm[i][1]);
    }
    
    last_end = tm[n-1][1];
    for(int i=n-2;i>=0;i--){
       if(tm[i][1]>=last_end || tm[i][0] == tm[i+1][0]) st.insert(i);
       last_end = min(last_end, tm[i][1]);
    }
    
    out<<n - st.size();
}