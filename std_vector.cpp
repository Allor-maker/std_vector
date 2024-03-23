#include "std_vector.h"
#include <iostream>

void vector:: print() const
{
	for (int i = 0; i < this->n; i++)
	{
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}
double& vector::operator[](int i)
{
	return this->data[i];
}
vector& vector::operator=(const vector& v)
{
	if (&v == this)
		return *this;
	this->n = v.n;
	capacity = v.capacity;
	delete[] data;
	data = new double[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = v.data[i];
	}
	return *this;
}
vector& vector::push_back(double elem)
{
	if (n >= capacity)
	{
		double* data2 = new double[capacity * 2];
		for (int i = 0; i < this->n; i++)
		{
			data2[i] = this->data[i];
		}
		data2[this->n] = elem;
		delete[] data;
		data = data2;
		n += 1;
		capacity *= 2;
		return *this;
	}
	else
	{
		this->data[n] = elem;
		n += 1;
		return *this;
	}
}

vector& vector::pop_back()
{
	if (n == 0) throw 0;
	double quater = 0.33 * capacity;
	if ((double)n <= quater)
	{
		n -= 1;
		capacity = 2 * n;
		double* data2 = new double[capacity];
		for (int i = 0; i < (this->n); i++)
		{
			data2[i] = data[i];
		}
		for (int i = this->n; i < capacity; i++)
		{
			data2[i] = 0;
		}
		delete[] data;
		data = data2;
		return *this;
	}
	else
	{
		this->data[n - 1] = 0;
		n -= 1;
		return *this;
	}
}

vector& vector::insert(double elem, int pos)
{
	if (pos == this->n)
		return this->push_back(elem);

	if (pos > this->n || pos < 0) throw 0;

	if (n >= capacity)
	{

		double* data2 = new double[capacity * 2];
		for (int i = 0; i < pos; i++)
		{
			data2[i] = this->data[i];
		}
		data2[pos] = elem;
		for (int i = pos; i < this->n; i++)
		{
			data2[i + 1] = data[i];
		}
		delete[] data;
		data = data2;
		n += 1;
		capacity *= 2;
		return *this;
	}
	else
	{
		for (int i = n; i > pos; i--)
		{
			data[i] = data[i - 1];
		}
		this->data[pos] = elem;
		n += 1;
		return *this;
	}
}

vector& vector::erase(int pos)
{
	if (pos == this->n) return this->pop_back();

	if (pos > n || pos < 0 || n == 0) throw 0;

	double third = 0.33 * capacity;
	if ((double)(n - 1) <= third)
	{
		n -= 1;
		capacity = 2 * n;
		double* data2 = new double[capacity];
		for (int i = n; i > pos; i--)
		{
			data2[i - 1] = data[i];
		}
		for (int i = pos - 1; i > 0; i--)
		{
			data2[i] = data[i];
		}
		delete[] data;
		data = data2;
		return *this;
	}
	else
	{
		for (int i = pos; i < n - 1; i++)
		{
			data[i] = data[i + 1];
		}
		data[n - 1] = 0;
		n -= 1;
		return *this;
	}
}

int vector::size() const
{
	return this->n;
}
int vector::capacity_size() const
{
	return this->capacity;
}
bool vector::empty() const
{
	if (this->n == 0)
		return true;
	return false;
}