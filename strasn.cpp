#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> mat;

mat add(mat a, mat b){
    
    int n = a.size();
    mat c(n, vector<int> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    return c;
}

mat sub(mat a, mat b){
    
    int n = a.size();
    mat c(n, vector<int> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    return c;
}

mat multi(mat a, mat b, int n){
    mat c(n, vector<int> (n));
    if(n == 1){
        c[0][0] = a[0][0] * b[0][0];
        return c;
    }

    int k = n/2;
    // a11 a12     b11 b12
    // a21 a22     b21 b22

    // m1 = (a11+a22)(b11+b22)
    // m2 = (a21 + a22) b11
    // m3 = a11(b12 - b22)
    // m4 = a22(b21 - b11)
    // m5 = (a11+a12)b22
    // m6 = (a21-a11)(b11+b12)
    // m7 = (a12 - a22)(b21 + b22)



    mat a11(k, vector<int> (k)), a12(k, vector<int> (k)), a21(k, vector<int> (k)), a22(k, vector<int> (k));
    mat b11(k, vector<int> (k)), b12(k, vector<int> (k)), b21(k, vector<int> (k)), b22(k, vector<int> (k));

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][k+j];
            a21[i][j] = a[i+k][j];
            a22[i][j] = a[i+k][j+k];


            b11[i][j] = b[i][j];
            b12[i][j] = b[i][k+j];
            b21[i][j] = b[i+k][j];
            b22[i][j] = b[i+k][j+k];
        }
    }


    mat m1 = multi(add(a11, a22), add(b11, b22), k);
    mat m2 = multi(add(a21,a22), b11, k);
    mat m3 = multi(sub(b12, b22), a11, k);
    mat m4 = multi(sub(b21, b11), a22, k);
    mat m5 = multi(add(a11,a12), b22, k);
    mat m6 = multi(sub(a21, a11), add(b11, b12), k);
    mat m7 = multi(sub(a12, a22), add(b21, b22), k);

    // c11 = m1+m4-m5+m7;
    // c12 = m3+m5
    // c21 = m2+m4
    // c22 = m1+m3-m2+m6

    mat c1 = add(m1, add(sub(m4, m5), m7));
    mat c2 = add(m3, m5);
    mat c3 = add(m2, m4);
    mat c4 = add(m1, add(sub(m3, m2), m6));

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            c[i][j] = c1[i][j];
            c[i][j+k] = c2[i][j];
            c[i+k][j] = c3[i][j];
            c[i+k][k+j] = c4[i][j];
        }
    }


    return c;

}


int main(){
    int choice, n;
    mat a, b;


    do{
        cout<<"1. enter matrices"<<endl;
        cout<<"2. multiply"<<endl;
        cout<<"3. exit"<<endl;

        cout<<"choice : ";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"size : ";
                cin>>n;

                cout<<"enter matrice 1 : "<<endl;
                a.resize(n), b.resize(n);
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        int temp;
                        cin>>temp;
                        a[i].push_back(temp);
                    }
                }

                cout<<"enter matrice 2 : "<<endl;
                // a.resize(n), b.resize(n);
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        int temp;
                        cin>>temp;
                        b[i].push_back(temp);
                    }
                }
                break;
            }
            case 2:{
                mat c = multi(a, b, n);
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        cout<<c[i][j]<<" ";
                    }
                    cout<<endl;
                }
                break;
            }

            case 3:{
                cout<<"..."<<endl;
                break;
            }
            default : break;
        }
    }while(choice != 3);
    return 0;
}
