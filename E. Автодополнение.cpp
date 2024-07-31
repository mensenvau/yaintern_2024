#include <bits/stdc++.h>
using namespace std;
struct Item {
    int index;
    string name;
    int value;
};
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
void insert(TrieNode* root, string& str, int& index){ 
    TrieNode* current = root; 
    for (auto c : str) { 
        if (current->childNode[c - 'a'] == NULL) { 
            TrieNode* newNode = new TrieNode(); 
            current->childNode[c - 'a'] = newNode;
        }
        current->items.push_back(index); 
        current = current->childNode[c - 'a'];
    }
    current->items.push_back(index); 
    current->end = 1;
}

int search(TrieNode* root, string& str){ 
    TrieNode* current = root; 
    for (auto c : str) { 
        if (current->childNode[c - 'a'] == NULL) { 
            return -1;
        }
        current = current->childNode[c - 'a'];
    }
    
    return current->items[0]; 
}
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    // declare && read
    TrieNode* root = new TrieNode();
    int n, q;
    in>>n>>q;
    vector<Item> data; 
    
    for(int i=0;i<n;i++){
       Item t; 
       in>>t.name>>t.value; 
       t.index = i + 1;
       data.push_back(t);
    }
    
    // sort
    sort(data.begin(), data.end(), [](const Item& a, const Item& b) {
        return a.value > b.value;
    });
    
    for(int i=0;i<n;i++){ 
        insert(root, data[i].name, data[i].index); 
        //cout<<data[i].name<<" "<<data[i].value<<endl;
    }
    
    string s = "";
    char p, k;
    
    for(int i=0; i<q; i++){
      in>>k;
      if(k=='+') { in>>p; s.push_back(p); } else { s.pop_back();  }
      out<<search(root, s)<<endl;
    }
}


