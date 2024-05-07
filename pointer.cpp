#include <iostream>
using namespace std;   

int main(){
    string name = "Khun";
    string *pName = &name;
    int nums[5] = {1,2,3,4,5};

    int *pNums = nums;

    int *np = nullptr;
    int x = 123;

    np = &x;
    if(np == nullptr){
        cout << "Address not assigned" << endl;
    }else{
        cout << "Address assigned -> " << *np << endl;
    }
    // cout << pName << " " << *pName << ' ' << sizeof(pName) << endl;
    // cout << pNums << " " << *pNums << ' ' << sizeof(pNums) << endl;
    return 0;
}