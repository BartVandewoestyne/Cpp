class Y;  // A forward declaration is necessary here!

class X {
private:
    Y *pY;
};

class Y {
private:
    X myX;
};
