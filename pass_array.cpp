#include <iostream>
#include <cmath>
using namespace std;

// function decorations
int search(double l[], double target, int size);
double getSum(double l[], int size);
bool binarySearch(double list[], double target, int size) ;
void bubbleSort(double list[], int size);

int main()
{
    double list[15] = {5,6,7,3,2,1,9,10,6};
    fill(list + 10, list + 15, 69); // (begin, end, value)
    int size = sizeof(list) / sizeof(double);
    // cout << getSum(list, size) << endl;
    // cout << search(list,99, size) << endl;
    
    bubbleSort(list,size);
    for(double n: list){
        cout << n << " ";
    }
    double target = 69;
    cout << (binarySearch(list,target,size) ? "Found target!" : "Target not found!") << endl;

    return 0;
}

double getSum(double l[], int size){
    int total = 0;
    for(int i = 0; i < size; i ++){
        total += l[i];
    }
    return total;
}

int search(double l[], double target, int size){
    for(int i = 0; i < size; i ++){
        if(l[i] == target) return i;
    }
    return -1;
}

bool binarySearch(double list[], double target, int size){
    int l = 0;
    int r = size-1;
    
    while(l <= r){
        int mid = l + (r - l) / 2;

        if(list[mid] > target) r = mid - 1;
        else if(list[mid] < target) l = mid + 1;
        else return true;
    }

    return false;
}

void bubbleSort(double list[], int size){
    double temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(list[j] > list[j + 1]){
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
