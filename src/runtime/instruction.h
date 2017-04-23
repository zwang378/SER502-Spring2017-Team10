/**
 * @file instruction.h
 * @brief Purpose: declaration of the machine instruction.
 * @version 0.5
 * @date 04.23.2017
 * @author Xiangyu Guo
 */
#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

typedef struct label_table label_table_st;
struct label_table;

typedef struct instruction instruction_st;
struct instruction;

typedef struct instruction_set instruction_set_st;
struct instruction_set;

/**
 * @brief load an ASM program into the runtime.
 * @param file_path path of asm file.
 * @return instruct_set loaded instruction sequence.
 */
instruction_set_st *instruction_load_program(const char *);

/**
 * @brief get next instruction from instruction set
 * @param instruction_set a valid instruction_set object.
 * @return NULL, failed or no more instructions; otherwise a pointer to the instruction.
 */
instruction_st *instruction_set_get_instruction(instruction_set_st *);

/**
 * @brief set a new program counter
 * @param instruction_set a valid instruction_set object.
 * @param new_pc new program counter address.
 */
void instruction_set_set_pc(instruction_set_st *, int);

/**
 * @brief get the comparision result
 * @param instruction_set a valid instruction_set object.
 * @return flag value.
 */
int instruction_set_get_flag(instruction_set_st *);

/**
 * @brief set a new comparision result
 * @param instruction_set a valid instruction_set object.
 * @param new_flag new flag value.
 */
void instruction_set_set_flag(instruction_set_st *, int);

/**
 * @brief get operation code from an instruction.
 * @param instruction, a valid instruction object.
 * @return op_code, operation code
 */
char *instruction_get_op_code(instruction_st *);

/**
 * @brief get operation code from an instruction.
 * @param instruction, a valid instruction object.
 * @return operand, first operand
 */
char *instruction_get_op_first(instruction_st *);

/**
 * @brief get operation code from an instruction.
 * @param instruction, a valid instruction object.
 * @return operand, second operand
 */
char *instruction_get_op_second(instruction_st *);

#endif