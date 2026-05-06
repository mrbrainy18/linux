#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printTable(vector<vector<int>> &dp, string X, string Y) {
    int m = X.length();
    int n = Y.length();

    cout << "\nDP Table:\n";
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void LCS(string X, string Y) {

    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++) {

            if(i==0 || j==0)
                dp[i][j] = 0;

            else if(X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;

            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "\nLength of LCS: " << dp[m][n] << endl;

    int index = dp[m][n];
    string lcs(index, ' ');

    int i = m, j = n;

    while(i > 0 && j > 0) {

        if(X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }

        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    cout << "LCS String: " << lcs << endl;

    printTable(dp, X, Y);

    cout << "\nTime Complexity = O(m*n)";
    cout << "\nSpace Complexity = O(m*n)\n";
}

int main() {

    int choice;
    string X, Y;

    do {

        cout << "\n--- Longest Common Subsequence ---\n";
        cout << "1. Enter First String\n";
        cout << "2. Enter Second String\n";
        cout << "3. Find LCS\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter First String: ";
                cin >> X;
                break;

            case 2:
                cout << "Enter Second String: ";
                cin >> Y;
                break;

            case 3:
                if(X.empty() || Y.empty()) {
                    cout << "Enter both strings first.\n";
                } else {
                    LCS(X, Y);
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}

//in this when both X[i-1] == Y[j-1], we can store the characters in one string? do we really need to write the below code - 

string lcs(index, ' ');

    int i = m, j = n;

    while(i > 0 && j > 0) {

        if(X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }

        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

