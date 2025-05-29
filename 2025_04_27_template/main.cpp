#include <iostream>
#include <vector>
#include <cassert>
 
template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <class T>
class Stack 
{
private:
    std::vector<T> elements;
    int m_size;
    int m_maxSize;
public:
    //在类内定义：
    Stack()
    {
        m_maxSize = 100;
        m_size = 0;
    }
    void push(T const& elem) 
    {
        elements.push_back(elem);
        m_size++;
    }
    T pop();
    T const& top() const;
    bool isEmpty();
};
// 在类外定义
template <typename T>
T Stack<T>::pop()
{
    assert(!elements.empty());
    T elem = elements.back();
    elements.pop_back();
    m_size--;
    return elem;
}
template<typename T>
T const& Stack<T>::top() const
{
    assert(!elements.empty);
    return elements.back();
}
template<typename T>
bool Stack<T>::isEmpty()
{
    return m_size == 0;
}
int main() {
    std::cout << max(3, 5) << std::endl;
    std::cout << max('a', 'b') << std::endl;

    Stack<char> charStack;
    charStack.push('a');
    charStack.push('b');
    charStack.push('c');

    while(!charStack.isEmpty())
    {
        std::cout<<charStack.pop()<<std::endl;
    }
    return 0;
}