#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <typeinfo>

using namespace std;

struct MyError : public exception
{	// Odrêbny error który jest ³apany podczas testowania
	string message;
public:
	MyError(string);
};
ostream& operator<<(ostream& os, const MyError& e);


struct Vehicle
{
	// Struktura któr¹ bêdziemy przechowywaæ w kolejce.
public:
	unsigned int wheels;
	string colour;
	double price;

	Vehicle();		// Kostruktor domyœlny
	Vehicle(const Vehicle& v);	// Konstruktor kopiuj¹cy
	Vehicle(string, double = 99.99, unsigned int = 4);	// Konstruktor
	bool operator ==(const Vehicle& obj)
	{
		if (colour == obj.colour && wheels == obj.wheels && price == obj.price) return true;
		return false;
	}
	template<typename type_same>
	bool operator==(const type_same& obj) // Przeci¹¿enie porównania które ³apie wszystkie przypadki w których nie porównujemy ze sob¹ dwóch obiektów typu Vehicle
	{
		return false;
	}
	template<typename type_same>
	bool operator!=(const type_same obj) // Wynik odwrotny do porównywania
	{
		return !Vehicle::operator==(obj);
	}
};
ostream& operator << (ostream& os, const Vehicle obj);


template <typename type_queue>
class QElem
{	// Najmniejszy element kolejki
	QElem<type_queue>* adress;		// Przechowuje adres nastêpnego elementu	
	type_queue value;				// Przechowuje wartoœæ elementu

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
{	// WYpisywanie wartoœci z elementu
	return os << obj.get_value();
}

template <class type_queue> 
class Queue
{	// Kolejka Fifo. Pozwala na dodawanie elementów na jej koniec oraz pobieranie elementów z pocz¹tku. Wzorowane list¹ ³añcuchow¹ jednostronn¹.
	int elements_number{};		// Liczba elementów w kolejce
	QElem <type_queue>* head;	// WskaŸnik na pierwszy element kolejki
	QElem <type_queue>** tail;	// Przechowuje adres wskaŸnika na kolejny pusty adres z ostatniego elementu.

	void add_first(type_queue val)
	{	// Dodaje pierwszy element gdy lista jest pusta. Ustawia "tail" na adresie  wskaŸnika przechowywanego w elemencie.
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
	{	// Zwraca prawdê gdy lista jest pusta
		return elements_number ? false : true;
	}

public:
	Queue()
	{	// Kontruktor domœlny
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
	{	// Zwraca element z pocz¹tku i usuwa go.
		if (is_empty()) throw MyError("Queue is empty!");	// B³¹d jeœli staramy siê zaczerpn¹æ z pustej kolejki
		elements_number--;										
		QElem<type_queue>* buff_adr = head->get_adress();	// Przechowywanie adresu drugiego elementu
		type_queue buff_val = head->get_value();			// Pobieranie wartoœci pierwszego
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
	{	// Destruktor. Przesuwa siê po kolejce kolejno dealokuj¹c wêz³y
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
	{	// Porównuje ze sob¹ dwa obiekty Queue. Aby by³y równe musz¹ przechowywaæ ten sam typ oraz te same wartoœci.
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
{	// Wypisywanie wartoœci. Polega na kolejnym wypisywaniu elementów.
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

