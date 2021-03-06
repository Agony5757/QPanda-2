from pyqpanda import *
import time
PI = 3.1415926535898


def utilities_fun():

    machine = init_quantum_machine(QMachineType.CPU)

    prog = QProg()
    q = machine.qAlloc_many(6)
    c = machine.cAlloc_many(6)

    prog.insert(H(q[0]))\
        .insert(Y(q[5]))\
        .insert(S(q[2]))\
        .insert(CZ(q[0], q[1]))

    print(to_QRunes(prog, machine))
    print(to_QASM(prog, machine))
    print(to_Quil(prog, machine))
    print(count_gate(prog, machine))
    print(get_clock_cycle(machine, prog))
    print(get_bin_str(prog, machine))

    machine.finalize()


def QCloud_fun():

    QCM = QCloud()
    QCM.initQVM()

    qlist = QCM.qAlloc_many(10)
    clist = QCM.qAlloc_many(10)
    prog = QProg()
    for i in qlist:
        prog.insert(H(i))

    prog.insert(CZ(qlist[1], qlist[5]))\
        .insert(CZ(qlist[3], qlist[7]))\
        .insert(CZ(qlist[0], qlist[4]))\
        .insert(RZ(qlist[7], PI / 4))\
        .insert(RX(qlist[5], PI / 4))\
        .insert(RX(qlist[4], PI / 4))\
        .insert(RY(qlist[3], PI / 4))\
        .insert(CZ(qlist[2], qlist[6]))\
        .insert(RZ(qlist[3], PI / 4))\
        .insert(RZ(qlist[8], PI / 4))\
        .insert(CZ(qlist[9], qlist[5]))\
        .insert(RY(qlist[2], PI / 4))\
        .insert(RZ(qlist[9], PI / 4))\
        .insert(CZ(qlist[2], qlist[3]))

    param1 = {"RepeatNum": 1000, "token": "3CD107AEF1364924B9325305BF046FF3",
              "BackendType": QMachineType.CPU}
    param2 = {"token": "3CD107AEF1364924B9325305BF046FF3",
              "BackendType": QMachineType.CPU}

    task = QCM.run_with_configuration(prog, param1)
    print(task)

    time.sleep(3)
    result = QCM.get_result("1904301115021866")

    print(result)
    # print(QCM.prob_run_dict(prog,qlist,param2))

    # res = QCM.get_result("1904261648207832")
    # print(res)
    QCM.finalize()


def cpu_qvm_fun():

    machine = init_quantum_machine(QMachineType.CPU)
    machine.initQVM()

    q = machine.qAlloc_many(10)
    c = machine.cAlloc_many(10)

    prog = QProg()
    prog.insert(Hadamard_Circuit(q))\
        .insert(T(q[0]).dagger())\
        .insert(Y(q[1]))\
        .insert(RX(q[3], PI / 3))\
        .insert(RY(q[2], PI / 3))\
        .insert(CNOT(q[1], q[5]))
    # .insert(measure_all(q,c))


    print(to_QRunes(prog,machine))
    machine.finalize()


def singleAmp_fun():

    machine = SingleAmpQVM()

    machine.initQVM()

    q = machine.qAlloc_many(10)
    c = machine.cAlloc_many(10)

    prog = QProg()

    prog.insert(Hadamard_Circuit(q))\
        .insert(CZ(q[1], q[5]))\
        .insert(CZ(q[3], q[5]))\
        .insert(CZ(q[2], q[4]))\
        .insert(CZ(q[3], q[7]))\
        .insert(CZ(q[0], q[4]))\
        .insert(RY(q[7], PI / 2))\
        .insert(RX(q[8], PI / 2))\
        .insert(RX(q[9], PI / 2))\
        .insert(CR(q[0], q[1], PI))\
        .insert(CR(q[2], q[3], PI))\
        .insert(RY(q[4], PI / 2))\
        .insert(RZ(q[5], PI / 4))\
        .insert(RX(q[6], PI / 2))\
        .insert(RZ(q[7], PI / 4))\
        .insert(CR(q[8], q[9], PI))\
        .insert(CR(q[1], q[2], PI))\
        .insert(RY(q[3], PI / 2))\
        .insert(RX(q[4], PI / 2))\
        .insert(RX(q[5], PI / 2))\
        .insert(CR(q[9], q[1], PI))\
        .insert(RY(q[1], PI / 2))\
        .insert(RY(q[2], PI / 2))\
        .insert(RZ(q[3], PI / 4))\
        .insert(CR(q[7], q[8], PI))

    machine.run(prog)

    result = machine.pmeasure_index(1)
    print(result)

def partialAmp_fun():

    machine = PartialAmpQVM()

    machine.initQVM()

    q = machine.qAlloc_many(10)
    c = machine.cAlloc_many(10)

    prog = QProg()

    prog.insert(Hadamard_Circuit(q))\
        .insert(CZ(q[1], q[5]))\
        .insert(CZ(q[3], q[7]))\
        .insert(CZ(q[0], q[4]))\
        .insert(RZ(q[7], PI / 4))\
        .insert(RX(q[5], PI / 4))\
        .insert(RX(q[4], PI / 4))\
        .insert(RY(q[3], PI / 4))\
        .insert(CZ(q[2], q[6]))\
        .insert(RZ(q[3], PI / 4))\
        .insert(RZ(q[8], PI / 4))\
        .insert(CZ(q[9], q[5]))\
        .insert(RY(q[2], PI / 4))\
        .insert(RZ(q[9], PI / 4))\
        .insert(CZ(q[2], q[3]))

    machine.run(prog)

    result = machine.get_prob_tuple_list(q, 6)
    print(result)

if __name__ == "__main__":

    cpu_qvm_fun()
    # singleAmp_fun()
    # partialAmp_fun()
    # QCloud_fun()
