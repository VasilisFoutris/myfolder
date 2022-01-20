#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

class creature{

    public:

        creature();

        creature ( string s1, int L, int N );

        void print( int L );

        virtual bool is_a_good();

        virtual void is_a_zombie();

        void bless( creature v, int L );

        void beat( creature v, int L );
        
        void print_action_beat( creature v );

        void print_action_bless( creature v );

        void print_life();

        ~creature();

    private:

        string name;
        int remaining_life;
        int next;

};

creature::creature(){

    name = " ";

}

creature::creature( string s1, int L, int N ){
    
    name = s1;
    remaining_life = L;

}

bool creature::is_a_good(){

    if ( remaining_life != 0 ){
        
        cout << "This creature is good for now!\n " << endl;

    }

    return true;

}

void creature::is_a_zombie(){

    if( remaining_life = 0 ){

        cout << "This creature turned into zombie!\n " << endl;
        
    }

}

void creature::bless( creature v, int L ){

    L++;
    remaining_life = L;

}

void creature::beat( creature v, int L ){

    L--;
    remaining_life = L;

}

void creature::print( int L ){

    cout << "Creature Name: " << name << "\t Starting Life: " << L << endl;

}

void creature::print_action_beat( creature v ){

    cout << "Creature Name: " << name << "\t Has been beeten\n " << endl;

}

void creature::print_action_bless( creature v ){

    cout << "Creature Name: " << name << "\t Has been blessed\n " << endl;

}

void creature::print_life(){

    cout << "Creature Name: " << name << "\t Remaining Life: " << remaining_life << "\n" << endl;

}

creature::~creature(){

}

class good_creature : public creature{

    public:

        good_creature();

        void clone();

        bool check_is_a_good();

        void print();

        ~good_creature();

        good_creature();

    private:
    
};

good_creature::good_creature() : creature() {

}

bool good_creature::check_is_a_good(){

    if( is_a_good() ){

        return true;

    }

    return true;

}

void good_creature::clone(){

    //delete [] cre;

}

void good_creature::print(){

}

good_creature::~good_creature(){

    //delete [] cre;

}

class bad_creature : public creature {

    public:

        bad_creature();

        void clone();

        bool check_is_a_good();

        void print();

        ~bad_creature();

        bad_creature();

    private:

};

bad_creature::bad_creature() : creature() {

}

bool bad_creature::check_is_a_good(){

    if( is_a_good() ){

        return false;

    }

    return false;

}

void bad_creature::clone(){

    //delete [] cre ;

}

void bad_creature::print(){

}

bad_creature::~bad_creature(){

}

class creature_society : public creature {

    int no_of_good = 0;
    int no_of_zombies = 0;

    public:

        creature_society( int N );

        void clone_next();

        void clone_zombies();;

        void print();

        ~creature_society();

    private:

        int members;
        creature** cre;

};

creature_society::creature_society( int N ){

    cre = new creature*[ N ];

    for( int i = 0; i < N; i++ ){

        int ra = ( rand() % 2 );

        if( ra ){

            cre[i] = new good_creature();

        }
        else{

            cre[i] = new bad_creature();

        }

    }

}

void creature_society::clone_next(){

}

void creature_society::clone_zombies(){



}

void creature_society::print(){

    //if ( cre ){
       
        //cout << "Good dominates in the world!\n " << endl; 

    //}

    //if ( cre ){
        
        //cout <<  "This is a dead society\n " << endl;

    //}
    
    //else{
        
        //cout << "Try again to improve the world\n " << endl;

    //}

}

creature_society::~creature_society(){

    //delete [] cre;

}

