// CodeVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector
{
private:
    T* data;
    int currentSize = 0;
    int currentCapacity = 0;

public:
    SimpleVector() : data(new T[10]), currentSize(0), currentCapacity(10) {}
    SimpleVector(int _capacity) : data(new T[_capacity]), currentSize(0), currentCapacity(_capacity) {}

    SimpleVector(const SimpleVector<T>& _class)
    {
        currentCapacity = _class.currentCapacity;
        data = new T[currentCapacity];
        currentSize = _class.currentSize;
        for (int i = 0; i < currentSize; i++)
        {
            data[i] = _class.data[i];
        }
    }
    ~SimpleVector()
    {
        delete[] data;
        data = nullptr;
    }

    void resize(int _i)
    {
        if (_i > currentCapacity)
        {
            currentCapacity = _i;
            T* temp = new T[currentCapacity];
            for (int i = 0; i < currentSize; i++)
            {
                temp[i] = data[i];
            }

            delete[] data;
            data = temp;
        }
    }

    void push_back(const T& _T)
    {
        if (currentSize == currentCapacity)
        {
            resize(currentCapacity + 5);
        }
        data[currentSize] = _T;
        ++currentSize;
    }

    void pop_back()
    {
        if (currentSize > 0)
        {
            --currentSize;
        }
    }

    int size() const
    {
        return currentSize;
    }

    int capacity() const
    {
        return currentCapacity;
    }

    T operator[] (int _i)
    {
        if (_i >= 0 || _i < currentSize)
        {
            return data[_i];
        }
        else
        {
            cout << "Out of range" << "\n";
        }
    }

    void sortData()
    {
        sort(data, data + currentSize);
    }
};

int main()
{
    // int
    SimpleVector<int> SV;
    SV.push_back(8);
    SV.push_back(5);
    SV.push_back(9);
    for (int i = 0; i < SV.size(); i++)
    {
        cout << SV[i] << "\n";
    }
    SV.sortData();
    cout << "Sort!" << "\n";
    for (int i = 0; i < SV.size(); i++)
    {
        cout << SV[i] << "\n";
    }
    cout << "pop_back !" << "\n";
    SV.pop_back();
    for (int i = 0; i < SV.size(); i++)
    {
        cout << SV[i] << "\n";
    }

    cout << "===============================" << "\n";
    // char
    SimpleVector<char> SV2;
    SV2.push_back('A');
    SV2.push_back('C');
    SV2.push_back('B');
    for (int i = 0; i < SV2.size(); i++)
    {
        cout << SV2[i] << "\n";
    }
    SV2.sortData();
    cout << "Sort!" << "\n";
    for (int i = 0; i < SV2.size(); i++)
    {
        cout << SV2[i] << "\n";
    }
    cout << "===============================" << "\n";
    // auto resize on push_back
    SimpleVector<int> SV3;
    SV3.push_back(2);
    SV3.push_back(3);
    SV3.push_back(4);
    SV3.push_back(1);
    SV3.push_back(8);
    SV3.push_back(9);
    SV3.push_back(5);
    SV3.push_back(6);
    SV3.push_back(7);
    SV3.push_back(10);
    cout << "this capacity : " << SV3.capacity() << "\n";
    for (int i = 0; i < SV3.size(); i++)
    {
        cout << SV3[i] << "\n";
    }
    SV3.push_back(15);
    SV3.push_back(100);
    cout << "this capacity : " << SV3.capacity() << "\n";
    for (int i = 0; i < SV3.size(); i++)
    {
        cout << SV3[i] << "\n";
    }
    SV3.sortData();
    cout << "Sort!" << "\n";
    for (int i = 0; i < SV3.size(); i++)
    {
        cout << SV3[i] << "\n";
    }
}