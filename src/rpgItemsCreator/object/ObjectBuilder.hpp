#ifndef OBJECTBUILDER_HPP
#define OBJECTBUILDER_HPP

//todo: choose only needed includes
#include <tao/json/events.hpp>
#include <string>

using Object = tao::json::value;
using EventConsumer = tao::json::events::to_value;

namespace object
{

enum class BuildState
{
	INITIAL = 0,
	IN_PROGRESS,
	FINISHED
};

class ObjectBuilder
{
public:
	ObjectBuilder();

	Object pullObject();

	template <typename T>
	ObjectBuilder& addMember(const std::string& memberName, 
		const T& memberValue);

private:
	template <typename T>
	void setValue(EventConsumer& consumer, const T& value) {}

	EventConsumer consumer_;
	BuildState buildState_;
};

} // namespace object

#endif //OBJECTBUILDER