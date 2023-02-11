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
            std::vector<std::string> betreuerVec,
            std::vector<std::string> doktorandVec)
            : id(id), name(name), uni(uni), jahr(jahr), betreuerVec(betreuerVec), doktorandVec(doktorandVec) {};

    Person() {};

    bool isEmpty(){
        return (id.empty() ? true : false);
    }

    void print(string output="") {
        string data =
                "id: " + id +
                " name: " + name +
                " uni: " + uni +
                " jahr: " + jahr;

        data += " betreuerVec: ";
        for (auto val : betreuerVec) {
            data += val + " ";
        }

        data += "doktorandVec:";
        for (auto val : doktorandVec) {
            data += " " + val;
        }

        cout << output << data << endl;
    }
};

class PersonList {
public:
    vector<Person> persons;
    vector<string> cache;

    Person searchByName(string name) {
        for (Person person: persons) {
            if (person.name == name) {
                return person;
            }
        }
        return Person();
    }

    Person searchById(string id) {
        for (Person person: persons) {
            if (person.id == id) {
                return person;
            }
        }
        return Person();
    }

    void add(Person p){
        persons.push_back(p);
    }

    int size(){
        return persons.size();
    }

    void personRel() {
        for (Person person: persons) {
            cout << endl << person.name << endl;
            for (string dok: person.doktorandVec) {
                Person pers = searchById(dok);
                if (!pers.isEmpty()) {
                    pers.print();
                }
            }
        }
    }

    Person personRel(string id) {
        for (Person person: persons) {
            if (person.id != id){
                continue;
            }
            cout << endl << "\t" << person.name << endl;
            for (string dok: person.doktorandVec) {
                Person pers = searchById(dok);
                if (!pers.isEmpty()) {
                    pers.print("\t\t");
                }
            }
        }
        return Person();
    }

    void personRelRec(string id) {
        for (string dok: searchById(id).doktorandVec) {
            Person pers = searchById(dok);
            if (std::count(cache.begin(), cache.end(), pers.id)) {
                return;
            }
            cache.push_back(dok);
            if (!pers.isEmpty()){
                pers.print("\t");
            }
            personRelRec(dok);
        }
    }

    void print(string output=""){
        for (Person person: persons) {
            person.print(output);
        }
    }

};





