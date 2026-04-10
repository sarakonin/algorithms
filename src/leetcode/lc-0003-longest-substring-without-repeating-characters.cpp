#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.compare("")==0) {
            return 0;
        }
        int maxc=1;
        int c=1;
        bool f=false;
        int k=0;
        int sp=0;
        for(int i=0;i<s.size();i++){
            if(i<s.size()-1){
                for (int j=k;j<i+1;j++) {
                    if (s[j]==s[i+1]) {f=true; sp=j; break;}
                    c++;
                }
                if (f) {
                    k=sp+1;
                    c=1;
                    f=false;
                 }
                if (c>maxc) maxc=c;
                c=1;
            }
        }
        return maxc;
    }
};

/* notes:
 * sp (second position) resetira pozicija na start od nov podstring
 * bez ova pagja na tc dvdf (podstringot zamisli go kako podvizen prozorec, a ne kako del od string)
 * isto brojacot (c) raboti ako broi vo loop-ot za sporedbi i se resetira na kraj
*/

int main() {
    string s;
    cin>>s;
    Solution sol;
    printf("%d",sol.lengthOfLongestSubstring(s));
    return 0;
}