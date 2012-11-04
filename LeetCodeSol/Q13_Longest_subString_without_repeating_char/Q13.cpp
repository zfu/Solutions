#include <iostream>
#include <string>
using namespace std;
void cleanmap(bool charmap[], int n){
    for(int i = 0; i < n; i++){
        charmap[i] = false;
    }
}
int longestSubString(string str){
    int size = 256;
    bool charmap[size];
    int maxLength = 0;
    int currLength = 0;
    string longest;
    string curr;
    for(int i = 0; i < str.length(); i++){
        if(charmap[str[i]] == false){
            charmap[str[i]] = true;
            curr.push_back(str[i]);
            currLength++;
            if(currLength >= maxLength){
                maxLength = currLength;
                longest = curr;
            }
        }else{
            curr.clear();
            cleanmap(charmap, size);
            curr.push_back(str[i]);
            currLength = 1;
            charmap[str[i]] = true;
        }
    }
    cout << longest << endl;
    return maxLength;
}


int main(){
    //string str("abcabcbb");
    string str("bbb");
    int len = longestSubString(str);
    cout << len << endl;
    return 0;
}
