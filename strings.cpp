#include <iostream>
using namespace std;


int main(){
    int list[4] = {0}; // init = 0
    string mans[] = {"a", "b", "c", "d", "e", "f"};
    list[3] = 69;

    cout << sizeof(list) / 5 << endl;
    cout << sizeof(mans) / sizeof(mans[0]) << endl;
    cout << sizeof(mans) / sizeof(string) << endl;
    return 0;
}
