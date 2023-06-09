#ifndef _TEST_PRIORITY_QUEUE_H
#define _TEST_PRIORITY_QUEUE_H

#include <queue>
#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>   // snprintf()
#include <cstdlib>  // abort()
#include <algorithm>

#include "pub.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::priority_queue;
using std::exception;
using std::find;
using std::sort;

namespace jj19
{
	void test_priority_queue(long& totalCount)
	{
		cout << "\ntest_priority_queue()......... \n";

	    priority_queue<string, std::vector<string>, std::greater<string>> c;
	    char buf[10];
		//srand((unsigned)time(NULL));
	    clock_t timeStart = clock();
		for (long i = 0; i < totalCount; ++i) 
		{
		    try {
			snprintf(buf, 10, "%d", rand() % 65535);
			c.push(string(buf));
		    } catch(std::exception& e) {

			cout << "i=" << i << e.what() << endl;
			abort();
		    }
		}

		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "queue.size()= " << c.size() << endl;
		cout << "queue.top()= " << c.top() << endl;
		c.pop();
		cout << "queue.size()= " << c.size() << endl;
		cout << "queue.top()= " << c.top() << endl;
	}
}
#endif
