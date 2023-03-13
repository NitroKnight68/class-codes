//Fractional Knapsack Problem using Greedy
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sack {
	int weight, profit;
	float ratio;
};

bool structSort(Sack a, Sack b) {
	if(a.ratio > b.ratio)
		return true;
	return false;
}

int main() {
	int n, k, i;
	float pSum = 0.0;
	cout << "Enter the number of sacks: ";
	cin >> n;
	cout << endl;
	struct Sack s[n];
	for(int i = 0; i < n; i++) {
		cout << "Enter the weight of sack " << i+1 << ": ";
		cin >> s[i].weight;
		cout << "Enter the profit of sack " << i+1 << ": ";
		cin >> s[i].profit;
		cout << endl;
		s[i].ratio = ((float)s[i].profit / s[i].weight);
	}
	
	sort(s, s+n, structSort);
	
	cout << "Enter the total weight: ";
	cin >> k;

	for(i = 0; i <= n; i++) {
	//	cout << "k : " << k << " P : " << pSum << endl;
		if(s[i].weight <= k) {
			pSum += s[i].profit;
			k -= s[i].weight;
		}	
		else 
			break;
	}
	//cout << "k : " << k << " P : " << pSum << endl;
	pSum += (s[i].ratio * k);		
	cout << "The maximum profit is: " << pSum << endl;
	return 0;
}
