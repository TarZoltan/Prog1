#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Person{

private:

	string first_name;
	string second_name;
	int age;

public:

	Person(){};
	Person(string fn, string sn, int a){

		if (a<=0 || a > 150)
        {
            throw runtime_error("Invalid age!");
        }

        string n = fn + sn;

        for (int i = 0; i < n.length(); ++i)
        {
            if (n[i] == ':' || n[i] == ';' || n[i] == '[' || n[i] == ']' || n[i] == '\'' || n[i] == '"'
            	|| n[i] == '&'|| n[i] == '*'|| n[i] == '&'|| n[i] == '^'|| n[i] == '%'|| n[i] == '$'
            	|| n[i] == '#'|| n[i] == '@'|| n[i] == '!')
        {
            throw runtime_error("Invalid character!");
        }
            
        }

		first_name = fn;
		second_name = sn;
		age = a;
		
	}

	string get_first_name(){
		return first_name;
	}

	string get_second_name(){
		return second_name;
	}

	int get_age(){
		return age;
	}


	void set_first_name(string x){
		first_name = x;
	}

	void set_second_name(string x){
		second_name = x;
	}

	void set_age(int x){
		age = x;
	}



} ;


istream& operator>> (istream& is, Person& p)
{

	string fn;
	string sn;
	int a;

    is >> fn >> sn >> a;

    p.set_first_name(fn);
    p.set_second_name(sn);
    p.set_age(a);
    return is;

}

    ostream& operator<< (ostream& os, Person& p)
{
    os << p.get_first_name() << ' ' << p.get_second_name() << " " << p.get_age() << endl;;
    return os;
}


int main(){

	Person p1;

	p1.set_age(63);
	p1.set_first_name("Goofy");
	p1.set_second_name("GOO");

	cout << p1.get_first_name() << " "  << p1.get_second_name() << " " << p1.get_age() << endl;

	Person p2;

	//cin >> p2;

	//cout << p2;

	Person p3("Elem", "Ér", 41);
	cout << p3;

	std::vector<Person> vp;
	Person p;

	while(cin >> p){
		vp.push_back(p);
	};


	for (int i = 0; i < vp.size(); ++i)
	{
		cout << vp[i] << endl;
	}


	return 0;


}