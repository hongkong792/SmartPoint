#ifndef SMARTPOINT
#define SMARTPOINT

namespace DTLab
{
template<typename T>
class SmartPoint
{
protected:
   T * m_point;
public:
    SmartPoint(T *p = nullptr) {
        m_point = p;
    }
    //同一片堆空间只能由一个指针指向
    SmartPoint(const SmartPoint<T> &obj)
    {
        m_point = obj.m_point;
        const_cast<SmartPoint<T> &>(obj).m_point = nullptr;
    }
    SmartPoint<T>& operator=(const SmartPoint<T> &obj){
        if(this  != &obj){
            delete m_point;
            m_point = obj.m_point;
            const_cast<SmartPoint<T> &>(obj).m_point = nullptr;

        }
        return *this;
    }

    T *operator->()
    {
        return m_point;
    }
    T*operator*()
    {
        return *m_point;
    }
    bool isNull()
    {
        return (m_point == nullptr);
    }
    T* get()
    {
        return m_point;
    }
    ~SmartPoint()
    {
        delete m_point;
    }

};


}


#endif // SMARTPOINT

