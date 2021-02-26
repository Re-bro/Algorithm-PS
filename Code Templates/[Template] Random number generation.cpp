/* 
	[Template] Random number generation
*/
#include<bits/stdc++.h>
#include<random>

using namespace std;
int main(void) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 10000);
	for (int i = 0; i < 10; i++) {
		cout << dis(gen) << '\n';
	}
}