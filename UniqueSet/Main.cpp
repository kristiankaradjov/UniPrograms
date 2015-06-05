#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Set
{
private:
	const static unsigned int chunk = 2;
	int size;
	T * data;
	int top;

public:
	Set() :size(chunk), data(new T[size]), top(-1){}
	~Set(){ delete[] data; }
	Set(const Set & right) :size(right.size), data(new T[size]), top(right.top)
	{
		for (int i = 0; i<size; i++)
			data[i] = right.data[i];
	}
	Set& operator=(const Set & right)
	{
		if (this != &right){
			delete[] data;
			size = right.size;
			data = new T[size];
			top = right.top;
			for (int i = 0; i<size; i++)
				data[i] = right.data[i];
		}
		return *this;
	}
	void push(const T & v)
	{
		if (comp(v))
		{
			if (top >= (size - 1)) resize();
			data[++top] = v;
		}
		else
		{
			cout << v<<"is already in the set" << endl;
		}
}
	T pop(){
		if (top < 0)
		{
			cout << "There is no more data " << endl;
			cout << "The last element was: ";
			return data[top + 1];
		}
		else
		{
			return data[top--];
		}
	}
	bool comp(T v)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == v)
			{
				return false;
			}
		}
		return true;
	}
private:
	void resize(){
		T * oldData = data;
		data = new T[size + chunk];
		for (int i = 0; i<size; i++)
			data[i] = oldData[i];
		delete[] oldData;
		size += chunk;
	}
};

int main(){
	Set<int> st;
	st.push(1);
	st.push(2);
	st.push(1);
	st.push(4);
	Set<int> st1 = st;

	cout << st.pop() << endl;
	cout << st.pop() << endl;
	cout << st.pop() << endl;
	cout << st.pop() << endl;

	cout << st1.pop() << endl;
	cout << st1.pop() << endl;
	cout << st1.pop() << endl;
	cout << st1.pop() << endl;


	return 0;
}
