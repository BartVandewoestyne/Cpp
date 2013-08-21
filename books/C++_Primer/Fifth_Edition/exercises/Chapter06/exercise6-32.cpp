/**
 * This code seems ok to me.  It fills the array with values from 1 to 10.
 */

int &get(int *array, int index) { return array[index]; }

int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
