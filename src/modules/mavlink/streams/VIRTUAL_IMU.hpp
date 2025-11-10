/****************************************************************************
 *
 *   Copyright (c) 2020 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
#ifndef VIRTUAL_IMU_HPP
#define VIRTUAL_IMU_HPP

#include "uORB/topics/virtual_imu.h"

 class MavlinkStreamVirtualImu : public MavlinkStream
{
public:
    static MavlinkStream *new_instance(Mavlink *mavlink)
    {
        return new MavlinkStreamVirtualImu(mavlink);
    }
    const char *get_name() const
    {
        return MavlinkStreamVirtualImu::get_name_static();
    }
    static const char *get_name_static()
    {
        return "VIRTUAL_IMU";
    }
    static uint16_t get_id_static()
    {
        return MAVLINK_MSG_ID_VIRTUAL_IMU;
    }
    uint16_t get_id()
    {
        return get_id_static();
    }
    unsigned get_size()
    {
        return MAVLINK_MSG_ID_VIRTUAL_IMU_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES;
    }

private:
    //Subscription to array of uORB virtual_imu instances
    uORB::Subscription _virtual_imu_subs{ORB_ID(virtual_imu)};
    // SubscriptionMultiArray subscription is needed because failure detection ID has multiple instances.
    // uORB::Subscription is used to subscribe to a single-instance topic

    /* do not allow top copying this class */
    MavlinkStreamVirtualImu(MavlinkStreamVirtualImu &);
    MavlinkStreamVirtualImu& operator = (const MavlinkStreamVirtualImu &);

protected:
    explicit MavlinkStreamVirtualImu(Mavlink *mavlink) : MavlinkStream(mavlink)
    {}

	bool send() override
	{
	    virtual_imu_s virtual_imu{};
	    bool updated = false;

		// Update virtual_imu and publish only if the status has changed
		if (_virtual_imu_subs.update(&virtual_imu)) {
	// mavlink_virtual_imu_t is the MAVLink message object
			mavlink_virtual_imu_t msg{};

			msg.p = virtual_imu.p;
			msg.q = virtual_imu.q;
			msg.r = virtual_imu.r;

	//Send the message
			mavlink_msg_virtual_imu_send_struct(_mavlink->get_channel(), &msg);
			updated = true;
		}


	    return updated;
	}

};

#endif
