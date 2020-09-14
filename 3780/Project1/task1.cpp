#include <iostream>
int multiplybytwo(int);
int subtractthree(int);

	int main() {
		int x = 1;
		int y = 2;
		int z = 3;

		std::cout<<multiplybytwo(z)<<std::endl;

		return 0;
}

int multiplybytwo(int r) {
	int x = r * 2;
	int y = subtractthree(x);
		return y;
}

int subtractthree (int e) {
	int x = e-3;
	return x;
}



