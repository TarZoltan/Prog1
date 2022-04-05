#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <stdexcept>



using namespace std;

template<typename C>
void print(const C& c){
	for (auto v : c)
        std::cout << v << ' ';
    cout << endl;
}

template<typename C>
void inc(C& c, int n){
	for (auto& i : c)
        i = n + i;
}

template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++=*p;
	}
	
	return f2;
}


int main()
{
	const int size = 10;

	int arr[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


	std::array<int, size> ai;
	std::copy(arr, arr + size, ai.begin());

	vector<int> vi(size);
	std::copy(arr, arr + size, vi.begin());	

	list<int> li(size);
	std::copy(arr, arr + size, li.begin());


    array <int, size> ai2 = ai;
    vector<int> vi2 = vi;
    list<int> li2 = li;

    print(ai);
    print(vi);
    print(li);

    inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	
	print(ai2);
	print(vi2);
	print(li2);
	
	copy2(ai2.begin(), ai2.end(), vi2.begin());
	copy2(li2.begin(), li2.end(), ai2.begin());
	
	print(ai2);
	print(vi2);
	print(li2);



	auto res_v = find(vi2.begin(), vi2.end(), 3);
	if (res_v != vi2.end())
		cout << 3 <<" in vi2: " << distance(vi2.begin(), res_v) << endl;
	else
		cout << 3 << " not found" << endl;

	auto res_l = find(vi2.begin(), vi2.end(), 27);
	if (res_l != vi2.end())
		cout << 27 <<" in vi2: " << distance(vi2.begin(), res_l) << endl;
	else
		cout << 27  << " not found" << endl;


	return 0;
};