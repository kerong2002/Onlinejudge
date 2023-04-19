//2023/04/19 kerong
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_MONEY 5000000
using namespace std;
int main(){
    int T = 0;
    cin >> T;
    while(T--){
        long long int total = 0;
        int land[41] = {0};
        int cnt = 0;
        while(true){
            cin >> land[cnt];
            if(land[cnt]==0){
                break;
            }
            else{
                cnt++;
            }
        }
        sort(land, land + cnt, greater<int>());
        for(int x=0;x<cnt;x++){
            if(total >= MAX_MONEY){
               break;
            }
            total += 2 * (int)pow(land[x],x+1);

        }
        if(total >= MAX_MONEY){
            cout << "Too expensive" << endl;
        }
        else{
            cout << total << endl;
        }
    }
    return 0;
}
