#include "CppUnitTest.h"
#include "..\Logger\Logger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoggerUnitTest
{
	TEST_CLASS(LoggerUnitTest)
	{
	public:
		
		TEST_METHOD(LoggerInit)
		{
			UsbDeviceMessage message(0, 1, 0, "printer");
			Loggers loger;
			loger.add(message);
			Assert::AreEqual(message.getAsStr(), loger.getMessage(0)->getAsStr());

		}

		TEST_METHOD(LoggerAdd)
		{
			UsbDeviceMessage message(0, 1, 0, "printer");
			Loggers logger;
			logger.add(message);
			Assert::AreEqual(message.getAsStr(), logger.getMessage(0)->getAsStr());

			FanSpeedMessage message2(0, 1, 40);
			logger.add(message2);
			Assert::AreEqual(message2.getAsStr(), logger.getMessage(0)->getAsStr());
			Assert::AreEqual(message.getAsStr(), logger.getMessage(1)->getAsStr());
		}
	};
}
