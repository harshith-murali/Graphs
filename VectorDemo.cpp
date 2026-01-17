#include <iostream>
#include<vector>
using namespace std;
void vectorChange(vector<int> &vec){
    for(int &it : vec){
        it *= 2;
    }
}
void vectorChangeWrong(vector<int> vec){
    for(auto it : vec){
        it *= 2;
    }
}
int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};
    vectorChangeWrong(myVector);
    for(int val : myVector){
        cout << val << " ";
    }
    cout << endl;
    vectorChange(myVector);
    for(int val : myVector){
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}