#include <iostream>
#include <queue>
using namespace std;

int main() {
    int size = 0;
    cout << "Enter the number of size of dataset." << endl;
    cin >> size;
    int data[size];

    priority_queue<int, vector<int>, greater<int>> top;
    priority_queue<int> bottom;
    for(int i = 0; i < size; i++) {
        int temp = 0;
        cin >> temp;
        if(i < size/2) {
            bottom.push(temp);
        } else {
            top.push(temp);
        }
    }
    if(size%2 == 0) {
        int med = top.top() + bottom.top();
        cout << med/2 << endl; 
    } else {
        cout << top.top() << endl;
    }
}