<!-- .slide: data-background="#111111" -->

# Recap

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## What was the most difficult thing?

## What have you learned today?


___

### Points to remember

* <!-- .element: class="fragment fade-in" --> Deduction guides help the compiler to deduce proper template classes
* <!-- .element: class="fragment fade-in" --> SFINAE is used to disable code generation for a certain types
* <!-- .element: class="fragment fade-in" --> To pass a template class to a template you need to use so-called template template arguments
* <!-- .element: class="fragment fade-in" --> If you want a function that can take any number of arguments use variadic templates
* <!-- .element: class="fragment fade-in" --> Use fold expressions to simplify operations on variadic arguments
* <!-- .element: class="fragment fade-in" --> If possible, you can replace template functions with generic lambdas (from C++14). Just keep in mind that lambdas are objects and have a limited lifespan.
* <!-- .element: class="fragment fade-in" --> If possible, use `if constexpr`, `static_assert` or concepts to emulate SFINAE.

___

## Pre-test answers

___

## Pre-test 1/3 🤯

### Czy poniższy kod jest poprawny?

```cpp
template<typename... Args> bool f(Args... args) {
    return (args && ... && args);
}
```

1. <!-- .element: class="fragment highlight-red" --> Tak
2. <!-- .element: class="fragment highlight-green" --> Nie, paczka parametrów jest użyta dwukrotnie w wyrażeniu fold
3. <!-- .element: class="fragment highlight-red" --> Nie, operator elipsis (wielokropka) jest źle użyty
4. <!-- .element: class="fragment highlight-red" --> Nie, jako typ argumentu funkcja powinna przyjmować `Args&&...`

___
<!-- .slide: style="font-size: 0.9em" -->

## Pre-test 2/3 🤯

### Co wypisze się na ekranie?

```cpp
#include <iostream>

template <typename T>
void fun(T)
{
  static int i;
  std::cout << ++i;
}

int main()
{
  fun(1);
  fun(1.0);
  fun(2);
}
```

#### <code class="fragment fade-in">112`

___
<!-- .slide: style="font-size: 0.8em" -->

## Pre-test 3/3 🤯

### Zaznacz prawdziwe stwierdzenia o poniższym kodzie

```cpp
template<typename T> class MyDeleter {};
template<typename T, typename Policy> class Handle { /* ... */ };

int main() {
    Handle<int, MyDeleter> h;
}
```

1. <!-- .element: class="fragment highlight-red" --> Kod się kompiluje
2. <!-- .element: class="fragment highlight-green" --> `MyDeleter`  nie może być użyte jako argument szablonowy `Policy`
3. <!-- .element: class="fragment highlight-red" --> `template<typename T, template typename Policy>` - to powinno naprawić ten kod
4. <!-- .element: class="fragment highlight-green" --> `template<typename T, template <typename ...> typename Policy>` - to powinno naprawić ten kod
5. <!-- .element: class="fragment highlight-green" --> `template<typename T, template <typename></typename> typename Policy>` - to powinno naprawić ten kod
