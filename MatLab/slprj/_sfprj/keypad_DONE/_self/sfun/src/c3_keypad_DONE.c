/* Include files */

#include "keypad_DONE_sfun.h"
#include "c3_keypad_DONE.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_BLINK_RED1               ((uint8_T)1U)
#define c3_IN_BLINK_RED2               ((uint8_T)2U)
#define c3_IN_BLOCKING                 ((uint8_T)3U)
#define c3_IN_BLOCKING_BLINK           ((uint8_T)4U)
#define c3_IN_CHECK_CONFIRMATION       ((uint8_T)5U)
#define c3_IN_CHECK_SEQ                ((uint8_T)6U)
#define c3_IN_CONVERT                  ((uint8_T)7U)
#define c3_IN_DEFAULT_VAL              ((uint8_T)8U)
#define c3_IN_IDLE                     ((uint8_T)9U)
#define c3_IN_INIT                     ((uint8_T)10U)
#define c3_IN_INPUT_HANDLING           ((uint8_T)11U)
#define c3_IN_LOW_BAT                  ((uint8_T)12U)
#define c3_IN_RIGHT_SEQ                ((uint8_T)13U)
#define c3_IN_SET_NEW_PASS1            ((uint8_T)14U)
#define c3_IN_SET_NEW_PASS2            ((uint8_T)15U)
#define c3_IN_WRONG_SEQ                ((uint8_T)16U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance);
static void initialize_params_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance);
static void enable_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void disable_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void c3_update_jit_animation_state_c3_keypad_DONE
  (SFc3_keypad_DONEInstanceStruct *chartInstance);
static void c3_do_animation_call_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_keypad_DONE
  (SFc3_keypad_DONEInstanceStruct *chartInstance);
static void set_sim_state_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_keypad_DONE
  (SFc3_keypad_DONEInstanceStruct *chartInstance);
static void finalize_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance);
static void sf_gateway_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance);
static void mdl_start_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance);
static void c3_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void initSimStructsc3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance);
static void c3_enter_atomic_INIT(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void c3_CONVERT(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void c3_CHECK_SEQ(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void c3_BLINK_RED2(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void c3_BLOCKING(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void c3_BLOCKING_BLINK(SFc3_keypad_DONEInstanceStruct *chartInstance);
static boolean_T c3_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_blue_led, const char_T *c3_identifier);
static boolean_T c3_b_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint8_T c3_c_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_cnt_test, const char_T *c3_identifier);
static uint8_T c3_d_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_b_new_password_out, const char_T *c3_identifier, int8_T
  c3_y[6]);
static void c3_f_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, int8_T c3_y[6]);
static real_T c3_g_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_cnt_blink, const char_T *c3_identifier);
static real_T c3_h_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static int8_T c3_i_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_confirm_key, const char_T *c3_identifier);
static int8_T c3_j_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_k_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_b_password_in, const char_T *c3_identifier, real_T c3_y[6]);
static void c3_l_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static uint16_T c3_m_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_temporalCounter_i1, const char_T
  *c3_identifier);
static uint16_T c3_n_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint32_T c3_o_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_previousTicks, const char_T *c3_identifier);
static uint32_T c3_p_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_q_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[16]);
static void c3_r_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[16]);
static const mxArray *c3_s_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_t_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static int8_T c3_get_my_new_pass(SFc3_keypad_DONEInstanceStruct *chartInstance,
  uint32_T c3_elementIndex);
static void c3_set_my_new_pass(SFc3_keypad_DONEInstanceStruct *chartInstance,
  uint32_T c3_elementIndex, int8_T c3_elementValue);
static int8_T *c3_access_my_new_pass(SFc3_keypad_DONEInstanceStruct
  *chartInstance, uint32_T c3_rdOnly);
static void init_dsm_address_info(SFc3_keypad_DONEInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_keypad_DONEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  int32_T c3_i;
  emlrtLicenseCheckR2012b(chartInstance->c3_fEmlrtCtx, "Fixed_Point_Toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  *chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_is_active_c3_keypad_DONE = 0U;
  *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_doneDoubleBufferReInit = false;
  *chartInstance->c3_presentTicks = 0U;
  *chartInstance->c3_elapsedTicks = 0U;
  *chartInstance->c3_previousTicks = 0U;
  *chartInstance->c3_is_active_c3_keypad_DONE = 1U;
  chartInstance->c3_JITTransitionAnimation[0U] = 1U;
  sf_force_animation_for_chart_exec_at_init(chartInstance->S);
  *chartInstance->c3_is_c3_keypad_DONE = c3_IN_DEFAULT_VAL;
  for (c3_i = 0; c3_i < 6; c3_i++) {
    (*chartInstance->c3_new_password_out)[c3_i] = 1;
  }

  chartInstance->c3_dataWrittenToVector[15U] = true;
  *chartInstance->c3_state = 15U;
  chartInstance->c3_dataWrittenToVector[6U] = true;
}

static void initialize_params_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  *chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor((_sfTime_ -
    sf_get_start_time(chartInstance->S)) / 0.01 + 0.5);
  *chartInstance->c3_previousTicks = *chartInstance->c3_presentTicks;
}

static void disable_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  *chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor((_sfTime_ -
    sf_get_start_time(chartInstance->S)) / 0.01 + 0.5);
  *chartInstance->c3_elapsedTicks = *chartInstance->c3_presentTicks -
    *chartInstance->c3_previousTicks;
  *chartInstance->c3_previousTicks = *chartInstance->c3_presentTicks;
  if ((uint32_T)*chartInstance->c3_temporalCounter_i1 +
      *chartInstance->c3_elapsedTicks <= 2047U) {
    *chartInstance->c3_temporalCounter_i1 = (uint16_T)((uint32_T)
      *chartInstance->c3_temporalCounter_i1 + *chartInstance->c3_elapsedTicks);
  } else {
    *chartInstance->c3_temporalCounter_i1 = 2047U;
  }
}

static void c3_update_jit_animation_state_c3_keypad_DONE
  (SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  chartInstance->c3_JITStateAnimation[0U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_INIT);
  chartInstance->c3_JITStateAnimation[1U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_CONVERT);
  chartInstance->c3_JITStateAnimation[2U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_INPUT_HANDLING);
  chartInstance->c3_JITStateAnimation[3U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_WRONG_SEQ);
  chartInstance->c3_JITStateAnimation[4U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_RIGHT_SEQ);
  chartInstance->c3_JITStateAnimation[5U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_BLOCKING);
  chartInstance->c3_JITStateAnimation[6U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_IDLE);
  chartInstance->c3_JITStateAnimation[7U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_CHECK_SEQ);
  chartInstance->c3_JITStateAnimation[8U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_CHECK_CONFIRMATION);
  chartInstance->c3_JITStateAnimation[9U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_BLOCKING_BLINK);
  chartInstance->c3_JITStateAnimation[10U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_BLINK_RED1);
  chartInstance->c3_JITStateAnimation[11U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_BLINK_RED2);
  chartInstance->c3_JITStateAnimation[12U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_DEFAULT_VAL);
  chartInstance->c3_JITStateAnimation[13U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_SET_NEW_PASS1);
  chartInstance->c3_JITStateAnimation[14U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_SET_NEW_PASS2);
  chartInstance->c3_JITStateAnimation[15U] = (uint8_T)
    (*chartInstance->c3_is_c3_keypad_DONE == c3_IN_LOW_BAT);
}

