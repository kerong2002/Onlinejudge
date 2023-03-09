#include <iostream>
#include <vector>
using namespace std;

bool check(const string &str, int left, int right){
    while(left < right){
        if(str[left] != str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(int argc, char **argv){
    int t = 0;
    cin >> t;
    while(t--){
        string input;
        cin >> input;
        vector<int> dp(input.size()+1,0);
        dp[1] = 1;
        for(int y=2;y<=input.size();y++){
            dp[y] = dp[y-1] + 1;
            for(int x=0;x<y;x++){
                if(check(input, x, y-1)){
                    dp[y] = min(dp[x]+1, dp[y]);
                }
            }
        }
        cout << dp[input.size()] << endl;
    }
    return 0;
}
