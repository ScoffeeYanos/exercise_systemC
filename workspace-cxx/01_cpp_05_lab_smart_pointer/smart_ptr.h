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
