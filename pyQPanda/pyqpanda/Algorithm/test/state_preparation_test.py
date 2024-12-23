'''
State Preparation Test\n
Copyright (C) Origin Quantum 2017-2018\n
Licensed Under Apache Licence 2.0
'''

from pyqpanda import *
from pyqpanda.utils import *
from .test_utils import test_begin_str, test_end_str

def entanglement_test():
    """
    Execute a test to verify the entanglement of a two-qubit state using the pyQPanda quantum computing framework.
    
    This function initializes a quantum environment, allocates qubits and classical bits, constructs a quantum circuit
    with Hadamard gates, a controlled-Z gate, and a measurement, and then runs the circuit with a specified number of shots.
    It prints the number of shots and the results of the measurement, and finally finalizes the environment.
    
        Args:
            None
    
        Returns:
            None
    
        Raises:
            Any exceptions raised by the pyQPanda API during the execution of the quantum circuit.
    
        Note:
            This function is designed to be used within the pyQPanda package and relies on the internal API for quantum
            circuit simulation and execution.
    """
    print(test_begin_str('Entanglement Test'))
    # init the environment
    init()

    # allocate qubit/cbit
    q_list=qAlloc_many(20)
    c_list=cAlloc_many(20)

    # Create empty program
    qprog=QProg()

    # insert gates
    qprog.insert(single_gate_apply_to_all(H,q_list)) \
        .insert(CZ(q_list[1],q_list[0])) \
        .insert(H(q_list[1])) \
        .insert(meas_all(q_list[0:2],c_list[0:2]))
    
    shots_num=1000
    result=run_with_configuration(program=qprog,shots=shots_num,cbit_list=c_list[0:2])
  
    print("Shots:",shots_num,"Results:",result)
    # finalize
    finalize()

    print(test_end_str('Entanglement Test'))

def qif_test():
    """
    Executes a Q-If test within the pyQPanda framework, simulating quantum computing operations using a circuit
    simulator. The test initializes the environment, allocates resources, constructs a quantum circuit with
    conditional statements, runs the circuit for a specified number of shots, and then finalizes the
    environment.

    The function performs the following steps:
    - Prints the beginning of the Q-If test.
    - Initializes the simulation environment.
    - Allocates quantum and classical bits.
    - Sets up the true and false branches for the conditional quantum operation.
    - Constructs the quantum circuit with the conditional operation and measures the outcomes.
    - Runs the circuit for a predefined number of shots.
    - Prints the number of shots and the results.
    - Finalizes the simulation environment.
    - Prints the end of the Q-If test.

    This function is designed to be run on a quantum circuit simulator or quantum cloud service within the
    pyQPanda package.
    """
    print(test_begin_str('Q-If Test'))
    
    #init the environment
    init()

    #allocate resources
    q=qAlloc_many(10)
    c=cAlloc_many(10)
    
    #set the true branch and false branch
    #ready for qif
    true_branch=X(q[2])
    false_branch=X(q[1])

    qprog=QProg().insert(H(q[0])) \
        .insert(Measure(q[0],c[0])) \
        .insert(CreateIfProg(bind_a_cbit(c[0]),true_branch,false_branch)) \
        .insert(meas_all(q[1:3],c[1:3]))

    shots_num=1000
    result=run_with_configuration(program=qprog,shots=shots_num,cbit_list=c[0:3])
  
    print("Shots:",shots_num,"Results:",result)
    # finalize
    finalize()

    print(test_end_str('Q-If Test'))


def full_test():
    """
    Execute a suite of tests within the state preparation module of the pyQPanda package.
    
    This function sequentially runs all available tests in the `test_list`, which includes
    various quantum circuit simulation tests. It is designed to validate the correctness
    of state preparation functionalities within the quantum computing framework.

    The tests are executed in order, and upon completion of each test, the function prints
    a progress update indicating the number of tests passed out of the total number of tests.
    
        Args:
            None

        Returns:
            None
    """
    test_list=[entanglement_test, qif_test]

    for i in range(len(test_list)):
        test_list[i]()
        print('State_preparation test: %d/%d pass' % (i+1,len(test_list)))
        print(" ")