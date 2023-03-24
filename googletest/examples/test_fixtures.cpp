#include <gtest/gtest.h>

#include <vector>

class VectorTest : public ::testing::Test {
 protected:
  void SetUp() override {
    v1 = {1}; 
    v2 = {1, 2};
  }

  // void TearDown() override {}

  std::vector<int> v0;
  std::vector<int> v1;
  std::vector<int> v2;
};

TEST_F(VectorTest, IsEmptyInitially)
{
  EXPECT_EQ(v0.size(), 0);
}

TEST_F(VectorTest, IndexingWorks)
{
  ASSERT_EQ(v0.size(), 0);

  ASSERT_EQ(v1.size(), 1);
  EXPECT_EQ(v1[0], 1);

  ASSERT_EQ(v2.size(), 2);
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
}