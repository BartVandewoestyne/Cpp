char *init(int ht, int wd = 80, char bckgrnd = ' ');

int main()
{

// (a) ERROR, because init does not provide a default for the ht parameter.
//init();

// (b) OK, and probably also what was intended, because calls init(24, 10, ' ');
init(24, 10);

// (c) OK, but probably not what was intended, because calls init(14, '*', ' ');
init(14, '*');

}
