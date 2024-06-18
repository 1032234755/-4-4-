#include <iostream>
#include <vector>

using namespace std;

vector<double> tridiagonal_solve(vector<double> a, vector<double> b, vector<double> c, vector<double> d) {
    int n = d.size();
    vector<double> alpha(n - 1);
    vector<double> beta(n);

    // Прямой ход
    alpha[0] = -c[0] / b[0];
    beta[0] = d[0] / b[0];

    for (int i = 1; i < n - 1; ++i) {
        alpha[i] = -c[i] / (b[i] + a[i] * alpha[i - 1]);
        beta[i] = (d[i] - a[i] * beta[i - 1]) / (b[i] + a[i] * alpha[i - 1]);
    }

    beta[n - 1] = (d[n - 1] - a[n - 2] * beta[n - 2]) / (b[n - 1] + a[n - 2] * alpha[n - 2]);

    // Обратный ход
    vector<double> x(n);
    x[n - 1] = beta[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }

    return x;
}

int main() {
    vector<double> a = { 0, 7, 21, 7 };
    vector<double> b = { 8, 19, -23, -7 };
    vector<double> c = { -2, 5, 9, 0 };
    vector<double> d = { -14, 55, 49, 8 };

    vector<double> solution = tridiagonal_solve(a, b, c, d);

    cout << "Решение методом прогонки: ";
    for (double x : solution) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
