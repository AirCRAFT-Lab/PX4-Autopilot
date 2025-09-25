/****************************************************************************
 *
 *   Copyright 2024 The MathWorks, Inc.
 *   This file is used to create the added Parameter metadata.
 *
 ****************************************************************************/

/**
 * New group testing parameter 1.
 *
 * To check if it reflects.
 *
 * @min -1000000
 * @max 1000000
 * @group Simulink Module
 */
PARAM_DEFINE_INT32(SL_INT32_PARAM, 0);

/**
 * New group testing parameter 2.
 *
 * To check if it reflects.
 *
 * @min -1000000
 * @max 1000000
 * @group Simulink Module
 */
PARAM_DEFINE_FLOAT(SL_FLOAT_PARAM, 0.0);


/**
 * Yaw damper gain
 * 
 * Yaw damper gain that can be adjusted in parameters or on the RC
 * 
 * @min 0
 * @max 99999
 * @group Modular
 * @category Developer
 */
PARAM_DEFINE_FLOAT(YAW_DAMPER_GAIN, 0.7);

/**
 * Max yaw rate
 * 
 * Maximum yaw rate that the pilot can command from the RC
 * 
 * @min 0
 * @max 99999
 * @group Modular
 * @category Developer
 */
PARAM_DEFINE_FLOAT(YAW_RATE_MAX, 0.5);

/**
 * Default yaw gain
 * 
 * Default yaw gain that the gain will get reset to when the pilot move the switch to the reset position
 * 
 * @min 0
 * @max 99999
 * @group Modular
 * @category Developer
 */
PARAM_DEFINE_FLOAT(YAW_GAIN_DEFAULT, 0.7);
