#include <iostream>
#include <vector>
#include "Client.h"

#define NEW_LINE() cout << "-----------------------------------" << endl << endl

using namespace std;

Client::Client(int _client_number, string _name, string _surname, string _type_of_document, string _document_id) {
    client_number = _client_number;
    name = _name;
    surname = _surname;
    type_of_document = _type_of_document;
    document_id = _document_id;
}
Client::Client(const Client& c) {
    client_number = c.client_number;
    name = c.name;
    surname = c.surname;
    type_of_document = c.type_of_document;
    document_id = c.document_id;
    products = c.products;
}
Client& Client::operator = (const Client& c) {
    if (this != &c) {
        client_number = c.client_number;
        name = c.name;
        surname = c.surname;
        type_of_document = c.type_of_document;
        document_id = c.document_id;
        products = c.products;
    }
    return *this;
}

std::ostream& operator << (ostream& out, Client& c) {
    return out << "Client number:\t" << c.get_client_number() << endl <<
        "Name:\t\t" << c.get_name() << endl <<
        "Surname:\t" << c.get_surname() << endl <<
        "Document's type:" << c.get_type_of_document() << endl <<
        "Document's ID:\t" << c.get_document_id() << endl <<
        "Products: " << endl << c.get_products();
}
bool operator == (Client a, Client b) {
    return a.get_client_number() == b.get_client_number() && a.get_name() == b.get_name() && a.get_surname() == b.get_surname() && a.get_type_of_document() == b.get_type_of_document() && a.get_document_id() == b.get_document_id() && a.get_products() == b.get_products();
}
bool operator != (Client a, Client b) {
    return !(a == b);
}

string Client::get_changeable_data() {
    string out = "";
    out += "1. Name:\t\t" + name + "\n";
    out += "2. Surname:\t\t" + surname + "\n";
    out += "3. Document's type:\t" + type_of_document + "\n";
    out += "4. Document's ID:\t" + document_id + "\n";
    return out;
}
void Client::add_product(string product) {
    if (product != "")
        products.push_back(product);
}
void Client::delete_product(string product) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i] == product) {
            products.erase(products.begin() + i);
            break;
        }
    }
}

// Getter
const int Client::get_client_number() {
    return client_number;
}
const string Client::get_name() {
    return name;
}
const string Client::get_surname() {
    return surname;
}
const string Client::get_name_surname() {
    return name + " " + surname;
}
const string Client::get_type_of_document() {
    return type_of_document;
}
const string Client::get_document_id() {
    return document_id;
}
const string Client::get_products() {
    string out = "";
    for (int i = 0; i < products.size(); i++) {
        out += "\t";
        out += products[i];
        out += "\n";
    }
    return out;
}

// Setter
void Client::set_client_number(int _client_number) {
    client_number = _client_number;
}
void Client::set_name(string _name) {
    name = _name;
}
void Client::set_surname(string _surname) {
    surname = _surname;
}
void Client::set_type_of_document(string _type_of_document) {
    type_of_document = _type_of_document;
}
void Client::set_document_id(string _document_id) {
    document_id = _document_id;
}