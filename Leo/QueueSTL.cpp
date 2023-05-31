#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int main(){
    queue<int> s;
    s.push(2);
    s.push(5);
    s.push(15);
    s.push(25);
    s.push(35);
    cout << s.empty() << endl ;
    return 0;
}