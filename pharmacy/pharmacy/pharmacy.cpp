#include <iostream>
#include <fstream>
#include <string>
#include "Pharmacy.h"
using namespace std;

int Pharmacy::count = 0;

Pharmacy::Pharmacy() {
    medicine_name = "med";
    price_per_unit = 0.0;
    quantity_sold = 0.0;
    total_revenue = 0.0;
    cout << "Default constructor" << endl;
    ++count;
}

Pharmacy::Pharmacy(string name, double price, double quantity, double revenue) {
    medicine_name = name;
    price_per_unit = price;
    quantity_sold = quantity;
    total_revenue = revenue;
    cout << "Parameterized constructor" << endl;
    ++count;
}

Pharmacy::Pharmacy(const Pharmacy& obj) {
    medicine_name = obj.medicine_name;
    price_per_unit = obj.price_per_unit;
    quantity_sold = obj.quantity_sold;
    total_revenue = obj.total_revenue;
    cout << "Copy constructor" << endl;
}

Pharmacy::~Pharmacy() {
    cout << "Destructor" << endl;
}

void Pharmacy::set_medicine_name(string name) {
    medicine_name = name;
}

void Pharmacy::set_price_per_unit(double price) {
    if (price < 0) {
        cout << "Invalid price. Please provide a non-negative value." << endl;
        return;
    }
    price_per_unit = price;
}

void Pharmacy::set_quantity_sold(double quantity) {
    if (quantity < 0) {
        cout << "Invalid quantity. Please provide a non-negative value." << endl;
        return;
    }
    quantity_sold = quantity;
}

void Pharmacy::set_total_revenue(double revenue) {
    if (revenue < 0) {
        cout << "Invalid revenue. Please provide a non-negative value." << endl;
        return;
    }
    total_revenue = revenue;
}

string Pharmacy::get_medicine_name() {
    return medicine_name;
}

double Pharmacy::get_price_per_unit() {
    return price_per_unit;
}

double Pharmacy::get_quantity_sold() {
    return quantity_sold;
}

double Pharmacy::get_total_revenue() {
    return total_revenue;
}

void Pharmacy::update_record() {
    int choice;
    cout << "Which attribute do you want to update?" << endl;
    cout << "1. Medicine Name" << endl;
    cout << "2. Price Per Unit" << endl;
    cout << "3. Quantity Sold" << endl;
    cout << "4. Total Revenue" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1: {
        string new_name;
        cout << "Enter new medicine name: ";
        cin >> new_name;
      set_medicine_name(new_name);
        
        cout << "updated successfuly" << endl;
        break;
    }
    case 2: {
        double new_price;
        cout << "Enter new price per unit: ";
        cin >> new_price;
       set_price_per_unit(new_price);
        
            cout << "updated successfuly" << endl;
        break;
    }
    case 3: {
        double new_quantity;
        cout << "Enter new quantity sold: ";
        cin >> new_quantity;
        set_quantity_sold(new_quantity);
        
        cout << "updated successfuly" << endl;
        break;
    }
    case 4: {
        double new_revenue;
        cout << "Enter new total revenue: ";
        cin >> new_revenue;
       set_total_revenue(new_revenue);
        
        cout << "updated successfuly" << endl;
        break;
    }
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}
string Pharmacy::getdetails() {
    return "Medicine name :" + medicine_name + "Price per unit :" + to_string(price_per_unit) + "Quantity sold :" + to_string(quantity_sold) + "Total revenue :" + to_string(total_revenue);
}

void Pharmacy::store_in_file(Pharmacy p[]) {
    ofstream fout;
    fout.open("pharmacy.txt", ios::app);
    for (int i = 0; i < count; i++) {
        fout << p[i].getdetails() << endl;
        
    }
    fout.close();
}
void Pharmacy::read_from_file(Pharmacy p[]) {
    try {
        ifstream fin("pharmacy.txt");
        if (fin.fail()) {
            throw runtime_error("File not found");
        }
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }
    catch (runtime_error& e) {
        cout << "Error occurred: " << e.what() << endl;
    }
}