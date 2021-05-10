#include "Logger.h"
#include <typeinfo>



Loggers::Loggers() noexcept{}

void Loggers::add(IMessage & message) noexcept {
	this->messages.push_back(&message);
}

IMessage* Loggers::getMessage(size_t i) {
	size_t size = this->messages.size();
	size_t new_i = size - i - 1;
	return this->messages.at(new_i);
}