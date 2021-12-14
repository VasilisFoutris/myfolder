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

        int open();

        int close();

        int serve();
    
        int is_free();

        int free();

        int open_flag();
        
        int serving_flag();

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
        
    int last_customer = 1;
    int first_paper = 1; 
    
    cout << "\nCustomers:" << endl;
    cin >> customers ;
    
    last_customer = customers;

    
    
        

        
    

   

    cout << "\n" << endl;
    cout << "-------------------------" << endl;
    cout << "First paper is : " << first_paper << endl;
    cout << "\n" << endl;

    for( int curr_serving = 1; curr_serving <= last_customer; curr_serving++ ){
        
        
        open();
        open_flag();
        cout << "-------------------------" << endl;
        cout << "Currently serving number: " << curr_serving << endl;
        cout << "-------------------------" << endl;
        cout << "\n" << endl;

        serve();
        serving_flag();
        free();
        customers_served++;

    }
    cout << "-------------------------" << endl;
    cout << "Customers served:"<< customers_served << endl;
    cout << "\n" << endl;

    close();
    
}

cashier::~cashier(){
    
    cout << "Cashier has been destroyed\n" << endl;

}



int cashier::open(){

    cout << "Cashier is open!\n" << endl;

    return 0;
}

int cashier::is_open(){


  return 0;
}

int cashier::close(){

    cout << "Cashier is closed!\n" << endl;

    return 0;
}

int cashier::serve(){

    cout << "Cashier is serving!\n" << endl;

    return 0;
}

int cashier::free(){

    cout << "Cashier is free!\n" << endl;
    
    return 0;
}

int cashier::is_free(){

    cout << "Free cashier found!\n "<< endl;

    return 0;
}

int cashier::open_flag(){

    if( is_open() == true ){

        cout << "Cashier open\n" << endl;
        open();
        
    }
    
    return 0;
}

int cashier::serving_flag(){

    if( is_free() == true ){

        free();

    }
    else{

        cout << "Cashier currently serving another customer\n" << endl;

        cout << "Cashier finished serving current number\n\n" <<  endl;

    }

    return 0;
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

    cout << "Bank under construction\n " << endl;
    int t;
    for( int i = 0; i < 5; i++ ){
        
        t = rand() % 5 + 1;
    }
    
    switch (t){

        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
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

    srand ( time ( NULL ) );

    bank b1(5);

    return 0;
}