#include <iostream>
#include <stdexcept>
#include <string>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <vector>


using namespace std;

template <typename C>
void print(const C& c, char sep = '\n'){
	cout << "Elements: " << endl;
	

	for(const auto elem: c){
		cout << elem << sep;
	}
}



int main()
try {

	const string iname {"input.txt"};
	ifstream ifs {iname};

	vector<double> vd;
	for (double d; ifs >> d;){
		vd.push_back(d);
	}

	cout.precision(10);

	print(vd);

	vector<int> vi(vd.size());
/*
	for(auto& i: vd){
		vi.push_back(i);
	}
*/
	copy(vd.begin(), vd.end(), vi.begin());

	print(vi);

	for (int i = 0; i < vd.size(); i++)
	{
		cout << vd[i] << '\t' << vi[i] <<endl;
	}

	double sumd = accumulate(vd.begin(), vd.end(), 0.0);

	cout << "Double sum: "<<  sumd << endl;

	double sumi = accumulate(vi.begin(), vi.end(), 0.0);

	cout << "Int sum: "<< sumi << endl;

	cout << "kul: "<< sumd - sumi << endl;

	reverse(vd.begin(), vd.end());
	print(vd);

	double vd_mean = sumd / vd.size();
	cout << "Mean d: " << vd_mean << endl;


	vector<double> vd2;

	for (int i = 0; i < vd.size(); i++){
		if (vd[i] < vd_mean)
		{
			vd2.push_back(vd[i]);
		}
	}
// létezik valami copy_if
	print(vd2);

	sort(vd.begin(), vd.end());
	print(vd);


}
catch(std::exception& e) {
	std::cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch(...) {
	std::cerr << "Unknown exception\n";
	return 2;
}