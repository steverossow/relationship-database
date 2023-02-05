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


    // Speicherung der Daten in einer Zeichenfolge
    string data; 
  
    string first_line;
    string curr = "";
    string outPrev = "";
    string outCurr = "";
    // Schleife, zur Auslesung der ganzen Datei
    while (getline(file, data)){
        
        curr = data[0];

        try {
            std::stoi(curr);
            outCurr = "int " + curr ;
        } catch ( ... ) {
            outCurr = "string " + curr ;
        }
        cout << "prev: " << outPrev << " curr: " << outCurr << "\n ";
        outPrev = outCurr;
    }

    return 0;

}










