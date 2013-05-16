// TODO: check this!
int main()
{
    // We cannot change v2; const is top-level.
    const int v2 = 0;
    
    // OK: copying the value of v2; top-level const in v2 is ignored.
    int v1 = v2;
    
    // OK: 
    int *p1 = &v1, &r1 = v1;
    
    // We can change p2; const is low-level.
    // We cannot change p3; const is top-level. TODO: check this???
    int i = 1;
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
}
