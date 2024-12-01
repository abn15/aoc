#include<bits/stdc++.h>
using namespace std;
int main(){
   ifstream ifs{ "input.txt" };
	if (!ifs.is_open()) return -1;

    vector<int> left, right;
    unordered_map<int,int>rightmap;
	for (int m = 0, n = 0; ifs >> m >> n;) {
		left.push_back(m);
		right.push_back(n);
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

    for (size_t i = 0; i < right.size(); i++) {
        rightmap[right[i]]++;
    }

	
	int totalsim = 0;
    
	for (size_t i = 0; i < left.size(); i++) {
		int score=rightmap[left[i]]*left[i];
        totalsim+=score;
	}

	cout << totalsim << endl;

    return 0;
}