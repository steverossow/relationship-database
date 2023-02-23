#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Doktorand.hpp"
#include <cstdlib>

#include <algorithm>

using namespace std;




    /**
    * @brief Entfernt alle Leerzeichen am Ende einer Zeichenkette.
    * Diese Funktion verwendet die übergebene Zeichenkette `s` als Eingabe und gibt eine gekürzte
    * Zeichenkette zurück, in der alle Leerzeichen am Ende entfernt werden.
    * @param s Die Eingabezeichenkette, von der am Ende Leerzeichen entfernt werden sollen.
    * @return Die gekürzte Zeichenkette ohne Leerzeichen am Ende.
    */



int main() {

        /**
    * @brief Liest eine Datei mit Personendaten aus und speichert sie in einer Liste.
    * Diese Funktion liest die Datei "db.txt" ein und entnimmt daraus Personendaten,
    * die in einer Liste von Personen gespeichert werden. Die Liste wird als Objekt der
    * Klasse `PersonList` erstellt und zurückgegeben. Jede Person in der Datei wird durch
    * eine Zeile mit sechs Feldern repräsentiert, die durch Kommas getrennt sind. Das erste
    * Feld enthält die Personalnummer der Person, die restlichen Felder enthalten ihren Namen, ihr
    * Jahr der Dissertation, ihre Uni, die Nummern der Betreuer und die Nummern der Doktoranden. Die Felder
    * sind durch Leerzeichen getrennt. Alle Felder werden als Zeichenketten eingelesen und
    * in einer Liste von Person-Objekten gespeichert.
    * @return Die Liste der gelesenen Personen, als Objekt der Klasse `PersonList`.
    */




    ifstream linestream("db.txt");
    PersonList personList = PersonList();

    string line;
    string data;
    string sep;
    int i = 0;
    int eingabe;


    while (getline(linestream, line)) {
        if (i > 0) {
            sep = ",";
            if (i % 6 == 0) {
                sep = "\r\n";
            }
        }
        data += sep + line;
        i++;
    }
    int letztesLeerzeichenIndex = -1;
    for (int i = line.length() - 1; i >= 0; i--) {
        if (line[i] == ' ') {
            letztesLeerzeichenIndex = i;
            break;
        }
    }
    if (letztesLeerzeichenIndex != -1) {
        std::string neueZeile = line.substr(0, letztesLeerzeichenIndex) + line.substr(letztesLeerzeichenIndex + 1);
    }
    /**
    * @brief Entnimmt die einzelnen Elemente aus einer Zeichenkette mit Kommatrennung.
    * Diese Funktion nimmt eine Zeichenkette `data` entgegen, die eine Reihe von Elementen
    * enthält, die durch Kommas getrennt sind. Jedes Element wird in ein Vektor von
    * Zeichenketten aufgeteilt und zurückgegeben. Die Zeichenkette wird in Zeilen unterteilt,
    * die durch den Zeilenumbruch '\n' getrennt sind. Die Funktion verwendet die Bibliothek
    * `sstream`, um die Zeichenkette zu zerlegen und die Elemente zu entnehmen.
    * @param data Die Zeichenkette mit den zu entnommen Elementen.
    * @return Ein Vektor von Zeichenketten, der jedes entnommene Element enthält.
    */

    stringstream lineStream(data);
    string element;
    while (getline(lineStream, element, '\n')) {
        vector<std::string> elements;
        stringstream elementStream(element);
        string item;
        while (getline(elementStream, item, ',')) {
            elements.push_back(item);
        }

    /**
    * @brief Entnimmt einzelne Elemente aus einem Vektor von Zeichenketten.
    *
    * Diese Funktion entnimmt die ersten vier Elemente aus einem Vektor von
    * Zeichenketten und gibt sie als separate Zeichenketten zurück. Die Funktion
    * geht davon aus, dass der Vektor `elements` mindestens vier Elemente enthält.
    *
    * @param elements Ein Vektor von Zeichenketten, aus dem die Elemente extrahiert werden sollen.
    * @return Eine Struktur, die die extrahierten Elemente enthält.
    */


        std::string PersNum = elements[0];
        std::string Name = elements[1];
        std::string Uni = elements[2];
        std::string JahrDis = elements[3];

    /**
    * @brief Entnimmt eine Liste von Betreuern aus einer Zeichenkette.
    * Diese Funktion entnimmt eine Liste von Betreuern aus dem fünften Element
    * des Vektors `elements` und gibt sie als Vektor von Zeichenketten zurück.
    * Die Funktion geht davon aus, dass das fünfte Element des Vektors eine
    * Zeichenkette ist, die mit Leerzeichen getrennte Betreuer enthält.
    * @param elements Ein Vektor von Zeichenketten, aus dem die Betreuer entnommen werden sollen.
    * @return Ein Vektor von Zeichenketten, der die Betreuer enthält.
    */

        std::vector<std::string> Betreuer;
        std::stringstream betreuerStream(elements[4]);
        while (getline(betreuerStream, item, ' ')) {
            Betreuer.push_back(item);
        }

        /**
    * @brief Entnimmt eine Liste von Doktoranden aus einer Zeichenkette.
    * Diese Funktion entnimmt eine Liste von Doktoranden aus dem sechsten Element
    * des Vektors `elements` und gibt sie als Vektor von Zeichenketten zurück.
    * Die Funktion geht davon aus, dass das sechste Element des Vektors eine
    * Zeichenkette ist, die mit Leerzeichen getrennte Doktoranden enthält.
    * @param elements Ein Vektor von Zeichenketten, aus dem die Doktoranden extrahiert werden sollen.
    * @return Ein Vektor von Zeichenketten, der die Doktoranden enthält.
    */

        std::vector<std::string> Doktorand;
        std::stringstream doktorandStream(elements[5]);
        while (getline(doktorandStream, item, ' ')) {
            Doktorand.push_back(item);
        }

        Person person(PersNum, Name, Uni, JahrDis, Betreuer, Doktorand);
        personList.add(person);
    }


    // Ausgabe Menü mit 5 verschiedenen Auswahlmöglichkeiten
    while (true) {

        cout << "       =============================" << endl;
        cout << "               Was suchen Sie? " << endl;
        cout << "       =============================" << endl << endl;
        cout << "       [1] = Informationen über eine Person" << endl << endl;
        cout << "       [2] = Informationen über alle Personen" << endl << endl;
        cout << "       [3] = Informationen über die Doktoranden der gesuchten Person" << endl << endl;
        cout << "       [4] = Inforamtionen über die Doktoranden einer Person und Informationen derer Doktoranden (rekursiv)" << endl << endl;
        cout << "       [5] = Möchten Sie wissen wer der letzte (jüngste) wissenschaftliche nachkomme von Werner Heisenberg ist? " << endl << endl;
        cout << "       [6] = Prgramm schließen." << endl << endl;
        cout << "       Bitte geben Sie eine Zahl ein [1,2,3,4,5,6]: " << endl;

        cin >> eingabe;


        /**
    *@brief Wenn die Benutzereingabe "1" ist, wird diese Bedingung ausgeführt.
    *
    *Sucht eine Person in der PersonListe nach ihrem Namen und gibt Informationen über diese aus.
    *
    *@param personList Die PersonListe, in der nach der Person gesucht wird.
    *@return Eine Person mit allen Daten
    */

        if (eingabe == 1) {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string name;
            cout << "Bitte geben Sie einen Namen ein (Wenn die Person nur Vor-und Zunammen hat bitte zwei Leereichen dazwischen): ";
            getline(cin, name);


            Person person = personList.searchByName(name);
            if (!person.isEmpty()) {
                person.print();
            } else {
                cout << "Es wurde keine Person mit dem Namen '" << name << "' gefunden." << endl;
            }


            /**
    *@brief Wenn die Benutzereingabe "2" ist, wird diese Bedingung ausgeführt.
    *
    *Sucht alle Personen in der PersonListe und gibt alle Informationen über diese aus.
    *
    *@param personList Die PersonListe, in der nach allen Person gesucht wird.
    *@return Gibt alle Personen mit allen Informationen aus
    */
        } else if (eingabe == 2) {


            cout << "Alle Personen: " << endl;
            personList.print("\t");


           /**
    *@brief Wenn die Benutzereingabe "3" ist, wird diese Bedingung ausgeführt.
    *
    *Sucht nach einer Person in der Datenbank mithilfe der PersNum und ruft die Funktion "personRel" auf,
    *um alle Doktoranden und deren Doktoranden etc. zurückzuliefern.
    *@param PersNum Personalnummer der Person, nach der gesucht wird.
    *@return Gibt die Doktoranden der eingegeben Person aus
    */


        } else if (eingabe == 3) {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string PersNum;
            cout << "Bitte PersNum eingeben: ";
            getline(cin, PersNum);

            cout << endl << endl << endl;
            Person pers = personList.searchById(PersNum);
            cout << "Der Doktorvater ist: " << pers.Name << endl << endl;
            cout << "Die Doktoranden sind: " << endl;
            personList.personRel(PersNum);

    /**
    *Wenn die Benutzereingabe "4" ist, wird diese Bedingung ausgeführt.
    *Der Benutzer wird aufgefordert, eine PersNum einzugeben, und eine Person in der Datenbank wird mithilfe dieser PersNum gesucht.
    *Eine Funktion wird aufgerufen, die alle Doktoranden und (rekursiv) deren Doktoranden einer Person zurückgibt.
    *@param Der Doktorvater und die Doktoranden der gesuchten Person werden auf der Konsole ausgegeben.
    * Die Doktoranden der Doktoranden der gesuchten Person werden ebenfalls ausgegeben.
    */

        } else if (eingabe == 4) {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string PersNum;
            cout << "Bitte PersNum eingeben: ";
            getline(cin, PersNum);

            cout << endl
                 << "Schreiben Sie eine Funktion, die zu einer Person in der Datenbank alle Doktoranden sowie (rekursiv) deren Doktoranden etc. zurückliefert. "
                 << endl
                 << endl;
            Person pers = personList.searchById(PersNum);
            cout << "Der Doktorvater ist: " << pers.Name << endl << endl;
            cout << "Die Doktoranden sind: " << endl;
            personList.personRelRec(PersNum);


            cout << endl
                 << "Die Doktoranden der Doktoranden von " << pers.Name << " sind: "
                 << endl;
            personList.personRelRec(PersNum);

            /**
    *@brief Option 5: Zeigt den jüngsten wissenschaftlichen Nachkomme von Werner Heisenberg an
    *Diese Funktion zeigt den jüngsten wissenschaftlichen Nachkomme von Werner Heisenberg an.
    *Dazu wird die ID von Werner Heisenberg verwendet, um alle seine direkten und indirekten Doktoranden zu finden.
    *Anschließend wird der letzte Eintrag in der Auflistung der Nachkommen als der jüngste wissenschaftliche Nachkomme ausgegeben.
    *@param PersNum von Werner Heisnberg
    *@return letzter wissenschaftlichter Nachkomme von Werner Heisenberg
    */

        } else if (eingabe == 5) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');


            cout << endl

                 << endl
                 << endl;
            Person pers = personList.searchById("51469");
            cout << "Der jüngste wissenschaftliche Nachkomme von Werner Heisenberg ist die letzte in der Auflistung "
                 << endl;
            personList.personRelRec("51469");


            cout << endl
                 << "Die Doktoranden der Doktoranden von " << pers.Name << " sind: "
                 << endl;
            personList.personRelRec("51469");


        } else if (eingabe == 6) {

            std::cout << "Programm wird beendet" << std::endl;
            exit(0);
        } else {
            cout << "       Falsche Eingabe, bitte nochmal: " << endl << endl;
        }


    }
}