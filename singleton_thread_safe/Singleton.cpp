#include "Singleton.h"

Singleton* Singleton::GetInstance(const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

std::string Singleton::value() {
    return value_;
}
