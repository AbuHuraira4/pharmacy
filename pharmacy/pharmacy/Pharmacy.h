#pragma once
#include<iostream>
using namespace std;

class Pharmacy { 
private: 
    string medicine_name;
    double price_per_unit;
    double quantity_sold;
    double total_revenue;

public: 
    static int count;
    Pharmacy(); 
    Pharmacy(string name, double price, double quantity, double revenue); 
    Pharmacy(const Pharmacy& obj); 
    ~Pharmacy(); 

    void set_medicine_name(string name);
    void set_price_per_unit(double price);
    void set_quantity_sold(double quantity);
    void set_total_revenue(double revenue);

    string get_medicine_name();
    double get_price_per_unit();
    double get_quantity_sold();
    double get_total_revenue();
    string getdetails();

    void update_record();
    void store_in_file(Pharmacy p[]);
    static void read_from_file(Pharmacy p[]);
};

