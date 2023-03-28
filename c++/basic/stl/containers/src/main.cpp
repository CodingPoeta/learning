#include "includes.h"
#include <cstdlib> //rand() and RAND_MAX
void test_containers( const int& choice ) {
	long value;  	
    srand(time(NULL));

	if ( choice != 1 ) { 	//1 ==> array, use ASIZE
		cout << "how many elements: ";
		cin >> value; 		
	}

	switch (choice) {
		case 1 : jj01::test_array(); break;
		case 2 : jj02::test_vector(value); break;
		case 3 : jj03::test_list(value); break;
		case 4 : jj04::test_forward_list(value); break;
		case 5 : jj05::test_deque(value); break;
		case 6 : jj06::test_multiset(value); break;
		case 7 : jj07::test_multimap(value); break;
		case 8 : jj08::test_unordered_multiset(value); break;
		case 9 : jj09::test_unordered_multimap(value); break;
		#ifdef __GNUC__
		case 10: jj10::test_slist(value); break;
		case 11: jj11::test_hash_multiset(value); break;
		case 12: jj12::test_hash_multimap(value); break;
		#endif
		case 13: jj13::test_set(value); break;
		case 14: jj14::test_map(value); break;
		case 15: jj15::test_unordered_set(value); break;
		case 16: jj16::test_unordered_map(value); break;
		case 17: jj17::test_stack(value); break;
		case 18: jj18::test_queue(value); break;
		case 19: jj19::test_priority_queue(value); break;
		default: break;
	}
}

int main(int argc, char* argv[]) {
	jj00::test_misc();

	int choice;
	cout << "select: \n";
	cin >> choice;

	switch (choice) {
	case 20: jj20::test_list_with_special_allocator(); break;
	case 25: jj25::test_components_sizeof(); break;
	case 30: jj30::test_all_components(); break;
	case 31: jj31::test_Rb_tree(); break;
	case 32: jj32::test_Hashtable(); break;
	case 33: jj33::test_iterator_category(); break;
	case 34: jj34::test_accumulate(); break;
	case 35: jj35::test_for_each(); break;
	case 36: jj36::test_sort(); break;
	default: test_containers(choice); break;
	}

	return 0;
}
