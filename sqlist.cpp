#include<bits/stdc++.h>
using namespace std;

template<typename T>
class SequenceList{
private:
	T* data;
	int size;
	int capacity;
public:
	SequenceList():data(nullptr), size(0), capacity(10){
		data = new T[capacity];
	}
	~SequenceList(){
		delete[] data;
	}
	void ExpandCapacity(){
		capacity *= 2;
		T* newData = new T[capacity];
		for(int i = 0; i < size; ++i){
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	void insert(int pos, T t){
		if(pos < 0 || pos >= size){
			cout << "Position is wang!\n";
			return; 
		}
		if(capacity == size){
			ExpandCapacity();
		}
		for(int i = size - 1; i >= pos; --i){
			data[i + 1] = data[i];
		}
		data[pos] = t;
		++size;
	}
	void append(T t){
		if(size == capacity){
			ExpandCapacity();
		}
		data[size] = t;
		++size;
	}
	void Display(){
		for(int i = 0; i < size; ++i){
			cout << data[i] << " ";
		}
		cout << endl;
	}
	int GetSize(){
		return size;
	}
	bool IsEmpty(){
		if(size == 0){
			return true;
		}else{
			return false;
		}
	}
	T at(int pos){
		if(pos < 0 || pos >= size){
			cout << "Position is out of range!\n";
		}
		return data[pos];
	}
	int find(T t){
		for(int i = 0; i < size; ++i){
			if(t == data[i]){
				return i;
			}
		}
		return size;
	}
	void Delete(int pos){
		if(pos < 0 || pos >= size){
			cout << "Index is out of range!\n";
			return;
		}
		for(int i = pos; i < size - 1; ++i){
			data[i] = data[i + 1];
		}
		--size;
	}
};

int main(){
	SequenceList<char>l;
	l.append('a');
	l.append('b');
	l.append('c');
	l.append('d');
	l.append('e');
	l.Display();
	cout << "Length:  " << l.GetSize() << endl;
	if(l.IsEmpty()){
		cout << "List is empty" << endl;
	}else{
		cout << "List isn`t empty" << endl;
	}
	cout << l.at(2) << endl;
	cout << "a.at " << l.find('a') << endl;
	l.insert(3, 'f');
	l.Display();
	l.Delete(2);
	l.Display();
	return 0;
}