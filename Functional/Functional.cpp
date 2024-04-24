// Functional.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "framework.h"
#include "Functional.h"

const std::locale loc = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>);

Occupant::Occupant() {}
Occupant::~Occupant() {}
std::wstring Occupant::getContact() {
	return this->contact;
}
std::wstring Occupant::getContactName() {
	return this->contactName;
}
std::wstring Occupant::getDateEnd() {
	return this->dateEnd;
}
std::wstring Occupant::getDateStart() { 
	return this->dateStart;
}
std::wstring Occupant::getName() {
	return this->name;
}
int Occupant::getPlace() {
	return -1;
}
int Occupant::getPrice() {
	return this->price;
}
void Occupant::setContact(std::wstring contact) {
	this->contact = contact;
}
void Occupant::setContactName(std::wstring contactName) {
	this->contactName = contactName;
}
void Occupant::setDateEnd(std::wstring dateEnd) {
	this->dateEnd = dateEnd;
}
void Occupant::setDateStart(std::wstring dateStart) {
	this->dateStart = dateStart;
}
void Occupant::setName(std::wstring name) {
	this->name = name;
}
void Occupant::setPlace(int) {}
void Occupant::setPrice(int price) {
	this->price = price;
}
void Occupant::setType(int type) {
	this->type = type;
}
Occupant* Occupant::copy() {
	return NULL;
}

PlaceOccupant::PlaceOccupant(std::wstring name, std::wstring contactName, std::wstring contact, std::wstring dateStart, std::wstring dateEnd, int price) {
	this->name = name;
	this->contactName = contactName;
	this->contact = contact;
	this->dateStart = dateStart;
	this->dateEnd = dateEnd;
	this->price = price;
	this->type = 1;
}
PlaceOccupant::~PlaceOccupant() {}
PlaceOccupant::PlaceOccupant(const PlaceOccupant& temp) {
	this->name = temp.name;
	this->contactName = temp.contactName;
	this->contact = temp.contact;
	this->dateStart = temp.dateStart;
	this->dateEnd = temp.dateEnd;
	this->price = temp.price;
	this->type = temp.type;
}
Occupant* PlaceOccupant::copy() {
	return new PlaceOccupant(*this);
}

QuarterOccupant::QuarterOccupant(std::wstring name, std::wstring contactName, std::wstring contact, std::wstring dateStart, std::wstring dateEnd, int price, int placeNumber) {
	this->name = name;
	this->contactName = contactName;
	this->contact = contact;
	this->dateStart = dateStart;
	this->dateEnd = dateEnd;
	this->price = price;
	this->placeNumber = placeNumber;
	this->type = 2;
}
QuarterOccupant::~QuarterOccupant() {}
QuarterOccupant::QuarterOccupant(const QuarterOccupant& temp) {
	this->name = temp.name;
	this->contactName = temp.contactName;
	this->contact = temp.contact;
	this->dateStart = temp.dateStart;
	this->dateEnd = temp.dateEnd;
	this->price = temp.price;
	this->placeNumber = temp.placeNumber;
	this->type = temp.type;
}
Occupant* QuarterOccupant::copy() {
	return new QuarterOccupant(*this);
}
int QuarterOccupant::getPlace() {
	return this->placeNumber;
};
void QuarterOccupant::setPlace(int number) {
	this->placeNumber = number;
};

bool Comp::operator()(Occupant* s, int i) { return s->getName() > std::to_wstring(i); }
bool Comp::operator()(int i, Occupant* s) { return std::to_wstring(i) > s->getName(); }

bool CompSet::operator() (Occupant* a, Occupant* b) const {
	if (a->getName()	 == b->getName())
		return a->getDateStart() < b->getDateStart();
	else
		return a->getName() < b->getName();
}

