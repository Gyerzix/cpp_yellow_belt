#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename T> T Sqr(const T& x);
template <typename F> vector<F> operator*(const vector<F>& lhs, const vector<F>& rhs);
template <typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& lhs, const pair<First, Second>& rhs);
template <typename Key, typename Value> map<Key, Value> operator*(const map<Key, Value>& lhs, const map<Key, Value>& rhs);

template <typename T>
T Sqr(const T& x) {
	return x * x;
}

template <typename F>
vector<F> operator*(const vector<F>& lhs, const vector<F>& rhs) {
	vector<F> result;
	for (int i = 0; i < lhs.size(); i++) {
		result.push_back(lhs[i] * rhs[i]);
	}
	return result;
}
template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& lhs, const pair<First, Second>& rhs) {
	First f = lhs.first * rhs.first;
	Second s = lhs.second * rhs.second;
	return { f, s };
}

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& lhs, const map<Key, Value>& rhs) {
	map<Key, Value> result;
	for (auto& item : lhs) {
		auto value = rhs.at(item.first);
		result[item.first] = item.second * value;
	}
	return result;
}

int main() {
	// Пример вызова функции
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}