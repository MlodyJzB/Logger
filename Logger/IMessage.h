#pragma once
#include <string>
class IMessage
{
private:
	std::string priority;
public:
	IMessage(int priority = 0) noexcept;
	void setPriority() noexcept;
	std::string getPriority() const noexcept;
	void show() const noexcept;
};

