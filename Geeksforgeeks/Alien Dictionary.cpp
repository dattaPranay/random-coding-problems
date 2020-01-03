// Link -- https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
// topological sorting 



{
//Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];
        
        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);
        
        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;
        
        cout<<f;
        cout<<endl;
        
    }
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */
#define forn(x,y,z) for(x= y ; x<z ; x++ )
int graph[26][26];
vector<int> stack1;
bool visit[26];

void dfs(int x){
    visit[x]= true;
    int i;
    forn(i, 0, 26){
        if (graph[x][i] == 1 && visit[i]== false){
            dfs(i);
        }
    }
    stack1.push_back(x);
    
}
void topological(){
    int i =0;
    forn(i,0, 26) visit[i]= false;
    
    forn(i,0, 26){
        
        if(visit[i]==false) {
            int j;
            forn(j, 0, 26){
                
                if  ( graph[i][j]== 1) {
                    dfs(i); 
                    break;
                }
            }
                  
                        
        }
        
    }
    
}

string printOrder(string dict[], int N, int k)
{
   //Your code here
   
   
   int i= 0;
   int k1=0;
   forn(i, 0, 26)
   forn(k1, 0, 26) graph[i][k1]=0;
   stack1.clear();
   forn(i, 1, N){
       
       int sizea;
       sizea= dict[i].length() > dict[i-1].length() ? dict[i-1].length() : dict[i].length();
       int j=0;
       
       forn(j, 0, sizea){
           if  (dict[i].at(j)  != dict[i-1].at(j) ){
               break;
           }
       }
       if (j!= sizea){
            int a= dict[i].at(j) -'a';
            int b = dict[i-1].at(j) - 'a';
            graph[a][b]= 1;
       }
       
   }
   topological();
   string ans("");
   while (stack1.size()>0){
       int temp = stack1.back(); 
       stack1.pop_back();
       char tempch= 'a' + temp;
       string ss(1, tempch);
       ans.insert(0,ss);
   }
   
    //cout  << ans << endl;
    return ans;
   
}