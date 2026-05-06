#include <iostream>
#include <vector>
using namespace std;

void hamiltonianPath(vector<vector<int>> &graph, int n) {

    vector<int> path(n, -1);
    vector<bool> visited(n, false);

    int pos = 0;

    path[0] = 0;
    visited[0] = true;

    while(pos >= 0) {

        if(pos == n - 1) {

            cout << "\nHamiltonian Path Exists:\n";

            for(int i = 0; i < n; i++)
                cout << path[i] << " ";

            cout << endl;
            return;
        }

        int next = path[pos] + 1;

        bool found = false;

        while(next < n) {

            if(!visited[next] && graph[path[pos]][next] == 1) {

                pos++;

                path[pos] = next;
                visited[next] = true;

                found = true;
                break;
            }

            next++;
        }

        if(!found) {

            visited[path[pos]] = false;
            path[pos] = -1;

            pos--;

            if(pos >= 0)
                path[pos]++;
        }
    }

    cout << "\nNo Hamiltonian Path Exists\n";
}

int main() {

    int choice;

    do {

        cout << "\n--- Hamiltonian Path ---\n";
        cout << "1. Find Hamiltonian Path\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {

                int n;

                cout << "Enter number of vertices: ";
                cin >> n;

                vector<vector<int>> graph(n, vector<int>(n));

                cout << "Enter adjacency matrix:\n";

                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        cin >> graph[i][j];
                    }
                }

                hamiltonianPath(graph, n);

                break;
            }

            case 2:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 2);

    return 0;
}
