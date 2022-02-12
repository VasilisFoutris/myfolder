#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

int books;

class base { 
// Το αντικείμενο βάση έχει μόνο δομικό ρόλο στην βιβλιοθήκη
public:
    
    base(){
       
		cout << "Base under construction\n " << endl;
        
    }

	~base(){

		cout << "Base destruction phase\n " << endl;
        cout << "Library completely destroyed\n " << endl;

	}
};

class upper_closet_shelf {
  
public:
  
    upper_closet_shelf(){
        int closet1[100];
		cout << "Closet shelf under construction\n " << endl;

	}
	
	~upper_closet_shelf(){

		cout << "Closet shelf destruction phase\n " << endl;

	}

};

class bottom_closet_shelf {
  
public:
    
    bottom_closet_shelf(){
        int closet2[100];
		cout << "Bottom shelf under construction\n " << endl;

	}
	
	~bottom_closet_shelf(){

		cout << "Bottom shelf destruction phase\n " << endl;

	}

};

class closet {

public:

    closet(){
		
		cout << "Closet under construction\n " << endl;

	}

	~closet(){

		cout << "Closet destruction phase\n " << endl;

	}
    
};

class upper_shelf {

public:
    
    upper_shelf(){
        int shelf1[100];
		cout << "Upper shelf under construction\n " << endl;

	}

	~upper_shelf(){

		cout << "Upper shelf destruction phase\n " << endl;

	}

};

class mid_shelf {

public:
    
    mid_shelf(){
        int shelf2[100];
		cout << "Mid shelf under construction\n " << endl;

	}

	~mid_shelf(){

		cout << "Mid shelf destruction phase\n " << endl;

	}

};

class bottom_shelf {

public:
    
    bottom_shelf(){
        int shelf3[10];
		cout << "Bottom shelf under construction\n " << endl;

	}

	~bottom_shelf(){

		cout << "Bottom shelf destruction phase\n " << endl;

	}

};

