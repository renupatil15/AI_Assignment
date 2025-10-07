#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

bool isValid(map<string, string>& colors, map<string, vector<string>>& neighbors, string region, string color) {
    for (string neighbor : neighbors[region]) {
        if (colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

bool solveCSP(map<string, string>& colors, map<string, vector<string>>& neighbors, vector<string>& regions, vector<string>& availableColors, int index) {
    if (index == regions.size()) {
        return true; 
    }

    string region = regions[index];
    for (string color : availableColors) {
        if (isValid(colors, neighbors, region, color)) {
            colors[region] = color;
            if (solveCSP(colors, neighbors, regions, availableColors, index + 1))
                return true;
            colors[region] = ""; 
        }
    }
    return false;
}

int main() {
    vector<string> regions = {"A", "B", "C", "D", "E"};
    
    vector<string> availableColors = {"Red", "Green", "Blue"};

    map<string, vector<string>> neighbors;
    neighbors["A"] = {"B", "C"};
    neighbors["B"] = {"A", "C", "D"};
    neighbors["C"] = {"A", "B", "D", "E"};
    neighbors["D"] = {"B", "C", "E"};
    neighbors["E"] = {"C", "D"};

    map<string, string> colors;
    for (string r : regions) colors[r] = "";

    if (solveCSP(colors, neighbors, regions, availableColors, 0)) {
        cout << "Solution Found:\n";
        for (string r : regions) {
            cout << r << " -> " << colors[r] << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
