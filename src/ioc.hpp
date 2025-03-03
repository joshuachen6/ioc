#pragma once

#define COMPONENT(lifetime, name, ...)                                         \
  class _##name {                                                              \
  public:                                                                      \
    static _##name &getInstance() {                                            \
      static _##name instance;                                                 \
      return instance;                                                         \
    }                                                                          \
    __VA_ARGS__                                                                \
    static _##name *create() { return new _##name(); }                         \
                                                                               \
  private:                                                                     \
    _##name() {}                                                               \
    _##name(const _##name &) = delete;                                         \
    _##name &operator=(const _##name &) = delete;                              \
  };                                                                           \
  class name {                                                                 \
  public:                                                                      \
    name() {                                                                   \
      if (#lifetime == "singleton") {                                          \
        instance = &_##name::getInstance();                                    \
      } else {                                                                 \
        instance = _##name::create();                                          \
      }                                                                        \
    }                                                                          \
    ~name() {                                                                  \
      if (#lifetime == "transient") {                                          \
        delete instance;                                                       \
      }                                                                        \
    }                                                                          \
    _##name &operator*() { return *instance; }                                 \
    _##name *operator->() { return instance; }                                 \
                                                                               \
  private:                                                                     \
    _##name *instance;                                                         \
  };
