#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void optimalStorage(vector<int> &files) {

    sort(files.begin(), files.end());

    int n = files.size();

    int sum = 0;
    int mrt = 0;

    cout << "\nOptimal Order of Files:\n";

    for(int i = 0; i < n; i++) {
        cout << files[i] << " ";

        sum += files[i];
        mrt += sum;
    }

    float mrtAvg = (float)mrt / n;

    cout << "\n\nMean Retrieval Time = " << mrtAvg << endl;
}

int main() {

    int choice;
    vector<int> files;

    do {

        cout << "\n--- Optimal Storage Tape ---\n";
        cout << "1. Enter File Sizes\n";
        cout << "2. Find Optimal Storage Order\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {

                int n;

                cout << "Enter number of files: ";
                cin >> n;

                files.resize(n);

                cout << "Enter file sizes:\n";

                for(int i = 0; i < n; i++)
                    cin >> files[i];

                break;
            }

            case 2: {

                if(files.empty()) {
                    cout << "Enter file sizes first\n";
                    break;
                }

                optimalStorage(files);

                cout << "\n\nTime Complexity = O(n log n)\n";

                break;
            }

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 3);

    return 0;
}
