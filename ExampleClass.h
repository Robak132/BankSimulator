#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

class ExampleClass {
public:
	int first;
	int second;
	ExampleClass(int _first, int _second);
	ExampleClass();
	ExampleClass(const ExampleClass& e);
	ExampleClass& operator=(const ExampleClass& e);
};

bool operator == (const ExampleClass& a, const ExampleClass& b);

#endif