#include <gtest/gtest.h>

#include <memory>
#include <string>

#include <tao/json.hpp>

//how to link to shorten this include?
#include "../../rpgItemsCreator/object/ObjectBuilder.hpp"

//#include "object/ObjectBuilder.hpp"

class ObjectBuilderTests : public ::testing::Test
{
protected:

	ObjectBuilderTests()
	: sut_(new object::ObjectBuilder())
	{}

	std::unique_ptr<object::ObjectBuilder> sut_; //system under tests
};

TEST_F(ObjectBuilderTests, PullObjectShouldReturnUninitializedObject) //ShouldPullUninitializedObject ?
{
	const auto object = sut_->pullObject();
	EXPECT_EQ(object.type(), tao::json::type::UNINITIALIZED);
}

TEST_F(ObjectBuilderTests, PullObjectShouldReturnObjectIfMemberIsAdded)
{
	sut_->addMember("name", std::string("sword"));
	const auto object = sut_->pullObject();
	EXPECT_EQ(object.type(), tao::json::type::OBJECT);
}