static void c3_do_animation_call_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  c3_update_jit_animation_state_c3_keypad_DONE(chartInstance);
  c3_do_animation_call_c3_keypad_DONE(chartInstance);
}

static const mxArray *get_sim_state_c3_keypad_DONE
  (SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_l_y = NULL;
  const mxArray *c3_m_y = NULL;
  const mxArray *c3_n_y = NULL;
  const mxArray *c3_o_y = NULL;
  const mxArray *c3_p_y = NULL;
  const mxArray *c3_q_y = NULL;
  const mxArray *c3_r_y = NULL;
  const mxArray *c3_s_y = NULL;
  const mxArray *c3_t_y = NULL;
  const mxArray *c3_u_y = NULL;
  const mxArray *c3_v_y = NULL;
  const mxArray *c3_w_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(22, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", chartInstance->c3_blue_led, 11, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", chartInstance->c3_cnt_test, 3, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", chartInstance->c3_locked, 3, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", *chartInstance->c3_new_password_out,
    2, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", chartInstance->c3_red_led, 11, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", chartInstance->c3_state, 3, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", chartInstance->c3_unlocked, 3, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", chartInstance->c3_cnt, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", chartInstance->c3_cnt_blink, 0, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", chartInstance->c3_confirm_key, 2, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", *chartInstance->c3_correct_password,
    2, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", chartInstance->c3_exit_key, 2, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", chartInstance->c3_index, 3, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", chartInstance->c3_key_dec, 2, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", *chartInstance->c3_password_in, 0,
    0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", chartInstance->c3_zero, 3, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y",
    chartInstance->c3_is_active_c3_keypad_DONE, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", chartInstance->c3_is_c3_keypad_DONE,
    3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 17, c3_s_y);
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", chartInstance->c3_temporalCounter_i1,
    5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 18, c3_t_y);
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y", chartInstance->c3_key_in_start, 3,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 19, c3_u_y);
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", chartInstance->c3_previousTicks, 7,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 20, c3_v_y);
  c3_w_y = NULL;
  sf_mex_assign(&c3_w_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 16), false);
  sf_mex_setcell(c3_y, 21, c3_w_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  *chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_blue_led = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "blue_led");
  *chartInstance->c3_cnt_test = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "cnt_test");
  *chartInstance->c3_locked = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "locked");
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
                        "new_password_out", *chartInstance->c3_new_password_out);
  *chartInstance->c3_red_led = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "red_led");
  *chartInstance->c3_state = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "state");
  *chartInstance->c3_unlocked = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "unlocked");
  *chartInstance->c3_cnt = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "cnt");
  *chartInstance->c3_cnt_blink = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "cnt_blink");
  *chartInstance->c3_confirm_key = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 9)), "confirm_key");
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 10)),
                        "correct_password", *chartInstance->c3_correct_password);
  *chartInstance->c3_exit_key = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "exit_key");
  *chartInstance->c3_index = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 12)), "index");
  *chartInstance->c3_key_dec = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 13)), "key_dec");
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 14)),
                        "password_in", *chartInstance->c3_password_in);
  *chartInstance->c3_zero = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 15)), "zero");
  *chartInstance->c3_is_active_c3_keypad_DONE = c3_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 16)),
     "is_active_c3_keypad_DONE");
  *chartInstance->c3_is_c3_keypad_DONE = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 17)), "is_c3_keypad_DONE");
  *chartInstance->c3_temporalCounter_i1 = c3_m_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 18)), "temporalCounter_i1");
  *chartInstance->c3_key_in_start = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 19)), "key_in_start");
  *chartInstance->c3_previousTicks = c3_o_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 20)), "previousTicks");
  c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 21)),
                        "dataWrittenToVector",
                        chartInstance->c3_dataWrittenToVector);
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 22)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_jit_animation_state_c3_keypad_DONE(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_keypad_DONE
  (SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if ((*chartInstance->c3_is_c3_keypad_DONE == c3_IN_BLINK_RED1) &&
        (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                    "setSimStateSideEffectsInfo", 1, 2) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_c3_keypad_DONE == c3_IN_BLINK_RED2) &&
        (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                    "setSimStateSideEffectsInfo", 1, 3) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_c3_keypad_DONE == c3_IN_BLOCKING) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 4) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_c3_keypad_DONE == c3_IN_BLOCKING_BLINK) &&
        (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                    "setSimStateSideEffectsInfo", 1, 5) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_c3_keypad_DONE == c3_IN_LOW_BAT) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 13) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_c3_keypad_DONE == c3_IN_RIGHT_SEQ) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 14) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_c3_keypad_DONE == c3_IN_SET_NEW_PASS1) &&
        (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                    "setSimStateSideEffectsInfo", 1, 15) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_c3_keypad_DONE == c3_IN_WRONG_SEQ) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 17) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  c3_set_sim_state_side_effects_c3_keypad_DONE(chartInstance);
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
  chartInstance->c3_JITTransitionAnimation[1] = 0U;
  chartInstance->c3_JITTransitionAnimation[2] = 0U;
  chartInstance->c3_JITTransitionAnimation[3] = 0U;
  chartInstance->c3_JITTransitionAnimation[4] = 0U;
  chartInstance->c3_JITTransitionAnimation[5] = 0U;
  chartInstance->c3_JITTransitionAnimation[6] = 0U;
  chartInstance->c3_JITTransitionAnimation[7] = 0U;
  chartInstance->c3_JITTransitionAnimation[8] = 0U;
  chartInstance->c3_JITTransitionAnimation[9] = 0U;
  chartInstance->c3_JITTransitionAnimation[10] = 0U;
  chartInstance->c3_JITTransitionAnimation[11] = 0U;
  chartInstance->c3_JITTransitionAnimation[12] = 0U;
  chartInstance->c3_JITTransitionAnimation[13] = 0U;
  chartInstance->c3_JITTransitionAnimation[14] = 0U;
  chartInstance->c3_JITTransitionAnimation[15] = 0U;
  chartInstance->c3_JITTransitionAnimation[16] = 0U;
  chartInstance->c3_JITTransitionAnimation[17] = 0U;
  chartInstance->c3_JITTransitionAnimation[18] = 0U;
  chartInstance->c3_JITTransitionAnimation[19] = 0U;
  chartInstance->c3_JITTransitionAnimation[20] = 0U;
  chartInstance->c3_JITTransitionAnimation[21] = 0U;
  chartInstance->c3_JITTransitionAnimation[22] = 0U;
  chartInstance->c3_JITTransitionAnimation[23] = 0U;
  chartInstance->c3_JITTransitionAnimation[24] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  *chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor((_sfTime_ -
    sf_get_start_time(chartInstance->S)) / 0.01 + 0.5);
  *chartInstance->c3_elapsedTicks = *chartInstance->c3_presentTicks -
    *chartInstance->c3_previousTicks;
  *chartInstance->c3_previousTicks = *chartInstance->c3_presentTicks;
  if ((uint32_T)*chartInstance->c3_temporalCounter_i1 +
      *chartInstance->c3_elapsedTicks <= 2047U) {
    *chartInstance->c3_temporalCounter_i1 = (uint16_T)((uint32_T)
      *chartInstance->c3_temporalCounter_i1 + *chartInstance->c3_elapsedTicks);
  } else {
    *chartInstance->c3_temporalCounter_i1 = 2047U;
  }

  *chartInstance->c3_sfEvent = CALL_EVENT;
  *chartInstance->c3_key_in_prev = *chartInstance->c3_key_in_start;
  *chartInstance->c3_key_in_start = *chartInstance->c3_key_in;
  c3_c3_keypad_DONE(chartInstance);
  c3_update_jit_animation_state_c3_keypad_DONE(chartInstance);
  c3_do_animation_call_c3_keypad_DONE(chartInstance);
}

