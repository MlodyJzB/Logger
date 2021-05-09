#include "IMessage.h"

IMessage::IMessage(int priority) noexcept {
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

void IMessage::setPriority() noexcept{

}

std::string IMessage::getPriority() const noexcept {
	return this->priority;
}

void IMessage::show() const noexcept {

}
