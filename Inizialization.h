#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <queue>


using namespace std;

void init_gr(int n, vector<vector<int>>& a,int param)
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
				{
					switch (param) // начало оператора switch
					  {
						  case 1: // если count = 1
						 {
						 
							a[i][j] = 1;
						
						 break;
						 }
						 case 2: // если count = 1
						 {
						  int tmp = rand()%100;
					      if(tmp < 50)
						  {
							a[i][j] = 1;
							a[j][i] = a[i][j];
						  }
						  else
						  {
							a[i][j] = 0;
							a[j][i] = a[i][j];
						  }
						 break;
						 }
						 case 3:  
						 {
						 int tmp = rand()%100;
					      if(tmp < 33)
						  {
							a[i][j] = 1;
							a[j][i] = a[i][j];
						  }
						  else
						  {
							a[i][j] = 0;
							a[j][i] = a[i][j];
						  }
						 break;
						 }
						 case 4:  
						 {
						 int tmp = rand()%100;
					      if(tmp < 25 )
						  {
							a[i][j] = 1;
							a[j][i] = a[i][j];
						  }
						  else
						  {
							a[i][j] = 0;
							a[j][i] = a[i][j];
						  }
						 break;
						 }
						 case 5:  
						 {
						 int tmp = rand()%100;
					      if(tmp < 20 )
						  {
							a[i][j] = 1;
							a[j][i] = a[i][j];
						  }
						  else
						  {
							a[i][j] = 0;
							a[j][i] = a[i][j];
						  }
						 break;
						 }
						 case 6:  
						 {
						 int tmp = rand()%100;
					      if(tmp < 17 )
						  {
							a[i][j] = 1;
							a[j][i] = a[i][j];
						  }
						  else
						  {
							a[i][j] = 0;
							a[j][i] = a[i][j];
						  }
						 break;
						 }
						 case 7:  
						 {
						 int tmp = rand()%100;
					      if(tmp < 14 )
						  {
							a[i][j] = 1;
							a[j][i] = a[i][j];
						  }
						  else
						  {
							a[i][j] = 0;
							a[j][i] = a[i][j];
						  }
						 break;
						 }
						 case 8:  
						 {
						 int tmp = rand()%100;
					      if(tmp < 12 )
						  {
							a[i][j] = 1;
							a[j][i] = a[i][j];
						  }
						  else
						  {
							a[i][j] = 0;
							a[j][i] = a[i][j];
						  }
						 break;
						 }
						 
						 
						 default: // если count равно любому другому значению
						 cout << "Nepravilni vvod" << endl;
						 }
				//{///////RANDOM////////
				//	/*int tmp = rand()%5;
				//	if (tmp == 0)
				//	{
				//		a[i][j] =0;
				//		a[j][i] = a[i][j];
				//	}*/
				//	//else
				//	//{
				//		//tmp = rand()%50;
				//		/*cout << "Enter element of matrix  " << "[" << i+1 <<"]" << "[" << j +1<<"]" <<  "\n";;
				//		cin >> a[i][j];
				//		a[j][i] = a[i][j];*/
				//	 int tmp = rand()%50;
				//	 if(tmp > 25)
				//	 {
				//		a[i][j] = 1;
				//		a[j][i] = a[i][j];
				//	 }
				//	 else
				//	 {
				//		a[i][j] = 0;
				//		a[j][i] = a[i][j];
				//	 }
				//	//}
				}
			}
		}
	 }
}

int BFS(int n,int s,vector<vector<int>>& g)
{
	/*vector<vector<int> > g(n);

	for(size_t i = 0; i < n; ++i)
    {
        g[i].resize(n);
        for(size_t j = 0; j < n; ++j)
		{
			g[i][j] = -1;
		}
    }
	init_gr(n,g);*/
	int tmp = -1;
	queue<int> q;
	q.push (s);
	vector<bool> used (n);
	vector<int> d (n), p (n);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (size_t i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			if (to == 1)
			{

				if (!used[i]) {
					used[i] = true;
					q.push (i);
					d[i] = d[v] + 1;
					p[i] = v;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "for " << i+1 << " versh ";
		cout << d[i] << " ";
		cout << p[i] + 1 << endl;
	}
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		if (d[i] > max)
		{
			max = d[i];
		}
	}
	cout << "diametr: "<< max << endl;
	for (int i = 0; i < n; i++)
	{
		if (d[i] == max)
		{
			tmp = i;
			break;
		}
	}
	return tmp;
}