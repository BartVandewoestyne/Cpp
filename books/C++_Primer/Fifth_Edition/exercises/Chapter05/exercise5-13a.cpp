char next_text()
{
    return 'a';
}

int main()
{
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
      case 'a': aCnt++;
                break;    // FIX: add break statement.
      case 'e': eCnt++;
                break;    // FIX: add break statement.
      default: iouCnt++;
    }
}
