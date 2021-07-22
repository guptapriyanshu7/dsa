#include <iostream>
#include <map>
#include <unordered_set>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using std::cout;

typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	indexed_set s;
	s.insert(2);
	s.insert(3);
	s.insert(7);
	s.insert(9);
	auto x = s.find_by_order(2);
	cout << *x << "\n";
	cout << s.order_of_key(7) << "\n";
	cout << s.order_of_key(6) << "\n";
	cout << s.order_of_key(8) << "\n";

	// std::bitset<10> a("0010110110");
	// cout << a << "\n";

	// std::map<std::string, int> m;
	// m["monkey"] = 4;
	// m["banana"] = 3;
	// m["harpsichord"] = 9;
	// std::cout << m["aybabtu"] << "\n";
	// std::cout << m.count("aybabtu") << "\n";
	// for (auto x : m) { std::cout << x.first << " " << x.second << "\n"; }

	// std::unordered_set<int> s;
	// s.insert(5);
	// s.insert(5);
	// s.insert(5);
	// std::cout << s.count(5);

	return 0;
}