static void mdl_start_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  sim_mode_is_external(chartInstance->S);
}

static void c3_c3_keypad_DONE(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  boolean_T c3_guard1 = false;
  boolean_T c3_temp;
  int32_T c3_i;
  uint8_T c3_u;
  if (!*chartInstance->c3_doneDoubleBufferReInit) {
    *chartInstance->c3_doneDoubleBufferReInit = true;
    *chartInstance->c3_key_in_prev = *chartInstance->c3_key_in;
    *chartInstance->c3_key_in_start = *chartInstance->c3_key_in;
  }

  c3_guard1 = false;
  switch (*chartInstance->c3_is_c3_keypad_DONE) {
   case c3_IN_BLINK_RED1:
    if (*chartInstance->c3_temporalCounter_i1 >= 50) {
      chartInstance->c3_JITTransitionAnimation[15U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_BLINK_RED2;
      *chartInstance->c3_temporalCounter_i1 = 0U;
      if (!chartInstance->c3_dataWrittenToVector[12U]) {
        sf_read_before_write_error(chartInstance->S, 17U, 116U, 29, 7);
      }

      *chartInstance->c3_red_led = !*chartInstance->c3_red_led;
      chartInstance->c3_dataWrittenToVector[12U] = true;
    }
    break;

   case c3_IN_BLINK_RED2:
    c3_BLINK_RED2(chartInstance);
    break;

   case c3_IN_BLOCKING:
    c3_BLOCKING(chartInstance);
    break;

   case c3_IN_BLOCKING_BLINK:
    c3_BLOCKING_BLINK(chartInstance);
    break;

   case c3_IN_CHECK_CONFIRMATION:
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      sf_read_before_write_error(chartInstance->S, 3U, 97U, 1, 11);
    }

    if (*chartInstance->c3_confirm_key == -13) {
      chartInstance->c3_JITTransitionAnimation[11U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_CHECK_SEQ;
    } else {
      if (!chartInstance->c3_dataWrittenToVector[7U]) {
        sf_read_before_write_error(chartInstance->S, 7U, 93U, 75, 7);
      }

      *chartInstance->c3_confirm_key = *chartInstance->c3_key_dec;
      chartInstance->c3_dataWrittenToVector[8U] = true;
      *chartInstance->c3_state = 6U;
      chartInstance->c3_dataWrittenToVector[6U] = true;
    }
    break;

   case c3_IN_CHECK_SEQ:
    c3_CHECK_SEQ(chartInstance);
    break;

   case c3_IN_CONVERT:
    c3_CONVERT(chartInstance);
    break;

   case c3_IN_DEFAULT_VAL:
    chartInstance->c3_JITTransitionAnimation[18U] = 1U;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_INIT;
    c3_enter_atomic_INIT(chartInstance);
    break;

   case c3_IN_IDLE:
    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      sf_read_before_write_error(chartInstance->S, 9U, 58U, 24, 4);
    }

    if ((*chartInstance->c3_key_in_prev != *chartInstance->c3_key_in_start) && (*
         chartInstance->c3_key_in_prev == *chartInstance->c3_zero)) {
      chartInstance->c3_JITTransitionAnimation[9U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_CONVERT;
      c3_u = *chartInstance->c3_key_in;
      if (c3_u > 127) {
        c3_u = 127U;
        sf_data_saturate_error(chartInstance->S, 8U, 51, 12);
      }

      *chartInstance->c3_key_dec = (int8_T)(c3_u - 48);
      chartInstance->c3_dataWrittenToVector[7U] = true;
      *chartInstance->c3_state = 2U;
      chartInstance->c3_dataWrittenToVector[6U] = true;
    } else {
      if (*chartInstance->c3_Voltage_in_V < 20971520U) {
        chartInstance->c3_JITTransitionAnimation[23U] = 1U;
        *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
        *chartInstance->c3_is_c3_keypad_DONE = c3_IN_LOW_BAT;
        *chartInstance->c3_temporalCounter_i1 = 0U;
        *chartInstance->c3_state = 18U;
        chartInstance->c3_dataWrittenToVector[6U] = true;
        *chartInstance->c3_red_led = true;
        chartInstance->c3_dataWrittenToVector[12U] = true;
        *chartInstance->c3_blue_led = true;
        chartInstance->c3_dataWrittenToVector[13U] = true;
      }
    }
    break;

   case c3_IN_INIT:
    chartInstance->c3_JITTransitionAnimation[8U] = 1U;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_IDLE;
    *chartInstance->c3_state = 1U;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    *chartInstance->c3_red_led = true;
    chartInstance->c3_dataWrittenToVector[12U] = true;
    break;

   case c3_IN_INPUT_HANDLING:
    chartInstance->c3_JITTransitionAnimation[12U] = 1U;
    *chartInstance->c3_state = 3U;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_IDLE;
    *chartInstance->c3_state = 1U;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    *chartInstance->c3_red_led = true;
    chartInstance->c3_dataWrittenToVector[12U] = true;
    break;

   case c3_IN_LOW_BAT:
    if (*chartInstance->c3_temporalCounter_i1 >= 100) {
      chartInstance->c3_JITTransitionAnimation[24U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_IDLE;
      *chartInstance->c3_state = 1U;
      chartInstance->c3_dataWrittenToVector[6U] = true;
      *chartInstance->c3_red_led = true;
      chartInstance->c3_dataWrittenToVector[12U] = true;
    }
    break;

   case c3_IN_RIGHT_SEQ:
    if (*chartInstance->c3_temporalCounter_i1 >= 2000) {
      c3_guard1 = true;
    } else {
      if (!chartInstance->c3_dataWrittenToVector[9U]) {
        sf_read_before_write_error(chartInstance->S, 5U, 30U, 23, 8);
      }

      if (*chartInstance->c3_exit_key == 17) {
        c3_guard1 = true;
      } else {
        if (!chartInstance->c3_dataWrittenToVector[9U]) {
          sf_read_before_write_error(chartInstance->S, 5U, 129U, 1, 8);
        }

        if (*chartInstance->c3_exit_key == -6) {
          chartInstance->c3_JITTransitionAnimation[20U] = 1U;
          *chartInstance->c3_blue_led = false;
          chartInstance->c3_dataWrittenToVector[13U] = true;
          *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
          *chartInstance->c3_is_c3_keypad_DONE = c3_IN_SET_NEW_PASS2;
          *chartInstance->c3_exit_key = 0;
          chartInstance->c3_dataWrittenToVector[9U] = true;
        } else {
          *chartInstance->c3_blue_led = true;
          chartInstance->c3_dataWrittenToVector[13U] = true;
          *chartInstance->c3_red_led = false;
          chartInstance->c3_dataWrittenToVector[12U] = true;
          c3_u = *chartInstance->c3_key_in;
          if (c3_u > 127) {
            c3_u = 127U;
            sf_data_saturate_error(chartInstance->S, 22U, 121, 12);
          }

          *chartInstance->c3_exit_key = (int8_T)(c3_u - 48);
          chartInstance->c3_dataWrittenToVector[9U] = true;
          *chartInstance->c3_unlocked = 1U;
          chartInstance->c3_dataWrittenToVector[1U] = true;
          *chartInstance->c3_locked = 0U;
          chartInstance->c3_dataWrittenToVector[0U] = true;
          *chartInstance->c3_index = 1U;
          chartInstance->c3_dataWrittenToVector[3U] = true;
          *chartInstance->c3_state = 9U;
          chartInstance->c3_dataWrittenToVector[6U] = true;
        }
      }
    }
    break;

   case c3_IN_SET_NEW_PASS1:
    if (*chartInstance->c3_temporalCounter_i1 >= 10) {
      chartInstance->c3_JITTransitionAnimation[21U] = 1U;
      if (!chartInstance->c3_dataWrittenToVector[3U]) {
        sf_read_before_write_error(chartInstance->S, 6U, 127U, 137, 5);
      }

      c3_i = (int32_T)((uint32_T)*chartInstance->c3_index + 1U);
      if ((uint32_T)c3_i > 255U) {
        c3_i = 255;
        sf_data_saturate_error(chartInstance->S, 127U, 137, 7);
      }

      *chartInstance->c3_index = (uint8_T)c3_i;
      chartInstance->c3_dataWrittenToVector[3U] = true;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_SET_NEW_PASS2;
      *chartInstance->c3_exit_key = 0;
      chartInstance->c3_dataWrittenToVector[9U] = true;
    }
    break;

   case c3_IN_SET_NEW_PASS2:
    c3_temp = (*chartInstance->c3_key_in_prev != *chartInstance->c3_key_in_start);
    if (c3_temp) {
      c3_temp = (*chartInstance->c3_key_in_start == 35);
    }

    if (c3_temp) {
      chartInstance->c3_JITTransitionAnimation[19U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_INIT;
      c3_enter_atomic_INIT(chartInstance);
    } else {
      if (!chartInstance->c3_dataWrittenToVector[11U]) {
        sf_read_before_write_error(chartInstance->S, 9U, 132U, 25, 4);
      }

      if ((*chartInstance->c3_key_in_prev != *chartInstance->c3_key_in_start) &&
          (*chartInstance->c3_key_in_prev == *chartInstance->c3_zero)) {
        chartInstance->c3_JITTransitionAnimation[22U] = 1U;
        *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
        *chartInstance->c3_is_c3_keypad_DONE = c3_IN_SET_NEW_PASS1;
        *chartInstance->c3_temporalCounter_i1 = 0U;
        flag_new_pass = true;
        if (!chartInstance->c3_dataWrittenToVector[3U]) {
          sf_read_before_write_error(chartInstance->S, 6U, 127U, 60, 5);
        }

        c3_u = *chartInstance->c3_key_in;
        if (c3_u > 127) {
          c3_u = 127U;
          sf_data_saturate_error(chartInstance->S, 127U, 69, 12);
        }

        (*chartInstance->c3_new_password_out)[sf_eml_array_bounds_check(NULL,
          chartInstance->S, 127U, 43, 23, 19U, (int32_T)*chartInstance->c3_index,
          1, 6) - 1] = (int8_T)(c3_u - 48);
        chartInstance->c3_dataWrittenToVector[15U] = true;
        *chartInstance->c3_state = 16U;
        chartInstance->c3_dataWrittenToVector[6U] = true;
        if (!chartInstance->c3_dataWrittenToVector[3U]) {
          sf_read_before_write_error(chartInstance->S, 6U, 127U, 116, 5);
        }

        *chartInstance->c3_cnt_test = *chartInstance->c3_index;
        chartInstance->c3_dataWrittenToVector[10U] = true;
      } else {
        *chartInstance->c3_state = 17U;
        chartInstance->c3_dataWrittenToVector[6U] = true;
        if (!chartInstance->c3_dataWrittenToVector[3U]) {
          sf_read_before_write_error(chartInstance->S, 6U, 130U, 66, 5);
        }

        *chartInstance->c3_cnt_test = *chartInstance->c3_index;
        chartInstance->c3_dataWrittenToVector[10U] = true;
        c3_u = *chartInstance->c3_key_in;
        if (c3_u > 127) {
          c3_u = 127U;
          sf_data_saturate_error(chartInstance->S, 130U, 84, 12);
        }

        *chartInstance->c3_exit_key = (int8_T)(c3_u - 48);
        chartInstance->c3_dataWrittenToVector[9U] = true;
      }
    }
    break;

   case c3_IN_WRONG_SEQ:
    if (*chartInstance->c3_temporalCounter_i1 >= 50) {
      chartInstance->c3_JITTransitionAnimation[16U] = 1U;
      *chartInstance->c3_cnt_blink = 0.0;
      chartInstance->c3_dataWrittenToVector[14U] = true;
      *chartInstance->c3_index = 1U;
      chartInstance->c3_dataWrittenToVector[3U] = true;
      *chartInstance->c3_state = 7U;
      chartInstance->c3_dataWrittenToVector[6U] = true;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_BLINK_RED1;
      *chartInstance->c3_temporalCounter_i1 = 0U;
      if (!chartInstance->c3_dataWrittenToVector[12U]) {
        sf_read_before_write_error(chartInstance->S, 17U, 115U, 29, 7);
      }

      *chartInstance->c3_red_led = !*chartInstance->c3_red_led;
      chartInstance->c3_dataWrittenToVector[12U] = true;
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    break;
  }

  if (c3_guard1) {
    chartInstance->c3_JITTransitionAnimation[5U] = 1U;
    *chartInstance->c3_blue_led = false;
    chartInstance->c3_dataWrittenToVector[13U] = true;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_INIT;
    c3_enter_atomic_INIT(chartInstance);
  }
}

static void initSimStructsc3_keypad_DONE(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_enter_atomic_INIT(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  int32_T c3_i;
  chartInstance->c3_dataWrittenToVector[4U] = true;
  for (c3_i = 0; c3_i < 6; c3_i++) {
    (*chartInstance->c3_correct_password)[c3_i] =
      (*chartInstance->c3_new_password_in)[c3_i];
    (*chartInstance->c3_password_in)[c3_i] = 0.0;
  }

  chartInstance->c3_dataWrittenToVector[5U] = true;
  *chartInstance->c3_cnt = 0U;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  *chartInstance->c3_index = 1U;
  chartInstance->c3_dataWrittenToVector[3U] = true;
  *chartInstance->c3_unlocked = 0U;
  chartInstance->c3_dataWrittenToVector[1U] = true;
  *chartInstance->c3_key_dec = 0;
  chartInstance->c3_dataWrittenToVector[7U] = true;
  *chartInstance->c3_exit_key = 0;
  chartInstance->c3_dataWrittenToVector[9U] = true;
  *chartInstance->c3_state = 0U;
  chartInstance->c3_dataWrittenToVector[6U] = true;
  *chartInstance->c3_cnt_test = 1U;
  chartInstance->c3_dataWrittenToVector[10U] = true;
  *chartInstance->c3_zero = 0U;
  chartInstance->c3_dataWrittenToVector[11U] = true;
  *chartInstance->c3_red_led = false;
  chartInstance->c3_dataWrittenToVector[12U] = true;
  *chartInstance->c3_blue_led = false;
  chartInstance->c3_dataWrittenToVector[13U] = true;
  flag_new_pass = false;
}

static void c3_CONVERT(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  uint8_T c3_u;
  int32_T c3_i;
  if (!chartInstance->c3_dataWrittenToVector[7U]) {
    sf_read_before_write_error(chartInstance->S, 7U, 25U, 2, 7);
  }

  if ((*chartInstance->c3_key_dec != -13) && (!flag_new_pass)) {
    chartInstance->c3_JITTransitionAnimation[1U] = 1U;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_INPUT_HANDLING;
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      sf_read_before_write_error(chartInstance->S, 6U, 9U, 34, 5);
    }

    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      sf_read_before_write_error(chartInstance->S, 7U, 9U, 43, 7);
    }

    (*chartInstance->c3_password_in)[sf_eml_array_bounds_check(NULL,
      chartInstance->S, 9U, 22, 18, 8U, (int32_T)*chartInstance->c3_index, 1, 6)
      - 1] = (real_T)*chartInstance->c3_key_dec;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      sf_read_before_write_error(chartInstance->S, 6U, 9U, 60, 5);
    }

    c3_i = (int32_T)((uint32_T)*chartInstance->c3_index + 1U);
    if ((uint32_T)c3_i > 255U) {
      c3_i = 255;
      sf_data_saturate_error(chartInstance->S, 9U, 60, 7);
    }

    *chartInstance->c3_index = (uint8_T)c3_i;
    chartInstance->c3_dataWrittenToVector[3U] = true;
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      sf_read_before_write_error(chartInstance->S, 6U, 9U, 80, 5);
    }

    *chartInstance->c3_cnt_test = *chartInstance->c3_index;
    chartInstance->c3_dataWrittenToVector[10U] = true;
  } else {
    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      sf_read_before_write_error(chartInstance->S, 7U, 26U, 1, 7);
    }

    if (*chartInstance->c3_key_dec == -13) {
      chartInstance->c3_JITTransitionAnimation[2U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_CHECK_CONFIRMATION;
      *chartInstance->c3_confirm_key = 0;
      chartInstance->c3_dataWrittenToVector[8U] = true;
    } else {
      c3_u = *chartInstance->c3_key_in;
      if (c3_u > 127) {
        c3_u = 127U;
        sf_data_saturate_error(chartInstance->S, 8U, 51, 12);
      }

      *chartInstance->c3_key_dec = (int8_T)(c3_u - 48);
      chartInstance->c3_dataWrittenToVector[7U] = true;
      *chartInstance->c3_state = 2U;
      chartInstance->c3_dataWrittenToVector[6U] = true;
    }
  }
}

static void c3_CHECK_SEQ(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  int32_T c3_k;
  boolean_T c3_y;
  boolean_T c3_x[6];
  boolean_T c3_exitg1;
  if (!chartInstance->c3_dataWrittenToVector[5U]) {
    sf_read_before_write_error(chartInstance->S, 8U, 27U, 9, 11);
  }

  if (!chartInstance->c3_dataWrittenToVector[4U]) {
    sf_read_before_write_error(chartInstance->S, 4U, 27U, 22, 16);
  }

  for (c3_k = 0; c3_k < 6; c3_k++) {
    c3_x[c3_k] = ((*chartInstance->c3_password_in)[c3_k] == (real_T)
                  (*chartInstance->c3_correct_password)[c3_k]);
  }

  c3_y = true;
  c3_k = 0;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_k < 6)) {
    if (!c3_x[c3_k]) {
      c3_y = false;
      c3_exitg1 = true;
    } else {
      c3_k++;
    }
  }

  if (c3_y) {
    chartInstance->c3_JITTransitionAnimation[3U] = 1U;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_RIGHT_SEQ;
    *chartInstance->c3_temporalCounter_i1 = 0U;
    *chartInstance->c3_exit_key = 0;
    chartInstance->c3_dataWrittenToVector[9U] = true;
    *chartInstance->c3_cnt_test = 33U;
    chartInstance->c3_dataWrittenToVector[10U] = true;
    flag_new_pass = true;
  } else {
    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      sf_read_before_write_error(chartInstance->S, 8U, 59U, 9, 11);
    }

    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      sf_read_before_write_error(chartInstance->S, 4U, 59U, 22, 16);
    }

    for (c3_k = 0; c3_k < 6; c3_k++) {
      c3_x[c3_k] = ((*chartInstance->c3_password_in)[c3_k] == (real_T)
                    (*chartInstance->c3_correct_password)[c3_k]);
    }

    c3_y = true;
    c3_k = 0;
    c3_exitg1 = false;
    while ((!c3_exitg1) && (c3_k < 6)) {
      if (!c3_x[c3_k]) {
        c3_y = false;
        c3_exitg1 = true;
      } else {
        c3_k++;
      }
    }

    if (!c3_y) {
      chartInstance->c3_JITTransitionAnimation[10U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_WRONG_SEQ;
      *chartInstance->c3_temporalCounter_i1 = 0U;
      *chartInstance->c3_red_led = false;
      chartInstance->c3_dataWrittenToVector[12U] = true;
      if (!chartInstance->c3_dataWrittenToVector[2U]) {
        sf_read_before_write_error(chartInstance->S, 1U, 18U, 40, 3);
      }

      c3_k = (int32_T)((uint32_T)*chartInstance->c3_cnt + 1U);
      if ((uint32_T)c3_k > 255U) {
        c3_k = 255;
        sf_data_saturate_error(chartInstance->S, 18U, 40, 7);
      }

      *chartInstance->c3_cnt = (uint8_T)c3_k;
      chartInstance->c3_dataWrittenToVector[2U] = true;
      *chartInstance->c3_unlocked = 0U;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      *chartInstance->c3_locked = 1U;
      chartInstance->c3_dataWrittenToVector[0U] = true;
    } else {
      *chartInstance->c3_state = 4U;
      chartInstance->c3_dataWrittenToVector[6U] = true;
    }
  }
}

