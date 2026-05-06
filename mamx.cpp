#include <iostream>
#include <vector>
using namespace std;

pair<int,int> findMinMax(vector<int> &arr, int low, int high) {

    if(low == high)
        return {arr[low], arr[low]};

    if(high == low + 1) {
        if(arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    int mid = (low + high) / 2;

    pair<int,int> left = findMinMax(arr, low, mid);
    pair<int,int> right = findMinMax(arr, mid + 1, high);

    int minimum = min(left.first, right.first);
    int maximum = max(left.second, right.second);

    return {minimum, maximum};
}

int main() {

    int choice;
    vector<int> arr;
    int n;

    do {
        cout << "\n--- Min & Max using Divide and Conquer ---\n";
        cout << "1. Enter elements\n";
        cout << "2. Find Min and Max\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter number of elements: ";
                cin >> n;

                arr.resize(n);
                cout << "Enter elements:\n";
                for(int i = 0; i < n; i++)
                    cin >> arr[i];
                break;

            case 2:
                if(arr.empty()) {
                    cout << "Enter elements first\n";
                } else {
                    pair<int,int> result = findMinMax(arr, 0, arr.size()-1);
                    cout << "Minimum: " << result.first << endl;
                    cout << "Maximum: " << result.second << endl;
                }
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 3);

    return 0;
}