class book{
	//Στην κλάση βιβλίο δημιουργούνται τα βιβλία 

public:
    string  gen_random_aplha( int len1 = 10 ) {
    
    std::string s1;
    static const char alpha[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";

    for ( int i = 0; i < len1; ++i ) {
        s1 += alpha[ rand() % ( sizeof( alpha ) - 1 ) ];
    }
    return s1;
    }

    string gen_random_num ( int len2 = 10 ){
    
    std::string s2;
    static const char num[] =
        "0123456789";

       for ( int d = 0; d < len2; ++d ) {
        s2 += num[ rand() % ( sizeof( num ) - 1)];
    }
    return s2;
    }
    
    string  gen_random_beta( int len3 = 10 ) {
    string s3;
    static const char alpha[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int r = 0; r < len3; ++r) {
        s3 += alpha[ rand() % ( sizeof( alpha ) - 1) ];
    }
    return s3;
    }

	book(){
      
        cout << "Book Title : " << gen_random_aplha() << endl;

        cout << "ISBN : " << gen_random_num() << endl;

        cout << "Writer : " << gen_random_beta() << "\n\n" << endl;  
       
    }

	~book(){
        cout << "-------------------------" << endl;
		cout << "Book destroyed" << endl;
        cout << "-------------------------\n" << endl;
	}   
};

int place_book(){

    int t = 0;

    //srand ( time ( NULL ) );
    t = rand() % 5 + 1;
    
    switch ( t ){
////   
    case 1:
////Αν t = 1 τοποθετεί το βιβλίο στο πρώτο ράφι

    cout << "-------------------------" << endl;
    cout << "Book placed in position 1 - Upper Shelf" << endl;
    cout << "-------------------------\n" << endl;
    
    break;

////
    case 2:
////Αν t = 2 τοποθετεί το βιβλίο στο δεύτερο ράφι

    cout << "-------------------------" << endl;
    cout << "Book placed in position 2 - Mid Shelf" << endl;
    cout << "-------------------------\n" << endl;
    
    break;

////
    case 3:
////Αν t = 3 τοποθετεί το βιβλίο στο τρίτο ράφι

    cout << "-------------------------" << endl;    
    cout << "Book placed in position 3 - Lower Shelf" << endl;
    cout << "-------------------------\n" << endl;
    
    break;

////
    case 4:
////Αν t = 4 τοποθετεί το βιβλίο στο πρώτο ράφι του ντουλαπιού   

    cout << "-------------------------" << endl;
    cout << "Book placed in position 4 - Upper Closet Shelf" << endl;
    cout << "-------------------------\n" << endl;
    
    break;

////
    case 5:
////Αν t = 5 τοποθετεί το βιβλίο στο δεύτερο ράφι του ντουλαπιού

    cout << "-------------------------" << endl;
    cout << "Book placed in position 5 - Bottom Closet Shelf" << endl;
    cout << "-------------------------\n" << endl;
    
    break;
////
    }

    return 0; 
}

int take_book(){

    int t;
    t = rand() % 5 + 1;

    switch ( t ){
////
        case 1:
////Αν t = 1 αφαιρεί το βιβλίο απο το πρώτο ράφι      
        cout << "-------------------------" << endl;
        cout << "Book has been removed from position 1 - Upper Shelf" << endl;
        cout << "-------------------------\n" << endl;

        break;

////
        case 2:
////Αν t = 2 αφαιρεί το βιβλίο απο το δεύτερο ράφι      
        cout << "-------------------------" << endl;
        cout << "Book has been removed from position 2 - Mid Shelf" << endl;
        cout << "-------------------------\n" << endl;

        break;

////
        case 3:
////Αν t = 3 αφαιρεί το βιβλίο απο το τρίτο ράφι      
        cout << "-------------------------" << endl;
        cout << "Book has been removed from position 3 - Bottom Shelf" << endl;
        cout << "-------------------------\n" << endl;

        break;

////
        case 4:
////Αν t = 4 αφαιρεί το βιβλίο από το πρώτο ράφι του ντουλαπιού
        cout << "-------------------------" << endl;
        cout << "Book has been removed from position 4 - Upper Closet Shelf" << endl;
        cout << "-------------------------\n" << endl;

        break;

////
        case 5:
////Αν t = 5 αφαιρεί το βιβλίο από το δεύτερο ράφι του ντουλαπιού
        cout << "-------------------------" << endl;
        cout << "Book has been removed from position 5 - Bottom Closet Shelf" << endl;
        cout << "-------------------------\n" << endl;

        break;
////
    }

    return 0;
}       

// Ο constructor δημιουργεί την βιβλιοθήκη σαν σύνολο ραφιών και ντουλαπιών ενώ καλεί τις κλάσεις να δημιουργήσουν τα αντικείμενα
// O destructor καταστρέφει τα αντικείμενα όταν το πρόγραμμα τελειώσει  
int construct_destruct(){

    srand ( time ( NULL ) );
    
    cout << "\nBOOK CREATION SECTOR :\n\n "<< endl;
    //εδώ η διαδικασία δημιουργίας των βιβλίων

    // δημιουργούμε όσα αντικείμενα book θέλουμε 

    std::vector<book> v( books );

    cout << "Books have been configured "  << endl; 
    cout << "-------------------------\n" << endl;
    cout << "Starting library construction\n " << endl; 

    //cout << " Base under construction\n " << endl;
    //εδώ η κλήση της κλάσης base για δημιουργ΄΄ια
    base obj1;

    //εδώ η κλήση της κλάσης upper_closet_shelf για δημιουργ΄΄ια
    upper_closet_shelf obj2;

    //εδώ η κλήση της κλάσης bottom_closet_shelf για δημιουργ΄΄ια
    bottom_closet_shelf obj3;

    //εδώ η κλήση της κλάσης closet για δημιουργ΄΄ια
    closet obj4;

    //εδώ η κλήση της κλάσης upper_shelf για δημιουργ΄΄ια
    upper_shelf obj5;

    //εδώ η κλήση της κλάσης mid_shelf για δημιουργ΄΄ια
    mid_shelf obj6;

    //εδώ η κλήση της κλάσης bottom_shelf για δημιουργ΄΄ια
    bottom_shelf obj7;

    cout << "Library finished construction\n " << endl;
    // Η βιβλιοθήκη κατασκευάστηκε
    
    //Εδώ ξεκινάει η διαδικασία τοποθέτησης και αφαίρεσης των βιβλίων από τη βιβλιοθήκη
    
    for ( int m = 0; m < books; m++ ){
        place_book();
    }
    
    for ( int n = 0; n < books; n++ ){
        take_book();
    }

    return true;
}

int main(){
    
    cout << "Please enter a value of books from 1 to 100: \n " << endl;
    cin >> books;
    construct_destruct();

    return 0;
}