#ifndef  QPROG_TO_DAG_H_
#define  QPROG_TO_DAG_H_

#include <map>
#include "Core/Utilities/Tools/Traversal.h"
#include "Core/QuantumCircuit/QGlobalVariable.h"
#include "Core/Utilities/Tools/QPandaException.h"
#include "Core/Utilities/QProgInfo/QCircuitInfo.h"
#include "Core/Utilities/QProgTransform/QProgToDAG/QProgDAG.h"
QPANDA_BEGIN


/**
* @class QProgDAG
* @ingroup Utilities
* @brief transform QProg to DAG
* @note
*/
class QProgToDAG
{
public:

    /**
    * @brief  traversal QProg
    * @param[in]  _Ty& node
    * @param[in]  QProgDAG& prog_dag
    * @return     void
    */
    template <typename _Ty>
    void traversal(_Ty &node,QProgDAG<GateNodeInfo> & prog_dag)
    {
		NodeIter NullItr;
        QCircuitParam parm;
        execute(node.getImplementationPtr(), nullptr, prog_dag, parm, NullItr);
    }

    void execute(std::shared_ptr<AbstractQGateNode>, std::shared_ptr<QNode>,QProgDAG<GateNodeInfo> &, QCircuitParam&, NodeIter&);
    void execute(std::shared_ptr<AbstractClassicalProg>, std::shared_ptr<QNode>, QProgDAG<GateNodeInfo> &, QCircuitParam&, NodeIter&);
    void execute(std::shared_ptr<AbstractQuantumMeasure>, std::shared_ptr<QNode>,QProgDAG<GateNodeInfo> &, QCircuitParam&, NodeIter&);
	void execute(std::shared_ptr<AbstractQuantumReset>, std::shared_ptr<QNode>, QProgDAG<GateNodeInfo> &, QCircuitParam&, NodeIter&);
    void execute(std::shared_ptr<AbstractQuantumCircuit>, std::shared_ptr<QNode>, QProgDAG<GateNodeInfo> &, QCircuitParam&, NodeIter&);
    void execute(std::shared_ptr<AbstractQuantumProgram>, std::shared_ptr<QNode>, QProgDAG<GateNodeInfo> &, QCircuitParam&, NodeIter&);
    void execute(std::shared_ptr<AbstractControlFlowNode>, std::shared_ptr<QNode>, QProgDAG<GateNodeInfo> &, QCircuitParam&, NodeIter&);

protected:
    void transformQGate(std::shared_ptr<AbstractQGateNode>, QProgDAG<GateNodeInfo> &,const QCircuitParam&, NodeIter&);
    void transformQMeasure(std::shared_ptr<AbstractQuantumMeasure>, QProgDAG<GateNodeInfo> &, NodeIter&);
	void transformQReset(std::shared_ptr<AbstractQuantumReset> cur_node, QProgDAG<GateNodeInfo> &prog_dag, NodeIter& cur_iter);
};

QPANDA_END


#endif
