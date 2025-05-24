#include <iostream>
#include<fstream>
#include "Pharmacy.h"
using namespace std;

int main() {
    cout << "-----WELCOME TO PHARMACY MANAGEMENT SYSTEM----" << endl;
    cout << endl;

    int opt = 0;
    int size = 0;
    Pharmacy* p = nullptr;

    do {
        cout << "What do you wish to do?" << endl;
        cout << "1. Add medicine record" << endl;
        cout << "2. Update medicine record" << endl;
        cout << "3. View medicine records" << endl;
        cout << "4. Store records in file" << endl;
        cout << "5. View records from file" << endl;
        cout << "6. Exit program" << endl;

        cin >> opt;
        cout << "You chose " << opt << endl;

        switch (opt) {
        case 1:
            cout << "Adding Medicine Record" << endl;
            cout << "Enter Size Of An Array you Want: ";
            cin >> size;
            if (size > 0) {
                p = new Pharmacy[size];
                for (int i = 0; i < size; i++) {
                    string name;
                    double price, quantity, revenue;
                    cout << "Enter medicine name: ";
                    cin >> name;
                    cout << "Enter price per unit: ";
                    cin >> price;
                    cout << "Enter quantity sold: ";
                    cin >> quantity;
                    cout << "Enter total revenue: ";
                    cin >> revenue;
                    p[i] = Pharmacy(name, price, quantity, revenue);
                }
            }
            else {
                cout << "Invalid array size. Please enter a positive integer." << endl;
            }
            break;
        case 2:
            
                cout << "Updating Medicine Record" << endl;
                for (int i = 0; i < size; i++) {
                    p[i].update_record();
                    
                }
                p->store_in_file(p);
           
            break;
        case 3:
            
                cout << "Viewing All Medicine Records" << endl;
                for (int i = 0; i < size; i++) {
                    cout << p[i].getdetails();
                    cout << endl;
                }
            break;
        case 4:
      
          
                cout << "Storage Of Data In File" << endl;
                for (int i = 0; i < size; i++) {
                    p[i].store_in_file(p);
                
                cout << "Records Successfully Stored in file" << endl;
            }
           
            break;

        case 5:
            cout << "Viewing Medicine Records from File" << endl;
            Pharmacy::read_from_file(p);
            break;
        case 6:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid option. Please choose a valid option." << endl;
            break;
        }
    } while (opt != 6);

    delete[] p;

    return 0;
}
