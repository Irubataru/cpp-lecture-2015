#pragma once

template <typename T>
class SharedPtr
{
public:
  SharedPtr()
    : data {nullptr},
      counter {nullptr} {}

  SharedPtr(T* && new_data)
    : data {new_data},
      counter {new unsigned {1}}
  {
    new_data = nullptr;
  }

  SharedPtr(const SharedPtr & copy)
    : data {copy.data},
      counter {copy.counter}
  {
    increment();
  }

  SharedPtr(SharedPtr && move)
    : data {move.data},
      counter {move.counter}
  {
    move.data = nullptr;
    move.counter = nullptr;
  }

  ~SharedPtr()
  {
    cleanup();
  }

  SharedPtr& operator=(const SharedPtr & copy)
  {
    if (this == &copy or data == copy.data)
      return *this;

    cleanup();
    data = copy.data;
    counter = copy.counter;

    increment();
    return *this;
  }

  SharedPtr& operator=(SharedPtr && move)
  {
    if (this == &move) {
      return *this;
    } else if (data == move.data) {
      decrement();
      return *this;
    }

    cleanup();
    data = move.data;
    counter = move.counter;

    move.data = nullptr;
    move.counter = nullptr;

    decrement();
    return *this;
  }

  T& operator*() const
  {
    return *data;
  }

  T operator->() const
  {
    return data;
  }

  unsigned useCount() const
  {
    if (counter == nullptr)
      return 0;
    else
      return *counter;
  }

  bool isNull() const
  {
    return (counter == nullptr);
  }

private:
  T * data;
  unsigned * counter;

  void cleanup()
  {
    if (counter != nullptr) {
      if (*counter == 1) {
        delete data;
        delete counter;
      } else {
        *counter = *counter - 1;
      }
      data = nullptr;
      counter = nullptr;
    }
  }

  void increment()
  {
    if (counter != nullptr)
      *counter += 1;
  }

  void decrement()
  {
    if (counter != nullptr)
      *counter -= 1;
  }

};
