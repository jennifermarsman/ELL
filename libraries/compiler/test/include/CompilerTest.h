#pragma once

#include <string>
#include <ostream>
#include "Compiler.h"

void TestLLVM();
void TestLLVMShiftRegister();

class ModelBuilder
{
public:
	ModelBuilder();
	ModelBuilder(const ModelBuilder& src);
	ModelBuilder(ModelBuilder&& src);

	template<typename T>
	nodes::ConstantNode<T>* Constant(const T value);
	template<typename T>
	nodes::ConstantNode<T>* Constant(const std::vector<T>& values);
	template<typename T>
	model::InputNode<T>* Inputs(size_t count);
	template<typename T>
	model::InputNode<T>* Inputs(std::vector<T>& values);
	template<typename T>
	model::OutputNode<T>* Outputs(const model::OutputPort<T>& x);
	template<typename T>
	nodes::BinaryOperationNode<T>* Add(const model::OutputPort<T>& x, const model::OutputPort<T>& y);
	template<typename T>
	nodes::BinaryOperationNode<T>* Subtract(const model::OutputPort<T>& x, const model::OutputPort<T>& y);
	template<typename T>
	nodes::BinaryOperationNode<T>* Multiply(const model::OutputPort<T>& x, const model::OutputPort<T>& y);
	template<typename T>
	nodes::BinaryOperationNode<T>* Divide(const model::OutputPort<T>& x, const model::OutputPort<T>& y);
	template<typename T>
	nodes::DotProductNode<T>* DotProduct(const model::OutputPort<T>& x, const model::OutputPort<T>& y);
	template<typename T>
	nodes::AccumulatorNode<T>* Accumulate(const model::OutputPort<T>& x);
	template<typename T>
	nodes::SumNode<T>* Sum(const model::OutputPort<T>& x);
	template<typename T>
	nodes::DelayNode<T>* Delay(const model::OutputPort<T>& x, size_t windowSize);

	// Expose as a property!
	model::Model& Model = _model;

	const std::string& Name = _name;

	void SetName(const std::string name)
	{
		_name = std::move(name);
	}

private:
	model::Model _model;
	std::string _name;
};

void TestBinaryVector(bool expanded);
void TestBinaryScalar();
void TestDotProduct();

void TestSum(bool expanded);
void TestAccumulator(bool expanded);
void TestDelay();
void TestSlidingAverage();
void TestDotProductOutput();