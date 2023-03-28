#ifndef _TEST_HASH_MULTIMAP_H
#define _TEST_HASH_MULTIMAP_H

using namespace std;

#ifdef __GNUC__
#include <ext/hash_map>
    //...\4.9.2\include\c++\backward\backward_warning.h	
	//[Warning] #warning This file ... (如上個函數所言)
#endif

#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace jj12
{
void test_hash_multimap(long& value)
{
	cout << "\ntest_hash_multimap().......... \n";
    
	#ifdef __GNUC__
	__gnu_cxx::hash_multimap<long, string> c;  	
	char buf[10];
			
    clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	//c.insert(...   		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	
    timeStart = clock();								
    //! auto ite = c.find(...
	cout << "milli-seconds : " << (clock()-timeStart) << endl;
	#endif
}												
}
#endif