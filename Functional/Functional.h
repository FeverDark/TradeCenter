// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа FUNCTIONAL_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции FUNCTIONAL_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef FUNCTIONAL_EXPORTS
#define FUNCTIONAL_API __declspec(dllexport)
#else
#define FUNCTIONAL_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <clocale>
#include <cwctype>
#include <codecvt>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <regex>
#include <algorithm>

struct Place {
	Place(int a, int b, int c) {
		this->number = a;
		this->square = b;
		this->occupated = c;
	}
	int number;
	int square;
	int occupated;
};

class Occupant {
protected:
	std::wstring name;
	std::wstring contactName;
	std::wstring contact;
	std::wstring dateStart;
	std::wstring dateEnd;
	int price;
	int type = 0;
public:
	Occupant();
	virtual ~Occupant();
	virtual std::wstring getName();
	virtual std::wstring getContactName();
	virtual std::wstring getContact();
	virtual std::wstring getDateStart();
	virtual std::wstring getDateEnd();
	virtual int getPrice();
	virtual void setName(std::wstring name);
	virtual void setContactName(std::wstring contactName);
	virtual void setContact(std::wstring contact);
	virtual void setDateStart(std::wstring dateStart);
	virtual void setDateEnd(std::wstring dateEnd);
	virtual void setPrice(int price);
	virtual void setType(int type);
	virtual Occupant* copy();
	virtual int getPlace();
	virtual void setPlace(int number);
};

class PlaceOccupant : public Occupant {
private:
public:
	PlaceOccupant(std::wstring name, std::wstring contactName, std::wstring contact, std::wstring dateStart, std::wstring dateEnd, int price);
	~PlaceOccupant();
	PlaceOccupant(const PlaceOccupant& temp);
	Occupant* copy();
};

class QuarterOccupant : public Occupant {
private:
	int placeNumber;
public:
	QuarterOccupant(std::wstring name, std::wstring contactName, std::wstring contact, std::wstring dateStart, std::wstring dateEnd, int price, int placeNumber);
	~QuarterOccupant();
	QuarterOccupant(const QuarterOccupant& temp);
	Occupant* copy();
	int getPlace() override;
	void setPlace(int number) override;
};

struct Comp
{
	bool operator()(Occupant* s, int i);
	bool operator()(int i, Occupant* s);
};

struct CompSet {
	bool operator() (Occupant* a, Occupant* b) const;
};

class DB {
public:
	std::vector<Place> places;
	std::set<Occupant*, CompSet>* placeOccupants;
	std::set<Occupant*, CompSet>* quarterOccupants;
	DB();
	~DB();
	DB(const DB& temp);
	DB& operator=(const DB& temp);
	void save();
};

void FUNCTIONAL_API getData(std::vector<std::vector<std::wstring>>& data, std::wstring find, int number);
void FUNCTIONAL_API deleteRent(std::wstring name, std::wstring placeNumber);
void FUNCTIONAL_API addRent(int type, std::wstring name, std::wstring contactName, std::wstring contact, std::wstring dateStart, std::wstring dateEnd, int price, int placeNumber);
std::vector<Place> FUNCTIONAL_API getPlaces();