#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define sz(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

const long long MOD = 1e9 + 7;
const long long BASE = 31;
const int LEN = 3e3;
const int N = 2e3 + 1;
long long p[LEN + 1];

struct Line{
    int len;
    string str;
    long long prefix;
    int prefix_len;
    int start_pos;
    long long * hashAt;
    bool valid; 

    Line(){
        len = 0;
        hashAt = NULL;
        prefix = 0;
        prefix_len = 0;
        start_pos = 0;
        valid = false;
    }


    int size(){
        return len;
    }


    void resize(int newSize){
        if(len < newSize && hashAt != NULL){
            delete[] hashAt;
            hashAt = NULL;
        }
        len = newSize;
        if(hashAt == NULL)
            hashAt = new long long[len + 2];
    }


    void set(string s){
        str = ' ' + s + ' ';
        resize(sz(s));
        calc_hash();
        init_prefix();
        init_valid();
    }


    void init_valid(){
        valid = true;
        for(int i = prefix_len + 1;i<len;i++){
            if(str[i] == '.' && dict.find(hashAt[i-1]) == dict.end()){
                valid = false;
                return;
            }
        }
    }


    void init_prefix(){
        start_pos = len;
        int cur = start_pos;
        prefix = 0;
        prefix_len = 0;
        for(int i = 0;i<len;i++){
            if(str[cur] == '.') break;
            prefix = (prefix * BASE + (str[i] - 'a')) % MOD;
            prefix_len++;
        }
    }


    void dec_start_pos(){
        start_pos--;
        prefix = ((str[start_pos] - 'a')  * p[prefix_len] * prefix) % MOD;
        prefix_len++;
    }


    void calc_hash(){
        hashAt[0] = 0;
        for(int i = 1;i<=len;i++){
            hashAt[i] = (hashAt[i - 1] * BASE + (str[i] - 'a')) % MOD;
        }
    }


    ~Line(){
        delete[] hashAt;
    }


    friend istream& operator >> (istream & in, Line& line){
        string s;
        in >> s;
        line.set(s);
        return in;
    }
};

set<long long> dict;
Line lines[N];


long long hashOf(string s){
    long long code = 0;
    for(int i = 0;i < sz(s);i++){
        code = (code * BASE + (s[i] - 'a')) % MOD;
    }
    return code;
}

int main(){
    ios::sync_with_stdio(0);
    p[0] = 1;
    for(int i = 1;i<=LEN;i++){
        p[i] = (p[i-1] * BASE) % MOD;
    }
    int n,m;
    while(cin >> m){
        string wrd;
        for(int i = 0;i<m;i++){
            cin >> wrd;    
            dict.insert(hashOf(wrd));
        }
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> lines[i];
        }

    }
    return 0;
}
