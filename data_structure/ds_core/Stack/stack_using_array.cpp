#include<bits/stdc++.h>
using namespace std;

class myStack{
    public:
        vector<int> v;

        void push(int val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();
        }

        int top(){
            return v.back();
        }

        int size(){
            return v.size();
        }

        bool empty(){
            if(v.size() == 0)
                return true;
                else
                    return false;
        }
};

int main(){

    myStack stk;

    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        stk.push(x);
    }

    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
    
    return 0;
}