#include <iostream>
using namespace std;

int **createPascalTriangle(int n)
{
    int **Ptriangle = new int *[n];
    for (int i = 0; i < n; i++)
    {
        Ptriangle[i] = new int[n];
    }
    int i, j, x;
    for (i = 0; i < n; i++)
    {
        x = 1;
        for (j = 0; j <= i; j++)
        {
            Ptriangle[i][j] = x;
            /*cout << Ptriangle[i][j] << " ";*/
            x = x * (i - j) / (j + 1);
        }
        /*cout << endl;*/
    }
    return Ptriangle;
}
void displayPascalTriangle(int **pt, int n)
{
    int i, j, x;
    for (i = 0; i < n; i++)
    {
        x = 1;
        for (j = 0; j <= i; j++)
        {
            cout << pt[i][j] << " ";
        }
        cout << endl;
    }
}
void deallocatePascalTriangle(int **pt, int n)
{
    for (int i = 0; i < n; i++)
    {
        pt[i] = nullptr;
        cout << "Destructing stuff\n";
    }
    pt = nullptr;
    delete[] pt;
}
int main()
{
    cout << "Enter the number till you want to print Pascal Triangle\n";
    int n;
    cin >> n;
    int **a = createPascalTriangle(n);
    displayPascalTriangle(a, n);
    deallocatePascalTriangle(a, n);

    return 0;
}
