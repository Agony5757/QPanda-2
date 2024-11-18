/*
Copyright (c) 2017-2023 Origin Quantum Computing. All Right Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Core/Utilities/Tools/Utils.h"
#include "QAlg/DJ_Algorithm/DJ_Algorithm.h"
#include "QPandaNamespace.h"
#include "Core/Core.h"
#include <vector>

using namespace std;
USING_QPANDA

void diagonal_test()
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
	auto qvec = qAllocMany(10);
	auto cvec = cAllocMany(10);
	std::vector<std::complex<double>> elements(1024, 1.0);
	auto prog = QProg();
	prog << Diagonal(qvec, elements);
	prog << MeasureAll(qvec, cvec);
	auto result = qvm ->directlyRun(prog);

	destroyQuantumMachine(qvm);
}

int main()
{ 
	diagonal_test();

	return 0;
}
