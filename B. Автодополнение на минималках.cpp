#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
    TrieNode* childNode[26];
    bool end;
    vector<int> items; 
    TrieNode()
    {
        end = false;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string& str, int& id){ 
    TrieNode* current = root; 
    for (auto c : str) { 
        if (current->childNode[c - 'a'] == NULL) { 
            TrieNode* newNode = new TrieNode(); 
            current->childNode[c - 'a'] = newNode;
        }
        current->items.push_back(id); 
        current = current->childNode[c - 'a'];
    }
    current->items.push_back(id); 
    current->end = 1;
}

int search(TrieNode* root, string& str, int &n){ 
    TrieNode* current = root; 
    for (auto c : str) { 
        if (current->childNode[c - 'a'] == NULL) { 
            return -1;
        }
        current = current->childNode[c - 'a'];
    }
    
    if(n - 1 < current->items.size()) return current->items[n - 1]; 
    return -1;
}
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    unordered_map<string, int> ids;
    
    // declare && read
    TrieNode* root = new TrieNode();
    int n, q;
    in>>n>>q;
    vector<string> strs(n);
    
    for(int i=0;i<n;i++){
       in>>strs[i];
       ids[strs[i]] = i + 1;
    }
    
    // sort
    sort(strs.begin(), strs.end());
    for(int i=0;i<n;i++){ 
        insert(root, strs[i], i); 
        // cout<<strs[i]<<endl;
    }
    
    string p;
    int k;
    for(int i=0; i<q; i++){
       in>>k>>p;
       int res = search(root, p, k);
      // cout<<"this -> "<<p<<" "<<search(root, p, k)<<endl;
       if(res == -1) cout<<-1<<endl;
       else cout<<ids[strs[res]]<<endl;
    }
}