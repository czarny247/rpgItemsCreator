#ifndef OBJECTBUILDER_HPP_
#define OBJECTBUILDER_HPP_

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

	//leave it for now - maybe it will be useful as it looks now
	//return std::optional (c++17 needed) or (smart?) pointer - it will hide json type dependencies - see tests!
	Object pullObject(); //rename to build() ?

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

#endif //OBJECTBUILDER_HPP_