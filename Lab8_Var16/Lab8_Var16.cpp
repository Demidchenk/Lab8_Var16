#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

typedef int matrix[100][100];
int n;

void input(matrix a)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 100;
}

void output(matrix a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

int minElem(matrix a, int r, int c)
{
    int min = a[r][c];
    if (r < c)
    {
        for (int i = r; i <= c; i++)
            for (int j = i; j <= c; j++)
                if (a[i][j] < min) min = a[i][j];
    }
    else
    {
        for (int i = c; i <= r; i++)
            for (int j = c; j <= i; j++)
                if (a[i][j] < min) min = a[i][j];
    }
    return min;
}

void genMatr(matrix a, matrix b)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = minElem(a, i, j);
}

int main()
{
    cout << "Input n:\n";
    cin >> n;
    matrix a, b;
    input(a);
    cout << "Matrix A:\n";
    output(a);
    genMatr(a, b);
    cout << "Matrix B:\n";
    output(b);
}
