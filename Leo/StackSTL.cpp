// * Stack using STL library

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <memory>
#include <stack>

using namespace std;

int TestStack(string string_test){
    stack <char> s;
    for (int i = 0; i < string_test.length(); i++){
        if (string_test[i] == '(' || string_test[i] == '{' || string_test[i] == '[') {
            s.push(string_test[i]);
        } 
        else if (string_test[i] == ')' || string_test[i] == ']' || string_test[i] == '}'){
            if ((string_test[i] == ')') && s.top() != '(') {
                return -1;
            }
            else if ((string_test[i] == ']') && (s.top() != '[')) {
                return -1;
            }
            else if ((string_test[i] == '}') && (s.top() != '{')) {
                return -1;
            }
            else {
                s.pop();
            }
        }
    }
    if (!s.empty()) {
        return -1;
    }
    return 1;
}
    


int main(){
    auto start = std::chrono::steady_clock::now();

    string test1 = "{{{{}}}[][]((())";    // * False
    string test2 = "(%TT{>><]]]%%%%%%)";  // * False
    string test3 = "(((((()))))){}{}{}[][][][[[]]]"; // * True
    string test4 = "{{{@23+6767}}}*<45>(a+b)[]"; // * True
    string test5 = "(a+b)"; // * True
    string test6 = "(((((a+b %%%%%####3422222222222)))))[]{}[]"; // * True
    string test7 = "[[[{{()}}]]]"; // * True
    string test8 = "((((((}}}}}}"; // * False
    string test9 = "Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$)"; // * True
    string test10 = "@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%% "; // * True
    string test11 = "<<<<<{{{{[@@@@((((%%%%%%............))))]]]*****######!!!!!!!}}}}>>>>>"; // * False
    string test12 = "(((()()()())[{}]))[[[]]]{[[()()][]]}"; // * True
    string test13 = "(((([[{{((()))}}]]]))))([{<>}])"; // * False
    string test14 = "((((({[((([])))][{(())}]})}))))"; // * False
    string test15 = "((((({[2312((123([2131])*))][{(())}]})}))))"; // * False
    string test16 = "((((({[2312((123([2131])*))][{(())}]}2312((123([2131"; // * False
    
    // cout << TestStack(test10) << endl;
    // cout << TestStack(test11) << endl;
    // cout << TestStack(test12) << endl;
    // cout << TestStack(test13) << endl;
    // cout << TestStack(test14) << endl;

    cout << "Result for test case 15: ";
    cout << TestStack(test5) << endl;

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " us (microsecond)" << std::endl;

    // get memory consumption
    std::unique_ptr<int[]> ptr(new int[1024 * 1024]);
    std::cout << "Memory usage: " << 1024 * 1024 * sizeof(int) << " bytes" << std::endl;
    return 0;
}