#pragma once
#include <string>
#include <chrono>

class IMessage
{
protected:
	std::string priority;
	void setPriority(const size_t priority) noexcept;
	std::chrono::time_point<std::chrono::system_clock> addedTime;
public:
	~IMessage();
	std::string getPriority() const noexcept;
	virtual std::string getAsStr() const noexcept;
	void setTimeAdded() noexcept;
	std::chrono::time_point<std::chrono::system_clock> getTimeAdded() noexcept;
};


class UsbDeviceMessage : public IMessage
{
private:
	size_t port;
	std::string deviceName;
	std::string operation;
public:
	UsbDeviceMessage(size_t priority,
		size_t port,
		size_t operationNum,
		std::string deviceName) noexcept;

	std::string getDeviceName() const noexcept;
	std::string getOperation() const noexcept;
	size_t getPort() const noexcept;
	virtual std::string getAsStr() const noexcept;
};

class FanSpeedMessage : public IMessage
{
private:
	size_t percentage;
	std::string operation;
public:
	FanSpeedMessage(size_t priority,
		size_t operationNum,
		size_t percentage) noexcept;

	size_t getPercentage() const noexcept;
	std::string getOperation() const noexcept;
	std::string getAsStr() const noexcept;
};

std::ostream& operator<< (std::ostream& stream, const IMessage& message);