static void c3_BLINK_RED2(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  if (*chartInstance->c3_temporalCounter_i1 >= 50) {
    chartInstance->c3_JITTransitionAnimation[6U] = 1U;
    *chartInstance->c3_red_led = true;
    chartInstance->c3_dataWrittenToVector[12U] = true;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_IDLE;
    *chartInstance->c3_state = 1U;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    *chartInstance->c3_red_led = true;
    chartInstance->c3_dataWrittenToVector[12U] = true;
  } else {
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      sf_read_before_write_error(chartInstance->S, 1U, 29U, 1, 3);
    }

    if (*chartInstance->c3_cnt == 3) {
      chartInstance->c3_JITTransitionAnimation[4U] = 1U;
      *chartInstance->c3_red_led = true;
      chartInstance->c3_dataWrittenToVector[12U] = true;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_BLOCKING;
      *chartInstance->c3_temporalCounter_i1 = 0U;
      *chartInstance->c3_cnt = 0U;
      chartInstance->c3_dataWrittenToVector[2U] = true;
    }
  }
}

static void c3_BLOCKING(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  boolean_T c3_guard1 = false;
  uint8_T c3_u;
  if (!chartInstance->c3_dataWrittenToVector[9U]) {
    sf_read_before_write_error(chartInstance->S, 5U, 32U, 2, 8);
  }

  c3_guard1 = false;
  if ((*chartInstance->c3_exit_key == -6) ||
      (*chartInstance->c3_temporalCounter_i1 >= 2000)) {
    c3_guard1 = true;
  } else {
    if (!chartInstance->c3_dataWrittenToVector[14U]) {
      sf_read_before_write_error(chartInstance->S, 2U, 32U, 40, 9);
    }

    if (*chartInstance->c3_cnt_blink == 20.0) {
      c3_guard1 = true;
    } else if (*chartInstance->c3_temporalCounter_i1 >= 50) {
      chartInstance->c3_JITTransitionAnimation[13U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_BLOCKING_BLINK;
      *chartInstance->c3_temporalCounter_i1 = 0U;
      if (!chartInstance->c3_dataWrittenToVector[14U]) {
        sf_read_before_write_error(chartInstance->S, 2U, 110U, 34, 9);
      }

      (*chartInstance->c3_cnt_blink)++;
      chartInstance->c3_dataWrittenToVector[14U] = true;
      if (!chartInstance->c3_dataWrittenToVector[12U]) {
        sf_read_before_write_error(chartInstance->S, 17U, 110U, 60, 7);
      }

      *chartInstance->c3_red_led = !*chartInstance->c3_red_led;
      chartInstance->c3_dataWrittenToVector[12U] = true;
      if (!chartInstance->c3_dataWrittenToVector[13U]) {
        sf_read_before_write_error(chartInstance->S, 18U, 110U, 80, 8);
      }

      *chartInstance->c3_blue_led = !*chartInstance->c3_blue_led;
      chartInstance->c3_dataWrittenToVector[13U] = true;
    } else {
      c3_u = *chartInstance->c3_key_in;
      if (c3_u > 127) {
        c3_u = 127U;
        sf_data_saturate_error(chartInstance->S, 23U, 44, 12);
      }

      *chartInstance->c3_exit_key = (int8_T)(c3_u - 48);
      chartInstance->c3_dataWrittenToVector[9U] = true;
      *chartInstance->c3_state = 8U;
      chartInstance->c3_dataWrittenToVector[6U] = true;
    }
  }

  if (c3_guard1) {
    chartInstance->c3_JITTransitionAnimation[7U] = 1U;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_INIT;
    c3_enter_atomic_INIT(chartInstance);
  }
}

static void c3_BLOCKING_BLINK(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  if (*chartInstance->c3_temporalCounter_i1 >= 50) {
    chartInstance->c3_JITTransitionAnimation[14U] = 1U;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
    *chartInstance->c3_is_c3_keypad_DONE = c3_IN_BLOCKING;
    *chartInstance->c3_temporalCounter_i1 = 0U;
    *chartInstance->c3_cnt = 0U;
    chartInstance->c3_dataWrittenToVector[2U] = true;
  } else {
    if (!chartInstance->c3_dataWrittenToVector[9U]) {
      sf_read_before_write_error(chartInstance->S, 5U, 122U, 1, 8);
    }

    if (*chartInstance->c3_exit_key == -6) {
      chartInstance->c3_JITTransitionAnimation[17U] = 1U;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_NO_ACTIVE_CHILD;
      *chartInstance->c3_is_c3_keypad_DONE = c3_IN_INIT;
      c3_enter_atomic_INIT(chartInstance);
    } else {
      c3_u = *chartInstance->c3_key_in;
      if (c3_u > 127) {
        c3_u = 127U;
        sf_data_saturate_error(chartInstance->S, 110U, 109, 12);
      }

      *chartInstance->c3_exit_key = (int8_T)(c3_u - 48);
      chartInstance->c3_dataWrittenToVector[9U] = true;
      if (!chartInstance->c3_dataWrittenToVector[9U]) {
        sf_read_before_write_error(chartInstance->S, 5U, 110U, 98, 8);
      }

      sf_mex_printf("%s =\\n", "exit_key");
      c3_y = NULL;
      sf_mex_assign(&c3_y, sf_mex_create("y", chartInstance->c3_exit_key, 2, 0U,
        0U, 0U, 0), false);
      sf_mex_call(chartInstance->c3_fEmlrtCtx, "disp", 0U, 1U, 14, c3_y);
      *chartInstance->c3_state = 11U;
      chartInstance->c3_dataWrittenToVector[6U] = true;
    }
  }
}

const mxArray *sf_c3_keypad_DONE_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  const char * c3_data[4] = {
    "789c6360f4f465646060e06380023608c50bc4cc402c001566624005e8f28c38681860656081eb83c983703f949f9c9f57925a5102e1e425e6a6c275a6e4e766"
    "e625e695845416a43214a516e7e794a5a68065d2327352433273537df291381e99404eae1b92149c039202b19d335293b3834b73198a328a112ecc41e6c0c323",
    "01c9bf0c48fe65c1121ec8f2e8003d3c40ea4a528bf290ed63a6c03e98f9ec38ed6307db979c9f5b9058944a35fb58d0f808fb58c0f665e6955880f830fb6650"
    "689f094efb20e109938f768d75b6d20f2d4e2d2ad62fc9cccdccd577c94f2ecd4dcd2b29d60f76f55530d5f77572d1f7494c32d68706895e2eb23b1370b8838d",
    "4877e2ca079c0c1c50d681e4e7dfaf3bd2cf3e081829f655e0308fd8742686c33e583a83c9bb5696581a388785b9175806045b96e666a4993b25ba22dc1140c0"
    "1e42ee60c0c1a7b5f9002a2f58bc", "" };

  c3_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c3_data[0], 1560U, &c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static boolean_T c3_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_blue_led, const char_T *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_blue_led),
    &c3_thisId);
  sf_mex_destroy(&c3_b_blue_led);
  return c3_y;
}

