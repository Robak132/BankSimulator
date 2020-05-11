#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>

using namespace std;

class Client {
private:
    int client_number;

    string name;
    string surname;

    string type_of_document;
    string document_id;

    vector<string>products;
public:
    Client(int _client_number, string _name, string _surname, string _type_of_document, string _document_id);
    Client(const Client& c);
    Client& operator = (const Client& c);
      
    friend std::ostream& operator << (ostream& out, Client& c);
    friend bool operator == (Client a, Client b);
    friend bool operator != (Client a, Client b);

    string get_changeable_data();
    void add_product(string product);
    void delete_product(string product);

    // Getter
    const int get_client_number();
    const string get_name();
    const string get_surname();
    const string get_name_surname();
    const string get_type_of_document();
    const string get_document_id();
    const string get_products();

    // Setter
    void set_client_number(int _client_number);
    void set_name(string _name);
    void set_surname(string _surname);
    void set_type_of_document(string _type_of_document);
    void set_document_id(string _document_id);
};
#endif