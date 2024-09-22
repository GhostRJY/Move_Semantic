#include <iostream>
#include<conio.h>
#include"SmartPointer.h"
#include"Timer.h"
#include"DynArray.h"

SmartPointer<TestObject> doObject();
DynArray<int> cloneDoubledArray(const DynArray<int> &arr);

void testCopying()
{
    ////Проверяю работоспособность
    std::cout << "*****************первый пример*************************\n";
    SmartPointer<TestObject> obj1{ new TestObject };
    std::cout << "Первый объект -> " << (obj1.isNull() ? "Null" : "not null") << '\n';
    std::cout << "Адрес первого объекта -> " << &obj1 << "\n\n";
    _getch();


    std::cout << "*****************второй пример*************************\n";
    SmartPointer<TestObject> obj2(obj1);
    std::cout << "Второй объект -> " << (obj2.isNull() ? "Null" : "not null") << '\n';
    std::cout << "Адрес второго объекта -> " << &obj2 << "\n\n";
    _getch();


    std::cout << "*****************Третий пример*************************\n";
    SmartPointer<TestObject> obj3;
    obj3 = obj2;
    std::cout << "Третий объект -> " << (obj3.isNull() ? "Null" : "not null") << '\n';
    std::cout << "Адрес второго объекта -> " << &obj3 << "\n\n";
    _getch();
    system("cls");
}

int main()
{
    setlocale(LC_ALL, "rus");
    testCopying();
    
    {
        //удали DEBUG в хедере увидишь разницу
        std::cout << "*****************четвертый пример*************************\n";
        SmartPointer<TestObject> obj4;
        obj4 = doObject();
        std::cout << "Четвертый объект -> " << (obj4.isNull() ? "Null" : "not null") << '\n';
        std::cout << "Адрес Четвертого объекта -> " << &obj4 << "\n\n";
        _getch();
        
    }
    system("cls");
    //Тест динамического массива
    Timer t;
    DynArray<int> arr(1000000);

    for(int i{ 0 }; i < arr.getLength(); ++i)
        arr[i] = i;

    arr = cloneDoubledArray(arr);

    std::cout << t.elapsed() << '\n';

    return 0;
}

SmartPointer<TestObject> doObject()
{
    SmartPointer<TestObject> object{ new TestObject };

    std::cout << "Временный объект -> " << (object.isNull() ? "Null" : "not null") << '\n';
    std::cout << "Адрес временного объекта -> " << &object << "\n\n";

    return object;
}

DynArray<int> cloneDoubledArray(const DynArray<int> &arr)
{
    DynArray<int> doubledArr(arr.getLength());
    for(int i{ 0 }; i < doubledArr.getLength(); ++i)
        doubledArr[i] = arr[i] * 2;

    return doubledArr;
}