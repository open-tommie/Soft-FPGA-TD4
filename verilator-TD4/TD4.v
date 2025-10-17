//
// originally from
// https://github.com/asfdrwe/simpleTD4/blob/master/TD4.v
//
// modified for verilator 
// by tommie.jp
// Oct-12-2025
//
module TD4 (
    input wire clock, 
    input wire reset_n,
    input wire [3:0] in_port,
    output wire [3:0] pc_out, 
    output wire [7:0] op, 
    output wire [3:0] out_port, 
    output wire [3:0] alu_data);

// Copyright (c) 2020 asfdrwe (asfdrwe@gmail.com)
// SPDX-License-Identifier: MIT
  reg [3:0] reg_a, reg_b, reg_out; 
  reg [3:0] pc = 4'b0;
  reg cflag = 1'b1;
  assign out_port = reg_out;
  assign pc_out = pc;

  reg [7:0] rom[0:15];
  initial begin
    rom[4'b0000] = 8'b1011_0011; // 0000: OUT 0011
    rom[4'b0001] = 8'b1011_0110; // 0001: OUT 0110
    rom[4'b0010] = 8'b1011_1100; // 0010: OUT 1100
    rom[4'b0011] = 8'b1011_1000; // 0011: OUT 1000
    rom[4'b0100] = 8'b1011_1000; // 0100: OUT 1000
    rom[4'b0101] = 8'b1011_1100; // 0101: OUT 1100
    rom[4'b0110] = 8'b1011_0110; // 0110: OUT 0110
    rom[4'b0111] = 8'b1011_0011; // 0111: OUT 0011
    rom[4'b1000] = 8'b1011_0001; // 1000: OUT 0001
    rom[4'b1001] = 8'b1111_0000; // 1001: JMP 0000
    rom[4'b1010] = 8'b0000_0000; // 1010: NOP
    rom[4'b1011] = 8'b0000_0000; // 1011: NOP
    rom[4'b1100] = 8'b0000_0000; // 1100: NOP
    rom[4'b1101] = 8'b0000_0000; // 1101: NOP
    rom[4'b1110] = 8'b0000_0000; // 1110: NOP
    rom[4'b1111] = 8'b0000_0000; // 1111: NOP

    $monitor("monitor: time=%03t, clock=%b, pc=%02hH %bB, rom[pc]=%02hH %bB, in_port=%02hH, pc_out=%02hH %b, op=%02h %b, out_port=%02hH %b, alu_data=%02hH %b",
             $time, clock, pc, pc, rom[pc], rom[pc], 
             in_port, pc_out, pc_out, op, op, out_port, out_port, alu_data, alu_data);
    // , reg_a=%02hH, reg_b=%02hH, reg_out=%02hH, cflag=%b", 
    //          reg_a, reg_b, reg_out, cflag);

  end   

  wire [7:0] opcode;
  assign opcode = rom[pc];
  assign op = opcode;

  wire [1:0] alu_sel, load_sel;
  wire jmp;
  wire [3:0] im; // IMMEDIATE 
  assign alu_sel = (opcode[7:6] == 2'b11) ? 2'b11 : opcode[5:4];
  assign load_sel = opcode[7:6];
  assign jmp = opcode[4];
  assign im = opcode[3:0];

  wire [3:0] alu_in;
  assign alu_in = (alu_sel == 2'b00) ? reg_a : // from A
                  (alu_sel == 2'b01) ? reg_b : // from B
                  (alu_sel == 2'b10) ? in_port : // from input port
                                       4'b0000; // zero
  
  wire [3:0] alu_out;
  wire nextcflag;
  assign {nextcflag, alu_out} = alu_in + im;
  assign alu_data = alu_out;

  wire load_a, load_b, load_out, load_pc;
  assign load_a = (load_sel == 2'b00) ? 1'b0 : 1'b1; // negative logic
  assign load_b = (load_sel == 2'b01) ? 1'b0 : 1'b1; // negative logic
  assign load_out = (load_sel == 2'b10) ? 1'b0 : 1'b1; // negative logic
  assign load_pc = (load_sel == 2'b11 && (jmp == 1'b1 || cflag)) ? 1'b0 : 1'b1; // negative logic

  wire [3:0] next_pc;
  assign next_pc = (load_pc == 1'b0) ? alu_out : pc + 1;

  always @(posedge clock or negedge reset_n) begin
    // $display("display: time=%03t clock=%b reset_n=%b pc=%02HH %bB opcode=%02HH %bB reg_a=%02HH reg_b=%02HH reg_out=%02HH cflag=%b", 
            //  $time, clock, reset_n, pc, pc, opcode, opcode, reg_a, reg_b, reg_out, cflag);  
    if (!reset_n) begin
      reg_a <= 4'b0;
      reg_b <= 4'b0;
      reg_out <= 4'b0;
      cflag <= 1'b1;
      pc <= 4'b0;
    end else begin
      reg_a <= #1 (load_a == 1'b0) ? alu_out : reg_a;
      reg_b <= #1 (load_b == 1'b0) ? alu_out : reg_b;
      reg_out <= #1 (load_out == 1'b0) ? alu_out : reg_out;
      cflag  <= #1 ~nextcflag; // negative logic carry 
      pc <= #1 next_pc;
    end
  end
endmodule
