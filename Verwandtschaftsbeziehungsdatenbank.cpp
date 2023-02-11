#include <iostream>
#include <fstream>

using namespace std;

#include <vector>
#include <string>
#include <sstream>
#include "Doktorand.hpp"
#include <ctype.h>
#include <stdio.h>


#include <iostream>
#include <string>
#include <algorithm>

const std::string WHITESPACE = " \n\r\t\f\v";

std::string rtrim(const std::string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

int main() {

// Speichertort der zu öffnenden Datei
    ifstream file("db.txt");

    PersonList personList = PersonList();

    // Überprüfen, ob die Datei erfolgreich geöffnet wurde
    if (!file.is_open()) {
        cout << "Datei konnte nicht geöffnet werden." << endl;
        return 1;
    }

    string line;
    string data = "";
    string sep = "";
    int i = 0;
    int t;

    // Schleife, zur Auslesung der ganzen Datei
    ifstream f("db.txt");
    if (f.is_open()) {

        while (getline(f, line)) {
            if (i > 0) {
                sep = ",";
                if (i % 6 == 0) {
                    sep = "\n";
                }
            }
            data += sep + rtrim(line);
            i++;
        }
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
        std::vector<std::string> doktorandVec;
        std::stringstream doktorandStream(elements[4]);
        while (getline(doktorandStream, item, ' ')) {
            doktorandVec.push_back(item);
        }
        // doktorand vector Erstellung
        std::vector<std::string> betreuerVec;
        std::stringstream betreuerVec(elements[5]);
        while (getline(doktorandStream, item, ' ')) {
            doktorandVec.push_back(item);
        }
        std::string betreuer_id = elements[5];

        Person person(id, name, uni, jahr, doktorandVec, betreuer_id);
        personList.add(person);
    }

    cout << personList.size() << endl;
    //personList.print();
    personList.searchName("Mario  Hlawitschka").print();
    return 0;

}