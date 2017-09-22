#include<iostream>
#include<string>
#include<vector>
using namespace std;

class LRS{
    string _language;
    string _religion;
    string _sign;
public:
    LRS(string language, string religion, string sign):_language(language), _religion(religion), _sign(sign){
    }

    bool checkEquality(LRS lrs){ // Use Operator overloading
        if(
            this->_language.compare(lrs._language) == 0
            and this->_religion.compare(lrs._religion) == 0
            and this->_sign.compare(lrs._sign) == 0
        ){
            return true;
        }else{
            return false;
        }
    }

    void displayLrs(){
		cout << "Language  =" << _language << endl;
		cout << "Religion  =" << _religion << endl;
		cout << "Sign      =" << _sign << endl;
    }
};

class storage{
    vector<LRS> lrs;
public:
    int storageInsert(LRS myLrs){
        for(int i=0; i<lrs.size(); i++){
            if(lrs[i].checkEquality(myLrs)){
                return i;
            }
        }
        lrs.push_back(myLrs);
        return lrs.size()-1;
    }
    void displayStorage(int index){
        lrs[index].displayLrs();
    }
    void printStorage(){
        cout << "Contents of the storage are :" << endl;
        for(int i=0; i<lrs.size(); i++){
            lrs[i].displayLrs();
            cout << "===========" << endl;
        }
    }
};

storage myStorage;

class Human
{
	string _name;
	string _age;
	string _education;
    int _storageIndex;
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
        LRS myLrs( language, religion, sign);
        _storageIndex = myStorage.storageInsert(myLrs);
	}

	void Display()
	{
        myStorage.displayStorage(_storageIndex);
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
    myStorage.printStorage();
}
