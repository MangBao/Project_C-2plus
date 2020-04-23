#include <fstream>
#include <iomanip>
#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
	int m, n, a[100][100];
	ifstream ReadFile("F:\\PIKACHU\\ascii_img\\p\\1.txt");
	//--- Check
	cout << ReadFile.good();
	//system("pause");
	cout << endl;
	//---- cái này mình cho system ("pause"); vì nếu lỗi mở file sẽ in vô hạn
	ReadFile >> m;
	ReadFile >> n;
	for (int i = 0; i < m; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			ReadFile >> a[i][j];
			cin.get();
			cout << setw(100) << a[i][j];
		}
	}
	ReadFile.close();
	return 0;
}
