#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key key) {
	if (m.count(key) == 0) {
		throw runtime_error("Error");
	}
	else {
		return m.at(key);
	}
}

int main() {
	try {
		map<int, string> m = { {0, "value"} };
		string& item = GetRefStrict(m, 0);
		item = "newvalue";
		cout << m[0] << endl; // выведет newvalue
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}