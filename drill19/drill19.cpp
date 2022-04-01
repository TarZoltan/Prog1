#include <iostream>
#include <string>
#include <vector>


using namespace std;


template<typename T>
struct S{

	S(T vv = 0) : val{vv}{}; // konstruktor
	T& get();
	const T& get() const;
	void set(T a);
	void operator=(const T& s);

private:
	T val;
};


template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{
	return val;
}

template<typename T>
void S<T>::set(T a){
	val = a;
}

template<typename T>
void S<T>::operator=(const T& s){
	val = s;
}

template<typename T>
void read_val(T& v){
	cin >> v;
}


template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{";
	for(int i = 0; i < v.size(); ++i){
		os << v[i] << (i < v.size()-1 ? ", " : " ");
	}
	os << "}\n";
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char ch = 0;
	is >> ch;
	if(ch != '{'){
		is.unget();
		return is;
	}
	for(T val; is >> val;){
		v.push_back(val);
		is >> ch;
		if(ch != ',') break;
	}
	return is;
}


int main(){

	S<int> a;
	a.set(12);
	cout << a.get() << endl;

	S<int> si {42};
	S<char> sc {'z'};
	S<double> sd {3.13};
	S<string> ss {"almafa"};
	S<vector<int>> svi {vector<int> {1, 3, 5, 7}};

	cout << "S<int>: " << si.get() << endl;
	cout << "S<char>: " << sc.get() << endl;
	cout << "S<double>: " << sd.get() << endl;
	cout << "S<string>: " << ss.get() << endl;
	cout << "S<string>: ";

	for (auto& v: svi.get())
	{
		cout << v << " ";
	}
	cout << endl;


	si = 30;
	cout << "S<int>: " << si.get() << endl;


	S<int> si2;


	cout << "si2: ";
	int vi;
	read_val(vi);
	si2.set(vi);
	cout << si2.get() << endl; 

	cout << "Vector (format: {int, int, ... , int}): ";
	vector<int> vint;
	read_val(vint);
	S<vector<int>> svi2 {vint};
	cout << "S<vector<int>> : " << svi2.get();


	return 0;

}