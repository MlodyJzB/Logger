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

//UsbDeviceMessage
UsbDeviceMessage::UsbDeviceMessage(size_t priority,
	size_t port, 
	int operationNum,
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
