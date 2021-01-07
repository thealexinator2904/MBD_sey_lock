#ifndef __c3_keypad_DONE_h__
#define __c3_keypad_DONE_h__

/* Type Definitions */
#ifndef typedef_SFc3_keypad_DONEInstanceStruct
#define typedef_SFc3_keypad_DONEInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c3_JITStateAnimation[16];
  uint8_T c3_JITTransitionAnimation[25];
  boolean_T c3_dataWrittenToVector[16];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  int8_T (*c3_my_new_pass_address)[6];
  int32_T c3__index_pass;
  boolean_T c3_dsmdiag_my_new_pass;
  void *c3_fEmlrtCtx;
  int32_T *c3_sfEvent;
  boolean_T *c3_doneDoubleBufferReInit;
  uint8_T *c3_is_active_c3_keypad_DONE;
  uint8_T *c3_is_c3_keypad_DONE;
  uint8_T *c3_key_in;
  uint8_T *c3_locked;
  uint8_T *c3_unlocked;
  uint8_T *c3_cnt;
  uint8_T *c3_index;
  int8_T (*c3_correct_password)[6];
  real_T (*c3_password_in)[6];
  uint8_T *c3_state;
  int8_T *c3_key_dec;
  int8_T *c3_confirm_key;
  int8_T *c3_exit_key;
  uint8_T *c3_cnt_test;
  uint8_T *c3_zero;
  boolean_T *c3_red_led;
  boolean_T *c3_blue_led;
  real_T *c3_cnt_blink;
  int8_T (*c3_new_password_in)[6];
  int8_T (*c3_new_password_out)[6];
  uint32_T *c3_Voltage_in_V;
  uint16_T *c3_temporalCounter_i1;
  uint32_T *c3_presentTicks;
  uint32_T *c3_elapsedTicks;
  uint32_T *c3_previousTicks;
  uint8_T *c3_key_in_prev;
  uint8_T *c3_key_in_start;
} SFc3_keypad_DONEInstanceStruct;

#endif                                 /*typedef_SFc3_keypad_DONEInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_keypad_DONE_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_keypad_DONE_get_check_sum(mxArray *plhs[]);
extern void c3_keypad_DONE_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
