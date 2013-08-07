int get_size()
{
    return 1;
}

int main()
{
    // with for-loop
    begin:
      int sz = get_size();
      if (sz <= 0) {
          goto begin;
      }


    // Loop equivalent.
    while (get_size() <= 0);
}
