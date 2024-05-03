#include <iostream>
#include "std_vector.h"

int main()
{

	vector<int> v(2,1);
	v.print();

	double* arr1 = new double[5];
	for (int i = 0; i < 5; i++)
	{
		arr1[i] = i;
	}

	int j = 0;
	vector<double> v2(arr1, 5);
	v2.push_back(5);
	v2.print();
	j = v2.capacity_size();
	std::cout << j << std::endl;

	int i = 0;//capacity
	vector<int> v3(1, 1);
	v3.print();
	i = v3.capacity_size();
	std::cout << i << std::endl;
	
	v3.push_back(1);
	v3.print();
	i = v3.capacity_size();
	std::cout << i << std::endl;

	v3.push_back(4);
	v3.print();
	i = v3.capacity_size();
	std::cout << i << std::endl;

	int i2 = 0;
	v2.pop_back();
	v2.print();
	i2 = v2.capacity_size();
	std::cout << i2 << std::endl;

	v2.pop_back();
	v2.print();
	i2 = v2.capacity_size();
	std::cout << i2 << std::endl;

	v2.pop_back();
	v2.print();
	i2 = v2.capacity_size();
	std::cout << i2 << std::endl;

	v2.pop_back();
	v2.print();
	i2 = v2.capacity_size();
	std::cout << i2 << std::endl;


	vector<double> v4(arr1, 5);
	v4.print();
	int i3 = 0;

	v4.insert(9, 2);
	v4.print();
	i3 = v4.capacity_size();
	std::cout << i3 << std::endl;

	vector<int> v5(2, 1);
	v5.insert(3, 1);
	v5.insert(4, 2);
	v5.print();
	i3 = v5.capacity_size();
	std::cout << i3 << std::endl;

	v5.insert(5, 3);
	v5.print();
	i3 = v5.capacity_size();
	std::cout << i3 << std::endl;

	v5.insert(9, 5);
	v5.print();

	vector<int> v6(v5);
	v6.erase(3);
	v6.print();
	i3 = v6.capacity_size();
	std::cout << i3 << std::endl;

	v6.erase(2);
	v6.print();

	v6.erase(1);
	v6.print();

	v6.erase(0);
	v6.print();
	i3 = v6.capacity_size();
	std::cout << i3 << std::endl;

	vector<int> V;
	V.push_back(1);
	V.print();
	V.pop_back();
	bool value = V.empty();
	std::cout << value << std::endl;

	vector<char> Ch(4,'a');
	Ch.print();

	Ch.push_back('i');
	Ch.print();
	

}