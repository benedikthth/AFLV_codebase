// Difference of set A and B (returns A, without any elements in B)
template<class T>
set<T> operator -(set<T> reference, set<T> items_to_remove)
{
    set<T> result;
    std::set_difference(
        reference.begin(), reference.end(),
        items_to_remove.begin(), items_to_remove.end(),
        std::inserter(result, result.end()));
    return result;
}
// Union of A and B 
template<class T>
set<T> operator +(set<T> reference, set<T> items_to_add)
{
    set<T> result;
    std::set_union(
        reference.begin(), reference.end(),
        items_to_add.begin(), items_to_add.end(),
        std::inserter(result, result.end()));
    return result;
}
// Intersection of A and B. (returns set of elements that are in both A and B);
template<class T>
set<T> operator /(set<T> A, set<T> B ){
  set<T> result;
  std::set_intersection( A.begin(), A.end(), B.begin(), B.end(), std::inserter(result, result.end()));
  return result;
}

template<class T>
bool contains(set<T> s, T item){
  return find(s.begin(), s.end(), item) != s.end();
}