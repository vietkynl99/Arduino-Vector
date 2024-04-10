#ifndef _VECTOR_H_
#define _VECTOR_H_

template <typename T>
class Vector
{
private:
    int mSize;
    T *mDataArr;

public:
    Vector()
    {
        mDataArr = nullptr;
        mSize = 0;
    }

    ~Vector()
    {
        if (mDataArr != nullptr)
        {
            delete[] mDataArr;
            mDataArr = nullptr;
        }
        mSize = 0;
    }

    bool push_back(T value)
    {
        int newSize = mSize + 1;
        T *newDataArr = new T[newSize];
        if (newDataArr == nullptr)
        {
            return false;
        }

        if (mSize > 0)
        {
            for (int i = 0; i < mSize; i++)
            {
                newDataArr[i] = mDataArr[i];
            }
            // memcpy(newDataArr, mDataArr, mSize * sizeof(T));
            delete[] mDataArr;
        }
        newDataArr[newSize - 1] = value;

        mSize = newSize;
        mDataArr = newDataArr;
        return true;
    }

    T at(int index)
    {
        if (index >= 0 && index < mSize)
        {
            return mDataArr[index];
        }
        else
        {
            T value;
            return value;
        }
    }

    int size()
    {
        return mSize;
    }

    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            if (this->mDataArr)
            {
                delete[] this->mDataArr;
                this->mDataArr = nullptr;
            }

            this->mSize = other.mSize;
            if (this->mSize > 0)
            {
                this->mDataArr = new T[this->mSize];
                if (this->mDataArr)
                {
                    memcpy(this->mDataArr, other.mDataArr, other.mSize * sizeof(T));
                }
                else
                {
                    this->mSize = 0;
                }
            }
        }
        return *this;
    }

    T &operator[](int index)
    {
        return at(index);
    }
};
#endif