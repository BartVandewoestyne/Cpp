/*
 * Example to illustrate whether we need an empty destructor or not.
 *
 * TODO: finish this!
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/1025313/will-an-empty-destructor-do-the-same-thing-as-the-generated-destructor
 *   [2] http://www.codesynthesis.com/~boris/blog/2012/04/04/when-provide-empty-destructor/
 *   [3] http://programmers.stackexchange.com/questions/144092/the-rule-of-5-to-use-it-or-not
 */
class Foo {
    public:
        Foo();
    private:
        int t;
};
