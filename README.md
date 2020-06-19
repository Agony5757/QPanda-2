## QPanda 2

![图片: ](./Documentation/img/1.png)

QPanda 2是由本源量子开发的开源量子计算框架，它可以用于构建、运行和优化量子算法.

QPanda 2作为本源量子计算系列软件的基础库，为QRunes、Qurator、量子计算服务提供核心部件。

## 持续化集成状态
| Linux                | Windows and MacOS|
|-------------------------|------------------|
[![Build Status](https://travis-ci.org/OriginQ/QPanda-2.svg?branch=master)](https://travis-ci.org/OriginQ/QPanda-2)        |    [![Build Status](https://dev.azure.com/yekongxiaogang/QPanda2/_apis/build/status/OriginQ.QPanda-2?branchName=master)](https://dev.azure.com/yekongxiaogang/QPanda2/_build/latest?definitionId=4&branchName=master)   

| C++ 文档         | Python 文档 |
|-------------------------|-----------------|
 | [![Documentation Status](https://readthedocs.org/projects/qpanda-toturial/badge/?version=latest)](https://qpanda-toturial.readthedocs.io/zh/latest/?badge=latest)      | [![Documentation Status](https://readthedocs.org/projects/pyqpanda-toturial/badge/?version=latest)](https://pyqpanda-toturial.readthedocs.io/zh/latest/?badge=latest)    

## 安装
### Python 3.5-3.7
通过pip进行安装：

    pip install pyqpanda
    
### Python 其他版本和C++

如果要使用Python 3的其他版本，或者直接通过C++ API进行量子编程，可直接从源码进行编译,内容参见[使用文档](https://qpanda-toturial.readthedocs.io/zh/latest/)。使用C++进行量子编程也可从[Release](https://github.com/OriginQ/QPanda-2/releases)中获取对应操作系统环境的QPanda库文件压缩包，请参见[QPanda库使用示例](https://github.com/OriginQ/QPanda-Example)。

### 验证安装
下面的例子可以在量子计算机中构建量子纠缠态(|00>+|11>)，对其进行测量，重复制备1000次。预期的结果是约有50%的概率使测量结果分别在00或11上。

    from pyqpanda import *

    init(QMachineType.CPU)
    prog = QProg()
    q = qAlloc_many(2)
    c = cAlloc_many(2)
    prog.insert(H(q[0]))
    prog.insert(CNOT(q[0],q[1]))
    prog.insert(measure_all(q,c))
    result = run_with_configuration(prog, cbit_list = c, shots = 1000)
    print(result)
    finalize()

观察到如下结果说明您已经成功安装QPanda（安装失败请参阅[FAQ](https://pyqpanda-toturial.readthedocs.io/zh/latest/)，或在issue中提出）。
    
    {'00': 493, '11': 507}
    
更多的例子请参见[使用示例](https://github.com/OriginQ/QPanda-Example)。

## 相关资料

 - [本源量子官网](http://originqc.com.cn/)
 - [本源量子云平台](http://www.qubitonline.cn/)
 - [本源量子教育](https://learn-quantum.com/EDU/index.html)
 - [ReadTheDocs文档(C++)](https://qpanda-toturial.readthedocs.io/zh/latest/)
 - [ReadTheDocs文档(Python)](https://pyqpanda-toturial.readthedocs.io/zh/latest/)
 - [QRunes量子语言](https://qrunes-tutorial.readthedocs.io/en/latest/)
 - [Qurator-VSCode](https://qurator-vscode.readthedocs.io/zh_CN/latest/)

 ## 贡献代码

我们欢迎新的成员加入到QPanda的事业中，[CONTRIBUTING](https://github.com/OriginQ/QPanda-2/blob/master/CONTRIBUTING.md)会指导您如何加入到我们的Developer大家庭。

[Github issue](https://github.com/OriginQ/QPanda-2/issues)专门用于处理请求和Bug，如果您想讨论更专业的技术问题请移步到我们QQ群：905550304，或者登陆我们的[量子社区](https://qcode.qubitonline.cn/qcode/forumtopic/community.html?belonged=1)。

## 团队介绍

QPanda由本源量子开发，本源量子致力于量子计算机的研发与应用，已推出6-qubit超导量子芯片（KF C6-130）、2-qubit半导量子芯片（XW B2-100），团队的目标是在近年制造出更多量子比特的芯片，提供公开云服务，实现量子优势与量子应用。软件团队为硬件提供支撑，除QPanda外还开发了QRunes量子语言、Qurator量子软件开发插件、本源量子云计算云服务平台、本源量子教育云等产品。

## 关于

- `QCodar` 参考张昱研究组的论文 [CODAR: A Contextual Duration-Aware Qubit Mapping for Various NISQ Devices](https://arxiv.org/abs/2002.10915)以及开源项目[Q-CODAR ](https://github.com/S4Plus/Q-CODAR)
- `VQNet`  参考Zhao-Yun Chen, Cheng Xue, Si-Ming Chen, Guo-Ping Guo的论文[VQNet: Library for a Quantum-Classical Hybrid Neural Network](https://arxiv.org/abs/1901.09133)
- `PartialAmplitudeQVM` 参考Zhao-Yun Chen, Qi Zhou, Cheng Xue, Xia Yang, Guang-Can Guo, Guo-Ping Guo的论文[64-Qubit Quantum Circuit Simulation](https://arxiv.org/abs/1802.06952)

 ## License
 Apache License 2.0

 Copyright (c) 2017-2019 By Origin Quantum Computing. All Right Reserved.
