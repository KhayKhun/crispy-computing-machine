#include <iostream>
using namespace std;

void swap(string &x, string &y); // manipulate memory

int oddSum(string s){
    int t;
    for(int i = s.size() - 1; i >= 0; i-=2){
        t += s[i] - '0'; // ASCII value 0f 0 is 48
    }
    return t;
}
int evenSum(string s)
{
    int total = 0;
    for(int i = s.size() - 2; i >= 0; i-=2){
        int n = (s[i] - '0') * 2;
        total += n < 10 ? n : 1 + n % 10;
    }
    return total;
}

int main(){
    string s = "6011000990139424";
    int res = evenSum(s) + oddSum(s);
    bool isValid = res%10 == 0;
    cout << s <<(isValid ? " is a valid number" : "is not a valid number") << endl;
    return 0;
}
