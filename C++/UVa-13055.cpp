//2023/04/19 kerong
#include <iostream>
#include <stack>
using namespace std;
int main(){
    int T = 0;
    cin >> T;
    stack<string> s;
    while(T--){
        string oper;
        cin >> oper;
        if(oper == "Sleep"){
            string name;
            cin >> name;
            s.push(name);
        }
        else if(oper == "Test"){
            if(!s.empty()){
                cout << s.top() << endl;
            }
            else{
                cout << "Not in a dream" << endl;
            }
        }
        else if(oper == "Kick"){
            if(!s.empty()){
                s.pop();
            }
        }
    }
    return 0;
}
