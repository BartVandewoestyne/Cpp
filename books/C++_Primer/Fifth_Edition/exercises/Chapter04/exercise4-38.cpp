int main()
{
    // We assume i and j are integers.
    int i = 3;
    int j = 4;

    // This is probably not what the author intended.  We loose precision here
    // due to the integer division that occurs before the cast.
    double slope = static_cast<double>(j/i);

    // This is what it should be.
    double slope2 = static_cast<double>(j) / i;
}
