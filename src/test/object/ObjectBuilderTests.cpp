#include <gtest/gtest.h>

#include <memory>

#include <tao/json.hpp>

#include "../../rpgItemsCreator/object/ObjectBuilder.hpp"

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