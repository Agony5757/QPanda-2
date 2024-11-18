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

void print_result(const std::map<string, bool> &result)
{
	for (auto &item : result) {
		cout << item.first << " : " << item.second << endl;
	}
}
void print_qstate(QStat& qstate)
{
	for (size_t i = 0; i < qstate.size(); i++) {
		cout << "q" << i << " : " << qstate[i] << endl;
	}
}

void diagonal_test()
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
	auto qvec = qAllocMany(2);
	auto cvec = cAllocMany(2);
	std::vector<std::complex<double>> elements(4, 1.0);
	elements[0] = -1;
	auto prog = QProg();
	prog << H(qvec[0]);
	prog << H(qvec[1]);
	prog << Diagonal(qvec, elements);

	//prog << H(qvec[1]);
	// prog << MeasureAll(qvec, cvec);
	std::map<string, bool> result = qvm ->directlyRun(prog);



	{
		QStat qstate = qvm->getQState();
		print_qstate(qstate);
	}

	destroyQuantumMachine(qvm);

	print_result(result);
}

int main()
{ 
	diagonal_test();

	return 0;
}
