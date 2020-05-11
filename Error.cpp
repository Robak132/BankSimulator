#include <iostream>
#include <exception>
#include "Error.h"

ValueNotFound::ValueNotFound(string _message) {
	message = _message;
}
DuplicatedKey::DuplicatedKey(string _message) {
	message = _message;
}