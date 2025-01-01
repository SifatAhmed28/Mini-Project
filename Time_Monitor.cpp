#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Struct to store focus session details
struct FocusSession {
    string date;
    int focusMinutes; 
};

// Function to calculate average focus time
double calculateAverage(const vector<FocusSession>& sessions) {
    if (sessions.empty()) return 0.0;
    int totalMinutes = 0;
    for (const auto& session : sessions) {
        totalMinutes += session.focusMinutes;
    }
    return static_cast<double>(totalMinutes) / sessions.size();
}

// Function to save a focus session to a file
void saveSession(const FocusSession& session) {
    ofstream file("focus_data.txt", ios::app);
    if (file.is_open()) {
        file << session.date << " " << session.focusMinutes << "\n";
        file.close();
    } else {
        cerr << "Error: Unable to open file for saving session.\n";
    }
}

// Function to load focus sessions from a file
vector<FocusSession> loadSessions() {
    vector<FocusSession> sessions;
    ifstream file("focus_data.txt");
    if (file.is_open()) {
        FocusSession session;
        while (file >> session.date >> session.focusMinutes) {
            sessions.push_back(session);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for loading sessions.\n";
    }
    return sessions;
}

// Function to add a focus session
void addFocusSession() {
    FocusSession todaySession;
    cout << "Enter today's date (YYYY-MM-DD): ";
    cin >> todaySession.date;
    cout << "Enter today's focus time in minutes: ";
    while (!(cin >> todaySession.focusMinutes) || todaySession.focusMinutes < 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a positive integer: ";
    }
    saveSession(todaySession);
    cout << "Session saved successfully!\n";
}

// Function to view focus statistics
void viewStatistics() {
    auto sessions = loadSessions();
    if (sessions.empty()) {
        cout << "No previous focus sessions found.\n";
        return;
    }

    double averageFocus = calculateAverage(sessions);
    cout << "Your average focus time in the past days: " << averageFocus / 60 << " hours.\n";

    for (const auto& session : sessions) {
        cout << "Date: " << session.date << ", Focus Time: " << session.focusMinutes / 60.0 << " hours\n";
    }
}

// Function to monetize today's focus time
void monetizeFocusTime() {
    FocusSession todaySession;
    cout << "Enter today's focus time in minutes: ";
    while (!(cin >> todaySession.focusMinutes) || todaySession.focusMinutes < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer: ";
    }

    double monetizationRate = 0.10; // $0.10 per minute
    double monetizedValue = todaySession.focusMinutes * monetizationRate;
    cout << "Today's focus time value: $" << monetizedValue << "\n";
}

// Main function with a menu
int main() {
    int choice;
    do {
        cout << "\n=== Focus Time Tracker ===\n";
        cout << "1. Add a Focus Session\n";
        cout << "2. View Focus Statistics\n";
        cout << "3. Monetize Today's Focus Time\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFocusSession();
                break;
            case 2:
                viewStatistics();
                break;
            case 3:
                monetizeFocusTime();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
