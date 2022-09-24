/*
 * References:
 *
 * [codingame.com] Init statement for if/switch
 *   https://www.codingame.com/playgrounds/2205/7-features-of-c17-that-will-simplify-your-code/init-statement-for-ifswitch
 *
 * [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *   https://youtu.be/pEzV32yRu4U
 *
 * [doumler2017] The new C++17 and why it's good for you - Timur Doumler, ADC 2017
 *   https://youtu.be/ky_eXBMcJK0?t=2m9s
 *
 * [lorimer20160822] C++17 If statement with initializer
 *   https://skebanga.github.io/if-with-initializer/
 *
 * [turner20160725] C++ Weekly - Ep 21 C++17's `if` and `switch` Init Statements
 *   https://youtu.be/AiXU5EuLZgc
 */

int GetValue() { return 5; }

int main()
{
    {   // OLD METHOD

        // Note that val's scope is larger than necessary, it 'leaks' from the
        // scope where it is really used to the enclosing scope.
        auto val = GetValue();
        if (val == 5) {
            // success
        } else {
            // failure 
        }
    }

    {   // C++17 METHOD

        // Here, val is visible only inside the if and else statements and
        // does not 'lea'k.
        if (auto val = GetValue(); val == 5) {
            // success
        } else {
            // failure
        }
    }
}
