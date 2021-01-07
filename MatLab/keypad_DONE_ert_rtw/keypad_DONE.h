/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: keypad_DONE.h
 *
 * Code generated for Simulink model 'keypad_DONE'.
 *
 * Model version                  : 1.170
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Jan  6 14:10:49 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_keypad_DONE_h_
#define RTW_HEADER_keypad_DONE_h_
#include <stddef.h>
#include <string.h>
#ifndef keypad_DONE_COMMON_INCLUDES_
# define keypad_DONE_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* keypad_DONE_COMMON_INCLUDES_ */

#include "keypad_DONE_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T SFunctionBuilder;            /* '<Root>/S-Function Builder' */
} B_keypad_DONE_T;

/* Parameters (default storage) */
struct P_keypad_DONE_T_ {
  int8_T DataStoreMemory_InitialValue[6];
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_keypad_DONE_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_keypad_DONE_T keypad_DONE_P;

/* Block signals (default storage) */
extern B_keypad_DONE_T keypad_DONE_B;

/* Model entry point functions */
extern void keypad_DONE_initialize(void);
extern void keypad_DONE_step(void);
extern void keypad_DONE_terminate(void);

/* Real-time Model object */
extern RT_MODEL_keypad_DONE_T *const keypad_DONE_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'keypad_DONE'
 */
#endif                                 /* RTW_HEADER_keypad_DONE_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
