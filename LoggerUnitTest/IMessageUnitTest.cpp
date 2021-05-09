#include "CppUnitTest.h"
#include "..\Logger\IMessage.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IMessageUnitTest
{
	TEST_CLASS(IMessageUnitTest)
	{
	public:

		TEST_METHOD(UsbDeviceMessageInit)
		{
			UsbDeviceMessage message(0, 1, 0, "printer");
			Assert::AreEqual(message.getPriority(), std::string("Info"));
			Assert::AreEqual(message.getDeviceName(), std::string("printer"));
			Assert::AreEqual(message.getPort(), size_t(1));
			Assert::AreEqual(message.getOperation(), std::string("plugged"));

			UsbDeviceMessage message2(1, 2, 1, "pendrive");
			Assert::AreEqual(message2.getPriority(), std::string("Info"));
			Assert::AreEqual(message2.getDeviceName(), std::string("pendrive"));
			Assert::AreEqual(message2.getPort(), size_t(2));
			Assert::AreEqual(message2.getOperation(), std::string("unplugged"));
		}

		TEST_METHOD(UsbDeviceMessageGetAsStr)
		{
			UsbDeviceMessage message(0, 1, 0, "printer");
			std::string expected_str = "Port 1: printer plugged";
			Assert::AreEqual(message.getAsStr(), expected_str);
		}

	
	};
}