static boolean_T c3_b_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_cnt_test, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_cnt_test),
    &c3_thisId);
  sf_mex_destroy(&c3_b_cnt_test);
  return c3_y;
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_b_u;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_u, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_b_u;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_b_new_password_out, const char_T *c3_identifier, int8_T
  c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_new_password_out),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_new_password_out);
}

static void c3_f_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, int8_T c3_y[6])
{
  int8_T c3_iv[6];
  int32_T c3_i;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_iv, 1, 2, 0U, 1, 0U, 2, 1, 6);
  for (c3_i = 0; c3_i < 6; c3_i++) {
    c3_y[c3_i] = c3_iv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static real_T c3_g_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_cnt_blink, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_cnt_blink),
    &c3_thisId);
  sf_mex_destroy(&c3_b_cnt_blink);
  return c3_y;
}

static real_T c3_h_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static int8_T c3_i_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_confirm_key, const char_T *c3_identifier)
{
  int8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_confirm_key),
    &c3_thisId);
  sf_mex_destroy(&c3_b_confirm_key);
  return c3_y;
}

static int8_T c3_j_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_k_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_b_password_in, const char_T *c3_identifier, real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_password_in), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_password_in);
}

static void c3_l_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv[6];
  int32_T c3_i;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c3_i = 0; c3_i < 6; c3_i++) {
    c3_y[c3_i] = c3_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static uint16_T c3_m_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_temporalCounter_i1, const char_T
  *c3_identifier)
{
  uint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_temporalCounter_i1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_temporalCounter_i1);
  return c3_y;
}

