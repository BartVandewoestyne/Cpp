#include <gtest/gtest.h>

#include <csignal>

void Foo(int* n)
{
    std::cerr << "Error on line X of Foo()" << std::endl;
    exit(1);
}

void NormalExit()
{
    std::cerr << "Success" << std::endl;
    exit(0);
}

void KillProcess()
{
    std::cerr << "Sending myself unblockable signal" << std::endl;
    std::raise(SIGKILL);
}

TEST(MyDeathTest, Foo)
{
    ASSERT_DEATH(
            {
                int n = 5;
                Foo(&n);
            },
            "Error on line .* of Foo()");
}

TEST(MyDeathTest, NormalExit)
{
    EXPECT_EXIT(NormalExit(), testing::ExitedWithCode(0), "Success");
}

TEST(MyDeathTest, KillProcess)
{
    EXPECT_EXIT(
            KillProcess(), testing::KilledBySignal(SIGKILL), "Sending myself unblockable signal");
}