#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <queue>
#include "Diametr.h"
#include "Inizialization.h"

using namespace std;

int main()
{
	int tmp = -1;
	srand (time(NULL));
	int n;
	cout << "Enter number of Graph" << "\n";
	cin >> n;
	vector<vector<int> > g(n);
	for(size_t i = 0; i < n; ++i)
    {
        g[i].resize(n);
        for(size_t j = 0; j < n; ++j)
		{
			g[i][j] = -1;
		}
    }
	int param;
	cout << "Vvedite param zapolneni9"<< endl;
	cin >> param;
	int k;
	cout << "Vvedite param poiska"<< endl;
	cin >> k;
	int s;
	cout << "Vvedite vershinu s kotoroy nahcat` poisk"<< endl;
	cin >> s;
	init_gr(n,g,param);
	///////////////////////
	 for_each(g.begin(), g.end(), [](vector<int>& ivec)
		{
			for_each(ivec.begin(), ivec.end(), [](int i)
			{
				cout << left << setw(5) << i;
			});
			cout << endl;
		});
    ///////////////////////////////
	diametr(n,g);
	for (int i = 0; i < k; i++)
	{
		s = BFS(n,s,g);
	}
	return 0;
}