static uint16_T c3_n_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint16_T c3_y;
  uint16_T c3_b_u;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_u, 1, 5, 0U, 0, 0U, 0);
  c3_y = c3_b_u;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint32_T c3_o_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_previousTicks, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_previousTicks),
    &c3_thisId);
  sf_mex_destroy(&c3_b_previousTicks);
  return c3_y;
}

static uint32_T c3_p_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_b_u;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_u, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_b_u;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_q_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[16])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_r_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[16])
{
  boolean_T c3_bv[16];
  int32_T c3_i;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv, 1, 11, 0U, 1, 0U, 1, 16);
  for (c3_i = 0; c3_i < 16; c3_i++) {
    c3_y[c3_i] = c3_bv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_s_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_t_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_t_emlrt_marshallIn(SFc3_keypad_DONEInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static int8_T c3_get_my_new_pass(SFc3_keypad_DONEInstanceStruct *chartInstance,
  uint32_T c3_elementIndex)
{
  if (chartInstance->c3_dsmdiag_my_new_pass) {
    ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, "my_new_pass",
      c3_elementIndex);
  }

  return (*chartInstance->c3_my_new_pass_address)[c3_elementIndex];
}

static void c3_set_my_new_pass(SFc3_keypad_DONEInstanceStruct *chartInstance,
  uint32_T c3_elementIndex, int8_T c3_elementValue)
{
  if (chartInstance->c3_dsmdiag_my_new_pass) {
    ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, "my_new_pass",
      c3_elementIndex);
  }

  (*chartInstance->c3_my_new_pass_address)[c3_elementIndex] = c3_elementValue;
}

