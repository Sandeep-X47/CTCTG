#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "json.hpp" // nlohmann/json library

using json = nlohmann::json;
using namespace std;

// Utility class for string operations
class Utils {
public:
    static string toLower(const string& s) {
        string result = s;
        transform(result.begin(), result.end(), result.begin(),
                  [](unsigned char c){ return tolower(c); });
        return result;
    }
};

// Class to manage travel routes and times
class TravelManager {
private:
    json data;

public:
    // Constructor: load JSON data from file
    TravelManager(const string& filePath) {
        ifstream inFile(filePath);
        if (!inFile.is_open()) {
            throw runtime_error("Failed to open " + filePath);
        }

        try {
            inFile >> data;
        } catch (const json::parse_error& e) {
            throw runtime_error(string("JSON parse error: ") + e.what());
        }
        inFile.close();
    }

    // Display travel times for a given route
    void displayTravelTime(const string& fromCity, const string& toCity) {
        string fromLower = Utils::toLower(fromCity);
        string toLower = Utils::toLower(toCity);
        bool found = false;

        for (auto &route : data["routes"]) {
            if (Utils::toLower(route["from"]) == fromLower &&
                Utils::toLower(route["to"]) == toLower) {

                cout << "Route from " << route["from"] << " to " << route["to"] << ":\n";
                for (auto &t : route["time"].items()) {
                    cout << t.key() << ": " << t.value() << ":00\n";
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No route found from " << fromCity << " to " << toCity << endl;
        }
    }
};

// Main function
int main() {
    try {
        TravelManager manager("D:\\STARTED\\CTCTG\\Data\\Time.json");

        string from, to;
        cout << "From: ";
        getline(cin, from);
        cout << "To: ";
        getline(cin, to);

        manager.displayTravelTime(from, to);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
