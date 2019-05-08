ϵͳ���ú�����
==============

.. _pyqpanda: https://qpanda-2.readthedocs.io/zh_CN/latest/
Ϊ�˼��� \ **��Ч**\��\ **���**\��QPanda2�ṩ��C++ �� Python(���ڻᷢ��Python�汾��ʹ���ĵ�) �����汾����������Ҫ����C++�汾��ʹ�á�

.. ��Ҫ�˽��ѧϰpython�汾��ʹ�����Ʋ� pyqpanda_��

���뻷��
>>>>>>>>>

QPanda-2����C++Ϊ�������ԣ����ϵͳ�Ļ���Ҫ�����£�

.. list-table::

    * - software
      - version
    * - CMake
      - >= 3.1
    * - GCC
      - >= 5.0 
    * - Python
      - >= 3.6.0  


����QPanda-2
>>>>>>>>>>>>>>>>>

���������ϵͳ���Ѿ���װ��git�� �����ֱ������������������ȡQPanda2��

    .. code-block:: c

        $ git clone https://github.com/OriginQ/QPanda-2.git


��Ȼ�ˣ�����һЩΪ��װgit�Ļ����˵��Ҳ����ֱ��ͨ�������ȥ����QPanda-2�� ����Ĳ����������£�

1. ������������� https://github.com/OriginQ/QPanda-2 �� ������ҳ�ῴ����

.. image:: images/QPanda_github.png
    :align: center  

2. ��� ``Clone or Download`` �������½��棺

.. image:: images/Clone.png
    :align: center  

3. Ȼ���� ``Download zip``�� �ͻ����QPanda2�����ء�

.. image:: images/Download.png
    :align: center  

4. ��ѹ���ص��ļ����ͻῴ�����ǵ�QPanda-2��Ŀ��

    .. code-block:: c
    
        $ cd qpanda-2
        $ mkdir build
        $ cd build
        $ cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. 
        $ make
    
��װ
>>>>>>>>

������ɺ󣬰�װ�ͼ򵥵Ķֻ࣬��Ҫ�����������

    .. code-block:: c

        $ make install

��ʼ���ӱ��
>>>>>>>>>>>>>>

���������������һ�أ������ͱ����Լ�������Ӧ�á�

�����Ŷ��ڹ������ʹ��QPanda 2��������˵����δ���C++��Ŀ������Ҫ�Ҷ�˵���������һ�����Ҫ�ṩCMakelist��ʾ���������Ҳο���

    .. code-block:: c

        cmake_minimum_required(VERSION 3.1)
        project(testQPanda)
        SET(CMAKE_INSTALL_PREFIX "/usr/local")
        SET(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${CMAKE_INSTALL_PREFIX} lib/cmake")

        add_definitions("-std=c++14 -w -DGTEST_USE_OWN_TR1_TUPLE=1")
        set(CMAKE_BUILD_TYPE "Release")
        set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g -ggdb")
        set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3")
        add_compile_options(-fPIC -fpermissive)
        find_package(QPANDA REQUIRED)
        if (QPANDA_FOUND)

            include_directories(${QPANDA_INCLUDE_DIR}
                            ${THIRD_INCLUDE_DIR})
            add_executable(${PROJECT_NAME} test.cpp)
            target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
        endif (QPANDA_FOUND)


�����ʾ����Python�汾�ṩ��ʾ����һ���ģ��������ҾͲ���˵�ˡ�

    .. code-block:: c

        #include "QPanda.h"
        #include <stdio.h>
        using namespace QPanda;
        int main()
        {
            init(QMachineType::CPU);
            QProg prog;
            auto q = qAllocMany(2);
            auto c = cAllocMany(2);
            prog << H(q[0])
                << CNOT(q[0],q[1])
                << MeasureAll(q, c);
            auto results = runWithConfiguration(prog, c, 1000);
            for (auto result : results){
                printf("%s : %d\n", result.first.c_str(), result.second);
            }
            finalize();
        }

��󣬱��룬��

    .. code-block:: c

        $ mkdir build
        $ cd build
        $ cmake .. 
        $ make

���н������:

    .. code-block:: c

        00 : 512
        11 : 488 



