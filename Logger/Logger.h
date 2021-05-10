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
	IMessage* getMessage(size_t i);
};

