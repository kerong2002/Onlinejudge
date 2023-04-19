//2023/04/19
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string a, b;
	while(cin >> a >> b){
		if(stoi(a) == 0 && stoi(b) == 0){
			break;
		}
		int carry = 0;
		int ans = 0;
		int f = a.size()-1;
		int s = b.size()-1;
		while(f>=0 || s>=0 || carry>0){
            int f_num = 0;
            int s_num = 0;
            if(f>=0){
                f_num = a[f]-'0';
            }
            if(s>=0){
                s_num = b[s]-'0';
            }



            if(carry > 0){
                ans += 1;
            }
            carry = (f_num + s_num + carry)/10;
            f--;
            s--;
		}
		if(ans){
            cout << ans;
		}
		else{
            cout << "No";
		}
		cout << " carry operation";
		cout << (ans > 1 ? "s." : ".") << endl;
	}
	return 0;
}
