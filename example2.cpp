#include <iostream>
#include <vector>
#include <string>
//#include <cstdlib>
//#include <ctime>
using namespace std;



class base { 
    
public:
    
    base(){

		cout << " Base under construction\n " << endl;
    }

	~base(){

		cout << " Base destruction phase\n " << endl;
	}
};

class closet_shelf {
  
public:

    closet_shelf(){

		cout << " Closet shelfs under construction\n " << endl;

	}
	
	~closet_shelf(){

		cout << " Closet shelfs destruction phase\n " << endl;

	}

};

class closet {

public:

    closet(){
		
		cout << " Closet under construction\n " << endl;

	}

	~closet(){

		cout << " Closet destruction phase\n " << endl;

	}
    
};

class shelf {

public:

    shelf(){

		cout << " Shelfs under construction\n " << endl;

	}

	~shelf(){

		cout << " Shelfs destruction phase\n " << endl;

	}

};

class book{
	//Στην κλάση βιβλίο δημιουργούνται τα βιβλία 
    int L;
	char book_title[20];
	int isbn;
    char writer[20];
    
public:

	book(){


        isbn = 1000;
		L = 2;   
        cout << "Enter Book Title " << endl ;
		cin >> book_title;
                
        cout << "Enter Writer : " << endl ;
        cin >> writer;        
        cout << " \n\n " << endl ;
                
        isbn++;
        //cout << isbn << endl ;

        cout << "Book Title : " << book_title << endl ;
        cout << "Book Number : " << L << endl ;
        cout << "ISBN : " << isbn << endl ;
        cout << "Writer : " << writer << "\n\n" << endl ;  
        
        int books = L;

    }


	~book(){

		cout << " Books destroyed " << endl;
	}
};

int place_book(){

    return 0;
}

int take_book(){

    return 0;
}       

//int book_generator(){
    // Εδώ δημιουργείται τυχαία ο αριθμός βιβλίων που θα προστεθούν στη βιβλιοθήκη 
	//srand( ( int ) time ( 0 ) );
	//int i = 0;
    //int L;
	
	//L = ( rand () % 100) + 20;
	//cout << L << endl;

	//return L;
//}

//int book_ISBN_generator(){
    // Εδώ δημιουργείται o τυχαίος κλειδάριθμος ISBN των βιβλίων 
    //srand( ( int ) time ( 0 ) );
	//int i = 0; 
    //int k;
    //int isbn;
    //k = book_generator();

    //for( k > 10; k < 30; k++ ) {
	    //isbn = ( rand() % 10 ) + 1 ;
        //cout << isbn << endl; 
        //return isbn;
	//}
    //return isbn;
//}
// *************************************************************************************** ΒΓΑΖΕΙ ΣΑΧΛΑΜΑΡΕΣ ΤΥΧΑΙΑ ISBN ΕΔΩ ΦΤΙΑΞΤΟ
//int ISBN_string(){
   
	//int isbn_str_length = 10;
    //int k = book_generator();

    //for( int g = 0; g <= k;  g++ ){
        //int x = book_ISBN_generator();
        //string s1( isbn_str_length , x );
	    //cout << " ISBN: "<< s1 << endl;
        
   //}
//}

// Ο constructor δημιουργεί την βιβλιοθήκη σαν σύνολο ραφιών και ντουλαπιών ενώ καλεί τις κλάσεις να δημιουργήσουν τα αντικείμενα
int construct(){

    cout << " BOOK CREATION SECTOR :\n\n "<< endl;
    //εδώ η διαδικασία δημιουργίας των βιβλίων
    book obj1;

    cout << " Starting library construction\n " << endl; 

    cout << " Base under construction\n " << endl;
    //εδώ η κλήση της κλάσης base για δημιουργ΄΄ια

    cout << " Closet shelfs under construction\n " << endl;
    //εδώ η κλήση της κλάσης closet_shelf για δημιουργ΄΄ια

    cout << " Closet under construction\n " << endl;
    //εδώ η κλήση της κλάσης closet για δημιουργ΄΄ια

    cout << " Shelfs under construction\n " << endl;
    //εδώ η κλήση της κλάσης shelf για δημιουργ΄΄ια

    cout << " Library finished construction\n " << endl;
    // Η βιβλιοθήκη κατασκευάστηκε
    
    return true;
}

//Ο destructor καταστρέφει την βιβλιοθήκη σαν σύνολο
int destruct(){



    cout << " Starting destruction of the library\n " << endl;
    //εδώ η διαδικασία καταστοφής της βιβλιοθήκης

    cout << " Shelfs destruction phase\n " << endl;
    //εδώ η διαδικασία καταστοφής των ραφιών

    cout << " Closet shelfs destruction phase\n " << endl;
    //εδώ η διαδικασία καταστοφής των ραφιών στο ντουλ΄σπι

    cout << " Closet destruction phase\n " << endl;
    //εδώ η διαδικασία καταστοφής του ντουλαπιο΄υ

    cout << " Base destruction phase\n " << endl;
    //εδώ η διαδικασία καταστοφής της βάσης

    cout << " Library completely destroyed\n " << endl;
    // Η βιβλιοθήκη καταστράφηκε
    
    return true;
}

int main(){

    int q = 1;
        
    construct();

	base obj2;
    
    closet_shelf obj3;

    closet obj4;

    shelf obj5;

    q++;

    if ( q == 2 ){
        destruct();
    }
    return 0;
}