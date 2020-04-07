

//main.cpp
vector_t<double> z;

cout << "Suma de vector_t<double>: " << endl;
z.write();

//vector_t.hpp
template<class T> T scalProd(const vector_t<T>& v, const vector_t<T>& w) {
  assert (v.getSize() == w.getSize());
  for (int i = 0; i < v.getSize(); i++)
    z[i] = v[i] + w[i];
}
