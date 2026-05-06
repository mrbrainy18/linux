#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void print(Node* root, string s) {
    if(!root) return;

    if(root->data != '#')
        cout << root->data << " : " << s << endl;

    print(root->left, s + "0");
    print(root->right, s + "1");
}

void huffman(vector<char> &ch, vector<int> &freq) {

    priority_queue<Node*, vector<Node*>, cmp> pq;

    for(int i = 0; i < ch.size(); i++)
        pq.push(new Node(ch[i], freq[i]));

    while(pq.size() > 1) {

        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('#', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    cout << "\nHuffman Codes:\n";
    print(pq.top(), "");
}

int main() {

    int choice;
    vector<char> ch;
    vector<int> freq;

    do {
        cout << "\n--- Huffman Coding ---\n";
        cout << "1. Enter characters & frequencies\n";
        cout << "2. Generate Huffman Codes\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int n;
                cout << "Enter number of characters: ";
                cin >> n;

                ch.clear();
                freq.clear();

                cout << "Enter characters:\n";
                for(int i = 0; i < n; i++) {
                    char c;
                    cin >> c;
                    ch.push_back(c);
                }

                cout << "Enter frequencies:\n";
                for(int i = 0; i < n; i++) {
                    int f;
                    cin >> f;
                    freq.push_back(f);
                }

                break;
            }

            case 2: {
                if(ch.empty()) {
                    cout << "Enter data first\n";
                    break;
                }

                huffman(ch, freq);
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
