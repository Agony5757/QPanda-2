#include "QuantumMetadata.h"
#include <algorithm>
#include <string>
#include "Core/Utilities/TranformQGateTypeStringAndEnum.h"
#include <XMLConfigParam.h>


using namespace std;

USING_QPANDA
const size_t _G_qubit_count = 4;
vector<vector<int>> _G_qubitMatrix = { {0,1,1,0},
                                       {1,0,0,1},
                                       {1,0,0,1},
                                       {0,1,1,0} };

QuantumMetadata::QuantumMetadata(const string &filename)
{

    if (m_config.loadFile(filename.c_str()))
    {
        m_is_config_exist = true;
    }
    else
    {
        m_is_config_exist = false;
    }
}


bool QuantumMetadata::getMetadata(int &qubit_num, std::vector<std::vector<int> > &matrix)
{
    if (!m_is_config_exist)
    {
        qubit_num = _G_qubit_count;
        matrix = _G_qubitMatrix;
    }
    else
    {
        return m_config.getMetadataConfig(qubit_num, matrix);
    }
    return true;
}

bool QuantumMetadata::getQGate(std::vector<string> &single_gates, std::vector<string> double_gates)
{
    if (!m_is_config_exist)
    {
        single_gates.push_back("RX");
        single_gates.push_back("RY");
        single_gates.push_back("RZ");
        single_gates.push_back("X1");
        single_gates.push_back("H");
        single_gates.push_back("S");

        double_gates.push_back("CNOT");
        double_gates.push_back("CZ");
        double_gates.push_back("ISWAP");
    }
    else
    {
        return m_config.getQGateConfig(single_gates, double_gates);
    }

    return true;
}

bool QuantumMetadata::getGateTime(std::map<GateType, size_t> &gate_time_map)
{
    if (!m_is_config_exist)
    {
        insertGateTimeMap({"RX", 2}, gate_time_map);
        insertGateTimeMap({"RY", 2}, gate_time_map);
        insertGateTimeMap({"RZ", 2}, gate_time_map);
        insertGateTimeMap({"X1", 2}, gate_time_map);
        insertGateTimeMap({"H", 2}, gate_time_map);
        insertGateTimeMap({"S", 2}, gate_time_map);

        insertGateTimeMap({"CNOT", 5}, gate_time_map);
        insertGateTimeMap({"CZ", 5}, gate_time_map);
        insertGateTimeMap({"ISWAP", 5}, gate_time_map);
    }
    else
    {
        return m_config.getQGateTimeConfig(gate_time_map);
    }
    return true;
}

void QuantumMetadata::insertGateTimeMap(const pair<string, size_t> &gate_time, map<GateType, size_t> &gate_time_map)
{

    pair<GateType, size_t> gate_type_time(TransformQGateType::getInstance()[gate_time.first],                                            gate_time.second);
    gate_time_map.insert(gate_type_time);

    return ;
}


QuantumMetadata::~QuantumMetadata()
{
}

