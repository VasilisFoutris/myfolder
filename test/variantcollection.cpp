#include <iostream>
#include "variantcollection.h"
using namespace std;
		
variantcollection::variantcollection(){
			
cout<<"\n Vcf loaded "<<endl;

}
		
void variantcollection::func(){
		
		raw_file.open("test.vcf", ios::in);
		filtered_file.open("filtered_test.vcf", ios::out);
		
		if(!raw_file) {

			cout << "No such file";
		
		}
	
		else {
		
			//select and search in line
			while (getline(raw_file, s)) {
			
				//check for next 2 characters and check if string starts with MT and continue
				if(s.substr(0, 2).compare(mt_s)==0){
				
					for( int i = 0; i < s.length(); i++ ){
					
						//check pair of 2 characters until AF is reached 
						if( s.substr(i,2).compare(af_s) == 0 ){
						
							//move pointer from A to first int ( A->F->=-> )
							i += 3;
							int a;
							
							//if the number is smaller than 10 ints check until ";" and stop
							for( a = 0; a < 10; a++ ){
								
								if( s [ i + a ] == ';'){
								
									break;
								
								}
							
							}
						
							//start from i and take a charecters 
							string s1 = s.substr(i,a);					
							s1.erase(a-3,1);
						
							//assign to int
							int num = stoi( s1 );
							
							// Only pass variants with AF > 0,5 
							if( num > 50 ){
							
								filtered_file << s << "\n";
							
							}
						
							break;
						
						}
					}
				}
			
				else{
				
					filtered_file << s << endl;
				
				}	
    		}   	
		}

	raw_file.close();
	filtered_file.close(); 
	
	}
		
variantcollection::~variantcollection(){
			
	cout<<"\n VCF is filtered"<<endl;
}
		
	
