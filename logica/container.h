#ifndef CONTAINER
#define CONTAINER

template <class T>
class Container {
    private:
        T* punt;
        unsigned int capienza;      //capienza totale del mio vettore
        unsigned int dim;           //dimensione corrente del mio vettore
    public:
        typedef T* iterator;

        Container();
        void add(const T&);
        T& pos(const unsigned int&) const;
        void clear();
        bool erase(const unsigned int&);
        unsigned int getCapienza() const;
        unsigned int getDim() const;
        bool isEmpty() const;

        iterator begin() const;
        iterator end() const;

        ~Container(); //distruttore
        bool operator!=(const Container<T>&) const;
        bool operator<(const Container<T>&) const;
        Container<T>& operator=(const Container<T>&);
        bool operator==(const Container<T>&) const;
        T& operator[](const unsigned int&) const;

        int search(const T&) const;
};

template<class T>
Container<T>::Container(): punt(nullptr), capienza(0), dim(0){}

template<class T>
void Container<T>::add(const T& t) {
    if(isEmpty()){
        capienza=1;
        punt=new T[1];
    }
    if(dim >= capienza) {
        capienza = 1+dim;
        T* newPunt = new T[capienza];
        for(unsigned int i = 0; i < dim; ++i) {
            newPunt[i] = punt[i];
        }
        delete[] punt;
        punt = newPunt;
    }
    punt[dim] = t;
    dim++;
}

template<class T>
T& Container<T>::pos(const unsigned int& i) const {
    if(i <= dim) {
        return punt[i];
    }
}

template<class T>
void Container<T>::clear() {
    if(dim > 0) {
        T* newPunt = nullptr;
        delete[] punt;
        punt = newPunt;
        capienza = 0;
        dim = 0;
    }
}

template<class T>
bool Container<T>::erase(const unsigned int &i) {
    if(i < dim) {
        unsigned int pos = 0;
        T* newPunt = new T[capienza];
        for(unsigned int l = 0; l < dim; l++) {
            if(l != i) {
                newPunt[pos] = punt[l];
                pos++;
            }
        }
        dim--;
        delete[] punt;
        punt = newPunt;
        return true;
    }
    return false;
}

template<class T>
unsigned int Container<T>::getCapienza() const {
    return capienza;
}

template<class T>
unsigned int Container<T>::getDim() const {
    return dim;
}

template<class T>
bool Container<T>::isEmpty() const {
    return dim == 0;
}

template<class T>
typename Container<T>::iterator Container<T>::begin() const {
    return punt;
}

template<class T>
typename Container<T>::iterator Container<T>::end() const {
    return punt+dim;
}

template<class T>
T& Container<T>::operator[](const unsigned int& t) const {
    return punt[t];
}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& t) {
    if(t.isEmpty()) {
        clear();
    }
    else if(this != &t) {
        T* newPunt = new T[t.capienza];

        for(unsigned int i = 0; i < t.dim; ++i) {
            newPunt[i] = t[i];
        }
        delete[] punt;
        dim = t.dim;
        capienza = t.capienza;
        punt = newPunt;
    }
    return *this;
}

template<class T>
bool Container<T>::operator==(const Container<T>& t) const {
    if(punt && t) {
        if(dim == t.getDim()) {
            for(unsigned int i = 0; i < dim; ++i) {
                if(punt[i] != t[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

template<class T>
bool Container<T>::operator!=(const Container<T>& t) const {
    if(punt && t) {
        if(dim == t.getDim()) {
            for(unsigned int i = 0; i < dim; ++i) {
                if(punt[i] == t[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

template<class T>
bool Container<T>::operator<(const Container<T>& t) const {
    return punt < t.punt;
}

template<class T>
int Container<T>::search(const T& t) const {
    for(unsigned int i = 0; i < dim; ++i) {
        if(punt[i] == t) {
            return i;
        }
    }
    return -1;
}

//Distruttore
template <class T>
Container<T>::~Container() {
    if(punt) delete[] punt; //distruzione profonda
}


// ricerca multipla di occorrenze, ritorna un container con tutti i risultati
/*template <class T>
void Container<T>::research(QString text, Container &temp) const{
    if(text != "") {
        for(int i=0;i<temp.dim;i++){
            if(!(temp[i]->get_titolo()==text)){
                temp.remove(*temp[i]);
                i--;
            }
        }
    }
}

template <class T>
Container<T> Container<T>::search(QString titolo, QString genere, QString autore) const{//side effect?
    if(titolo=="" && genere=="" && autore=="")
        throw wrong("Nessun parametro inserito per la ricerca!");
    Container aux = *this;
    research(titolo, aux);
    research(genere, aux);
    research(autore, aux);
    return aux;
}*/


#endif // CONTAINER
