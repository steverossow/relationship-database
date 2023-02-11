#include <iostream>
#include <vector>

class Person {

public:

    std::string id;
    std::string name;
    std::string uni;
    std::string jahr;
    std::vector<std::string> doktorandVec;
    std::vector<std::string> betreuerVec;


    Person(std::string id,
            std::string name,
            std::string uni,
            std::string jahr,
            std::string doktorand_id,
            std::string betreuer_id)
            : id(id), name(name), uni(uni), jahr(jahr), doktorand_id(doktorand_id), betreuer_id(betreuer_id) {};

    void print() {
        cout
        << "id: " << id
        << " name: " << name
        << " uni: " << uni
        << " jahr: " << jahr
        << " doktorand_id: " << doktorand_id
        << " betreuer_id: " << betreuer_id
        << endl;
    }
};




class PersonList {
public:
    vector<Person> persons;

    Person searchName(string name) {
        for (Person person: persons) {
            if (person.name == name) {
                return person;
            }
        }
    }
    int add(Person p){
        persons.push_back(p);
        return 1;
    }

    int size(){
        return persons.size();
    }

    void print(){
        for (Person person: persons) {
            person.print();
        }
    }
};





