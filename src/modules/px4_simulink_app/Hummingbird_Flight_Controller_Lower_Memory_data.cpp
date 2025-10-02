//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hummingbird_Flight_Controller_Lower_Memory_data.cpp
//
// Code generated for Simulink model 'Hummingbird_Flight_Controller_Lower_Memory'.
//
// Model version                  : 2.238
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Oct  1 21:21:18 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Hummingbird_Flight_Controller_Lower_Memory.h"

// Block parameters (default storage)
P_Hummingbird_Flight_Controll_T Hummingbird_Flight_Controller_P = {
  // Variable: IB
  //  Referenced by: '<S1402>/Constant13'

  { 1.4365636849630137, 0.0, 0.21166159010381053, 0.0, 3.3499098651084727, 0.0,
    0.21166159010381053, 0.0, 4.6320009945919063 },

  // Variable: g
  //  Referenced by: '<S14>/Gain3'

  32.174,

  // Variable: m
  //  Referenced by:
  //    '<S489>/Gain5'
  //    '<S721>/Gain5'
  //    '<S1112>/Gain5'

  1.243239883135451,

  // Mask Parameter: PIDController5_D
  //  Referenced by: '<S806>/Derivative Gain'

  0.05,

  // Mask Parameter: PIDController3_D
  //  Referenced by: '<S754>/Derivative Gain'

  0.1,

  // Mask Parameter: PIDController8_D
  //  Referenced by: '<S1035>/Derivative Gain'

  { 0.2, 0.2, 5.0E-5 },

  // Mask Parameter: PIDController9_D
  //  Referenced by: '<S1087>/Derivative Gain'

  { 0.015, 0.015, 0.0 },

  // Mask Parameter: PIDController9_D_d
  //  Referenced by: '<S1377>/Derivative Gain'

  { 0.015, 0.015, 0.0 },

  // Mask Parameter: PIDController_D
  //  Referenced by: '<S1486>/Derivative Gain'

  1.0,

  // Mask Parameter: PIDController3_I
  //  Referenced by: '<S758>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController5_I
  //  Referenced by: '<S810>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController8_I
  //  Referenced by: '<S1039>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController9_I
  //  Referenced by: '<S1091>/Integral Gain'

  { 0.02505936168136361, 0.02505936168136361, 0.05011872336272722 },

  // Mask Parameter: PIDController9_I_i
  //  Referenced by: '<S1381>/Integral Gain'

  { 0.0, 0.0, 0.0 },

  // Mask Parameter: PIDController_InitialConditionF
  //  Referenced by: '<S58>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S110>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_l
  //  Referenced by: '<S230>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditio_a
  //  Referenced by: '<S178>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialCondit_lu
  //  Referenced by: '<S408>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditio_g
  //  Referenced by: '<S356>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialCondition
  //  Referenced by: '<S522>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_f
  //  Referenced by: '<S636>/Filter'

  0.0,

  // Mask Parameter: PIDController5_InitialCondition
  //  Referenced by: '<S808>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_f
  //  Referenced by: '<S756>/Filter'

  0.0,

  // Mask Parameter: PIDController8_InitialCondition
  //  Referenced by: '<S1037>/Filter'

  0.0,

  // Mask Parameter: PIDController9_InitialCondition
  //  Referenced by: '<S1089>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_g
  //  Referenced by: '<S974>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_m
  //  Referenced by: '<S1147>/Filter'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_h
  //  Referenced by: '<S1379>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_b
  //  Referenced by: '<S1313>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditi_gy
  //  Referenced by: '<S1488>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditio_p
  //  Referenced by: '<S63>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_m
  //  Referenced by: '<S115>/Integrator'

  0.0,

  // Mask Parameter: PIDController5_InitialConditi_i
  //  Referenced by: '<S813>/Integrator'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_a
  //  Referenced by: '<S761>/Integrator'

  0.0,

  // Mask Parameter: PIDController8_InitialConditi_g
  //  Referenced by: '<S1042>/Integrator'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_i
  //  Referenced by: '<S1094>/Integrator'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_b
  //  Referenced by: '<S1384>/Integrator'

  0.0,

  // Mask Parameter: PIDController_LowerIntegratorSa
  //  Referenced by: '<S63>/Integrator'

  -2.0,

  // Mask Parameter: PIDController1_LowerIntegratorS
  //  Referenced by: '<S115>/Integrator'

  -2.0,

  // Mask Parameter: PIDController8_LowerIntegratorS
  //  Referenced by: '<S1042>/Integrator'

  -5.0,

  // Mask Parameter: PIDController9_LowerIntegratorS
  //  Referenced by: '<S1094>/Integrator'

  -4.0,

  // Mask Parameter: PIDController9_LowerIntegrato_p
  //  Referenced by: '<S1384>/Integrator'

  -4.0,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by: '<S70>/Saturation'

  -5.0,

  // Mask Parameter: PIDController1_LowerSaturationL
  //  Referenced by: '<S122>/Saturation'

  -5.0,

  // Mask Parameter: PIDController5_LowerSaturationL
  //  Referenced by: '<S820>/Saturation'

  -15.0,

  // Mask Parameter: PIDController9_LowerSaturationL
  //  Referenced by: '<S1101>/Saturation'

  -5.0,

  // Mask Parameter: PIDController9_LowerSaturatio_a
  //  Referenced by: '<S1391>/Saturation'

  -5.0,

  // Mask Parameter: PIDController5_N
  //  Referenced by: '<S816>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController3_N
  //  Referenced by: '<S764>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController8_N
  //  Referenced by: '<S1045>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController9_N
  //  Referenced by: '<S1097>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController9_N_j
  //  Referenced by: '<S1387>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S1496>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController5_P
  //  Referenced by: '<S818>/Proportional Gain'

  1.0,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S766>/Proportional Gain'

  1.0,

  // Mask Parameter: PIDController8_P
  //  Referenced by: '<S1047>/Proportional Gain'

  { 0.21, 0.21, 0.00035 },

  // Mask Parameter: PIDController9_P
  //  Referenced by: '<S1099>/Proportional Gain'

  { 0.60000000000000009, 0.60000000000000009, 0.1 },

  // Mask Parameter: PIDController9_P_b
  //  Referenced by: '<S1389>/Proportional Gain'

  { 0.60000000000000009, 0.60000000000000009, 0.1 },

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S1498>/Proportional Gain'

  0.0,

  // Mask Parameter: PIDController_UpperIntegratorSa
  //  Referenced by: '<S63>/Integrator'

  2.0,

  // Mask Parameter: PIDController1_UpperIntegratorS
  //  Referenced by: '<S115>/Integrator'

  2.0,

  // Mask Parameter: PIDController8_UpperIntegratorS
  //  Referenced by: '<S1042>/Integrator'

  5.0,

  // Mask Parameter: PIDController9_UpperIntegratorS
  //  Referenced by: '<S1094>/Integrator'

  4.0,

  // Mask Parameter: PIDController9_UpperIntegrato_e
  //  Referenced by: '<S1384>/Integrator'

  4.0,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by: '<S70>/Saturation'

  5.0,

  // Mask Parameter: PIDController1_UpperSaturationL
  //  Referenced by: '<S122>/Saturation'

  5.0,

  // Mask Parameter: PIDController5_UpperSaturationL
  //  Referenced by: '<S820>/Saturation'

  15.0,

  // Mask Parameter: PIDController9_UpperSaturationL
  //  Referenced by: '<S1101>/Saturation'

  5.0,

  // Mask Parameter: PIDController9_UpperSaturatio_o
  //  Referenced by: '<S1391>/Saturation'

  5.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1424>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // data
    0U,                                // id

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S1514>/Out1'

  {
    (0ULL),                            // timestamp

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // previous

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // current

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    }                                  // next
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S1441>/Constant'

  {
    (0ULL),                            // timestamp

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // previous

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // current

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    }                                  // next
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S1519>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S1455>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_ns
  //  Referenced by: '<S1512>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S1439>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S1520>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // alt_ellipsoid
    0.0F,                              // delta_alt
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // terrain_alt
    0U,                                // lat_lon_reset_counter
    0U,                                // alt_reset_counter
    false,                             // terrain_alt_valid
    false,                             // dead_reckoning

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S1456>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // alt_ellipsoid
    0.0F,                              // delta_alt
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // terrain_alt
    0U,                                // lat_lon_reset_counter
    0U,                                // alt_reset_counter
    false,                             // terrain_alt_valid
    false,                             // dead_reckoning

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S19>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // prev_waypoint

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // current_waypoint

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // next_waypoint
    0.0F,                              // angle_desired
    0.0F,                              // angle_actual
    0.0F,                              // alpha
    0.0F,                              // as_a
    0.0F                               // as_b
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S1516>/Out1'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S1443>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Constant_Value_oi
  //  Referenced by: '<S1433>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S1517>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S1453>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S1515>/Out1'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S1442>/Constant'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S1458>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_bd
  //  Referenced by: '<S1457>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_ds
  //  Referenced by: '<S1518>/Out1'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // gyro_rad
    0U,                                // gyro_integral_dt
    0,                                 // accelerometer_timestamp_relative

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // accelerometer_m_s2
    0U,                                // accelerometer_integral_dt
    0U,                                // accelerometer_clipping
    0U,                                // gyro_clipping
    0U,                                // accel_calibration_count
    0U                                 // gyro_calibration_count
  },

  // Computed Parameter: Constant_Value_os
  //  Referenced by: '<S1454>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // gyro_rad
    0U,                                // gyro_integral_dt
    0,                                 // accelerometer_timestamp_relative

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // accelerometer_m_s2
    0U,                                // accelerometer_integral_dt
    0U,                                // accelerometer_clipping
    0U,                                // gyro_clipping
    0U,                                // accel_calibration_count
    0U                                 // gyro_calibration_count
  },

  // Computed Parameter: Constant_Value_bo
  //  Referenced by: '<S135>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // energy
    0.0F,                              // energy_setpoint
    0.0F,                              // energy_setpoint_dot
    0.0F,                              // energy_dot
    0.0F,                              // energy_ratio
    0.0F,                              // energy_ratio_sp
    0.0F,                              // energy_ratio_dot
    0.0F,                              // energy_ratio_setpoint_dot
    0.0F,                              // climb_angle

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_eb
  //  Referenced by: '<S133>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // h_sp
    0.0F,                              // h
    0.0F,                              // climb_angle_sp
    0.0F,                              // climb_angle_ideal
    0.0F,                              // horz_dist
    0.0F,                              // v_sp
    0.0F,                              // v

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S1513>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_e2
  //  Referenced by: '<S1440>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S1342>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_ay
  //  Referenced by: '<S305>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_km
  //  Referenced by: '<S483>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S711>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_p1
  //  Referenced by: '<S997>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_bh
  //  Referenced by: '<S1336>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_k2
  //  Referenced by: '<S1422>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // de
    0.0F,                              // dt
    0.0F,                              // da
    0.0F                               // dr
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S1420>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S307>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S485>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S713>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_g5
  //  Referenced by: '<S999>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_ib
  //  Referenced by: '<S1338>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S309>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_av
  //  Referenced by: '<S487>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_jn
  //  Referenced by: '<S715>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_c1
  //  Referenced by: '<S1001>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_cm
  //  Referenced by: '<S1340>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_n3
  //  Referenced by: '<S1511>/Out1'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_pi
  //  Referenced by: '<S1438>/Constant'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: pi/3
  //  Referenced by: '<S14>/Saturation'

  1.0471975511965976,

  // Expression: -pi/3
  //  Referenced by: '<S14>/Saturation'

  -1.0471975511965976,

  // Expression: 0
  //  Referenced by: '<S15>/Constant'

  0.0,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S58>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S63>/Integrator'

  0.001,

  // Expression: 100
  //  Referenced by: '<S27>/Constant2'

  100.0,

  // Computed Parameter: Filter_gainval_c
  //  Referenced by: '<S110>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_k
  //  Referenced by: '<S115>/Integrator'

  0.001,

  // Expression: 100
  //  Referenced by: '<S28>/Constant2'

  100.0,

  // Expression: 15*pi/180
  //  Referenced by: '<S15>/Saturation1'

  0.26179938779914941,

  // Expression: -10*pi/180
  //  Referenced by: '<S15>/Saturation1'

  -0.17453292519943295,

  // Expression: 0
  //  Referenced by: '<S13>/Gain3'

  0.0,

  // Expression: 32.174
  //  Referenced by: '<S13>/Gain4'

  32.174,

  // Computed Parameter: Filter_gainval_j
  //  Referenced by: '<S230>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S13>/Constant1'

  100.0,

  // Computed Parameter: Filter_gainval_b
  //  Referenced by: '<S178>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S13>/Constant4'

  100.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/Constant10'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/Constant11'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S320>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S320>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S320>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S320>/Saturation'

  -1.0,

  // Expression: 60*pi/180
  //  Referenced by: '<S311>/Gain1'

  1.0471975511965976,

  // Expression: 1500
  //  Referenced by: '<S321>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S321>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S321>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S321>/Saturation'

  -1.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S311>/Gain2'

  0.3490658503988659,

  // Expression: 1500
  //  Referenced by: '<S322>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S322>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S322>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S322>/Saturation'

  -1.0,

  // Expression: 0.2
  //  Referenced by: '<S311>/Gain3'

  0.2,

  // Expression: 32.174
  //  Referenced by: '<S311>/Gain4'

  32.174,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S408>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S311>/Constant1'

  100.0,

  // Computed Parameter: Filter_gainval_bd
  //  Referenced by: '<S356>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S311>/Constant4'

  100.0,

  // Expression: 0
  //  Referenced by: '<S8>/Constant14'

  0.0,

  // Expression: 100
  //  Referenced by: '<S489>/Constant'

  100.0,

  // Expression: 1500
  //  Referenced by: '<S717>/Constant'

  1500.0,

  // Expression: 5/500
  //  Referenced by: '<S717>/Gain'

  0.01,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S522>/Filter'

  0.001,

  // Expression: 1500
  //  Referenced by: '<S718>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S718>/Gain'

  0.002,

  // Expression: pi/8
  //  Referenced by: '<S491>/Gain1'

  0.39269908169872414,

  // Expression: 15*pi/180
  //  Referenced by: '<S491>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S491>/Saturation1'

  -0.26179938779914941,

  // Expression: 1500
  //  Referenced by: '<S719>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S719>/Gain'

  0.002,

  // Expression: pi/8
  //  Referenced by: '<S491>/Gain2'

  0.39269908169872414,

  // Expression: 15*pi/180
  //  Referenced by: '<S491>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S491>/Saturation'

  -0.26179938779914941,

  // Expression: 1500
  //  Referenced by: '<S720>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S720>/Gain'

  0.002,

  // Expression: pi/3
  //  Referenced by: '<S491>/Gain'

  1.0471975511965976,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S636>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S490>/Constant1'

  100.0,

  // Expression: 0
  //  Referenced by: '<S9>/Constant10'

  0.0,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S813>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_k
  //  Referenced by: '<S808>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_m
  //  Referenced by: '<S761>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S756>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S1042>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_e
  //  Referenced by: '<S1037>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_m2
  //  Referenced by: '<S1094>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_lu
  //  Referenced by: '<S1089>/Filter'

  0.001,

  // Expression: 15*pi/180
  //  Referenced by: '<S724>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S724>/Saturation1'

  -0.26179938779914941,

  // Expression: 15*pi/180
  //  Referenced by: '<S724>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S724>/Saturation'

  -0.26179938779914941,

  // Computed Parameter: Filter_gainval_io
  //  Referenced by: '<S974>/Filter'

  0.001,

  // Expression: 1
  //  Referenced by: '<S723>/Constant4'

  1.0,

  // Expression: 0
  //  Referenced by: '<S10>/Constant14'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S1346>/Constant'

  1500.0,

  // Expression: 5/500
  //  Referenced by: '<S1346>/Gain'

  0.01,

  // Computed Parameter: Filter_gainval_pt
  //  Referenced by: '<S1147>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S1112>/Constant'

  100.0,

  // Expression: 1500
  //  Referenced by: '<S1349>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1349>/Gain'

  0.002,

  // Expression: pi/3
  //  Referenced by: '<S1116>/Gain'

  1.0471975511965976,

  // Expression: 1500
  //  Referenced by: '<S1348>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1348>/Gain'

  0.002,

  // Expression: 10
  //  Referenced by: '<S1116>/Gain2'

  10.0,

  // Expression: 1500
  //  Referenced by: '<S1347>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1347>/Gain'

  0.002,

  // Expression: 10
  //  Referenced by: '<S1116>/Gain1'

  10.0,

  // Computed Parameter: Integrator_gainval_ma
  //  Referenced by: '<S1384>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_kc
  //  Referenced by: '<S1379>/Filter'

  0.001,

  // Expression: 15*pi/180
  //  Referenced by: '<S1116>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S1116>/Saturation1'

  -0.26179938779914941,

  // Expression: 15*pi/180
  //  Referenced by: '<S1116>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S1116>/Saturation'

  -0.26179938779914941,

  // Computed Parameter: Filter_gainval_o
  //  Referenced by: '<S1313>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S1114>/Constant4'

  100.0,

  // Expression: 0
  //  Referenced by: '<S11>/Constant'

  0.0,

  // Expression: -120
  //  Referenced by: '<S11>/Constant1'

  -120.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S11>/Constant2'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S1402>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1402>/Constant9'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1402>/Constant29'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1402>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1402>/Constant3'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S1411>/Constant7'

  1000.0,

  // Expression: 1/500
  //  Referenced by: '<S1411>/Gain10'

  0.002,

  // Expression: 2
  //  Referenced by: '<S1411>/Saturation'

  2.0,

  // Expression: 0
  //  Referenced by: '<S1411>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1402>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1402>/Switch3'

  0.0,

  // Expression: IBmat(:,:,1,1)
  //  Referenced by: '<S1402>/Constant2'

  { 2.92525710891472, -0.0060651112354350991, 0.2809484711602882,
    -0.0060651112354350991, 4.5510371556052851, -0.0011029437157677353,
    0.2809484711602882, -0.0011029437157677353, 7.2341711388768024 },

  // Expression: 0
  //  Referenced by: '<S1414>/Constant1'

  0.0,

  // Expression: 120
  //  Referenced by: '<S1404>/Saturation3'

  120.0,

  // Expression: 0
  //  Referenced by: '<S1404>/Saturation3'

  0.0,

  // Expression: 8*0.000017484269645*.75
  //  Referenced by: '<S1415>/Constant'

  0.00010490561787000001,

  // Expression: -1
  //  Referenced by: '<S1415>/Gain'

  -1.0,

  // Expression: [0; 0; 0]
  //  Referenced by: '<S1413>/Constant1'

  { 0.0, 0.0, 0.0 },

  // Expression: eye(3)
  //  Referenced by: '<S1402>/Constant12'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: 44.41
  //  Referenced by: '<S1415>/Saturation9'

  44.41,

  // Expression: -44.41
  //  Referenced by: '<S1415>/Saturation9'

  -44.41,

  // Expression: -8*ly*0.000017484269645
  //  Referenced by: '<S1415>/Constant2'

  -0.00015153033692333332,

  // Expression: 78.5
  //  Referenced by: '<S1415>/Saturation8'

  78.5,

  // Expression: -78.5
  //  Referenced by: '<S1415>/Saturation8'

  -78.5,

  // Expression: -8*0.000017484269645*lx
  //  Referenced by: '<S1415>/Constant1'

  -0.00026809213455666669,

  // Expression: 3.805821
  //  Referenced by: '<S1415>/Saturation10'

  3.805821,

  // Expression: -3.805821
  //  Referenced by: '<S1415>/Saturation10'

  -3.805821,

  // Expression: 8*0.000001178991825
  //  Referenced by: '<S1415>/Constant3'

  9.4319346E-6,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1415>/Saturation'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1415>/Saturation'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1415>/Saturation4'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1415>/Saturation4'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1415>/Saturation1'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1415>/Saturation1'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1415>/Saturation5'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1415>/Saturation5'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1415>/Saturation2'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1415>/Saturation2'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1415>/Saturation6'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1415>/Saturation6'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1415>/Saturation3'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1415>/Saturation3'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1415>/Saturation7'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1415>/Saturation7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1402>/Constant14'

  0.0,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1412>/Gain'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1412>/Gain8'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1412>/Gain1'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1412>/Gain2'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1412>/Gain3'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1412>/Gain9'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1412>/Gain10'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1412>/Gain11'

  1.3113202233750001E-5,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1412>/Gain4'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1412>/Gain12'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1412>/Gain5'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1412>/Gain13'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1412>/Gain6'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1412>/Gain14'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1412>/Gain7'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1412>/Gain15'

  1.178991825E-6,

  // Expression: 1/(10075*pi/30)
  //  Referenced by: '<S1402>/Gain'

  0.00094782100104354552,

  // Expression: [pi/6 2 pi/6 pi/6]
  //  Referenced by: '<S1402>/Saturation'

  { 0.52359877559829882, 2.0, 0.52359877559829882, 0.52359877559829882 },

  // Expression: -[pi/6 0 pi/6 pi/6]
  //  Referenced by: '<S1402>/Saturation'

  { -0.52359877559829882, -0.0, -0.52359877559829882, -0.52359877559829882 },

  // Expression: 1
  //  Referenced by: '<S1402>/Constant'

  1.0,

  // Expression: [0;0;0;0;0;0;0;0]
  //  Referenced by: '<S1403>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: -1
  //  Referenced by: '<S1403>/Constant2'

  -1.0,

  // Expression: 1500
  //  Referenced by: '<S1429>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1429>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S1429>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1429>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1426>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1426>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S1426>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1426>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1427>/Constant7'

  1500.0,

  // Expression: -1/500
  //  Referenced by: '<S1427>/Gain10'

  -0.002,

  // Expression: 1
  //  Referenced by: '<S1427>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1427>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1428>/Constant7'

  1500.0,

  // Expression: -1/500
  //  Referenced by: '<S1428>/Gain10'

  -0.002,

  // Expression: 1
  //  Referenced by: '<S1428>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1428>/Saturation'

  -0.9,

  // Expression: -1
  //  Referenced by: '<S1403>/Constant'

  -1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant7'

  1.0,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Convert To ft//s'

  3.28084,

  // Computed Parameter: Filter_gainval_a
  //  Referenced by: '<S1488>/Filter'

  0.001,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain13'

  3.28084,

  // Expression: 1000
  //  Referenced by: '<S1446>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1444>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1445>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1447>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1448>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1449>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1450>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1451>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1452>/Constant'

  1000.0,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain1'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain2'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain3'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain4'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain5'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain6'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain7'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain8'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain12'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain9'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain10'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain11'

  3.28084,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory'

  0.0,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S15>/Gain'

  3.2808F,

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S144>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_ic
  //  Referenced by: '<S145>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_lw
  //  Referenced by: '<S319>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_bs
  //  Referenced by: '<S323>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_jh
  //  Referenced by: '<S10>/Constant'

  0.0F,

  // Computed Parameter: Constant2_Value_p
  //  Referenced by: '<S10>/Constant2'

  0.0F,

  // Expression: ly
  //  Referenced by: '<S1412>/Constant2'

  1.08333337F,

  // Expression: lx
  //  Referenced by: '<S1412>/Constant1'

  1.91666663F,

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S1402>/Constant5'

  1.0F,

  // Computed Parameter: Gain3_Gain_f
  //  Referenced by: '<S1402>/Gain3'

  1.9098593F,

  // Computed Parameter: Gain2_Gain_cf
  //  Referenced by: '<S1402>/Gain2'

  1.9098593F,

  // Computed Parameter: Gain4_Gain_ki
  //  Referenced by: '<S1402>/Gain4'

  1.9098593F,

  // Computed Parameter: Converttoft1_Gain
  //  Referenced by: '<S5>/Convert to ft1'

  3.28084F,

  // Computed Parameter: Converttoft2_Gain
  //  Referenced by: '<S5>/Convert to ft2'

  3.28084F,

  // Computed Parameter: Converttoft3_Gain
  //  Referenced by: '<S5>/Convert to ft3'

  3.28084F,

  // Computed Parameter: ConvertTofts1_Gain
  //  Referenced by: '<S5>/Convert To ft//s1'

  3.28084F,

  // Computed Parameter: ConvertTofts3_Gain
  //  Referenced by: '<S5>/Convert To ft//s3'

  3.28084F,

  // Computed Parameter: ConvertTofts4_Gain
  //  Referenced by: '<S5>/Convert To ft//s4'

  3.28084F,

  // Computed Parameter: ConvertTofts5_Gain
  //  Referenced by: '<S5>/Convert To ft//s5'

  3.28084F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialCondi
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_InitialCo
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gt
  //  Referenced by: '<S1446>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialCon_j
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initial_j
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_f
  //  Referenced by: '<S1444>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialCo_jx
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initia_jx
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gl
  //  Referenced by: '<S1445>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialC_jxk
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initi_jxk
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_nm
  //  Referenced by: '<S1447>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initial_jxkx
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Init_jxkx
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_dx
  //  Referenced by: '<S1448>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initia_jxkxj
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Ini_jxkxj
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_f1
  //  Referenced by: '<S1449>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initi_jxkxj0
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_In_jxkxj0
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S1450>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Init_jxkxj0l
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_I_jxkxj0l
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_n2
  //  Referenced by: '<S1451>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Ini_jxkxj0lw
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2__jxkxj0lw
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gn
  //  Referenced by: '<S1452>/Gain'

  1000.0F,

  // Computed Parameter: Gain_Gain_dj
  //  Referenced by: '<S4>/Gain'

  1.31132019E-5F,

  // Computed Parameter: Gain8_Gain_d
  //  Referenced by: '<S4>/Gain8'

  1.31132019E-5F,

  // Computed Parameter: Gain1_Gain_l
  //  Referenced by: '<S4>/Gain1'

  1.31132019E-5F,

  // Computed Parameter: Gain2_Gain_k
  //  Referenced by: '<S4>/Gain2'

  1.31132019E-5F,

  // Computed Parameter: Gain3_Gain_c0
  //  Referenced by: '<S4>/Gain3'

  1.31132019E-5F,

  // Computed Parameter: Gain9_Gain_g
  //  Referenced by: '<S4>/Gain9'

  1.31132019E-5F,

  // Computed Parameter: Gain10_Gain_l
  //  Referenced by: '<S4>/Gain10'

  1.31132019E-5F,

  // Computed Parameter: Gain11_Gain_c
  //  Referenced by: '<S4>/Gain11'

  1.31132019E-5F,

  // Expression: ly
  //  Referenced by: '<S4>/Constant2'

  1.08333337F,

  // Expression: lx
  //  Referenced by: '<S4>/Constant1'

  1.91666663F,

  // Computed Parameter: Gain4_Gain_o
  //  Referenced by: '<S4>/Gain4'

  1.17899185E-6F,

  // Computed Parameter: Gain12_Gain_j
  //  Referenced by: '<S4>/Gain12'

  1.17899185E-6F,

  // Computed Parameter: Gain5_Gain_o
  //  Referenced by: '<S4>/Gain5'

  1.17899185E-6F,

  // Computed Parameter: Gain13_Gain_k
  //  Referenced by: '<S4>/Gain13'

  1.17899185E-6F,

  // Computed Parameter: Gain6_Gain_m
  //  Referenced by: '<S4>/Gain6'

  1.17899185E-6F,

  // Computed Parameter: Gain14_Gain_o
  //  Referenced by: '<S4>/Gain14'

  1.17899185E-6F,

  // Computed Parameter: Gain7_Gain_i
  //  Referenced by: '<S4>/Gain7'

  1.17899185E-6F,

  // Computed Parameter: Gain15_Gain_f
  //  Referenced by: '<S4>/Gain15'

  1.17899185E-6F,

  // Computed Parameter: Switch5_Threshold
  //  Referenced by: '<S1402>/Switch5'

  1800U,

  // Computed Parameter: Constant15_Value
  //  Referenced by: '<S1402>/Constant15'

  0U,

  // Computed Parameter: Switch6_Threshold
  //  Referenced by: '<S1402>/Switch6'

  1800U,

  // Computed Parameter: Constant3_Value_h
  //  Referenced by: '<S15>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_ab
  //  Referenced by: '<S15>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_pj
  //  Referenced by: '<S13>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_n
  //  Referenced by: '<S13>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_e4
  //  Referenced by: '<S13>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_j
  //  Referenced by: '<S311>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_c
  //  Referenced by: '<S311>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_c4
  //  Referenced by: '<S311>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_by
  //  Referenced by: '<S490>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S490>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_pq
  //  Referenced by: '<S490>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant5_Value_d
  //  Referenced by: '<S723>/Constant5'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S723>/Constant6'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_f
  //  Referenced by: '<S723>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant7_Value_g
  //  Referenced by: '<S10>/Constant7'

  { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U },

  // Computed Parameter: Constant9_Value_c
  //  Referenced by: '<S10>/Constant9'

  { 0U, 0U },

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S1114>/Constant5'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant6_Value_k
  //  Referenced by: '<S1114>/Constant6'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_fj
  //  Referenced by: '<S1114>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant6_Value_b
  //  Referenced by: '<S1402>/Constant6'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant10_Value_n
  //  Referenced by: '<S1402>/Constant10'

  { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U },

  // Computed Parameter: Constant1_Value_abx
  //  Referenced by: '<S1402>/Constant1'

  { 0U, 0U, 0U, 0U }
};

//
// File trailer for generated code.
//
// [EOF]
//
