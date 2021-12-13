#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

class cashier{

    public:
    
        int customers_served;
    
        cashier( int customers );

        int is_open();

        void open();

        void close();

        void serve();
    
        int is_free();

        void free();

        void open_flag();
        
        void serving_flag();

        ~cashier();


    private:

        int cust;
        int next;
        int *cashiers_serving;
        cashier *total_cashier;
      
};

cashier::cashier( int customers ){
    
    cust = customers;
    customers_served = 0;
    
    open();
    open_flag();
    serve();
    serving_flag();
    free();
    customers_served++;
    cout << "Customers served:"<< customers_served << endl;

    close();
}

cashier::~cashier(){
    
    cout << "Cashier has been destroyed\n" << endl;

}



void cashier::open(){

    cout << "Cashier is open!\n" << endl;

}

int cashier::is_open(){


  return 1;
}

void cashier::close(){

    cout << "Cashier is closed!\n" << endl;

}

void cashier::serve(){

    cout << "Cashier is serving!\n" << endl;

}

void cashier::free(){

    cout << "Cashier is free!\n" << endl;

}

int cashier::is_free(){



    return 1;
}

void cashier::open_flag(){

    if( is_open ){

        cout << "Cashier open\n" << endl;
        open();
        
    }
}

void cashier::serving_flag(){

    if( is_free ){

        free();

    }
    else{

        cout << "Cashier currently serving another customer\n" << endl;
        
    }

}

class bank{

    public:
    
        bank( int cust );
        
        int curr_serving( int customers );

        int chack_to_open();

        int check_to_close();

        int waiting_customers();

        int enter();

        int exit();

        ~bank();

    private:

        cashier cashier1;
        cashier cashier2;
        cashier cashier3;
        cashier cashier4;
        cashier cashier5;

};


bank::bank( int customers ) : cashier1 ( customers ), cashier2 ( customers ), cashier3( customers ), cashier4( customers ), cashier5( customers ) {
    
    int last_customer = 1;
    int first_paper = 1; 

    cout << "\nCustomers:" << endl;
    cin >> last_customer ;

    cout << "\n" << endl;
    cout << "-------------------------" << endl;
    cout << "First paper is : " << first_paper << endl;
    cout << "\n" << endl;

    for( int curr_serving = 1; curr_serving <= last_customer; curr_serving++ ){
        
        cout << "Currently serving: " << curr_serving << endl;
        cout << "\n" << endl;

    }

}

int bank::curr_serving( int customers ){

    return 0;
}

int bank::chack_to_open(){

    return 0;
}

int bank::check_to_close(){

    return 0;
}

int bank::waiting_customers(){

    return 0;
}

int bank::enter(){

    return 0;
}

int bank::exit(){

    return 0;
}

bank::~bank (){

    cout << "Bank destruction phase\n" << endl;

}

int main(){
    
    int n;

    bank b1(10);

    return 0;
}