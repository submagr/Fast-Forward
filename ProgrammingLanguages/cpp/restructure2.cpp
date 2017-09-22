#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class LRS{
    string _language;
    string _religion;
    string _sign;
public:
    LRS(string language, string religion, string sign):_language(language), _religion(religion), _sign(sign){
    }

    void displayLrs(){
		cout << "Language  =" << _language << endl;
		cout << "Religion  =" << _religion << endl;
		cout << "Sign      =" << _sign << endl;
    }
};

class storage{
    // vector<LRS> lrs;
    static map<string, LRS *> myMap;
public:
    static string createStorage(string language, string religion, string sign){
        string key = language+religion+sign;
        if(myMap[key]==NULL){
            myMap[key] = new LRS(language, religion, sign);
        }
        return key;
    }

    static void Display(string key){
        myMap[key]->displayLrs();
    }
};

map<string, LRS *> storage::myMap;

class Human
{
	string _name;
	string _age;
	string _education;
    string _storageKey;
public:
	static int count;

	Human(string language,
		string religion,
		string sign,
		string name,
		string age,
		string education) :_name(name),
		_age(age),
		_education(education)
	{
		count++;
        _storageKey = storage::createStorage(language, religion, sign);
	}

	void Display()
	{
        storage::Display(_storageKey);
		cout << "Name      =" << _name << endl;
		cout << "Age       =" << _age << endl;
		cout << "Education =" << _education << endl;
		cout << "_____________________________" << endl;
	}
};

int Human::count=0;

int main()
{
	Human hum1("tulu"  , "hindu", "leo"    , "aishwarya" , "40", "msc"   );
	Human hum2("tulu"  , "hindu", "leo"    , "genelia"   , "28", "bsc"   );
	Human hum3("kanada", "hindu", "scorpio", "deepika"   , "25", "bcom"  );
	Human hum4("kanada", "hindu", "scorpio", "juhi"      , "38", "bsc"   );
	Human hum5("telugu", "hindu", "taurus" , "sridevi"   , "48", "visual");
	Human hum6("telugu", "hindu", "taurus" , "hema"      , "55", "visual");

	hum1.Display();
	hum2.Display();
	hum3.Display();
	hum4.Display();
	hum5.Display();
	hum6.Display();

	cout << "Human count =" << Human::count << endl;
    // myStorage.printStorage();
}
