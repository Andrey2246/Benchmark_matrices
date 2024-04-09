#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

int MAT_SIZE = 1000;

void dgemm_blas(vector<vector<double>> &m1, vector<vector<double>> &m2, vector<vector<double>> &out){
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            for (int k = 0; k < MAT_SIZE; ++k) {
                out[i][j] += m1[i][k] * m2[k][j];
            }
        }
        cout<<i<<endl;
    }
}

void print_matrix(vector<vector<double>> m1){
    for (int i = 0; i < MAT_SIZE; i++){
        for (int j = 0; j < MAT_SIZE; j++){
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }
}

void fill_matrixes(vector<vector<double>> &m1, vector<vector<double>> &m2){
    for (int i = 0; i < MAT_SIZE; i++){
        for (int j = 0; j < MAT_SIZE; j++){
            m1[i][j] = rand() % 100 ;
            m2[i][j] = rand() % 100 ;
        }
    }

}

int main() {
    vector<vector<double>> m1(MAT_SIZE, vector<double>(MAT_SIZE));
    vector<vector<double>> m2(MAT_SIZE, vector<double>(MAT_SIZE));
    fill_matrixes(m1, m2);
    vector<vector<double>> out(MAT_SIZE, vector<double>(MAT_SIZE));
    auto start = chrono::high_resolution_clock::now(); 
    dgemm_blas(m1, m2, out);
    auto diff = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start);
    cout << diff.count() << endl;
}