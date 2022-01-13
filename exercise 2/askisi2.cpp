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

        //~cashier();

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
    cout << "Cashier under construction\n " << endl; 
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

        if( customers_served == C ){
            
            close();
            cout << "Cashier max workrate achieved!\n " << endl;

        }

    }

    else{
    
        cout << "Cashier is free!\n" << endl;

    } 
}

//cashier::~cashier(){
//    
//    cout << "Cashier has been destroyed\n" << endl;
//
//}

class bank{

    int last_customer;
    int curr_serving;
    int K;
    int last_cashier;
    cashier* cashiers;

    public:
    
        bank( int N , int K );

        void open( int cashier_num );

        void close( int cashier_num );

        int open_cashier();

        bool check_to_open();

        bool check_to_close();

        int waiting_customers();

        int enter();

        int exit();

        int serve();

        ~bank();

    private:

    

};


bank::bank( int cust, int Fo ){

    last_customer = 1;
    curr_serving = 1;
    K = Fo;
    last_cashier = 0;
    cashiers = new cashier[5];

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

bool bank::check_to_open(){

    cout << "Currently in queue: " << waiting_customers() << "  " << "Currently open cashiers : " << ( open_cashier() * K ) << endl;

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

    if( !check_to_open() ){
        
        last_customer++;
        return true;

    }

    else{
        
        bool opened=false;
        
        for (int i = 0; i < 5; i++){

            if( !cashiers[i].is_open() ){
                
                open(i);
                opened = true;
                last_customer++;
                break;

            }
        }
        if( !opened ){
        
            return false;
        }

        return true;

    }

}


int bank::serve(){

    int current_cashier=0;
    
    if(open_cashier() ==0 ){

        open(0);
        current_cashier=0;
        last_cashier=0;

    }

    else{
        
        bool found=false;
        
        for (int a = 0; a < 5; a++){
            int i=(last_cashier+(i+1))%5;

            if( cashiers[i].is_open() && cashiers[i].is_free() ){
                
                last_cashier=i;
                current_cashier=i;
                found=true;
                break;

            }

        }
        
        if( !found ){
         
            cout<<"Cashiers not available!\n";

        }

    }
    
    cout << "Customer no: " << curr_serving << " by cashier no: "<< last_cashier << endl;
    cashiers[ current_cashier ].serve(); 
    cashiers[ current_cashier ].free();
    
    exit();
    return 0;
}

int bank::exit(){

    curr_serving++;

    if( check_to_close() ){
        for ( int i = 0; i < 5; i++ ){

            if( cashiers[i].is_open() && cashiers[i].is_free() ){

                close(i);
                break;

            }

        }

    }

    return 0;

}


bank::~bank (){

    cout << "Bank destruction phase\n" << endl;

}

int main( int argc, char *argv[] ){
    
    if( argc != 5 ){
        
        cout << "Error\n " << endl;
        return 1;

    }

    int K = stoi ( argv[1] ) ;
    int M = stoi ( argv[2] ) ;
    int N = stoi ( argv[3] ) ;
    int L = stoi ( argv[4] ) ;

    bank b1( N , K );

    int waiting_to_be_served = 0;

    for (int i = 0; i < M; i++){

        for (int a = 0; a < N; a++){
            
            if(!b1.enter()){

                waiting_to_be_served++;

            }

        }

        for (int a = 0; a < N; a++){

            if( b1.waiting_customers() ==0 ){

                break;
            }

            b1.serve();

        }
        
    }

    for (int i = 0; i < waiting_to_be_served; i++){

        b1.enter();
        b1.serve();
    }
    
    return 0;

}