#include<bits/stdc++.h>

using namespace std;

#define Shahtaz_69()  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void knapsack(int n, int cap,  int v[], int w[]){

    int dp[n+1][cap+1];       //!creating dp table for knapsack

   //!fill the dp table starting from dp[0][0]
   for(int i=0; i<=n; i++){
        for(int j=0; j<=cap; j++){

            //in the dp table 0th coulumn and 0th row will be assigned as 0
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(w[i]>j){
                dp[i][j] = dp[i-1][j]; //copy form the above row 
            }
            else{

                 dp[i][j] = max (dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
            }
        }
   }

   //! to print the dp table
    

   for(int i=0; i<=n; i++){
    for(int j=0; j<=cap; j++){
        cout<<dp[i][j]<<'\t';
    }
    cout<<endl;
    cout<<endl;
   }
    cout<<"\n\n";
    

   //!picking item -->backtracking
    int a = n;
    int b = cap;

   int max_value = 0;// to see the maximum value we can get
   int total_weight = 0; 

   while(a>0 && b>0){
    if(dp[a][b] != dp[a-1][b]){
        //dose not match with the upper cell
        // we pict the item  we go weight cells to left

        b -=w[a];
        cout<<"item num. -> "<<a<<'\t'<<"| weight. -> "<<w[a]<<'\t'<<"| value. -> "<<v[a]<<endl;
        max_value += v[a];
        total_weight +=w[a];

    }
    a--;
   }

   cout<<"----------------------------------"<<endl;
   cout<<"maximum_value :: "<<max_value<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"total_weight :: "<<total_weight<<endl;
   cout<<"----------------------------------"<<endl;

}


int main(){

    Shahtaz_69();

    int n = 6 ;//!number of items
    
    int cap =  12;//!capacity a.k.a the maximum weight of the knapsack

    //!weight
    int w[] = {0,4,2,6,5,3,4};
    //!value
    int v[] = {0,10,4,6,7,5,6};

    knapsack(n, cap, v, w);
    return 0;
}