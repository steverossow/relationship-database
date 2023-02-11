#include <iostream>
#include <fstream>

using namespace std;

#include <vector>
#include <string>
#include <sstream>
#include "Doktorand.hpp"
#include "data.hpp"

#include <algorithm>

const std::string WHITESPACE = " \n\r\t\f\v";

std::string rtrim(const std::string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

int main() {

// Speichertort der zu öffnenden Datei
    std::stringstream dbStream(db);
    PersonList personList = PersonList();

    string line;
    string data;
    string sep;
    int i = 0;

    // Schleife, zur Auslesung der ganzen Datei
    while (getline(dbStream, line)) {
        if (i > 0) {
            sep = ",";
            if (i % 6 == 0) {
                sep = "\n";
            }
        }
        data += sep + rtrim(line);
        i++;
    }

    //cout << data;
    std::stringstream lineStream(data);
    std::string element;
    while (getline(lineStream, element, '\n')) {
        std::vector<std::string> elements;
        std::stringstream elementStream(element);
        std::string item;
        while (getline(elementStream, item, ',')) {
            elements.push_back(item);
        }
        //cout << elements.size() << endl;
        std::string id = elements[0];
        std::string name = elements[1];
        std::string uni = elements[2];;
        std::string jahr = elements[3];

        // doktorand vector Erstellung
        std::vector<std::string> betreuerVec;
        std::stringstream betreuerStream(elements[4]);
        while (getline(betreuerStream, item, ' ')) {
            betreuerVec.push_back(item);
        }

        // doktorand vector Erstellung
        std::vector<std::string> doktorandVec;
        std::stringstream doktorandStream(elements[5]);
        while (getline(doktorandStream, item, ' ')) {
            doktorandVec.push_back(item);
        }

        Person person(id, name, uni, jahr, betreuerVec, doktorandVec);
        personList.add(person);
    }

    cout << "Person count: " << personList.size() << endl;

    cout << "All persons: " << endl;
    personList.print("\t");

    cout << endl << "Search By Name: " << endl;
    personList.searchByName("Mario  Hlawitschka").print("\t");

    cout << endl << "Alle Einträge zu einem Doktoranten: ";
    personList.personRel("124000");

    cout << endl
         << "Schreiben Sie eine Funktion, die zu einer Person in der Datenbank alle Doktoranden sowie (rekursiv) deren Doktoranden etc. zurückliefert. "
         << endl;
    Person pers = personList.searchById("226240");
    cout << pers.name << endl;
    personList.personRelRec("226240");

    cout << endl
         << "Schreiben Sie eine Funktion, die zu einer Person in der Datenbank alle Doktoranden sowie (rekursiv) deren Doktoranden etc. zurückliefert. "
         << endl;
    personList.personRelRec("125450");

    return 0;

}