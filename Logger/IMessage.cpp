#include "IMessage.h"
#include <sstream>

// IMessage

void IMessage::setPriority(const size_t priority) noexcept {
	switch (priority) {
	case 0:
		this->priority = "Info";
		break;
	case 1:
		this->priority = "Trace";
		break;
	case 2:
		this->priority = "Error";
		break;
	}
}

IMessage::~IMessage(){}

std::string IMessage::getPriority() const noexcept {
	return this->priority;
}

std::string IMessage::getAsStr() const noexcept {
	return "";
}

void IMessage::setTimeAdded() noexcept {
	this->addedTime = std::chrono::system_clock::now();
}

std::chrono::time_point<std::chrono::system_clock> IMessage::getTimeAdded() noexcept {
	return this->addedTime;
}

std::ostream& operator<< (std::ostream& stream, const IMessage & message)
{
	stream << message.getAsStr();
	return stream;
}

//UsbDeviceMessage
UsbDeviceMessage::UsbDeviceMessage(size_t priority,
	size_t port, 
	size_t operationNum,
	std::string deviceName) noexcept 
{
	setPriority(priority);
	this->port = port;
	this->deviceName = deviceName;
	switch (operationNum) {
	case 0:
		this->operation = "plugged";
		break;
	case 1:
		this->operation = "unplugged";
		break;
	case 2:
		this->operation = "error";
		break;
	}
}

std::string UsbDeviceMessage::getDeviceName() const noexcept {
	return this->deviceName;
}

std::string UsbDeviceMessage::getOperation() const noexcept {
	return this->operation;
}

size_t UsbDeviceMessage::getPort() const noexcept {
	return this->port;
}

std::string UsbDeviceMessage::getAsStr() const noexcept {
	std::stringstream ss;
	ss << "Port " << this->getPort() << ": " << this->getDeviceName() << " " <<this->getOperation();
	return ss.str();
}

//FanSpeedMessage
FanSpeedMessage::FanSpeedMessage(size_t priority,
	size_t operationNum,
	size_t percentage) noexcept
{
	setPriority(priority);
	this->percentage = percentage;
	switch (operationNum) {
	case 0:
		this->operation = "increased";
		break;
	case 1:
		this->operation = "decreased";
		break;
	}
}

size_t FanSpeedMessage::getPercentage() const noexcept {
	return this->percentage;
}

std::string FanSpeedMessage::getOperation() const noexcept {
	return this->operation;
}

std::string FanSpeedMessage::getAsStr() const noexcept {
	std::stringstream ss;
	ss << "Fan speed " << this->getOperation() << " to " << this->getPercentage() << "%";
	return ss.str();
}
