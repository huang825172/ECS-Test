#include <iostream>

namespace ecs {

// Extract components from query in system function definition.
template <int index, class FuncType>
struct ArgTypeAt;

template <class ResultType, class Head, class... Tail>
struct ArgTypeAt<0, ResultType(Head, Tail...)> {
  using type = Head;
};

template <int index, class ResultType, class Head, class... Tail>
struct ArgTypeAt<index, ResultType(Head, Tail...)> {
  using type = typename ArgTypeAt<index - 1, ResultType(Head, Tail...)>::type;
};

// Recursive component unpack.
template <class T, class... args>
class Query {
 public:
  void iter() {
    std::cout << typeid(T).name() << std::endl;
    if constexpr (sizeof...(args) > 0) (new Query<args...>())->iter();
  }
};

template <class SystemFunc>
void systemQuery(SystemFunc func) {
  typename ArgTypeAt<0, SystemFunc>::type query;
  func(query);
}

#define createQuery(systemFunc) \
  ecs::systemQuery<decltype(systemFunc)>(systemFunc)

}  // namespace ecs