DB::DB() {
	placeOccupants = new std::set<Occupant*, CompSet>;
	quarterOccupants = new std::set<Occupant*, CompSet>;
	std::wstring name;
	std::wstring contactName;
	std::wstring contact;
	std::wstring dateStart;
	std::wstring dateEnd;
	int price;
	int type;
	int placeNumber;
	int square;
	int occupated;
	std::wistringstream ss;
	tm t;
	time_t time_stamp;
	time_t now;
	std::wifstream file("places.txt");
	file.imbue(loc);
	for (; file.is_open() && !file.eof();) {
		placeNumber = NULL;
		file >> placeNumber >> square >> occupated;
		if (placeNumber != NULL)
			places.push_back(Place(placeNumber, square, occupated));
	}
	file.close();
	file = std::wifstream("rent.txt");
	file.imbue(loc);
	for (; file.is_open() && !file.eof();) {
		type = NULL;
		name = L"";
		file >> type >> name >> contactName >> contact >> dateStart >> dateEnd >> price;
		if (type != NULL && name != L"") 
			switch (type) {
			case 1:
				name = regex_replace(name, std::wregex(L"_"), L" ");
				contactName = regex_replace(contactName, std::wregex(L"_"), L" ");
				dateStart = regex_replace(dateStart, std::wregex(L"_"), L" ");
				dateEnd = regex_replace(dateEnd, std::wregex(L"_"), L" ");
				placeOccupants->insert(new PlaceOccupant(name, contactName, contact, dateStart, dateEnd, price));
				break;
			case 2:
				file >> placeNumber;
				name = regex_replace(name, std::wregex(L"_"), L" ");
				contactName = regex_replace(contactName, std::wregex(L"_"), L" ");
				dateStart = regex_replace(dateStart, std::wregex(L"_"), L" ");
				dateEnd = regex_replace(dateEnd, std::wregex(L"_"), L" ");
				quarterOccupants->insert(new QuarterOccupant(name, contactName, contact, dateStart, dateEnd, price, placeNumber));
				t = {};
				ss = std::wistringstream(dateEnd);
				ss >> std::get_time(&t, L"%d.%m.%Y");
				time_stamp = _mkgmtime(&t);
				now = time(0);
				if (now > time_stamp) {
					for (int i = 0; i < places.size(); ++i) {
						(places[i].number == placeNumber) ? places[i].occupated = 0 : NULL;
					}
				}
				break;
			default:
				name = regex_replace(name, std::wregex(L"_"), L" ");
				contactName = regex_replace(contactName, std::wregex(L"_"), L" ");
				dateStart = regex_replace(dateStart, std::wregex(L"_"), L" ");
				dateEnd = regex_replace(dateEnd, std::wregex(L"_"), L" ");
				placeOccupants->insert(new PlaceOccupant(name, contactName, contact, dateStart, dateEnd, price));
				break;
			}
	}
	file.close();
};
DB::~DB() {
	save();
	for (std::set<Occupant*, CompSet>::const_iterator it = placeOccupants->begin(); it != placeOccupants->end(); ++it)
		delete* it;
	for (std::set<Occupant*, CompSet>::const_iterator it = quarterOccupants->begin(); it != quarterOccupants->end(); ++it)
		delete* it;
	delete placeOccupants;
	delete quarterOccupants;
}
DB::DB(const DB& temp) {
	for (std::set<Occupant*, CompSet>::const_iterator it = placeOccupants->begin(); it != placeOccupants->end(); ++it)
		delete* it;
	for (std::set<Occupant*, CompSet>::const_iterator it = quarterOccupants->begin(); it != quarterOccupants->end(); ++it)
		delete* it;
	placeOccupants = new std::set<Occupant*, CompSet>;
	quarterOccupants = new std::set<Occupant*, CompSet>;
	for (std::set<Occupant*, CompSet>::const_iterator i = temp.placeOccupants->begin(); i != temp.placeOccupants->end(); ++i)
		placeOccupants->insert((*i)->copy());
	for (std::set<Occupant*, CompSet>::const_iterator i = temp.quarterOccupants->begin(); i != temp.quarterOccupants->end(); ++i)
		quarterOccupants->insert((*i)->copy());
};
DB& DB::operator=(const DB& temp) {
	if (this != &temp) {
		for (std::set<Occupant*, CompSet>::const_iterator it = placeOccupants->begin(); it != placeOccupants->end(); ++it)
			delete* it;
		for (std::set<Occupant*, CompSet>::const_iterator it = quarterOccupants->begin(); it != quarterOccupants->end(); ++it)
			delete* it;
		placeOccupants->clear();
		quarterOccupants->clear();
		delete placeOccupants;
		delete quarterOccupants;
		placeOccupants = new std::set<Occupant*, CompSet>;
		quarterOccupants = new std::set<Occupant*, CompSet>;
		for (std::set<Occupant*, CompSet>::const_iterator i = temp.placeOccupants->begin(); i != temp.placeOccupants->end(); ++i) 
			placeOccupants->insert((*i)->copy());
		for (std::set<Occupant*, CompSet>::const_iterator i = temp.quarterOccupants->begin(); i != temp.quarterOccupants->end(); ++i) 
			quarterOccupants->insert((*i)->copy());
	}
	return *this;
};
void DB::save() {
	std::wofstream file("places.txt", std::wofstream::trunc);
	file.imbue(loc);
	for (std::vector<Place>::iterator i = this->places.begin(); i != this->places.end() && file.is_open(); ++i) {
		file << (*i).number << " " << (*i).square << " " << (*i).occupated;
		file << std::endl;
	}
	file.close();
	file = std::wofstream("rent.txt", std::wofstream::trunc);
	file.imbue(loc);
	for (std::set<Occupant*, CompSet>::iterator i = this->placeOccupants->begin(); i != this->placeOccupants->end() && file.is_open(); ++i) {
		file << L"1" << " " << regex_replace((*i)->getName(), std::wregex(L" "), L"_") << " " << regex_replace((*i)->getContactName(), std::wregex(L" "), L"_") << " " << (*i)->getContact() << " " << regex_replace((*i)->getDateStart(), std::wregex(L" "), L"_") << " " << regex_replace((*i)->getDateEnd(), std::wregex(L" "), L"_") << " " << (*i)->getPrice();
		file << std::endl;
	}
	for (std::set<Occupant*, CompSet>::iterator i = this->quarterOccupants->begin(); i != this->quarterOccupants->end() && file.is_open(); ++i) {
		file << L"2" << " " << regex_replace((*i)->getName(), std::wregex(L" "), L"_") << " " << regex_replace((*i)->getContactName(), std::wregex(L" "), L"_") << " " << (*i)->getContact() << " " << regex_replace((*i)->getDateStart(), std::wregex(L" "), L"_") << " " << regex_replace((*i)->getDateEnd(), std::wregex(L" "), L"_") << " " << (*i)->getPrice() << " " << (*i)->getPlace();
		file << std::endl;
	}
	file.close();
}

