#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// =========================
// Pharmacy Management System
// Data file: pharmacy_data.txt
// =========================

// Struct to store medicine details: ID, Name, Price, and Stock Quantity.
struct Medicine {
    int id{};
    string name;
    double price{};
    int stock{};
};

// -------------------------
// Utility helpers (input + formatting)
// -------------------------

static string trim(const string& s) {
    size_t start = 0;
    while (start < s.size() && isspace(static_cast<unsigned char>(s[start]))) start++;
    size_t end = s.size();
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) end--;
    return s.substr(start, end - start);
}

static string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });
    return s;
}

static void printLine(char ch = '=', int width = 72) {
    cout << string(width, ch) << "\n";
}

static void printHeader(const string& title) {
    printLine('=');
    cout << "PHARMACY MANAGEMENT SYSTEM\n";
    printLine('-');
    cout << title << "\n";
    printLine('=');
}

static void pauseForUser() {
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Safe integer input (prevents invalid input from breaking the program).
static int readInt(const string& prompt, int minValue = numeric_limits<int>::min(),
                   int maxValue = numeric_limits<int>::max()) {
    while (true) {
        cout << prompt;
        long long v;
        if (!(cin >> v)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (v < minValue || v > maxValue) {
            cout << "  Value out of range. Try again.\n";
            continue;
        }
        return static_cast<int>(v);
    }
}

// Safe double input (for medicine price).
static double readDouble(const string& prompt, double minValue = -1e308,
                         double maxValue = 1e308) {
    while (true) {
        cout << prompt;
        double v;
        if (!(cin >> v)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Please enter a valid number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (v < minValue || v > maxValue) {
            cout << "  Value out of range. Try again.\n";
            continue;
        }
        return v;
    }
}

static string readNonEmptyLine(const string& prompt) {
    while (true) {
        cout << prompt;
        string s;
        getline(cin, s);
        s = trim(s);
        if (!s.empty()) return s;
        cout << "  This field cannot be empty. Please try again.\n";
    }
}

// -------------------------
// Data helpers
// -------------------------

static bool idExists(const vector<Medicine>& meds, int id) {
    return any_of(meds.begin(), meds.end(), [&](const Medicine& m) { return m.id == id; });
}

static int findByNameIndex(const vector<Medicine>& meds, const string& name) {
    // Case-insensitive exact match (simple and predictable for console use).
    const string target = toLower(trim(name));
    for (int i = 0; i < static_cast<int>(meds.size()); i++) {
        if (toLower(trim(meds[i].name)) == target) return i;
    }
    return -1;
}

// -------------------------
// File handling (save / load)
// -------------------------
// File format per line: id|name|price|stock

static bool loadFromFile(const string& filePath, vector<Medicine>& meds) {
    meds.clear();

    ifstream in(filePath);
    if (!in.is_open()) {
        // File does not exist yet -> start with an empty list.
        return false;
    }

    string line;
    while (getline(in, line)) {
        line = trim(line);
        if (line.empty()) continue;

        stringstream ss(line);
        string idStr, nameStr, priceStr, stockStr;

        if (!getline(ss, idStr, '|')) continue;
        if (!getline(ss, nameStr, '|')) continue;
        if (!getline(ss, priceStr, '|')) continue;
        if (!getline(ss, stockStr)) continue;

        Medicine m{};
        try {
            m.id = stoi(trim(idStr));
            m.name = trim(nameStr);
            m.price = stod(trim(priceStr));
            m.stock = stoi(trim(stockStr));
        } catch (...) {
            // Skip corrupted lines safely.
            continue;
        }

        // Basic validation.
        if (m.id <= 0 || m.name.empty() || m.price < 0.0 || m.stock < 0) continue;
        if (!idExists(meds, m.id)) meds.push_back(m);
    }

    return true;
}

static bool saveToFile(const string& filePath, const vector<Medicine>& meds) {
    ofstream out(filePath, ios::trunc);
    if (!out.is_open()) return false;

    for (const auto& m : meds) {
        out << m.id << "|" << m.name << "|" << fixed << setprecision(2) << m.price << "|"
            << m.stock << "\n";
    }
    return true;
}

// -------------------------
// Menu actions
// -------------------------

static void displayAll(const vector<Medicine>& meds) {
    printHeader("4) Display All Medicines");

    if (meds.empty()) {
        cout << "No medicines found.\n";
        return;
    }

    cout << left << setw(10) << "ID" << setw(32) << "NAME" << right << setw(12) << "PRICE"
         << right << setw(12) << "STOCK" << "\n";
    printLine('-', 72);

    for (const auto& m : meds) {
        cout << left << setw(10) << m.id << setw(32) << m.name << right << setw(12) << fixed
             << setprecision(2) << m.price << right << setw(12) << m.stock << "\n";
    }

    printLine('-', 72);
    cout << "Total medicines: " << meds.size() << "\n";
}

static void addMedicine(vector<Medicine>& meds) {
    printHeader("1) Add Medicine");

    int id = readInt("Enter Medicine ID (positive number): ", 1);
    if (idExists(meds, id)) {
        cout << "\nA medicine with this ID already exists.\n";
        return;
    }

    string name = readNonEmptyLine("Enter Medicine Name: ");
    double price = readDouble("Enter Price: ", 0.0);
    int stock = readInt("Enter Stock Quantity: ", 0);

    Medicine m{};
    m.id = id;
    m.name = name;
    m.price = price;
    m.stock = stock;

    meds.push_back(m);
    cout << "\nMedicine added successfully.\n";
}

static void searchByName(const vector<Medicine>& meds) {
    printHeader("2) Search by Name");

    if (meds.empty()) {
        cout << "No medicines available to search.\n";
        return;
    }

    string name = readNonEmptyLine("Enter Medicine Name to search: ");
    int idx = findByNameIndex(meds, name);

    if (idx == -1) {
        cout << "\nNo matching medicine found for: " << name << "\n";
        return;
    }

    const Medicine& m = meds[idx];
    cout << "\nResult:\n";
    printLine('-', 72);
    cout << left << setw(18) << "Medicine ID" << ": " << m.id << "\n";
    cout << left << setw(18) << "Name" << ": " << m.name << "\n";
    cout << left << setw(18) << "Price" << ": " << fixed << setprecision(2) << m.price
         << "\n";
    cout << left << setw(18) << "Stock Quantity" << ": " << m.stock << "\n";
    printLine('-', 72);
}

static void updateStock(vector<Medicine>& meds) {
    printHeader("3) Update Stock");

    if (meds.empty()) {
        cout << "No medicines available to update.\n";
        return;
    }

    string name = readNonEmptyLine("Enter Medicine Name to update: ");
    int idx = findByNameIndex(meds, name);

    if (idx == -1) {
        cout << "\nNo matching medicine found for: " << name << "\n";
        return;
    }

    cout << "\nCurrent stock for \"" << meds[idx].name << "\" is: " << meds[idx].stock << "\n";
    int newStock = readInt("Enter new stock quantity (0 or greater): ", 0);
    meds[idx].stock = newStock;
    cout << "\nStock updated successfully.\n";
}

static void showMenu() {
    printHeader("Main Menu");
    cout << "1. Add Medicine\n";
    cout << "2. Search by Name\n";
    cout << "3. Update Stock\n";
    cout << "4. Display All\n";
    cout << "5. Exit\n";
    printLine('-', 72);
}

int main() {
    const string dataFile = "pharmacy_data.txt";
    vector<Medicine> medicines;

    // Load medicines from file at startup (if available).
    loadFromFile(dataFile, medicines);

    while (true) {
        showMenu();
        int choice = readInt("Select an option (1-5): ", 1, 5);

        switch (choice) {
            case 1:
                addMedicine(medicines);
                saveToFile(dataFile, medicines);  // Save after changes.
                pauseForUser();
                break;
            case 2:
                searchByName(medicines);
                pauseForUser();
                break;
            case 3:
                updateStock(medicines);
                saveToFile(dataFile, medicines);  // Save after changes.
                pauseForUser();
                break;
            case 4:
                displayAll(medicines);
                pauseForUser();
                break;
            case 5:
                printHeader("Exit");
                saveToFile(dataFile, medicines);  // Final save for safety.
                cout << "Thank you for using the Pharmacy Management System.\n";
                printLine('=');
                return 0;
        }
    }
}

