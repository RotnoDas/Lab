#include <iostream>
#include <vector>
using namespace std;
// Function to perform LU Decomposition
bool LU_Decomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();
    // Initialize L and U matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = (i == j) ? 1 : 0; // Diagonal elements of L are 1
            U[i][j] = 0;
        }
    }
    // Perform LU Decomposition
    for (int i = 0; i < n; i++) {
        // Upper Triangular
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }
        // Lower Triangular
        for (int k = i + 1; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[k][j] * U[j][i]);
            }
            if (U[i][i] == 0) {
                cerr << "LU decomposition not possible. Zero pivot encountered." << endl;
                return false;
            }
            L[k][i] = (A[k][i] - sum) / U[i][i];
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the order of matrix: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> L(n, vector<double>(n));
    vector<vector<double>> U(n, vector<double>(n));

    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    if (LU_Decomposition(A, L, U)) {
        cout << "L matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << L[i][j] << " ";
            }
            cout << endl;
        }

        cout << "U matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << U[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
