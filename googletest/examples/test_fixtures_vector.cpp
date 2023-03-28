#include <gtest/gtest.h>

#include <vector>

class VectorTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 5);
  }

  // void TearDown() override {}

  std::vector<int> v{1, 2, 3, 4, 5};
};

TEST_F(VectorTest, ResizingBiggerChangesSizeAndCapacity)
{
  v.resize(10);

  EXPECT_EQ(v.size(), 10);
  EXPECT_GE(v.capacity(), 10);
}

TEST_F(VectorTest, ResizingSmallerChangesSizeButNotCapacity)
{
  v.resize(0);

  EXPECT_EQ(v.size(), 0);
  EXPECT_GE(v.capacity(), 5);
}

TEST_F(VectorTest, ReservingBiggerChangesCapacityButNotSize)
{
  v.reserve(10);

  EXPECT_EQ(v.size(), 5);
  EXPECT_GE(v.capacity(), 10);
}

TEST_F(VectorTest, ReservingSmallerDoesNotChangeSizeOrCapacity)
{
  v.reserve(0);

  EXPECT_EQ(v.size(), 5);
  EXPECT_GE(v.capacity(), 5);
}