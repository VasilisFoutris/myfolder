#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

class cashier{

    public:
    
    cashier(){

        cout << "Cashiers opening\n" << endl;

    }

    ~cashier(){

        cout << "Cashiers closed for today\n" << endl;

    }

};


class bank{

    public:
    
    bank(){

        cout << "\nBank cosntruction phase\n" << endl;

    }

    ~bank(){
        
        cout << "Bank destruction phase\n" << endl;

    }

};


int construct_destruct(){

    bank obj1;
    cashier obj2;
    


return true;
}

int main(){
    
    construct_destruct();

}