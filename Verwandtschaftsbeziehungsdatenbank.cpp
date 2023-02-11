#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include "Doktorand.hpp"
#include <ctype.h>
#include <stdio.h>

int main(){





// Speichertort der zu öffnenden Datei
ifstream file("/Users/lautlos/work/Doktordatei/db.txt");

    
    vector<Person2> persons;

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
    ifstream f("/Users/lautlos/work/Doktordatei/db.txt");
    if (f.is_open()) {
        
        while (getline(f, line)) {
          // cout << "test";

            if (i > 0) {
                sep = ",";
            }
            if (i % 6 == 0) {
                sep = "\n";
            }

            //cout << "test2";
            data = sep + line;
            i++;
        }
            
      
        if(t > 0) {
               // cout << "test3";
                std::vector<std::string> elements;
                std::stringstream lineStream(data);
                std::string element;
                while(getline(lineStream, element, ',')) {
                    elements.push_back(element);
                }
       // cout << "test4";

         // Konvertiere die Teilstrings zu den richtigen Datentypen
                //int id = stoi(elements[0]);
                std::string id = elements[0];
                std::string name = elements[1];
                std::string uni = elements[2];
                //int jahr = stoi(elements[3]);
                //int doktorand_id = stoi(elements[4]);
                //int betreuer_id = stoi(elements[5]);
                std::string jahr= elements[3];
                //std::string doktorand_id = elements[4];
                //std::string betreuer_id = elements[5];




            // Füge die Person zum Vector hinzu
                Person2 person(id, name, uni, jahr /*doktorand_id, betreuer_id*/);
                persons.push_back(person);


            
        }
        t++;
    }
     
     //Gebe den Vector mit Personen aus
        for (Person2 person:persons) {
           //cout << "bla";
            cout << person.id << ", " << person.name << ", " << person.uni << ", " << person.jahr << ", " /*<< person.doktorand_id << ", " << person.betreuer_id */<< endl;
                
    

        }
return 0;

}