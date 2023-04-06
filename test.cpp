#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>

class Student{
    private: 
        int code;
    public: 
        Student(int code) { 
            code = code;
        }
};

template <typename T1, typename T2>
T2 func1(T1 a, T2 b){
    return a + b;
}

int main()
{
    vector<int> myvector;
    for(int i = 0; i<3; i++) myvector.push_back(i+10);
    for(vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}