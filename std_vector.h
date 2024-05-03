#pragma once
template <class T>
class vector
{
private:
	T* data = nullptr;
	int n = 0;
	int capacity = 0;
	int factor = 2 * n;//amount of memory allocated in the constructor
public:	
	class Iterator
	{
	private:
		T* ptr = nullptr;
	public:
		Iterator() :ptr(0) {}
		Iterator(T* p) : ptr(p) {}

		T& operator*()
		{
			return *ptr;
		}
		T* operator->()
		{
			return ptr;
		}

		Iterator& operator++()
		{
			++ptr;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator cp = *this;
			ptr++;
			return cp;
		}
		Iterator& operator--()
		{
			--ptr;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator cp = *this;
			ptr--;
			return cp;
		}

		Iterator operator+(int j) const
		{
			return Iterator(ptr + j);
		}
		Iterator operator-(int j) const
		{
			return Iterator(ptr - j);
		}
		Iterator begin()
		{
			return data;
		}
		Iterator end()
		{
			return (data + n);
		}


	};
	vector():n(0),capacity(1)
	{
		data = new T[capacity];
	}

	vector(int n,T elem):n(n)
	{
		capacity = factor;
		data = new T[capacity];
		for (int i = 0; i < this->n; i++)
		{
			data[i] = elem;
		}
	}

	vector(T* arr,int n) :n(n)
	{
		capacity = factor;
		data = new T[capacity];
		for (int i = 0; i < n; i++)
		{
			data[i] = arr[i];
		}
	}

	vector(const vector& v) : n(v.n),capacity(v.capacity)
	{
		this->data = new T[n];
		for (int i = 0; i < n; i++)
		{
			data[i] = v.data[i];
		}
	}
	void print() const
	{
		for (int i = 0; i < this->n; i++)
		{
			std::cout << this->data[i] << " ";
		}
		std::cout << std::endl;
	}

	T& operator[](int i)
	{
		return this->data[i];
	}

	vector<T>& operator=(const vector<T>& v)
	{
		if (&v == this)
			return *this;
		this->n = v.n;
		capacity = v.capacity;
		delete[] data;
		data = new T[n];
		for (int i = 0; i < n; i++)
		{
			data[i] = v.data[i];
		}
		return *this;
	}

	vector<T>& push_back(T elem)
	{
		if (n >= capacity)
		{
			T* data2 = new T[capacity * 2];
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
	
	vector<T>& pop_back()
	{
		if (n == 0) throw 0;
		double quater = 0.33 * capacity;
		if ((double)n <= quater)
		{
			n -= 1;
			capacity = 2 * n;
			T* data2 = new T[capacity];
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

	vector<T>& insert(T elem, int pos)
	{
		if (pos == this->n)
			return this->push_back(elem);

		if (pos > this->n || pos < 0) throw 0;

		if (n >= capacity)
		{

			T* data2 = new T[capacity * 2];
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

	vector<T>& erase(int pos)
	{
		if (pos == this->n) return this->pop_back();

		if (pos > n || pos < 0 || n == 0) throw 0;

		double third = 0.33 * capacity;
		if ((double)(n - 1) <= third)
		{
			n -= 1;
			capacity = 2 * n;
			T* data2 = new T[capacity];
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

	int size() const
	{
		return this->n;
	}
	int capacity_size() const
	{
		return this->capacity;
	}
	bool empty() const
	{
		if (this->n == 0)
			return true;
		return false;
	}

	~vector()
	{
		delete[] data;
	}
};