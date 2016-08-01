#include "CompilerTest.h"

using namespace emll::compiler;

int main(int argc, char* argv[])
{
	TestDotProductOutput();

	TestBinaryVector(false);
	TestBinaryVector(true);
	TestBinaryScalar();
	TestDotProduct();
	TestSum(false);
	TestSum(true);
	TestAccumulator(false);
	TestAccumulator(true);
	TestDelay();
	TestSlidingAverage();

	TestLLVM();
	TestLLVMShiftRegister();

	return 0;
}
