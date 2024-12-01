#include<bits/stdc++.h>
using namespace std;
int main(){
   ifstream ifs{ "input.txt" };
	if (!ifs.is_open()) return -1;

    vector<int> left, right;
	for (int m = 0, n = 0; ifs >> m >> n;) {
		left.push_back(m);
		right.push_back(n);
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	
	int totalDistance = 0;
	for (size_t i = 0; i < left.size(); i++) {
		totalDistance += abs(left.at(i) - right.at(i));
	}

	cout << totalDistance << endl;

    return 0;
}