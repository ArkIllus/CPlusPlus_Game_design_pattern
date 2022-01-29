#include "hungry_singleton.h"
//#include "hungry_singleton.cpp" //防止错误LNK2019 无法解析的外部符号 //警告LNK4042 对象被多次指定；已忽略多余的指定
#include "lazy_singleton_static_local.h"
//#include "lazy_singleton_DCL_mutex.h"
//#include "lazy_singleton_DCL_mutex.cpp"
#include <iostream>
#include <mutex>
using namespace std;

//严重性	代码	    说明
//错误	    LNK2019	    无法解析的外部符号 "void __cdecl testHungrySingleton(void)" (? testHungrySingleton@@YAXXZ)，函数 _main 中引用了该符号	
// 项目                 文件	                                                                                                                            行	
// _singleton_pattern	C : \Users\leshp\OneDrive\Documents\Projects\CPlusPlus_design_pattern\_singleton_pattern\_singleton_pattern\_singleton_pattern.obj	1

class Singleton
{
private:
    static Singleton* instance;
    static mutex mtx;
    Singleton() { cout << "构造饿汉（DCL_mutex）" << endl; }
    ~Singleton() { cout << "析构饿汉（DCL_mutex）" << endl; }
    Singleton(const Singleton& temp);
    Singleton& operator=(const Singleton& temp);

public:
    static Singleton* getInstance()
    {
        cout << "getInstance" << endl;
        if (instance == nullptr)
        {
            //lock_guard<mutex> guard(mtx); // 法一 lock_guard<std::mutex> gurad(mtx);
            unique_lock<mutex> lock(mtx); // 法二 unique_lock<std::mutex> lock(mtx);

            // 第一种实现：基于operator new+placement new，遵循1,2,3执行顺序依次编写代码。
            // 第二种实现：基于直接嵌入ASM汇编指令mfence，uninx的barrier宏也是通过该指令实现的。
            // #define barrier() __asm__ volatile ("lwsync")
            // barrier(); 
            // 第三种实现：Atomic
            // 第四种实现：pthread_once 保证初始化单例的函数只执行一次
            // 第五种实现：C++11的local static变量的内存模型 （《Effective C++》）

            if (instance == nullptr)
            {
                // instance = new Singleton();
                // 这条语句（new关键字）会导致三个事情的发生：
                // 1.调用operator new 分配能够存储Singleton对象的内存；
                // 2.在被分配的内存中构造一个Singleton对象；
                // 3.让p指向这块被分配的内存，返回指针p。

                Singleton* tmp = static_cast<Singleton*>(operator new(sizeof(Singleton)));
                new(tmp)Singleton();
                instance = tmp;

                // 可能会由于内存读写的乱序执行导致这段代码出问题(在上面提供了5种解决办法)
            }
        }
        return instance;
    }

    // 实现一个内嵌垃圾回收类
    class CGarbo //Garbo意为垃圾工人
    {
    public:
        ~CGarbo()
        {
            if (Singleton::instance)
                delete Singleton::instance;
        }
    };
    static CGarbo Garbo; // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
};
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx; // 默认初始化
Singleton::CGarbo Garbo; // 默认初始化

void testLazySingleton_DCL_mutex()
{
	cout << "在testLazySingleton_DCL_mutex程序的开始" << endl;
	Singleton::getInstance();
    Singleton* s = Singleton::getInstance();
	cout << "在testLazySingleton_DCL_mutex程序的结束" << endl;
}

int main() {
    cout << "在main程序的开始" << endl;
    testHungrySingleton();
    testLazySingleton_StaticLocal();
    testLazySingleton_DCL_mutex();
    cout << "在main程序的结束" << endl;
}