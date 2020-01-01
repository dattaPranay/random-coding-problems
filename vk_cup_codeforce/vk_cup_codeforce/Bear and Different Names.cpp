// Link to this Question -- https://codeforces.com/contest/771/problem/B 
// greedy -- implementaion 
#include <iostream>
#include <vector>
#include <string>
using namespace std;


#define MAXX 51
#define forn(x) for(int i =0 ; i< x; i++)
#define forxn(i,x) for(i =0 ; i< x; i++)
int arr[MAXX];

char tempstr[6];
int N, K;
int main() {

	cin >> N >> K;
	int size = N - K + 1;
	vector<string> names;
	vector<string> ans;
	char first, second;
	first = 'A';
	second = 'a';
	forn(MAXX/2) {
		
		int j = 0;
		second = 'a';
		forxn(j,MAXX / 2) {
			
			
			string f(1, first);
			string e(1, second);
			f = f + e;
			names.push_back(f);
			second = second + 1;
		}
		first = first + 1;
	}
	forn(K - 1) {
		ans.push_back(names.at(i));
	}
	int count = K;
	forn(size) {
		cin >> tempstr;
		if (tempstr[0] == 'Y') {
			arr[i] = 1;
			ans.push_back(names.at( (count++) %MAXX) );
			
		}
		else {
			arr[i] = 0;
			ans.push_back(ans.at(i));
		}
	}
	forn((int)(ans.size()) ) {
		cout <<  ans.at(i) << " ";
	}
	
	


	return 0;
}
