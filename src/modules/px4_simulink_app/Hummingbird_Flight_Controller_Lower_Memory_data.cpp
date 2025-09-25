//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hummingbird_Flight_Controller_Lower_Memory_data.cpp
//
// Code generated for Simulink model 'Hummingbird_Flight_Controller_Lower_Memory'.
//
// Model version                  : 2.189
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Thu Sep 25 09:50:43 2025
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
  //  Referenced by: '<S1458>/Constant13'

  { 1.4365636849630137, 0.0, 0.21166159010381053, 0.0, 3.3499098651084727, 0.0,
    0.21166159010381053, 0.0, 4.6320009945919063 },

  // Variable: g
  //  Referenced by: '<S13>/Gain3'

  32.174,

  // Variable: m
  //  Referenced by:
  //    '<S545>/Gain5'
  //    '<S777>/Gain5'
  //    '<S1168>/Gain5'

  1.243239883135451,

  // Mask Parameter: PIDController5_D
  //  Referenced by: '<S862>/Derivative Gain'

  0.05,

  // Mask Parameter: PIDController3_D
  //  Referenced by: '<S810>/Derivative Gain'

  0.1,

  // Mask Parameter: PIDController8_D
  //  Referenced by: '<S1091>/Derivative Gain'

  { 0.2, 0.2, 5.0E-5 },

  // Mask Parameter: PIDController9_D
  //  Referenced by: '<S1143>/Derivative Gain'

  { 0.015, 0.015, 0.0 },

  // Mask Parameter: PIDController9_D_d
  //  Referenced by: '<S1433>/Derivative Gain'

  { 0.015, 0.015, 0.0 },

  // Mask Parameter: PIDController_D
  //  Referenced by: '<S1533>/Derivative Gain'

  1.0,

  // Mask Parameter: PIDController3_I
  //  Referenced by: '<S814>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController5_I
  //  Referenced by: '<S866>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController8_I
  //  Referenced by: '<S1095>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController9_I
  //  Referenced by: '<S1147>/Integral Gain'

  { 0.02505936168136361, 0.02505936168136361, 0.05011872336272722 },

  // Mask Parameter: PIDController9_I_i
  //  Referenced by: '<S1437>/Integral Gain'

  { 0.02505936168136361, 0.02505936168136361, 0.05011872336272722 },

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S286>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionF
  //  Referenced by: '<S234>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_i
  //  Referenced by: '<S464>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditio_g
  //  Referenced by: '<S412>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialCondition
  //  Referenced by: '<S578>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_f
  //  Referenced by: '<S692>/Filter'

  0.0,

  // Mask Parameter: PIDController5_InitialCondition
  //  Referenced by: '<S864>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_f
  //  Referenced by: '<S812>/Filter'

  0.0,

  // Mask Parameter: PIDController8_InitialCondition
  //  Referenced by: '<S1093>/Filter'

  0.0,

  // Mask Parameter: PIDController9_InitialCondition
  //  Referenced by: '<S1145>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_g
  //  Referenced by: '<S1030>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_m
  //  Referenced by: '<S1203>/Filter'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_h
  //  Referenced by: '<S1435>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_b
  //  Referenced by: '<S1369>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditi_gy
  //  Referenced by: '<S1535>/Filter'

  0.0,

  // Mask Parameter: PIDController2_InitialCondition
  //  Referenced by: '<S116>/Integrator'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_j
  //  Referenced by: '<S168>/Integrator'

  0.0,

  // Mask Parameter: PIDController5_InitialConditi_i
  //  Referenced by: '<S869>/Integrator'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_a
  //  Referenced by: '<S817>/Integrator'

  0.0,

  // Mask Parameter: PIDController8_InitialConditi_g
  //  Referenced by: '<S1098>/Integrator'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_i
  //  Referenced by: '<S1150>/Integrator'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_b
  //  Referenced by: '<S1440>/Integrator'

  0.0,

  // Mask Parameter: PIDController2_LowerIntegratorS
  //  Referenced by: '<S116>/Integrator'

  -2.0,

  // Mask Parameter: PIDController3_LowerIntegratorS
  //  Referenced by: '<S168>/Integrator'

  -2.0,

  // Mask Parameter: PIDController8_LowerIntegratorS
  //  Referenced by: '<S1098>/Integrator'

  -5.0,

  // Mask Parameter: PIDController9_LowerIntegratorS
  //  Referenced by: '<S1150>/Integrator'

  -4.0,

  // Mask Parameter: PIDController9_LowerIntegrato_p
  //  Referenced by: '<S1440>/Integrator'

  -4.0,

  // Mask Parameter: PIDController2_LowerSaturationL
  //  Referenced by: '<S123>/Saturation'

  -5.0,

  // Mask Parameter: PIDController3_LowerSaturationL
  //  Referenced by: '<S175>/Saturation'

  -5.0,

  // Mask Parameter: PIDController5_LowerSaturationL
  //  Referenced by: '<S876>/Saturation'

  -15.0,

  // Mask Parameter: PIDController9_LowerSaturationL
  //  Referenced by: '<S1157>/Saturation'

  -5.0,

  // Mask Parameter: PIDController9_LowerSaturatio_a
  //  Referenced by: '<S1447>/Saturation'

  -5.0,

  // Mask Parameter: PIDController5_N
  //  Referenced by: '<S872>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController3_N
  //  Referenced by: '<S820>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController8_N
  //  Referenced by: '<S1101>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController9_N
  //  Referenced by: '<S1153>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController9_N_j
  //  Referenced by: '<S1443>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S1543>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController5_P
  //  Referenced by: '<S874>/Proportional Gain'

  1.0,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S822>/Proportional Gain'

  1.0,

  // Mask Parameter: PIDController8_P
  //  Referenced by: '<S1103>/Proportional Gain'

  { 0.21, 0.21, 0.00035 },

  // Mask Parameter: PIDController9_P
  //  Referenced by: '<S1155>/Proportional Gain'

  { 0.60000000000000009, 0.60000000000000009, 0.1 },

  // Mask Parameter: PIDController9_P_b
  //  Referenced by: '<S1445>/Proportional Gain'

  { 0.60000000000000009, 0.60000000000000009, 0.1 },

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S1545>/Proportional Gain'

  0.0,

  // Mask Parameter: PIDController2_UpperIntegratorS
  //  Referenced by: '<S116>/Integrator'

  2.0,

  // Mask Parameter: PIDController3_UpperIntegratorS
  //  Referenced by: '<S168>/Integrator'

  2.0,

  // Mask Parameter: PIDController8_UpperIntegratorS
  //  Referenced by: '<S1098>/Integrator'

  5.0,

  // Mask Parameter: PIDController9_UpperIntegratorS
  //  Referenced by: '<S1150>/Integrator'

  4.0,

  // Mask Parameter: PIDController9_UpperIntegrato_e
  //  Referenced by: '<S1440>/Integrator'

  4.0,

  // Mask Parameter: PIDController2_UpperSaturationL
  //  Referenced by: '<S123>/Saturation'

  5.0,

  // Mask Parameter: PIDController3_UpperSaturationL
  //  Referenced by: '<S175>/Saturation'

  5.0,

  // Mask Parameter: PIDController5_UpperSaturationL
  //  Referenced by: '<S876>/Saturation'

  15.0,

  // Mask Parameter: PIDController9_UpperSaturationL
  //  Referenced by: '<S1157>/Saturation'

  5.0,

  // Mask Parameter: PIDController9_UpperSaturatio_o
  //  Referenced by: '<S1447>/Saturation'

  5.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1471>/Constant'

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
  //  Referenced by: '<S1561>/Out1'

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
  //  Referenced by: '<S1488>/Constant'

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
  //  Referenced by: '<S1566>/Out1'

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
  //  Referenced by: '<S1502>/Constant'

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
  //  Referenced by: '<S1559>/Out1'

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
  //  Referenced by: '<S1486>/Constant'

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
  //  Referenced by: '<S1567>/Out1'

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
  //  Referenced by: '<S1503>/Constant'

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
  //  Referenced by: '<S18>/Constant'

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
  //  Referenced by: '<S1563>/Out1'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S1490>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S1480>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S1564>/Out1'

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
  //  Referenced by: '<S1500>/Constant'

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
  //  Referenced by: '<S1562>/Out1'

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
  //  Referenced by: '<S1489>/Constant'

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
  //  Referenced by: '<S1505>/Out1'

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
  //  Referenced by: '<S1504>/Constant'

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
  //  Referenced by: '<S1565>/Out1'

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
  //  Referenced by: '<S1501>/Constant'

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
  //  Referenced by: '<S188>/Constant'

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
  //  Referenced by: '<S186>/Constant'

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
  //  Referenced by: '<S1560>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_e2
  //  Referenced by: '<S1487>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S1398>/Constant'

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
  //  Referenced by: '<S361>/Constant'

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
  //  Referenced by: '<S539>/Constant'

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
  //  Referenced by: '<S767>/Constant'

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
  //  Referenced by: '<S1053>/Constant'

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
  //  Referenced by: '<S1392>/Constant'

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
  //  Referenced by: '<S1469>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // de
    0.0F,                              // dt
    0.0F,                              // da
    0.0F                               // dr
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S363>/Constant'

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
  //  Referenced by: '<S541>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_g3
  //  Referenced by: '<S769>/Constant'

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
  //  Referenced by: '<S1055>/Constant'

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
  //  Referenced by: '<S1394>/Constant'

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
  //  Referenced by: '<S365>/Constant'

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
  //  Referenced by: '<S543>/Constant'

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
  //  Referenced by: '<S771>/Constant'

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
  //  Referenced by: '<S1057>/Constant'

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
  //  Referenced by: '<S1396>/Constant'

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
  //  Referenced by: '<S1558>/Out1'

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
  //  Referenced by: '<S1485>/Constant'

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
  //  Referenced by: '<S13>/Saturation'

  1.0471975511965976,

  // Expression: -pi/3
  //  Referenced by: '<S13>/Saturation'

  -1.0471975511965976,

  // Expression: 0
  //  Referenced by: '<S14>/Constant'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S116>/Integrator'

  0.001,

  // Computed Parameter: Integrator_gainval_k
  //  Referenced by: '<S168>/Integrator'

  0.001,

  // Expression: 15*pi/180
  //  Referenced by: '<S14>/Saturation2'

  0.26179938779914941,

  // Expression: -10*pi/180
  //  Referenced by: '<S14>/Saturation2'

  -0.17453292519943295,

  // Expression: 1500
  //  Referenced by: '<S198>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S198>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S198>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S198>/Saturation'

  -0.9,

  // Expression: 30*pi/180
  //  Referenced by: '<S12>/Gain1'

  0.52359877559829882,

  // Expression: 1500
  //  Referenced by: '<S199>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S199>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S199>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S199>/Saturation'

  -0.9,

  // Expression: 20*pi/180
  //  Referenced by: '<S12>/Gain2'

  0.3490658503988659,

  // Expression: 1500
  //  Referenced by: '<S200>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S200>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S200>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S200>/Saturation'

  -0.9,

  // Expression: 0
  //  Referenced by: '<S12>/Gain3'

  0.0,

  // Expression: 32.174
  //  Referenced by: '<S12>/Gain4'

  32.174,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S286>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S12>/Constant1'

  100.0,

  // Computed Parameter: Filter_gainval_b
  //  Referenced by: '<S234>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S12>/Constant4'

  100.0,

  // Expression: -120
  //  Referenced by: '<S6>/Constant11'

  -120.0,

  // Expression: 0
  //  Referenced by: '<S7>/Constant10'

  0.0,

  // Expression: -120
  //  Referenced by: '<S7>/Constant11'

  -120.0,

  // Expression: 1500
  //  Referenced by: '<S376>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S376>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S376>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S376>/Saturation'

  -1.0,

  // Expression: 60*pi/180
  //  Referenced by: '<S367>/Gain1'

  1.0471975511965976,

  // Expression: 1500
  //  Referenced by: '<S377>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S377>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S377>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S377>/Saturation'

  -1.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S367>/Gain2'

  0.3490658503988659,

  // Expression: 1500
  //  Referenced by: '<S378>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S378>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S378>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S378>/Saturation'

  -1.0,

  // Expression: 0.2
  //  Referenced by: '<S367>/Gain3'

  0.2,

  // Expression: 32.174
  //  Referenced by: '<S367>/Gain4'

  32.174,

  // Computed Parameter: Filter_gainval_n
  //  Referenced by: '<S464>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S367>/Constant1'

  100.0,

  // Computed Parameter: Filter_gainval_bd
  //  Referenced by: '<S412>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S367>/Constant4'

  100.0,

  // Expression: 0
  //  Referenced by: '<S8>/Constant14'

  0.0,

  // Expression: 100
  //  Referenced by: '<S545>/Constant'

  100.0,

  // Expression: 1500
  //  Referenced by: '<S773>/Constant'

  1500.0,

  // Expression: 5/500
  //  Referenced by: '<S773>/Gain'

  0.01,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S578>/Filter'

  0.001,

  // Expression: 1500
  //  Referenced by: '<S774>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S774>/Gain'

  0.002,

  // Expression: pi/8
  //  Referenced by: '<S547>/Gain1'

  0.39269908169872414,

  // Expression: 15*pi/180
  //  Referenced by: '<S547>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S547>/Saturation1'

  -0.26179938779914941,

  // Expression: 1500
  //  Referenced by: '<S775>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S775>/Gain'

  0.002,

  // Expression: pi/8
  //  Referenced by: '<S547>/Gain2'

  0.39269908169872414,

  // Expression: 15*pi/180
  //  Referenced by: '<S547>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S547>/Saturation'

  -0.26179938779914941,

  // Expression: 1500
  //  Referenced by: '<S776>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S776>/Gain'

  0.002,

  // Expression: pi/3
  //  Referenced by: '<S547>/Gain'

  1.0471975511965976,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S692>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S546>/Constant1'

  100.0,

  // Expression: 0
  //  Referenced by: '<S9>/Constant10'

  0.0,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S869>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_k
  //  Referenced by: '<S864>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_m
  //  Referenced by: '<S817>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S812>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S1098>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_e
  //  Referenced by: '<S1093>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_m2
  //  Referenced by: '<S1150>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S1145>/Filter'

  0.001,

  // Expression: 15*pi/180
  //  Referenced by: '<S780>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S780>/Saturation1'

  -0.26179938779914941,

  // Expression: 15*pi/180
  //  Referenced by: '<S780>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S780>/Saturation'

  -0.26179938779914941,

  // Computed Parameter: Filter_gainval_io
  //  Referenced by: '<S1030>/Filter'

  0.001,

  // Expression: 1
  //  Referenced by: '<S779>/Constant4'

  1.0,

  // Expression: 0
  //  Referenced by: '<S10>/Constant14'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S1402>/Constant'

  1500.0,

  // Expression: 5/500
  //  Referenced by: '<S1402>/Gain'

  0.01,

  // Computed Parameter: Filter_gainval_pt
  //  Referenced by: '<S1203>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S1168>/Constant'

  100.0,

  // Expression: 1500
  //  Referenced by: '<S1405>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1405>/Gain'

  0.002,

  // Expression: pi/3
  //  Referenced by: '<S1172>/Gain'

  1.0471975511965976,

  // Expression: 1500
  //  Referenced by: '<S1404>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1404>/Gain'

  0.002,

  // Expression: 10
  //  Referenced by: '<S1172>/Gain2'

  10.0,

  // Expression: 1500
  //  Referenced by: '<S1403>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1403>/Gain'

  0.002,

  // Expression: 10
  //  Referenced by: '<S1172>/Gain1'

  10.0,

  // Computed Parameter: Integrator_gainval_ma
  //  Referenced by: '<S1440>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_kc
  //  Referenced by: '<S1435>/Filter'

  0.001,

  // Expression: 15*pi/180
  //  Referenced by: '<S1172>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S1172>/Saturation1'

  -0.26179938779914941,

  // Expression: 15*pi/180
  //  Referenced by: '<S1172>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S1172>/Saturation'

  -0.26179938779914941,

  // Computed Parameter: Filter_gainval_o
  //  Referenced by: '<S1369>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S1170>/Constant4'

  100.0,

  // Expression: 0
  //  Referenced by: '<S1458>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1458>/Constant9'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1458>/Constant29'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1458>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1458>/Constant3'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S1466>/Constant7'

  1000.0,

  // Expression: 1/500
  //  Referenced by: '<S1466>/Gain10'

  0.002,

  // Expression: 2
  //  Referenced by: '<S1466>/Saturation'

  2.0,

  // Expression: 0
  //  Referenced by: '<S1466>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1458>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1458>/Switch3'

  0.0,

  // Expression: IBmat(:,:,1,1)
  //  Referenced by: '<S1458>/Constant2'

  { 2.92525710891472, -0.0060651112354350991, 0.2809484711602882,
    -0.0060651112354350991, 4.5510371556052851, -0.0011029437157677353,
    0.2809484711602882, -0.0011029437157677353, 7.2341711388768024 },

  // Expression: 120
  //  Referenced by: '<S1460>/Saturation3'

  120.0,

  // Expression: 0
  //  Referenced by: '<S1460>/Saturation3'

  0.0,

  // Expression: 8*0.000017484269645*.75
  //  Referenced by: '<S1468>/Constant'

  0.00010490561787000001,

  // Expression: -1
  //  Referenced by: '<S1468>/Gain'

  -1.0,

  // Expression: eye(3)
  //  Referenced by: '<S1458>/Constant12'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: 44.41
  //  Referenced by: '<S1468>/Saturation9'

  44.41,

  // Expression: -44.41
  //  Referenced by: '<S1468>/Saturation9'

  -44.41,

  // Expression: -8*ly*0.000017484269645
  //  Referenced by: '<S1468>/Constant2'

  -0.00015153033692333332,

  // Expression: 78.5
  //  Referenced by: '<S1468>/Saturation8'

  78.5,

  // Expression: -78.5
  //  Referenced by: '<S1468>/Saturation8'

  -78.5,

  // Expression: -8*0.000017484269645*lx
  //  Referenced by: '<S1468>/Constant1'

  -0.00026809213455666669,

  // Expression: 3.805821
  //  Referenced by: '<S1468>/Saturation10'

  3.805821,

  // Expression: -3.805821
  //  Referenced by: '<S1468>/Saturation10'

  -3.805821,

  // Expression: 8*0.000001178991825
  //  Referenced by: '<S1468>/Constant3'

  9.4319346E-6,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1468>/Saturation'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1468>/Saturation'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1468>/Saturation4'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1468>/Saturation4'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1468>/Saturation1'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1468>/Saturation1'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1468>/Saturation5'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1468>/Saturation5'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1468>/Saturation2'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1468>/Saturation2'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1468>/Saturation6'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1468>/Saturation6'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1468>/Saturation3'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1468>/Saturation3'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1468>/Saturation7'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1468>/Saturation7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1458>/Constant14'

  0.0,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1467>/Gain'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1467>/Gain8'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1467>/Gain1'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1467>/Gain2'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1467>/Gain3'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1467>/Gain9'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1467>/Gain10'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1467>/Gain11'

  1.3113202233750001E-5,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1467>/Gain4'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1467>/Gain12'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1467>/Gain5'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1467>/Gain13'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1467>/Gain6'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1467>/Gain14'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1467>/Gain7'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1467>/Gain15'

  1.178991825E-6,

  // Expression: 1/(10075*pi/30)^2
  //  Referenced by: '<S1458>/Gain'

  8.9836465001918872E-7,

  // Expression: [pi/6 2 pi/6 pi/6]
  //  Referenced by: '<S1458>/Saturation'

  { 0.52359877559829882, 2.0, 0.52359877559829882, 0.52359877559829882 },

  // Expression: -[pi/6 0 pi/6 pi/6]
  //  Referenced by: '<S1458>/Saturation'

  { -0.52359877559829882, -0.0, -0.52359877559829882, -0.52359877559829882 },

  // Expression: 1
  //  Referenced by: '<S1458>/Constant'

  1.0,

  // Expression: [0;0;0;0;0;0;0;0]
  //  Referenced by: '<S1459>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: -1
  //  Referenced by: '<S1459>/Constant2'

  -1.0,

  // Expression: 1500
  //  Referenced by: '<S1476>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1476>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S1476>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1476>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1473>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1473>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S1473>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1473>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1474>/Constant7'

  1500.0,

  // Expression: -1/500
  //  Referenced by: '<S1474>/Gain10'

  -0.002,

  // Expression: 1
  //  Referenced by: '<S1474>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1474>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1475>/Constant7'

  1500.0,

  // Expression: -1/500
  //  Referenced by: '<S1475>/Gain10'

  -0.002,

  // Expression: 1
  //  Referenced by: '<S1475>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1475>/Saturation'

  -0.9,

  // Expression: -1
  //  Referenced by: '<S1459>/Constant'

  -1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant7'

  1.0,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Convert To ft//s'

  3.28084,

  // Computed Parameter: Filter_gainval_a
  //  Referenced by: '<S1535>/Filter'

  0.001,

  // Expression: 0
  //  Referenced by: '<S5>/Rate Transition'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/Rate Transition'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/Rate Transition'

  0.0,

  // Expression: 3.28084
  //  Referenced by: '<S5>/Gain13'

  3.28084,

  // Expression: 1000
  //  Referenced by: '<S1493>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1491>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1492>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1494>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1495>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1496>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1497>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1498>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1499>/Constant'

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
  //  Referenced by: '<S14>/Gain'

  3.2808F,

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S197>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_ic
  //  Referenced by: '<S201>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_lw
  //  Referenced by: '<S375>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_bs
  //  Referenced by: '<S379>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_jh
  //  Referenced by: '<S10>/Constant'

  0.0F,

  // Computed Parameter: Constant2_Value_p
  //  Referenced by: '<S10>/Constant2'

  0.0F,

  // Expression: ly
  //  Referenced by: '<S1467>/Constant2'

  1.08333337F,

  // Expression: lx
  //  Referenced by: '<S1467>/Constant1'

  1.91666663F,

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S1458>/Constant5'

  1.0F,

  // Computed Parameter: Gain3_Gain_f
  //  Referenced by: '<S1458>/Gain3'

  1.9098593F,

  // Computed Parameter: Gain2_Gain_cf
  //  Referenced by: '<S1458>/Gain2'

  1.9098593F,

  // Computed Parameter: Gain4_Gain_ki
  //  Referenced by: '<S1458>/Gain4'

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

  // Computed Parameter: TmpRTBAtSumInport2_InitialCondi
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_InitialCo
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gt
  //  Referenced by: '<S1493>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialCon_j
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initial_j
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_f
  //  Referenced by: '<S1491>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialCo_jx
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initia_jx
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gl
  //  Referenced by: '<S1492>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialC_jxk
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initi_jxk
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_nm
  //  Referenced by: '<S1494>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initial_jxkx
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Init_jxkx
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_dx
  //  Referenced by: '<S1495>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initia_jxkxj
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Ini_jxkxj
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_f1
  //  Referenced by: '<S1496>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initi_jxkxj0
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_In_jxkxj0
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S1497>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Init_jxkxj0l
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_I_jxkxj0l
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_n2
  //  Referenced by: '<S1498>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Ini_jxkxj0lw
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2__jxkxj0lw
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gn
  //  Referenced by: '<S1499>/Gain'

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

  // Computed Parameter: ConvertTofts4_Gain
  //  Referenced by: '<S5>/Convert To ft//s4'

  3.28084F,

  // Computed Parameter: ConvertTofts5_Gain
  //  Referenced by: '<S5>/Convert To ft//s5'

  3.28084F,

  // Computed Parameter: ConvertTofts3_Gain
  //  Referenced by: '<S5>/Convert To ft//s3'

  3.28084F,

  // Computed Parameter: Switch5_Threshold
  //  Referenced by: '<S1458>/Switch5'

  1800U,

  // Computed Parameter: Constant15_Value
  //  Referenced by: '<S1458>/Constant15'

  0U,

  // Computed Parameter: Switch6_Threshold
  //  Referenced by: '<S1458>/Switch6'

  1800U,

  // Computed Parameter: Constant3_Value_h
  //  Referenced by: '<S14>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_a
  //  Referenced by: '<S14>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_pj
  //  Referenced by: '<S12>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_n
  //  Referenced by: '<S12>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_e4
  //  Referenced by: '<S12>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_j
  //  Referenced by: '<S367>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_c
  //  Referenced by: '<S367>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_c4
  //  Referenced by: '<S367>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_b
  //  Referenced by: '<S546>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S546>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_pq
  //  Referenced by: '<S546>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant5_Value_d
  //  Referenced by: '<S779>/Constant5'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S779>/Constant6'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_f
  //  Referenced by: '<S779>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant7_Value_g
  //  Referenced by: '<S10>/Constant7'

  { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U },

  // Computed Parameter: Constant9_Value_c
  //  Referenced by: '<S10>/Constant9'

  { 0U, 0U },

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S1170>/Constant5'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant6_Value_k
  //  Referenced by: '<S1170>/Constant6'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_fj
  //  Referenced by: '<S1170>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant10_Value_n
  //  Referenced by: '<S1458>/Constant10'

  { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U },

  // Computed Parameter: Constant1_Value_ab
  //  Referenced by: '<S1458>/Constant1'

  { 0U, 0U, 0U, 0U }
};

//
// File trailer for generated code.
//
// [EOF]
//
