#include <iostream>

using namespace std;

int MIN (int a, int b)
{
    return (a>b ? b : a);
}


void init(int n, int **a)
{
	for (int i = 0; i<n; i++) 
	{
		for (int j = 0; j<n; j++)
		{
			if(a[i][j] == -1)
			{
				if (j == i)
				{
					a[i][j] = 0;
				}
				else
				{///////RANDOM////////
					/*int tmp = rand()%5;
					if (tmp == 0)
					{
						a[i][j] =0;
						a[j][i] = a[i][j];
					}*/
					//else
					//{
						//tmp = rand()%50;
						cout << "Enter element of matrix  " << "[" << i+1 <<"]" << "[" << j +1<<"]" <<  "\n";;
						cin >> a[i][j];
						a[j][i] = a[i][j];
					//}
				}
			}
		}
	 }
}


int diametr(int n,vector<vector<int>>& a)
{
	/*int** a = new int*[n];
	for(int i=0; i<n; i++)
	{
		a[i] = new int[n]; 
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = -1;
		}
	}
	init(n,a);*/
	int **edge = new int *[n];
    for (int i = 0; i < n; i++)
        edge[i] = new int [n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            edge[i][j] = a[i][j];
            if (!edge[i][j]) 
                edge[i][j] = 10000;
        }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    edge[i][j] = MIN(edge[i][j], edge[i][k]+edge[k][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (edge[i][j] == 10000) 
                edge[i][j] = 0;
        }
    }
    int max = edge[0][1];
    for(int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++) {
            if(edge[i][j] > max)
                max = edge[i][j];
        }
    }
	cout << endl;
    cout <<"diametr "<< max << endl;
    delete [] edge;
	return 0;
}