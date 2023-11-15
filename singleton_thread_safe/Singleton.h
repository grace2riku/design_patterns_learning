#ifndef _H_SINGLETON_
#define _H_SINGLETON_

#include <iostream>

class Singleton {
    private:
        static Singleton* pinstance_;
        static std::mutex mutex_;

    protected:
        Singleton(const std::string value): value_(value) {}

        static Singleton* singleton_;
        ~Singleton() {}

        std::string value_;

    public:
        Singleton(Singleton &other) = delete;
        void operator = (const Singleton &) = delete;

        static Singleton* GetInstance(const std::string& value);

        std::string value();
};

#endif	// _H_BOOT_