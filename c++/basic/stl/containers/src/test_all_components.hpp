#ifndef _TEST_ALL_COMPONENTS_H
#define _TEST_ALL_COMPONENTS_H

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

namespace jj30
{
void test_all_components()
{
	cout << "\ntest_all_components().......... \n";
     
  	int ia[7] = { 27, 210, 12, 47, 109, 83, 40 };
  	vector<int,allocator<int>> vi(ia,ia+7);
 
   	cout << count_if(vi.begin(), vi.end(), 
              not1(bind2nd(less<int>(), 40)));	//5
    cout << endl;          
}															 
}
#endif