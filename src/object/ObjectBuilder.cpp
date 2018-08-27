#include "ObjectBuilder.hpp"

#include <string>

namespace object
{

ObjectBuilder::ObjectBuilder()
: buildState_(BuildState::INITIAL)
{}

Object ObjectBuilder::pullObject()
{
	if(buildState_ == BuildState::IN_PROGRESS)
	{
		consumer_.end_object();
		buildState_ = BuildState::FINISHED;
	}

	Object obj = std::move(consumer_.value);
	return obj;
}

template <typename T>
ObjectBuilder& ObjectBuilder::addMember(const std::string& memberName, 
	const T& memberValue)
{
	if(buildState_ == BuildState::INITIAL
		|| buildState_ == BuildState::FINISHED)
	{
		consumer_.begin_object();
		buildState_ = BuildState::IN_PROGRESS;
	}

	consumer_.key(memberName);
	setValue(consumer_, memberValue);
	consumer_.member();
	return *this;
}

template ObjectBuilder& ObjectBuilder::addMember<bool>(
	const std::string& memberName, 
	const bool& memberValue);
template ObjectBuilder& ObjectBuilder::addMember<int64_t>(
	const std::string& memberName, 
	const int64_t& memberValue);
template ObjectBuilder& ObjectBuilder::addMember<uint64_t>(
	const std::string& memberName, 
	const uint64_t& memberValue);
template ObjectBuilder& ObjectBuilder::addMember<double>(
	const std::string& memberName, 
	const double& memberValue);
template ObjectBuilder& ObjectBuilder::addMember<std::string>(
	const std::string& memberName, 
	const std::string& memberValue);

template<>
void ObjectBuilder::setValue(EventConsumer& consumer, 
	const bool& value)
{
	consumer.boolean(value);
}	

template<>
void ObjectBuilder::setValue(EventConsumer& consumer, 
	const int64_t& value)
{
	consumer.number(value);
}	

template<>
void ObjectBuilder::setValue(EventConsumer& consumer, 
	const uint64_t& value)
{
	consumer.number(value);
}	

template<>
void ObjectBuilder::setValue(EventConsumer& consumer, 
	const double& value)
{
	consumer.number(value);
}	

template<>
void ObjectBuilder::setValue(EventConsumer& consumer, 
	const std::string& value)
{
	consumer.string(value);
}

} // namespace object