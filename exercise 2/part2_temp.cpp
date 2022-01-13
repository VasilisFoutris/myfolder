#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

class cashier{
    
    bool free_flag;
    bool open_flag;
    int customers_served;
    int C;
    
    public:
    
        cashier( int C );

        //cashier(){};

        void open();

        void close();

        void serve();
    
        void free();

        bool is_open(){ return open_flag; };

        bool is_free(){ return free_flag; };

        ~cashier();

//    private:
//
//        int cust;
//        int next;
//        int *cashiers_serving;
//        cashier *total_cashier;
      
};

cashier::cashier( int custs = 0 ){
    
    C = custs;
    open_flag = false;
    free_flag = true;
    customers_served = 0;
    
}

cashier::~cashier(){
    
    cout << "Cashier has been destroyed\n" << endl;

}

void cashier::open(){

    if( !is_open() ){

        open_flag = true;
        customers_served = 0;

    }

    else{

        cout << "Cashier is open!\n" << endl;

    }
   
}

void cashier::close(){

    if( is_open() ) {

        open_flag = false;

    }

    else{

        cout << "Cashier is closed\n " << endl;

    }
  
}


void cashier::serve(){

    if( is_free() ){

        free_flag = false;

    }

    else{

        cout << "Cashier is serving!\n" << endl;

    }

}

void cashier::free(){

    if( !is_free() ){

        free_flag = true;
        customers_served++;

        if( customers_served = C ){
            
            close();
            cout << "Cashier max workrate achieved!\n " << endl;

        }

    }

    else{
    
        cout << "Cashier is free!\n" << endl;

    } 
}


class bank{

    int last_customer;
    int curr_serving;
    int K;
    int last_cashier;

    public:
    
        bank( int cust , int F );

        void open( int cashier_num );

        void close( int cashier_num );

        int open_cashier();

        bool chack_to_open();

        bool check_to_close();

        int waiting_customers();

        int enter();

        int exit();

        int serve();

        ~bank();

    private:

    cashier cashiers[5];

};


bank::bank( int cust, int Fo ){

    last_customer = 1;
    curr_serving = 1;
    K = Fo;
    
    last_cashier = 0;
    
    for( int i = 0; i < 5; i++ ){

        cashiers[i] = cashier( cust );

    }

}

void bank::open( int cashier_num ){

    cashiers[ cashier_num ].open();

    cout << "Open and ready to serve --> Cashier No. : "<< cashier_num << endl;
    
    cout << "\n" << endl;

}

void bank::close( int cashier_num ){

    cashiers[ cashier_num ].close();
    
    cout << "Closed --> Cashier No. :  " << cashier_num <<  endl;

    cout << "\n" << endl;

}

int bank::open_cashier(){

    int current = 0;
    
    for( int i = 0; i < 5; i++ ){

        if( cashiers[ i ].is_open() ){

            current++;

        }

    } 

    return current;

}

bool bank::chack_to_open(){

    cout << "Currently in queue: " << waiting_customers << "  " << "Currently open cashiers : " << ( open_cashier() * K ) << endl;

    cout << "\n" << endl;

    return waiting_customers() >= ( open_cashier() * K ) ;

}

bool bank::check_to_close(){

    return waiting_customers() <= ( ( open_cashier() - 1 ) * K ); 

}

int bank::waiting_customers(){

    return last_customer - curr_serving;
}

int bank::enter(){

    if( chack_to_open() ){

        curr_serving++;

    }

    else{

        if ( open_cashier() == 5 ){

            cout << "Sorry you cannot enter until some customers are serverd!\n " << endl; 

        }
        
        for( int i = 0; i < 5; i++ ){

            if( !cashiers[i].is_open() ){

                open_cashier();
                break;

            }

        }    

    }

    return 0;
}

int bank::serve(){

    if( open_cashier() == 0 ){

        open( 0 );
        last_cashier = 0;
        
    }
    
    for( int i = last_cashier + 1; i <= last_cashier + 5; i++ ){

        if( cashiers[ i % 5 ].is_open() ){

            last_cashier = ( i % 5 );
            break;

        }

    }

    cashiers[ last_cashier ].serve();    
    
    cout << "Custom" << endl; 

}

int bank::exit(){

    curr_serving++;

    if( check_to_close() ){

        for ( int i = 0; i < 5; i++ ){



        }  
         
    }

    return 0;
}


bank::~bank (){

    cout << "Bank destruction phase\n" << endl;

}

int main(){
    
    int n;

    srand ( time ( NULL ) );

    bank b1(5 , 5);

    return 0;
}