#pragma once

template <typename T>
class UniquePtr
{
template <typename Q>
friend class UniquePtr;

public:
  UniquePtr()
    : data {nullptr} {}

  UniquePtr(T* && new_data)
    : data {new_data}
  {
    new_data = nullptr;
  }

  UniquePtr(const UniquePtr &) = delete;

  template <typename Q>
  UniquePtr(UniquePtr<Q> && temp)
    : data {temp.data}
  {
    temp.data = nullptr;
  }
  
  ~UniquePtr()
  {
    if (data != nullptr)
      delete data;
  }

  UniquePtr& operator=(const UniquePtr &) = delete;

  template <typename Q>
  UniquePtr& operator=(UniquePtr<Q> && temp)
  {
    if (data != nullptr)
      delete data;

    data = temp.data;
    temp.data = nullptr;

    return *this;
  }

  bool isNull() const
  {
    return (data == nullptr);
  }

  T& operator*() const
  {
    return *data;
  }

  T* operator->() const
  {
    return data;
  }

private:
  T * data;
};
