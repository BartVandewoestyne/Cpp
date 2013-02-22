template<typename C>
bool lastGreaterThanFirst(const C& container)
{
    if (container.empty()) return false;

    typename C::const_iterator begin(container.begin());
    typename C::const_iterator end(container.end());

    return *--end > *begin;
}
