
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct Fact {
    string relation;
    string person1;
    string person2;
};

vector<Fact> knowledgeBase;

void addFact(string relation, string p1, string p2 = "") {
    knowledgeBase.push_back({relation, p1, p2});
}


bool isParent(string p1, string p2) {
    for (auto &f : knowledgeBase) {
        if (f.relation == "parent" && f.person1 == p1 && f.person2 == p2)
            return true;
    }
    return false;
}


bool isMale(string p) {
    for (auto &f : knowledgeBase)
        if (f.relation == "male" && f.person1 == p) return true;
    return false;
}

bool isFemale(string p) {
    for (auto &f : knowledgeBase)
        if (f.relation == "female" && f.person1 == p) return true;
    return false;
}

string fatherOf(string child) {
    for (auto &f : knowledgeBase)
        if (isParent(f.person1, child) && isMale(f.person1))
            return f.person1;
    return "Unknown";
}

string motherOf(string child) {
    for (auto &f : knowledgeBase)
        if (isParent(f.person1, child) && isFemale(f.person1))
            return f.person1;
    return "Unknown";
}

set<string> siblingsOf(string person) {
    set<string> sibs;
    for (auto &f : knowledgeBase) {
        if (isParent(f.person1, person)) {
            string parent = f.person1;
            for (auto &f2 : knowledgeBase) {
                if (f2.relation == "parent" && f2.person1 == parent && f2.person2 != person)
                    sibs.insert(f2.person2); 
            }
        }
    }
    return sibs;
}

set<string> grandparentsOf(string child) {
    set<string> gps;
    for (auto &f : knowledgeBase) {
        if (isParent(f.person1, child)) {
            string parent = f.person1;
            for (auto &f2 : knowledgeBase) {
                if (isParent(f2.person1, parent))
                    gps.insert(f2.person1); 
            }
        }
    }
    return gps;
}

int main() {

    addFact("parent", "Ramesh", "Aarav");
    addFact("parent", "Ramesh", "Ananya");
    addFact("parent", "Sita", "Aarav");
    addFact("parent", "Sita", "Ananya");
    addFact("parent", "Aarav", "Kabir");
    addFact("parent", "Meera", "Sita");

    addFact("male", "Ramesh");
    addFact("male", "Aarav");
    addFact("male", "Kabir");
    addFact("female", "Sita");
    addFact("female", "Ananya");
    addFact("female", "Meera");


    cout << "Father of Ananya: " << fatherOf("Ananya") << endl;
    cout << "Mother of Aarav: " << motherOf("Aarav") << endl;

    cout << "Siblings of Aarav: ";
    for (string s : siblingsOf("Aarav")) cout << s << " ";
    cout << endl;

    cout << "Grandparents of Kabir: ";
    for (string gp : grandparentsOf("Kabir")) cout << gp << " ";
    cout << endl;

    return 0;
}

