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
			Assert::AreEqual(message.getAsStr(), loger.getMessagePtr(0)->getAsStr());

		}

		TEST_METHOD(LoggerAdd)
		{
			UsbDeviceMessage message(0, 1, 0, "printer");
			Loggers logger;
			logger.add(message);
			Assert::AreEqual(message.getAsStr(), logger.getMessagePtr(0)->getAsStr());

			FanSpeedMessage message2(0, 1, 40);
			logger.add(message2);
			Assert::AreEqual(message2.getAsStr(), logger.getMessagePtr(0)->getAsStr());
			Assert::AreEqual(message.getAsStr(), logger.getMessagePtr(1)->getAsStr());
		}

		TEST_METHOD(LoggerErrorIteratorBegin)
		{
			Loggers logger;

			UsbDeviceMessage message(2, 1, 0, "printer");
			logger.add(message);

			FanSpeedMessage message2(0, 0, 20);
			logger.add(message2);

			FanSpeedMessage message3(0, 0, 30);
			logger.add(message3);

			FanSpeedMessage message4(2, 1, 40);
			logger.add(message4);

			Loggers::ErrorIterator i = logger.begin();

			auto iMessage = *i;

			Assert::AreEqual(iMessage->getAsStr(), message.getAsStr());
		}

		TEST_METHOD(LoggerErrorIteratorPlusPlusOperator)
		{
			Loggers logger;

			UsbDeviceMessage message(2, 1, 0, "printer");
			logger.add(message);

			FanSpeedMessage message2(0, 0, 20);
			logger.add(message2);

			FanSpeedMessage message3(0, 0, 30);
			logger.add(message3);

			FanSpeedMessage message4(2, 1, 40);
			logger.add(message4);

			Loggers::ErrorIterator i = logger.begin();
			IMessage* iMessage = *i;

			Assert::AreEqual(iMessage->getAsStr(), message.getAsStr());

			++i;
			auto iMessage2 = *i;

			Assert::AreNotEqual(iMessage2->getAsStr(), message2.getAsStr());
			Assert::AreNotEqual(iMessage2->getAsStr(), message3.getAsStr());
			Assert::AreEqual(iMessage2->getAsStr(), message4.getAsStr());

		}
	};
}
