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
			Assert::AreEqual(message2.getPriority(), std::string("Trace"));
			Assert::AreEqual(message2.getDeviceName(), std::string("pendrive"));
			Assert::AreEqual(message2.getPort(), size_t(2));
			Assert::AreEqual(message2.getOperation(), std::string("unplugged"));
		}

		TEST_METHOD(UsbDeviceMessageGetAsStr)
		{
			UsbDeviceMessage message(0, 1, 0, "printer");
			std::string expectedStr = "Port 1: printer plugged";
			Assert::AreEqual(message.getAsStr(), expectedStr);
		}

		TEST_METHOD(FanSpeedMessageInit)
		{
			FanSpeedMessage message(0, 1, 40);
			Assert::AreEqual(message.getPriority(), std::string("Info"));
			Assert::AreEqual(message.getPercentage(), size_t(40));
			Assert::AreEqual(message.getOperation(), std::string("decreased"));

			FanSpeedMessage message2(0, 0, 60);
			Assert::AreEqual(message2.getPriority(), std::string("Info"));
			Assert::AreEqual(message2.getPercentage(), size_t(60));
			Assert::AreEqual(message2.getOperation(), std::string("increased"));
		}

		TEST_METHOD(FanSpeedMessageGetAsStr)
		{
			FanSpeedMessage message(0, 1, 40);
			std::string expectedStr = "Fan speed decreased to 40%";
			Assert::AreEqual(message.getAsStr(), expectedStr);

			FanSpeedMessage message2(0, 0, 60);
			std::string expectedStr2 = "Fan speed increased to 60%";
			Assert::AreEqual(message2.getAsStr(), expectedStr2);
		}

		TEST_METHOD(IMessageOperatorOS)
		{
			FanSpeedMessage message(0, 1, 40);
			std::string expectedStr = "Fan speed decreased to 40%";
			std::ostringstream stream;
			stream << message;
			Assert::AreEqual(message.getAsStr(), expectedStr);

		}

	
	};
}
