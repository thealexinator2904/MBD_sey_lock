/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: keypad_DONE.c
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

#include "keypad_DONE.h"
#include "keypad_DONE_private.h"

/* Block signals (default storage) */
B_keypad_DONE_T keypad_DONE_B;

/* Real-time model */
RT_MODEL_keypad_DONE_T keypad_DONE_M_;
RT_MODEL_keypad_DONE_T *const keypad_DONE_M = &keypad_DONE_M_;

/* Model step function */
void keypad_DONE_step(void)
{
  /* S-Function (keypad_sfcn): '<Root>/S-Function Builder' */
  keypad_sfcn_Outputs_wrapper( &keypad_DONE_B.SFunctionBuilder );
}

/* Model initialize function */
void keypad_DONE_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(keypad_DONE_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &keypad_DONE_B), 0,
                sizeof(B_keypad_DONE_T));
}

/* Model terminate function */
void keypad_DONE_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
