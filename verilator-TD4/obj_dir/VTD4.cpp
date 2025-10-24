// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTD4__pch.h"

//============================================================
// Constructors

VTD4::VTD4(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTD4__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset_n{vlSymsp->TOP.reset_n}
    , in_port{vlSymsp->TOP.in_port}
    , pc_out{vlSymsp->TOP.pc_out}
    , op{vlSymsp->TOP.op}
    , out_port{vlSymsp->TOP.out_port}
    , alu_data{vlSymsp->TOP.alu_data}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VTD4::VTD4(const char* _vcname__)
    : VTD4(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTD4::~VTD4() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTD4___024root___eval_debug_assertions(VTD4___024root* vlSelf);
#endif  // VL_DEBUG
void VTD4___024root___eval_static(VTD4___024root* vlSelf);
void VTD4___024root___eval_initial(VTD4___024root* vlSelf);
void VTD4___024root___eval_settle(VTD4___024root* vlSelf);
void VTD4___024root___eval(VTD4___024root* vlSelf);

void VTD4::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTD4::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTD4___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTD4___024root___eval_static(&(vlSymsp->TOP));
        VTD4___024root___eval_initial(&(vlSymsp->TOP));
        VTD4___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTD4___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTD4::eventsPending() { return false; }

uint64_t VTD4::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTD4::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTD4___024root___eval_final(VTD4___024root* vlSelf);

VL_ATTR_COLD void VTD4::final() {
    VTD4___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTD4::hierName() const { return vlSymsp->name(); }
const char* VTD4::modelName() const { return "VTD4"; }
unsigned VTD4::threads() const { return 1; }
void VTD4::prepareClone() const { contextp()->prepareClone(); }
void VTD4::atClone() const {
    contextp()->threadPoolpOnClone();
}
