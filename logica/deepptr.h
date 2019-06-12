#ifndef DEEPPTR
#define DEEPPTR

template<class T>
class DeepPtr {
    public:
        T* point;
        DeepPtr(T* = nullptr);
        DeepPtr(const DeepPtr&);
        DeepPtr<T>& operator=(const DeepPtr&);
        T& operator*() const;
        T* operator->() const;
        bool operator==(const DeepPtr&) const;
        bool operator!=(const DeepPtr&) const;
        ~DeepPtr();
};

template<class T>
DeepPtr<T>::DeepPtr(T* toPoint): point(toPoint != nullptr? toPoint->clone() : nullptr) {}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr& toDeep): point(toDeep.point != nullptr? (toDeep.point)->clone() : nullptr) {}

template<class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& toDeep) {
    if(this != &toDeep) {
        if(point) {
            delete point;
        }
        point = toDeep.point != nullptr? (toDeep.point)->clone() : nullptr;
    }
    return *this;
}

template<class T>
T& DeepPtr<T>::operator*() const {
    return *point;
}

template<class T>
T* DeepPtr<T>::operator->() const {
    return point;
}

template<class T>
bool DeepPtr<T>::operator==(const DeepPtr& toDeep) const {
    return *point == *toDeep;
}

template<class T>
bool DeepPtr<T>::operator!=(const DeepPtr& toDeep) const {
    return *point != *toDeep;
}

template<class T>
DeepPtr<T>::~DeepPtr() {
    if(point) {
        delete point;
    }
}
#endif // DEEPPTR_H
