#include "CppUnitTest.h"
#include "..\Logger\IMessage.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IMessageUnitTest
{
	TEST_CLASS(IMessageUnitTest)
	{
	public:

		TEST_METHOD(IMessageInitNoPriority)
		{
			IMessage message;
			Assert::AreEqual(message.getPriority(), std::string("Info"));
		}

		TEST_METHOD(IMessageInitPriority)
		{
			IMessage message1(1);
			Assert::AreEqual(message1.getPriority(), std::string("Trace"));

			IMessage message2(2);
			Assert::AreEqual(message2.getPriority(), std::string("Error"));
		}
	};
}
