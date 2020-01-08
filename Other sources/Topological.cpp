/*
  Wonderland has a unique alphabetical order which is different from the original order from a to z. For instance, say, “luka” is a partial order of Wonderland alphabets. 
  Then, the following information can be found:A letter “l” comes before “u”, “k” and “a”; “u” comes before “k” and “a”; and “k” comes before “a”.Accordingly, if the list 
  of {uak, la, ualak, uka, ak, au} is arranged in Wonderland’s alphabetical order, it will be {la, uka, ualak, uak, au, ak}.One day, a man from Wonderland came to Sungsam 
  University as an exchange student.You are going to team up with him. But you don’t know the alphabetical order of Wonderland.The only thing you know is N words arranged 
  in Wonderland’s alphabetical order. For the alphabets contained in the given N words, write a program to find out their alphabetical order used in Wonderland. [Input]The
  first line has T, the number of test cases.The first line of each test case contains N(1 = N = 100), the number of given words.Each of the following N lines contains a 
  given word arranged in Wonderland’s alphabetical order.Each word is made of lowercase alphabet letters only and its length is less than or equal to 10. [Output]For each
  test case, print “#x”(x represents a test case number and starts from 1).For the alphabets contained in the given words, print their alphabetical order used in Wonderland.
  Print “!” if there is no possible order, while print “?” if there are multiple possible orders.  
  Input Example 
  3
  6
  la
  uka
  ualak
  uak
  au
  ak
  5
  la
  uka
  ualak
  uak
  ak
  6
  cab
  cba
  abc
  acb
  bca
  bac


   
  Output Example 
  #1 luka
  #2 ?
  #3 !
   

*/


#include<iostream>

using namespace std;
#define forn(x) for(int i=0; i< x; i++)
#define forin(i,x) for( i=0; i< x; i++)
char arr[103][13];
char ans[27];
int anspoi;
int N;
int letters[26];
int graph[26][26];
int stack1[27];
int stackpoi;

bool dfs(int x, int* visit, int* visit1) {
	if (visit[x] == 1) return false;
	if (visit1[x] == 1) return true;

	visit[x] = 1;
	visit1[x] = 1;
	forn(26) {
		if (graph[x][i] == 1) {
			if (dfs(i, visit, visit1) == false)
				return false;
		}
	}

	stack1[++stackpoi] = x;
	visit[x] = 0;
	return true;
}

bool topologicalsort() {

	int *visit1 = new int[26];
	forn(26) visit1[i] = 0;
	forn(26) {
		if (letters[i] == 1 && visit1[i] == 0) {
			int *visit = new int[26];
			forn(26) visit[i] = 0;
			if (dfs(i, visit, visit1) == false) return false;

		}
	}
	return true;
}


bool findString() {
	while (stackpoi >= 0)
	{

		ans[++anspoi] = 'a' + stack1[stackpoi];
		int x, y;
		if (stackpoi == 0) { 
			ans[++anspoi] = '\0'; 
			return true; 
		}
		x = stack1[stackpoi--];
		y = stack1[stackpoi];
		if (graph[x][y] != 1) {
			return false;
		}
	}

	return true;
}

int main() {
	int test;
	cin >> test;
	int t = 0;
	forin(t, test) {
		cin >> N;
		stackpoi = -1;
		anspoi = -1;
		forn(26) {
			for (int j = 0; j < 26; j++) {
				graph[i][j] = 0;
			}
			letters[i] = 0;
		}

		forn(N) {
			cin >> arr[i];
			for (int j = 0; arr[i][j] != '\0'; j++)
				letters[arr[i][j] - 'a'] = 1;
		}

		forn(N - 1) {

			for (int j = 0; arr[i][j] != '\0' && arr[i + 1][j] != '\0'; j++) {
				if (arr[i][j] != arr[i + 1][j]) {
					int tempa = arr[i][j] - 'a';
					int tempb = arr[i + 1][j] - 'a';
					graph[tempa][tempb] = 1;
					break;
				}
			}

		}

		if (topologicalsort() == true) {

			if (findString() == true) {
				cout << "#" << t + 1 << " " << ans << endl;
			}
			else {
				cout << "#" << t + 1 << " ?" << endl;
			}


		}
		else {
			cout << "#" << t + 1 << " !" << endl;
		}

	}



	return 0;
}