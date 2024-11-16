#include <bits/stdc++.h>
using namespace std;

#define Shahtaz_69()  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void  lcs(string s1, int l1, string s2, int l2 ){

    //! creting the dp table 
    int dp[l1+1][l2+1];

    //! fill up the dp table
    for(int i=0; i<=l1; i++){
        for(int j =0 ; j<=l2; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1] [j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }


    //! printing the dp table
    
    for(int i=0; i<=l1; i++ ){
         for(int j =0 ; j<=l2; j++){
            cout<<dp[i][j]<<'\t';
    }
    cout<<endl;
    cout<<endl;
    }
    

    int len = dp[l1][l2];   //! the size of the lcs which is the value of the last cell of the dp table

    char lcs_res[len + 1];
    lcs_res[len] = '\0';

    int i=l1;
    int j = l2;

    int t = len - 1;
    //! backtracking form [l1][l2]
    while(i>0 && j>0){
        if(dp[i][j] == dp[i-1][j]) i--;
            else if(dp[i][j] == dp[i][j-1]) j--;
            else
                {
                    lcs_res[t] = s1[i-1];   //! storing the data fron the back 
                    t--;
                    i--;
                    j--;
                }
    }
    cout<<endl;
    cout<<endl;
    cout<<"LCS Length: "<<len<<endl;
    cout<<"LCS : "<<lcs_res<<endl;

}
int main(){
    
    Shahtaz_69();

    //! getting the size of the two string
    int p, q;
    cin>>p>>q; 

    cin.ignore(); //! to clear the new line char form the previous input 


    char s1[p];
    char s2[q];

    scanf("%s", s1);
    scanf("%s", s2);

    /*
    ID: 22-20-1069
    -> P = (22 % 6 ) + 10 -> 14
    -> Q = (20 % 6 ) + 10 -> 12
    S1-> GTCGTTCGGAATGC (len= 14)
    S2-> ACCGGTCGAGTG (len = 12)


    sample input
14 12
GTCGTTCGGAATGC
ACCGGTCGAGTG

    */

    lcs(s1, p, s2, q);  //! calling the lcs 

    return 0;

}