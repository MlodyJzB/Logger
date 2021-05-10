#pragma once
#include "IMessage.h"
#include <vector>
#include <chrono>


class Loggers
{
private:
	std::vector<IMessage*> messages;
public:
	Loggers() noexcept;
	void add(IMessage &message) noexcept;
	IMessage* getMessagePtr(size_t i);

	class ErrorIterator {
		friend Loggers;
	private:
		std::vector<IMessage*>::iterator current;
		std::vector<IMessage*>& collection;
	public:
		ErrorIterator(std::vector<IMessage*>& col, std::vector<IMessage*>::iterator const i);
		IMessage*& operator*();

		ErrorIterator& operator++();
	};

	ErrorIterator begin();
	ErrorIterator end();
};