static int8_T *c3_access_my_new_pass(SFc3_keypad_DONEInstanceStruct
  *chartInstance, uint32_T c3_rdOnly)
{
  if (chartInstance->c3_dsmdiag_my_new_pass) {
    ssAccessDataStore_wrapper(chartInstance->S, 0, "my_new_pass", c3_rdOnly);
  }

  return &(*chartInstance->c3_my_new_pass_address)[0U];
}

static void init_dsm_address_info(SFc3_keypad_DONEInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "my_new_pass", (void **)
    &chartInstance->c3_my_new_pass_address, &chartInstance->c3__index_pass);
}

static void init_simulink_io_address(SFc3_keypad_DONEInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_is_active_c3_keypad_DONE = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_is_c3_keypad_DONE = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_key_in = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_locked = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_unlocked = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_cnt = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 4);
  chartInstance->c3_index = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c3_correct_password = (int8_T (*)[6])ssGetDWork_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_password_in = (real_T (*)[6])ssGetDWork_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_state = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_key_dec = (int8_T *)ssGetDWork_wrapper(chartInstance->S, 8);
  chartInstance->c3_confirm_key = (int8_T *)ssGetDWork_wrapper(chartInstance->S,
    9);
  chartInstance->c3_exit_key = (int8_T *)ssGetDWork_wrapper(chartInstance->S, 10);
  chartInstance->c3_cnt_test = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_zero = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 11);
  chartInstance->c3_red_led = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_blue_led = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_cnt_blink = (real_T *)ssGetDWork_wrapper(chartInstance->S,
    12);
  chartInstance->c3_new_password_in = (int8_T (*)[6])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c3_new_password_out = (int8_T (*)[6])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 7);
  chartInstance->c3_Voltage_in_V = (uint32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_temporalCounter_i1 = (uint16_T *)ssGetDWork_wrapper
    (chartInstance->S, 13);
  chartInstance->c3_presentTicks = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 14);
  chartInstance->c3_elapsedTicks = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 15);
  chartInstance->c3_previousTicks = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 16);
  chartInstance->c3_key_in_prev = (uint8_T *)ssGetDWork_wrapper(chartInstance->S,
    17);
  chartInstance->c3_key_in_start = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 18);
  chartInstance->c3_dsmdiag_my_new_pass = (boolean_T)
    ssGetDSMBlockDiagnosticsEnabled_wrapper(chartInstance->S, 0, "my_new_pass");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c3_keypad_DONE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2562345222U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2486015993U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(997315169U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(743651564U);
}

mxArray *sf_c3_keypad_DONE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_keypad_DONE_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("machine_data");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_keypad_DONE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_keypad_DONE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNrNl19r2zAQwOUkTRPWlXaFsceyh1H2MPYHtr3N0A2Wh60ZK/vTdghVvoKIIxlZbtM99aP1I+0"
    "jzIpEZmtl9lyTyCAud+Tk+/l0JwkFow8ofzbzsbeDUD+Xg3x0kHnWrB7k476Vxt5b2HfzoS4T0P"
    "ZU0lGUS06mc51ksxE/E/P5X6M/8/dvmD8ozD+0dvP8enMr//A4dP17N/gPCv5bVj+NM8AxRJvWv"
    "lIOdNSYg3KFFaTKD45BLY6+w6H1WNAJRCb+1XOQOUdYwbHlcOjB4QInJE0vhIywyDzJS706WXd4"
    "tC4h0mXiSV4+1eJYczi0niqiAHmyvq7Gjes946ZS2uH4u17/jyOc+z+t4OiWOLq6ZyEv4g9PatX"
    "50MnD0Pbd05jxSYFj9fn4VovnjsOjdSr4GZNTPIFLf3jQuHEfpkJKoGrRi73guf7euO5hxpROjh"
    "/r7KBxH2Y8gpk39fK58b6YpwJHQD3pY+PGdb84qzDuUR87qrWv9Eo8PfQTpGgn/t1b9i3z/vcV8"
    "T9w8qF1lmJCFTsHTF/oek9IhN8efHzXDtfDpXBtO1zbhqsM1Oq++WgpXPccLq0rmCZCknhfZFyB"
    "xOxZgSf49707cO7d3cJ5AxQSKaKqGF9VPXRK8XUQUcYvqfguA+e7hIu+QszPa2xNr6x8aeUPK5/"
    "b/50YeXUcrvaesNfK+6v66YazHjbsvsA4zq8bUrW3vh+3sr6reO46PFpPJJwzkaWHjE7S1nieLK"
    "VedxwerUdEka+SKQX8UHzJT4hClvrQbzqTtcM="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_keypad_DONE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "siHS7FACSBSEbGyKLgXwLiC";
}

