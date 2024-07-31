#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3") // Use -O3 optimization level for GCC
#pragma GCC target("sse4.2") // Target SSE 4.2 instruction set for better performance


int find(const string& str){
    unsigned int res = 0;
    char c = 'R';
    
    for(int i=0; i < str.size(); i++){
        if(str[i] == 'F') {
            if(c == 'R') res++; else res--;
        } else {
            c = str[i];
        }
    }
    
    return res;
}
int main() {
    ios::sync_with_stdio(0);
 
    ifstream in("input.txt");
    ofstream out("output.txt");
 
    cin.tie(0);
    in.tie(0); 
    
    unsigned int n; 
    string str;
    unordered_set<int> st;
    
    in>>n>>str;  
    
    for (unsigned int i = 0; i < str.size(); i++) {
        char original_char = str[i];
        for (char new_char : {'F', 'R', 'L'}) {
            if (original_char != new_char) {
                str[i] = new_char;
                st.insert(find(str));
            }
        }
        str[i] = original_char;
    }
    
    out<<st.size();
}