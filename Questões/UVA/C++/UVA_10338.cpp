#include <bits/stdc++.h>
using namespace std;

#define llu unsigned long long

int main() {
    int ds; cin >> ds;
    string word;

    llu fat[21]; fat[0] = 1;
    for (int i = 1; i < 21; i++) fat[i] = fat[i-1] * i;

    for (int i = 1; i <= ds; i++){
        cin >> word;
        
        vector<int> freq(26, 0);
        int t = word.size();
        for(int i = 0; i < t; i++) freq[word[i] - 'A']++;
        cout << "Data set " << i << ": ";

        llu s = fat[t];

        for(int i = 0; i < 26; i++) s /= fat[freq[i]];      
        cout << s << "\n";        
    }

    return 0;
}