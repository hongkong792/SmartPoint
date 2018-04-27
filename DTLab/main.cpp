#include <iostream>
#include "smartpoint.h"

using namespace std;
using namespace DTLab;

class Test
{
public:
    Test() {

        cout << "Test()" << endl;
    }
    ~Test(){
          cout << "~Test()" << endl;
    }
};

int main()
{
   SmartPoint<Test> sp = new Test();

    SmartPoint<Test> obj;

     obj = sp;
    // obj++;
      cout << sp.isNull() << endl;
      cout << obj.isNull() << endl;

    return 0;
}

