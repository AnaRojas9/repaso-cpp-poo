#ifndef ARREGLO_HPP
#define ARREGLO_HPP

#include <cstddef>

template <typename T>
class Arreglo {
public:
    explicit Arreglo(std::size_t n) : n_(n), datos_(new T[n]()) {}

    Arreglo(const Arreglo& o) : n_(o.n_), datos_(new T[o.n_]) {
        for (std::size_t i = 0; i < n_; ++i) datos_[i] = o.datos_[i];
    }

    ~Arreglo() { delete[] datos_; }

    T& operator[](std::size_t i) { return datos_[i]; }
    const T& operator[](std::size_t i) const { return datos_[i]; }

    std::size_t tam() const { return n_; }

private:
    std::size_t n_;
    T* datos_;
};

#endif