static void sf_opaque_initialize_c3_keypad_DONE(void *chartInstanceVar)
{
  initialize_params_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*)
    chartInstanceVar);
  initialize_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_keypad_DONE(void *chartInstanceVar)
{
  enable_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_keypad_DONE(void *chartInstanceVar)
{
  disable_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_keypad_DONE(void *chartInstanceVar)
{
  sf_gateway_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_keypad_DONE(void *chartInstanceVar)
{
  ext_mode_exec_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_keypad_DONE(SimStruct* S)
{
  return get_sim_state_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_keypad_DONE(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_keypad_DONE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_keypad_DONEInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_keypad_DONE_optimization_info();
    }

    finalize_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_keypad_DONE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc3_keypad_DONE((SFc3_keypad_DONEInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_keypad_DONE_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [38] = {
    "eNrtXU+T2zQUd7ZLaaGFhQ7QGTh0OADDgSkw03Ij3ewuBLbd0GxboDBBsV8SsYpkJDm7ywmuDB+",
    "AO3e+AAf4CBz5Atz5AByQbCd1FCd2nDRxW2Um9cp57+k9vaef/jzZdSr1m476PKe+HwvHOauu59",
    "R3w4k+T8XlSuIb3d903ozLvyoiGvQbiKO+cGZ+KOrDbRCMBBIzWqcdlkqGaQc4UFfR+ozLadIE7",
    "gcE06O9gLpanrjXw26v2WMB8bYVL/IOKDlV0vxANpScHczBlXsAnuxxFnR7ewR1RxpzeVzrgXsk",
    "gv4sEwTIZuBrtcTNgEjsE9g9AbdOhURKY/FAt6ZEEmryZKqZ2lLRHBKyvk8woqnW9pBogq8aWMI",
    "d31P/HgRSGWWSuT3E5Tb00ADEPj4KZTIKpkws1A9tTJFkHCOy2yc1zTipW4MofW4yD8iMBlG6bX",
    "NARz7DVE73f3NPWbpLUZvADrSD7nRpTfgu0M6/i+EY+NR269TYADjqwgGdWmnYILsnobdGUTJJJ",
    "nEf7iJ+w1X+E+BNjV4VOaKJlJ/gUHFMI4PQyLo45HigmneqtKBf15GZ1WWCfuRskUUWStsdwCwv",
    "jKTtubSGCBFTyQ6Zvw8DIKHUHSTRbLJIajqdz5mPuipqPdXIOsRrjHp4whduICTr11S47ezv31J",
    "Ika7cA7I6lcA7yIW0fivcHngBAWWoQiYZVpci1MNCeyuDKvZpFpUjOgHdOWb8SBk6o9s/MEH7YC",
    "phX3RV66vYvSNUmM8i062fSTfE+avOA5y/kAPnh3zm9a2EnEqKHCdxNes9vzFOf8aod0PdqVQqI",
    "V81wXfRqGfT4NN0W1r+X3s/fnT8yk+f/H72m59/+++frPorE/VXRnr/fWm+cfG5uPzaEIBG4TmY",
    "iIpw3E3otZki/5WE/K24LPDHzet7N2rN7eZu+6PTT/e7nx/v41rklwx9Xzb0Hd6/opHw1A9xTXC",
    "37sUDti6jIBrGtPwPEvqezWiP8/H96PPvhwvxV+9XTf609jpntJcut0kALQJeMn7XZofzZWE7XC",
    "pbEoQshx3nctlx1rBDlwlzj/RAWw47UNXEmTQ7tgw7tsIpwXHLR0IozPdaLCiJX/L1k6cNe3SZg",
    "6e7SUn88lkuO54y7NBloafUTkni64dG4f4e0KinLMeOyf46nx3VqjmOptlxZsyOMxqznFLoX/0q",
    "Vz8/b/jhfIy7bb3WTJkHrc8fn+ey51nDHl12Ge1g3m8dwWl57HEahXHYZVyv7UdYXAp7/vyicL+",
    "HEyy1c8oRZweFcRhTD05K01+ahcdF5YqWB25JcKxRuN+P5iqYlgjHvsw1rmyO2bPpfA+cLUf/Kw",
    "viVr513GXDH5fDfawWciUeQMt9X/d3H3mtnYNbu8ux6/WV2PWCYdcLkV3jBi113HxjJXa9aNily",
    "xL6PuOI1FigN59a+N2EPZX59gnOJOYbIB0mHFdO26dJ029jTL8NB8mIz89ol3NGu1RHuIKiP/9s",
    "xbeux9dr8fXr+PpeTPdVdP3hfnW964S3llJ/Fp5eMOLhQjwuYNpSy41o/3w58f32UuI7y56Lhj0",
    "Xw61aGGAWiEPsHoml2fPOSvrrJcMeXfaQRPc4lhLoIburZoiMT+DQvPuClYJ8juV7IvkqJYizCz",
    "nHoyJ8Ty+YV1gV36L2zZvvWCQ/YuKbY9BvLVDPw6b/5fbsedAlo32H+YgtRTxA/BaaSK0OsxKTu",
    "fMuNdO1enWzD7Qre8m7bYxSsomCsBTBcJKeNG+6iIC3w4I2gbFUuk/CNW7yYML3KfqK036bEew2",
    "x35tY3kPe+Paah3CvPsdnzDkjbVDc0I2Fgc++i6YuHsIQjZ0Uj5xl7W/TWlfH5n1h6lREC7Hvk5",
    "2Ju5yfXxjAIdMNz4iB+1v1aiq9/MRaSklAmh5OgHawt7J2F08MkNwd1/9YMjto5Om5Jh2x5xXdL",
    "0uOmEi3Cm+byHff29K3jPruug852oGv2PwL7v+9fFvVcugf1EcLspXZL/zRrhpEB7bCQN9ve327",
    "x/L4C/afnnXBy8b/LrsKaSPEH076HSA34Y6xbI47rQZI4CoxY3Vxt+HTyJuZMX7SwafLidjXUd6",
    "eDRl/f57JPBj3v3bIvOOQE08PrDzjhX3/3XjR1T/suNv2fKK7CeGR5vrIpquWJx5KPkUizMWZ5a",
    "JM/PG37LlFVkPhTgzXBRh4lmcKX5Oy+KJXfese90zKz6z8OEZoz5dDndK9K4jKYXfSoEPi57nsj",
    "hhcWIVOLFonFq8WA5eFJmXpZ3Lnfecn4aMdeBFNYN/w+DfSvS36Hq5avFj/fixrLi1OLIaHMl7b",
    "rnIc2denL23eLJO/ivVxxlP8savxZPVrGOynud4VOYjdv3yeK5fsuLT4sT65h1pz0lavLB4Ubb5",
    "RVqcWtxYzfwi6/ldixcWL9Y5v8iKT4sTq8m3Tnt+2eZRLE6UId86LT4tPqxm/ZH3vTOP2r7nk4s",
    "Xj/c+Z954tfixmnOjc7+vogCO6HnHu9csjqyY3z4Xl6Lv8wafLh+Ox7vFDafYe018DgKoHL4GZC",
    "G80A/SWrxYJb99jjZvnNcCzkG/kDyg0s4zircjEOQL8CxeWLx4rPFiN4pzixdztGPe94xZvLB48",
    "SjjRVqcN+I4HwKGxYti+e34PYsaNnLvX9i8ic2brBMvGhnx+arB92q070m7sAMSwv+rKvm6DrsP",
    "usC8Le09rRY/LH5Y/Hjy8GN4fZjvwfwf2x93Ng==",
    ""
  };

  static char newstr [2741] = "";
  newstr[0] = '\0';
  for (i = 0; i < 38; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_keypad_DONE(SimStruct *S)
{
  const char* newstr = sf_c3_keypad_DONE_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2168901641U));
  ssSetChecksum1(S,(2316793671U));
  ssSetChecksum2(S,(1611053898U));
  ssSetChecksum3(S,(3858542220U));
}

static void mdlRTW_c3_keypad_DONE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_keypad_DONE(SimStruct *S)
{
  SFc3_keypad_DONEInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_DONEInstanceStruct *)utMalloc(sizeof
    (SFc3_keypad_DONEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_keypad_DONEInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_keypad_DONE;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_keypad_DONE;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_keypad_DONE;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_keypad_DONE;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_keypad_DONE;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_keypad_DONE;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_keypad_DONE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_keypad_DONE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_keypad_DONE;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_keypad_DONE;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_keypad_DONE;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c3_keypad_DONE;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c3_JITStateAnimation,
    chartInstance->c3_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_start_c3_keypad_DONE(chartInstance);
}

void c3_keypad_DONE_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_keypad_DONE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_keypad_DONE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_keypad_DONE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_keypad_DONE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
