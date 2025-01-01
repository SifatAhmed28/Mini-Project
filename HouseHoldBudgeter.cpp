#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

using namespace std;

int main() {
    string name[6];
    double houseRent[6];
    double electricity[6];
    double Bua_Total;
    double wifi_Total;
    double gas_Total;
    double garbage_Total;

    cout << "Enter Nickname Of All Members" << endl;
    cout<<"---------------------------------"<<endl;

    for(int i = 0; i < 6; i++) {
        cout << "Enter Name: ";
        cin >> name[i];
        cout<<endl;
    }
cout<<endl;
    // Now we have the names, let's find out the costing
    cout<<"Enter Common Rent "<<endl;
    cout<<"-------------------"<<endl;
    cout << "Enter Bua Monthly Total Rent: ";
    cin >> Bua_Total;

    cout << "Enter Wifi Monthly Total Rent: ";
    cin >> wifi_Total;

    cout << "Enter Gas Monthly Total Rent: ";
    cin >> gas_Total;

    cout << "Enter Garbage Monthly Total Rent: ";
    cin >> garbage_Total;
    cout<<endl;
   cout<<"Now Type Cost of Individual"<<endl;
   cout<<"--------------------------------"<<endl;
    for(int i = 0; i < 6; i++) {
        cout << "Enter " << name[i] << "'s Monthly House Rent: ";
        cin >> houseRent[i];

        cout << "Enter " << name[i] << "'s Electricity Bill: ";
        cin >> electricity[i];
        cout<<endl;
    }

    // Calculate the shared costs
    double sharedCost = (Bua_Total / 6) + (wifi_Total / 6) + (gas_Total / 6) + (garbage_Total / 6);

    // Calculate the total cost for each member
    double sum_Total[6];

    for(int i = 0; i < 6; i++) {
        sum_Total[i] = houseRent[i] + electricity[i] + sharedCost;
    }

    // Create and open a CSV file for writing
    ofstream csvFile("output.csv");

    if (!csvFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    // Write header
    csvFile << "Name,House Rent,Electricity,Bua Share,Wifi Share,Gas Share,Garbage Share,Total Cost\n";

    // Write data
    for(int i = 0; i < 6; i++) {
        csvFile << name[i] << "," 
                << fixed << setprecision(2) << houseRent[i] << "," 
                << fixed << setprecision(2) << electricity[i] << "," 
                << fixed << setprecision(2) << (Bua_Total / 6) << "," 
                << fixed << setprecision(2) << (wifi_Total / 6) << "," 
                << fixed << setprecision(2) << (gas_Total / 6) << "," 
                << fixed << setprecision(2) << (garbage_Total / 6) << "," 
                << fixed << setprecision(2) << sum_Total[i] << "\n";
    }

    // Close the file
    csvFile.close();

    cout << "Data has been written to output.csv" << endl;

    return 0;
}
