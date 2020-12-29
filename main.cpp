#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<vector<int>> A1;
	vector<int>A2;
	vector<vector<int>>::iterator it1;
	vector<int>::iterator it2;
	vector<int>::iterator it3;
	int m, n;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;
	A1.resize(m);
	A2.resize(m * n);
	for (it1 = A1.begin(); it1 != A1.end(); it1++) { (*it1).resize(n); }
	for (it1 = A1.begin(); it1 != A1.end(); it1++)
	{
		for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
		{
			cout << "Enter new element: ";
			cin >> *it2;
		}
	}

	for (it1 = A1.begin(); it1 != A1.end(); it1++)
	{
		for (it2 = (A1.at(distance(A1.begin(), it1))).begin(); it2 != (A1.at(distance(A1.begin(), it1))).end(); it2++)
		{
			it3 = A2.begin() + n * (it1 - A1.begin()) + distance((*it1).begin(), it2);;
			*it3 = *it2;
		}
	}
	cout << "\nNew array: ";
	for (it2 = A2.begin(); it2 != A2.end(); it2++) { cout << *it2 << ' '; }

	vector<vector<int>> A3;
	A3.resize(m);
	for (it1 = A3.begin(); it1 != A3.end(); it1++) { (*it1).resize(n); }
	for (it2 = A2.begin(); it2 != A2.end(); it2++)
	{
		it1 = A3.begin() + (it2 - A2.begin()) / n;
		it3 = (*it1).begin() + (it2 - A2.begin()) % n;
		*it3 = *it2;
	}
	cout << "\nReturned first array:\n";
	for (it1 = A3.begin(); it1 != A3.end(); it1++)
	{
		for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
		{
			cout << *it2 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
