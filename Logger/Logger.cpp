#include "Logger.h"



Loggers::Loggers() noexcept{}

void Loggers::add(IMessage & message) noexcept {
	message.setTimeAdded();
	this->messages.push_back(&message);
}

IMessage* Loggers::getMessagePtr(size_t i) {
	size_t size = this->messages.size();
	size_t new_i = size - i - 1;
	return this->messages.at(new_i);
}

Loggers::ErrorIterator::ErrorIterator(std::vector<IMessage*>& col, std::vector<IMessage*>::iterator const i): collection(col) {
	current = i;
}

IMessage*&  Loggers::ErrorIterator::operator*(){
	return *current;
}

Loggers::ErrorIterator& Loggers::ErrorIterator::operator++() {
	for (auto i = current + 1; i != collection.end(); ++i) {
		IMessage* messagePtr = *i;
		if (messagePtr->getPriority() == "Error") {
			this->current = i;
			return *this;
		}
	}
	this->current = collection.end();
	return *this;
}

Loggers::ErrorIterator Loggers::begin() {
	for (std::vector<IMessage*>::iterator i = messages.begin(); i != messages.end(); ++i) {
		IMessage* messagePtr = *i;
		if (messagePtr->getPriority() == "Error")return ErrorIterator(messages, i);
	}
	return ErrorIterator(messages, messages.end());
}

Loggers::ErrorIterator Loggers::end() {
	return ErrorIterator(messages, messages.end());
}