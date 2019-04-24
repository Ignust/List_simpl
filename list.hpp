#ifndef LIST_HPP
#define LIST_HPP

template<typename T>
class List
{
private:
    class Cell
    {
    public:
        Cell(T data = T());
        ~Cell(){}
        T mData;
        Cell* mNextCell;
    };
public:
    class iterator
    {
    public:
        iterator() :mCell(nullptr){}

        iterator(Cell* ptr) : mCell(ptr){}
        ~iterator(){}
    private:

    private:
        Cell* mCell;
    };
public:
    List();
    ~List();

    void push_back(T data);
    int getSize();
    T& operator[] (const int index);
    void pop_Front();
    void clear();
    void erase(const int index);
    void insert(const int index, const T data);
    Cell* begin();

private:
    Cell* mFirstCell;
    int mSize;

};



//---------------------------------------------------------------------------------
template<typename T>
List<T>::Cell::Cell( T data)
    : mData(data),
      mNextCell(nullptr)
//---------------------------------------------------------------------------------
{

}










//---------------------------------------------------------------------------------
template <typename T>
List<T>::List()
    : mFirstCell(nullptr),
      mSize(0)
//---------------------------------------------------------------------------------
{

}

//---------------------------------------------------------------------------------
template <typename T>
List<T>::~List()
//---------------------------------------------------------------------------------
{
    clear();
}

//---------------------------------------------------------------------------------
template <typename T>
void List<T>::push_back(T data)
//---------------------------------------------------------------------------------
{
    Cell* tempPtr = new Cell(data);
    if(mFirstCell == nullptr){
        mFirstCell = tempPtr;
    } else {
        Cell* current = mFirstCell;
        while(current->mNextCell != nullptr){
            current = current->mNextCell;
        }
        current->mNextCell = tempPtr;
    }

    mSize++;
}

//---------------------------------------------------------------------------------
template <typename T>
int List<T>::getSize()
//---------------------------------------------------------------------------------
{
    return mSize;
}

//---------------------------------------------------------------------------------
template <typename T>
T& List<T>::operator[](const int index)
//---------------------------------------------------------------------------------
{
    Cell* tempCell = mFirstCell;
    int counter = 0;
    while(tempCell != nullptr){
        if(counter == index){
            return tempCell->mData;
        }
        tempCell = tempCell->mNextCell;
        counter++;
    }
}

//---------------------------------------------------------------------------------
template <typename T>
void List<T>::pop_Front()
//---------------------------------------------------------------------------------
{
    if(mFirstCell != nullptr){
        Cell* tempCell = mFirstCell;
        mFirstCell = mFirstCell->mNextCell;
        delete tempCell;
        mSize--;
    }
}

//---------------------------------------------------------------------------------
template <typename T>
void List<T>::clear()
//---------------------------------------------------------------------------------
{
    while (mSize != 0) {
        pop_Front();
    }
}

//---------------------------------------------------------------------------------
template <typename T>
void List<T>::erase(const int index)
//---------------------------------------------------------------------------------
{
    if(index >= mSize){
        return;
    }

    Cell* tempCell = mFirstCell;
    for(int i = 0; i< index-1; i++){
        tempCell = tempCell->mNextCell;
    }
    Cell* deletCell =tempCell->mNextCell;
    tempCell->mNextCell = deletCell->mNextCell;
    delete deletCell;
    mSize--;
}

//---------------------------------------------------------------------------------
template <typename T>
void List<T>::insert(const int index, const T data)
//---------------------------------------------------------------------------------
{

}

//---------------------------------------------------------------------------------
template <typename T>
typename List<T>::Cell* List<T>::begin()
//---------------------------------------------------------------------------------
{
    return mFirstCell;
}


#endif // LIST_HPP
