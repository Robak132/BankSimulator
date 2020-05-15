#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <typeinfo>

using namespace std;

struct MyError : public exception
{	// Odr�bny error kt�ry jest �apany podczas testowania
	string message;
public:
	MyError(string);
};
ostream& operator<<(ostream& os, const MyError& e);


struct Vehicle
{
	// Struktura kt�r� b�dziemy przechowywa� w kolejce.
public:
	unsigned int wheels;
	string colour;
	double price;

	Vehicle();		// Kostruktor domy�lny
	Vehicle(const Vehicle& v);	// Konstruktor kopiuj�cy
	Vehicle(string, double = 99.99, unsigned int = 4);	// Konstruktor
	bool operator ==(const Vehicle& obj)
	{
		if (colour == obj.colour && wheels == obj.wheels && price == obj.price) return true;
		return false;
	}
	template<typename type_same>
	bool operator==(const type_same& obj) // Przeci��enie por�wnania kt�re �apie wszystkie przypadki w kt�rych nie por�wnujemy ze sob� dw�ch obiekt�w typu Vehicle
	{
		return false;
	}
	template<typename type_same>
	bool operator!=(const type_same obj) // Wynik odwrotny do por�wnywania
	{
		return !Vehicle::operator==(obj);
	}
};
ostream& operator << (ostream& os, const Vehicle obj);


template <typename type_queue>
class QElem
{	// Najmniejszy element kolejki
	QElem<type_queue>* adress;		// Przechowuje adres nast�pnego elementu	
	type_queue value;				// Przechowuje warto�� elementu

public:
	QElem(type_queue val)
	{
		value = val;
		adress = nullptr;
	}

	type_queue get_value() const
	{
		return value;
	}

	QElem<type_queue>* get_adress() const
	{
		return adress;
	}

	QElem<type_queue>** get_adress_of_adress()
	{
		return &adress;
	}
};

template <typename type_queue>
ostream& operator << (ostream& os, const QElem<type_queue> obj) 
{	// WYpisywanie warto�ci z elementu
	return os << obj.get_value();
}

template <class type_queue> 
class Queue
{	// Kolejka Fifo. Pozwala na dodawanie element�w na jej koniec oraz pobieranie element�w z pocz�tku. Wzorowane list� �a�cuchow� jednostronn�.
	int elements_number{};		// Liczba element�w w kolejce
	QElem <type_queue>* head;	// Wska�nik na pierwszy element kolejki
	QElem <type_queue>** tail;	// Przechowuje adres wska�nika na kolejny pusty adres z ostatniego elementu.

	void add_first(type_queue val)
	{	// Dodaje pierwszy element gdy lista jest pusta. Ustawia "tail" na adresie  wska�nika przechowywanego w elemencie.
		head = new QElem<type_queue>(val);		
		tail = head->get_adress_of_adress();
	}

	void add_next(type_queue val)
	{	// Dodaje kolejne elementy gdy istnieje pierwszy
		*tail = new QElem<type_queue>(val);
		QElem<type_queue>& obj_buff = **tail;
		tail = obj_buff.get_adress_of_adress();
	}

	bool is_empty()
	{	// Zwraca prawd� gdy lista jest pusta
		return elements_number ? false : true;
	}

public:
	Queue()
	{	// Kontruktor dom�lny
		head = nullptr;
		tail = nullptr;
	}

	void push(type_queue val)
	{	// Dodaje element na koniec kolejki.
		if (!elements_number++)
		{
			add_first(val);
		}
		else
			add_next(val);
	}

	type_queue pop()
	{	// Zwraca element z pocz�tku i usuwa go.
		if (is_empty()) throw MyError("Queue is empty!");	// B��d je�li staramy si� zaczerpn�� z pustej kolejki
		elements_number--;										
		QElem<type_queue>* buff_adr = head->get_adress();	// Przechowywanie adresu drugiego elementu
		type_queue buff_val = head->get_value();			// Pobieranie warto�ci pierwszego
		delete head;										// Usuwanie pierwszego elementu
		head = buff_adr;									// Ustawianie drugiego elementu jako pierwszego
		return buff_val;
	}

	QElem<type_queue>* get_head() const
	{	
		return head;
	}

	int length() const
	{
		return elements_number;
	}

	~Queue()
	{	// Destruktor. Przesuwa si� po kolejce kolejno dealokuj�c w�z�y
		int len = length();
		QElem<type_queue>* now_element = head;
		for (int i = 0; i < len; i++)
		{
			QElem<type_queue>* next_element = now_element->get_adress();
			delete now_element;
			now_element = next_element;
		}
	}

	template<typename type_add>
	bool operator == (const Queue<type_add>& obj)
	{	// Por�wnuje ze sob� dwa obiekty Queue. Aby by�y r�wne musz� przechowywa� ten sam typ oraz te same warto�ci.
		if (typeid(type_queue) != typeid(type_add)) return false;
		if (length() != obj.length()) return false;
		int len = obj.length();
		const QElem<type_queue>* element_left = get_head();	
		const QElem<type_add>* element_right = obj.get_head();

		for (int i = 0; i < len; i++)
		{
			if (element_left->get_value() != element_right->get_value()) return false;
			element_left = element_left->get_adress();
			element_right = element_right->get_adress();
		}
		return true;
	}
};

template <typename type_queue>
ostream& operator << (ostream& os, const Queue<type_queue>& obj)
{	// Wypisywanie warto�ci. Polega na kolejnym wypisywaniu element�w.
	{
		int len = obj.length();
		if (!len) os << "Queue is empty!";
		QElem<type_queue>* buff_obj = obj.get_head();
		for (int i = 0; i < len; i++)
		{
			os << buff_obj->get_value();
			buff_obj = buff_obj->get_adress();
			if (buff_obj != nullptr)
				os << ", ";
		}
		return os;
	}
}

