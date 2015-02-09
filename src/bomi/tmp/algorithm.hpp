#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace tmp {

namespace detail {
template<class Container>
using it_type = std::conditional_t<std::is_const<Container>::value,
    typename Container::const_iterator, typename Container::iterator>;
}

template<class Container, class Test>
SIA find_if(Container &c, Test test) -> detail::it_type<Container>
{ return std::find_if(std::begin(c), std::end(c), test); }

template<class Container, class Test>
SIA contains_if(const Container &c, Test test) -> bool
{
    const auto end = std::end(c);
    return std::find_if(std::begin(c), end, test) != end;
}

template<class Container, class T>
SIA find(Container &c, const T &t) -> detail::it_type<Container>
{ return std::find(std::begin(c), std::end(c), t); }

template<class Container, class T>
SIA contains(const Container &c, const T &t) -> bool
{
    const auto end = std::end(c);
    return std::find(std::begin(c), end, t) != end;
}

template<class Container, class F>
SIA transform(Container &c, F f) -> Container&
{ for (auto &item : c) f(item); return c; }

template<class Container, class F>
SIA transformed(const Container &c, F f) -> Container
{ Container ret = c; return transform<Container, F>(ret, f); }

template<class Container>
SIA sort(Container &c) -> void
{ std::sort(std::begin(c), std::end(c)); }

template<class Container, class Compare>
SIA sort(Container &c, Compare cmp) -> void
{ std::sort(std::begin(c), std::end(c), cmp); }

template<class T>
SIA max(const T &t1, const T &t2) -> T { return std::max(t1, t2); }

template<class T, class... Args>
SIA max(const T &t1, const T &t2, const Args&... args) -> T
    { return max(max(t1, t2), args...); }

template<class T>
SIA min(const T &t1, const T &t2) -> T { return std::min(t1, t2); }

template<class T, class... Args>
SIA min(const T &t1, const T &t2, const Args&... args) -> T
    { return min(min(t1, t2), args...); }

}

#endif // ALGORITHM_HPP
