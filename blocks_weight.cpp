#include <iostream>
#include <cstdint>

using namespace std;

int main() {
	int N; cin >> N;
	int R; cin >> R;
	uint64_t sum = 0;
	for (int i = 0; i < N; i++) {
		int W; cin >> W;
		int H; cin >> H;
		int D; cin >> D;
		uint64_t temp = static_cast<uint64_t>(W) * H * D;
		sum += temp;
	}
	cout << sum * R << endl;
	return 0;
}