string  gen_random_aplha( int len1 = 6 ) {

    std::string s1;
    static const char alpha[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    for ( int i = 0; i < len1; ++i ) {
        
        s1 += alpha[ rand() % ( sizeof( alpha ) - 1 ) ];

    }
    
    return s1;

}

int main( int argc, char *argv[] ){

    if( argc != 6 ){
        
        cout << "Error, not enough command line arguments\n " << endl;
        
        return 0;

    }

    int N = stoi ( argv[1] ) ;
    int M = stoi ( argv[2] ) ;
    int L = stoi ( argv[3] ) ;
    int good_threshold = stoi ( argv[4] ) ;
    int bad_threshold = stoi ( argv[5] ) ;

    // το good threshold για όλα τα πλάσματα και αν η ζωη των πλασμάτων ειναι μεγαλύτερη 
    // απο αυτο τοτε κλωνοποιουνται κυκλικα, απο δεξια στα αριστερα και μετα το τελευταιο
    // κλωνοποιείται το πρωτο

    // το bad threshold για όλα τα πλάσματα και αν η ζωη των πλασμάτων ειναι μεγαλύτερη 
    // απο αυτο τοτε κλωνοποιουνται απο αριστερα στα δεξια όλα το εναπομειναντα πλασματα
    // και αν ειναι το τελυταιο τοτε δεν κλωνοποιειται  

    srand( time( NULL ) );
    std::vector<creature> v( N );
    creature_society cs( N );
    int selected = 0;

    for( int i = 0; i < N; i++ ){
        
        v[i] = creature( gen_random_aplha(), L, N );
        v[i].print( L );
        cout << "Society Position: " << i << "\n" << endl;

    }

    for( int t = 0; t <= M; t++ ){

        int creature_selector = 1 + ( rand() % N );
        int action_selector = 1 + ( rand() % 2 );
    

        switch ( creature_selector ){
    
            case(1):

            selected = 0;

            if( action_selector == 1 ){
            
                v[selected].bless( v[selected], L );

                v[selected].print_action_bless( v[selected] );

            }

            if( action_selector == 2 ){
            
                v[selected].beat( v[selected], L );

                v[selected].print_action_beat( v[selected] );

            }

            break;
    

            case(2):

            selected = 1;

            if( action_selector == 1 ){
            
                v[selected].bless( v[selected], L );

                v[selected].print_action_bless( v[selected] );

            }

            if( action_selector == 2 ){
            
                v[selected].beat( v[selected], L );

                v[selected].print_action_beat( v[selected] );

            }

            break;

    
            case(3):

            selected = 2;

            if( action_selector == 1 ){
            
                v[selected].bless( v[selected], L );

                v[selected].print_action_bless( v[selected] );

            }

            if( action_selector == 2 ){
            
                v[selected].beat( v[selected], L );

                v[selected].print_action_beat( v[selected] );

            }

            break;

    
            case(4):

            selected = 3;

            if( action_selector == 1 ){
            
                v[selected].bless( v[selected], L );

                v[selected].print_action_bless( v[selected] );

            }

            if( action_selector == 2 ){
            
                v[selected].beat( v[selected], L );

                v[selected].print_action_beat( v[selected] );
                
            }
    
            break;

    
            case(5):

            selected = 4;

            if( action_selector == 1 ){
            
                v[selected].bless( v[selected], L );

                v[selected].print_action_bless( v[selected] );

            }

            if( action_selector == 2 ){
            
                v[selected].beat( v[selected], L );

                v[selected].print_action_beat( v[selected] );
                
            }
    
            break;
            
        }

    }

    for( int j = 0; j < N; j++ ){
        
        v[j].print_life();

    }

    cs.print();

    for( int i = 0; i < N; i++ ){

    }


    
// με τον ποιντερ this θα κανεις το σημειο που ζηταει να σβηνεις καποιο στοιχειο απο τον πινακα και να κλωνοποιεις τα αλλα
// ΔΕΝ ΕΧΕΙΣ ΚΑΝΕΙ ΑΚΟΜΑ ΤΗΝ GOOD ΚΑΙ BAD CREATURE , ΔΕΝ ΕΧΕΙΣ ΤΕΛΕΙΩΣΕΙ ΤΗΝ CREATURE , ΔΕΣ ΛΙΓΟ ΤΙ ΓΙΝΕΤΑΙ ΜΕ ΚΛΗΡΟΝΟΜΙΚΟΤΗΤΕΣ, 
// VIRTUAL IS A GOOD ΚΑΙ IS A ZOMBIE ΓΙΑΤΙ ΠΡΕΠΕΙ ΝΑ ΝΑΙ ΜΕΣΑ ΣΤΗΝ GOOD ΚΑΙ BAD CREATURE , ΚΑΙ ΑΝ ΚΑΙ ΠΟΥ ΧΡΕΙΑΖΟΝΤΑΙ ΥΠΟΚΛΑΣΕΙΣ 
// ΣΥΜΦΩΝΑ ΜΕ ΟΤΙ ΛΕΝΕ ΣΤΟ LISTS
// ΚΑΙ ΔΕΣ ΤΙ ΜΕΝΕΙ ΣΤΗΝ CREATURE SOCIETY 
// ΣΤΗΝ MAIN ΛΕΙΠΟΥΝ ΟΙ ΑΝΤΙΣΤΟΙΧΕΣ ΕΝΤΟΛΕΣ ΜΕΣΑ ΣΤΙΣ SWITCH ΓΙΑ ΝΑ ΤΡΕΧΕΙ ΤΟ ΠΡΟΓΡΑΜΜΑ ΚΑΘΩΣ ΚΑΙ ΟΙ ΑΝΤΙΣΤΟΙΧΕΣ ΕΚΤΥΠΩΣΕΙΣ 
    
    return 0;
    
}