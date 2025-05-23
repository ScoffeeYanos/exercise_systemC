#ifndef FULL_ASOC_CACHE_H
#define FULL_ASOC_CACHE_H

#include <cstdlib>
#include <map>

using std::map;

// Template Class for fully associative cahe
template <class TAG_T, class ENTRY_T>
class full_asoc_cache
{
  public:
    typedef typename map<TAG_T, ENTRY_T>::size_type size_type;
    
    // Constructor
    full_asoc_cache(size_type size);
    
    // Read from Cache
    bool get(const TAG_T&, ENTRY_T&);
    
    // Insert into Cache using random replace strategy
    void insert(const TAG_T&, const ENTRY_T&);
    
    // Delete entry from Cache
    void erase(const TAG_T&);
    
    // Clear Cache
    void clear();
    
  protected:
    size_type _size;
    map<TAG_T, ENTRY_T> _map;
};

template <class TAG_T, class ENTRY_T>
inline
full_asoc_cache<TAG_T, ENTRY_T>::full_asoc_cache(size_type size) : _size(size)
{
  std::srand(size);
}
template <class TAG_T, class ENTRY_T>
bool full_asoc_cache<TAG_T,ENTRY_T>::get(const TAG_T& tag, ENTRY_T& entry){
  auto it = _map.find(tag);
  if(it != _map.end()){
    entry = it->second;
    return true;
  }
  return false;
}
template <class TAG_T, class ENTRY_T>
void full_asoc_cache<TAG_T,ENTRY_T>::insert(const TAG_T& tag, const ENTRY_T& entry){
    if(_map.size() >= _size) {
        auto it = _map.begin();
        std::advance(it, std::rand() % _size);
        _map.erase(it);
    }
    _map[tag] = entry;
}
template <class TAG_T, class ENTRY_T>
void full_asoc_cache<TAG_T,ENTRY_T>::erase(const TAG_T& tag){
    _map.erase(tag);
}
template <class TAG_T, class ENTRY_T>
void full_asoc_cache<TAG_T,ENTRY_T>::clear(){
    _map.clear();
}

#endif // FULL_ASOC_CACHE_H
