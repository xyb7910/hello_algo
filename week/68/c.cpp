#include <bits/stdc++.h>
using namespace std;
int main() {
    string str; cin >> str;
    set<char> s;
    for (int i = 0; i < str.size(); i ++)
    {
        if(isalpha(str[i])) s.insert(tolower(str[i]));
        else s.insert(str[i]);
    }
    cout << s.size();
    return 0;
}