#ifndef SMART_PTR_H
#define SMART_PTR_H

template <class T> class smart_ptr
{
  template<class Y> friend class smart_ptr;

  public:
    smart_ptr(T *ptr = 0);
    ~smart_ptr();

    // Copy Constructor    
    explicit smart_ptr(const smart_ptr &sptr);
    
    template <class Y>
    explicit smart_ptr(const smart_ptr<Y> &sptr);

    // Copy Assignment Operator    
    smart_ptr& operator=(const smart_ptr &sptr);
    
    template <class Y>
    smart_ptr& operator=(const smart_ptr<Y> &sptr);

    // Comparison and typical pointer-Operators    
    bool operator==(const smart_ptr &sptr) const;
    T& operator*() const;
    T* operator->() const;
    
  protected:
    T   *_ptr;
    int *_count;
};

// TODO
// Implement the missing functions!

#endif // SMART_PTR_H
template <class T>
smart_ptr<T>::smart_ptr(T *ptr) : _ptr(ptr)
{
    if (ptr)
        _count = new int(1);
    else
        _count = nullptr;
}

template <class T>
smart_ptr<T>::~smart_ptr()
{
    if (_count) {
        if (--(*_count) == 0) {
            delete _ptr;
            delete _count;
        }
    }
}
template <class T>
smart_ptr<T>::smart_ptr(const smart_ptr<T> &sptr) : _ptr(sptr._ptr), _count(sptr._count)
{
    if (_count)
        ++(*_count);
}
template <class T>
template <class Y>
smart_ptr<T>::smart_ptr(const smart_ptr<Y> &sptr) : _ptr(sptr._ptr), _count(sptr._count)
{
    if (_count)
        ++(*_count);
}
template <class T>
smart_ptr<T> &smart_ptr<T>::operator=(const smart_ptr<T> &sptr)
{
    if (this != &sptr) {
        if (_count && --(*_count) == 0) {
            delete _ptr;
            delete _count;
        }
        _ptr = sptr._ptr;
        _count = sptr._count;
        if (_count)
            ++(*_count);
    }
    return *this;
}
template <class T>
template <class Y>
smart_ptr<T> &smart_ptr<T>::operator=(const smart_ptr<Y> &sptr)
{
    if (_count && --(*_count) == 0) {
        delete _ptr;
        delete _count;
    }
    _ptr = sptr._ptr;
    _count = sptr._count;
    if (_count)
        ++(*_count);
    return *this;
}
template <class T>
bool smart_ptr<T>::operator==(const smart_ptr<T> &sptr) const
{
    return _ptr == sptr._ptr;
}
template <class T>
T &smart_ptr<T>::operator*() const
{
    return *_ptr;
}
template <class T>
T *smart_ptr<T>::operator->() const
{
    return _ptr;
}