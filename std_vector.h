#pragma once

class vector
{
private:
	double* data = nullptr;
	int n = 0;
	int capacity = 0;
	int factor = 2 * n;//amount of memory allocated in the constructor
public:	
	vector():n(0),capacity(1)
	{
		data = new double[capacity];
	}

	vector(int n,double elem = 0):n(n)
	{
		capacity = factor;
		data = new double[capacity];
		for (int i = 0; i < this->n; i++)
		{
			data[i] = elem;
		}
	}

	vector(double* arr,int n) :n(n)
	{
		capacity = factor;
		data = new double[capacity];
		for (int i = 0; i < n; i++)
		{
			data[i] = arr[i];
		}
	}

	vector(const vector& v) : n(v.n),capacity(v.capacity)
	{
		this->data = new double[n];
		for (int i = 0; i < n; i++)
		{
			data[i] = v.data[i];
		}
	}
	void print() const;

	double& operator[](int i);

	vector& operator=(const vector& v);

	vector& push_back(double elem);
	
	vector& pop_back();

	vector& insert(double elem, int pos);

	vector& erase(int pos);

	int size() const;

	int capacity_size() const;

	bool empty() const;

	~vector()
	{
		delete[] data;
	}
};