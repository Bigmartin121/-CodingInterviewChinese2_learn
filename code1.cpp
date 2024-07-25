#include <iostream>

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);


private:
    char* m_pData;

};


// CMyString& CMyString::operator=(const CMyString& str)
// {
//     if(this == &str)
//     {
//         return *this;
//     }

//     delete[] m_pData;
//     m_pData = nullptr;

//     m_pData = new char[strlen(str.m_pData) + 1];//此处若内存不足，将当值 new char 抛出异常
//     strcpy(m_pData, str.m_pData);
//     return *this;
// }
//

//先创建实例，再交换临时实例与原来的实例
CMyString& CMyString::operator=(const CMyString& str)
{
    if(this != &str)
    {
        CMyString strTemp(str);
        
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;//strTemp 作用域仅仅在if作用域内，离开后会自动被析构，即析构掉m_pData之前指向的内存
        m_pData = pTemp;
    }

    return *this;
}


int main() { std::cout << "Hello, world!"; return 0; }