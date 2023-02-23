#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person {

    /**
   * @brief Die Klasse Person repräsentiert eine Person
    */
public:

std::string PersNum;
std::string Name;
std::string Uni;
std::string JahrDis;
std::vector<std::string> Doktorand;
std::vector<std::string> Betreuer;


    /**
    * @brief Konstruktor für die Klasse Person.
    * @param PersNum Die Personalnummer der Person.
    * @param Name Der Name der Person.
    * @param Uni Die Universität, an der die Person ihren Abschluss gemacht hat.
    * @param JahrDis Das Jahr, in dem die Person promoviert hat.
    * @param Betreuer Eine Liste der Betreuer, die die Person hatte.
    * @param Doktorand Eine Liste der Doktoranden, die von der Person betreut wurden.
    */

Person(
    /**
    * @brief Die Personalnummer der Person.
    */
        std::string PersNum,
    /**
    * @brief Der Name der Person.
    */
       std::string Name,
    /**
    * @brief Die Universität, an der die Person promoviert hat.
    */
       std::string Uni,
    /**
     * @brief Das Jahr, in dem die Person ihre Dissertation abgeschlossen hat.
    */
       std::string JahrDis,
    /**
     * @brief Eine Liste der Betreuer, die diese Person bei ihrer Dissertation unterstützt haben.
    */
       std::vector<std::string> Betreuer,
    /**
    * @brief Eine Liste der Doktoranden, die von dieser Person betreut wurden.
    */
       std::vector<std::string> Doktorand)
        : PersNum(PersNum), Name(Name), Uni(Uni), JahrDis(JahrDis), Betreuer(Betreuer), Doktorand(Doktorand) {};

    /**
    * Der Konstruktor hat keinen Parameter, und die leere geschweifte Klammer "{}" zeigt an,
    * dass keine speziellen Anweisungen für die Initialisierung der Klasse erforderlich sind.
    */
Person() {};

    /**
   * Diese Funktion prüft, ob eine Variable namens "PersNum" leer ist oder nicht.
   * Wenn die Variable leer ist, wird "true" zurückgegeben, andernfalls wird "false" zurückgegeben.
   * @return Wenn PersNum leer dann false
    */
bool isEmpty() {
    return (PersNum.empty() ? true : false);
}

    /**
    * Druckt Informationen über eine Person aus.
    * @param output Eine optionale Zeichenkette, die vor den Informationen ausgegeben wird.
    */

void print(string output = "") {
    string data =
            "Personalnummer: " + PersNum + "\n"
            "    Name: " + Name + "\n"
            "    Uni: " + Uni + "\n"
            "    Jahr der Dissertation: " + JahrDis + "\n";

    data += "    Betreuer: ";
    for (auto val: Betreuer) {
        data += val + " ";
        cout << endl;
    }
    data += "\n";


    data += "    Doktorand:";
    for (auto val: Doktorand) {
        data += " " + val;
    }
    data += "\n";

    cout << output << data << endl;
}
};


    /**
    * Diese Klasse definiert eine Liste von Personen und einen Cache für die Liste.
    */
class PersonList {
public:
vector<Person> persons;
vector<string> cache;

    /**
    * Diese Methode sucht nach einer Person in der Liste mit einem bestimmten Namen und
    * gibt das erste passende Person-Objekt zurück, das in der Liste gefunden wird.
    * Wenn kein passendes Objekt gefunden wird, wird ein neues leeres Person-Objekt zurückgegeben.
    * @param Name der gesuchten Person
    * @return Das erste passende Person-Objekt, das in der Liste gefunden wird.
    *         Wenn kein passendes Objekt gefunden wird, wird ein neues leeres Person-Objekt zurückgegeben.
    */


Person searchByName(string Name) {
        for (Person person: persons) {
            if (person.Name == Name) {
                return person;
            }
        }
        return Person();
    }

    /**
    * Fragt den Benutzer nach einem Namen und sucht dann in der PersonList nach einer Person mit diesem Namen.
    * Wenn die Person gefunden wird, werden ihre Informationen ausgegeben.
    * @param personList Die Liste von Personen, in der gesucht werden soll.
   */

void searchPersonByName(PersonList &personList) {
    string name;
    cout << "Bitte geben Sie einen Namen ein: ";
    getline(cin, name);

    Person person = personList.searchByName(name);
    if (!person.isEmpty()) {
        person.print();
    } else {
        cout << "Es wurde keine Person mit dem Namen '" << name << "' gefunden." << endl;
    }
}


    /**
    * Sucht eine Person in der Liste anhand ihrer Personalnummer.
    * @param PersNum Die Personalnummer der gesuchten Person.
    * @return Das erste passende Person-Objekt, das in der Liste gefunden wird.
    *         Wenn kein passendes Objekt gefunden wird, wird ein neues leeres Person-Objekt zurückgegeben.
    */
Person searchById(string PersNum) {
    for (Person person: persons) {
        if (person.PersNum == PersNum) {
            return person;
        }
    }
    return Person();
}

    /**
    * Fügt eine Person zur Liste hinzu.
    * @param p Die Person, die zur Liste hinzugefügt werden soll.
    */
void add(Person p) {
    persons.push_back(p);
}


    /**
    * Druckt alle Personen und deren Doktoranden, die von der angegebenen Person betreut werden.
    */
void personRel() {

    for (Person person: persons) {
        for (string dok: person.Doktorand) {
            Person pers = searchById(dok);
            if (!pers.isEmpty()) {
                pers.print();
            }
        }
    }
}


    /**
    * Druckt alle Personen und deren Doktoranden, die von der angegebenen Person betreut wurden.
    * @param PersNum Die Personalnummer der Person.
    * @return Die Person mit der angegebenen Personalnummer oder eine leere Person, wenn keine Person gefunden wurde.
    */
Person personRel(string PersNum) {
    for (Person person: persons) {
        if (person.PersNum != PersNum) {
            continue;
        }
        cout << endl << "\t" << person.Name << endl;
        for (string dok: person.Doktorand) {
            Person pers = searchById(dok);
            if (!pers.isEmpty()) {
                pers.print("\t\t");
            }
        }
    }
    return Person();
}


    /**
    * Diese Funktion zeigt rekursiv die Beziehungen zwischen Personen an, beginnend mit der Person mit der angegebenen Personalnummer (PersNum).
    * Wenn der Parameter rec auf false gesetzt ist, wird der Cache gelöscht.
    * @param PersNum Die Personalsnummer der Person, derer Beziehungen angezeigt werden sollen.
    * @param rec Ein optionaler Parameter, der angibt, ob die Funktion rekursiv aufgerufen wird. Standardwert ist false.
    */


void personRelRec(string PersNum, bool rec = false) {
    if (!rec) {
        cache.clear();
    }
    for (string dok: searchById(PersNum).Doktorand) {
        Person pers = searchById(dok);
        if (std::count(cache.begin(), cache.end(), pers.PersNum)) {
            return;
        }
        if (!pers.isEmpty()) {
            pers.print("\t");
        }
        cache.push_back(dok);
        personRelRec(dok, true);
    }
}


    /**
    * Diese Funktion gibt die Daten aller Personen in der Liste aus, indem die print()-Funktion für jede Person aufgerufen wird.
    * @param output Ein optionaler Parameter, der an die print()-Funktion jeder Person übergeben wird. Standardwert ist ein leerer String.
    */
void print(string output = "") {
    for (Person person: persons) {
        person.print(output);
    }
}


};





