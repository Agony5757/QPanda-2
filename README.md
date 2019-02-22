[![Build Status](https://travis-ci.org/OriginQ/QPanda-2.svg?branch=master)](https://travis-ci.org/OriginQ/QPanda-2)

## QPanda 2


![图片: ](./Documentation/img/1.png)

QPanda 2 is an abbreviation of Quantum Programming Architecture for Nisq Device Application 2, which is a quantum software development kit used to deal with quantum circuits and experiments on various quantum computers, launched by the Origin Quantum Computing Team. It supports mainstream quantum logic gate operation and can be adapted to a variety of quantum chips, and the targeted optimization of quantum programs under different platforms.

The C++ language is used as the host language in QPanda 2, it is also supports quantum languages ​​written in QRunes or QASM. Currently, QPanda 2 supports up to 32-qubits in the local simulation. It integrates the quantum virtual machine(QVM) and encapsulates the typical quantum algorithms. Besides,in QPanda 2, quantum programs can make logical decisions where we have added the idea of ​​control flow(q-if), thus in line with the programming specifications of high-level languages.

There are three processes in QPanda 2: `initialization`, `compilation` and `running`.

![图片: ](./Documentation/img/2.png)

- **Initialization**:

The initialization allows users to design different quantum circuits to deal with the corresponding problems.

- **Compilation**:

Compilation allows users to rewrite them to run on different backends (such as simulators, quantum chips, quantum chips of different companies, and so on).

- **Running**:

That is the process of collecting results(classical information), Moreover, the results depending on the design of the problem(algorithm) to do the corresponding operation.








## Documentation
Documentation is hosted at https://qpanda-2.readthedocs.io/zh_CN/master/


## The Design Ideas of QPanda 2


The design of **QPanda 2** is forward-looking, considering that quantum computing will flourish and be widely applied in the future. So QPanda 2 did the following consideration when it was designed:

- Full series compatibility.

- Standard architecture.

- Standardized quantum machine model.

## The Project Includes：


![图片](./Documentation/img/3.png)



-   **QPanda SDK**：

The C++ is used as the host language for compiling quantum programs in QPanda 2 SDK. It enables users to connect and execute quantum programs conveniently.

-   **QRunes**：

QRunes is a set of quantum computing instructions developed by the Origin quantum team.It is similar to the assembly language in classical computer.

-   **QRunes(QASM) Generator**：

QRunes Generator is a C + + library that supports generating QRunes(QASM) directives in function calls.

-   **[QPanda Documentation](./Documentation/README.md)**：


The QPanda 2 documentation is detailed documentation for the user. It includes algorithm summary, corresponding quantum circuits, and QPanda 2 code. Aiming at guiding users to use QPanda 2 correctly and quickly.

![图片](./Documentation/img/4.png)


## Installation and configuration

-   **[Click for detailed！](./Documentation/Doc/3.Installation_en.md)**：

 ## License
 Apache License 2.0


 Copyright (c) 2017-2018 By Origin Quantum Computing. All Right Reserved.
