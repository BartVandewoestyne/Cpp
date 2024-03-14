#include <catch2/catch_test_macros.hpp>

#include <csignal>
#include <iostream>

void goExit()
{
    std::cerr << "Success" << std::endl;
    exit(0);
}

void KillMe()
{
    std::cerr << "Killing myself!" << std::endl;
    std::raise(SIGKILL);
}

void AbortMe()
{
    std::cerr << "Aborting!" << std::endl;
    std::abort();
}

//TEST_CASE( "Go exit!", "[exit]")
//{
//    goExit(); 
//}

//TEST_CASE("Kill me!", "[kill]")
//{
//   KillMe();
//}

TEST_CASE( "test1", "[test1]")
{
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Abort me!", "[abort]")
{
    AbortMe();
}

TEST_CASE( "test3", "[test3]")
{
    REQUIRE(2 + 2 == 4);
}