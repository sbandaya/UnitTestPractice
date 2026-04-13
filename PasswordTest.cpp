/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}


TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZz");
	ASSERT_EQ(2, actual);
}


TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}


TEST(PasswordTest, long_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zzzzzzzzzzzzzzz");
	ASSERT_EQ(15, actual);
}


TEST(PasswordTest, has_mixed_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("ZzZ");
	ASSERT_TRUE(actual);
}


TEST(PasswordTest, all_uppercase)
{
	Password my_password;
	int actual = my_password.has_mixed_case("ZZZ");
	ASSERT_FALSE(actual);
}


TEST(PasswordTest, all_lowercase)
{
	Password my_password;
	int actual = my_password.has_mixed_case("zzz");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_not_matching)
{
	Password my_password;
	int actual = my_password.has_mixed_case("ZaB");
	ASSERT_TRUE(actual);
}


TEST(PasswordTest, mixed_empty)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}