DB maindb;

void FUNCTIONAL_API getData(std::vector<std::vector<std::wstring>>& data, std::wstring find, int number) {
	std::locale::global(std::locale(""));
	std::transform(find.begin(), find.end(), find.begin(), towlower);
	std::set<Occupant*, CompSet> all;
	std::set_union(maindb.placeOccupants->begin(), maindb.placeOccupants->end(), maindb.quarterOccupants->begin(), maindb.quarterOccupants->end(), std::inserter(all, all.begin()), CompSet());
	std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<Occupant*>>>, std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<Occupant*>>>> range;
	if (number > 0) 
		range = std::equal_range(all.begin(), all.end(), number, Comp{});
	else
		range = std::make_pair(all.begin(), all.end());
	int j = 0;
	for (std::set<Occupant*, CompSet>::iterator i = range.first; i != range.second; ++i) {
		std::wstring name = (*i)->getName();
		std::wstring contactName = (*i)->getContactName();
		std::wstring contact = (*i)->getContact();
		std::wstring dateStart = (*i)->getDateStart();
		std::wstring dateEnd = (*i)->getDateEnd();
		std::wstring price = std::to_wstring((*i)->getPrice());
		std::wstring square = std::to_wstring((*i)->getPlace());
		std::wstring area = L"-1";
		for (int k = 0; k < maindb.places.size(); ++k) {
			if (maindb.places[k].number == (*i)->getPlace()) {
				area = std::to_wstring(maindb.places[k].square);
				break;
			}
		}
		transform(name.begin(), name.end(), name.begin(), towlower);
		transform(contactName.begin(), contactName.end(), contactName.begin(), towlower);
		if (find == L"" || name.find(find) != std::wstring::npos || contactName.find(find) != std::wstring::npos || contact.find(find) != std::wstring::npos || dateStart.find(find) != std::wstring::npos || dateEnd.find(find) != std::wstring::npos || price.find(find) != std::wstring::npos || square.find(find) != std::wstring::npos) {
			data.push_back(std::vector<std::wstring>());
			data[j].push_back((*i)->getName());
			data[j].push_back((*i)->getContactName());
			data[j].push_back(contact);
			data[j].push_back(dateStart);
			data[j].push_back(dateEnd);
			data[j].push_back(price);
			data[j].push_back(square == L"-1" ? L"" : square);
			data[j].push_back(area == L"-1" ? L"" : area);
			j++;
		}
	}
}

void FUNCTIONAL_API deleteRent(std::wstring name, std::wstring placeNumber) {
	if (placeNumber == L"") {
		for (std::set<Occupant*, CompSet>::iterator i = maindb.placeOccupants->begin(); i != maindb.placeOccupants->end(); ++i) {
			if ((*i)->getName() == name) {
				delete* i;
				maindb.placeOccupants->erase(i);
				break;
			}
		}
	} else {
		for (std::set<Occupant*, CompSet>::iterator i = maindb.quarterOccupants->begin(); i != maindb.quarterOccupants->end(); ++i) {
			if ((*i)->getName() == name && std::stoi(placeNumber) == (*i)->getPlace()) {
				delete* i;
				maindb.quarterOccupants->erase(i);
				break;
			}
		}
		for (std::vector<Place>::iterator i = maindb.places.begin(); i != maindb.places.end(); ++i) {
			if ((*i).number == std::stoi(placeNumber)) {
				(*i).occupated = 0;
				break;
			}
		}
	}
}

void FUNCTIONAL_API addRent(int type, std::wstring name, std::wstring contactName, std::wstring contact, std::wstring dateStart, std::wstring dateEnd, int price, int placeNumber) {
	if (type == 1) 
		maindb.placeOccupants->insert(new PlaceOccupant(name, contactName, contact, dateStart, dateEnd, price));
	else {
		maindb.quarterOccupants->insert(new QuarterOccupant(name, contactName, contact, dateStart, dateEnd, price, placeNumber));
		for (std::vector<Place>::iterator i = maindb.places.begin(); i != maindb.places.end(); ++i) {
			if ((*i).number == placeNumber) {
				(*i).occupated = 1;
				break;
			}
		}
	}
}

std::vector<Place> FUNCTIONAL_API getPlaces() {
	return maindb.places;
}
