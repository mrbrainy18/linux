#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX 20

int n;
int cost[MAX][MAX];
bool visited[MAX];

int final_path[MAX];
int curr_path[MAX];

int final_res = INT_MAX;

int firstMin(int i) {
    int min = INT_MAX;
    for(int k = 0; k < n; k++) {
        if(cost[i][k] < min && i != k)
            min = cost[i][k];
    }
    return min;
}

int secondMin(int i) {
    int first = INT_MAX, second = INT_MAX;
    for(int j = 0; j < n; j++) {
        if(i == j) continue;

        if(cost[i][j] <= first) {
            second = first;
            first = cost[i][j];
        }
        else if(cost[i][j] < second && cost[i][j] != first)
            second = cost[i][j];
    }
    return second;
}

void copyToFinal() {
    for(int i = 0; i < n; i++)
        final_path[i] = curr_path[i];
    final_path[n] = curr_path[0];
}

void TSPRec(int curr_bound, int curr_weight, int level) {

    if(level == n) {
        if(cost[curr_path[level-1]][curr_path[0]] != 0) {
            int curr_res = curr_weight + cost[curr_path[level-1]][curr_path[0]];

            if(curr_res < final_res) {
                copyToFinal();
                final_res = curr_res;
            }
        }
        return;
    }

    for(int i = 0; i < n; i++) {

        if(cost[curr_path[level-1]][i] != 0 && !visited[i]) {

            int temp = curr_bound;
            curr_weight += cost[curr_path[level-1]][i];

            if(level == 1)
                curr_bound -= ((firstMin(curr_path[level-1]) + firstMin(i)) / 2);
            else
                curr_bound -= ((secondMin(curr_path[level-1]) + firstMin(i)) / 2);

            if(curr_bound + curr_weight < final_res) {
                curr_path[level] = i;
                visited[i] = true;

                TSPRec(curr_bound, curr_weight, level + 1);
            }

            curr_weight -= cost[curr_path[level-1]][i];
            curr_bound = temp;

            for(int j = 0; j < n; j++)
                visited[j] = false;

            for(int j = 0; j < level; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void TSP() {

    int curr_bound = 0;

    for(int i = 0; i < n; i++)
        curr_bound += (firstMin(i) + secondMin(i));

    curr_bound = (curr_bound & 1)? curr_bound/2 + 1 : curr_bound/2;

    visited[0] = true;
    curr_path[0] = 0;

    TSPRec(curr_bound, 0, 1);

    cout << "\nMinimum Cost: " << final_res << endl;

    cout << "Path: ";
    for(int i = 0; i <= n; i++)
        cout << final_path[i] << " ";
    cout << endl;
}

int main() {

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for(int i = 0; i < n; i++)
        visited[i] = false;

    TSP();

    return 0;
}
