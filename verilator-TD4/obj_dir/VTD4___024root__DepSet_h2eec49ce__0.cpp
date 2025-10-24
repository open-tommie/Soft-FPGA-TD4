// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTD4.h for the primary calling header

#include "VTD4__pch.h"
#include "VTD4___024root.h"

void VTD4___024root___ico_sequent__TOP__0(VTD4___024root* vlSelf);

void VTD4___024root___eval_ico(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_ico\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VTD4___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VTD4___024root___ico_sequent__TOP__0(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___ico_sequent__TOP__0\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.TD4__DOT__alu_in = ((0U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                   ? (IData)(vlSelfRef.TD4__DOT__reg_a)
                                   : ((1U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                       ? (IData)(vlSelfRef.TD4__DOT__reg_b)
                                       : ((2U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                           ? (IData)(vlSelfRef.in_port)
                                           : 0U)));
    vlSelfRef.alu_data = (0xfU & ((IData)(vlSelfRef.TD4__DOT__alu_in) 
                                  + (IData)(vlSelfRef.TD4__DOT__im)));
    vlSelfRef.TD4__DOT__next_pc = (0xfU & (((3U == (IData)(vlSelfRef.TD4__DOT__load_sel)) 
                                            & ((vlSelfRef.TD4__DOT__rom
                                                [vlSelfRef.TD4__DOT__pc] 
                                                >> 4U) 
                                               | (IData)(vlSelfRef.TD4__DOT__cflag)))
                                            ? (IData)(vlSelfRef.alu_data)
                                            : ((IData)(1U) 
                                               + (IData)(vlSelfRef.TD4__DOT__pc))));
}

void VTD4___024root___eval_triggers__ico(VTD4___024root* vlSelf);

bool VTD4___024root___eval_phase__ico(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_phase__ico\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VTD4___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VTD4___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VTD4___024root___eval_act(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_act\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VTD4___024root___nba_sequent__TOP__0(VTD4___024root* vlSelf);
void VTD4___024root___nba_sequent__TOP__1(VTD4___024root* vlSelf);
void VTD4___024root___nba_sequent__TOP__2(VTD4___024root* vlSelf);

void VTD4___024root___eval_nba(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_nba\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTD4___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x1fcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTD4___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTD4___024root___nba_sequent__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void VTD4___024root___nba_sequent__TOP__0(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___nba_sequent__TOP__0\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.reset_n) {
        vlSelfRef.TD4__DOT__reg_out = ((2U != (IData)(vlSelfRef.TD4__DOT__load_sel))
                                        ? (IData)(vlSelfRef.TD4__DOT__reg_out)
                                        : (IData)(vlSelfRef.alu_data));
        vlSelfRef.TD4__DOT__reg_a = ((0U != (IData)(vlSelfRef.TD4__DOT__load_sel))
                                      ? (IData)(vlSelfRef.TD4__DOT__reg_a)
                                      : (IData)(vlSelfRef.alu_data));
        vlSelfRef.TD4__DOT__reg_b = ((1U != (IData)(vlSelfRef.TD4__DOT__load_sel))
                                      ? (IData)(vlSelfRef.TD4__DOT__reg_b)
                                      : (IData)(vlSelfRef.alu_data));
    } else {
        vlSelfRef.TD4__DOT__reg_out = 0U;
        vlSelfRef.TD4__DOT__reg_a = 0U;
        vlSelfRef.TD4__DOT__reg_b = 0U;
    }
    vlSelfRef.TD4__DOT__cflag = ((1U & (~ (IData)(vlSelfRef.reset_n))) 
                                 || (1U & (~ (1U & 
                                              (((IData)(vlSelfRef.TD4__DOT__alu_in) 
                                                + (IData)(vlSelfRef.TD4__DOT__im)) 
                                               >> 4U)))));
}

VL_INLINE_OPT void VTD4___024root___nba_sequent__TOP__2(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___nba_sequent__TOP__2\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.out_port = vlSelfRef.TD4__DOT__reg_out;
    vlSelfRef.TD4__DOT__pc = ((IData)(vlSelfRef.reset_n)
                               ? (IData)(vlSelfRef.TD4__DOT__next_pc)
                               : 0U);
    vlSelfRef.pc_out = vlSelfRef.TD4__DOT__pc;
    vlSelfRef.op = vlSelfRef.TD4__DOT__rom[vlSelfRef.TD4__DOT__pc];
    vlSelfRef.TD4__DOT__im = (0xfU & vlSelfRef.TD4__DOT__rom
                              [vlSelfRef.TD4__DOT__pc]);
    vlSelfRef.TD4__DOT__load_sel = (3U & (vlSelfRef.TD4__DOT__rom
                                          [vlSelfRef.TD4__DOT__pc] 
                                          >> 6U));
    vlSelfRef.TD4__DOT__alu_sel = ((3U == (IData)(vlSelfRef.TD4__DOT__load_sel))
                                    ? 3U : (3U & (vlSelfRef.TD4__DOT__rom
                                                  [vlSelfRef.TD4__DOT__pc] 
                                                  >> 4U)));
    vlSelfRef.TD4__DOT__alu_in = ((0U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                   ? (IData)(vlSelfRef.TD4__DOT__reg_a)
                                   : ((1U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                       ? (IData)(vlSelfRef.TD4__DOT__reg_b)
                                       : ((2U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                           ? (IData)(vlSelfRef.in_port)
                                           : 0U)));
    vlSelfRef.alu_data = (0xfU & ((IData)(vlSelfRef.TD4__DOT__alu_in) 
                                  + (IData)(vlSelfRef.TD4__DOT__im)));
    vlSelfRef.TD4__DOT__next_pc = (0xfU & (((3U == (IData)(vlSelfRef.TD4__DOT__load_sel)) 
                                            & ((vlSelfRef.TD4__DOT__rom
                                                [vlSelfRef.TD4__DOT__pc] 
                                                >> 4U) 
                                               | (IData)(vlSelfRef.TD4__DOT__cflag)))
                                            ? (IData)(vlSelfRef.alu_data)
                                            : ((IData)(1U) 
                                               + (IData)(vlSelfRef.TD4__DOT__pc))));
}

void VTD4___024root___eval_triggers__act(VTD4___024root* vlSelf);

bool VTD4___024root___eval_phase__act(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_phase__act\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<9> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VTD4___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VTD4___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VTD4___024root___eval_phase__nba(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_phase__nba\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VTD4___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__ico(VTD4___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__nba(VTD4___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__act(VTD4___024root* vlSelf);
#endif  // VL_DEBUG

void VTD4___024root___eval(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VTD4___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("TD4.v", 9, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VTD4___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VTD4___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("TD4.v", 9, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VTD4___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("TD4.v", 9, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VTD4___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VTD4___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VTD4___024root___eval_debug_assertions(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_debug_assertions\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY(((vlSelfRef.reset_n & 0xfeU)))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY(((vlSelfRef.in_port & 0xf0U)))) {
        Verilated::overWidthError("in_port");}
}
#endif  // VL_DEBUG
